// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056C2D0
// Canonical corpus name: F_33RotationMatrixAroundXAxis
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_33RotationMatrixAroundXAxis_0056c2d0.c

void UnknownObject::RotateMatrixAroundXAxis()
{
    // Applies an X-axis rotation to columns 1 and 2 of a 3x3 double matrix (this, 9 doubles at 8-byte stride): each column pair is recombined with sin/cos of angle a2 while column 0 is unchanged. If a3 is non-null, Euler angles are extracted to a3: -this[5] is written at a3+0 after FloatConvertWrapper, then either the gimbal-lock path (fabs(this[5]) == 1.0, using the dbl_59E420 constant) or the regular atan2 path fills a3+8 and a3+16. Used in vehicle physics suspension orientation setup; called by SuspensionDataCopyToPhysicsEngine.
    // CALCULATION: Compute v3 = sin(a2) and v5 = cos(a2). [source:raw]
    // CALCULATION: Rotate matrix column 1: this[1] (offset 0x8) = this[1]*cos + this[2]*sin; this[2] (offset 0x10) = this[2]*cos - this[1]*sin. [field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: Rotate matrix column 2: this[4] (offset 0x20) = this[4]*cos + this[5]*sin; this[5] (offset 0x28) = this[5]*cos - this[4]*sin. [field:this:0x00000020, field:this:0x00000028, source:raw]
    // CALCULATION: Rotate matrix column 3: this[7] (offset 0x38) = this[7]*cos + this[8]*sin; this[8] (offset 0x40) = this[8]*cos - this[7]*sin. Column 0 elements (0x0, 0x18, 0x30) are left unchanged. [field:this:0x00000038, field:this:0x00000040, source:raw]
    // GUARD: If a3 is non-null, perform Euler-angle extraction; otherwise the function ends after the rotation. [source:raw]
    // ASSIGNMENT: Capture v12 = this[5] (offset 0x28), call FloatConvertWrapper(this), then write the double value -v12 at a3+0. [callee:0x00588570, field:this:0x00000028, source:raw]
    // GUARD: Gimbal-lock branch: if fabs(this[5]) == 1.0 (the 1.0 constant, matching the read-only double global dbl_59E420), use the singularity Euler path; otherwise use the regular atan2 path. [field:this:0x00000028, global:0x0059E420, source:raw]
    // ASSIGNMENT: Gimbal-lock path: write a3+8 = atan2(-this[6], this[0]) (elements this 0x30 and 0x0) and zero the DWORDs at a3+16 and a3+20. [field:this:0x00000000, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Regular path: write a3+8 = atan2(this[2], this[8]) (elements this 0x10 and 0x40) and a3+16 = atan2(this[3], this[4]) (elements this 0x18 and 0x20). [field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000040, source:raw]

    // Conservative worker pseudocode:
    //   // Right-multiply 3x3 double matrix by Rx(a2): rotate columns 1 and 2.
    //   s = sin(a2); c = cos(a2);
    //   for each column pair (1,2), (4,5), (7,8):
    //       x1 = this[c0]; x2 = this[c1];
    //       this[c0] = x1*c + x2*s;
    //       this[c1] = x2*c - x1*s;
    //   if (a3) {
    //       v12 = this[5];
    //       FloatConvertWrapper(this);
    //       a3[0] = -v12;
    //       if (fabs(this[5]) == 1.0) {           /* gimbal lock * /
    //           a3[8]  = atan2(-this[6], this[0]);
    //           a3[16] = 0; a3[20] = 0;
    //       } else {
    //           a3[8]  = atan2(this[2], this[8]);
    //           a3[16] = atan2(this[3], this[4]);
    //       }
    //   }
    // UNRESOLVED: The decompiled element types mix double reads and long-double writes for the same 8-byte matrix elements; the 8-byte element stride is inferred from the offsets and matches a double matrix.
    // UNRESOLVED: The layout of the a3 output buffer is not asserted beyond the written offsets (a3+0, a3+8, a3+16, a3+20), and the mixed double/DWORD writes at a3+16/a3+20 in the gimbal branch are taken verbatim from the source.
    // UNRESOLVED: The in-place semantics of FloatConvertWrapper(this) are not analyzed here; only the captured pre-conversion value of this[5] is used for the a3+0 write.
}
