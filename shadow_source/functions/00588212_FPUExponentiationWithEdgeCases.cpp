// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588212
// Canonical corpus name: sub_588212
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_588212_00588212.c

void UnknownObject::FPUExponentiationWithEdgeCases()
{
    // Implements floating-point exponentiation (x87 FYL2X based) with full IEEE 754 edge-case handling. Validates an argument marker, special-cases NaN/infinity and zero operands, dispatches the finite-base finite-exponent case to sub_58DE2C under an fsave/frstor FPU-state save, runs X87FPExponentiation over __FYL2X__ for the general negative-base case, and raises a math-error report through the handler at 0x005E63B8 or the default wrapper when the flag dword_8D3E40 is clear.
    // GUARD: Validate the argument marker: when the low word of a1 is not 639, call sub_58DCB5 (invalid-argument handling). [callee:0x0058DCB5, source:raw]
    // GUARD: Inspect the exponent bits of a1 with mask 0x7FF00000; equality with 2146435072 selects the NaN/infinity path for the first operand. [source:raw]
    // CALL: Load the NaN/infinity branch operand through FloadWithFBFloatLoadWithNaNCheck. [callee:0x0058DCE5, source:raw]
    // CALL: When the second operand is finite or an unqualified zero, dispatch to sub_58DE2C around an fsave/frstor FPU-state save/restore. [callee:0x0058DE2C, source:raw]
    // CALCULATION: The NaN/infinity with finite exponent path returns the sum of the loaded value and the second operand. [source:raw]
    // CALL: For a non-special first operand, reload it via FloadWithFBFloatLoadWithNaNCheck and branch on the zero-flag result v10. [callee:0x0058DCE5, source:raw]
    // GUARD: When the exponent operand has nonzero mantissa or exponent bits (not a pure zero), take the exponentiation path. [source:raw]
    // GUARD: Negative base with non-integer exponent: call FloatRoundednessCheck and negate the second operand before exponentiating. [callee:0x005883E5, source:raw]
    // CALL: Core computation: X87FPExponentiation of __FYL2X__(second operand, base), negated when the sign-bit flag v12 is set. [callee:0x0058DCA0, source:raw]
    // CALL: When the math-error handling flag dword_8D3E40 is clear, raise a domain/exception report through the handler at 0x005E63B8 (called as sub_58DD89 in the raw source). [global:0x005E63B8, global:0x008D3E40, source:raw]
    // GUARD: When the exponent operand is a pure zero (no mantissa or exponent bits), return 1.0 when the mantissa is also zero and 0.0 otherwise. [source:raw]
    // ASSIGNMENT: The zero/infinity-result cases are materialized from the 80-bit constants tbyte_5E6BF0 and tbyte_5E6C50, with sign applied from the v17/v18 sign bits. [global:0x005E6BF0, global:0x005E6C50, source:raw]
    // CALL: On exceptional return paths, when dword_8D3E40 is clear, CRTFloatPassthroughWrapper applies the default error return. [callee:0x0058DC40, global:0x008D3E40, source:raw]
    // RETURN: Return the computed double result in ST0 (result/result variable). [source:raw]

    // Conservative worker pseudocode:
    //   double pow_helper(int marker, double base, double exp) {
    //     if ((WORD)marker != 639) handle_invalid_argument();
    //     if (is_nan_or_inf(base)) {
    //       double b = load_with_nan_check(&base);
    //       return b + exp;
    //     }
    //     if (is_pure_zero(exp)) return (exp == 0.0 && base == 0.0) ? 1.0 : 0.0;
    //     if (base < 0 && !is_integer(exp)) {
    //       roundedness_check(base);
    //       exp = -exp;
    //       double r = x87_exp(fyl2x(exp, base));
    //       if (sign_flag) r = -r;
    //       if (!g_math_error_flag) raise_math_error(handler, 29);
    //       return r;
    //     }
    //     return special_case_result(tbyte_5E6BF0, tbyte_5E6C50, sign_bits);
    //   }
    // UNRESOLVED: The identity and contract of sub_58DD89 (math-error reporter taking the handler at 0x005E63B8) is not in the packet callee list and is only visible in raw source.
    // UNRESOLVED: Decompiler artifacts leave several flags (v10 zero flag, v12, v17/v18, and v13/v14) as uninitialized register reads; the exact branch semantics of those paths is uncertain.
    // UNRESOLVED: The meaning of the argument marker 639 and the exact IEEE rounding behavior on the negative-base paths is not established.
    // UNRESOLVED: The owner of the function is unknown; it appears to be a free-floating CRT-style math helper.
}
