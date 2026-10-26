// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E1E0
// Canonical corpus name: CollisionGlobalInit_e1e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalInit_e1e0_0044e1e0.c

void UnknownObject::CollisionGlobalInit_e1e0()
{
    // Unconditional init of a six-dword global block: sets dword_7CCF48 to 72, zeroes the four adjacent dwords dword_7CCF4C through dword_7CCF58, sets dword_7CCF5C to 18000, and returns 0.
    // ASSIGNMENT: dword_7CCF48 = 72 (state/config id). [global:0x007CCF48, source:raw]
    // ASSIGNMENT: dword_7CCF4C = 0. [global:0x007CCF4C, source:raw]
    // ASSIGNMENT: dword_7CCF50 = 0. [global:0x007CCF50, source:raw]
    // ASSIGNMENT: dword_7CCF54 = 0. [global:0x007CCF54, source:raw]
    // ASSIGNMENT: dword_7CCF58 = 0. [global:0x007CCF58, source:raw]
    // ASSIGNMENT: dword_7CCF5C = 18000. [global:0x007CCF5C, source:raw]
    // RETURN: Return 0 (no calls, no guards; all writes unconditional). [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGlobalInit_e1e0() {
    //     dword_7CCF48 = 72;
    //     dword_7CCF4C = 0; dword_7CCF50 = 0; dword_7CCF54 = 0; dword_7CCF58 = 0;
    //     dword_7CCF5C = 18000;
    //     return 0;
    //   }
    // UNRESOLVED: The subsystem/state the six globals belong to and the meaning of the literals 72 and 18000 are not established; the existing analysis labels the block a collision object index of type 72 and dword_7CCF5C a renderer threshold of 18000 (DERIVED).
    // UNRESOLVED: No callers are recorded statically (top-level or indirect-only); frame-path membership is NOT_FOUND.
    // UNRESOLVED: The declared name CollisionGlobalInit_e1e0 carries an address-derived suffix; the semantic name is not corroborated by runtime evidence.
}
