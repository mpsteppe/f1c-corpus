// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BFD40
// Canonical corpus name: IndexedListLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedListLookup_004bfd40.c

void UnknownObject::IndexedListLookup()
{
    // Linked-list index accessor. Guards on the requested index a2 against the list count at this+0xC; resets the iterator this+0x8 to null for a negative index, otherwise seeds it from the head at this+0x0 and walks the next-node links (node + 4) a2 times. From the node reached, reads its data pointer (first DWORD of the node) and returns the first DWORD of that data. Returns 0 when the index is out of range, the walk hits a null node, or either pointer is null. __thiscall.
    // ASSIGNMENT: Initialize the working index v2 = a2 and the default result = 0. [source:raw]
    // GUARD: Guard: proceed only when a2 < this[3] (this+0xC list count); otherwise return the default 0. [source:raw, field:this:0x0000000C]
    // STATE_TRANSITION: For a negative a2, set the iterator this[2] (this+0x8) to 0 (no list element). [source:raw, field:this:0x00000008]
    // ASSIGNMENT: For non-negative a2, seed the iterator this[2] from the list head this[0] (this+0x0). [source:raw, field:this:0x00000008, field:this:0x00000000]
    // LOOP: do-while walk of up to a2 steps: read the current node v4 = this[2]; if null, break; otherwise decrement v2 and advance this[2] to the next-node link stored at v4 + 4. [source:raw, field:this:0x00000008]
    // GUARD: Guard: v5 = this[2]; continue only when the reached node v5 is non-null. [source:raw, field:this:0x00000008]
    // GUARD: Guard: v6 = *v5 (data pointer); continue only when the node's data pointer v6 is non-null. [source:raw, field:*(this+0x8):0x00000000]
    // RETURN: Return the first DWORD of the node's data, *(_DWORD *)v6. [source:raw, field:*(this+0x8):0x00000000]
    // RETURN: Return the default 0 when the index guard fails or a null node/data pointer is encountered. [source:raw]
    // CALL: Called by AIDriverCountSetup (0x004BFD90) to look up an indexed list entry. [caller:0x004BFD90, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4BFD40(_DWORD *this, int index) {
    //     int result = 0;
    //     if (index < this[3]) {
    //       if (index < 0) {
    //         this[2] = 0;
    //       } else {
    //         this[2] = *this;
    //         int n = index;
    //         while (n > 0) {
    //           int node = this[2];
    //           if (!node) break;
    //           --n;
    //           this[2] = *(int *)(node + 4);
    //         }
    //       }
    //       int *node = (int *)this[2];
    //       if (node) {
    //         int data = *node;
    //         if (data) return *(int *)data;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Node layout: the next-node link is read at node + 4, but that offset has no packet field evidence reference and its structure is unverified.
    // UNRESOLVED: Meaning of the returned first DWORD of the node's data and the list's element semantics depend on the caller AIDriverCountSetup (0x004BFD90).
    // UNRESOLVED: The this+0x8 iterator is treated as a walk cursor; writing to it as a side effect may affect subsequent reads on the same list object.
}
