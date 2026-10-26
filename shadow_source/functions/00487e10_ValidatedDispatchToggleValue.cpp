// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487E10
// Canonical corpus name: UtilityFunction_7e10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_7e10_00487e10.c

void UnknownObject::ValidatedDispatchToggleValue()
{
    // UI dispatch handler that validates the current value via UIValueValidator, sets handler state to 1 via sub_487260, handles radio/check state via UIRadioCheckStateChangeHandler, obtains a value pointer through the vtable slot at offset 0xAC and toggles it (0<->1) when non-null, then performs a secondary validation through the vtable slot at offset 0x98 and finalizes via sub_486600. Returns -1 on any validation failure, 0 on success.
    // GUARD: If UIValueValidator(this) returns 0, return -1 immediately (primary validation failure) [callee:0x004874E0, source:raw]
    // CALL: Set the handler state to 1 via sub_487260(this, 1) [callee:0x00487260, source:raw]
    // CALL: Handle radio/check state change via UIRadioCheckStateChangeHandler(this) [callee:0x00487460, source:raw]
    // CALL: Invoke the vtable slot at offset 0xAC (field obj+0xAC, vtable read through this+0) to obtain a pointer to a toggleable value [field:obj:0x000000AC, field:this:0x00000000, source:raw]
    // ASSIGNMENT: If the returned pointer is non-null, toggle the pointed value: *v2 = (*v2 == 0) [field:obj:0x000000AC, source:raw]
    // GUARD: If the vtable dispatch at offset 0x98 (field obj+0x98) returns non-zero, return -1 (secondary validation failure) [field:obj:0x00000098, field:this:0x00000000, source:raw]
    // CALL: Finalize the computation via sub_486600(this) once all validations pass [callee:0x00486600, source:raw]
    // RETURN: Return 0 on success, -1 on any validation failure [function:0x00487E10, source:raw]

    // Conservative worker pseudocode:
    //   int ValidatedDispatchToggleValue(this) {
    //     if (!UIValueValidator(this))
    //       return -1;
    //     sub_487260(this, 1);
    //     UIRadioCheckStateChangeHandler(this);
    //     int* v2 = (int*)vtbl[0xAC](this);      // vtable slot at offset 0xAC
    //     if (v2)
    //       *v2 = (*v2 == 0);
    //     if (vtbl[0x98](this))                  // vtable slot at offset 0x98
    //       return -1;
    //     sub_486600(this);
    //     return 0;
    //   }
    // UNRESOLVED: The vtable slots at offsets 0x98 and 0xAC are not resolved to concrete class methods; field evidence labels them as obj+0x98 and obj+0xAC
    // UNRESOLVED: The semantic meaning of the toggled value (0/1) at the pointer returned by the 0xAC vtable slot is unknown
    // UNRESOLVED: Owner is unconfirmed; the ABI lead is a generic utility-function name (LEGACY)
}
