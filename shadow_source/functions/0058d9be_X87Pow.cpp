// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058D9BE
// Canonical corpus name: X87Pow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/X87Pow_0058d9be.c

void UnknownObject::X87Pow()
{
    // x87 assembler primitive (ABI lead names it x87_pow, LEGACY). Compares the absolute value of st0 with the extended-precision constant tbyte_5E6C0E and branches on the FPU status flags: if the compare flags are set, the value is tested against zero, producing +0.0 for zero and otherwise loading the constant tbyte_5E6BF0 (negated when the a1 flag is set); if the compare flags are clear, the value is rounded, fraction-isolated, and passed through f2xm1 (2^x - 1). Result is returned in st0.
    // GUARD: Duplicate st0, take its absolute value, load extended-precision constant tbyte_5E6C0E, compare both via fcompp, and store the FPU status word; branch on condition bits 0x41 (C0/C3) [global:0x005E6C0E, function:0x0058D9BE, source:raw]
    // GUARD: On the compare-flags branch, test st0 against zero via ftst and store the status word [function:0x0058D9BE, source:raw]
    // STATE_TRANSITION: If st0 is zero, store byte value 4 at stack slot _EBP-144, pop st0, and load +0.0 via fldz as the result [function:0x0058D9BE, source:raw]
    // CALCULATION: Otherwise pop st0 and load the second extended-precision constant tbyte_5E6BF0; if the a1 flag is non-zero, negate it via fchs [function:0x0058D9BE, source:raw]
    // CALCULATION: On the non-compare branch, round st0 via frndint, exchange st(1)/st(0), subtract (fraction extraction), test/abs, then apply f2xm1 to compute 2^st0 - 1 [function:0x0058D9BE, source:raw]
    // RETURN: Return the computed value in st0 [function:0x0058D9BE, source:raw]

    // Conservative worker pseudocode:
    //   double X87Pow(a1, _EBP) {
    //     if (compareFlags(FPUStatus, 0x41) != 0) {        // fcompp |st0| vs tbyte_5E6C0E
    //       if (st0 == 0.0) {                             // ftst
    //         _EBP[-144] = 4;
    //         return +0.0;                                 // fldz
    //       } else {
    //         double v = tbyte_5E6BF0;
    //         if (a1)
    //           v = -v;                                    // fchs
    //         return v;
    //       }
    //     } else {
    //       return 2.0^fraction(st0) - 1.0;               // frndint/fxch/fsub/ftst/fabs/f2xm1
    //     }
    //   }
    // UNRESOLVED: tbyte_5E6BF0 is referenced by the raw source but has no packet globals entry or evidence ref, so it is described but cannot be linked
    // UNRESOLVED: The numerical values and meaning of the two extended-precision constants tbyte_5E6C0E / tbyte_5E6BF0 are unknown
    // UNRESOLVED: Exact role of the a1 flag (conditional sign flip) is unproven
    // UNRESOLVED: Caller/callee context is empty in this packet; the x87_pow ABI lead (LEGACY) is the only hint this is a power-function primitive
    // UNRESOLVED: The stack byte 4 written to _EBP-144 is unexplained; it may be a status/tag write outside the visible frame
}
