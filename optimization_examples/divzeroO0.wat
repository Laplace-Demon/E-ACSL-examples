(module
  (import "symbolic" "i32_symbol" (func  (result i32)))
  (global (mut i32) i32.const 8389632)
  (table 1 1 (ref null func))
  (memory 129)
  (func (result i32)
    call 0
  )
  (func (result i32) (local i32)
    global.get 0
    i32.const 16
    i32.sub
    local.tee 0
    global.set 0
    local.get 0
    call 1
    i32.store offset=12 align=4
    local.get 0
    call 1
    i32.store offset=8 align=4
    local.get 0
    local.get 0
    i32.load offset=12 align=4
    local.get 0
    i32.load offset=8 align=4
    i32.div_s
    i32.store offset=4 align=4
    local.get 0
    i32.const 16
    i32.add
    global.set 0
    i32.const 0
  )
  (func (param i32) (param i32) (result i32)
    call 2
  )
  (export "memory" (memory 0))
  (export "main" (func 3))
)
