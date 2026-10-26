// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589B9E
// Canonical corpus name: sub_589B9E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589B9E_00589b9e.c

void UnknownObject::IsDigitCharacterQuery()
{
    // Character-class query that tests a character code against the digit classification bit. In single-byte mode it masks the per-code classification table entry with 4; in multi-byte mode it delegates to the lookup-table conversion fallback with the same mask value 4.
    // GUARD: Mode guard on the character-encoding state: when cbMultiByte <= 1 the code page is single-byte and the static classification table applies directly; otherwise the multi-byte conversion path is taken. [global:0x005E6BD4, source:raw]
    // CALCULATION: Single-byte path: read the classification table entry off_5E69C8[0][CharType] and keep only the bit selected by mask 4 (binary bit 2, the digit class bit). [global:0x005E69C8, source:raw]
    // CALL: Multi-byte path: delegate the classification to CharacterEncodingConvertViaLookupTableFallback, passing the character code and the class mask 4. [callee:0x0058C674, source:raw]
    // RETURN: Return the masked classification flags from the selected path. [function:0x00589B9E, source:raw]

    // Conservative worker pseudocode:
    //   int IsDigitCharacterQuery(int CharType) {
    //       if (cbMultiByte <= 1)
    //           return off_5E69C8[0][CharType] & 4;
    //       return CharacterEncodingConvertViaLookupTableFallback(CharType, 4);
    //   }
    // UNRESOLVED: Digit-class interpretation of mask 4 is DERIVED from the mask value; the packet does not name the classification flags.
    // UNRESOLVED: Callers include PPMP6ImageDecoder (0x00501E39) in addition to sub_48B560; the calling context is not part of this packet.
}
