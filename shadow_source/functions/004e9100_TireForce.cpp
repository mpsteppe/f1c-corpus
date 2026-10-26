// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E9100
// Canonical corpus name: TireForce
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireForce_004e9100.c

void UnknownObject::TireForce()
{
    // Tire-force computation using a friction-circle model. Computes lateral and longitudinal slip terms, selects a sign-branched lookup table (positive vs negative) by a floating-point sign flag, linearly interpolates table entries, scales by a force coefficient, applies an aerodynamic drag table term, clamps to a maximum, and returns force plus a slip-velocity drag term.
    // CALCULATION: Compute v28 = a2*a2 * this[3740] - (a2*a2 * a3 + a4[1]) * this[3397]. [field:this:0x00003A70, field:this:0x00003514, source:raw]
    // CALCULATION: Compute v25 = |a2*a2 * a5 - a4[0]| * this[3397]. [field:this:0x00003514, source:raw]
    // GUARD: Select lookup table by floating-point sign flag (v10|v11): positive branch scales by this[3855] and indexes this[3856..3857]; negative branch scales by this[3871] and indexes this[3872..3873]. [field:this:0x00003C3C, field:this:0x00003C40, field:this:0x00003C7C, field:this:0x00003C80, source:raw]
    // CALL: Positive branch: scale v9 by this[3855], call sub_5895A2 with the scaled value (return unused), and index the positive lookup table; negative table index clamps to entry 0. [callee:0x005895A2, field:this:0x00003C3C, field:this:0x00003C40, source:raw]
    // CALL: Negative branch: scale v9 by this[3871], call sub_5895A2 with the scaled value (return unused), and index the negative lookup table; negative table index clamps to entry 0. [callee:0x005895A2, field:this:0x00003C7C, field:this:0x00003C80, source:raw]
    // CALCULATION: Linear interpolation between adjacent table entries using the fractional part of the index, producing v14 (positive table at this[3856..3857] or negative table at this[3872..3873]). [field:this:0x00003C40, field:this:0x00003C80, source:raw]
    // GUARD: If v14*v14 - v25*v25 <= 0.0, the friction-circle residual is non-positive and the force term v22 is set to 0. [source:raw]
    // CALCULATION: Otherwise compute v26 = sqrt(v14*v14 - v25*v25) / v14. [source:raw]
    // CALCULATION: Compute v20 = v28 * this[3839], call sub_5895A2(v20), index and interpolate the aero lookup table at this[3840..3841] (clamped to 13), and produce v22 = interpolated * this[3398] * v26. [field:this:0x00003BFC, field:this:0x00003C00, field:this:0x00003518, callee:0x005895A2, source:raw]
    // GUARD: Clamp v22 to the maximum at this[3919]. [field:this:0x00003D3C, source:raw]
    // RETURN: Return v22 + this[3921] * this[3398] * (a2*a2) + a4[2]. [field:this:0x00003D44, field:this:0x00003518, source:raw]

    // Conservative worker pseudocode:
    //   double TireForce(float* this, float a2, float a3, float* a4, float a5) {
    //     double s2 = (double)(a2 * a2);
    //     double v28 = s2 * this[3740] - (s2 * a3 + a4[1]) * this[3397];
    //     double v25 = fabs(s2 * a5 - a4[0]) * this[3397];
    //     double v14;
    //     if (sign_flag_positive) {
    //       double sc = v28 * this[3855]; sub_5895A2(sc);
    //       int i = (int)sc; if (i < 0) i = 0; if (i >= 14) i = 13;
    //       v14 = this[i + 3856] + (this[i + 3857] - this[i + 3856]) * (sc - i);
    //     } else {
    //       double sc = v28 * this[3871]; sub_5895A2(sc);
    //       int i = (int)sc; if (i < 0) i = 0; if (i >= 14) i = 13;
    //       v14 = this[i + 3872] + (this[i + 3873] - this[i + 3872]) * (sc - i);
    //     }
    //     double v22 = 0.0;
    //     double r = v14 * v14 - v25 * v25;
    //     if (r > 0.0) {
    //       double v26 = sqrt(r) / v14;
    //       double aero = v28 * this[3839]; sub_5895A2(aero);
    //       int i = (int)aero; if (i < 0) i = 0; if (i >= 14) i = 13;
    //       v22 = (this[i + 3840] + (this[i + 3841] - this[i + 3840]) * (aero - i)) * this[3398] * v26;
    //     }
    //     if (v22 > this[3919]) v22 = this[3919];
    //     return v22 + this[3921] * this[3398] * s2 + a4[2];
    //   }
    // UNRESOLVED: Packet lists global flt_59E440 (0x0059E440) as read, but the raw source contains no explicit use; likely folded into a constant by the compiler.
    // UNRESOLVED: The sign-flag branch (v10|v11) is a floating-point compare status captured by the compiler; the exact predicate that selects positive vs negative table is not explicit in the pseudocode.
    // UNRESOLVED: Callee sub_5895A2 is called with intermediate values and its return is unused; purpose unknown.
}
