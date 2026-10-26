// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548A00
// Canonical corpus name: LinkedListFloatSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListFloatSearch_00548a00.c

void UnknownObject::findNodeByFloatValue()
{
    // Linked-list search by float key. Starts at the head pointer this[11] (offset 0x2C); returns 0 immediately if the list is empty. Walks nodes comparing the float field at node offset 0x8 against the search value a2, following next pointers at node offset 0x14. Returns the first node whose float matches a2, or 0 when the chain ends without a match.
    // ASSIGNMENT: v2 = this[11] (head pointer at offset 0x2C) [field:this:0x0000002C, source:raw]
    // GUARD: If the head pointer is null the list is empty; return 0 immediately [field:this:0x0000002C, source:raw]
    // LOOP: Walk the chain while the float value at node offset 0x8 differs from a2, moving to the next node via the pointer at node offset 0x14 [field:*(this+0x40):0x00000008, field:*(this+0x40):0x00000014, source:raw]
    // GUARD: When the next-node pointer at offset 0x14 is null the chain is exhausted; return 0 without a match [field:*(this+0x40):0x00000014, source:raw]
    // RETURN: Return the first node whose float at offset 0x8 equals a2, or 0 when no node matches [function:0x00548A00, source:raw]

    // Conservative worker pseudocode:
    //   v2 = this[0x2C / 4];
    //   if (!v2) return 0;
    //   while (*(float*)(v2 + 0x8) != a2) {
    //     v2 = *(v2 + 0x14);
    //     if (!v2) return 0;
    //   }
    //   return v2;
    // UNRESOLVED: The node base is framed by the deterministic extractor as *(this+0x40), while the raw source dereferences the node pointer directly; the node-to-container (this+0x40) relationship is not proven
    // UNRESOLVED: The semantic meaning of the float search key at node offset 0x8 is unknown without a caller-side contract; container owner is unknown
}
