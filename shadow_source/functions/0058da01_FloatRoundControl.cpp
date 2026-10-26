// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DA01
// Canonical corpus name: FloatRoundControl
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatRoundControl_0058da01.c

void UnknownObject::FloatRoundControl()
{
    // Small __usercall helper (ABI lead FloatRoundControl, LEGACY) that takes a double in st0, rounds it via frndint, and when the input is already integral multiplies it by the double constant dbl_5E6C22 and rounds again. Returns the original value in st0; the intermediate arithmetic is an x87-side effect of setting/using the FPU rounding state rather than a change to the returned value.
    // CALCULATION: Round the incoming value (st0) to an integer via frndint, keeping the original in _ST6 [function:0x0058DA01, source:raw]
    // GUARD: Branch only when the rounded value _ST6 equals the original input, i.e. the input is already integral [function:0x0058DA01, source:raw]
    // CALCULATION: On the integral path, multiply the value by the double constant dbl_5E6C22 and round again via frndint [global:0x005E6C22, source:raw]
    // RETURN: Return the original value in st0 [function:0x0058DA01, source:raw]

    // Conservative worker pseudocode:
    //   double FloatRoundControl(double result) {
    //     double rounded = round(result);        // frndint
    //     if (rounded == result) {
    //       round(result * dbl_5E6C22);          // frndint; value not returned
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The purpose of dbl_5E6C22 and the FloatRoundControl ABI-lead name are LEGACY hints; the exact FPU control/rounding effect is unproven
    // UNRESOLVED: _ST5/_ST6 are Hex-Rays artifacts of the x87 stack; the precise stack effect of the second frndint is unclear
    // UNRESOLVED: The scaled result of the integral path is computed but the original value is returned, suggesting the operation acts as an FPU-state/rounding-mode control rather than a pure value transform
    // UNRESOLVED: Caller/callee context is empty in this packet
}
