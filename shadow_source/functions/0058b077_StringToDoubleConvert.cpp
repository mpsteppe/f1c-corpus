// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B077
// Canonical corpus name: sub_58B077
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58B077_0058b077.c

void UnknownObject::StringToDoubleConvert()
{
    // strtod-style converter: skips leading whitespace using a character-type table (or an encoding-aware fallback), parses the numeric string via EncodingLocaleDetectionFromParseResult, and returns the parsed double, handling infinity/NaN/range flag bits and setting TLS errno 34 (ERANGE) on non-finite results.
    // LOOP: Skip leading whitespace: while the current byte classifies as space (bit 8 of the off_5E69C8 character-type table when cbMultiByte <= 1, else CharacterEncodingConvertViaLookupTableFallback(char, 8)), advance i. [global:0x005E69C8, global:0x005E6BD4, callee:0x0058C674, field:this:0x00000000, source:raw]
    // CALL: Strlen(i) measures the remaining string; its result is unused by the caller flow. [callee:0x0058E1B0]
    // CALL: EncodingLocaleDetectionFromParseResult(v9, i) parses the numeric token and returns a descriptor double* v4 carrying a flag dword at [0] and an end pointer at [1]. [callee:0x0058E12E]
    // ASSIGNMENT: If a2 is non-null, write the end pointer past the parsed number into *a2. [field:this:0x00000000]
    // GUARD: Parse-flag test: if (v5 & 0x240) != 0 (range/format failure) take the error return; otherwise continue with finite/infinity/NaN handling. [function:0x0058B077]
    // GUARD: Sign check: current character *i == 45 (ASCII '-') negates the infinity value; this is the packet guard this:0x0 == 45. [guard:0, field:this:0x00000000]
    // ASSIGNMENT: Infinity branch: when flags & 0x81, the value is +dbl_5E9990 (or -dbl_5E9990 when preceded by '-'). [global:0x005E9990, field:this:0x00000000]
    // RETURN: NaN branch: when flags & 0x100 the value is 0.0; when no special flag is set, return v4[2] as the plain parsed value without touching errno. [function:0x0058B077]
    // ASSIGNMENT: The non-finite path stores errno 34 (ERANGE) into the TLS slot via TLSOffsetGetter and returns the infinity or NaN value. [callee:0x0058AFCF]
    // RETURN: Error return: when flag 0x240 is set, return 0.0 and, if a2, set *a2 = a1 (the unconsumed start of the string). [field:this:0x00000000]

    // Conservative worker pseudocode:
    //   skip_whitespace(&i);
    //   Strlen(i);
    //   parse = EncodingLocaleDetectionFromParseResult(buf, i);
    //   if (a2) *a2 = end_ptr(parse);
    //   flags = parse[0];
    //   if ((flags & 0x240) != 0) { if (a2) *a2 = a1; return 0.0; }
    //   if (flags & 0x81) {
    //       value = dbl_5E9990;
    //       if (*i == 45) value = -dbl_5E9990;
    //   } else if (flags & 0x100) {
    //       value = 0.0;
    //   } else {
    //       return parse[2];
    //   }
    //   set_tls_errno(34);
    //   return value;
    // UNRESOLVED: Flag-bit meanings (0x81 infinity, 0x100 NaN, 0x240 range/format) are inferred from the branch structure, not labelled in packet evidence.
    // UNRESOLVED: Character class bit 8 is interpreted as whitespace per strtod convention.
}
