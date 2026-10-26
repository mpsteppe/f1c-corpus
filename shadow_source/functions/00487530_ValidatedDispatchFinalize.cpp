// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487530
// Canonical corpus name: VirtualDispatchWithErrorHandling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualDispatchWithErrorHandling_00487530.c

void UnknownObject::ValidatedDispatchFinalize()
{
    // Validated UI dispatch handler: validates the current value via UIValueValidator, sets handler state to 1 via sub_487260, handles radio/check state via UIRadioCheckStateChangeHandler, then performs a secondary validation through the vtable slot at offset 0x98 (field obj+0x98) and finalizes via sub_486600. Returns -1 on any validation failure, 0 on success.
    // GUARD: If UIValueValidator(this) returns 0, return -1 immediately (primary validation failure) [callee:0x004874E0, source:raw]
    // CALL: Set the handler state to 1 via sub_487260(this, 1) [callee:0x00487260, source:raw]
    // CALL: Handle radio/check state change via UIRadioCheckStateChangeHandler(this) [callee:0x00487460, source:raw]
    // GUARD: If the vtable dispatch at offset 0x98 (field obj+0x98, vtable read through this+0) returns non-zero, return -1 (secondary validation failure) [field:obj:0x00000098, field:this:0x00000000, source:raw]
    // CALL: Finalize the computation via sub_486600(this) once all validations pass [callee:0x00486600, source:raw]
    // RETURN: Return 0 on success, -1 on any validation failure [function:0x00487530, source:raw]

    // Conservative worker pseudocode:
    //   int ValidatedDispatchFinalize(this) {
    //     if (!UIValueValidator(this))
    //       return -1;
    //     sub_487260(this, 1);
    //     UIRadioCheckStateChangeHandler(this);
    //     if (vtbl[0x98](this))                  // vtable slot at offset 0x98
    //       return -1;
    //     sub_486600(this);
    //     return 0;
    //   }
    // UNRESOLVED: The vtable slot at offset 0x98 is not resolved to a concrete class method; field evidence labels it as obj+0x98
    // UNRESOLVED: The relationship of this function to a near-identical nearby dispatch that additionally toggles a value via a higher vtable slot is not established
    // UNRESOLVED: Owner is unconfirmed; the ABI lead is a generic virtual-dispatch name (LEGACY)
}
