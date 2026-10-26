// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587ECE
// Canonical corpus name: sub_587ECE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587ECE_00587ece.c

void UnknownObject::WhitespaceSkipAndStringToInt()
{
    // cdecl string-to-integer parser with whitespace skip. Advances past leading whitespace (character-type category 8), consumes an optional '+'/'-' sign, then accumulates decimal digits (category 4) into an integer value and returns it negated when the sign was '-'. Character classification is versioned by the cbMultiByte global: the off_5E69C8 table is used when cbMultiByte <= 1, otherwise CharacterEncodingConvertViaLookupTableFallback. Called by 24 per-frame/parse-time consumers including RaceCommentaryDirectorSystem and SessionConfigReader.
    // LOOP: Skip leading whitespace: while the current character *a1 matches character-type category 8 (looked up in off_5E69C8 when cbMultiByte <= 1, else via CharacterEncodingConvertViaLookupTableFallback(*a1, 8)), advance a1. [global:0x005E69C8, global:0x005E6BD4, callee:0x0058C674, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Read the first non-whitespace byte v3 = *a1, set the scan pointer v4 = a1 + 1, and preserve the original byte v5 = v3 for the later sign check. [field:this:0x00000000, source:raw]
    // GUARD: If v3 is '+' (43) or '-' (45), consume the sign and load the next byte v3 = *v4++. [source:raw]
    // LOOP: Parse digits: initialize v6 = 0, then while the current character v3 matches digit category 4 (off_5E69C8 lookup when cbMultiByte <= 1, else CharacterEncodingConvertViaLookupTableFallback(v3, 4)), accumulate and advance v4. [global:0x005E69C8, global:0x005E6BD4, callee:0x0058C674, source:raw]
    // CALCULATION: Accumulate decimal value per digit: v6 = v3 + 10 * v6 - 48 (subtracting ASCII '0'). [source:raw]
    // RETURN: Return -v6 when the original sign byte v5 was '-' (45); otherwise return the parsed value v6. [source:raw]

    // Conservative worker pseudocode:
    //   while (is_char_type(*a1, WHITESPACE_CAT_8)) ++a1;
    //   v3 = *a1; v4 = a1 + 1; v5 = v3;
    //   if (v3 == '+' || v3 == '-') v3 = *v4++;
    //   v6 = 0;
    //   while (is_char_type(v3, DIGIT_CAT_4)) { v6 = v3 + 10 * v6 - 48; v3 = *v4++; }
    //   return (v5 == '-') ? -v6 : v6;
    // UNRESOLVED: Character classification is versioned by cbMultiByte: when cbMultiByte <= 1 the off_5E69C8 table (off_5E69C8[0][char]) is indexed directly, otherwise CharacterEncodingConvertViaLookupTableFallback is called. The exact meaning of the cbMultiByte boundary (encoding-version gate) is DERIVED.
    // UNRESOLVED: Category masks 8 (whitespace) and 4 (digit) are inferred from the loop positions; the full character-type category set is not evidenced by the packet.
    // UNRESOLVED: No owner object is evidenced; the function is a free cdecl utility shared by many subsystems.
}
