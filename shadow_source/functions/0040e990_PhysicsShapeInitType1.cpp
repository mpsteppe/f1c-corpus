// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E990
// Canonical corpus name: StructInitWithFloatConstantsAndSubCalls_e990
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithFloatConstantsAndSubCalls_e990_0040e990.c

void UnknownObject::PhysicsShapeInitType1()
{
    // Initializer for a physics collision-shape sub-object (proposed type-1 shape): writes the 16-bit discriminator a2 into this+8, sets the subtype field this+28 to the constant 1, stores a3 into this+32, fills a local six-dword array v6 with constant bit patterns (0, 1071644672, -1717986918, 1069128089, 0, 1071644672), passes it with the scalar 1.2 to CollisionInvMassStore, then bulk-sets six collision-data fields via F_6FieldBulkSetter(0, 1081671680, 0, 1078198272, -1610612736, 1072273817). When a4 is non-zero it continues into ShortComputation_e770(this, a4, 0); otherwise the fall-through returns a4 (zero). Invoked by sub_40FE50 as a per-entry shape initializer.
    // ASSIGNMENT: Store the 16-bit discriminator: *(_WORD*)(this + 8) = a2. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set the subtype/kind field: *(_DWORD*)(this + 28) = 1 (the type-1 shape constant). [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Store the passed-through argument/pointer: *(_DWORD*)(this + 32) = a3. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Fill the local six-dword array v6 with the constant bit patterns 0, 1071644672, -1717986918, 1069128089, 0, 1071644672. [source:raw]
    // CALL: CollisionInvMassStore(1.2, (int)v6): store the scalar 1.2 together with the local constant array into collision data. [callee:0x00459950, source:raw]
    // CALL: F_6FieldBulkSetter(0, 1081671680, 0, 1078198272, -1610612736, 1072273817): bulk-set six fields in the collision data structure. [callee:0x00459990, source:raw]
    // GUARD: When a4 is non-zero, take the continuation path into ShortComputation_e770. [source:raw]
    // CALL: ShortComputation_e770((_DWORD*)this, a4, 0): conditional continuation computation on this. [callee:0x0040E770, source:raw]
    // RETURN: Return a4; because the guard already diverted all non-zero a4 values, the fall-through returns zero. [source:raw]
    // CALL: Invoked by sub_40FE50 (0x0040FE50) as a per-entry shape initializer. [caller:0x0040FE50, source:raw]

    // Conservative worker pseudocode:
    //   *(WORD*)(this + 8) = a2;
    //   *(DWORD*)(this + 28) = 1;
    //   *(DWORD*)(this + 32) = a3;
    //   v6[0..5] = { 0, 1071644672, -1717986918, 1069128089, 0, 1071644672 };
    //   CollisionInvMassStore(1.2, (int)v6);
    //   F_6FieldBulkSetter(0, 1081671680, 0, 1078198272, -1610612736, 1072273817);
    //   if (a4) return ShortComputation_e770(this, a4, 0);
    //   return a4;
    // UNRESOLVED: The v6 bit patterns and the F_6FieldBulkSetter arguments are float bit fields; their decoded float values are deliberately not asserted (no IEEE-754 synthesis per rules).
    // UNRESOLVED: Whether the constant 1 at this+28 is truly a physics shape 'type' enum is a prose proposal from the existing analysis, not a confirmed enum value.
    // UNRESOLVED: The concrete semantics and target structure of CollisionInvMassStore and F_6FieldBulkSetter are not confirmed from this packet.
    // UNRESOLVED: The meaning of the 16-bit discriminator a2 (written at this+8) and the passed-through value a3 (stored at this+32) is unknown.
    // UNRESOLVED: The owner class is unknown (UnknownObject).
}
