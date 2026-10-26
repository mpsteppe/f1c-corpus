// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BC68
// Canonical corpus name: sub_58BC68
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58BC68_0058bc68.c

void UnknownObject::IsFdivBugPresent()
{
    // Constant-only FPU sanity probe. Computes 4195835.0 - (4195835.0 / 3145727.0) * 3145727.0 and returns TRUE when the residual exceeds 1.0. This is the canonical Pentium FDIV-bug detection expression: on a correct FPU the algebraically-identical intermediate collapses and the residual is ~0, while on a faulty FPU it evaluates to ~256, exceeding 1.0. Reads three double constants from 0x005B8C80, 0x005B8D48, 0x005B8D50.
    // CALCULATION: Evaluate 4195835.0 / 3145727.0 using the double constants held at dbl_5B8C80 and dbl_5B8D48. [global:0x005B8C80, global:0x005B8D48, source:raw]
    // CALCULATION: Multiply the quotient by 3145727.0 and subtract from 4195835.0 to form the residual. [global:0x005B8C80, global:0x005B8D48, source:raw]
    // RETURN: Return (residual > 1.0) as BOOL; the 1.0 bound is the double held at dbl_5B8D50. [global:0x005B8D50, function:0x0058BC68, source:raw]

    // Conservative worker pseudocode:
    //   BOOL IsFdivBugPresent() {
    //     return 4195835.0 - 4195835.0 / 3145727.0 * 3145727.0 > 1.0;
    //   }
    // UNRESOLVED: Exact literal-to-global mapping (which double lives at 0x005B8C80 / 0x005B8D48 / 0x005B8D50) is not evidenced in the packet; references are conservative.
    // UNRESOLVED: FDIV-bug interpretation is a DERIVED semantic proposal; the packet evidence only shows the constant arithmetic.
}
