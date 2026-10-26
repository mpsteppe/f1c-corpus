// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589BC6
// Canonical corpus name: sub_589BC6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589BC6_00589bc6.c

void UnknownObject::CharacterHighBitTest()
{
    // Character-class high-bit test for a given CharType. In single-byte mode (cbMultiByte <= 1) it returns the 0x80 bit of the character class table entry off_5E69C8[0][CharType]; otherwise it delegates to CharacterEncodingConvertViaLookupTableFallback(CharType, 128).
    // GUARD: Branch on the cbMultiByte global (0x5E6BD4): when it is <= 1 the single-byte lookup path is taken, otherwise the fallback converter is used. [global:0x005E6BD4, source:raw]
    // CALCULATION: Single-byte path: return off_5E69C8[0][CharType] & 0x80, i.e. test the high bit of the character-class table entry indexed by row 0 and column CharType. [global:0x005E69C8, source:raw]
    // CALL: Multi-byte path: return CharacterEncodingConvertViaLookupTableFallback(CharType, 128). [callee:0x0058C674, source:raw]
    // CALL: Consumed by StringPrefixPatternCheck (005685B0) and sub_568910 (00568910). [caller:0x005685B0, caller:0x00568910, source:raw]

    // Conservative worker pseudocode:
    //   int sub_589BC6(int CharType) {
    //     if (cbMultiByte <= 1) {
    //       return off_5E69C8[0][CharType] & 0x80;
    //     }
    //     return CharacterEncodingConvertViaLookupTableFallback(CharType, 128);
    //   }
    // UNRESOLVED: Semantics of the off_5E69C8 table (a character-class table with per-codepage rows) is not grounded in this packet.
    // UNRESOLVED: Meaning of the return bit (0x80 = 128) is unknown; callers likely use it as a class flag while scanning strings.
    // UNRESOLVED: Valid range of CharType and the relationship between cbMultiByte and codepage selection are unresolved.
}
