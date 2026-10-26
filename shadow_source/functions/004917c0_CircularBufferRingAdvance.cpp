// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004917C0
// Canonical corpus name: CircularBufferRingAdvance
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CircularBufferRingAdvance_004917c0.c

void UnknownObject::CircularBufferRingAdvance()
{
    // Advances a circular buffer index (modulo capacity) when the race-phase condition permits, destroys two embedded list iterators, then walks the ring slot at the current index: increments each node's age counter (max 3), and for aged-out nodes unlinks, frees (value and node) and prepends them into an external list. Always returns 1.
    // GUARD: If sub_4F9B20(&unk_8AFE18) returns non-zero, advance the ring index: header[4] = (header[4] + 1) % header[0], where header is the struct behind this pointer. [callee:0x004F9B20, global:0x008AFE18, field:this:0x00000000, source:raw]
    // CALL: Destroy the two embedded list iterators at header + 28 and header + 44 via ListIteratorFullDestruction. [callee:0x004910D0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Select the ring slot for the current index: slot = buffer_base + 16 * index, and start the walk from the slot's head pointer (slot[2] = first node). [field:this:0x00000000, source:raw]
    // LOOP: Walk the linked list of nodes at the current slot. For each node read the age counter at node + 8: if below 3, increment it and advance to the next node; otherwise evict the node. [field:obj:0x00000008, source:raw]
    // ASSIGNMENT: Unlink an evicted node from the slot list by relinking the previous node's next pointer (or the slot head when first) and fixing the tail pointer and count. [field:obj:0x00000000, field:obj:0x00000004, source:raw]
    // GUARD: If the evicted node's flag byte at +8 is set and its value pointer (node + 0) is non-null, free the value via FreeWrapper_7bcf; then free the node itself. [field:obj:0x00000008, field:obj:0x00000000, callee:0x00587BCF, source:raw]
    // CALL: Prepend the evicted node into an external list via LinkedListNodePrepend and continue the walk. [callee:0x00490AA0, source:raw]
    // RETURN: Return 1 regardless of whether any node was evicted. [source:raw]

    // Conservative worker pseudocode:
    //   char CircularBufferRingAdvance(int *this) {
    //     int *hdr = *this;
    //     if (sub_4F9B20(&unk_8AFE18)) hdr[1] = (hdr[1] + 1) % hdr[0];
    //     ListIteratorFullDestruction(*this + 28);
    //     ListIteratorFullDestruction(*this + 44);
    //     int *slot = (int*)(hdr[2] + 16 * hdr[1]);
    //     Node *cur = (Node*)slot[2];
    //     while (cur) {
    //       if (cur->age < 3) { cur->age++; cur = cur->next; }
    //       else { unlink_node(slot, cur); if (cur->flags && cur->value) FreeWrapper_7bcf(cur->value); FreeWrapper_7bcf(cur); LinkedListNodePrepend(cur); cur = (Node*)slot[2]; }
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: The external list that receives evicted nodes via LinkedListNodePrepend is not resolvable from this function alone.
    // UNRESOLVED: The slot layout at buffer_base + 16 * index (head/tail/current/count words) is inferred from pointer arithmetic; only the outer header field (field:this:0x00000000) has direct packet evidence.
    // UNRESOLVED: The exact trigger condition checked by sub_4F9B20 (race-phase timer) is DERIVED from the caller's context, not confirmed here.
}
