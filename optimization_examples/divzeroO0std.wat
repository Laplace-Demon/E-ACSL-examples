(module
  (type (;0;) (func (result i32)))
  (type (;1;) (func (param i32 i32) (result i32)))
  (import "symbolic" "i32_symbol" (func $__i32 (type 0)))
  (func $owi_i32 (type 0) (result i32)
    call $__i32)
  (func $__original_main (type 0) (result i32)
    (local i32)
    global.get $__stack_pointer
    i32.const 16
    i32.sub
    local.tee 0
    global.set $__stack_pointer
    local.get 0
    call $owi_i32
    i32.store offset=12
    local.get 0
    call $owi_i32
    i32.store offset=8
    local.get 0
    local.get 0
    i32.load offset=12
    local.get 0
    i32.load offset=8
    i32.div_s
    i32.store offset=4
    local.get 0
    i32.const 16
    i32.add
    global.set $__stack_pointer
    i32.const 0)
  (func $main (type 1) (param i32 i32) (result i32)
    call $__original_main)
  (table (;0;) 1 1 funcref)
  (memory (;0;) 129)
  (global $__stack_pointer (mut i32) (i32.const 8389632))
  (export "memory" (memory 0))
  (export "main" (func $main)))
