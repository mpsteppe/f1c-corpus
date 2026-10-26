// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00496750
// Canonical corpus name: DoublyLinkedListAppend_6750
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListAppend_6750_00496750.c

void UnknownObject::DoublyLinkedListAppendWithFlag()
{
    // Appends a value node a2 to a doubly-linked list rooted at this: allocates a 16-byte node (value, next, prev, byte flag) via OperatorNewNhMallocWrapper, links it after the tail (this+0x18C0), or initializes head (this+0x18BC) and secondary pointer (this+0x18C4) on first insertion, updates tail, increments the count at this+0x18C8. When a3 is non-zero, sets the byte flag at this+0x24 to 1. Returns a3. Called by GameObjectUpdateFrame (004661B0) and DirectoryChangeHandler (0048E6B0).
    // GUARD: Skip the entire append when a2 is zero; fall through to flag handling and return a3 [source:raw]
    // CALL: Allocate a 16-byte list node via OperatorNewNhMallocWrapper [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the new node: value slot (v4) = a2, next (v4+4) = 0, prev (v4+8) = 0, byte (v4+12) = 0; v4 is set to 0 when allocation returns null [source:raw]
    // GUARD: Branch on whether the list head this+0x18BC is already non-null [field:this:0x000018BC, source:raw]
    // ASSIGNMENT: Append to non-empty list: old tail's next (*(this+0x18C0)+4) = v4 and new node's prev (v4+8) = old tail (this+0x18C0) [field:*(this+0x18C0):0x00000004, field:this:0x000018C0, source:raw]
    // ASSIGNMENT: First insertion branch: head this+0x18BC = v4 and secondary pointer this+0x18C4 = v4 [field:this:0x000018BC, field:this:0x000018C4, source:raw]
    // ASSIGNMENT: Update tail this+0x18C0 = v4 and increment the node count this+0x18C8 [field:this:0x000018C0, field:this:0x000018C8, source:raw]
    // STATE_TRANSITION: When a3 is non-zero, set the byte flag at this+0x24 to 1 (literal 1) [field:this:0x00000024, source:raw]
    // RETURN: Return a3 as the function result [function:0x00496750, source:raw]
    // CALL: Invoked by GameObjectUpdateFrame (004661B0) and DirectoryChangeHandler (0048E6B0) [caller:0x004661B0, caller:0x0048E6B0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2) {
    //     v4 = OperatorNewNhMallocWrapper(16);
    //     if (v4) { v4[0] = a2; v4[1] = 0; v4[2] = 0; *((BYTE*)v4 + 12) = 0; } else v4 = 0;
    //     if (*(this + 0x18BC)) {
    //       *(*(this + 0x18C0) + 4) = v4;
    //       *(v4 + 8) = *(this + 0x18C0);
    //     } else {
    //       *(this + 0x18BC) = v4;
    //       *(this + 0x18C4) = v4;
    //     }
    //     *(this + 0x18C0) = v4;
    //     ++*(this + 0x18C8);
    //   }
    //   result = a3;
    //   if (a3) *((BYTE*)this + 0x24) = 1;
    //   return result;
    // UNRESOLVED: The exact role of this+0x18C4 (secondary pointer, possibly a read cursor) is inferred from the append pattern and is not proven by packet facts
    // UNRESOLVED: The 16-byte node layout (value, next, prev, byte) and the meaning of the byte at node+12 are inferred from the initialization literals only
}
