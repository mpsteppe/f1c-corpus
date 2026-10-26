// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431C70
// Canonical corpus name: PhysicsShutdown
// Owner: PhysicsSystemModule [DERIVED]
// Raw source: functions/PhysicsShutdown_00431c70.c

void PhysicsSystemModule::shutdownPhysicsSystem()
{
    // Tears down global physics-system state. Cleans up a doubly-linked list header (dword_7C73E8), walks and frees two global node lists (heads dword_7C7418 and dword_7C7404) using ConditionalFreeByFlagCheck/RecursiveNodeDeletion plus the memory free wrapper, zeroes all list heads and tails, frees two flagged allocation blocks (dword_7C73F8, dword_7C73F0) when non-null, and finally frees the list-header block dword_7C73E8. Called during engine shutdown.
    // CALL: Clean up the doubly-linked list header at dword_7C73E8 via DualLinkedListCleanup. [callee:0x004331A0, global:0x007C73E8]
    // LOOP: Walk the node list headed at dword_7C7418 (next pointer at node+4): for each node run ConditionalFreeByFlagCheck and then FreeWrapper_7bcf until the list is exhausted. [global:0x007C7418, callee:0x00582290, callee:0x00587BCF]
    // ASSIGNMENT: Reset the first list's head and tail state dword_7C7418, dword_7C741C, dword_7C7420, dword_7C7424 to 0. [global:0x007C7418, global:0x007C741C, global:0x007C7420, global:0x007C7424]
    // LOOP: Walk the node list headed at dword_7C7404 (next pointer at node+4): for each node run RecursiveNodeDeletion and then FreeWrapper_7bcf until the list is exhausted. [global:0x007C7404, callee:0x00434240, callee:0x00587BCF]
    // ASSIGNMENT: Reset the second list's head and tail state dword_7C7404, dword_7C7408, dword_7C740C, dword_7C7410 to 0. [global:0x007C7404, global:0x007C7408, global:0x007C740C, global:0x007C7410]
    // GUARD: If dword_7C73F8 is non-null, release it via FreeWrapper_7bcf. [global:0x007C73F8, callee:0x00587BCF]
    // GUARD: If dword_7C73F0 is non-null, release it via FreeWrapper_7bcf. [global:0x007C73F0, callee:0x00587BCF]
    // RETURN: If dword_7C73E8 is non-null, release it via FreeWrapper_7bcf and return the (now-null) value; otherwise return the existing null value. [global:0x007C73E8, callee:0x00587BCF]

    // Conservative worker pseudocode:
    //   DualLinkedListCleanup(&dword_7C73E8)
    //   for node in list(dword_7C7418): ConditionalFreeByFlagCheck(node); FreeWrapper_7bcf(node)
    //   zero dword_7C7418/7C741C/7C7420/7C7424
    //   for node in list(dword_7C7404): RecursiveNodeDeletion(node); FreeWrapper_7bcf(node)
    //   zero dword_7C7404/7C7408/7C740C/7C7410
    //   if dword_7C73F8: FreeWrapper_7bcf(dword_7C73F8)
    //   if dword_7C73F0: FreeWrapper_7bcf(dword_7C73F0)
    //   if dword_7C73E8: return FreeWrapper_7bcf(dword_7C73E8)
    // UNRESOLVED: The node layout is only observed as a next pointer at node+4; the exact node struct (size, extra fields) is not reconstructed.
    // UNRESOLVED: The distinct roles of the two freed node lists (dword_7C7418 vs dword_7C7404) and the two flagged blocks (dword_7C73F8/dword_7C73F0) are inferred from the free discipline, not proven.
}
