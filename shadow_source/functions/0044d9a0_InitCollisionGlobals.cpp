// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D9A0
// Canonical corpus name: CollisionGlobalsInit1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalsInit1_0044d9a0.c

void UnknownObject::InitCollisionGlobals()
{
    // Zero-argument collision-globals initializer. Writes 42 to the first dword of the global block at dword_7CCF30 and zeroes the five following dwords (dword_7CCF34 through dword_7CCF44). Returns 0. Not reached from the tick root frame path; static callers are unknown.
    // ASSIGNMENT: Set dword_7CCF30[0] to the collision init literal 42 [global:0x007CCF30, source:raw]
    // ASSIGNMENT: Zero the collision counter/parameter field dword_7CCF34 [global:0x007CCF34, source:raw]
    // ASSIGNMENT: Zero the collision counter/parameter field dword_7CCF38 [global:0x007CCF38, source:raw]
    // ASSIGNMENT: Zero the collision counter/parameter field dword_7CCF3C [global:0x007CCF3C, source:raw]
    // ASSIGNMENT: Zero the collision counter/parameter field dword_7CCF40 [global:0x007CCF40, source:raw]
    // ASSIGNMENT: Zero the collision counter/parameter field dword_7CCF44 [global:0x007CCF44, source:raw]
    // RETURN: Return 0 as the initialization result [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalsInit1() {
    //     dword_7CCF30[0] = 42;
    //     dword_7CCF34 = 0;
    //     dword_7CCF38 = 0;
    //     dword_7CCF3C = 0;
    //     dword_7CCF40 = 0;
    //     dword_7CCF44 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of the magic value 42 written to dword_7CCF30[0] is unknown.
    // UNRESOLVED: Owning class of the collision global block is unknown; owner stays UnknownObject.
    // UNRESOLVED: The block's collision semantics are DERIVED from the vehicle subsystem tag and the existing-analysis prose only, not proven by static or runtime evidence.
}
