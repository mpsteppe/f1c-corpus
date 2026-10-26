// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040EB30
// Canonical corpus name: CameraProjectionMatrixInitWithFloatConstants
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraProjectionMatrixInitWithFloatConstants_0040eb30.c

void UnknownObject::CameraProjectionMatrixInitWithFloatConstants()
{
    // Initializes a physics/collision shape structure: stores a discriminator word a2 at this+0x8, the subtype constant 3 at this+0x1C and the external data pointer a3 at this+0x20. Builds a local six-dword array of precomputed float bit patterns and stores it together with the inverse-mass scalar 15.0 via CollisionInvMassStore, then bulk-sets six more float fields via F_6FieldBulkSetter. If a4 is non-zero, delegates to ShortComputation_e770(this, a4, 0); otherwise returns a4.
    // ASSIGNMENT: Store the discriminator word a2 at this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store the subtype/kind constant 3 at this+0x1C. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Store the external data pointer a3 at this+0x20. [field:this:0x00000020, source:raw]
    // CALCULATION: Build the local six-dword constant array v6 from precomputed float bit patterns. [source:raw]
    // CALL: Store the inverse-mass scalar 15.0 and the constant float array into the collision data: CollisionInvMassStore(15.0, v6). [callee:0x00459950, source:raw]
    // CALL: Bulk-set six float fields in the collision data: F_6FieldBulkSetter(0, 1085667584, 0, 1078362112, 0, 1072693248). [callee:0x00459990, source:raw]
    // ASSIGNMENT: Copy a4 into result as the default return value. [source:raw]
    // GUARD: If a4 is non-zero, take the continuation path. [source:raw]
    // CALL: Conditional continuation computation: ShortComputation_e770(this, a4, 0); its result becomes the return value. [callee:0x0040E770, source:raw]
    // RETURN: Return result: a4 on the skipped-continuation path, or the result of ShortComputation_e770 otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   *(word*)(this + 8) = a2;
    //   *(dword*)(this + 28) = 3;
    //   *(dword*)(this + 32) = a3;
    //   v6[0..5] = { 1717986918, 1072064102, 0, 1071644672, 0, 1071644672 };
    //   CollisionInvMassStore(15.0, (int)v6);
    //   F_6FieldBulkSetter(0, 1085667584, 0, 1078362112, 0, 1072693248);
    //   result = a4;
    //   if (a4) return ShortComputation_e770(this, a4, 0);
    //   return result;
    // UNRESOLVED: The exact float semantics of the constant bit patterns passed to CollisionInvMassStore and F_6FieldBulkSetter are not confirmed by this packet.
    // UNRESOLVED: The meaning of the continuation flag a4 and the destination structure ShortComputation_e770 operates on is unknown.
}
