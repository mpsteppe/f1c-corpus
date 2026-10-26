// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581940
// Canonical corpus name: sub_581940
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_581940_00581940.c

void UnknownObject::RemoveNodeByIdentifier()
{
    // Linked-list node removal by identifier. Searches the container's node chain for a node whose data pointer equals a2, unlinks it, and fixes up head (this+0), tail (this+4) and cursor (this+8) pointers when the removed node is one of them. Decrements the element count (this+0xC). Optionally clears the node's release flag (node+8) when a3 is zero; when the release flag is set, calls the data object's vtable method at offset +4 with a refcount of 1, then frees the node wrapper via FreeWrapper_7bcf. Returns 1 when removed, 0 when not found or a2 is null.
    // GUARD: Guard on a2 being non-null; returns 0 when the identifier is null. [source:raw]
    // ASSIGNMENT: Start traversal at the head node stored at this+0; result initialised to 0. [field:this:0x00000000, source:raw]
    // LOOP: Walk the next-link chain reading node+4; stop when a node's data pointer at node+0 equals a2 or the chain ends. [field:*(obj+0x4):0x00000000, field:obj:0x00000004, field:*(*(obj+0x4)+0x0):0x00000004, source:raw]
    // GUARD: When traversal reaches a null next link the node is not present; return 0. [field:obj:0x00000004, source:raw]
    // ASSIGNMENT: When the removed node is the cursor stored at this+8, advance the cursor to the removed node's next link. [field:this:0x00000008, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Unlink the node: predecessor's next link (or head this+0 when no predecessor) is set to the removed node's next link. [field:this:0x00000000, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: When the removed node is the tail stored at this+4, set the tail to the predecessor. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Decrement the element count at this+0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: When a3 is zero, clear the release flag byte at node+8. [field:obj:0x00000008, source:raw]
    // GUARD: Guard on the release flag byte at node+8; when set and the data pointer at node+0 is non-null, invoke the data object's vtable method at offset +4 passing refcount 1. [field:obj:0x00000008, field:*(obj+0x4):0x00000000, source:raw]
    // CALL: Free the node wrapper through FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Zero the removed node's metadata dword at node+0xC during removal handling. [field:obj:0x0000000C, source:raw]
    // RETURN: Return 1 after a successful removal, 0 when a2 is null or the node is absent. [source:raw]

    // Conservative worker pseudocode:
    //   char RemoveNodeByIdentifier(_DWORD* this, int a2, char a3) {
    //     if (!a2) return 0;
    //     node = this[0]; prev = 0;
    //     while (node) {
    //       if (node[0] == a2) break;
    //       prev = node; node = node[1];
    //     }
    //     if (!node) return 0;
    //     if (node == this[2]) this[2] = node[1];
    //     next = node[1];
    //     if (prev) prev[1] = next; else this[0] = next;
    //     if (this[1] == node) this[1] = prev;
    //     --this[3];
    //     if (!a3) ((_BYTE*)node)[8] = 0;
    //     if (((_BYTE*)node)[8] && node[0])
    //       (*(void (__thiscall **)(_DWORD, int))(*(_DWORD*)node[0] + 4))(node[0], 1);
    //     FreeWrapper_7bcf(node);
    //     return 1;
    //   }
    // UNRESOLVED: The vtable method invoked at data+4 with refcount 1 is a destructor/release routine whose identity is not evidenced here.
    // UNRESOLVED: The byte flag at node+8 and the metadata dword at node+0xC have no evidenced semantic beyond this function's usage.
    // UNRESOLVED: The meaning of the identifier a2 (node data pointer) depends on how nodes are inserted by other functions.
}
