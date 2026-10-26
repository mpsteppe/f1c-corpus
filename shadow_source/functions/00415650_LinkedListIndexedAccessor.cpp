// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00415650
// Canonical corpus name: LinkedListIndexedAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListIndexedAccessor_00415650.c

void UnknownObject::LinkedListIndexedAccessor()
{
    // Indexed accessor over a singly-linked list. The list object stores its head pointer at this+0 and its entry count at this[3] (+0xC). Given a zero-based index a2 it walks the head forward a2 times through each node's next pointer (second DWORD) and returns the first DWORD of the node at that index. Returns 0 when the index is out of bounds (a2 < 0 or a2 >= this[3]) or the walk reaches a null node before consuming the index.
    // GUARD: Returns 0 unless the requested index a2 is non-negative and strictly below the list count stored at this[3]. [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Loads the list head pointer from *this (this+0). [source:raw, field:this:0x00000000]
    // LOOP: Walks the singly-linked list by following each node's next pointer (second DWORD, node+4) until a2 steps are consumed; a null node encountered first causes an early return of 0. [source:raw, field:obj:0x00000004]
    // RETURN: Returns the first DWORD of the node reached at index a2, or 0 when no node exists at that index. [source:raw]
    // CALL: Invoked by SessionStringNameLookup (004122C0) and ShortComputation_5730 (00415730) as an indexed read over a linked list. [caller:0x004122C0, caller:0x00415730]

    // Conservative worker pseudocode:
    //   if (a2 < 0 || a2 >= this[3]) return 0;
    //   node = *this;
    //   while (node && a2 > 0) {
    //     node = node[1];
    //     --a2;
    //   }
    //   if (!node) return 0;
    //   return *node;
    // UNRESOLVED: The returned first DWORD's meaning (e.g. an ID or key) is caller-dependent and unknown here
    // UNRESOLVED: Field node+8 is listed by packet facts but never read in this function's raw source; its purpose is unverifiable from this packet
}
