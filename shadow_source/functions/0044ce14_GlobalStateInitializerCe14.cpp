// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CE14
// Canonical corpus name: GlobalStateInitializer_ce14
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateInitializer_ce14_0044ce14.c

void UnknownObject::GlobalStateInitializerCe14()
{
    // Straight-line initializer at 0x0044CE14: stores the raw 32-bit integer -1082130432 into dword_7CA440 and zeroes the adjacent float flt_7CA444. Called by SpatialNodeInitCe00 per that function's raw source. No branches and no callees.
    // ASSIGNMENT: Set dword_7CA440 = -1082130432, a raw 32-bit constant (spelled as a signed decimal integer in the raw source; likely a float bit pattern). [global:0x007CA440, source:raw]
    // ASSIGNMENT: Set flt_7CA444 = 0.0, zeroing the float field adjacent to dword_7CA440. [global:0x007CA444, source:raw]

    // Conservative worker pseudocode:
    //   void GlobalStateInitializerCe14() {
    //     dword_7CA440 = -1082130432;
    //     flt_7CA444 = 0.0;
    //   }
    // UNRESOLVED: The semantic meaning of the raw constant -1082130432 (a -1.0f float bit pattern if interpreted as IEEE-754) is not determinable from this function alone; it is preserved in its packet spelling.
    // UNRESOLVED: The packet lists no callers, so the full call chain invoking this initializer is unknown beyond the named call site in SpatialNodeInitCe00's raw source.
}
