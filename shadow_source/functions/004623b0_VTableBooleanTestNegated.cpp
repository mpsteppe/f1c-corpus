// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004623B0
// Canonical corpus name: ShortComputation_23b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_23b0_004623b0.c

void UnknownObject::VTableBooleanTestNegated()
{
    // Invokes VTableBooleanTestWrapper(a1, 140) and returns true only when the vtable-mediated boolean test yields zero (negated boolean).
    // CALL: Calls VTableBooleanTestWrapper(a1, 140), a vtable-dispatched boolean test with selector value 140. [callee:0x0057A830, source:raw]
    // CALCULATION: Compares the wrapper result against 0, inverting the boolean. [source:raw]
    // RETURN: Returns true when the wrapper test returned zero, otherwise false. [source:raw]

    // Conservative worker pseudocode:
    //   return VTableBooleanTestWrapper(a1, 140) == 0;
    // UNRESOLVED: Meaning of the selector literal 140 passed to VTableBooleanTestWrapper is unknown; caller context suggests a readiness or state query (callers include NetComm_SetSelfAsReady, ConditionalRenderStateUpdate, SessionTypeSetter).
}
