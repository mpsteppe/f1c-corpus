// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589C49
// Canonical corpus name: CharacterClassificationQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CharacterClassificationQuery_00589c49.c

void UnknownObject::CharacterClassificationQuery()
{
    // Character-class query that tests a character code against a broad printable-class bit set. In single-byte mode it masks the per-code classification table entry with 0x157; in multi-byte mode it delegates to the lookup-table conversion fallback with the same 0x157 (decimal 343) mask.
    // GUARD: Mode guard on the character-encoding state: when cbMultiByte <= 1 the code page is single-byte and the static classification table applies directly; otherwise the multi-byte conversion path is taken. [global:0x005E6BD4, source:raw]
    // CALCULATION: Single-byte path: read the classification table entry off_5E69C8[0][CharType] and keep only the bits selected by mask 0x157 (binary bits 0, 1, 2, 4, 6 and 8, spanning upper/lower/digit/punct/blank/alpha class bits). [global:0x005E69C8, source:raw]
    // CALL: Multi-byte path: delegate the classification to CharacterEncodingConvertViaLookupTableFallback, passing the character code and the decimal constant 343 (equal to 0x157) as the class mask. [callee:0x0058C674, source:raw]
    // RETURN: Return the masked classification flags from the selected path. [function:0x00589C49, source:raw]

    // Conservative worker pseudocode:
    //   int CharacterClassificationQuery(int CharType) {
    //       if (cbMultiByte <= 1)
    //           return off_5E69C8[0][CharType] & 0x157;
    //       return CharacterEncodingConvertViaLookupTableFallback(CharType, 343);
    //   }
    // UNRESOLVED: Broad-class interpretation of mask 0x157 is DERIVED from the mask value; the packet does not name the classification flags.
    // UNRESOLVED: Proposed name follows the packet canonical name CharacterClassificationQuery.
    // UNRESOLVED: LEGACY ABI name Character_Classification_Query is consistent with the canonical name but carries no stronger trust.
}
