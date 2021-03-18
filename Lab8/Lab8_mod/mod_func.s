
    .global mod_func
mod_func:
mod_loop:
    CMP R0,R1
    BLT end_mod
    SUB R0, R0, R1
    B mod_loop
end_mod:
    BX lr
