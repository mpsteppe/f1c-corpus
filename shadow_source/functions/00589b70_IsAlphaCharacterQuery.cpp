// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589B70
// Canonical corpus name: sub_589B70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589B70_00589b70.c

void UnknownObject::IsAlphaCharacterQuery()
{
    // Character-class query that tests a character code against the alpha (upper/lower letter) classification bits. In single-byte mode it masks the per-code classification table entry with 0x103; in multi-byte mode it delegates to the lookup-table conversion fallback with the same 0x103 (decimal 259) mask.
    // GUARD: Mode guard on the character-encoding state: when cbMultiByte <= 1 the code page is single-byte and the static classification table applies directly; otherwise the multi-byte conversion path is taken. [global:0x005E6BD4, source:raw]
    // CALCULATION: Single-byte path: read the classification table entry off_5E69C8[0][CharType] and keep only the bits selected by mask 0x103 (binary bits 0, 1 and 8, the upper/lower/alpha class bits). [global:0x005E69C8, source:raw]
    // CALL: Multi-byte path: delegate the classification to CharacterEncodingConvertViaLookupTableFallback, passing the character code and the decimal constant 259 (equal to 0x103) as the class mask. [callee:0x0058C674, source:raw]
    // RETURN: Return the masked classification flags from the selected path. [function:0x00589B70, source:raw]

    // Conservative worker pseudocode:
    //   int IsAlphaCharacterQuery(int CharType) {
    //       if (cbMultiByte <= 1)
    //           return off_5E69C8[0][CharType] & 0x103;
    //       return CharacterEncodingConvertViaLookupTableFallback(CharType, 259);
    //   }
    // UNRESOLVED: Exact bit-level meaning of mask 0x103 (upper/lower/alpha) is DERIVED from the mask value; the packet does not name the classification flags.
    // UNRESOLVED: LEGACY ABI name FAIL_589b70 carries no semantic signal.
}
