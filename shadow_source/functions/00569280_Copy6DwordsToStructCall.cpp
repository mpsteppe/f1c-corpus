// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00569280
// Canonical corpus name: Copy6DwordsToStructCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Copy6DwordsToStructCall_00569280.c

void UnknownObject::Copy6DwordsToStructCall()
{
    // Copies 0x18 (24) bytes / 6 dwords from a2 into this+124, then calls InertiaTensorWorldSpaceTransform (0x00569410) on this and returns its result. Called by physics state conversion and vehicle joint system loader code.
    // ASSIGNMENT: Copy 0x18 bytes (6 dwords) from a2 into this + 124 [source:raw]
    // CALL: Call InertiaTensorWorldSpaceTransform(this) after the copy [callee:0x00569410, source:raw]
    // RETURN: Return the result of InertiaTensorWorldSpaceTransform [callee:0x00569410, source:raw]

    // Conservative worker pseudocode:
    //   int Copy6DwordsToStructCall(int this, const void *a2) {
    //     qmemcpy((void *)(this + 124), a2, 0x18);
    //     return InertiaTensorWorldSpaceTransform(this);
    //   }
    // UNRESOLVED: Content and semantics of the 6-dword block at this+124 not evidenced; caller PhysicsStateVectorConversion hints at physics state but no packet evidence ties it.
}
