// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004189F0
// Canonical corpus name: ArraySearchReturningIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArraySearchReturningIndex_004189f0.c

void UnknownObject::SearchAndResetByID()
{
    // Linear scan of a 20-entry table rooted at this+0x864 (8 DWORD stride, first DWORD per entry is an ID). Every entry whose ID equals a2 is reset via StructInitWithSentinelValues. Returns 1 if at least one entry matched, otherwise 0.
    // ASSIGNMENT: Initialize result flag to 0 and set entry cursor to the start of the 20-entry search table at this+0x864 (this+537), with 20 entries remaining. [field:this:0x00000864, function:0x004189F0, source:raw]
    // LOOP: Iterate over the 20 entries advancing the cursor by 8 DWORDs per entry until the counter reaches zero. [field:this:0x00000864, source:raw]
    // GUARD: Match when the entry's first DWORD (ID field) equals the search id a2. [field:this:0x00000864, source:raw]
    // CALL: On match, call StructInitWithSentinelValues with the matched entry pointer to reset the entry to sentinel/default values. [callee:0x004144D0, source:raw]
    // ASSIGNMENT: Set the result flag to 1 on any match so the caller learns at least one entry was found and reset. [function:0x004189F0, source:raw]
    // RETURN: Return 1 if any entry matched, otherwise 0. [function:0x004189F0, source:raw]

    // Conservative worker pseudocode:
    //   int SearchAndResetByID(this, id) {
    //     entry = this + 0x864;
    //     result = 0;
    //     for (remaining = 20; remaining != 0; remaining--) {
    //       if (*entry == id) {
    //         StructInitWithSentinelValues(entry);
    //         result = 1;
    //       }
    //       entry += 8;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Purpose of the reset entries and which caller-specific entity IDs flow through a2 is not derivable from this function alone.
}
