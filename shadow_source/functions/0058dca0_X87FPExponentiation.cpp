// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DCA0
// Canonical corpus name: X87FPExponentiation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/X87FPExponentiation_0058dca0.c

void UnknownObject::X87FPExponentiation()
{
    // Computes 2 raised to the input power a1 using x87 FPU instructions (F2XM1 + FSCALE). The input double is saved, then frndint rounds the current FPU value to an integer, producing the integer part. F2XM1 evaluates 2^(a1 - int) - 1 (the fractional-power part), +1.0 restores the +1, and FSCALE scales the result by the integer part, yielding 2^int * 2^frac = 2^a1. The exponent value is returned on the x87 stack (st0).
    // ASSIGNMENT: Save the incoming exponent a1 into the FPU stack slot _ST6 before rounding. [source:raw]
    // CALCULATION: frndint rounds the current FPU top value to the nearest integer, leaving the integer part of the exponent in _ST6. [source:raw]
    // CALCULATION: F2XM1 computes 2^(-(ST6 - a1)) - 1 where -(ST6 - a1) is the fractional part; adding 1.0 yields 2^(a1 - ST6). [source:raw]
    // CALCULATION: FSCALE scales the fractional-power result by the integer part _ST6, combining into 2^a1. [source:raw]
    // RETURN: Return the computed 2^a1 double via the x87 FPU stack (st0). [function:0x0058DCA0]

    // Conservative worker pseudocode:
    //   double sub_58DCA0(double x) {
    //     double intPart;
    //     intPart = x;
    //     frndint;
    //     return fscale(f2xm1(-(intPart - x)) + 1.0, intPart);
    //   }
    // UNRESOLVED: The exact rounding mode selected for frndint (current x87 control-word RC) is not fixed by the source and is assumed to be round-to-nearest.
    // UNRESOLVED: The caller at 0x00588212 that supplies the exponent and consumes the FPU result is not analyzed here.
    // UNRESOLVED: Whether this helper is shared math infrastructure or specific to one subsystem is unknown; the ABI hint suggests a CRT-like float library routine.
}
