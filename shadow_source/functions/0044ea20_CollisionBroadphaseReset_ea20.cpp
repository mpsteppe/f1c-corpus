// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044EA20
// Canonical corpus name: CollisionBroadphaseReset_ea20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionBroadphaseReset_ea20_0044ea20.c

void UnknownObject::CollisionBroadphaseReset_ea20()
{
    // Unconditional reset of the twelfth collision block, a contiguous run of six dwords at 0x007CA4B8-0x007CA4CC. Writes block tag 94 to dword_7CA4B8, then zeroes the five state fields dword_7CA4BC through dword_7CA4CC. No branches, no calls, no parameters; returns 0.
    // ASSIGNMENT: Writes the block tag 94 into dword_7CA4B8, marking this 24-byte block as collision block twelve [global:0x007CA4B8, source:raw]
    // ASSIGNMENT: Zeroes dword_7CA4BC, the first of five collision bucket/state fields following the block tag [global:0x007CA4BC, source:raw]
    // ASSIGNMENT: Zeroes dword_7CA4C0, second bucket state field [global:0x007CA4C0, source:raw]
    // ASSIGNMENT: Zeroes dword_7CA4C4, third bucket state field [global:0x007CA4C4, source:raw]
    // ASSIGNMENT: Zeroes dword_7CA4C8, fourth bucket state field [global:0x007CA4C8, source:raw]
    // ASSIGNMENT: Zeroes dword_7CA4CC, the block's terminal state field [global:0x007CA4CC, source:raw]
    // RETURN: Returns integer 0 [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CA4B8 = 94;
    //   dword_7CA4BC = 0;
    //   dword_7CA4C0 = 0;
    //   dword_7CA4C4 = 0;
    //   dword_7CA4C8 = 0;
    //   dword_7CA4CC = 0;
    //   return 0;
    // UNRESOLVED: The five zeroed globals' individual roles (the skeleton fill labels them CollisionBucketIndex, CollisionBucketState and ControlThresholdStore) are DERIVED and not verifiable from this packet alone
    // UNRESOLVED: Block tag 94 is shared across sibling collision-block initializers; whether this resets broadphase state versus another collision subsystem is not established here
}
