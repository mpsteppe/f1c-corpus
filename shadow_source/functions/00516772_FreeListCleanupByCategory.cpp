// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00516772
// Canonical corpus name: sub_516772
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_516772_00516772.c

void UnknownObject::FreeListCleanupByCategory()
{
    // Per-category cleanup of a free-list allocator object. Reads the allocator state array at *(this+0x4). For category a2 >= 2, tags the vtable subobject (obj+0x14 = 12, obj+0x18 = a2) and dispatches a virtual call on it. For category a2 == 1, first drains two active-node lists (heads at this+0x44 and this+0x48): for each node with the byte flag at node+0x22 set, clears the flag and invokes the cleanup callback at node+0x30 with (a1, node+0x28), then clears the list heads. Finally frees both per-category free-list chains (heads v3[a2+14] and v3[a2+12]) by calling FreeWrapper_9351 on each node and decrementing the allocation counter at this+0x4C by the recovered block size (node[2] + node[1] + 16). Returns null after the chains are drained.
    // ASSIGNMENT: Load the allocator state array pointer: v3 = *(this+0x4); all list heads and the counter are reached through it. [field:this:0x00000004, source:raw]
    // GUARD: Guard on category a2 >= 2: tag the vtable subobject and dispatch to a virtual method before any list processing. [source:raw]
    // ASSIGNMENT: Write constant 12 into obj+0x14 on the vtable subobject (*a1) when a2 >= 2. [field:obj:0x00000014, source:raw]
    // ASSIGNMENT: Write the category value a2 into obj+0x18 on the vtable subobject when a2 >= 2. [field:obj:0x00000018, source:raw]
    // CALL: Virtual dispatch: read the vtable pointer at obj+0x0 (dereferencing this+0x0) and call the method at it with a1 as argument. [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // GUARD: Guard on category a2 == 1: process the two active-node lists before freeing the category chains; this branch is driven by the caller TwoIterationCleanup. [source:raw, caller:0x00516853]
    // LOOP: Walk active-node list 1 from head this+0x44 (v3[16]) until the next pointer at node+0x24 is null; for each node with the byte flag at node+0x22 set, clear the flag and call the cleanup callback at node+0x30 with (a1, node+0x28). After the walk, clear the list head this+0x44 to 0. [field:this:0x00000044, field:*(this+0x68):0x00000022, field:*(this+0x68):0x00000024, field:*(this+0x68):0x00000030, source:raw]
    // LOOP: Walk active-node list 2 from head this+0x48 (v3[17]) following the next pointer at node+0x24; for each node with the byte flag at node+0x22 set, clear the flag and call the cleanup callback at node+0x30 with (a1, node+0x28). After the walk, clear the list head this+0x48 to 0. [field:this:0x00000048, field:*(this+0x6C):0x00000022, field:*(this+0x6C):0x00000024, field:*(this+0x6C):0x00000030, source:raw]
    // LOOP: Free category free-list chain 1 (head v3[a2+14], cleared to 0 before the walk): for each node, save the next pointer at node[0], compute the block size as node[2] + node[1] + 16, call FreeWrapper_9351(a1, node), and decrement the counter this+0x4C by the block size. [callee:0x00519351, field:this:0x0000004C, source:raw]
    // LOOP: Free category free-list chain 2 (head v3[a2+12], cleared to 0 before the walk): for each node, save the next pointer at node[0], compute the block size as node[2] + node[1] + 16, call FreeWrapper_9351(a1, node), and decrement the counter this+0x4C by the block size. [callee:0x00519351, field:this:0x0000004C, source:raw]
    // RETURN: Return the saved chain pointer, which is null after the category free chains are drained. [source:raw, abi:lead, function:0x00516772]

    // Conservative worker pseudocode:
    //   void sub_516772(void* a1, unsigned int category) {
    //     unsigned int* state = *(unsigned int**)((char*)a1 + 4);
    //     if (category >= 2) {
    //       *(unsigned int*)((char*)*a1 + 20) = 12;
    //       *(unsigned int*)((char*)*a1 + 24) = category;
    //       (*(void (**)(void*))*a1)(a1);
    //     }
    //     if (category == 1) {
    //       for (node = state[16]; node; node = *(void**)((char*)node + 36))
    //         if (*(char*)((char*)node + 34)) { *(char*)((char*)node + 34) = 0;
    //           (*(void (**)(void*, void*))((char*)node + 48))(a1, (char*)node + 40); }
    //       state[16] = 0;
    //       for (node = state[17]; node; node = *(void**)((char*)node + 36))
    //         if (*(char*)((char*)node + 34)) { *(char*)((char*)node + 34) = 0;
    //           (*(void (**)(void*, void*))((char*)node + 48))(a1, (char*)node + 40); }
    //       state[17] = 0;
    //     }
    //     node = state[category + 14];
    //     state[category + 14] = 0;
    //     while (node) { next = *node; state[18] -= node[2] + node[1] + 16;
    //                    FreeWrapper_9351(a1, node); node = next; }
    //     node = state[category + 12];
    //     state[category + 12] = 0;
    //     while (node) { next = *node; state[18] -= node[2] + node[1] + 16;
    //                    FreeWrapper_9351(a1, node); node = next; }
    //   }
    // UNRESOLVED: Identity of the allocator object and of the state array at *(this+0x4) is unknown.
    // UNRESOLVED: The virtual method dispatched in the a2 >= 2 branch (on the vtable subobject *a1) is unnamed.
    // UNRESOLVED: Semantics of the per-node size components node[1] and node[2] (used as node[2]+node[1]+16) are unknown.
    // UNRESOLVED: The active-node bases *(this+0x68) and *(this+0x6C) and the cleanup callback contract (a1, node+0x28) are unnamed.
}
