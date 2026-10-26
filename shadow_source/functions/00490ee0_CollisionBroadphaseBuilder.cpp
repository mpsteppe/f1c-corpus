// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490EE0
// Canonical corpus name: CollisionBroadphaseBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionBroadphaseBuilder_00490ee0.c

void UnknownObject::CollisionBroadphaseBuilder()
{
    // Builds/updates a broadphase collision list a1 against a new AABB (a2-a5): allocates a pool AABB node, filters existing list nodes via sub_491680, clips overlapping AABBs into subdivisions via RectangleClipping, appends subdivision nodes to the list, unlinks and re-prepends the consumed node, then partitions the result via sub_490D00 and re-appends nodes through DoublyLinkedListAppend before destroying the temporary partition list.
    // CALL: Allocate a pool AABB node from the input coordinates a2-a5 via ResourcePoolNodeAllocDealloc. [callee:0x00490940, function:0x00490EE0]
    // GUARD: If the input list head a1[0] is null, skip the iteration phase; otherwise snapshot a1[2] to the current head before walking. [guard:0, field:this:0x00000000, field:this:0x00000008]
    // LOOP: Iterate the input list from the head, testing each stored node's AABB against the new AABB via sub_491680. [callee:0x00491680]
    // LOOP: For each overlapping node, run RectangleClipping to produce subdivisions; for each subdivision allocate a 12-byte node via OperatorNewNhMallocWrapper and link it into the a1 list updating head, tail, current and count. [callee:0x00491350, callee:0x00587C03, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // LOOP: Walk the list to locate the processed node, unlink it by fixing the previous node's next pointer, the head and tail pointers, and decrement the count, then free it via ConditionalResourceCleanup(1). [callee:0x00491E10, field:obj:0x00000000, field:obj:0x00000004, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // CALL: Re-add the unlinked node v8 to another list via LinkedListNodePrepend. [callee:0x00490AA0, field:obj:0x00000000]
    // ASSIGNMENT: Build a local partition list: wrap the pool AABB node v5 in a 12-byte node allocated via OperatorNewNhMallocWrapper and ShortComputation_ac20(v5, 0). [callee:0x00587C03, callee:0x004BAC20]
    // CALL: Finalize partitioning of the input list a1 against the local partition list via sub_490D00. [callee:0x00490D00]
    // LOOP: Iterate the partition list with LinkedListNodeAdvance and append each node back to a1 via DoublyLinkedListAppend(a1, node, 0). [callee:0x00581780, callee:0x00434030]
    // CALL: Destroy the temporary partition list via LinkedListDestructor_1db0. [callee:0x00491DB0]
    // RETURN: Return 0 (char result) to signal completion. [source:raw]

    // Conservative worker pseudocode:
    //   node = ResourcePoolNodeAllocDealloc(a2, a3, a4, a5)
    //   if a1 head exists: for each node in a1: if sub_491680(node) overlaps, clip into subdivisions and append 12-byte nodes to a1
    //   unlink the processed node from a1, free via ConditionalResourceCleanup, re-prepend via LinkedListNodePrepend
    //   wrap node into local partition list via ShortComputation_ac20, run sub_490D00 partition, append results back to a1 via DoublyLinkedListAppend
    //   LinkedListDestructor_1db0 on partition list
    //   return 0
    // UNRESOLVED: Meaning of the node flags byte at obj+0x8 (field is read by the raw source but no operation here consumes it).
    // UNRESOLVED: Semantics of sub_490D00 partitioning and the argument 0 to DoublyLinkedListAppend.
    // UNRESOLVED: Called from RenderSurfaceFillCopy (0x004918D0) and DualDispatchWithGuard (0x00491960); caller-side semantics not in this packet.
}
