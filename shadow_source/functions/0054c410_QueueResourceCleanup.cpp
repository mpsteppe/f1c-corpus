// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C410
// Canonical corpus name: QueueResourceCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QueueResourceCleanup_0054c410.c

void UnknownObject::QueueResourceCleanup()
{
    // Releases four kinds of queued resources during scene-graph teardown. (1) Iterates an array of 64-byte audio elements (count at this+0x118, base at this+0x11C), detaching each element's reference through sub_547710, zeroing the +4 slot and freeing the element via AudioResourceFree with the dword_8B78A0 sound-manager global. (2) Walks a linked list starting at this+0x13C, running ObjectDestructorWithArrayCleanup then FreeWrapper_7bcf per node. (3) Frees an array of 56-byte structures at this+0x110 (header at ptr-4 holds the count), calling EmptyStub_0170 per element and freeing the header with FreeWrapper_7bcf, then clears this+0x110. (4) If this+0x144 holds a single object pointer, calls EmptyStub_0170 and clears it. Returns 0.
    // CALL: Call ValueGetter(dword_8B8F28) to obtain the UI/context pointer used for per-resource cleanup. [callee:0x00545F40, global:0x008B8F28, source:raw]
    // GUARD: If this[70] (this+0x118, audio resource count) > 0, run the audio-element cleanup loop. [guard:0, field:this:0x00000118, source:raw]
    // LOOP: Iterate audioIndex 0..this[70]-1 over 64-byte elements at base this[71] (this+0x11C). [field:this:0x0000011C, source:raw]
    // CALL: sub_547710(uiContext, *(element + 4)): detach/clean the element's resource reference from the UI context. [callee:0x00547710, source:raw]
    // ASSIGNMENT: Zero the element's +4 slot: *(element + 4) = 0. [source:raw]
    // CALL: AudioResourceFree(dword_8B78A0, element): release the audio resource via the sound-manager global. [callee:0x00540CB0, global:0x008B78A0, source:raw]
    // LOOP: Walk the linked list whose head is this[79] (this+0x13C); each node's next pointer is at node+0x24 (v5[9]). [field:this:0x0000013C, source:raw]
    // CALL: For each list node: ObjectDestructorWithArrayCleanup(node) then FreeWrapper_7bcf(node). [callee:0x005511A0, callee:0x00587BCF, source:raw]
    // GUARD: If this[68] (this+0x110, 56-byte element array pointer) is nonzero, free the array. [field:this:0x00000110, source:raw]
    // CALCULATION: The array header at v7-4 holds the element count; the array spans v7 + 56 * count bytes. [source:raw]
    // LOOP: Walk the array backward 56 bytes per element, invoking EmptyStub_0170() once per element. [callee:0x004B0170, source:raw]
    // CALL: FreeWrapper_7bcf(header) releases the whole array allocation. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the array pointer: this[68] = 0 (this+0x110). [field:this:0x00000110, source:raw]
    // GUARD: If this[81] (this+0x144, single object pointer) is nonzero, clean it up. [field:this:0x00000144, source:raw]
    // CALL: EmptyStub_0170() placeholder call before clearing the single object pointer. [callee:0x004B0170, source:raw]
    // ASSIGNMENT: Clear the single object pointer: this[81] = 0 (this+0x144). [field:this:0x00000144, source:raw]
    // RETURN: Return 0 as the cleanup result. [source:raw]

    // Conservative worker pseudocode:
    //   ctx = ValueGetter(dword_8B8F28);
    //   if (this[70] > 0) {          /* audio count, this+0x118 * /
    //       for (i = 0; i < this[70]; i++) {
    //           elem = this[71] + i * 64;   /* this+0x11C * /
    //           sub_547710(ctx, *(elem + 4));
    //           *(elem + 4) = 0;
    //           AudioResourceFree(dword_8B78A0, elem);
    //       }
    //   }
    //   node = this[79];            /* linked list head, this+0x13C * /
    //   while (node) { nxt = node[9]; ObjectDestructorWithArrayCleanup(node); FreeWrapper_7bcf(node); node = nxt; }
    //   if (this[68]) {             /* 56-byte element array, this+0x110 * /
    //       header = this[68] - 4; count = *header;
    //       for (i = count; i > 0; i--) EmptyStub_0170();
    //       FreeWrapper_7bcf(header);
    //       this[68] = 0;
    //   }
    //   if (this[81]) { EmptyStub_0170(); this[81] = 0; }
    //   return 0;
    // UNRESOLVED: field:this:0x00000184 is listed in the field table as read-only but has no visible reference in the decompiled body; it cannot be attributed to an operation.
    // UNRESOLVED: Semantics of globals dword_8B78A0 (SoundManager) and dword_8B8F28 (UI root context) are DERIVED from existing analysis, not grounded in this packet.
    // UNRESOLVED: sub_547710's exact cleanup behavior, the 56-byte element layout, and the structure of the linked-list nodes are not described by the packet.
    // UNRESOLVED: EmptyStub_0170 is an empty placeholder; the real per-element cleanup intent is not evidenced.
    // UNRESOLVED: The single caller SceneGraph (0x0054A770) reaches this during scene-graph teardown, consistent with a queue/cleanup role, but no owner object is evidenced.
}
