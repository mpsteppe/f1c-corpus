// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A8A3
// Canonical corpus name: FloatClassify
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatClassify_0058a8a3.c

void UnknownObject::FloatClassify()
{
    // Classifies a double by inspecting its IEEE-754 exponent/sign bit fields and returns a small integer category. Exponent all-ones (NaN/Inf) delegates to UtilityFunction_1d2e and maps its result to 512/4/2/1; exponent zero with nonzero mantissa (subnormal) returns 128 or 16 by sign; remaining values return 256/255 for nonzero normal and 64/63 for +/-0. The exact meaning of the returned codes depends on the unexamined callee.
    // GUARD: First branch: (HIWORD(a1) & 0x7FF0) == 0x7FF0 selects values whose exponent field is all ones (NaN/Inf). [source:raw, function:0x0058A8A3]
    // CALL: In the all-ones-exponent branch, call UtilityFunction_1d2e(LODWORD(a1), HIDWORD(a1)) to further classify the value. [source:raw, callee:0x00591D2E, function:0x0058A8A3]
    // RETURN: Map the UtilityFunction_1d2e result: with v1 = result - 1, return 512 if v1 == 0; else with v2 = v1 - 1 return 4 if v2 == 0, 2 if v2 == 1, otherwise 1. [source:raw, function:0x0058A8A3]
    // GUARD: Second branch: exponent bits zero ((HIWORD(a1) & 0x7FF0) == 0) and mantissa nonzero (HIDWORD fraction bits or LODWORD nonzero) selects nonzero subnormal values. [source:raw, function:0x0058A8A3]
    // CALCULATION: For nonzero subnormals: v4 = -((HIWORD(a1) & 0x8000) != 0), mask the low byte of v4 with 0x90, and return v4 + 128 (128 for positive, 16 for negative). [source:raw, function:0x0058A8A3]
    // GUARD: Final branch handles exponent all-ones already excluded: zero and normal values; v5 = -((HIWORD(a1) & 0x8000) != 0) with low byte cleared to 0. [source:raw, function:0x0058A8A3]
    // RETURN: In the final branch, return v5 + 64 if a1 == 0.0 (64 for positive zero, 63 for negative zero), else v5 + 256 (256 positive, 255 negative). [source:raw, function:0x0058A8A3]

    // Conservative worker pseudocode:
    //   if ((HIWORD(a1) & 0x7FF0) == 0x7FF0) {          // NaN / Inf
    //       v1 = UtilityFunction_1d2e(LODWORD(a1), HIDWORD(a1)) - 1;
    //       if (v1 == 0) return 512;
    //       v2 = v1 - 1;
    //       if (v2 == 0) return 4;
    //       if (v2 == 1) return 2;
    //       return 1;
    //   } else if ((HIWORD(a1) & 0x7FF0) == 0 && ((HIDWORD(a1) & 0xFFFFF) != 0 || LODWORD(a1))) {
    //       v4 = -((HIWORD(a1) & 0x8000) != 0);
    //       LOBYTE(v4) = LOBYTE(v4) & 0x90;
    //       return v4 + 128;  // +128 positive, -112 = 16 negative
    //   } else {
    //       v5 = -((HIWORD(a1) & 0x8000) != 0);
    //       LOBYTE(v5) = 0;
    //       return (a1 == 0.0) ? v5 + 64 : v5 + 256;  // +/-0 -> 64/63, normal -> 256/255
    //   }
    // UNRESOLVED: Global dbl_5B8CC8 is marked read but does not appear in the decompiled source; it may be folded into an x87 constant.
    // UNRESOLVED: Meaning of the return codes depends on UtilityFunction_1d2e (0x00591D2E), which is not examined here.
    // UNRESOLVED: The codes resemble an IEEE-754 classification scheme (subnormal/normal/zero/sign), but the caller-side mapping in 0x0058DF5C is not established.
}
