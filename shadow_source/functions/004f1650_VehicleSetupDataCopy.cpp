// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1650
// Canonical corpus name: VehicleSetupDataCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleSetupDataCopy_004f1650.c

void UnknownObject::VehicleSetupDataCopy()
{
    // Copies setup vectors from six source buffers into this vehicle object, then performs two 3x3 matrix-vector multiplications to produce transformed render coordinates. Copies a2 into +0x34D4..+0x34DC, a3 into +0x34E0..+0x34E8, memcpy 0x24 bytes from a4 into the matrix block +0x34B0..+0x34D0, a5 into +0x34EC..+0x34F4 (transformed into +0x34F8..+0x3500), a6 into +0x3504..+0x350C, a7 into +0x3534..+0x353C (transformed into +0x3540..+0x3548), and stores a8 into +0x39F0 while returning it. Called per frame from VehiclePhysicsTimeStep (004C73F0).
    // ASSIGNMENT: Copy three dwords from source vector a2 into this+0x34D4, this+0x34D8 and this+0x34DC [field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // ASSIGNMENT: Copy three dwords from source vector a3 into this+0x34E0, this+0x34E4 and this+0x34E8 [field:this:0x000034E0, field:this:0x000034E4, field:this:0x000034E8, source:raw]
    // CALL: qmemcpy of 0x24 bytes (9 dwords) from a4 into this+0x34B0, populating the orientation matrix block spanning this+0x34B0..this+0x34D0 [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // ASSIGNMENT: Copy three dwords from source vector a5 into this+0x34EC, this+0x34F0 and this+0x34F4 [field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, source:raw]
    // CALCULATION: Matrix-vector multiply for a5: computes this+0x34F8, this+0x34FC and this+0x3500 as dot products of the matrix block rows (this+0x34B0 block, plus interleaved components at this+0x34B4/0x34B8/0x34CC/0x34D0/0x34D4/0x34D8/0x34DC/0x34E0) against the a5 components at this+0x34EC/0x34F0/0x34F4 [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x000034E0, field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, source:raw]
    // ASSIGNMENT: Copy three dwords from source vector a6 into this+0x3504, this+0x3508 and this+0x350C; no transform is computed for this vector [field:this:0x00003504, field:this:0x00003508, field:this:0x0000350C, source:raw]
    // ASSIGNMENT: Copy three dwords from source vector a7 into this+0x3534, this+0x3538 and this+0x353C [field:this:0x00003534, field:this:0x00003538, field:this:0x0000353C, source:raw]
    // CALCULATION: Matrix-vector multiply for a7: computes this+0x3540, this+0x3544 and this+0x3548 as dot products of the matrix block rows against the a7 components at this+0x3534/0x3538/0x353C [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, field:this:0x000034E0, field:this:0x00003534, field:this:0x00003538, field:this:0x0000353C, field:this:0x00003540, field:this:0x00003544, field:this:0x00003548, source:raw]
    // ASSIGNMENT: Store argument a8 into this+0x39F0; a8 is also carried as the return value [field:this:0x000039F0, source:raw]
    // RETURN: Returns a8 (the value stored to this+0x39F0); invoked from VehiclePhysicsTimeStep (004C73F0) [function:0x004F1650, caller:0x004C73F0, source:raw]

    // Conservative worker pseudocode:
    //   memcpy32(this + 0x34B0, a4, 0x24);
    //   copy3(this + 0x34D4, a2); copy3(this + 0x34E0, a3);
    //   copy3(this + 0x34EC, a5); copy3(this + 0x3504, a6); copy3(this + 0x3534, a7);
    //   transform3(this + 0x34F8, matrix = this + 0x34B0, vector = a5);
    //   transform3(this + 0x3540, matrix = this + 0x34B0, vector = a7);
    //   this[0x39F0/4] = a8;
    //   return a8;
    // UNRESOLVED: Vector a6 is stored to this+0x3504..+0x350C but no transform is computed for it, unlike a5 and a7; its distinct role is unresolved
    // UNRESOLVED: a8 is both written to this+0x39F0 and returned; the semantic meaning of the returned value is unresolved
    // UNRESOLVED: The matrix block at this+0x34B0 is read in a column-interleaved order by both transforms; the exact matrix layout convention is not established here
}
