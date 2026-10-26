// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E180
// Canonical corpus name: CollisionStateInit2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateInit2_0044e180.c

void UnknownObject::CollisionStateInit2()
{
    // Unconditional init of a six-dword global block: sets dword_7CD1C0 to 71, zeroes the four adjacent dwords dword_7CD1C4 through dword_7CD1D0, sets dword_7CD1D4 to 9000, and returns 0.
    // ASSIGNMENT: dword_7CD1C0 = 71 (state/config id). [global:0x007CD1C0, source:raw]
    // ASSIGNMENT: dword_7CD1C4 = 0. [global:0x007CD1C4, source:raw]
    // ASSIGNMENT: dword_7CD1C8 = 0. [global:0x007CD1C8, source:raw]
    // ASSIGNMENT: dword_7CD1CC = 0. [global:0x007CD1CC, source:raw]
    // ASSIGNMENT: dword_7CD1D0 = 0. [global:0x007CD1D0, source:raw]
    // ASSIGNMENT: dword_7CD1D4 = 9000. [global:0x007CD1D4, source:raw]
    // RETURN: Return 0 (no calls, no guards; all writes unconditional). [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionStateInit2() {
    //     dword_7CD1C0 = 71;
    //     dword_7CD1C4 = 0; dword_7CD1C8 = 0; dword_7CD1CC = 0; dword_7CD1D0 = 0;
    //     dword_7CD1D4 = 9000;
    //     return 0;
    //   }
    // UNRESOLVED: The subsystem/state the six globals belong to and the meaning of the literals 71 and 9000 are not established; the existing analysis labels the block collision state type 71 and dword_7CD1D4 a toe angle of 9000 (DERIVED).
    // UNRESOLVED: No callers are recorded statically (top-level or indirect-only); frame-path membership is NOT_FOUND.
    // UNRESOLVED: The declared name CollisionStateInit2 is not corroborated by runtime evidence.
}
