// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058850F
// Canonical corpus name: sub_58850F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58850F_0058850f.c

void UnknownObject::ParseDoubleFromStringWithWhitespaceSkip()
{
    // Locale-aware string-to-double parser. Skips a run of leading characters classified as whitespace (character category 8), using either the off_5E69C8 character-type table (when the cbMultiByte version global is 0 or 1) or the CharacterEncodingConvertViaLookupTableFallback fallback otherwise. After the skip loop it calls Strlen(a1) and then EncodingLocaleDetectionFromParseResult(v4, a1), which fills the local v4 parse-result structure; the returned double is read at offset 16 of that structure. The input string pointer a1 maps to field offset 0x0.
    // LOOP: Skip loop: while the current character is classified as whitespace (category 8), advance the input pointer a1 by one byte. [field:this:0x00000000, source:raw]
    // GUARD: Classification path selection: when the cbMultiByte global (0x005E6BD4) is <= 1 use the off_5E69C8 (0x005E69C8) character-type table row 0 masked with bit 8; otherwise use the fallback converter. [global:0x005E6BD4, global:0x005E69C8, source:raw]
    // CALCULATION: Lookup-table path: test off_5E69C8[0][*a1] & 8 for the current character. [global:0x005E69C8, field:this:0x00000000, source:raw]
    // CALL: Fallback path: call CharacterEncodingConvertViaLookupTableFallback(*a1, 8) to classify the current character with encoding fallback. [callee:0x0058C674, field:this:0x00000000, source:raw]
    // CALL: Call Strlen(a1) on the whitespace-skipped remainder (result value is not otherwise used in this function). [callee:0x0058E1B0, source:raw]
    // CALL: Call EncodingLocaleDetectionFromParseResult(v4, a1) to detect the locale encoding and parse the numeric string, writing the result into the local v4 parse-result structure. [callee:0x0058E12E, source:raw]
    // CALCULATION: Read the parsed double from the parse-result structure at offset 16. [callee:0x0058E12E, source:raw]
    // RETURN: Return the parsed double value. [source:raw]

    // Conservative worker pseudocode:
    //   double ParseDoubleFromStringWithWhitespaceSkip(unsigned char* s) {
    //     while (cbMultiByte <= 1 ? (off_5E69C8[0][*s] & 8) : CharacterEncodingConvertViaLookupTableFallback(*s, 8))
    //       ++s;
    //     Strlen(s);
    //     BYTE parseResult[24];
    //     return *(double*)(EncodingLocaleDetectionFromParseResult(parseResult, s) + 16);
    //   }
    // UNRESOLVED: The layout and field meaning of the EncodingLocaleDetectionFromParseResult parse-result structure, specifically the double stored at offset 16, are unknown.
    // UNRESOLVED: Why the Strlen(a1) return value is discarded is unclear; it may feed state only observable via side effects.
    // UNRESOLVED: The exact set of characters classified as whitespace (category 8) in the off_5E69C8 table is not enumerated here.
}
