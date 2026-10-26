// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004879E0
// Canonical corpus name: InitDispatchWithVTableCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitDispatchWithVTableCheck_004879e0.c

void UnknownObject::InitDispatchWithVTableCheck()
{
    // Validated UI dispatch init: validates the control via UIValueValidator (fail -> -1), runs a state-dependent vtable dispatch (StateDependentVTableDispatch_7760(this, 1)), propagates a UI control state change, then performs a secondary validation through the vtable slot at byte offset 152 (0x98, table read through this+0) and finalizes via sub_486600. Returns -1 on any failure, 0 on success.
    // GUARD: If UIValueValidator(this) returns 0, return -1 immediately (primary validation failure) [callee:0x004874E0, source:raw]
    // CALL: StateDependentVTableDispatch_7760(this, 1): state-dependent vtable dispatch with argument 1 [callee:0x00487760, source:raw]
    // CALL: UIControlStateChangeHandler(this): propagate the UI control state change [callee:0x00487960, source:raw]
    // GUARD: Call the vtable method at byte offset 152 (0x98) through the table pointer read at this+0; return -1 if it reports non-zero (secondary validation failure) [field:obj:0x00000098, field:this:0x00000000, source:raw]
    // CALL: sub_486600(this): finalize the initialization once all checks pass [callee:0x00486600, source:raw]
    // RETURN: Return 0 on success, -1 on any validation failure [function:0x004879E0, source:raw]

    // Conservative worker pseudocode:
    //   int InitDispatchWithVTableCheck(this) {
    //     if (!UIValueValidator(this))
    //       return -1;
    //     StateDependentVTableDispatch_7760(this, 1);
    //     UIControlStateChangeHandler(this);
    //     if (vtbl[152](this))               // vtable slot byte offset 152 (0x98)
    //       return -1;
    //     sub_486600(this);
    //     return 0;
    //   }
    // UNRESOLVED: The vtable slot at byte offset 152 (0x98) is not resolved to a concrete class method; field evidence labels it as obj+0x98
    // UNRESOLVED: The exact relationship to the structural twin (00487530) is not established; this function dispatches via StateDependentVTableDispatch_7760 and UIControlStateChangeHandler
    // UNRESOLVED: Owner is unconfirmed; the ABI lead is a generic dispatch-chain name (LEGACY)
}
