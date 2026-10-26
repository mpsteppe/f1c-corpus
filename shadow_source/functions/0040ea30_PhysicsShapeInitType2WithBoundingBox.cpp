// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040EA30
// Canonical corpus name: sub_40EA30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_40EA30_0040ea30.c

void UnknownObject::PhysicsShapeInitType2WithBoundingBox()
{
    // Physics collision-shape setup. Writes the initial discriminator state (this+0x8 = a2 type word, this+0x1C = 2 subtype constant, this+0x20 = a3 sub-struct pointer), computes bounding-box corner values through BoundingBoxComputation, derives three scaled squared-distance values (factor 0.4166666666666666, tied to the dbl_59E6F0 global at 0x0059E6F0), stores them via CollisionInvMassStore(5.0, v16), bulk-writes six constant fields through F_6FieldBulkSetter, and writes the four shape constants (89128.9609f / 0.955f pattern) into the sub-struct at this+0x20. When a4 is nonzero, ShortComputation_e770(this, a4, 0) overrides the returned value.
    // ASSIGNMENT: Write the initial discriminator state: this+0x20 = a3 (pointer to the sub-struct that receives the shape constants), this+0x8 = a2 (type/index discriminator word), this+0x1C = 2 (subtype/kind constant, shape type 2). [field:this:0x00000008, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALL: Call BoundingBoxComputation(&v8) to fill the local bounding-box corner values v8..v13 used for the distance-squared math. [callee:0x004DD550, source:raw]
    // CALCULATION: Compute squared side differences from the bounding-box locals and store three scaled distance-squared values in v16[0], v17 and v18, each scaled by 0.4166666666666666 (5/12); the scaling constant is tied to the dbl_59E6F0 (0x0059E6F0) global per the existing analysis. [callee:0x004DD550, global:0x0059E6F0, source:raw]
    // CALL: Call CollisionInvMassStore(5.0, v16) to store the three scaled distance-squared values into the collision inverse-mass slot array. [callee:0x00459950, source:raw]
    // CALL: Call F_6FieldBulkSetter(0, 1083179008, 1717986918, 1078355558, 1610612736, 1072064102) to bulk-write six constant fields of the shape sub-struct. [callee:0x00459990, source:raw]
    // ASSIGNMENT: Write the four shape constants into the sub-struct at this+0x20: elements 16 and 18 get 1202590843 (89128.9609f) and elements 17 and 19 get 1064598241 (0.955f). [field:*(this+0x20):0x00000040, field:*(this+0x20):0x00000044, field:*(this+0x20):0x00000048, field:*(this+0x20):0x0000004C, field:this:0x00000020, source:raw]
    // GUARD: If a4 is nonzero, call ShortComputation_e770(this, a4, 0) and take its return value as the function result. [callee:0x0040E770, source:raw]
    // RETURN: Return the low byte of the computed result value. [source:raw]

    // Conservative worker pseudocode:
    //   char PhysicsShapeInitType2WithBoundingBox(short a2, int a3, int a4) {
    //     *(_DWORD*)(this + 32) = a3; *(_WORD*)(this + 8) = a2; *(_DWORD*)(this + 28) = 2;
    //     BoundingBoxComputation(&bb);
    //     double dx2 = (bb.x - bb.p2x) * (bb.x - bb.p2x);
    //     double dy2 = (bb.y - bb.p2y) * (bb.y - bb.p2y);
    //     double dz2 = (bb.z - bb.p2z) * (bb.z - bb.p2z);
    //     double d[3] = {(dz2 + dy2) * 0.4166666666666666,
    //                   (dz2 + dx2) * 0.4166666666666666,
    //                   (dy2 + dx2) * 0.4166666666666666};
    //     CollisionInvMassStore(5.0, d);
    //     F_6FieldBulkSetter(0, 1083179008, 1717986918, 1078355558, 1610612736, 1072064102);
    //     int* v6 = *(int**)(this + 32);
    //     v6[16] = 1202590843; v6[17] = 1064598241; v6[18] = 1202590843; v6[19] = 1064598241;
    //     if (a4) v6 = (int*)ShortComputation_e770(this, a4, 0);
    //     return (char)v6;
    //   }
    // UNRESOLVED: The concrete geometry layout of the bounding-box locals (which of v8..v13 are x/y/z corner pairs) is not pinned by this packet.
    // UNRESOLVED: What F_6FieldBulkSetter does with its six constant arguments (which fields it writes) is not evidenced here.
    // UNRESOLVED: The semantics of the ShortComputation_e770(a4) override path are not evidenced in this packet.
}
