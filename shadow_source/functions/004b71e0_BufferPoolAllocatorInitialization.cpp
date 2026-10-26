// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B71E0
// Canonical corpus name: BufferPoolAllocatorInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferPoolAllocatorInitialization_004b71e0.c

void UnknownObject::BufferPoolAllocatorInitialization()
{
    // Full reinitialization of a buffer-pool object: transfers the linked buffer, tears down and clears the file-stream node list (freeing node data and nodes), rebuilds a node-transferred list, selects a circular-buffer entry count from the enum at this+0x9A4 (0=16, 1=24, 2=32, 3=48, 4=96), allocates the buffer via the new/malloc wrapper, stores it at this+0x9B0, resets the write/read indices to -1, and zero-initializes every 44-byte entry.
    // CALL: LinkedBufferTransfer(this) transfers linked buffer data into the buffer-pool object. [callee:0x004B5F60, function:0x004B71E0, source:raw]
    // CALL: sub_4B5E50(this) runs the companion buffer-pool setup step on the object. [callee:0x004B5E50, source:raw]
    // LOOP: Walk the file-stream list whose head is *(this+0x6C0): each node reads its flag byte at node+0xC and next pointer at node+0x4; when the flag is set, free the node's data pointer (and the +0x4 field of that data when non-null) with FreeWrapper_7bcf, then free the node itself with FreeWrapper_7bcf. [field:*(this+0x6C0):0x00000000, field:*(this+0x6C0):0x0000000C, field:*(*(this+0x6C0)+0x0):0x00000004, field:*(*(this+0x6C0)+0x4):0x00000004, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the file-stream list fields at this+0x6C0, +0x6C4, +0x6C8, +0x6CC and the flag byte at this+0x6D0 to 0. [field:this:0x000006C0, field:this:0x000006C4, field:this:0x000006C8, field:this:0x000006CC, field:this:0x000006D0, source:raw]
    // CALL: ListRebuildWithNodeTransfer(this+3908) rebuilds the list at this+3908 with node transfer. [callee:0x004B52A0, source:raw]
    // ASSIGNMENT: Clear the rebuilt-list fields at this+3896 and this+3900 to 0. [field:this:0x00000F38, field:this:0x00000F3C, source:raw]
    // ASSIGNMENT: Set the circular-buffer write index this+0x9B8 and read index this+0x9BC to -1 (invalid). [field:this:0x000009B8, field:this:0x000009BC, source:raw]
    // ASSIGNMENT: Set the counter/flag field this+0xF8C to 5. [field:this:0x00000F8C, source:raw]
    // CALL: SpriteOverlayListCleanup(this) is invoked on the object (named call in the raw body; no callee record in the packet). [source:raw]
    // ASSIGNMENT: Select the circular-buffer entry count from the enum value read at this+0x9A4: 0 to 16, 1 to 24, 2 to 32, 3 to 48, 4 to 96, stored at this+0x9B4. [field:*(this+0x9A4):0x00000000, field:this:0x000009A4, field:this:0x000009B4, source:raw]
    // CALL: Allocate the pit-stall circular buffer via the new/malloc wrapper (176 * entry_count + 4 bytes). [source:raw]
    // ASSIGNMENT: Store the allocated circular-buffer pointer at this+0x9B0. [field:this:0x000009B0, source:raw]
    // LOOP: Zero-initialize each 44-byte sub-entry of the circular buffer (entry pointer advances by 44 bytes per iteration). [source:raw]

    // Conservative worker pseudocode:
    //   void BufferPoolAllocatorInitialization(void* this) {
    //     LinkedBufferTransfer(this);
    //     sub_4B5E50(this);
    //     while (node = *(void**)(this + 0x6C0)) {
    //       flag = *(char*)(node + 0xC);
    //       node = *(void**)(node + 0x4);
    //       if (flag && *(void**)node && ((void**)node)[1])
    //         FreeWrapper_7bcf(((void**)node)[1]);
    //       if (flag && node) FreeWrapper_7bcf(node);
    //       FreeWrapper_7bcf(node);
    //     }
    //     *(dword*)(this + 0x6C0) = 0; *(dword*)(this + 0x6C4) = 0;
    //     *(dword*)(this + 0x6C8) = 0; *(dword*)(this + 0x6CC) = 0;
    //     *(byte*)(this + 0x6D0) = 0;
    //     ListRebuildWithNodeTransfer(this + 3908);
    //     *(dword*)(this + 3896) = 0; *(dword*)(this + 3900) = 0;
    //     *(dword*)(this + 0x9B8) = -1; *(dword*)(this + 0x9BC) = -1;
    //     *(dword*)(this + 0xF8C) = 5;
    //     SpriteOverlayListCleanup(this);
    //     switch (*(dword*)(this + 0x9A4)) {
    //       case 0: capacity = 16; break;
    //       case 1: capacity = 24; break;
    //       case 2: capacity = 32; break;
    //       case 3: capacity = 48; break;
    //       case 4: capacity = 96; break;
    //     }
    //     *(dword*)(this + 0x9B4) = capacity;
    //     buffer = new[176 * capacity + 4];
    //     *(void**)(this + 0x9B0) = buffer;
    //     for (i = 0; i < capacity; i++)
    //       StructZeroInit_46b0(buffer + 1 + i * 44);
    //   }
    // UNRESOLVED: The owning class behind the buffer-pool object is unknown (owner UNKNOWN).
    // UNRESOLVED: The raw body is truncated; the tail of the allocation loop and the exact argument to StructZeroInit_46b0 are not fully visible.
    // UNRESOLVED: SpriteOverlayListCleanup, OperatorNewNhMallocWrapper and StructZeroInit_46b0 are named calls in the raw body without callee records in the packet, so their addresses are not established here.
    // UNRESOLVED: The meaning of the counter value 5 at this+0xF8C and the -1 index sentinels is not established.
}
