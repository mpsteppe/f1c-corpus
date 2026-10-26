// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F3190
// Canonical corpus name: QuadraticCubicPolynomialEvaluator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadraticCubicPolynomialEvaluator_004f3190.c

void UnknownObject::EvaluateDualQuadratic()
{
    // Evaluates two quadratic polynomials a2^2*C2 + a2*C1 + C0 with double-precision coefficients read from the struct, writing the first result to *a3 and the second to *a4. When the enable flag byte at this+0x0 is zero, both outputs are set to 0.0. Returns the a3 pointer when enabled, the a4 pointer when disabled.
    // GUARD: if *this (enable flag byte at this+0x0) is non-zero, evaluate both quadratics; otherwise zero both outputs [field:this:0x00000000, source:raw]
    // CALCULATION: polynomial 1: *a3 = a2*a2*C2 + a2*C1 + C0 with C0 at this+0x4, C1 at this+0xC, C2 at this+0x14 (all doubles) [field:this:0x00000004, field:this:0x0000000C, field:this:0x00000014, source:raw]
    // CALCULATION: polynomial 2: *a4 = a2*a2*C2' + a2*C1' + C0' with C0' at this+0x1C, C1' at this+0x24, C2' at this+0x2C (all doubles) [field:this:0x0000001C, field:this:0x00000024, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: disabled path sets both outputs to 0.0: *a3 = 0.0; *a4 = 0.0 [field:this:0x00000000, source:raw]
    // RETURN: return the result pointer: a3 when enabled, a4 when disabled [function:0x004F3190, source:raw]

    // Conservative worker pseudocode:
    //   if (*this) {
    //     *a3 = a2*a2*C2_1 + a2*C1_1 + C0_1; /* C0_1=*(double*)(this+0x4), C1_1=*(double*)(this+0xC), C2_1=*(double*)(this+0x14) * /
    //     *a4 = a2*a2*C2_2 + a2*C1_2 + C0_2; /* C0_2=*(double*)(this+0x1C), C1_2=*(double*)(this+0x24), C2_2=*(double*)(this+0x2C) * /
    //     return a3;
    //   } else {
    //     *a3 = 0.0; *a4 = 0.0;
    //     return a4;
    //   }
    // UNRESOLVED: ABI lead name 'Evaluate_2nd_or_3rd_order_polynomial_at_param_2_' suggests 2nd/3rd-order evaluation, but only quadratic terms are present in the raw source; the owning class is unconfirmed.
    // UNRESOLVED: The dual-purpose return value (a3 when enabled, a4 when disabled) is an unusual convention; its intent is unconfirmed.
}
