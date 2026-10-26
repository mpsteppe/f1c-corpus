// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596E0F
// Canonical corpus name: sub_596E0F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596E0F_00596e0f.c

void UnknownObject::TestBitFlagMask()
{
    // Tests whether a byte flag and a word mask indicate a set condition, indexing two global lookup tables by a1. Returns 1 if the byte flag a3 has any bit in common with byte_8D47E1[a1], or if a2 is non-zero and has any bit in common with word_5E69D2[a1]. Returns 0 otherwise.
    // GUARD: If (a3 & byte_8D47E1[index]) is non-zero, return 1 immediately. [global:0x008D47E1, source:raw]
    // ASSIGNMENT: Compute maskedWord: when a2 is non-zero, (a2 & word_5E69D2[index]) truncated to 16 bits; otherwise 0. [global:0x005E69D2, source:raw]
    // GUARD: If maskedWord is non-zero, return 1. [source:raw]
    // RETURN: Return maskedWord (0 when no bit matched in either table). [source:raw, function:0x00596E0F]

    // Conservative worker pseudocode:
    //   if ((byteFlag & byte_8D47E1[index]) != 0) return 1;
    //   result = wordFlags ? (wordFlags & word_5E69D2[index]) : 0;
    //   if (result != 0) return 1;
    //   return result;
    // UNRESOLVED: The semantic roles of byte_8D47E1 and word_5E69D2 (e.g. per-index input/modifier bit masks) and the meaning of the index a1 are unknown.
    // UNRESOLVED: The single static caller is 0x00596DFE (ThreeArgCallWrapper); its relationship to this predicate is not analyzed here.
    // UNRESOLVED: Why the word test casts to a 16-bit value while the byte test does not is unexplained.
}
