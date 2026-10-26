// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005674C0
// Canonical corpus name: RotateMatrixAndExtractAngles
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RotateMatrixAndExtractAngles_005674c0.c

void UnknownObject::RotateMatrixAndExtractAngles()
{
    // Rotates the first two columns of a 3x3 matrix (elements 0..1, 3..4, 6..7) by angle a2 using sin/cos, converts float elements via FloatConvertWrapper, and extracts Euler-like angles into the output at a3. Writes pitch = -this[5]; in the gimbal-lock case fabs(this[5]) == 1.0 it writes zero to a3+8 and yaw to a3+4 from atan2(-this[6], this[0]), otherwise it writes yaw = atan2(this[2], this[8]) and roll = atan2(this[3], this[4]).
    // CALCULATION: Compute sin(a2) and cos(a2) for the rotation. [source:raw]
    // CALCULATION: Rotate the first two columns of the matrix: for each of the three pairs (this[0],this[1]), (this[3],this[4]), (this[6],this[7]) apply new = old*cos + other*sin and other = other*cos - old*sin. [field:this:0x00000000, field:this:0x00000004, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // CALL: Call FloatConvertWrapper(this) on the matrix. [callee:0x00588570, source:raw]
    // ASSIGNMENT: Write *(float*)a3 = -this[5] (the saved center-column element) as the output pitch value. [field:this:0x00000014, source:raw]
    // GUARD: Branch on fabs(this[5]) == 1.0 (comparing against constant dbl_59E420), the gimbal-lock condition. [field:this:0x00000014, global:0x0059E420, source:raw]
    // CALCULATION: Gimbal-lock branch: write zero to a3+8 and a3+4 = atan2(-this[6], this[0]). [field:this:0x00000018, field:this:0x00000000, source:raw]
    // CALCULATION: Non-gimbal-lock branch: write a3+4 = atan2(this[2], this[8]) and a3+8 = atan2(this[3], this[4]). [field:this:0x00000008, field:this:0x00000020, field:this:0x0000000C, field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5674C0(float* this, float a2, int a3) {
    //     float s = sin(a2), c = cos(a2);
    //     for each row r in {0,3,6}:
    //       float a = this[r], b = this[r+1];
    //       this[r] = a*c + b*s; this[r+1] = b*c - a*s;
    //     float pitch = this[5];
    //     FloatConvertWrapper(this);
    //     *(float*)a3 = -pitch;
    //     if (fabs(this[5]) == 1.0) {
    //       *(int*)(a3 + 8) = 0;
    //       *(float*)(a3 + 4) = atan2(-this[6], this[0]);
    //     } else {
    //       *(float*)(a3 + 4) = atan2(this[2], this[8]);
    //       *(float*)(a3 + 8) = atan2(this[3], this[4]);
    //     }
    //   }
    // UNRESOLVED: The layout of the output struct at a3 (offsets 0, 4, 8) and the exact angle convention are not established from this function alone.
    // UNRESOLVED: What FloatConvertWrapper does to the matrix before angle extraction is unknown.
    // UNRESOLVED: Matrix orientation/row-major-vs-column-major interpretation is caller-dependent.
}
