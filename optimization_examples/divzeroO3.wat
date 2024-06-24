(module
  (import "symbolic" "i32_symbol" (func  (result i32)))
  (global (mut i32) i32.const 8389632)
  (table 1 1 (ref null func))
  (memory 129)
  (func (result i32)
    call 0
  )
  (func (result i32)
    call 1
    drop
    call 1
    drop
    i32.const 0
  )
  (func (param i32) (param i32) (result i32)
    call 2
  )
  (export "memory" (memory 0))
  (export "main" (func 3))
)
