// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005456B0
// Canonical corpus name: sub_5456B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5456B0_005456b0.c

void UnknownObject::FindDrawableNodeByString()
{
    // Searches three category-linked node lists for a node whose name string (at node+88) equals a2, walking each list via a count field and head pointer and advancing through next-node pointers at node+0x6C. Returns the matching node pointer, or 0 when all three lists are exhausted without a match. Called by LinkedListWalkWithDispatch (0x005492B0).
    // ASSIGNMENT: Load the category-1 list counter this[71] (this+0x11C) and list head this[72] (this+0x120). [field:this:0x0000011C, field:this:0x00000120, source:raw]
    // LOOP: Walk category-1 list: while the counter is non-zero, strcmp a2 against the node name at node+88; on mismatch decrement the counter and advance to the next node via the next-node pointer at node+0x6C. [field:*(this+0x18C):0x0000006C, source:raw]
    // STATE_TRANSITION: When category-1 is exhausted (counter zero) without a match, fall through to category-2 using counter this[73] (this+0x124) and head this[74] (this+0x128). [field:this:0x00000124, field:this:0x00000128, source:raw]
    // LOOP: Walk category-2 list with the same strcmp/advance pattern, next-node pointer at node+0x6C. [field:*(this+0x194):0x0000006C, source:raw]
    // STATE_TRANSITION: When category-2 is exhausted without a match, fall through to category-3 using counter this[75] (this+0x12C) and head this[76] (this+0x130). [field:this:0x0000012C, field:this:0x00000130, source:raw]
    // LOOP: Walk category-3 list with the same strcmp/advance pattern, next-node pointer at node+0x6C; if its counter is zero, return 0. [field:*(this+0x19C):0x0000006C, source:raw]
    // RETURN: Return the matching node pointer v3 (matching name), or 0 when none of the three lists contains a node whose name equals a2. [source:raw]
    // CALL: Invoked by LinkedListWalkWithDispatch (0x005492B0). [caller:0x005492B0]

    // Conservative worker pseudocode:
    //   int sub_5456B0(_DWORD *self, const char *a2) {
    //     for (int list = 0; list < 3; ++list) {
    //       int count = self[71 + list * 2]; /* counters at this+0x11C/0x124/0x12C * /
    //       int node = self[72 + list * 2];  /* heads at this+0x120/0x128/0x130 * /
    //       while (count) {
    //         if (strcmp(a2, (const char *)(node + 88)) == 0) return node;
    //         --count;
    //         node = *(_DWORD *)(node + 108); /* next-node at node+0x6C * /
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The packet attributes the three next-node pointer fields to bases *(this+0x18C), *(this+0x194) and *(this+0x19C), while the raw source reaches the same pointers through node pointers loaded from this+0x120/0x128/0x130; the two base layouts are not reconciled.
    // UNRESOLVED: Node name-string offset (88 bytes) and next-node offset (108 bytes = 0x6C) are DERIVED from the linked-list walk pattern; the node struct type is unknown.
    // UNRESOLVED: The three lists (heads at this+0x120/0x128/0x130) correspond to categories 1/4/2 per existing analysis, but the mapping to a drawable-object category enum is not confirmed.
    // UNRESOLVED: The owning drawable-object manager class is unidentified; the legacy ABI name String_Dictionary_Lookup is retained only as a lead.
}
