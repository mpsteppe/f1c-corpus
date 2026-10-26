// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005357C0
// Canonical corpus name: ArgumentReorderWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArgumentReorderWrapper_005357c0.c

void UnknownObject::ArgumentReorderWrapper()
{
    // Thin forwarding wrapper that re-orders arguments and fixes the second parameter of the callee to the constant 15. Passes its receiver a1 through unchanged, injects the literal 15 as the callee's second argument, and forwards the byte pointer a2 and the third argument a3; the callee's result is returned directly. Called by sub_59B260 (0x0059B260).
    // CALL: Invokes sub_5356A0 with the receiver a1, the fixed constant 15, then a2 and a3, effectively injecting a constant channel/flag as the second argument [callee:0x005356A0, source:raw]
    // RETURN: Returns the callee's result directly without modification [source:raw]
    // CALL: Invoked by sub_59B260 (0x0059B260) [caller:0x0059B260, source:raw]

    // Conservative worker pseudocode:
    //   return sub_5356A0(a1, 15, a2, a3);
    // UNRESOLVED: The meaning of the injected constant 15 (channel, mode or flag) is not established from this packet
    // UNRESOLVED: The parameter conventions of sub_5356A0 beyond this call site are not determinable from this packet
}
