// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486540
// Canonical corpus name: LinkedListAppend_6540
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListAppend_6540_00486540.c

void UnknownObject::LinkedListAppend_6540()
{
    // Appends node a2 to the tail of a linked list whose head pointer is at this+0xD8. If the head is null the list is empty and a2 becomes the new head; otherwise the walk advances through each node's next pointer at +0x18 until a null next pointer is found (the tail) and sets that tail's next pointer to a2. Void function; called by sub_493480.
    // ASSIGNMENT: Load the list head v2 = this[54] (head pointer at this+0xD8). [field:this:0x000000D8, source:raw]
    // GUARD: If the head at this+0xD8 is non-null, walk to the tail and link a2 onto it; otherwise the list is empty and a2 becomes the new head directly. [field:this:0x000000D8, source:raw]
    // LOOP: Walk the list starting from the head's next pointer at +0x18, advancing v2 through each node's next pointer at +0x18 until a null next pointer is reached. [field:*(*(this+0xF0)+0x18):0x00000018, source:raw]
    // ASSIGNMENT: Append a2 as the new tail: set the tail node's next pointer at +0x18 to a2 (the next-pointer slot is reached through the indirect base at this+0xF0). [field:*(*(this+0xF0)+0x18):0x00000018, field:this:0x000000F0, source:raw]
    // ASSIGNMENT: Empty-list path: set the head at this+0xD8 to a2. [field:this:0x000000D8, source:raw]
    // RETURN: Void function; returns nothing after either append path. [function:0x00486540, source:raw]

    // Conservative worker pseudocode:
    //   void LinkedListAppend_6540(void **this, void *a2) {
    //       void *tail = this[54];
    //       if (tail) {
    //           for (void *next = *(void **)(tail + 24); next; next = *(void **)(next + 24))
    //               tail = next;
    //           *(void **)(tail + 24) = a2;
    //       } else {
    //           this[54] = a2;
    //       }
    //   }
    // UNRESOLVED: The exact role of this+0xF0 as the indirect base for the tail next-pointer write is not visible in the raw source, which addresses the tail node directly via v2; the identity of that base field is unevidenced.
    // UNRESOLVED: The node type (next pointer at +0x18), the list owner class, and the relationship (if any) to any sibling list on the same owner object are unevidenced.
}
