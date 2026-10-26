// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BACF0
// Canonical corpus name: LinkedListNodeRemoval_acf0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeRemoval_acf0_004bacf0.c

void UnknownObject::LinkedListNodeRemoval()
{
    // Removes the head node from a singly-linked list and returns the node's data pointer. Sets the list iterator/current pointer (this+0x8) to the old head, walks the list to the first node whose data equals the head's data, unlinks it (fixing head, tail and current pointers), decrements the node count (this+0xC), clears the node byte flag (obj+0x8) so the data is not freed by the caller-visible path, frees the node (and its data only if the flag is set) via FreeWrapper_7bcf, and returns the removed data pointer. Called by CollisionObjectInsertion (004B48E0) and ModelSceneFileLoader (004B6C90).
    // ASSIGNMENT: Set the list current/iterator pointer (this+0x8) to the old head before removal [field:this:0x00000008, source:raw]
    // GUARD: Empty-list guard: when the head pointer (this+0x0) is null, return null immediately [guard:1, field:this:0x00000000]
    // ASSIGNMENT: Capture the head node's data pointer (obj+0x0) and clear the node byte flag (obj+0x8) to zero so the node's data is not freed later [field:obj:0x00000000, field:obj:0x00000008, source:raw]
    // GUARD: Null-data guard: when the head node's data pointer (obj+0x0) is null, return null without unlinking [guard:0, field:obj:0x00000000]
    // LOOP: Walk the list from the head following the next pointer (obj+0x4) until a node whose data equals the removed data is found; if the walk exhausts the list, return null [field:obj:0x00000004, source:raw]
    // ASSIGNMENT: If the matched node equals the list current/iterator pointer (this+0x8), advance it to the matched node's next pointer [field:this:0x00000008, field:obj:0x00000004]
    // ASSIGNMENT: Unlink the matched node: set the predecessor's next pointer (obj+0x4) to the matched node's next, or if there is no predecessor, set the list head (this+0x0) to the next node [field:this:0x00000000, field:obj:0x00000004]
    // ASSIGNMENT: If the matched node is the tail, set the list tail pointer (this+0x4) to the predecessor node [field:this:0x00000004]
    // ASSIGNMENT: Decrement the list node count (this+0xC) by one [field:this:0x0000000C]
    // CALL: FreeWrapper_7bcf frees the node's data when the node byte flag (obj+0x8) is still set, then always frees the node itself [callee:0x00587BCF, field:obj:0x00000008]
    // RETURN: Return the removed node's data pointer (obj+0x0) [function:0x004BACF0, field:obj:0x00000000]
    // CALL: Invoked by CollisionObjectInsertion (004B48E0) and ModelSceneFileLoader (004B6C90) to pop list entries [caller:0x004B48E0, caller:0x004B6C90]

    // Conservative worker pseudocode:
    //   result = 0;
    //   this[2] = *this;
    //   if (*this == 0) return 0;
    //   v1 = *this; v4 = *v1;
    //   *((_BYTE*)v1 + 8) = 0;
    //   if (v4 == 0) return 0;
    //   v5 = *this;
    //   while (*v5 != v4) {
    //     result = v5;
    //     v5 = v5[1];
    //     if (!v5) return 0;
    //   }
    //   if (v5 == this[2]) this[2] = v5[1];
    //   v6 = v5[1];
    //   if (result) result[1] = v6; else *this = v6;
    //   if (this[1] == v5) this[1] = result;
    //   this[3] = this[3] - 1;
    //   if (*((_BYTE*)v5 + 8)) FreeWrapper_7bcf(v5[0]);
    //   FreeWrapper_7bcf(v5);
    //   return v4;
    // UNRESOLVED: Node field obj+0xC is flagged as read by packet facts but never appears in the decompiled logic; its role is not verifiable here
    // UNRESOLVED: The exact object type of the list is unknown; the packet models the owner as UnknownObject
}
