// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058FC20
// Canonical corpus name: sub_58FC20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58FC20_0058fc20.c

void UnknownObject::findFirstCharIndex()
{
    // Character-set first-match helper. Builds a 32-byte (256-bit) membership bitset from every byte of string a2, then scans string a1 and returns the index of the first character whose bit is set in that set. If a1 holds no matching character, the scan runs to the null terminator and returns that length index. Called by sub_588A34 and sub_588F8B.
    // ASSIGNMENT: Zero the 32-byte (256-bit) bitset buffer v7 with memset(v7, 0, 32). [source:raw]
    // LOOP: Walk string a2 byte by byte until the null terminator. [source:raw]
    // CALCULATION: Set the bit for the current byte of a2 in the membership bitset with _bittestandset. [source:raw]
    // LOOP: Walk string a1 byte by byte, tracking the running index in v5. [source:raw]
    // GUARD: Continue scanning a1 only while the current byte's bit is not set in the membership bitset; stop at the null terminator. [source:raw]
    // CALCULATION: Advance the index counter v5 and pointer a1 each iteration. [source:raw]
    // RETURN: Return v5, the index of the first matched character (or the string length when no character matches). [source:raw]

    // Conservative worker pseudocode:
    //   byte membership[32] = {0};
    //   for each byte c in a2 (until NUL): set bit c in membership;
    //   idx = -1;
    //   loop { ++idx; c = a1[idx]; if (c == 0) break; if (bit(c) in membership) break; }
    //   return idx;
    // UNRESOLVED: field:this:0x00000000 is a spurious template-generated field; the raw source is a __cdecl helper taking two byte-string pointers and no `this`.
    // UNRESOLVED: No-match behavior returns the index of the a1 null terminator (its length) rather than -1, even though v5 is initialised to -1 before the scan.
    // UNRESOLVED: The bitset is built from a2 with _bittestandset and probed with _bittest; the interpretation that this finds the first a1 character also occurring in a2 is DERIVED.
}
