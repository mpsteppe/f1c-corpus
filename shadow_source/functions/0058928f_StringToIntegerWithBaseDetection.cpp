// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058928F
// Canonical corpus name: sub_58928F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58928F_0058928f.c

void UnknownObject::StringToIntegerWithBaseDetection()
{
    // String-to-integer parser with automatic base detection and strtol-like semantics. Skips leading characters classified as whitespace, accepts an optional +/- sign, auto-detects base 16 (0x/0X), 8 (leading 0) or 10, accumulates digits through a character-class table (with an encoding fallback), detects overflow against 0xFFFFFFFF/a3, writes errno 34 via the TLS getter on range failure and optionally reports the end-of-parse pointer through a2.
    // ASSIGNMENT: Initialize the accumulated value v13 to 0 and load the first input character v4 = *a1. [field:this:0x00000000, source:raw]
    // LOOP: Advance the scan pointer i past every leading character whose type-table bit 8 is set (using off_5E69C8 when cbMultiByte <= 1, otherwise the CharacterEncodingConvertViaLookupTableFallback call); the loop reads v4 = *i each step. [global:0x005E69C8, global:0x005E6BD4, callee:0x0058C674, source:raw]
    // ASSIGNMENT: Record the end of the whitespace scan as v14 = i. [source:raw]
    // GUARD: Minus sign: if the current char v4 == 45, set the negative flag (a4 |= 2) and advance one character. [source:raw]
    // GUARD: Plus sign: if the current char v4 == 43, advance one character without setting any flag. [source:raw]
    // GUARD: Base validity gate: continue only when the requested base a3 is in [0, 36] and is not 1. [source:raw]
    // GUARD: Auto-detect when a3 == 0: a leading '0' (v4 == 48) selects hex or octal, otherwise base 10 is assumed. [source:raw]
    // GUARD: Hex-prefix test on the second input char: guard:0/guard:1 pass when the char after '0' is neither 'x' (120) nor 'X' (88), selecting octal base 8. [guard:0, guard:1, field:this:0x00000001, source:raw]
    // GUARD: Hex-prefix test on the second input char: guard:2/guard:3 pass when the char after '0' is 'x' (120) or 'X' (88), selecting hex base 16 and skipping the two-character prefix. [guard:2, guard:3, field:this:0x00000001, field:this:0x00000002, source:raw]
    // CALCULATION: Compute the per-base overflow quotient v12 = 0xFFFFFFFF / a3 used to bound digit accumulation. [source:raw]
    // LOOP: Digit accumulation loop: while the current char is a valid digit (type-table bit 4) or alphanumeric (type-table bits 0x103 / value 259), convert it to a digit value v8. [global:0x005E69C8, global:0x005E6BD4, callee:0x0058C674, callee:0x00589A35, source:raw]
    // GUARD: Terminate the parse when the digit value is not valid for the active base (v8 >= a3). [source:raw]
    // CALCULATION: Accumulate the result as v13 = v8 + a3 * v13, advancing the scan pointer each iteration; set the overflow flag (a4 |= 4) when v13 exceeds the bounded quotient. [source:raw]
    // GUARD: Overflow report: when the overflow flag (a4 bit 8) and the sign/size flags indicate an out-of-range result, write errno 34 through the TLS offset getter and clamp v13 to -1 or the 0x7FFFFFFF/0x80000000 boundary depending on signedness flags. [callee:0x0058AFCF, source:raw]
    // ASSIGNMENT: If a2 is non-null, write the end-of-parse pointer (v14 - 1, or a1 when the parse failed) through *a2. [source:raw]
    // RETURN: Return -v13 when the negative flag (a4 bit 2) is set, otherwise return v13; return 0 with *a2 = a1 when the base check failed. [source:raw]

    // Conservative worker pseudocode:
    //   int ParseInteger(const unsigned char *a1, const unsigned char **a2,
    //                    int base, int flags) {
    //     unsigned int value = 0;
    //     int c = *a1;
    //     const unsigned char *p = a1 + 1;
    //     while (IsSpace(c)) c = *p++;
    //     const unsigned char *end = p;
    //     if (c == '-') { flags |= 2; c = *p++; end = p; }
    //     else if (c == '+') { c = *p++; end = p; }
    //     if (base >= 0 && base != 1 && base <= 36) {
    //       if (base == 0) {
    //         if (c != '0') base = 10;
    //         else if (*p != 'x' && *p != 'X') base = 8;
    //         else base = 16;
    //       }
    //       if (base == 16 && c == '0' && (*p == 'x' || *p == 'X')) {
    //         c = p[1]; end = p + 2; p = end;
    //       }
    //       unsigned int limit = 0xFFFFFFFF / base;
    //       for (;;) {
    //         int digit;
    //         if (IsDigit(c)) digit = c - '0';
    //         else if (IsAlnum(c)) digit = ToUpper(c) - 55;
    //         else break;
    //         if ((unsigned)digit >= (unsigned)base) break;
    //         flags |= 8;
    //         if (value < limit ||
    //             (value == limit && (unsigned)digit <= 0xFFFFFFFF % base))
    //           value = digit + base * value;
    //         else flags |= 4;
    //         c = *end++;
    //       }
    //       if ((flags & 8) != 0 &&
    //           ((flags & 4) != 0 ||
    //            (flags & 1) == 0 &&
    //             ((flags & 2) != 0 && value > 0x80000000 ||
    //              (flags & 2) == 0 && value > 0x7FFFFFFF))) {
    //         *(int *)TLSOffsetGetter() = 34;
    //         value = (flags & 1) ? (unsigned int)-1 :
    //                 (flags & 2) ? 0x80000000 : 0x7FFFFFFF;
    //       }
    //       if (a2) *a2 = end - 1;
    //       return (flags & 2) ? -(int)value : (int)value;
    //     }
    //     if (a2) *a2 = a1;
    //     return 0;
    //   }
    // UNRESOLVED: The exact whitespace and digit bit meanings inside the off_5E69C8 type table (bits 8, 4 and 0x103) are inferred from usage, not named independently.
    // UNRESOLVED: The caller's flags (a4) semantics: bit 0 unsigned, bit 1 negative/sign, bit 4 overflow, bit 8 has-parsed-digits are DERIVED from the guard arithmetic.
    // UNRESOLVED: sub_589A35 is assumed to be an uppercase/hex conversion because it feeds the digit value 'c - 55'.
    // UNRESOLVED: errno 34 and the TLS offset getter call are CONFIRMED by source text but the meaning of the owning thread state is unknown.
}
