translation:
	assertion information functions -> keep them ?
	predicate functions -> define wrapper
	memory predicate functions -> keep them ?
	memory model functions -> remove them ? 
	contract behavior functions -> alter the code structure ?
    how to deal with assumes

integer type incompatibility:
	in owi's implementation long has the same range as int, which is not the case for E-ACSL's default architecture dependency
	use option -machdep gcc_x86_32 helps
	also, owi does not support GMP library

main function:
	add __e_acsl_memory_init and __e_acsl_memory_clean surrondings

assert:
	generate __e_acsl_assert_data_t by __e_acsl_assert_register_*
	call __e_acsl_assert(predicate,& __gen_e_acsl_assert_data);
	call __e_acsl_assert_clean(& __gen_e_acsl_assert_data);

behavior:
	generate __gen_e_acsl_contract by __e_acsl_contract_init
	register behavior by __e_acsl_contract_set_behavior_assumes
	count active behavior by __e_acsl_contract_partial_count_all_behaviors
	
	fix the behavior by __e_acsl_contract_get_behavior_assumes
	clean __gen_e_acsl_contract by __e_acsl_contract_clean

meet a pointer:
	__e_acsl_store_block
	__e_acsl_delete_block

define a pointer:
	__e_acsl_full_init

dereference a pointer:
	__e_acsl_valid_read(void *ptr, size_t size, void *base, void *addrof_base)

\valid(ptr):
	(calculate __gen_e_acsl_size and __gen_e_acsl_if)
	verify the validity by __e_acsl_valid(void *ptr, size_t size, void *base, void *addrof_base)

\old:
	store the value in advance

\at:
	store the value in advance

quantified condition:
	using a loop to accumulate the result

function //@ assert:
	simply use __e_acsl_assert

loop variant:
	copy information by __e_acsl_assert_copy_values
	check __gen_e_acsl_old_variant >= 0
	check __gen_e_acsl_old_variant > new variant value at the end of each iteration

loop invariant:
	check invariant before the loop begins
	check invariant at the end of each iteration

mathematical integers:
	define __e_acsl_mpz_t
	set integer by __gmpz_init_set_si
	operate integer by __gmpz_set, __gmpz_add, __gmpz_cmp
	clear integer by __gmpz_clear
	
other problems:
	numbers: int, long, __e_acsl_mpz_t integer
	memory models: \separated, \base_addr, \block_length, \offset, \freeable predicate

---
01/07
Normal ghost constructs:
	ghost code integrates just with normal C code in the instrumented program, trivial use cases include: (global) ghost variable, ghost statement, ghost else clause, ghost default clause, ghost case clause (however the use of break is not controlled, which may potentially break the non-interference rule), ghost label (the state of symbol does not fit well with data-ats)

Ghost function and ghost parameters:
	calling a non-ghost function from ghost code is by default forbidden in Frama-C as side-effect analysis is hard. Must write duplicate ghost functions, or pass `-kernel-warn-key ghost:bad-use=inactive` to enable this.
	ghost parameters become explicit in instrumented code, so every non-ghost call must provide a ghost argument

Ghost structure and ghost field:
	ghost structure definition is supported, however, for ghost struct fields, it is not support by E-ACSL currently. We either simply define the whole struct as ghost or as regular.

02/07
Abrupt termination:
	not supported (breaks, continues, returns, exits)
