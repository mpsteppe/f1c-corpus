// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B4D4
// Canonical corpus name: sub_58B4D4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58B4D4_0058b4d4.c

void UnknownObject::ToLowerCaseChar()
{
    // Converts a character code to its lowercase form. When the global dword_8D3F38 is non-zero it runs an encoding-conversion path that packs the input into a multibyte buffer (guided by the off_5E69C8 character table and cbMultiByte) and converts it through sub_591FA1 into a wide buffer; otherwise it falls back to plain ASCII lowercase by adding 32 to uppercase letters.
    // GUARD: If dword_8D3F38 is zero, take the ASCII fast path and skip the encoding conversion. [global:0x008D3F38, source:raw]
    // GUARD: On the encoding path, proceed only if CharType is >= 256, or the per-character table bit off_5E69C8[0][CharType] & 1 is set, or (when cbMultiByte <= 1) the CharacterEncodingConvertViaLookupTableFallback check passes. [global:0x005E69C8, global:0x005E6BD4, callee:0x0058C674, source:raw]
    // CALCULATION: Determine the multibyte byte count v4 and re-pack CharType into a buffer: if the table entry off_5E69C8[0][BYTE1(v2)] is non-negative, keep the low byte and set v4 = 1; otherwise place the high byte first, append the low byte, and set v4 = 2. [global:0x005E69C8, source:raw]
    // CALL: Call sub_591FA1(dword_8D3F38, 0x100, &CharType, v4, DestStr, 3, 0, 1) to convert the packed multibyte character into the 3-slot destination buffer DestStr. [callee:0x00591FA1, global:0x008D3F38, source:raw]
    // RETURN: If the conversion returned 1, return the first byte of DestStr; if it returned 2, return the first unsigned 16-bit unit of DestStr; otherwise return the original CharType. [source:raw]
    // GUARD: On the ASCII path, lowercase an uppercase letter: if CharType is between 65 and 90 inclusive, return CharType + 32. [source:raw]
    // RETURN: Return CharType unchanged when it is not an uppercase ASCII letter. [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8D3F38 != 0)
    //       if (isMultibyteOrTableFlagged(CharType) && sub_591FA1(dword_8D3F38, 0x100, &CharType, v4, DestStr, 3, 0, 1) != 0)
    //           return (convertedCount == 1) ? byte(DestStr) : word(DestStr);
    //       return CharType;
    //   else
    //       if (CharType >= 'A' && CharType <= 'Z')
    //           return CharType + 32;
    //   return CharType;
    // UNRESOLVED: dword_8D3F38 is only evidenced as a required non-zero handle/flag on the encoding path; its concrete meaning (code page, conversion state) is not established.
    // UNRESOLVED: The constant 0x100 passed to sub_591FA1 is not interpreted.
    // UNRESOLVED: sub_591FA1's full contract (argument meanings and return-value encoding beyond 1/2) is not established from this single call site.
    // UNRESOLVED: Why cbMultiByte <= 1 selects the off_5E69C8 table lookup versus the CharacterEncodingConvertViaLookupTableFallback conversion is unknown.
}
