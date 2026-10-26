// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004963D0
// Canonical corpus name: sub_4963D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4963D0_004963d0.c

void UnknownObject::GlobalResourceManagerShutdown()
{
    // Global resource manager shutdown. Walks four linked lists of managed objects, invoking each node's virtual destructor (with flag 1) and freeing the node; zeroes the list heads this[1..4] and this[7]; walks a third list invoking a release thunk on node data and zeroing it; walks a fourth list resetting objects via vtable dispatch; frees collision geometry; releases this[43] and this[44] resources; cleans up cursor resources; then walks the MAS audio list closing each MAS handle and zeroing the node data. Returns 0.
    // CALL: Call EmptyStub_0170(this) first. [callee:0x004B0170]
    // LOOP: Walk the first list headed at this[1], following next pointers at node +4; for each node, when the flag byte at node +12 is set and the node head is non-null, invoke the node's virtual destructor through the vtable pointer, then free the node via FreeWrapper_7bcf. [field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(this+0x8):0x00000004, field:*(*(this+0x4)+0x0):0x00000000, callee:0x00587BCF]
    // ASSIGNMENT: Zero the four list-head fields this[1], this[2], this[3] and this[4]. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010]
    // LOOP: Walk the second list headed at this[7], following next pointers at node +140; for each node invoke its virtual destructor through the vtable pointer with flag 1. [field:this:0x0000001C, field:*(this+0x1C):0x00000000, field:*(this+0xA8):0x0000008C]
    // ASSIGNMENT: Zero the second-list head this[7] after the walk. [field:this:0x0000001C]
    // LOOP: Walk the third list headed at this[65], following next pointers at node +16; for each node call ThunkToFUN0053cb90 on the data at node +12, zero that data field, call ShortComputation_4370 on node +4, then free the node. [field:this:0x00000104, field:*(this+0x114):0x00000010, callee:0x00494FD0, callee:0x00414370, callee:0x00587BCF]
    // LOOP: Walk the fourth list headed at this[67], following next pointers at node offset 84 (node[21]); for each node call ObjectResetWithVTableDispatch then free it. [field:this:0x0000010C, callee:0x00499AF0, callee:0x00587BCF]
    // CALL: Call CollisionGeometryFreeList() to release collision geometry. [callee:0x00494E60]
    // GUARD: When this[43] is non-null, call ThunkToFUN0053cb90(this[43]) and zero the field. [field:this:0x000000AC, callee:0x00494FD0]
    // GUARD: When this[44] is non-null, call ThunkToFUN0053cb90(this[44]) and zero the field. [field:this:0x000000B0, callee:0x00494FD0]
    // CALL: Call CursorResourceCleanup(dword_7CB24C) to release cursor resources. [callee:0x0044F5F0, global:0x007CB24C]
    // ASSIGNMENT: Copy this[60] into this[62] as the MAS list iterator start. [field:this:0x000000F0, field:this:0x000000F8]
    // LOOP: Walk the MAS audio list: for each node call MASCloseWrapper on the data at node +8, zero that data field, and advance through this[62] via next pointers at node +4 until the list ends. [callee:0x00495010, field:*(this+0xF0):0x00000008, field:this:0x000000F8, field:*(this+0xFC):0x00000000]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4963D0(_DWORD *this) {
    //     EmptyStub_0170(this);
    //     for (node = this[1]; node; ) {
    //       next = *(int*)(node + 4);
    //       if (*(char*)(node + 12) && *(_DWORD*)node) (*(void (__thiscall**)(_DWORD,int))*node)(node, 1);
    //       FreeWrapper_7bcf(node);
    //       node = next;
    //     }
    //     this[1] = this[2] = this[3] = this[4] = 0;
    //     for (node = this[7]; node; ) {
    //       next = *(int*)(node + 140);
    //       (*(void (__thiscall**)(int,int))node)(node, 1);
    //       node = next;
    //     }
    //     this[7] = 0;
    //     for (node = this[65]; node; ) {
    //       next = *(int*)(node + 16);
    //       ThunkToFUN0053cb90(*(int*)(node + 12));
    //       *(int*)(node + 12) = 0;
    //       ShortComputation_4370(node + 4);
    //       FreeWrapper_7bcf(node);
    //       node = next;
    //     }
    //     for (node = (int*)this[67]; node; ) {
    //       next = (int*)node[21];
    //       ObjectResetWithVTableDispatch(node);
    //       FreeWrapper_7bcf(node);
    //       node = next;
    //     }
    //     CollisionGeometryFreeList();
    //     if (this[43]) { ThunkToFUN0053cb90(this[43]); this[43] = 0; }
    //     if (this[44]) { ThunkToFUN0053cb90(this[44]); this[44] = 0; }
    //     CursorResourceCleanup(dword_7CB24C);
    //     this[62] = this[60];
    //     for (node = this[62]; node && *node; ) {
    //       MASCloseWrapper(*(int*)(*node + 8));
    //       *(int*)(*node + 8) = 0;
    //       this[62] = *(int*)(this[62] + 4);
    //       node = this[62];
    //       if (node) node = (int*)*node;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Fields this[63] (offset 0xFC), this[68] (offset 0x110) and this[109] (offset 0x1B4) are referenced per the IDB but do not appear in the decompiled source text; their role here is unknown.
    // UNRESOLVED: Global unk_7CDE00 is referenced per the IDB but does not appear in the decompiled source text.
    // UNRESOLVED: Callees sub_542E50 and EmptyStub_7470 are listed as callees but are not visible in the decompiled source text.
    // UNRESOLVED: Owner class is unknown; name GlobalResourceManagerShutdown is DERIVED from existing analysis.
}
