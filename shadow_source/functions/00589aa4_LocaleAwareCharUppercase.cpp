// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589AA4
// Canonical corpus name: sub_589AA4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589AA4_00589aa4.c

void UnknownObject::LocaleAwareCharUppercase()
{
    // Converts a single character to uppercase. When a locale is configured (dword_8D3F38 non-zero), classifies the character via the off_5E69C8 table (or CharacterEncodingConvertViaLookupTableFallback when multi-byte), swaps byte order for two-byte input, calls sub_591FA1 (LCMapString wrapper) to perform the locale-aware uppercase conversion, and returns a 1-byte or 2-byte result. Without a locale, falls back to plain ASCII uppercasing ('a'-'z' minus 32). Returns the original character when no conversion applies or conversion fails.
    // GUARD: Guard on dword_8D3F38 (locale) being non-zero: locale-aware conversion path vs. the ASCII fallback path. [global:0x008D3F38, source:raw]
    // CALCULATION: Character classification: CharType >= 256 is treated as cased; otherwise, if cbMultiByte <= 1 test (off_5E69C8[0][CharType] & 2) directly, else call CharacterEncodingConvertViaLookupTableFallback(CharType, 2). Determines whether the char is convertible. [global:0x005E6BD4, global:0x005E69C8, callee:0x0058C674, source:raw]
    // GUARD: Secondary classification on off_5E69C8[0][BYTE1(v2)] >= 0 selects the 1-byte conversion path; otherwise the 2-byte path is used. [global:0x005E69C8, source:raw]
    // CALCULATION: 1-byte path: store (unsigned __int8)v2 into the low word of the input buffer (CharType) and prepare a 1-byte conversion length. [source:raw]
    // CALCULATION: 2-byte path: swap the byte order of CharType (low byte = BYTE1(v2), word at +1 = (unsigned __int8)v2) and prepare a 2-byte conversion length. [source:raw]
    // CALL: Call sub_591FA1(dword_8D3F38, 0x200, &CharType, length, DestStr, 3, 0, 1) to perform the locale uppercase mapping (LCMapString-style) into the DestStr buffer. [callee:0x00591FA1, global:0x008D3F38, source:raw]
    // RETURN: On successful conversion: return (unsigned __int8)DestStr[0] when the result length is 1, otherwise return the 16-bit value from DestStr. [source:raw]
    // RETURN: Fallback path when no locale: return CharType - 32 for 'a'-'z' (97..122), otherwise return the original CharType unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_589AA4(int ch) {
    //     if (dword_8D3F38) {
    //       int isCased = (ch >= 256)
    //           || (cbMultiByte <= 1 ? (off_5E69C8[0][ch] & 2) : CharacterEncodingConvertViaLookupTableFallback(ch, 2));
    //       if (isCased && conversion-succeeds) {
    //         int len, in = 0;
    //         if (off_5E69C8[0][BYTE1(ch)] >= 0) { LOWORD(in) = (BYTE)ch; len = 1; }
    //         else { LOBYTE(in) = BYTE1(ch); *(WORD*)((char*)&in + 1) = (BYTE)ch; len = 2; }
    //         int n = sub_591FA1(dword_8D3F38, 0x200, &in, len, DestStr, 3, 0, 1);
    //         if (n == 1) return (BYTE)DestStr[0]; else return *(WORD*)DestStr;
    //       }
    //       return ch;
    //     }
    //     if (ch >= 'a' && ch <= 'z') return ch - 32;
    //     return ch;
    //   }
    // UNRESOLVED: The off_5E69C8 character-type table and the meaning of the 0x2 bit and the BYTE1 index are not documented; classification semantics are inferred.
    // UNRESOLVED: sub_591FA1's exact conversion behavior (assumed LCMapString wrapper) and the significance of literal arguments 0x200, 3, 0, 1 are not proven.
    // UNRESOLVED: The two-byte return is a raw 16-bit value; endianness of the swapped input/result is DERIVED from the raw source.
}
