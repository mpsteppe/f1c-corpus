// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E8CE0
// Canonical corpus name: TireForceSolver
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireForceSolver_004e8ce0.c

void UnknownObject::TireForceSolver()
{
    // Bisection root solver for a tire contact-force function. Builds an initial bracket from a lookup table scaled by |a4| * this[3903], clamps it to [0,128], then iteratively bisects: at each endpoint it evaluates the force via a sign-selected interpolated lookup table (positive table this[3855]/this[3856] or negative table this[3871]/this[3872]) combined with slip terms built from a2, a3 and a4. Stops when the endpoint forces bracket a sign change, expands the bracket by a5 otherwise, and returns the interpolated root, or a limit (0.0/128.0) on unordered (NaN) comparisons.
    // CALCULATION: Compute the initial bracket input v6 = fabs(a4) * this[3903] (field this+0x3CFC), pass it to sub_5895A2, then index the bracket lookup table starting at this[3904] (field this+0x3D00) with the integer part clamped to [0,13], linearly interpolating between adjacent entries by the fractional part to get v8. [field:this:0x00003CFC, field:this:0x00003D00, callee:0x005895A2, source:raw]
    // CALCULATION: Clamp the bracket center v8 to a maximum of 128.0. [source:raw]
    // ASSIGNMENT: Seed the bracket: low v45 = v8 - 4.0 and high v44 = v8 + 4.0; if the low value is negative, reset to v45 = 0.0 and v44 = 8.0. [source:raw]
    // LOOP: Bisection iteration. For each endpoint, build the force terms from the square of the endpoint: v51 = v^2 * this[3740] - (v^2 * a2 + a3[1]) * this[3397] and lateral term v55 = (v^2 * a4 - a3[0]) * this[3397]. Evaluate the force at the endpoint through sub_5895A2 plus an interpolated table lookup selected by sign: positive branch uses selector this[3855] and table this[3856..] adding the lateral term; negative branch uses selector this[3871] and table this[3872..] subtracting it. [field:this:0x00003A70, field:this:0x00003514, field:this:0x00003C3C, field:this:0x00003C40, field:this:0x00003C7C, field:this:0x00003C80, callee:0x005895A2, source:raw]
    // GUARD: If force_at_low * force_at_high <= 0.0 the root is bracketed: break out of the loop. Otherwise expand the bracket by a5: when the low force is non-negative and unordered (NaN) comparison flags fire, return 128.0; else high v44 += a5 clamped to 128.0; when the low force is negative, return 0.0 on unordered flags, else low v45 -= a5 clamped to >= 0.0. [source:raw]
    // RETURN: Return the interpolated root: v54 / (v54 - v30) * (v44 - v45) + v45, or the midpoint 0.5 * (v44 - v45) + v45 when the denominator equals 0.0. [function:0x004E8CE0, source:raw]

    // Conservative worker pseudocode:
    //   double TireForceSolver(float* this, float a2, float* a3, float a4, float a5) {
    //     double v6 = fabs(a4) * this[3903];
    //     sub_5895A2(v6);
    //     int idx = clamp((int)v6, 0, 13);
    //     double v8 = this[3904 + idx] + (this[3905 + idx] - this[3904 + idx]) * (v6 - idx);
    //     if (v8 > 128.0) v8 = 128.0;
    //     double lo = v8 - 4.0, hi = v8 + 4.0;
    //     if (lo < 0.0) { lo = 0.0; hi = 8.0; }
    //     for (;;) {
    //       double fLo = force(lo, a2, a3, a4);
    //       double fHi = force(hi, a2, a3, a4);
    //       if (fHi * fLo <= 0.0) break;
    //       if (fLo >= 0.0) {
    //         if (unordered) return 128.0;
    //         if (hi >= 128.0) return 128.0;
    //         hi = min(hi + a5, 128.0);
    //       } else {
    //         if (unordered) { if (hi >= 128.0) return 128.0; hi = min(hi + a5, 128.0); }
    //         else { if (lo <= 0.0) return 0.0; lo = max(lo - a5, 0.0); }
    //       }
    //     }
    //     double denom = fLo - fHi;
    //     if (denom == 0.0) return 0.5 * (hi - lo) + lo;
    //     return fLo / denom * (hi - lo) + lo;
    //   }
    //   /* force(v) = signed, interpolated table lookup at v (positive or negative table) plus lateral slip term * /
    // UNRESOLVED: The roles of the callers' arguments a2 and the a3[0]/a3[1] terms are not resolved; the squared-slip force formula is inferred from the arithmetic shape only.
    // UNRESOLVED: sub_5895A2 is invoked with each table index value and its behavior is not in this packet.
    // UNRESOLVED: The four globals (flt_59E440, flt_59E450, flt_59E46C, flt_59E6FC) appear in the packet global table but not in the raw source text; they are not attributed to any operation.
    // UNRESOLVED: The unordered (NaN) conditional-flag paths (v13|v14, v26|v27, v38|v39) are inferred to be floating-point unordered comparisons from the code shape.
}
