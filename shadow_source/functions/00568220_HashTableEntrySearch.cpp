// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568220
// Canonical corpus name: HashTableEntrySearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HashTableEntrySearch_00568220.c

void UnknownObject::HashTableEntrySearch()
{
    // Get-or-create lookup in a string-keyed bucket linked list. Walks the list starting at this[9], comparing each entry's string (defaulting empty keys to byte_5EA438) against a2 via sub_588410; if a match with a stored value other than -1 is found, returns that value. Otherwise allocates a new 12-byte entry whose key is copied with StringCopyWithBufferRealloc, assigns it the next index from this[13], allocates a 12-byte list wrapper node, inserts the entry into the head/tail list (incrementing the count this[12]), and returns the freshly assigned index.
    // ASSIGNMENT: Initialize the default result to -1 before any checks. [source:raw]
    // GUARD: If the search key a2 is null, return the default -1 result. [source:raw]
    // ASSIGNMENT: Load the bucket head pointer from this[9] into the current walk pointer this[11]. [field:this:0x00000024, field:this:0x0000002C]
    // GUARD: If the bucket head is null, jump straight to the create-new-entry path. [field:this:0x00000024]
    // LOOP: Walk the linked list; for each entry read its stored string pointer from the first dword of the entry, substituting the default string byte_5EA438 when that pointer is null. [source:raw, field:*(this+0x24):0x00000000, global:0x005EA438]
    // CALL: Compare the current entry's string against a2 with sub_588410; a zero result means a match and breaks the walk. [source:raw, callee:0x00588410]
    // ASSIGNMENT: On a non-match, advance the walk pointer by reading the next link from the second dword of the current walk node into this[11]. [field:this:0x0000002C]
    // ASSIGNMENT: Read the stored index value from the third dword of the matched entry as the candidate result. [field:*(this+0x2C):0x00000008]
    // GUARD: If the stored index value is not -1, return it; a value of -1 falls through to the create-new-entry path. [field:*(this+0x2C):0x00000008]
    // CALL: Allocate a 12-byte entry node with OperatorNewNhMallocWrapper; when allocation fails the node pointer is nulled. [callee:0x00587C03]
    // ASSIGNMENT: Initialize the new entry: null string pointer, stored value -1, copy the key with StringCopyWithBufferRealloc, and store the pre-increment value of the next-index counter this[13] as the entry index, then increment this[13]. [field:this:0x00000034, callee:0x00566650]
    // CALL: Allocate a 12-byte list wrapper node; on success set its data pointer to the entry, its next link to null and a one-byte flag to 1. [callee:0x00587C03]
    // GUARD: If the bucket head this[9] is still null, the new wrapper becomes head, tail and current walk pointer (this[9], this[11], this[10]) and the entry count this[12] is incremented. [field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030]
    // ASSIGNMENT: Otherwise link the current tail node to the new wrapper, update the tail pointer this[10] to it, and increment the entry count this[12]. [field:this:0x00000028, field:this:0x00000030]
    // RETURN: Return the freshly assigned index from the new entry (the previous value of the next-index counter). [field:this:0x00000034]

    // Conservative worker pseudocode:
    //   // String-key get-or-create over a bucket linked list; returns the stored index.
    //   int result = -1;
    //   if (!a2) return -1;
    //   this[11] = this[9];
    //   if (!this[11]) goto create;
    //   node = *this[11];
    //   if (!node) goto create;
    //   while (true) {
    //     const char* key = *(const char**)node;
    //     if (!*(void**)node) key = (const char*)byte_5EA438;
    //     if (sub_588410(key, a2) == 0) break;
    //     this[11] = this[11] ? *(void**)(this[11] + 1) : 0;
    //     if (!this[11]) goto create;
    //     node = *this[11];
    //     if (!node) goto create;
    //   }
    //   result = *(int*)(node + 2);
    //   if (result != -1) return result;
    //   create:
    //   entry = OperatorNewNhMallocWrapper(12);
    //   if (entry) {
    //     index = this[13]++;
    //     entry[0] = 0; entry[1] = -1;
    //     StringCopyWithBufferRealloc(entry, a2);
    //     entry[2] = index;
    //   }
    //   if (entry) {
    //     wrap = OperatorNewNhMallocWrapper(12);
    //     if (wrap) { *(void**)wrap = entry; *(void**)(wrap + 1) = 0; *(byte*)(wrap + 2) = 1; }
    //     if (!this[9]) { this[9] = wrap; this[11] = wrap; this[10] = wrap; ++this[12]; return entry[2]; }
    //     *(void**)(this[10] + 1) = wrap;
    //     this[10] = wrap;
    //     ++this[12];
    //   }
    //   return entry[2];
    // UNRESOLVED: The default string byte_5EA438 is treated as a fallback key for entries with null string pointers; its actual content and why a null key is replaced are not determined here.
    // UNRESOLVED: The bucket index computation and the hash function feeding the bucket head this[9] are external to this function.
}
