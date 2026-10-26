// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004623E0
// Canonical corpus name: FunctionCallWrapper_23e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_23e0_004623e0.c

void UnknownObject::VTableBoolCheckNegated()
{
    // Thin wrapper that calls VTableBoolCheck(a1, 140, &a1) and returns true only when the vtable-dispatched boolean test yields zero (negated boolean result).
    // CALL: Calls VTableBoolCheck(a1, 140, &a1), a vtable-dispatched boolean test with selector literal 140 and a pointer to the local argument copy as the third argument. [callee:0x0057A850, source:raw]
    // CALCULATION: Compares the VTableBoolCheck result against 0, inverting the boolean. [source:raw]
    // RETURN: Returns true when VTableBoolCheck returned zero, otherwise false. [source:raw]

    // Conservative worker pseudocode:
    //   return VTableBoolCheck(a1, 140, &a1) == 0;
    // UNRESOLVED: Meaning of the selector literal 140 and of the third pointer argument (&a1) passed to VTableBoolCheck is unknown; caller context (NetComm_SetSelfAsReady, ConditionalRenderStateUpdate) suggests a readiness or state query, but this is not evidenced.
}
