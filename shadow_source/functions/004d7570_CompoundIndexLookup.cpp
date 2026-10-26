// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7570
// Canonical corpus name: CompoundIndexLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CompoundIndexLookup_004d7570.c

void UnknownObject::CompoundIndexLookup()
{
    // Validates a compound index a2 against the range [0, this[4]) and returns a pointer to the a2-th compound entry at this[5] + 680*a2. On an out-of-range index it conditionally logs a tire-brand error (gated on StringSplitLoop returning non-zero) and returns 0.
    // GUARD: if a2 >= 0 and a2 < this[4] (compound count at this+0x10) the index is in range [field:this:0x00000010, source:raw]
    // CALCULATION: compute the compound data pointer as this[5] (base at this+0x14) + 680*a2 bytes [field:this:0x00000014, source:raw]
    // RETURN: return the compound data pointer for an in-range index [field:this:0x00000014, source:raw]
    // GUARD: out-of-range path: proceed only if StringSplitLoop(1, source path string aDDevF119992002_4, 954) returns non-zero [callee:0x004D7A50, global:0x005D45E4, source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, aTireBrandDoesn) writes the out-of-range tire-brand error message [callee:0x004D7AA0, global:0x008AD25C, global:0x005D4950, source:raw]
    // RETURN: out-of-range path returns 0 (no valid compound pointer) [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 >= 0 && a2 < this[4]) return this[5] + 680*a2;
    //   if (StringSplitLoop(1, aDDevF119992002_4, 954))
    //       DebugLogWrite(&dword_8AD25C, aTireBrandDoesn);
    //   return 0;
    // UNRESOLVED: Meanings of this[4] (compound count) and this[5] (base pointer, 680-byte stride) are DERIVED from existing_analysis prose; the raw source shows only the arithmetic.
    // UNRESOLVED: The purpose of the 954 source-line argument to StringSplitLoop and the exact role of the gating check are not confirmed from the raw source alone.
}
