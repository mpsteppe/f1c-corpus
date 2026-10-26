// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059136E
// Canonical corpus name: FloatingPointRemainder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatingPointRemainder_0059136e.c

void UnknownObject::FloatingPointRemainder()
{
    // Extended-precision floating-point remainder (x87 FPREM-style) helper, structurally a twin of 005910b6 per the DERIVED cluster prelabel. Validates the control word of operand a2 (dword at a2+6 xored with 0x700), classifies both operands through the byte_5E74FC table and exponent masks (0x7FFF0000, with the all-ones and zero patterns excluded), then reduces a5 modulo a2 either by repeated scaled subtraction (iteration count from the exponent-byte gap, divisor scaled by dbl_5E752C each step) or by direct x87 __FPREM__ when the exponent gap is small. Finally reloads the x87 environment when the a1 flag requests it. Reached from DoublePrecisionFloatClassification (0x00591574).
    // GUARD: Gate the whole reduction on the control-word check of operand a2: ((dword at a2+6) ^ 0x700) & 0x700 == 0 identifies a valid 80-bit long-double pattern. [source:raw]
    // CALCULATION: Index the classification table byte_5E74FC at ((xored control word >> 11) & 0xF); a non-zero entry admits the operand to the reduction path. [global:0x005E74FC, source:raw]
    // GUARD: Exponent-class guards: skip when a2's exponent field (mask 0x7FFF0000) equals 0x7FFF0000 (infinity/NaN pattern), or when a5's exponent field is 0 or equals 0x7FFF0000 (also written 2147418112). [source:raw]
    // GUARD: Skip when either operand's low doubleword of the mantissa (2 * DWORD1) is zero, marking an exact class that needs no reduction. [source:raw]
    // GUARD: Branch on the exponent gap: if (a5 exponent, 0x7FFF mask) is greater than (a2 exponent, 0x7FFF mask) + 63 take the scaled-subtraction path, otherwise take the direct FPREM path. [source:raw]
    // LOOP: Scaled-subtraction path: compute the iteration count from the exponent-byte difference (((expByte(a5) - expByte(a2)) & 0x3F | 0x20) + 1), then repeatedly subtract fabs(a2) from fabs(a5) while the FPU condition word lacks 0x100, scaling the divisor by dbl_5E752C each step until the count expires. [global:0x005E752C, source:raw]
    // LOOP: Direct path: while (a5 exponent, 0x7FFF mask) minus ((a2 exponent, 0x7FFF mask) + 10) is not negative, overwrite a5 with __FPREM__(a5, a2). [source:raw]
    // CALL: Reached from DoublePrecisionFloatClassification (0x00591574), consistent with an IEEE-754 remainder helper used by the classification path. [caller:0x00591574, function:0x0059136E, source:raw]
    // CALCULATION: When the a1 flag has low bits set ((a1 & 3) != 0), reload the x87 floating-point environment (fnstenv/fldenv) so the caller observes the FPU status word. [source:raw]
    // RETURN: Return the accumulated FPU status/condition value result. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_59136E(char a1, long double a2, long double a5) {
    //     unsigned int w = *((DWORD*)(&a2) + 6) ^ 0x700;
    //     if ((w & 0x700) == 0) {
    //       if (byte_5E74FC[(w >> 11) & 0xF]) {
    //         if ((expfield(a2) != 0x7FFF0000) &&
    //             (expfield(a5) != 0) && (expfield(a5) != 2147418112) &&
    //             (lowmant(a5) != 0) && (lowmant(a2) != 0)) {
    //           if ((exponent(a5) & 0x7FFF) > (exponent(a2) & 0x7FFF) + 63) {
    //             int n = ((expbyte(a5) - expbyte(a2)) & 0x3F | 0x20) + 1;
    //             double d = fabs(a2);
    //             double r = fabs(a5);
    //             do {
    //               if (!(fpsword & 0x100)) r = r - d;
    //               d = d * dbl_5E752C;
    //               --n;
    //             } while (n);
    //           } else {
    //             while ((int)((exponent(a5) & 0x7FFF) - ((exponent(a2) & 0x7FFF) + 10)) >= 0)
    //               a5 = __FPREM__(a5, a2);
    //           }
    //         }
    //       }
    //     }
    //     if ((a1 & 3) != 0) { fnstenv/env; fldenv/env; }
    //     return result;
    //   }
    // UNRESOLVED: Globals dbl_5E751C (0x005E751C) and tbyte_5E7534 (0x005E7534) are listed as read by the deterministic fact table but do not appear anywhere in the decompiled body; their role (likely adjacent FP constants or a table) is not evidenced in the source.
    // UNRESOLVED: The __usercall ABI (a1 in dl) and the unused arguments a3/a4 are not consumed in the visible body; their contract is unknown.
    // UNRESOLVED: Semantics of the byte_5E74FC entries and of the returned FPU condition word for the caller DoublePrecisionFloatClassification are not proven.
    // UNRESOLVED: The DERIVED cluster prelabel names 005910b6 as a structural twin; that equivalence was not independently verified in this packet.
}
