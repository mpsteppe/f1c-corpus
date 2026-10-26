// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DBE0
// Canonical corpus name: CollisionParameterBlockInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionParameterBlockInit_0044dbe0.c

void UnknownObject::CollisionParameterBlockInit()
{
    // One-shot initialization of a global collision parameter block: stores the literal 48 into the leading parameter/counter slot and zeroes five adjacent following dwords. Unconditional; returns 0.
    // ASSIGNMENT: Set dword_7CCE70 to the literal 48 (parameter/counter slot). [global:0x007CCE70, source:raw]
    // ASSIGNMENT: Zero dword_7CCE74, the second field of the collision parameter block. [global:0x007CCE74, source:raw]
    // ASSIGNMENT: Zero dword_7CCE78, the third field of the collision parameter block. [global:0x007CCE78, source:raw]
    // ASSIGNMENT: Zero dword_7CCE7C, the fourth field of the collision parameter block. [global:0x007CCE7C, source:raw]
    // ASSIGNMENT: Zero dword_7CCE80, the fifth field of the collision parameter block. [global:0x007CCE80, source:raw]
    // ASSIGNMENT: Zero dword_7CCE84, the sixth field of the collision parameter block. [global:0x007CCE84, source:raw]
    // RETURN: Return the literal 0. [source:raw, function:0x0044DBE0]

    // Conservative worker pseudocode:
    //   int CollisionParameterBlockInit() {
    //     dword_7CCE70 = 48;
    //     dword_7CCE74 = 0;
    //     dword_7CCE78 = 0;
    //     dword_7CCE7C = 0;
    //     dword_7CCE80 = 0;
    //     dword_7CCE84 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic roles of the six dword_7CCE70..7CCE84 globals beyond 'collision parameter block' are not evidenced here.
    // UNRESOLVED: Owner class unknown; no static callers found (top-level or indirect-only).
    // UNRESOLVED: Function is not on a frame path; invocation context unknown.
}
