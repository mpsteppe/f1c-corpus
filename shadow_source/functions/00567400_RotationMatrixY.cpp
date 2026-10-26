// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567400
// Canonical corpus name: RotationMatrixY
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotationMatrixY_00567400.c

void UnknownObject::RotationMatrixY()
{
    // Right-multiplies a 3x3 row-major matrix stored in this by a rotation about the Y axis by angle a2, touching only the X and Z columns (float pairs at this[0]/this[2], this[3]/this[5], this[6]/this[8]). After calling FloatConvertWrapper on the matrix, extracts Euler angles into the output buffer a3: yaw is written as the negated sin of the Y rotation, then either the gimbal-lock singularity path (when fabs(this[5]) equals 1.0) or the general atan2-based path computes pitch and roll.
    // CALCULATION: Compute sin(a2) and cos(a2) for the Y rotation angle. [source:raw]
    // CALCULATION: Rotate the first column pair: new this[0] = this[0]*cos - this[2]*sin, new this[2] = this[2]*cos + this[0]*sin. [source:raw, field:this:0x00000000, field:this:0x00000008]
    // CALCULATION: Rotate the second column pair: new this[3] = this[3]*cos - this[5]*sin, new this[5] = this[5]*cos + this[3]*sin. [source:raw, field:this:0x0000000C, field:this:0x00000014]
    // CALCULATION: Rotate the third column pair: new this[6] = this[6]*cos - this[8]*sin, new this[8] = this[8]*cos + this[6]*sin. [source:raw, field:this:0x00000018, field:this:0x00000020]
    // CALL: Call FloatConvertWrapper(this) to normalize or convert the rotated matrix before Euler extraction. [source:raw, callee:0x00588570]
    // ASSIGNMENT: Write the yaw component as the negated post-rotation this[5] value into the output buffer at a3. [source:raw, field:this:0x00000014]
    // GUARD: Gimbal-lock guard: branch on fabs(this[5]) being equal to 1.0, with 1.0 backed by dbl_59E420. [source:raw, global:0x0059E420, field:this:0x00000014]
    // CALCULATION: Singularity path: compute pitch as atan2(-this[6], this[0]), write it to a3+4, and clear the roll component at a3+8 to 0. [source:raw, field:this:0x00000018, field:this:0x00000000]
    // CALCULATION: General path: compute pitch as atan2(this[2], this[8]) into a3+4 and roll as atan2(this[3], this[4]) into a3+8. [source:raw, field:this:0x00000008, field:this:0x00000020, field:this:0x0000000C, field:this:0x00000010]

    // Conservative worker pseudocode:
    //   void sub_567400(float *m, float angle, int out) {
    //     float s = sin(angle), c = cos(angle);
    //     rot2(m[0], m[2], s, c);
    //     rot2(m[3], m[5], s, c);
    //     rot2(m[6], m[8], s, c);
    //     FloatConvertWrapper(m);
    //     *(float*)out = -m[5];
    //     if (fabs(m[5]) == 1.0) {
    //       *(int*)(out + 8) = 0;
    //       *(float*)(out + 4) = atan2(-m[6], m[0]);
    //     } else {
    //       *(float*)(out + 4) = atan2(m[2], m[8]);
    //       *(float*)(out + 8) = atan2(m[3], m[4]);
    //     }
    //   }
    //   // rot2(a, b): a' = a*c - b*s; b' = b*c + a*s
    // UNRESOLVED: Output buffer layout at a3 is only partially resolved: yaw at a3, pitch at a3+4, roll at a3+8; the a3+8 zero write in the singularity path is an int32 while other writes are floats.
    // UNRESOLVED: What FloatConvertWrapper mutates in the matrix before Euler extraction is external to this function.
}
