// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004331A0
// Canonical corpus name: DualLinkedListCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualLinkedListCleanup_004331a0.c

void UnknownObject::DualLinkedListCleanup()
{
    // Teardown routine for an object holding two linked lists. Flushes a global string buffer, then walks and frees every node of the first list (this+28): each active node's data block is default-initialized, its sub-allocations and the block itself freed, then the node freed. The second list (this+48) is walked and freed the same way. All list bookkeeping fields are zeroed on exit.
    // CALL: Call StringCopyWithBufferRealloc(&byte_5EA438) three times to flush/reset the global string buffer. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Zero the first-list count/state byte at this+24. [field:this:0x00000018, source:raw]
    // LOOP: Walk the first list from head this+28: for each node read the active flag at node+8 and the next pointer at node+4; stop when the next pointer is null. [field:this:0x0000001C, field:*(this+0x1C):0x00000008, field:*(*(this+0x1C)+0x0):0x00000008, field:*(*(this+0x1C)+0x4):0x00000004, source:raw]
    // GUARD: If the first-list node is active (node+8 flag), take its data block at node+0 and, when non-null, reinitialize it via SessionConfigDefaultInit. [field:*(this+0x1C):0x00000000, field:*(*(this+0x1C)+0x0):0x00000000, callee:0x00432CC0, source:raw]
    // CALL: Free the data block's owned sub-allocations (offset 0x14, offset 0x8, and the leading pointer) and then the data block itself with FreeWrapper_7bcf. [field:*(*(this+0x1C)+0x0):0x00000014, callee:0x00587BCF, source:raw]
    // CALL: Free the first-list node itself with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the first-list bookkeeping: head this+28, this+32, this+36, this+40 and the flags byte this+44. [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // LOOP: Walk the second list from head this+48: for each node read the active flag at node+8 and the next pointer at node+4; when the next pointer is null the loop ends. [field:this:0x00000030, field:*(this+0x30):0x00000008, field:*(*(this+0x30)+0x4):0x00000004, source:raw]
    // CALL: If the second-list node is active, free its data block (node+0) with FreeWrapper_7bcf, then free the node itself. [field:*(this+0x30):0x00000000, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the second-list bookkeeping: head this+48, this+52, this+56 and this+60. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // RETURN: Return 0. [function:0x004331A0, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   StringCopyWithBufferRealloc(&byte_5EA438);
    //   StringCopyWithBufferRealloc(&byte_5EA438);
    //   StringCopyWithBufferRealloc(&byte_5EA438);
    //   this->flags = 0;
    //   for (n = this->list1Head; n; n = n->next) {
    //     if (n->active) {
    //       d = n->data;
    //       if (d) {
    //         SessionConfigDefaultInit(d);
    //         if (d[5]) free(d[5]);
    //         if (d[2]) free(d[2]);
    //         if (*d)  free(*d);
    //         free(d);
    //       }
    //     }
    //     free(n);
    //   }
    //   this->list1Head = this->list1Tail = this->list1Extra = this->list1Extra2 = 0;
    //   this->list1Flags = 0;
    //   for (n = this->list2Head; n; n = n->next) {
    //     if (n->active) free(n->data);
    //     free(n);
    //   }
    //   this->list2Head = this->list2Tail = this->list2Extra = this->list2Extra2 = 0;
    //   return 0;
    // UNRESOLVED: Field names (count/state byte this+24, list head/tail/extra fields this+28..44 and this+48..60) are DERIVED from the decompilation; the packet only proves the offsets and their zeroing.
    // UNRESOLVED: The data-block sub-allocation offsets (0x14, 0x8, leading pointer) freed in the first list have no semantic names in the packet.
    // UNRESOLVED: Callers PhysicsShutdown (0x00431C70) and TextFileReader (0x004B09A0) confirm use as a teardown/cleanup routine.
}
