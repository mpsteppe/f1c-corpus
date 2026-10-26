// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561F60
// Canonical corpus name: SingleFunctionCallWrapper_1f60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_1f60_00561f60.c

void UnknownObject::DelegateWithDefaultObjectSubstitution()
{
    // Fastcall wrapper that defaults a null object pointer to the global off_5E4DFC, then delegates to the single call target sub_562AC0 with that pointer and constant 2, returning its result. No fields are read or written on the caller-supplied object.
    // GUARD: When the incoming object pointer a1 is null, substitute the global default object off_5E4DFC. [global:0x005E4DFC, source:raw]
    // CALL: Delegate to the single call target sub_562AC0 with the resolved object pointer and the constant 2. [function:0x00561F60, source:raw]
    // RETURN: Return the result of the sub_562AC0 call unchanged. [function:0x00561F60, source:raw]
    // CALL: Invoked by BooleanFlagResetWithSideEffects (0x0045D240); the call context supplies no evidence about this function's purpose beyond the delegation pattern. [caller:0x0045D240, function:0x00561F60]

    // Conservative worker pseudocode:
    //   if (!a1) a1 = off_5E4DFC;
    //   return sub_562AC0(a1, 2);
    // UNRESOLVED: The call target sub_562AC0 is present in the raw source but is not listed in the packet callees, so its contract cannot be confirmed from this packet alone
    // UNRESOLVED: The meaning of the constant 2 passed as the second argument is not determinable
    // UNRESOLVED: The owner class is unknown; no evidence inside this function identifies the object type
}
