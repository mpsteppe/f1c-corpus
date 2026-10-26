// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E240
// Canonical corpus name: CollisionAntiRollInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionAntiRollInit_0044e240.c

void UnknownObject::CollisionAntiRollInit()
{
    // Unconditional init of a six-dword global block: sets dword_7CD1D8 to 73, zeroes the four adjacent dwords dword_7CD1DC through dword_7CD1E8, sets dword_7CD1EC to 27000, and returns 0.
    // ASSIGNMENT: dword_7CD1D8 = 73 (state/config id). [global:0x007CD1D8, source:raw]
    // ASSIGNMENT: dword_7CD1DC = 0. [global:0x007CD1DC, source:raw]
    // ASSIGNMENT: dword_7CD1E0 = 0. [global:0x007CD1E0, source:raw]
    // ASSIGNMENT: dword_7CD1E4 = 0. [global:0x007CD1E4, source:raw]
    // ASSIGNMENT: dword_7CD1E8 = 0. [global:0x007CD1E8, source:raw]
    // ASSIGNMENT: dword_7CD1EC = 27000. [global:0x007CD1EC, source:raw]
    // RETURN: Return 0 (no calls, no guards; all writes unconditional). [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionAntiRollInit() {
    //     dword_7CD1D8 = 73;
    //     dword_7CD1DC = 0; dword_7CD1E0 = 0; dword_7CD1E4 = 0; dword_7CD1E8 = 0;
    //     dword_7CD1EC = 27000;
    //     return 0;
    //   }
    // UNRESOLVED: The subsystem/state the six globals belong to and the meaning of the literals 73 and 27000 are not established; the existing analysis labels the block anti-roll bar state type 73 and dword_7CD1EC a wheel caster limit of 27000 (DERIVED).
    // UNRESOLVED: No callers are recorded statically (top-level or indirect-only); frame-path membership is NOT_FOUND.
    // UNRESOLVED: The declared name CollisionAntiRollInit is not corroborated by runtime evidence.
}
