// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DB20
// Canonical corpus name: CollisionBroadphaseReset_db20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionBroadphaseReset_db20_0044db20.c

void UnknownObject::CollisionBroadphaseReset_db20()
{
    // One-shot reset of a global collision broadphase/bucket state block: stores the literal 46 into the leading bucket-index/counter slot and zeroes five adjacent following dwords. Unconditional; returns 0.
    // ASSIGNMENT: Set dword_7CCF00 to the literal 46 (bucket index/counter slot). [global:0x007CCF00, source:raw]
    // ASSIGNMENT: Zero dword_7CCF04, the second field of the collision bucket state block. [global:0x007CCF04, source:raw]
    // ASSIGNMENT: Zero dword_7CCF08, the third field of the collision bucket state block. [global:0x007CCF08, source:raw]
    // ASSIGNMENT: Zero dword_7CCF0C, the fourth field of the collision bucket state block. [global:0x007CCF0C, source:raw]
    // ASSIGNMENT: Zero dword_7CCF10, the fifth field of the collision bucket state block. [global:0x007CCF10, source:raw]
    // ASSIGNMENT: Zero dword_7CCF14, the sixth field of the collision bucket state block. [global:0x007CCF14, source:raw]
    // RETURN: Return the literal 0. [source:raw, function:0x0044DB20]

    // Conservative worker pseudocode:
    //   int CollisionBroadphaseReset_db20() {
    //     dword_7CCF00 = 46;
    //     dword_7CCF04 = 0;
    //     dword_7CCF08 = 0;
    //     dword_7CCF0C = 0;
    //     dword_7CCF10 = 0;
    //     dword_7CCF14 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic roles of the six dword_7CCF00..7CCF14 globals beyond 'collision bucket state' are not evidenced here.
    // UNRESOLVED: Owner class unknown; no static callers found (top-level or indirect-only).
    // UNRESOLVED: Function is not on a frame path; invocation context unknown.
}
