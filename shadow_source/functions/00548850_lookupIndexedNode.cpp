// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548850
// Canonical corpus name: sub_548850
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_548850_00548850.c

void UnknownObject::lookupIndexedNode()
{
    // Indexed linked-list node lookup. Returns the node at zero-based index a2 by walking the chain that starts at the head pointer stored in this[9] (offset 0x24), counting entries from 0. Returns 0 immediately when a2 >= the element count this[4] (offset 0x10), or when the chain is exhausted (next pointer at node offset 0xC0 becomes 0) before reaching index a2.
    // GUARD: If a2 >= this[4] (element count at offset 0x10), the requested index is out of range; return 0 without touching the list [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Initialize v2 = 0 and result = this[9] (head pointer at offset 0x24) [field:this:0x00000024, source:raw]
    // LOOP: Iterate while result is non-null, incrementing v2 each pass; break as soon as v2 equals the requested index a2 [source:raw, function:0x00548850]
    // ASSIGNMENT: Advance result to the next node pointer stored at node offset 0xC0 when the current node is not yet at index a2 [field:*(this+0xE4):0x000000C0, source:raw]
    // RETURN: Return the node reached at index a2, or 0 when the index is out of range or the chain ends before the index is reached [function:0x00548850, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 >= this[4]) return 0;
    //   result = this[9];
    //   for (v2 = 0; result; ++v2) {
    //     if (v2 == a2) break;
    //     result = *(result + 0xC0);
    //   }
    //   return result;
    // UNRESOLVED: The next-node pointer at node offset 0xC0 is framed by the deterministic extractor as a field of *(this+0xE4), while the raw source reads result+192 directly from the node pointer; the node-to-container (this+0xE4) relationship is therefore not proven
    // UNRESOLVED: List container owner and node type are unknown; no call or data evidence identifies the enclosing class
}
