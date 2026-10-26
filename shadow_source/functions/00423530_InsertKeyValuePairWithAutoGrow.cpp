// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423530
// Canonical corpus name: SortedStringTableBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SortedStringTableBuilder_00423530.c

void UnknownObject::InsertKeyValuePairWithAutoGrow()
{
    // Inserts a key/value string pair (a2, a3) into a growable string table stored at this (this[0] = capacity, this[1] = count, this[2] = entries pointer). Rejects the pair with -1 when a2 is null, a3 is null, either string is empty, or the two strings are equal. When count has reached capacity the table grows by 128 slots: a new buffer of 16 * new_capacity + 4 bytes is allocated (4-byte header holding the new capacity, followed by entries initialized to {0, -1, 0, -1}), each existing entry's two string fields are duplicated through StringCopyWithBufferRealloc (null strings substituted with byte_5EA438), and the old buffer's entry strings and header are freed. The count is then incremented and both new strings are duplicated via StringCopyWithBufferRealloc before returning 0. Called by sub_423890 (0x00423890).
    // GUARD: Early-out: if the key a2 is null, return -1. [source:raw]
    // GUARD: Early-out: if a3 is null, strlen(a2) is zero, strlen(a3) is zero, or strcmp(a2, a3) is zero (equal strings), return -1. [source:raw]
    // GUARD: Growth branch taken when the count this[1] (offset 0x4) is >= the capacity this[0] (offset 0x0). [field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Grows capacity: v6 = this[0] + 128 and this[0] = v6. [field:this:0x00000000, source:raw]
    // CALL: OperatorNewNhMallocWrapper(16 * (v5 + 128) + 4) allocates the new buffer: 4 bytes of header plus 16 bytes per entry. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: When allocation succeeds the header word is set to the new capacity v6 and the entry region begins at v7 + 1; on failure the new entries pointer v20 is set to 0. [source:raw]
    // LOOP: Initializes each of the new-capacity entries to {0, -1, 0, -1} (4 dwords per entry). [source:raw]
    // LOOP: Copy pass over the existing count this[1] entries (16-byte stride from this[2]): each entry's two string fields (+0 and +8) are read, substituted with &byte_5EA438 when null, and each passed to StringCopyWithBufferRealloc. [field:this:0x00000004, field:this:0x00000008, guard:0, global:0x005EA438, callee:0x00566650, source:raw]
    // CALL: Frees the old buffer: walks its entries backwards freeing each entry's two string pointers via ShortComputation_4370, then FreeWrapper_7bcf frees the buffer header at this[2] - 4. [callee:0x00414370, callee:0x00587BCF, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Repoints this[2] (offset 0x8) at the new entries buffer v20. [field:this:0x00000008, source:raw]
    // CALCULATION: Increments the count this[1] (offset 0x4). [field:this:0x00000004, source:raw]
    // CALL: Duplicates the new key a2 and the new value a3 through StringCopyWithBufferRealloc (the duplicated pointers are stored into the entry region on the caller's behalf via the buffer writes). [callee:0x00566650, source:raw]
    // RETURN: Returns 0 on success; all rejection paths return -1. [source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return -1;
    //   if (!a3 || !strlen(a2) || !strlen(a3) || !strcmp(a2, a3)) return -1;
    //   if (this[1] >= this[0]) {
    //       this[0] += 128;
    //       v7 = OperatorNewNhMallocWrapper(16 * this[0] + 4);
    //       if (v7) { v7[0] = this[0]; v20 = v7 + 1; init each entry to {0,-1,0,-1}; }
    //       else v20 = 0;
    //       for (i = 0; i < this[1]; ++i) {
    //           StringCopyWithBufferRealloc(this[2][i].s0 ? this[2][i].s0 : byte_5EA438);
    //           StringCopyWithBufferRealloc(this[2][i].s1 ? this[2][i].s1 : byte_5EA438);
    //       }
    //       if (this[2]) { for each old entry: ShortComputation_4370(s1); ShortComputation_4370(s0); FreeWrapper_7bcf(this[2] - 4); }
    //       this[2] = v20;
    //   }
    //   ++this[1];
    //   StringCopyWithBufferRealloc(a2); StringCopyWithBufferRealloc(a3);
    //   return 0;
    // UNRESOLVED: The sorted-string-table semantics implied by the ABI/canonical name (SortedStringTableBuilder) are not evidenced in this function, which shows only insertion and capacity growth; the insertion position logic is absent from the packet.
    // UNRESOLVED: The per-entry layout {char* string, int, char* string, int} and the {0,-1,0,-1} empty-entry convention are DERIVED readings of the raw source, not independently confirmed.
    // UNRESOLVED: The three StringCopyWithBufferRealloc calls in the copy/growth path discard their return values in the raw source; whether they duplicate strings into the new buffer or just validate/reallocate in place is not confirmed.
    // UNRESOLVED: The meaning of the growth step 128 and the role of the 4-byte header word are source facts whose structural semantics are not confirmed.
}
