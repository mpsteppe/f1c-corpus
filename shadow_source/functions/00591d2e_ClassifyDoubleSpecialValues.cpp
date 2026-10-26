// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591D2E
// Canonical corpus name: UtilityFunction_1d2e
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_1d2e_00591d2e.c

void UnknownObject::ClassifyDoubleSpecialValues()
{
    // Double classifier (__cdecl): takes a 64-bit double split into two 32-bit halves (low a1, high a2) and returns an integer class code. Returns 1 for +infinity, 2 for -infinity, 3 when the high-word exponent bits mask to 0x7FF8 (NaN-like), 4 when the exponent is all-ones with a nonzero mantissa/low word, and 0 otherwise (zero/subnormal path).
    // GUARD: Guard: if a2 == 2146435072 (0x7FF00000) and a1 == 0, return 1 (positive infinity). [source:raw]
    // GUARD: Guard: else if a2 == -1048576 and a1 == 0, return 2 (negative infinity). [source:raw]
    // GUARD: Guard: if (HIWORD(a2) & 0x7FF8) == 0x7FF8, return 3 (NaN-class). [source:raw]
    // GUARD: Guard: if (HIWORD(a2) & 0x7FF8) == 0x7FF0 and ((a2 & 0x7FFFF) != 0 or a1 != 0), return 4 (exponent all-ones with nonzero mantissa). [source:raw]
    // RETURN: Fall-through return 0 for values matching none of the special cases. [source:raw, function:0x00591D2E]
    // CALL: Called by sub_5895A2 (0x005895A2) and FloatClassify (0x0058A8A3) as the double special-value classification helper. [caller:0x005895A2, caller:0x0058A8A3, source:raw]

    // Conservative worker pseudocode:
    //   int sub_591D2E(int lo, int hi) {
    //     if (hi == 2146435072 && lo == 0) return 1;   /* +infinity * /
    //     if (hi == -1048576 && lo == 0) return 2;     /* -infinity * /
    //     if ((HIWORD(hi) & 0x7FF8) == 0x7FF8) return 3;
    //     if ((HIWORD(hi) & 0x7FF8) == 0x7FF0 && ((hi & 0x7FFFF) || lo)) return 4;
    //     return 0;
    //   }
    // UNRESOLVED: The 64-bit double is passed as two 32-bit integers (lo=a1, hi=a2); classification inspects the high half only.
    // UNRESOLVED: Return codes 1..4 map to +inf/-inf/NaN/nonzero-exponent by branch inspection; no external contract confirms the exact meaning of code 4 vs code 3.
}
