// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547860
// Canonical corpus name: sub_547860
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_547860_00547860.c

void UnknownObject::AppendNodeToListTail()
{
    // Appends node a2 to the tail of a linked list rooted at this[10] (this+0x28). When the list is empty the head becomes a2; otherwise the list is walked forward via each node's next pointer at +0x5C and the new node is linked at the tail. In both paths a2's prev (+0x58) and next (+0x5C) links are initialized and the node count this[3] (this+0xC) is incremented. Returns the previous tail (or 0 on the empty-list path).
    // ASSIGNMENT: Load the list head from this[10] (this+0x28) and initialize the result to 0. [field:this:0x00000028]
    // GUARD: Guard on the head being non-null: non-empty list path walks to the tail and appends; else empty-list path installs a2 as head. [field:this:0x00000028, source:raw]
    // LOOP: Walk forward from the head through each node's next pointer at offset 0x5C until the last node is reached. [field:*(*(this+0x84)+0x5C):0x0000005C]
    // ASSIGNMENT: Link the found tail's next pointer (+0x5C) to the new node a2. [field:*(*(this+0x84)+0x5C):0x0000005C]
    // ASSIGNMENT: Initialize the new node a2: prev (+0x58) set to the old tail, next (+0x5C) cleared to 0. [source:raw]
    // ASSIGNMENT: Empty-list path: install a2 as the new head at this+0x28 and clear both its links (+0x58 and +0x5C). [field:this:0x00000028, source:raw]
    // CALCULATION: Increment the node count at this[3] (this+0xC) on every successful append. [field:this:0x0000000C]
    // RETURN: Return the previous tail node on the non-empty path, or 0 on the empty-list path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_547860(_DWORD *this, int node) {
    //     int head = this[10]; /* this+0x28 * /
    //     int result = 0;
    //     if (head) {
    //       int last = head;
    //       for (int i = *(int *)(head + 0x5C); i; i = *(int *)(i + 0x5C)) last = i;
    //       *(int *)(last + 0x5C) = node;
    //       *(int *)(node + 0x58) = last;
    //       *(int *)(node + 0x5C) = 0;
    //       ++this[3];
    //       result = last;
    //     } else {
    //       this[10] = node;
    //       *(int *)(node + 0x58) = 0;
    //       *(int *)(node + 0x5C) = 0;
    //       ++this[3];
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Container object type (this) and node type are unknown; the list is only walked forward so the backward link (+0x58) is not exercised here.
    // UNRESOLVED: field:this:0x00000084 (this[33], a list-metadata pointer) is not dereferenced in the raw source of this function; its relevance is unknown.
    // UNRESOLVED: The packet field base for the +0x5C next link is expressed as *(*(this+0x84)+0x5C); the raw source reaches it through the node chain, so the two views are not reconciled.
}
