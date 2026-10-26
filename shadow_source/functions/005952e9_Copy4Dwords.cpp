// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005952E9
// Canonical corpus name: F_4IntCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4IntCopy_005952e9.c

void UnknownObject::Copy4Dwords()
{
    // Copies exactly 4 DWORDs from source pointer a2 to destination a1 by walking the source forward and writing each element to a1 + (source - a2). The source pointer is written only at offset 0 of the destination window per iteration, so each source DWORD overwrites the same destination base a1 with its value. Returns the source pointer advanced 4 DWORDs (16 bytes) past its start.
    // ASSIGNMENT: Seed the walking pointer result = a2 (source base) and the counter v3 = 3, giving 4 loop iterations. [source:raw]
    // LOOP: do-while loop over 4 DWORDs: the body runs until the countdown v3 (3,2,1) reaches zero. [source:raw]
    // ASSIGNMENT: Each iteration writes one source DWORD: *(a1 + (result - a2)) = *result, so the 4 source words land at destination offsets 0,4,8,12 from base a1. [source:raw]
    // CALCULATION: Advance the walking pointer: ++result (4 bytes) and --v3 after each store. [source:raw]
    // RETURN: Return the source pointer advanced 4 DWORDs past a2; the only static caller is sub_5953B8. [caller:0x005953B8, source:raw]

    // Conservative worker pseudocode:
    //   DWORD *sub_5952E9(int dest, DWORD *src) {
    //     DWORD *p = src;
    //     int n = 3;
    //     do { *(DWORD *)((char *)p + dest - (DWORD)src) = *p; ++p; --n; } while (n);
    //     return p;
    //   }
    // UNRESOLVED: The identity and layout of the object owned by dest/src is unknown; only that 4 consecutive DWORDs are copied.
    // UNRESOLVED: Whether dest and src may alias and what the caller (sub_5953B8) uses the returned advanced pointer for is not evident in this packet.
}
