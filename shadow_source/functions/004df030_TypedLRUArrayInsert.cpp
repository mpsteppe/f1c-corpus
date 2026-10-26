// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DF030
// Canonical corpus name: sub_4DF030
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DF030_004df030.c

void UnknownObject::TypedLRUArrayInsert()
{
    // Builds a 9-float stack entry carrying a type marker of 1 in slot 0 and the given float value a2 in slot 1, zeroes the remaining seven slots, then inserts it into the sorted LRU array via SortedArrayInsertWithLRUEviction only when the dword flag at this+24 (offset 0x18) is nonzero; returns the flag value when the insertion is skipped.
    // ASSIGNMENT: Store the given float value a2 into entry slot 1 of the local 9-float array. [source:raw]
    // ASSIGNMENT: Read the type/flag dword at this+24 (offset 0x18) as the insertion-enable result value. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Set entry slot 0 to the type marker value 1. [source:raw]
    // CALL: Zero the remaining 28 bytes of the entry (slots 2 through 8) with memset. [source:raw]
    // GUARD: When the dword at this+24 (offset 0x18) is nonzero, proceed with the insertion. [field:this:0x00000018, source:raw]
    // CALL: Insert the built 9-float entry into the sorted LRU array with SortedArrayInsertWithLRUEviction(this, v3). [callee:0x004DEDB0, source:raw]
    // RETURN: Return the insertion result; when the flag was zero, return that flag value without inserting. [source:raw]

    // Conservative worker pseudocode:
    //   int TypedLRUArrayInsert(int this, float a2) {
    //     float v3[9];
    //     v3[0] = 1;
    //     v3[1] = a2;
    //     memset(&v3[2], 0, sizeof(v3) - 8);
    //     int result = *(int*)(this + 24);
    //     if (result) return SortedArrayInsertWithLRUEviction((float*)this, v3);
    //     return result;
    //   }
    // UNRESOLVED: The semantic meaning of the dword flag at this+24 and the exact array element layout consumed by SortedArrayInsertWithLRUEviction are not established by the packet alone.
    // UNRESOLVED: The caller UIElementMultiDispatch (0x004E39D0) passes no further context that identifies the owning class.
}
