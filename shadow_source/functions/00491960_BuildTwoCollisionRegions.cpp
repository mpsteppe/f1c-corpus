// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491960
// Canonical corpus name: DualDispatchWithGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualDispatchWithGuard_00491960.c

void UnknownObject::BuildTwoCollisionRegions()
{
    // Validates that a4 and a5 are both positive, then invokes CollisionBroadphaseBuilder twice with the same four arguments (a2, a3, a4, a5). The first call passes the builder pointer stored at this[0] + 28 and the second the one at this[0] + 44. Returns 1 on success and 0 when the dimension guard fails.
    // GUARD: Reject the call when a4 is not greater than 0 or a5 is not greater than 0. [source:raw]
    // RETURN: Return 0 when either dimension guard fails. [source:raw, function:0x00491960]
    // CALL: Call CollisionBroadphaseBuilder with the first builder pointer located at this[0] + 28 (reading the object pointer at offset 0, then advancing 28 bytes), plus a2, a3, a4, a5. [field:this:0x00000000, callee:0x00490EE0, source:raw]
    // CALL: Call CollisionBroadphaseBuilder with the second builder pointer located at this[0] + 44, plus a2, a3, a4, a5. [field:this:0x00000000, callee:0x00490EE0, source:raw]
    // RETURN: Return 1 after both CollisionBroadphaseBuilder calls complete. [source:raw, function:0x00491960]

    // Conservative worker pseudocode:
    //   if (a4 <= 0 || a5 <= 0) return 0;
    //   CollisionBroadphaseBuilder((void***)(this[0] + 28), a2, a3, a4, a5);
    //   CollisionBroadphaseBuilder((void***)(this[0] + 44), a2, a3, a4, a5);
    //   return 1;
    // UNRESOLVED: The type and layout of the object referenced by this[0] are not established by the packet; the two builder pointers at +28 and +44 are read but their meaning is unknown.
    // UNRESOLVED: The cluster_copy prelabel (structural twin of 00404f70, DERIVED) names this a dual dispatch, but the static call target 0x00490EE0 is identical for both calls, so the +28/+44 values are arguments, not distinct call targets.
    // UNRESOLVED: The canonical name 'DualDispatchWithGuard' and the CollisionBroadphaseBuilder callee label suggest collision-region building, but that is labeling, not independent evidence.
    // UNRESOLVED: Whether a4/a5 are dimensions and a2/a3 coordinates is not proven by this packet.
}
