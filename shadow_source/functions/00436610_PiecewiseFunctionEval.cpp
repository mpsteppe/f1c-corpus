// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00436610
// Canonical corpus name: PiecewiseFunctionEval
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PiecewiseFunctionEval_00436610.c

void UnknownObject::PiecewiseFunctionEval()
{
    // Evaluates a two-input piecewise function from 15 coefficient fields of `this`. The a3 input selects one of three linear segments by sign and threshold (this[1..8]), the result is combined as a2 * this[0] + v3, then a boundary correction is applied when the a2 excess v5 over the boundary window (this[13], this[14]) is positive, using two correction lines (this[9..12]). Returns the corrected result, or the unmodified result when no correction applies.
    // GUARD: Segment selection on the a3 sign: branch on a3 <= 0.0 (zero reference dbl_59E430). [global:0x0059E430, source:raw]
    // GUARD: For non-positive a3, select the high-magnitude segment when a3 >= this[7] (threshold offset 0x38). [field:this:0x00000038, source:raw]
    // CALCULATION: v3 = a3 * this[6] (offset 0x30): high-magnitude negative segment, slope only. [field:this:0x00000030, source:raw]
    // CALCULATION: v3 = a3 * this[5] + this[8] (offsets 0x28, 0x40): low-magnitude negative segment, slope plus intercept. [field:this:0x00000028, field:this:0x00000040, source:raw]
    // GUARD: For positive a3, select the low segment when a3 <= this[3] (threshold offset 0x18). [field:this:0x00000018, source:raw]
    // CALCULATION: v3 = a3 * this[2] (offset 0x10): low positive segment, slope only. [field:this:0x00000010, source:raw]
    // CALCULATION: v3 = a3 * this[1] + this[4] (offsets 0x8, 0x20): high positive segment, slope plus intercept. [field:this:0x00000008, field:this:0x00000020, source:raw]
    // CALCULATION: result = a2 * this[0] (offset 0x0) + v3: combine the a2 scale term with the selected segment value. [field:this:0x00000000, source:raw]
    // GUARD: Boundary selection: when a2 <= this[14] (offset 0x70) compute the excess against the upper boundary. [field:this:0x00000070, source:raw]
    // CALCULATION: v5 = this[14] - a2 (offset 0x70). [field:this:0x00000070, source:raw]
    // CALCULATION: Otherwise v5 = a2 - this[13] (offset 0x68): excess beyond the lower boundary. [field:this:0x00000068, source:raw]
    // GUARD: Correction is attempted only when v5 > 0.0 (zero reference dbl_59E430). [global:0x0059E430, source:raw]
    // CALCULATION: v6 = v5 * this[10] + this[9] (offsets 0x50, 0x48): first boundary-correction line. [field:this:0x00000050, field:this:0x00000048, source:raw]
    // CALCULATION: v7 = v5 * this[12] + this[11] (offsets 0x60, 0x58): second boundary-correction line. [field:this:0x00000060, field:this:0x00000058, source:raw]
    // GUARD: Sign split of the correction on a2 <= 0.0 (zero reference dbl_59E430). [global:0x0059E430, source:raw]
    // CALCULATION: v9 = v7 * a3 - v6 * v5: correction value for the non-positive a2 side. [source:raw]
    // GUARD: Apply the negative-side correction only when v9 < 0.0 (zero reference dbl_59E430). [global:0x0059E430, source:raw]
    // RETURN: return result + v9 (corrected value, negative side). [source:raw]
    // CALCULATION: v8 = v5 * v6 + v7 * a3: correction value for the positive a2 side. [source:raw]
    // GUARD: Apply the positive-side correction only when v8 > 0.0 (zero reference dbl_59E430). [global:0x0059E430, source:raw]
    // RETURN: return result + v8 (corrected value, positive side). [source:raw]
    // RETURN: Fallback return of the unmodified result when no correction applies. [source:raw]

    // Conservative worker pseudocode:
    //   // c[0..14] are the coefficient fields; a3 picks the segment, a2 the scale plus boundary correction.
    //   double sub_436610(const double* c, double a2, double a3) {
    //     double v3;
    //     if (a3 <= 0.0) {
    //       v3 = (a3 >= c[7]) ? a3 * c[6] : a3 * c[5] + c[8];
    //     } else if (a3 <= c[3]) {
    //       v3 = a3 * c[2];
    //     } else {
    //       v3 = a3 * c[1] + c[4];
    //     }
    //     double result = a2 * c[0] + v3;
    //     double v5 = (a2 <= c[14]) ? c[14] - a2 : a2 - c[13];
    //     if (v5 > 0.0) {
    //       double v6 = v5 * c[10] + c[9];
    //       double v7 = v5 * c[12] + c[11];
    //       if (a2 <= 0.0) {
    //         double v9 = v7 * a3 - v6 * v5;
    //         if (v9 < 0.0) return result + v9;
    //       } else {
    //         double v8 = v5 * v6 + v7 * a3;
    //         if (v8 > 0.0) return result + v8;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner struct type and the exact meaning of the fifteen coefficient fields (a spring/damper response curve per existing analysis) are not confirmed by packet evidence.
    // UNRESOLVED: Callers ConstraintEnforce (0x004380B0) and sub_442C90 (0x00442C90) supply the a2/a3 inputs; call-site argument provenance is outside this packet.
}
