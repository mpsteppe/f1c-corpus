// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A88F
// Canonical corpus name: ArithmeticComparison_a88f
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_a88f_0058a88f.c

void UnknownObject::IsFiniteValue()
{
    // Finite/non-finite test on the upper 16 bits of a2: returns TRUE when the 12-bit field selected by masking with 0x7FF0 is not the all-ones sentinel 0x7FF0 (32752). Parameter a1 is never referenced.
    // CALCULATION: Extract a 12-bit exponent-region field from the high word of a2 via HIWORD(a2) & 0x7FF0. [source:raw]
    // RETURN: Return the comparison (HIWORD(a2) & 0x7FF0) != 0x7FF0 (32752): TRUE when the masked field is not the all-ones sentinel, i.e. the value is not flagged as infinity/NaN. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_58A88F(int a1, int a2) {
    //     return ((a2 >> 16) & 0x7FF0) != 0x7FF0;
    //   }
    // UNRESOLVED: Parameter a1 is unused; only a2 is inspected, so the intended 32/64-bit composite value (and which word holds it) is unconfirmed.
    // UNRESOLVED: The 0x7FF0 mask covers bits 20-30 of a2, which does not exactly match a double or float exponent field; exact bit-field semantics (NaN vs Infinity) are not proven.
    // UNRESOLVED: Both known callers F_4x4MatrixInverse (0x0050D0C2) and RayPlaneIntersect (0x0050E491) plausibly guard against degenerate inputs, but the guard contract is not confirmed.
}
