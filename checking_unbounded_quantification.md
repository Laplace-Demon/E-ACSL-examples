### checking unbounded quantification

To perform runtime assertion checking, quantifications in specification must be bounded in order to be executable. With symbolic execution, we can lift this restriction by introducing symbol for quantifier. For example:

```wast
(; forall x, P(x) ;)

(func (local $x i32)
    call $i32_symbol
    local.set $x
    [[ P(x) ]]
    call $assert
)
```

There, the value produced by `[[ P(x) ]]` encodes the truth value of the proposition `forall x, P(x)`.

Existentials and nested quantifications bring more complication, as they cannot be expressed by assertions in a single program state. Thus, we plan to add the following functions for symbolic execution:

- `model_exists(var, prop)` which returns a boolean, indicating whether the proposition `prop` holds true for one possible value of `var`.
- `model_forall(var, prop)` which returns a boolean, indicating whether the proposition `prop` holds true for all possible values of `var`.

The procedure for checking quantifications could be:

- Convert the proposition to [prenex normal form](https://en.wikipedia.org/wiki/Prenex_normal_form).
- Bind all the quantifiers to symbols of their type. (`i32`, `i64`, `f32` and `f64`)
- Calculate the inner quantifier-free proposition.
- Iterate on the quantifiers using the two functions.
- Call `assert` on the result.
