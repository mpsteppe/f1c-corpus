// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004974A0
// Canonical corpus name: LinkedListSearchWithAction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListSearchWithAction_004974a0.c

void UnknownObject::LinkedListSearchWithAction()
{
    // Singly-linked-list traversal and dispatch. Copies the head pointer at this+0x4 into the current-node slot at this+0xC, then walks the list through each node's +4 next-pointer. If a node's first field matches key a2, performs a setter action chain (SimpleSetter_fc40(1), FieldGetter_8e30 on the node, then SetterVirtualCall on the fetched value). Always calls ShortComputation_7250(this, 1) at the end and returns 0.
    // ASSIGNMENT: Copy the list head pointer from this+0x4 into the current-node slot this+0xC. [field:this:0x00000004, field:this:0x0000000C]
    // GUARD: Guard: skip traversal when the head pointer at this+0x4 is null. [field:this:0x00000004]
    // GUARD: Guard: skip traversal when the head node's first field (the first item) is null. [field:*(this+0x4):0x00000000]
    // GUARD: Guard: the traversal loop only runs when the search key a2 is non-null. [source:raw]
    // LOOP: Traverse the list: from the current node, read the next pointer at current+0x4, store it back into this+0xC, and load the next node's first field as the item for the next iteration. [field:*(this+0xC):0x00000004, field:this:0x0000000C]
    // GUARD: In-loop guards: break when the current node at this+0xC is null or when the next node pointer read from current+0x4 is null; the item read from the next node (first field) must be non-null to continue. [field:*(*(this+0xC)+0x4):0x00000000, field:this:0x0000000C]
    // GUARD: Match check: when the current item equals the search key a2 the action chain runs. [source:raw]
    // CALL: On match, call SimpleSetter_fc40(1) to set a flag to 1. [callee:0x0054FC40]
    // CALL: On match, call FieldGetter_8e30(v4) to fetch a field from the matched node. [callee:0x00498E30]
    // CALL: On match, call SetterVirtualCall(v5) with the field value fetched from the matched node. [callee:0x00498F40]
    // CALL: After traversal (and on the early-skip paths), call ShortComputation_7250(this, 1). [callee:0x00497250]
    // RETURN: Always return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListSearchWithAction(void* this, void* key) {
    //     void* cur = *(void**)(this + 4);
    //     *(void**)(this + 0xC) = cur;
    //     if (cur) {
    //       void* item = *(void**)cur;
    //       if (item && key) {
    //         do {
    //           if (item == key) {
    //             SimpleSetter_fc40(1);
    //             SetterVirtualCall(FieldGetter_8e30(item));
    //           }
    //           cur = *(void**)(this + 0xC);
    //           if (!cur) break;
    //           void* next = *(void**)(cur + 4);
    //           *(void**)(this + 0xC) = next;
    //           if (!next) break;
    //           item = *(void**)next;
    //         } while (item);
    //       }
    //     }
    //     ShortComputation_7250(this, 1);
    //     return 0;
    //   }
    // UNRESOLVED: Owner class and the meaning of this+0x4 (list head) and this+0xC (current node cursor) are unknown; the cursor field is rewritten each call and does not persist across calls.
    // UNRESOLVED: Node layout: only the first field (item) and +4 (next pointer) are evidenced; other node fields are unproven.
    // UNRESOLVED: The 1 written by ShortComputation_7250 lands in a byte field whose exact offset is not evidenced in this packet (prior analysis suggests this+0x25, DERIVED).
    // UNRESOLVED: What SetterVirtualCall actually configures on the matched node depends on the caller's use of the list.
}
