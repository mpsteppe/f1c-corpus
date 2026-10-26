// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047F180
// Canonical corpus name: DoublyLinkedListAppend_f180
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListAppend_f180_0047f180.c

void UnknownObject::DoublyLinkedListAppend_f180()
{
    // Appends a value to a doubly linked list whose head is this[0], tail this[1], and count this[3]. When the data argument a2 is non-null it allocates a 16-byte node with OperatorNewNhMallocWrapper, stores a2 as the payload and a3 as a byte flag, links the node onto the tail (or into the empty-list fields this[0]/this[2] when the list was empty), updates the tail to the new node, increments the count, and returns 1; when a2 is null it returns 0 without modifying the list. Structural twin of DoublyLinkedListAppend.
    // GUARD: Proceed with append only when the data argument a2 is non-null; otherwise return the initial result value 0. [source:raw]
    // CALL: Allocate a 16-byte list node with OperatorNewNhMallocWrapper(16); on failure v5 is set to 0. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the new node when allocation succeeded: node+0 = a2 (payload), node+4 = 0, node+8 = 0, node+12 = a3 (byte flag). [source:raw]
    // GUARD: Branch on whether the list head *this is non-null (list non-empty vs empty). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Non-empty path: link the old tail this[1] forward to the new node (old tail node+4 = v5) and the new node back to the old tail (v5+8 = this[1]). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Empty-list path: set head *this = v5 and this[2] = v5. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Update the tail pointer this[1] = v5 to the new node. [field:this:0x00000004, source:raw]
    // CALCULATION: Increment the element count at this[3] (byte offset 0x0C). [field:this:0x0000000C, source:raw]
    // RETURN: Return 1 when the append succeeded and a2 was non-null; return the initial 0 result when a2 was null. [source:raw]

    // Conservative worker pseudocode:
    //   char DoublyLinkedListAppend_f180(void** this, void* a2, char a3) {
    //       if (!a2) return 0;
    //       void* node = OperatorNewNhMallocWrapper(16);
    //       if (node) {
    //           node[0] = a2; ((char**)node)[2] = 0; ((char**)node)[4] = 0; ((char*)node)[12] = a3;
    //       } else {
    //           node = 0;
    //       }
    //       if (this[0]) {
    //           *((char**)this[1] + 4) = node; ((char**)node)[8] = this[1];
    //       } else {
    //           this[0] = node; this[2] = node;
    //       }
    //       this[1] = node;
    //       this[3]++;
    //       return 1;
    //   }
    // UNRESOLVED: Semantics of the extra this[2] field (set to the node on the empty-list path) beyond storing a duplicate reference is unknown.
    // UNRESOLVED: Meaning of the node byte flag a3 stored at node+12 is unknown.
    // UNRESOLVED: Owner object type is unknown; the list header layout (head/tail/extra/count) is inferred from field access patterns.
}
