// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407070
// Canonical corpus name: ArrayLinkedListVirtualDispatchIterator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayLinkedListVirtualDispatchIterator_00407070.c

void UnknownObject::ArrayLinkedListVirtualDispatchIterator()
{
    // Container-walk that dispatches a different virtual method slot than its sibling iterator: vtable+16 for array entries (20-byte stride, base this+0x48, count this+0x4C) and vtable+20 for linked-list nodes (head this+0x18, iterator this+0x20). Likely an alternative processing pass over the same two object containers. Returns the final linked-list node pointer.
    // GUARD: Skip both walks entirely when the array base pointer at this+0x48 is null. [field:this:0x00000048]
    // GUARD: Guard on the array entry count at this+0x4C: the array is only walked when the count is greater than 0. [guard:0, field:this:0x0000004C]
    // LOOP: Walk the array of 20-byte entries beginning at this+0x48, bounded by the entry count at this+0x4C. [field:this:0x00000048, field:this:0x0000004C]
    // CALL: For each non-null array entry, dispatch virtual method vtable+16 on it (thiscall). [source:raw]
    // ASSIGNMENT: Seed the traversal variable from the linked-list head pointer at this+0x18 and store it into the iterator field this+0x20. [field:this:0x00000018, field:this:0x00000020]
    // GUARD: Only enter the linked-list walk when the head pointer at this+0x18 is non-null. [field:this:0x00000018]
    // ASSIGNMENT: Read the first linked-list node pointer from the head object's first dword (the vtable pointer slot). [field:*(this+0x18):0x00000000, field:this:0x00000018]
    // LOOP: Iterate the linked list, following the next-node pointer stored at node+4, until a null node terminates the walk. [source:raw]
    // CALL: Dispatch virtual method vtable+20 on each linked-list node (thiscall). [field:*(*(this+0x18)+0x0):0x00000014]
    // ASSIGNMENT: Advance the iterator field this+0x20 to the next node during the list traversal. [field:this:0x00000020]
    // RETURN: Return the final linked-list node pointer (null when the list was empty or fully consumed). [source:raw]

    // Conservative worker pseudocode:
    //   int *ArrayLinkedListVirtualDispatchIterator(_DWORD *this) {
    //     int *result;
    //     if (this[18]) {
    //       if (this[19] > 0)
    //         for (int n = 0, off = 0; n < this[19]; ++n, off += 20)
    //           if (void *e = *(void **)(off + this[18]))
    //             ((void (__thiscall *)(void *))(*(_DWORD *)e + 16))(e);
    //     }
    //     result = (int *)this[6];
    //     this[8] = result;
    //     if (result) {
    //       for (int *i = *result; *result; i = *result) {
    //         ((void (__thiscall *)(int))(*(_DWORD *)i + 20))(i);
    //         result = (int *)this[8];
    //         if (!result) break;
    //         result = (int *)result[1];
    //         this[8] = result;
    //         if (!result) break;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identity of the dispatched virtual methods (vtable+16 array, vtable+20 list) is unknown; they are indirect calls with no static name.
    // UNRESOLVED: Fields this+0x24 and this+0x28 have no source-level reference in this function; their semantics are unknown.
    // UNRESOLVED: Owner object type and whether this is a distinct pass or an alternate entry over the same containers are not established.
}
