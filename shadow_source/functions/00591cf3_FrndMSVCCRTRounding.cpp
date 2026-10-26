// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591CF3
// Canonical corpus name: FrndMSVCCRTRounding
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FrndMSVCCRTRounding_00591cf3.c

void UnknownObject::FrndMSVCCRTRounding()
{
    // x87 rounding helper (__cdecl): loads the double argument a1 into ST7 and executes the frndint instruction, rounding it to an integer using the currently active FPU rounding mode. The rounded value is returned through the x87 register (ST7). No rounding mode is set or restored here; the ambient FPU control word governs the result.
    // ASSIGNMENT: Load the double argument a1 into x87 register ST7. [source:raw, function:0x00591CF3]
    // CALCULATION: Execute the x87 frndint instruction to round ST7 to an integer according to the current rounding mode. [source:raw, abi:lead]
    // RETURN: Return the rounded double left in ST7 (x87 return convention); the decompiler's result is the ST7 copy. [source:raw, abi:lead]
    // CALL: Called by sub_5895A2 (0x005895A2) and DoubleIntegerAndDivisibilityClassification (0x0058DF5C) to round an FPU double to an integer under the active rounding mode. [caller:0x005895A2, caller:0x0058DF5C, source:raw]

    // Conservative worker pseudocode:
    //   double sub_591CF3(double a1) {
    //     /* _ST7 = a1; then __asm frndint rounds ST7 to an integer
    //        per the active x87 rounding mode; return the rounded value * /
    //     return rounded_st7;
    //   }
    // UNRESOLVED: Rounding mode is not set or restored here; it is whatever the ambient x87 control word holds.
    // UNRESOLVED: Whether the returned value aliases ST7 or is a copied result is a decompiler artifact; the ABI delivers the value via ST7 regardless.
}
