// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567340
// Canonical corpus name: RotationMatrixYAxisRotationEulerExtraction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotationMatrixYAxisRotationEulerExtraction_00567340.c

void UnknownObject::ApplyXAxisRotationThenExtractEulerAngles()
{
    // Rotates a 3x3 row-major float matrix (this) about the X axis by angle a2 as a right-multiply (columns 1 and 2 are rotated with sin/cos, column 0 is unchanged), then extracts Euler angles into output buffer a3. The gimbal-lock branch (fabs of element [1][2] == 1.0) writes zero for one angle and atan2(-this[6], this[0]); the regular branch writes atan2 values from elements [0][2], [2][2], [1][0], [1][1]. FloatConvertWrapper is invoked on the matrix before the output writes. Called by camera, suspension-parameter and wheel-suspension update paths.
    // CALCULATION: Compute v3 = sin(a2) and v5 = cos(a2). [source:raw]
    // CALCULATION: Rotate matrix column 1: this[1] (offset 0x4) = this[1]*cos + this[2]*sin; this[2] (offset 0x8) = this[2]*cos - this[1]*sin. [field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Rotate matrix column 2: this[4] (offset 0x10) = this[4]*cos + this[5]*sin; this[5] (offset 0x14) = this[5]*cos - this[4]*sin. [field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALCULATION: Rotate matrix column 3: this[7] (offset 0x1C) = this[7]*cos + this[8]*sin; this[8] (offset 0x20) = this[8]*cos - this[7]*sin. Column 0 elements (0x0, 0xC, 0x18) are left unchanged. [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALL: Call FloatConvertWrapper(this), converting the matrix in place; the value v12 = this[5] (offset 0x14) is captured before the call and used for the a3+0 write. [callee:0x00588570, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write the float value -v12 (negative of pre-conversion this[5]) to a3+0. [field:this:0x00000014, source:raw]
    // GUARD: Gimbal-lock branch: if fabs(this[5]) == 1.0 (the 1.0 constant, matching the read-only double global dbl_59E420), use the singularity Euler path; otherwise use the regular atan2 path. [field:this:0x00000014, global:0x0059E420, source:raw]
    // ASSIGNMENT: Gimbal-lock path: write a3+4 = atan2(-this[6], this[0]) (using element this 0x18 and element this 0x0) and zero the DWORD at a3+8. [field:this:0x00000000, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Regular path: write a3+4 = atan2(this[2], this[8]) (elements this 0x8 and 0x20) and a3+8 = atan2(this[3], this[4]) (elements this 0xC and 0x10). [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000020, source:raw]

    // Conservative worker pseudocode:
    //   // Right-multiply row-major matrix by Rx(a2): rotate columns 1 and 2.
    //   s = sin(a2); c = cos(a2);
    //   for each column pair (1,2), (4,5), (7,8):
    //       x1 = this[c0]; x2 = this[c1];
    //       this[c0] = x1*c + x2*s;
    //       this[c1] = x2*c - x1*s;
    //   v12 = this[5];
    //   FloatConvertWrapper(this);
    //   a3[0] = -v12;
    //   if (fabs(this[5]) == 1.0) {           /* gimbal lock * /
    //       a3[1] = atan2(-this[6], this[0]);
    //       a3[2] = 0;
    //   } else {
    //       a3[1] = atan2(this[2], this[8]);
    //       a3[2] = atan2(this[3], this[4]);
    //   }
    // UNRESOLVED: The canonical name says Y-axis rotation, but the observed math rotates columns 1 and 2 while column 0 is unchanged, i.e. a right-multiply about the X axis; the naming discrepancy is not resolved.
    // UNRESOLVED: The layout of the a3 output buffer is not asserted beyond the written offsets (a3+0, a3+4, a3+8).
    // UNRESOLVED: The in-place semantics of FloatConvertWrapper(this) are not analyzed here; only the captured pre-conversion value of this[5] is used for the a3+0 write.
}
