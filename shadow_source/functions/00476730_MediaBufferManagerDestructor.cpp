// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476730
// Canonical corpus name: MediaBufferManagerDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MediaBufferManagerDestructor_00476730.c

void UnknownObject::MediaBufferManagerDestructor()
{
    // Destructor for a media buffer manager. Frees the main media buffer at this+0x188 when present, resets the vtable pointer to off_5A4550, walks a linked list of buffer-reference nodes rooted at this+0xF0 (each node freed, its child object conditionally destroyed through the node's own vtable), zeroes the list state fields this+0xF0..+0xFC, invokes the base destructor sub_485EB0, and frees self when bit 0 of the destruction flag a2 is set.
    // GUARD: The main media buffer pointer at this+0x188 (this[98]) is only freed when it is non-zero [field:this:0x00000188, source:raw]
    // CALL: FreeWrapper_7bcf releases the main media buffer pointed at by this+0x188 [callee:0x00587BCF, field:this:0x00000188, source:raw]
    // ASSIGNMENT: Vtable reset: the object's first dword (this+0x0) is set to the off_5A4550 vtable pointer [field:this:0x00000000, global:0x005A4550, source:raw]
    // LOOP: Linked-list walk starting at the head stored in this+0xF0 (this[60]); each node contributes its value pointer at node[0], a byte flag at node+12 and the next node at node[1]. The walk terminates when the this+0xFC (this[63]) sentinel reads 0 (deterministic packet guard) [field:*(this+0xF0):0x00000000, field:*(*(this+0xF0)+0x0):0x00000000, field:this:0x000000F0, field:this:0x000000FC, guard:0, source:raw]
    // CALL: Conditional child destroy: when the node byte flag at node+12 is non-zero and the node's value pointer at node[0] is present, the value object's vtable method is called with argument 1 (delete-style) through node[0] [field:*(*(this+0xF0)+0x0):0x00000000, source:raw]
    // CALL: FreeWrapper_7bcf releases each list node after its child (if any) has been destroyed [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list state block: this+0xF0, +0xF4, +0xF8 and +0xFC are all set to 0 after the walk completes [field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, source:raw]
    // CALL: sub_485EB0 is invoked as the base-class destructor / additional cleanup on this object [callee:0x00485EB0, source:raw]
    // RETURN: When bit 0 of a2 is set the object itself is freed via FreeWrapper_7bcf; the destructor otherwise returns this unchanged [callee:0x00587BCF, source:raw]

    // Conservative worker pseudocode:
    //   if (this[98]) FreeWrapper_7bcf(this[98]);
    //   this[0] = &off_5A4550;
    //   node = this[60];
    //   while (node) {
    //     next = node[1];
    //     flag = *((byte*)node + 12) == 0;
    //     if (!flag && node[0]) node[0]->vtable(node[0], 1);
    //     FreeWrapper_7bcf(node);
    //     node = next;
    //   }
    //   this[60] = this[61] = this[62] = this[63] = 0;
    //   sub_485EB0(this);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The deterministic guard records the this+0xFC == 0 test as the walk guard, while the raw source keys the loop on the head pointer this+0xF0; the exact role of the sentinel versus the head pointer in loop termination is not fully resolvable from this packet
    // UNRESOLVED: The child-destroy virtual call reaches node[0]'s vtable slot with argument 1, but the callee address is not resolvable from this packet
    // UNRESOLVED: The list node layout (next pointer at node[1], byte flag at node+12, value pointer at node[0]) is only partially evidenced here
}
