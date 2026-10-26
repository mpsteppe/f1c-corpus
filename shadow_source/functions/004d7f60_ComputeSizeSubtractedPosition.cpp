// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7F60
// Canonical corpus name: SizeComputationWithSubtraction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SizeComputationWithSubtraction_004d7f60.c

void UnknownObject::ComputeSizeSubtractedPosition()
{
    // UI text-layout helper on the UITextRenderWithScale (004D7E40) path, sibling of the centering helper at 004D7F20. Resolves an owner object via SwitchBasedGlobalLookup(a4); only when non-null it measures text through sub_5531F0 into a4, then stores a2 - a4 into *a3 (extent minus measured size) and returns a3. On a null lookup it returns null and leaves a3 untouched.
    // CALL: Resolve the owner object by key a4 through SwitchBasedGlobalLookup; the non-null result gates the whole body [callee:0x004D7FA0, source:raw]
    // GUARD: If the global lookup returned null, skip the body and return that null result directly [source:raw]
    // CALL: Measure text metrics for context a1, writing the measured size back through &a4 and the re-derived context through &a1, with a 0 flag [callee:0x005531F0, source:raw]
    // CALCULATION: Computed position: *a3 = a2 - a4 (extent minus full measured size) [source:raw]
    // ASSIGNMENT: Store the computed position into the output slot *a3 [source:raw]
    // RETURN: Return a3 (the output slot pointer) so the caller can chain on the stored value [source:raw]
    // CALL: Invoked from UITextRenderWithScale (004D7E40) as part of scaled text layout [caller:0x004D7E40, source:raw]

    // Conservative worker pseudocode:
    //   obj = SwitchBasedGlobalLookup(a4);
    //   if (!obj) return null;
    //   sub_5531F0(a1, &a4, &a1, 0);   // measure text; a4 <- size
    //   *a3 = a2 - a4;                 // subtract full size from extent
    //   return a3;
    // UNRESOLVED: The exact meaning of a1 and the third argument (address-of a1) inside sub_5531F0 is not verifiable from this function alone; a4 is reused as both the lookup key and the measured size output
    // UNRESOLVED: Whether the stored result is a right-aligned position or a remaining-size value is not distinguishable from the raw source alone
    // UNRESOLVED: The relationship to the centering sibling 004D7F20 (which halves a4 before subtracting) is evident in the raw source but the calling context that selects one over the other is not present here
}
