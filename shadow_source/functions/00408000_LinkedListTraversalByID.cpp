// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408000
// Canonical corpus name: LinkedListTraversalByID
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListTraversalByID_00408000.c

void UnknownObject::LinkedListTraversalByID()
{
    // Traverses a singly linked list searching for a node whose data object's ID field at offset 0x5C equals a2. The head pointer is read from this+0x18 (this[6]) into the traversal cursor this+0x20 (this[8]); each node stores its next pointer at +4 and its data object at +0. On a match, calls sub_406A70 with the matched data object. Returns silently when a2 is -1, the list is empty, or the end is reached without a match.
    // GUARD: Returns immediately when the target ID a2 is -1 (no-search sentinel) [source:raw]
    // ASSIGNMENT: Reads the list head from this[6] (offset 0x18) into the traversal cursor field this[8] (offset 0x20) [field:this:0x00000018, field:this:0x00000020, source:raw]
    // GUARD: Proceeds only when the head pointer and its data object are both non-null; otherwise returns silently [source:raw]
    // LOOP: While the ID field at offset 0x5C of the current data object does not equal a2, advances the cursor to the next node via the next pointer at node+4 and re-reads its data object; returns when the cursor becomes null (end of list) [field:*(this+0x20):0x0000005C, field:this:0x00000020, source:raw]
    // CALL: Invokes sub_406A70 with the data object of the matched node [callee:0x00406A70, source:raw]
    // RETURN: Returns void; every path exits without a value [function:0x00408000, source:raw]

    // Conservative worker pseudocode:
    //   void LinkedListTraversalByID(void* this, int id) {
    //     if (id == -1) return;
    //     cursor = this->head;                    // this+0x18 into this+0x20
    //     this->cursor = cursor;
    //     if (cursor == 0) return;
    //     data = *cursor;                         // node+0
    //     if (data == 0) return;
    //     while (data[0x5C] != id) {
    //       cur = this->cursor;
    //       if (cur != 0) this->cursor = *(void**)((char*)cur + 4);
    //       cursor = this->cursor;
    //       if (cursor != 0) { data = *cursor; continue; }
    //       return;
    //     }
    //     sub_406A70(data);
    //   }
    // UNRESOLVED: Field this+0x24 appears in the packet evidence but is not read by the raw source text; its role (node count per the analysis fill) is not evidenced here
    // UNRESOLVED: sub_406A70's semantics on the matched data object are defined outside this packet
    // UNRESOLVED: The node data layout (data object at node+0, next pointer at node+4) is implied by the traversal arithmetic but not independently confirmed
}
