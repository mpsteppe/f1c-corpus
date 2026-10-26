// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587DD0
// Canonical corpus name: sub_587DD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587DD0_00587dd0.c

void UnknownObject::boundedStringCopy()
{
    // Bounded NUL-terminated string copy with destination padding. Copies at most a3 bytes from source a2 to destination a1; stops at the terminating zero byte and, when room remains within the count, fills the rest of the destination with zero bytes. Returns a1. Fast path copies whole dwords using an embedded-zero detection mask (0x81010100 test on (word + 2130640639) ^ word ^ 0xFFFFFFDE) and a byte-at-a-time fallback for unaligned sources. Callers are string/file-path and name-copy routines.
    // GUARD: Guard on copy count: when a3 is zero, return a1 immediately without touching the destination. [field:this:0x00000000, source:raw]
    // GUARD: Guard on source alignment: when a2 is 4-byte aligned the word-at-a-time fast path is used; otherwise a byte-by-byte loop copies until the source becomes aligned. [source:raw]
    // LOOP: Byte copy loop: read *v5++, write *v6++, stop on a zero terminator byte or when the remaining count (v4/v3) is exhausted; on early terminator the remaining slots of the destination are zero-padded. [field:this:0x00000000, source:raw]
    // CALCULATION: Fast-path zero detection: v11 = (word + 2130640639) ^ word ^ 0xFFFFFFDE; a non-zero (v11 & 0x81010100) indicates an embedded zero byte within the loaded 4-byte word. [source:raw]
    // CALCULATION: Fast-path terminator position: inspect the loaded word for zero in byte 0, byte 1 ((v12 & 0xFF0000) == 0), or byte 2 ((v12 & 0xFF000000) == 0) and keep only the bytes before the terminator. [source:raw]
    // ASSIGNMENT: Fast path writes the truncated word (1, 2 or 3 bytes, or a full dword when no terminator is present) into the destination and advances v6 by 4. [source:raw]
    // ASSIGNMENT: After a terminator, pad the destination with zero bytes for the remainder of the count: dword stores of 0 while count permits, then the leftover 0 to 3 bytes. [field:this:0x00000000, source:raw]
    // RETURN: Return a1, the destination buffer, on every exit path. [field:this:0x00000000, function:0x00587DD0]

    // Conservative worker pseudocode:
    //   byte* boundedStringCopy(byte* dest, char* src, unsigned count) {
    //     if (count == 0) return dest;
    //     // aligned fast path copies whole dwords, stopping at a zero byte;
    //     // unaligned path falls back to byte copies until src is aligned.
    //     // A terminating zero zero-pads the rest of dest up to count.
    //     return dest;
    //   }
    // UNRESOLVED: Destination field this+0x00000000 is treated as the byte buffer written and returned; no object identity for that buffer is established by the packet.
    // UNRESOLVED: Exact bound semantics (hard cap vs strlen-style) depend on caller usage; the many string-copy callers are consistent with a bounded string copy but none are verified here.
    // UNRESOLVED: Owner is unknown: the DERIVED cluster_copy prelabel names a structural twin (sub_464D20) but provides no object type.
}
