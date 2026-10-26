// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005910B6
// Canonical corpus name: sub_5910B6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5910B6_005910b6.c

void UnknownObject::FloatingPointRemainderCore()
{
    // Core extended-precision floating-point remainder (x87 FPREM-style) reducer. Validates the control word of operand a2 (dword at a2+6 xored with 0x700), classifies both operands through the byte_5E74FC table and exponent masks (0x7FFF0000, excluding the all-ones and zero patterns), rejects operands whose low mantissa doubleword is zero, then reduces a5 modulo a2 either by repeated scaled subtraction (iteration count derived from the exponent-byte gap, divisor scaled by dbl_5E752C each step) or by direct x87 __FPREM__ when the exponent gap is at most 63. Finally reloads the x87 floating-point environment when the a1 flag has low bits set. Invoked from the FloatModulusWithDenormalHandling wrapper sub_5912BC.
    // CALCULATION: Seed result with the control word of operand a2 xored with 0x700: result = dword(a2+6) ^ 0x700. [function:0x005910B6, source:raw]
    // GUARD: Gate the whole reduction on the control-word check of operand a2: ((dword at a2+6) ^ 0x700) & 0x700 == 0 identifies a valid 80-bit long-double pattern; otherwise return early. [source:raw]
    // CALCULATION: Derive a classification index: result = (xored control word >> 11) & 0xF. [source:raw]
    // GUARD: Admit the operands only if the classification table byte_5E74FC at that index is non-zero. [global:0x005E74FC, source:raw]
    // GUARD: Skip when a2's exponent field (dword at a2+6 masked with 0x7FFF0000) equals 0x7FFF0000 (infinity/NaN pattern). [source:raw]
    // GUARD: Skip when a5's exponent field (dword at a5+6 masked with 0x7FFF0000) is 0 or equals 2147418112 (the 0x7FFF0000 infinity/NaN pattern). [source:raw]
    // GUARD: Skip when a5's low mantissa doubleword is zero (2 * DWORD1(a5) == 0 marks an exact class needing no reduction). [source:raw]
    // GUARD: Skip when a2's low mantissa doubleword is zero (2 * DWORD1(a2) == 0). [source:raw]
    // GUARD: Branch on the exponent gap: if (a5 exponent, 0x7FFF mask) is greater than (a2 exponent, 0x7FFF mask) + 63 take the scaled-subtraction path, otherwise take the direct FPREM path. [source:raw]
    // LOOP: Scaled-subtraction path: compute the iteration count from the exponent-byte difference (((expByte(a5) - expByte(a2)) & 0x3F | 0x20) + 1), take fabs(a2) and fabs(a5), then repeatedly subtract the divisor magnitude from the dividend magnitude while the FPU condition word lacks 0x100, scaling the divisor by dbl_5E752C each step until the count expires. [global:0x005E752C, source:raw]
    // LOOP: Direct path: while (a5 exponent, 0x7FFF mask) minus ((a2 exponent, 0x7FFF mask) + 10) is not negative, overwrite a5 with __FPREM__(a5, a2). [source:raw]
    // CALCULATION: When the a1 flag has low bits set ((a1 & 3) != 0), capture the FPU status word (result = v13 & 0x4300) and reload the x87 floating-point environment (fnstenv/fldenv) so the caller observes the FPU state. [source:raw]
    // RETURN: Return the accumulated result (FPU status/condition value or the classification table index path's result). [function:0x005910B6, source:raw]
    // CALL: Invoked by the FloatModulusWithDenormalHandling wrapper sub_5912BC (0x005912BC), which passes a fast-path/scale flag in a1 and the two operands as bit patterns. [caller:0x005912BC, function:0x005910B6, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_5910B6(char a1, long double a2, long double a5) {
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
    //     if ((a1 & 3) != 0) { result = fpsword & 0x4300; fnstenv/env; fldenv/env; }
    //     return result;
    //   }
    // UNRESOLVED: Globals dbl_5E751C (0x005E751C) and tbyte_5E7534 (0x005E7534) are listed as read by the deterministic fact table but do not appear anywhere in the decompiled body; their role (likely adjacent FP constants or a table) is not evidenced in the source.
    // UNRESOLVED: The __usercall ABI (a1 in dl) and the unused arguments a3/a4 are not consumed in the visible body; their contract is unknown.
    // UNRESOLVED: Semantics of the byte_5E74FC entries, of the returned FPU condition word, and of the a1 flag values (0, 2, 3) passed by sub_5912BC are not proven.
    // UNRESOLVED: The role of the 0x100 FPU condition flag and of the 0x700 control-word mask is DERIVED from x87 FPREM semantics, not confirmed.
    // UNRESOLVED: The proposed name FloatingPointRemainderCore and the twin relationship with 0059136e were not independently verified in this packet.
}
