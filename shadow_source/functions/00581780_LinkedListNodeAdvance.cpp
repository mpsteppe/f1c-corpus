// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581780
// Canonical corpus name: LinkedListNodeAdvance
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeAdvance_00581780.c

void UnknownObject::LinkedListNodeAdvance()
{
    // Advances a linked-list iteration cursor stored at this+0x8. Reads the current node pointer; when non-null, advances it to the next node through the link field at node+0x4 (evidence field:this:0xC). Reloads the cursor; when non-null returns the node's data value at node+0, otherwise returns 0. Null-safe at both stages so a full traversal ends cleanly.
    // ASSIGNMENT: Load the current node pointer from this+0x8 into a local. [field:this:0x00000008]
    // GUARD: If the current node is non-null, advance the cursor through the node link field. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Advance the cursor: this+0x8 = next-node pointer read through the link field at node+0x4 (this+0xC in the evidence model). [field:this:0x00000008, field:this:0x0000000C]
    // GUARD: Reload the cursor into a local; if null, the list is exhausted and the function returns 0. [source:raw]
    // RETURN: Return the data value at node+0 when the new current node is non-null, else return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall LinkedListNodeAdvance(void* this) {
    //     void* node = this->current;
    //     if (node) this->current = node->next;
    //     node = this->current;
    //     return node ? node->data : 0;
    //   }
    // UNRESOLVED: Node payload type and link-field layout are caller-defined; callers sub_490D00, CollisionBroadphaseBuilder and NetworkConnectionListDuplication drive the iteration.
    // UNRESOLVED: Semantics of the node+0 data value (pointer, id, or count) are not determinable from this function alone.
    // UNRESOLVED: The this+0xC field is written by this function's own cursor advance, not read from this itself; the exact mapping to node+0x4 rests on the analyzer's evidence model.
}
