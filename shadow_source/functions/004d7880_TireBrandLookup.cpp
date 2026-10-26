// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7880
// Canonical corpus name: TireBrandLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireBrandLookup_004d7880.c

void UnknownObject::TireBrandLookup()
{
    // Searches a tire-brand table for a name matching a2. Iterates up to *this entries stored at this[1] with a 36-byte stride, comparing each entry's brand-name string via sub_588410 and falling back to byte_5EA438 when a name pointer is null. Returns a pointer to the matching entry (this[1] + 36 * index), or on miss logs a non-existent-tire message (gated by dword_7C569C != 5 and StringSplitLoop) and returns 0.
    // GUARD: Entry-count guard: if *this (field this+0x0) is <= 0, take the not-found path immediately. [field:this:0x00000000, guard:0, source:raw]
    // LOOP: Search loop over the brand table at this[1] (field this+0x4), stride 36 bytes per entry: load the brand-name string pointer, substitute byte_5EA438 when null, and compare it against the lookup key a2 via sub_588410. [field:this:0x00000004, global:0x005EA438, callee:0x00588410, source:raw]
    // RETURN: On a match return a pointer to the matching entry: this[1] + 36 * v3. [field:this:0x00000004, function:0x004D7880, source:raw]
    // GUARD: Not-found reporting guard: when the session type dword_7C569C != 5 and StringSplitLoop(1, aDDevF119992002_4, 1080) returns nonzero, write the non-existent-tire message aNonExistentTir to the debug log via DebugLogWrite(&dword_8AD25C, aNonExistentTir). [global:0x007C569C, callee:0x004D7A50, global:0x005D45E4, callee:0x004D7AA0, global:0x008AD25C, global:0x005D49E4, source:raw]
    // RETURN: Return 0 when the brand name is not found in the table. [function:0x004D7880, source:raw]

    // Conservative worker pseudocode:
    //   int TireBrandLookup(int* this, int key) {
    //     if (*this <= 0) goto not_found;
    //     for (int i = 0; i < *this; ++i) {
    //       char* name = *(char**)(this[1] + 36 * i);
    //       if (!name) name = byte_5EA438;
    //       if (!sub_588410(key, name)) return this[1] + 36 * i;
    //     }
    //   not_found:
    //     if (dword_7C569C != 5) {
    //       if (StringSplitLoop(1, aDDevF119992002_4, 1080))
    //         DebugLogWrite(&dword_8AD25C, aNonExistentTir);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: sub_588410 is assumed to be a string-equality comparator (from the surrounding search context); its behavior is not in this packet.
    // UNRESOLVED: The 36-byte entry layout at this[1] is only partially known: offset 0 holds a brand-name string pointer, the remaining bytes are not described.
    // UNRESOLVED: The not-found debug message is emitted only when dword_7C569C != 5 (session-type dependent) and StringSplitLoop validates a source path; the exact gating semantics are inferred.
}
