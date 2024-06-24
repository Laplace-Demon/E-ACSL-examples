(module
  (type (;0;) (func (result i32)))
  (type (;1;) (func (param i32 i32) (result i32)))
  (import "symbolic" "i32_symbol" (func $__i32 (type 0)))
  (func $owi_i32 (type 0) (result i32)
    call $__i32)
  (func $__original_main (type 0) (result i32)
    call $owi_i32
    drop
    call $owi_i32
    drop
    i32.const 0)
  (func $main (type 1) (param i32 i32) (result i32)
    call $__original_main)
  (table (;0;) 1 1 funcref)
  (memory (;0;) 129)
  (global $__stack_pointer (mut i32) (i32.const 8389632))
  (export "memory" (memory 0))
  (export "main" (func $main)))
