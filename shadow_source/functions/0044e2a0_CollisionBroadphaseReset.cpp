// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E2A0
// Canonical corpus name: CollisionBroadphaseReset_e2a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionBroadphaseReset_e2a0_0044e2a0.c

void UnknownObject::CollisionBroadphaseReset()
{
    // Resets a collision broadphase bucket state block at a fixed global address: stores a type tag of 74 into the first word and zeroes five following bucket-state words. Always executes unconditionally and returns 0.
    // ASSIGNMENT: Store the bucket type tag 74 into the first word of the broadphase bucket block. [global:0x007CD098]
    // ASSIGNMENT: Zero the second bucket state word. [global:0x007CD09C]
    // ASSIGNMENT: Zero the third bucket state word. [global:0x007CD0A0]
    // ASSIGNMENT: Zero the fourth bucket state word. [global:0x007CD0A4]
    // ASSIGNMENT: Zero the fifth bucket state word. [global:0x007CD0A8]
    // ASSIGNMENT: Zero the sixth bucket state word. [global:0x007CD0AC]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionBroadphaseReset() {
    //     dword_7CD098 = 74;
    //     dword_7CD09C = 0;
    //     dword_7CD0A0 = 0;
    //     dword_7CD0A4 = 0;
    //     dword_7CD0A8 = 0;
    //     dword_7CD0AC = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Identity and layout of the object owning the six-word block starting at 0x7CD098.
    // UNRESOLVED: Semantic meaning of the type tag 74 and of each of the five zeroed bucket-state words.
}
