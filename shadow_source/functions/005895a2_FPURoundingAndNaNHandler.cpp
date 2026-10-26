// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005895A2
// Canonical corpus name: sub_5895A2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5895A2_005895a2.c

void UnknownObject::FPURoundingAndNaNHandler()
{
    // FPU helper handling NaN/Inf inputs and normal-number rounding, called across timer, suspension, tire and memory paths. Saves the FPU control word via ReturnFPUControlWord(dword_5E65A0, 0xFFFF). When the exponent bits of the double input ((HIWORD(a1) & 0x7FF0)) equal 0x7FF0 the value is NaN/Inf: it is classified by UtilityFunction_1d2e, and depending on the class the function either restores the control word and returns the input unchanged (class <= 2), dispatches a math error through MathDispatchWithErrorFallback (class == 3), or falls through to ConditionalMathWithDAT005e9ad0Flag. For normal numbers it applies FrndMSVCCRTRounding for rounding. The double result is returned through the FPU stack register.
    // ASSIGNMENT: Save the FPU control word into v2 via ReturnFPUControlWord(dword_5E65A0, 0xFFFF); the global dword_5E65A0 supplies the current control-word context. [callee:0x00591E66, global:0x005E65A0, source:raw]
    // GUARD: Test the double exponent field: (HIWORD(a1) & 0x7FF0) == 0x7FF0 selects the NaN/Inf path, otherwise the normal-number rounding path is taken. [source:raw]
    // CALL: Classify the NaN/Inf payload: v3 = UtilityFunction_1d2e(LODWORD(a1), HIDWORD(a1)). [callee:0x00591D2E, source:raw]
    // GUARD: When the classification v3 > 0 and v3 <= 2, restore the FPU control word and return a1 unchanged (benign NaN/Inf kept as-is). [callee:0x00591E66, source:raw]
    // GUARD: When the classification v3 == 3, dispatch the math error: MathDispatchWithErrorFallback(11, a1, v2), then return a1. [callee:0x0059163B, source:raw]
    // CALL: For other positive classifications (and for non-positive ones), route through ConditionalMathWithDAT005e9ad0Flag with dispatch code 8 and error code 11, passing both dword halves of a1 and of (a1 + 1.0), plus the saved control word v2. [callee:0x0059168F, source:raw]
    // CALL: Normal-number path: apply FrndMSVCCRTRounding(a1) to round the value. [callee:0x00591CF3, source:raw]
    // CALL: Restore the FPU control word from v2 via ReturnFPUControlWord(v2, 0xFFFF) after rounding. [callee:0x00591E66, source:raw]
    // RETURN: Return the double result (a1 for the NaN/Inf path, the rounded value on the normal-number path) through the FPU stack register. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_5895A2(double a1) {
    //     double result = a1;
    //     int savedCW = ReturnFPUControlWord(dword_5E65A0, 0xFFFF);
    //     if (((HIWORD(a1) & 0x7FF0) == 0x7FF0)) {
    //       int cls = UtilityFunction_1d2e(LODWORD(a1), HIDWORD(a1));
    //       if (cls > 0) {
    //         if (cls <= 2) { ReturnFPUControlWord(savedCW, 0xFFFF); return a1; }
    //         if (cls == 3) { MathDispatchWithErrorFallback(11, a1, savedCW); return a1; }
    //       }
    //       ConditionalMathWithDAT005e9ad0Flag(8, 11, LO32(a1), HI32(a1), LO32(a1+1.0), HI32(a1+1.0), savedCW);
    //     } else {
    //       FrndMSVCCRTRounding(a1);
    //       ReturnFPUControlWord(savedCW, 0xFFFF);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Global dbl_5B8C80 (0x005B8C80) is listed as referenced but does not appear in the raw source text; its role is unknown.
    // UNRESOLVED: Semantics of the UtilityFunction_1d2e classification return values beyond the branch pattern (positive 1..2 vs 3 vs otherwise) are unknown.
    // UNRESOLVED: Meaning of the dispatch constants 8 and 11 used in ConditionalMathWithDAT005e9ad0Flag and MathDispatchWithErrorFallback is not derivable from this function alone.
    // UNRESOLVED: The result is returned via the FPU stack register st7, so the decompiled `result = a1` may not reflect the rounding performed by FrndMSVCCRTRounding.
}
