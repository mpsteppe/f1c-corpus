// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BAD0
// Canonical corpus name: ShortComputation_bad0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_bad0_0049bad0.c

void UnknownObject::DistanceProjectionThresholdCheck()
{
    // Boolean check with no arguments. Computes a float distance projection via DistanceProjectionCalc on the global dword_7C54E0 offset by 12, holding the result in v1, then returns whether either RingBufferAccessWithWrap(v1) or IndexedFloatArrayLookup(v1) equals 2. Called by sub_49D4C0 (0049d4c0), HUDFlagRendererMain (004d82d0) and GlobalFlagSetterViaFunctionCall (0059d948).
    // CALL: DistanceProjectionCalc(dword_7C54E0 + 12) computes a float projection from the global dword_7C54E0 offset by 12; the float result is held in v1. [callee:0x004F0050, global:0x007C54E0, source:raw]
    // CALL: RingBufferAccessWithWrap(v1) indexes a ring buffer with wrap-around; the result is compared against 2. [callee:0x004D1CF0, source:raw]
    // CALL: IndexedFloatArrayLookup(v1) indexes a float array by the projection value; the result is compared against 2. [callee:0x004D1D40, source:raw]
    // RETURN: Returns true when either lookup equals 2, false otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_49BAD0() {
    //     float v1;
    //     v1 = DistanceProjectionCalc(dword_7C54E0 + 12);
    //     return RingBufferAccessWithWrap(v1) == 2 || IndexedFloatArrayLookup(v1) == 2;
    //   }
    // UNRESOLVED: dword_8ACEE0 is reported read by the deterministic facts but does not appear in the raw decompiled body; its role in this function is unknown.
    // UNRESOLVED: The +12 offset on dword_7C54E0 selects a sub-structure of that global; the meaning of the sub-structure is not evidenced.
    // UNRESOLVED: The semantic meaning of the value 2 produced by either lookup is not evidenced.
    // UNRESOLVED: The legacy ABI lead (abi:lead) names this function Short_Computation_49bad0; that naming is only a lead and is not independently corroborated.
}
