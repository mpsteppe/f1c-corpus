// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004361D0
// Canonical corpus name: F_3DVectorTransformBy33Matrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DVectorTransformBy33Matrix_004361d0.c

void UnknownObject::F_3DVectorTransformBy33Matrix()
{
    // Structural twin of Matrix3x3VectorMultiply (00435e00): computes the difference vector (a3 - a2), applies the 3x3 matrix stored as 9 doubles (row-major, this+0x0 through this+0x40), and writes the transformed result into a4. Row 0 sums this[0]*dx + this[1]*dy + this[2]*dz, row 1 uses this[3]/this[4]/this[5], row 2 uses this[6]/this[7]/this[8]. Returns the output pointer a4. No branches, globals, or callees; used by suspension/steering/integrator callers (SuspensionSpringDamperForceComputationWithClampi, VehicleMainPhysicsUpdate, VehiclePhysicsVelocityAngularVelocityIntegrator).
    // CALCULATION: v4 = a3[0] - a2[0] (x difference). [source:raw]
    // CALCULATION: v5 = a3[1] - a2[1] (y difference). [source:raw]
    // CALCULATION: v7 = a3[2] - a2[2] (z difference). [source:raw]
    // ASSIGNMENT: Set result = a4 (the return value is the output vector pointer). [source:raw]
    // CALCULATION: a4[0] = this[0]*v4 + this[1]*v5 + this[2]*v7 (matrix row 0, offsets +0x0/+0x8/+0x10). [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: a4[1] = this[3]*v4 + this[4]*v5 + this[5]*v7 (matrix row 1, offsets +0x18/+0x20/+0x28). [field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, source:raw]
    // CALCULATION: a4[2] = this[6]*v4 + this[7]*v5 + this[8]*v7 (matrix row 2, offsets +0x30/+0x38/+0x40). [field:this:0x00000030, field:this:0x00000038, field:this:0x00000040, source:raw]
    // RETURN: Return result (the output vector pointer a4). [source:raw]

    // Conservative worker pseudocode:
    //   dx = a3[0] - a2[0]; dy = a3[1] - a2[1]; dz = a3[2] - a2[2];
    //   a4[0] = this[0]*dx + this[1]*dy + this[2]*dz;
    //   a4[1] = this[3]*dx + this[4]*dy + this[5]*dz;
    //   a4[2] = this[6]*dx + this[7]*dy + this[8]*dz;
    //   return a4;
}
