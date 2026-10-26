// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7F20
// Canonical corpus name: CenteredPosition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CenteredPosition_004d7f20.c

void UnknownObject::ComputeCenteredTextPosition()
{
    // UI text-layout helper on the UITextRenderWithScale (004D7E40) path. Resolves a per-owner object via SwitchBasedGlobalLookup(a4), and only when non-null measures the text through sub_5531F0 into a4 (and re-derived a1), then stores the horizontally centered position a2 - a4/2 into *a3 and returns a3. When the lookup fails it returns the null lookup result and leaves a3 untouched.
    // CALL: Resolve the owner object by key a4 through SwitchBasedGlobalLookup; the non-null result gates the whole body [callee:0x004D7FA0, source:raw]
    // GUARD: If the global lookup returned null, skip the body and return that null result directly [source:raw]
    // CALL: Measure text metrics for context a1, writing the measured size back through &a4 and the re-derived context through &a1, with a 0 flag [callee:0x005531F0, source:raw]
    // CALCULATION: Centered offset: a4 / 2 yields half the measured size, then *a3 = a2 - (a4 / 2) [source:raw]
    // ASSIGNMENT: Store the computed centered position into the output slot *a3 [source:raw]
    // RETURN: Return a3 (the output slot pointer) so the caller can chain on the stored value [source:raw]
    // CALL: Invoked from UITextRenderWithScale (004D7E40) as part of scaled text layout [caller:0x004D7E40, source:raw]

    // Conservative worker pseudocode:
    //   obj = SwitchBasedGlobalLookup(a4);
    //   if (!obj) return null;
    //   sub_5531F0(a1, &a4, &a1, 0);   // measure text; a4 <- size
    //   *a3 = a2 - a4 / 2;             // center within extent
    //   return a3;
    // UNRESOLVED: The exact meaning of a1 and the third argument (address-of a1) inside sub_5531F0 is not verifiable from this function alone; a4 is reused as both the lookup key and the measured size output
    // UNRESOLVED: The units of a2 and a4 (pixels vs scaled units) depend on the UI scaling context of UITextRenderWithScale and are not established here
}
