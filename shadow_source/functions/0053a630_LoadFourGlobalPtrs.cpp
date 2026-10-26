// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053A630
// Canonical corpus name: ArithmeticComparison_a630
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_a630_0053a630.c

void UnknownObject::LoadFourGlobalPtrs()
{
    // Straight-line getter: writes four global values/pointers into four output parameters and returns 0. No branches, no calls, argument a5 unused. Called by sub_537110 (0x00537110) on the frame path. Reads dword_5DA998 and dword_5DA99C as values and the addresses of unk_5DA9A0 and unk_5DB9A0.
    // ASSIGNMENT: *a1 = dword_5DA998: first output parameter (this+0x0) receives the global value at 0x005DA998 [abi:lead, field:this:0x00000000, global:0x005DA998, source:raw]
    // ASSIGNMENT: *a2 = dword_5DA99C: second output parameter receives the global value at 0x005DA99C [global:0x005DA99C, source:raw]
    // ASSIGNMENT: *a3 = &unk_5DA9A0: third output parameter receives the address of the global at 0x005DA9A0 [global:0x005DA9A0, source:raw]
    // ASSIGNMENT: *a4 = &unk_5DB9A0: fourth output parameter receives the address of the global at 0x005DB9A0 [global:0x005DB9A0, source:raw]
    // RETURN: Return 0; input parameter a5 is never read [source:raw]

    // Conservative worker pseudocode:
    //   *a1 = dword_5DA998;
    //   *a2 = dword_5DA99C;
    //   *a3 = &unk_5DA9A0;
    //   *a4 = &unk_5DB9A0;
    //   return 0;
    // UNRESOLVED: Semantic role of the four globals (plain constants vs. pointers to tables) is not established; existing analysis labels them DERIVED.
    // UNRESOLVED: Parameter a5 is accepted but never referenced in the function body.
}
