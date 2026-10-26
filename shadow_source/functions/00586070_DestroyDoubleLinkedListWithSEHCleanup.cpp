// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586070
// Canonical corpus name: sub_586070
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_586070_00586070.c

void UnknownObject::DestroyDoubleLinkedListWithSEHCleanup()
{
    // Destroys two linked lists owned by the object: the first rooted at this+0x10 and the second rooted at this+0x0. For each node whose flag byte at node+0x8 is set and whose data pointer at node+0x0 is non-null, the function runs a per-node teardown (EmptyStub_0170) before freeing the data, then frees the node itself via FreeWrapper_7bcf. The second list additionally drives an SEH-registered callback loop (NTimeCallbackLoopWithSEH with size 1048, the SEH handler table at 0x0059D120) on the inner object before freeing the inner allocation, the data allocation, and the node. After each list is drained, all four root pointer/count fields of that list are zeroed. Returns 0.
    // GUARD: If the first list head at this+0x10 is non-null, traverse and drain the first list. [field:this:0x00000010, source:raw]
    // LOOP: Walk the first list following each node's next link; for nodes whose flag byte at node+0x8 is set and data pointer at node+0x0 is non-null, call EmptyStub_0170 then FreeWrapper_7bcf on the data, and free the node itself via FreeWrapper_7bcf. [field:obj:0x00000008, field:obj:0x00000000, callee:0x004B0170, global:0x004B0170, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four root fields of the first list: this+0x10, this+0x14, this+0x18 and this+0x1C. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // GUARD: If the second list head at this+0x0 is non-null, traverse and drain the second list. [field:this:0x00000000, source:raw]
    // LOOP: Walk the second list following each node's next link; for nodes whose flag byte at node+0x8 is set and data pointer at node+0x0 is non-null, dereference the data to reach an inner object, and if the inner object is non-null run NTimeCallbackLoopWithSEH on it with size 1048 and EmptyStub_0170 (under the SEH handler table at 0x0059D120), free the inner allocation base and the data allocation via FreeWrapper_7bcf, then free the node itself. [field:obj:0x00000008, field:obj:0x00000000, field:*(obj+0x0):0x00000000, callee:0x0058A5F7, callee:0x004B0170, callee:0x00587BCF, global:0x0059D120, source:raw]
    // ASSIGNMENT: Zero the four root fields of the second list: this+0x0, this+0x4, this+0x8 and this+0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return 0 after both lists are drained and zeroed. [function:0x00586070, source:raw]

    // Conservative worker pseudocode:
    //   list1 = a1 + 4; /* head at a1[4] == this+0x10 * /
    //   n = a1[4];
    //   while (n) { next = n[1]; if (n[8] && n[0]) { EmptyStub_0170(); FreeWrapper_7bcf(n[0]); } FreeWrapper_7bcf(n); n = next; }
    //   list1[0..3] = 0;
    //   n = a1[0];
    //   while (n) { next = n[1]; if (n[8] && n[0]) { p = n[0]; if (*p) { NTimeCallbackLoopWithSEH(*p, 1048, *(p-4), EmptyStub_0170); FreeWrapper_7bcf(p-4); } FreeWrapper_7bcf(p); } FreeWrapper_7bcf(n); n = next; }
    //   a1[0..3] = 0;
    //   return 0;
    // UNRESOLVED: The first list node stores data that is freed after an EmptyStub_0170 call, while the second list node data wraps an inner object drained by NTimeCallbackLoopWithSEH; the two lists' element semantics are inferred from the differing teardown paths, not independently evidenced.
    // UNRESOLVED: The exact size 1048 parameter semantics of NTimeCallbackLoopWithSEH and the SEH handler role of 0x0059D120 are not resolved from this function alone.
    // UNRESOLVED: The next-node link is read from the node's second dword, which the packet does not list as a tracked field.
}
