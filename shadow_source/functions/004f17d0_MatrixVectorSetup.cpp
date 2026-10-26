// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F17D0
// Canonical corpus name: MatrixVectorSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MatrixVectorSetup_004f17d0.c

void UnknownObject::MatrixVectorSetup()
{
    // Copies a 3x3 rotation matrix (0x24 bytes) from a2 into this+0x34B0, copies a 3-component input vector from a3 into this+0x3534..0x353C, then computes the matrix-by-vector product into this+0x3540..0x3548 and returns a pointer to the stored matrix. Called from the per-frame vehicle physics time step.
    // ASSIGNMENT: Copy 0x24 bytes (nine floats) of the rotation matrix from a2 into this+0x34B0..0x34D0 (offsets 13488 onward, R). [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // ASSIGNMENT: Store input vector components from a3: a3[0] to this+0x3534, a3[1] to this+0x3538, a3[2] to this+0x353C (offsets 13620/13624/13628). [field:this:0x00003534, field:this:0x00003538, field:this:0x0000353C, source:raw]
    // CALCULATION: Output X at this+0x3540 = this[0x34B0]*this[0x3534] + this[0x34B4]*this[0x3538] + this[0x34B8]*this[0x353C] (first matrix row dotted with the input vector). [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x00003534, field:this:0x00003538, field:this:0x0000353C, field:this:0x00003540, source:raw]
    // CALCULATION: Output Y at this+0x3544 = this[0x34BC]*this[0x3534] + this[0x34C0]*this[0x3538] + this[0x34C4]*this[0x353C] (second matrix row dotted with the input vector). [field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x00003534, field:this:0x00003538, field:this:0x0000353C, field:this:0x00003544, source:raw]
    // CALCULATION: Output Z at this+0x3548 = this[0x34C8]*this[0x3534] + this[0x34CC]*this[0x3538] + this[0x34D0]*this[0x353C] (third matrix row dotted with the input vector). [field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x00003534, field:this:0x00003538, field:this:0x0000353C, field:this:0x00003548, source:raw]
    // RETURN: Return a pointer to the copied rotation matrix (this + 13488, i.e. this+0x34B0). [field:this:0x000034B0, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   qmemcpy(this + 0x34B0, a2, 0x24);
    //   this[0x3534] = a3[0]; this[0x3538] = a3[1]; this[0x353C] = a3[2];
    //   this[0x3540] = M[0][0]*v.x + M[0][1]*v.y + M[0][2]*v.z;
    //   this[0x3544] = M[1][0]*v.x + M[1][1]*v.y + M[1][2]*v.z;
    //   this[0x3548] = M[2][0]*v.x + M[2][1]*v.y + M[2][2]*v.z;
    //   return this + 0x34B0;
    // UNRESOLVED: Caller VehiclePhysicsTimeStep (004c73f0) invokes this per frame; exact role of the output vector in the physics step is not in the packet.
}
