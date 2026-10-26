// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058EEF7
// Canonical corpus name: sub_58EEF7
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58EEF7_0058eef7.c

void UnknownObject::NormalizeCharacterInput()
{
    // Character normalization helper: selects a conversion path based on the cbMultiByte encoding mode global. When cbMultiByte <= 1 it tests flag bit 4 of a lookup-table entry indexed by the character; otherwise it delegates to CharacterEncodingConvertViaLookupTableFallback with the same bit test. If the bit test fails it returns an uppercased (mask 0xFFFFFFDF) form of the input minus 7; if the bit is set it returns the input unchanged. Called by sub_58E4D2.
    // ASSIGNMENT: v1 = CharType: preserve the original input for the unchanged return path. [source:raw]
    // GUARD: Branch on the cbMultiByte encoding-mode global: if cbMultiByte <= 1 use the direct lookup-table bit test, else call the fallback conversion routine. [global:0x005E6BD4, source:raw]
    // CALCULATION: v2 = off_5E69C8[0][CharType] & 4: test flag bit 4 of the per-character lookup-table entry for the encoding-conversion path. [global:0x005E69C8, source:raw]
    // CALL: v2 = CharacterEncodingConvertViaLookupTableFallback(CharType, 4): delegate the same bit-4 conversion test to the fallback routine when cbMultiByte > 1. [callee:0x0058C674, source:raw]
    // GUARD: Guard on the conversion flag: if v2 is zero the lookup reported no conversion, so fall through to the transform path. [source:raw]
    // CALCULATION: return (CharType & 0xFFFFFFDF) - 7: mask the input to its uppercase form and subtract 7, producing the converted output. [source:raw]
    // RETURN: Return the converted value when the flag bit was clear, otherwise return the original input v1. [function:0x0058EEF7, source:raw]
    // CALL: Invoked by sub_58E4D2 as part of its character-handling path. [caller:0x0058E4D2, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int NormalizeCharacterInput(int CharType) {
    //     int orig = CharType;
    //     int converted;
    //     if (cbMultiByte <= 1)
    //       converted = off_5E69C8[0][CharType] & 4;
    //     else
    //       converted = CharacterEncodingConvertViaLookupTableFallback(CharType, 4);
    //     if (!converted)
    //       return (CharType & 0xFFFFFFDF) - 7;
    //     return orig;
    //   }
    // UNRESOLVED: Meaning of flag bit 4 in the lookup-table entry and the character transform (CharType & 0xFFFFFFDF) - 7 is not established from this function alone.
    // UNRESOLVED: Role of the cbMultiByte encoding-mode global and the distinction between the two lookup paths is not documented here.
}
