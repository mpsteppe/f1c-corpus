// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056BDE0
// Canonical corpus name: sub_56BDE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56BDE0_0056bde0.c

void UnknownObject::AngleAxisToRotationMatrix()
{
    // Converts an angle-axis rotation vector a2 (3 doubles) into a 3x3 rotation matrix stored at this+0x0 through this+0x40 using Rodrigues' rotation formula, applied only when the squared norm of a2 is positive. When the optional output pointer a3 is non-null, extracts Euler angles from the resulting matrix: a gimbal-lock path when the sine-term magnitude equals 1.0, otherwise two atan2 computations.
    // CALCULATION: Compute the squared norm v5 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2]. [source:raw]
    // GUARD: Guard on v5 > 0.0: only build the rotation when the angle-axis vector has non-zero magnitude; the zero threshold compares against the dbl_59E430 zero sentinel. [global:0x0059E430, source:raw]
    // CALCULATION: Compute the angle v22 = sqrt(v5) and the negated normalized axis components v6, v7, v8 = -a2 / v22. [source:raw]
    // CALCULATION: Precompute Rodrigues factors: sin(v22), cos(v22), cross-product terms scaled by (1.0 - cos), and (1.0 - v_i*v_i)*cos + v_i*v_i diagonal terms; the 1.0 constant comes from dbl_59E420. [global:0x0059E420, source:raw]
    // LOOP: Iterate three columns of the 3x3 matrix: transform the three 3-element vectors stored in `this` (this+0x0, this+0x8, this+0x10, this+0x18, this+0x20, this+0x28, this+0x30, this+0x40) using the precomputed Rodrigues coefficients, writing the rotated values back into the matrix rows. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000040, source:raw]
    // CALL: Invoke FloatConvertWrapper in the Euler-extraction path (decompiler artifact at the matrix read). [callee:0x00588570, source:raw]
    // GUARD: Guard on a3 non-null: proceed to extract Euler angles into the output pointer a3. [source:raw]
    // CALCULATION: Read this+0x28 (sine term), negate it, and store it into a3 as the first Euler angle output. [field:this:0x00000028, source:raw]
    // GUARD: Gimbal-lock branch when fabs(this+0x28) == 1.0: zero the a3+16 and a3+20 outputs and compute a3+8 = atan2(-this+0x30, this+0x0). [field:this:0x00000030, field:this:0x00000000, source:raw]
    // CALCULATION: Non-gimbal-lock branch: a3+8 = atan2(this+0x10, this+0x40) and a3+16 = atan2(this+0x18, this+0x20). [field:this:0x00000010, field:this:0x00000040, field:this:0x00000018, field:this:0x00000020, source:raw]

    // Conservative worker pseudocode:
    //   void AngleAxisToRotationMatrix(char* this, double* axis, double* eulerOut) {
    //     double n2 = axis[0]*axis[0] + axis[1]*axis[1] + axis[2]*axis[2];
    //     if (n2 > 0.0) {
    //       double a = sqrt(n2);
    //       double x = -axis[0]/a, y = -axis[1]/a, z = -axis[2]/a;
    //       double s = sin(a), c = cos(a), k = 1.0 - c;
    //       // Rodrigues rotation applied column-wise over the 3x3 matrix at this+0x0..this+0x40
    //       for (int i = 0; i < 3; i++) { ... }
    //     }
    //     if (eulerOut) {
    //       double sy = -((double*)this)[5];
    //       eulerOut[0] = sy;
    //       if (fabs(sy) == 1.0) { eulerOut[2] = 0; eulerOut[3] = 0; eulerOut[1] = atan2(-((double*)this)[6], *(double*)this); }
    //       else { eulerOut[1] = atan2(((double*)this)[2], ((double*)this)[8]); eulerOut[2] = atan2(((double*)this)[3], ((double*)this)[4]); }
    //     }
    //   }
    // UNRESOLVED: The owner of this rotation-matrix helper is unknown; callers SuspensionDataCopyToPhysicsEngine, VehiclePhysicsInitializer, VehiclePhysicsIntegrationStep and sub_447780 indicate shared vehicle-physics orientation math.
    // UNRESOLVED: The purpose of dbl_59E428 (NaN sentinel) is not observable in the raw source; deterministic facts record it as referenced.
    // UNRESOLVED: The FloatConvertWrapper(v4) call site is a decompiler artifact with no visible effect on the reconstructed C.
}
