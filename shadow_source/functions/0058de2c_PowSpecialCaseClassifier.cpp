// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DE2C
// Canonical corpus name: sub_58DE2C
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58DE2C_0058de2c.c

void UnknownObject::PowSpecialCaseClassifier()
{
    // CRT special-case classifier for a binary double operation (structure matches pow(x, y) special cases): takes an absolute value of a1 guarded by an FPU sign flag, then classifies a1 (NaN, +inf, -inf, compared to 1.0) and a2 (NaN, +inf, -inf, 0.0, compared to 1.0) to select one of several result constants written to a3, returning a flag indicating the exact |a1|==1.0 result.
    // CALCULATION: Capture a1 into v4 and, when the FPU sign flag v6 is set, negate it (v4 = -a1); initialize the special-case flag v5 to 0. [source:raw]
    // GUARD: Compare the high word of a2 against the infinity/NaN exponent pattern 2146435072; a differing finite exponent routes to the finite-exponent path, while a matching pattern proceeds to infinity handling. [source:raw]
    // GUARD: Handle a2 == -INFINITY: compare |a1| (v4) against 1.0 — v4 > 1.0 routes to the zero result, v4 >= 1.0 routes to the dbl_5E7720 result with flag 1, and v4 < 1.0 falls through to the dbl_5E7718 result. [global:0x005E7718, global:0x005E7720, source:raw]
    // GUARD: Handle a1 with the infinity/NaN exponent pattern: if the low word of a1 is non-zero, a1 is NaN and the function returns without writing a3; otherwise for a1 == +INFINITY classify a2 against zero (a2 > 0 yields dbl_5E7718, a2 < 0 yields the zero result, a2 == 0 yields 1.0). [global:0x005E7718, source:raw]
    // CALL: For a1 == -INFINITY, call DoubleIntegerAndDivisibilityClassification(a2) to classify the exponent; the result v8 (equal to 1 meaning odd integer) selects the sign of the infinity result. [callee:0x0058DF5C, source:raw]
    // CALCULATION: For a1 == -INFINITY, select the result by a2 sign and parity: a2 > 0 yields dbl_5E7718, negated to -dbl_5E7718 when v8 == 1; a2 < 0 yields dbl_5E7738 when v8 == 1 else 0.0; a2 == 0 yields 1.0. [global:0x005E7718, global:0x005E7738, source:raw]
    // GUARD: Handle a2 == +INFINITY (infinity exponent pattern with zero low word): compare |a1| against 1.0 — v4 > 1.0 yields dbl_5E7718, v4 < 1.0 yields 0.0, and v4 == 1.0 yields dbl_5E7720 with the flag set to 1. [global:0x005E7718, global:0x005E7720, source:raw]
    // ASSIGNMENT: Write the selected special-case result constant (dbl_5E7718, dbl_5E7720, dbl_5E7738, or the literal 1.0/0.0) to *a3. [global:0x005E7718, global:0x005E7720, global:0x005E7738, source:raw]
    // RETURN: Return the flag v5 (0 for general special-case results, 1 for the exact |a1| == 1.0 result). [function:0x0058DE2C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_58DE2C(double a1, double a2, double* a3) {
    //     double mag = a1;
    //     int special = 0;
    //     if (sign_flag) mag = -a1;
    //     if (exponent(a2) == INF_PATTERN) {
    //       if (low_word(a2) != 0) { /* a2 NaN * /
    //         if (exponent(a1) == INF_PATTERN) { if (low_word(a1)) return special; /* a1 NaN * /
    //           if (a2 > 0.0) { *a3 = dbl_5E7718; return special; }
    //           if (a2 < 0.0) { *a3 = 0.0; return special; } }
    //         else { if (a1 != -INFINITY) return special;
    //           v8 = DoubleIntegerAndDivisibilityClassification(a2);
    //           if (a2 > 0.0) { *a3 = (v8 == 1) ? -dbl_5E7718 : dbl_5E7718; return special; }
    //           if (a2 < 0.0) { *a3 = (v8 == 1) ? dbl_5E7738 : 0.0; return special; } }
    //         *a3 = 1.0; return special; }
    //       if (mag > 1.0) { *a3 = dbl_5E7718; return special; }
    //       if (mag < 1.0) { *a3 = 0.0; return special; }
    //       special = 1; *a3 = dbl_5E7720; return special; }
    //     if (a2 == -INFINITY) {
    //       if (mag > 1.0) { *a3 = 0.0; return special; }
    //       if (mag >= 1.0) { special = 1; *a3 = dbl_5E7720; return special; }
    //       *a3 = dbl_5E7718; return special; }
    //     if (exponent(a1) == INF_PATTERN) {
    //       if (low_word(a1)) return special;
    //       if (a2 > 0.0) { *a3 = dbl_5E7718; return special; }
    //       if (a2 < 0.0) { *a3 = 0.0; return special; }
    //       *a3 = 1.0; return special; }
    //     if (a1 != -INFINITY) return special;
    //     v8 = DoubleIntegerAndDivisibilityClassification(a2);
    //     if (a2 > 0.0) { *a3 = (v8 == 1) ? -dbl_5E7718 : dbl_5E7718; return special; }
    //     if (a2 < 0.0) { *a3 = (v8 == 1) ? dbl_5E7738 : 0.0; return special; }
    //     *a3 = 1.0; return special;
    //   }
    // UNRESOLVED: Globals dbl_5B8C80 and dbl_5B8CC8 are deterministically read by this function but do not appear in the Hex-Rays pseudocode; the skeleton labels them a CRT handle boundary constant and a double zero constant respectively. They are presumed to be FPU-loaded comparison constants folded into the 1.0/0.0 literals, but their exact role is not visible in the raw source.
    // UNRESOLVED: The identification of this helper as pow() special-case handling is DERIVED from the |base| vs 1.0, base ±inf, exponent ±inf and NaN classification structure; the specific CRT operation it serves is not confirmed by packet evidence.
    // UNRESOLVED: The FPU sign flag v6 is a status bit produced by a comparison outside this function; its producer is not established.
}
