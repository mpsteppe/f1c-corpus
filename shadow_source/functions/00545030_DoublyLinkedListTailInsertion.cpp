// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545030
// Canonical corpus name: DoublyLinkedListTailInsertion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListTailInsertion_00545030.c

void UnknownObject::DoublyLinkedListTailInsertion()
{
    // Inserts node a2 at the tail of a doubly linked list. Reads the list head stored at this[62] (offset 0xF8); when the head is non-null it walks next pointers at +440 to the last node and links a2 in as the new tail (previous at +436, next at +440). When the head is null it makes a2 the new head. Returns the node that became the tail (or the new head on the empty-list path).
    // ASSIGNMENT: Load the list head pointer from dword index 62 (offset 0xF8) of this into the traversal cursor. [field:this:0x000000F8, source:raw]
    // GUARD: If the loaded head is non-null, enter the traversal-and-append path; otherwise take the empty-list branch that makes a2 the head. [field:this:0x000000F8, source:raw]
    // LOOP: Walk from the starting node referenced via this[172] (offset 0x2B0), following next pointers at +440 until the node whose next pointer is zero is reached, keeping that node as the tail. [field:this:0x000002B0, source:raw]
    // ASSIGNMENT: Write the new node a2 into the tail node's next pointer at +440. [field:*(*(this+0x2B0)+0x1B8):0x000001B8, source:raw]
    // ASSIGNMENT: Write the previous tail node into a2's previous pointer at +436. [source:raw]
    // ASSIGNMENT: Clear a2's next pointer at +440 to zero so it terminates the list. [source:raw]
    // STATE_TRANSITION: On the empty-list path, promote a2 to be the new list head stored at this[62] (offset 0xF8). [field:this:0x000000F8, source:raw]
    // ASSIGNMENT: On the empty-list path, clear a2's previous pointer at +436 to zero. [source:raw]
    // ASSIGNMENT: On the empty-list path, clear a2's next pointer at +440 to zero. [source:raw]
    // RETURN: Return the node that now terminates the list: the appended tail on the full-list path, or a2 on the empty-list path. [source:raw]

    // Conservative worker pseudocode:
    //   int DoublyLinkedListTailInsertion(int* this, int a2) {
    //     int result = this[62];
    //     if (result) {
    //       for (int i = *(int*)(result + 440); i; i = *(int*)(i + 440))
    //         result = i;
    //       *(int*)(result + 440) = a2;
    //       *(int*)(a2 + 436) = result;
    //       *(int*)(a2 + 440) = 0;
    //     } else {
    //       result = a2;
    //       this[62] = a2;
    //       *(int*)(a2 + 436) = 0;
    //       *(int*)(a2 + 440) = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The concrete owning class of this and of the linked nodes is unknown; the packet provides no owner evidence.
    // UNRESOLVED: The interpretation of +436/+440 as previous/next node pointers and of this[62] (offset 0xF8) as the list head comes from the linked-list structure of the raw code and from existing analysis (DERIVED), not from a proven field contract.
    // UNRESOLVED: Field base *(*(this+0x2B0)+0x1B8) renders the same tail next-pointer write as the raw +440 access; the two views were not independently corroborated against a struct definition.
}
