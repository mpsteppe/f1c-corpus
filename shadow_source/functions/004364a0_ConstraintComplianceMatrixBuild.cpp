// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004364A0
// Canonical corpus name: ConstraintComplianceMatrixBuild
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstraintComplianceMatrixBuild_004364a0.c

void UnknownObject::ConstraintComplianceMatrixBuild()
{
    // Builds a 3x5 constraint compliance matrix as 15 doubles (this[0..14]) from constraint parameters: products of input scalars and a5 vector components fill this[0]..this[12] (fields +0x0..+0x60), and this[13]/this[14] (fields +0x68/+0x70) are sums normalized by 1/sqrt(a2). Returns nonzero if any of the first 13 entries is non-zero, indicating non-zero constraint compliance. Called from sub_43C250 (0043C250).
    // CALCULATION: Matrix entry [0][0]: v20 = a3*a6; this[0] = v20 (field +0x0) [field:this:0x00000000, source:raw]
    // CALCULATION: Matrix entries [0][1] and [0][2]: this[1] = a4*a8 (field +0x8); this[2] = a9*a4 (field +0x10) [field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: Matrix entries [1][0] and [1][1]: v15 = a2*a5[6]; this[3] = v15 (field +0x18); this[4] = (a9*a4 - a4*a8) * v15 (field +0x20) [field:this:0x00000018, field:this:0x00000020, source:raw]
    // CALCULATION: Matrix entries [1][2], [2][0], [2][1] and [2][2]: v21 = a10*a4; this[5] = v21 (field +0x28); v22 = a4*a11; this[6] = v22 (field +0x30); v16 = a2*a5[7]; this[7] = v16 (field +0x38); this[8] = (a4*a11 - a10*a4) * v16 (field +0x40) [field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, field:this:0x00000040, source:raw]
    // CALCULATION: Matrix entries [3][0], [3][1], [4][0] and [4][1]: this[9] = a3*a5[2] (field +0x48); this[10] = a3*a5[3] (field +0x50); this[11] = a4*a5[4] (field +0x58); this[12] = a4*a5[5] (field +0x60) [field:this:0x00000048, field:this:0x00000050, field:this:0x00000058, field:this:0x00000060, source:raw]
    // CALCULATION: Normalized constraint rows: v17 = 1.0 / sqrt(a2); this[13] = (a12 + a5[0] + a13 - a7) * v17 (field +0x68); this[14] = (a12 + a5[1] + a13) * v17 (field +0x70) [field:this:0x00000068, field:this:0x00000070, source:raw]
    // RETURN: Returns nonzero if any of the matrix entries this[0]..this[12] (fields +0x0..+0x60) is non-zero, indicating non-zero constraint compliance; called by sub_43C250 (0043C250) [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, field:this:0x00000040, field:this:0x00000048, field:this:0x00000050, field:this:0x00000058, field:this:0x00000060, function:0x004364A0, caller:0x0043C250, source:raw]

    // Conservative worker pseudocode:
    //   this[0]  = a3*a6;
    //   this[1]  = a4*a8; this[2] = a9*a4;
    //   this[3]  = a2*a5[6]; this[4] = (a9*a4 - a4*a8) * (a2*a5[6]);
    //   this[5]  = a10*a4; this[6] = a4*a11;
    //   this[7]  = a2*a5[7]; this[8] = (a4*a11 - a10*a4) * (a2*a5[7]);
    //   this[9]  = a3*a5[2]; this[10] = a3*a5[3];
    //   this[11] = a4*a5[4]; this[12] = a4*a5[5];
    //   v17 = 1.0 / sqrt(a2);
    //   this[13] = (a12 + a5[0] + a13 - a7) * v17;
    //   this[14] = (a12 + a5[1] + a13) * v17;
    //   return this[0] != 0.0 || this[1] != 0.0 || ... || this[12] != 0.0;
    // UNRESOLVED: Read-only globals dbl_59E420 and dbl_59E430 are flagged by packet facts but do not appear in the raw decompiled source
    // UNRESOLVED: The meaning of the a2..a13 parameters and the a5 vector is inferred only from the compliance-matrix output shape; the caller sub_43C250 defines their semantic roles
}
