// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DFA60
// Canonical corpus name: ConditionalAudioParamSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalAudioParamSetup_004dfa60.c

void UnknownObject::ConditionalAudioParamSetup()
{
    // Conditional audio/transform setup for a vehicle audio object. Stores parameter a2 into byte field this+0x42 unconditionally, then branches on the object pointer at this+0x00. When the pointer is valid: optionally mixes audio physics via AudioPhysicsMixWithLerp, runs DualMatrixTransformMultiply across six consecutive DWORD fields this+0x04..this+0x18, sets the transform-ready flag this+0x40 to 1, reads flag bits via BitFlagReader into byte this+0x41, and builds a rotation matrix with EulerToRotationMatrix. When the pointer is null: zeroes the six DWORD fields and both flag bytes, then builds the same rotation matrix. Called by VehicleGraphicsSceneLoader (004DFCE0).
    // ASSIGNMENT: Parameter a2 stored into byte field this+0x42 unconditionally, before any branching [field:this:0x00000042, source:raw]
    // GUARD: Branches on the object pointer at this+0x00: non-zero takes the full setup path, zero takes the clear path [field:this:0x00000000, source:raw]
    // CALL: Setup path: when flag byte a3 is non-zero, AudioPhysicsMixWithLerp is called with the object pointer and argument a4 to mix audio physics [callee:0x0040E2B0, source:raw]
    // CALL: DualMatrixTransformMultiply applied over the six consecutive DWORD fields this+0x04..this+0x18, computing the dual-matrix transforms [callee:0x0054B530, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Setup path sets the transform-ready flag byte this+0x40 to 1 [field:this:0x00000040, source:raw]
    // CALL: BitFlagReader runs on the a3/a2 locals and its result is stored as byte this+0x41 set to (a2 != 0) [callee:0x0054C0B0, field:this:0x00000041, source:raw]
    // CALL: Both paths terminate by building a rotation matrix with EulerToRotationMatrix from the this+0x10 source into this+0x1C destination (this+4 / this+7 dword indices) [callee:0x00566E40, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Clear path zeroes the six DWORD fields this+0x04..this+0x18 [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Clear path sets both flag bytes this+0x40 and this+0x41 to 0 [field:this:0x00000040, field:this:0x00000041, source:raw]
    // CALL: Invoked by VehicleGraphicsSceneLoader (004DFCE0) during vehicle graphics scene setup [caller:0x004DFCE0, source:raw]

    // Conservative worker pseudocode:
    //   this[0x42] = a2;
    //   obj = this[0];
    //   if (obj) {
    //       if (a3) AudioPhysicsMixWithLerp(obj, a4);
    //       DualMatrixTransformMultiply(this+1, this+2, this+3, this+4, this+5, this+6);
    //       this[0x40] = 1;
    //       BitFlagReader(&a3, &a2);
    //       this[0x41] = (a2 != 0);
    //   } else {
    //       this[1..6] = 0;
    //       this[0x40] = 0; this[0x41] = 0;
    //   }
    //   EulerToRotationMatrix(this+4, this+7);
    // UNRESOLVED: The semantics of the BitFlagReader output byte this+0x41 are unknown; only the (a2 != 0) store is visible
    // UNRESOLVED: The object at this+0x00 is used purely as a validity check; its concrete type is not defined in this packet
    // UNRESOLVED: The EulerToRotationMatrix destination at this+0x1C is reachable only through the this+7 dword index and is not enumerated as a field in this packet
}
