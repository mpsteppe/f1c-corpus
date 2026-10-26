// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EF6C0
// Canonical corpus name: CoordinateTransformWithOffset
// Owner: VehiclePhysicsTransform [DERIVED]
// Raw source: functions/CoordinateTransformWithOffset_004ef6c0.c

void VehiclePhysicsTransform::transformCoordinateWithOffset()
{
    // Transforms a coordinate vector: builds a 3x3 rotation matrix from Euler input a3 via EulerToRotationMatrix, computes the ride-height delta 3-vector via RideHeightDelta, rotates that delta by the matrix, adds the position offset at this+0x34D4..0x34DC, and writes into a4 the difference between (a2 + position offset) and the transformed vector. On the per-frame physics path.
    // CALL: Invoke EulerToRotationMatrix(a3, v17) to convert the Euler angles in a3 into the 3x3 rotation matrix stored in v17. [callee:0x00566E40, source:raw]
    // CALL: Invoke RideHeightDelta(this, &v13) to compute the ride-height delta 3-vector into v13/v14/v15. [callee:0x004EF680, source:raw]
    // CALCULATION: Rotate the ride-height delta by the rotation matrix: v5 = v17[0]*v13 + v17[1]*v14 + v17[2]*v15, v6 = v17[3]*v13 + v17[4]*v14 + v17[5]*v15, v15 = v17[6]*v13 + v17[7]*v14 + v17[8]*v15. [source:raw]
    // CALCULATION: Add the position offset to the rotated delta: v13 = v5 + this[3381], v7 = v6 + this[3382], v8 = v15 + this[3383], reading offset components at this+0x34D4..0x34DC. [field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // CALCULATION: Build the comparison vector from a2 plus the same position offset: v9 = this[3381] + a2[0], v10 = this[3382] + a2[1], v16 = this[3383] + a2[2]. [field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // CALCULATION: Compute and store the output vector: a4[0] = v9 - v13, a4[1] = v10 - v7, a4[2] = v16 - v8. [source:raw]
    // RETURN: Return LODWORD(v14), the low DWORD of the y-component; an x87 codegen artifact rather than a meaningful value. [source:raw]

    // Conservative worker pseudocode:
    //   EulerToRotationMatrix(a3, v17);
    //   RideHeightDelta(this, &v13);
    //   (v5, v6, v15) = v17 * (v13, v14, v15);
    //   (v13, v7, v8) = (v5, v6, v15) + (this[3381], this[3382], this[3383]);
    //   (v9, v10, v16) = (this[3381], this[3382], this[3383]) + (a2[0], a2[1], a2[2]);
    //   a4[0] = v9 - v13; a4[1] = v10 - v7; a4[2] = v16 - v8;
    //   return LODWORD(v14);
    // UNRESOLVED: The meaning of a2 (a world-space coordinate?) and whether a4 algebraically reduces to a2 minus the rotated ride-height delta (the position offset cancels) is DERIVED, not proven by the packet.
    // UNRESOLVED: The Euler angle ordering and angular units of a3 are not visible from the packet.
    // UNRESOLVED: Returning LODWORD(v14) is an artifact of x87 register preservation, not a meaningful result.
}
