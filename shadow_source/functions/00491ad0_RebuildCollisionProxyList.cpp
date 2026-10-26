// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491AD0
// Canonical corpus name: CollisionProxyListBuilder
// Owner: CollisionProxyListBuilder [DERIVED]
// Raw source: functions/CollisionProxyListBuilder_00491ad0.c

void CollisionProxyListBuilder::RebuildCollisionProxyList()
{
    // Rebuilds the collision proxy working list at header offset 0x1C: first destroys its previous contents, then iterates two source lists (a ring-buffer slot selected by the header index at 0x4, and the embedded list at header 0x2C), copying each source node's four shorts through the pool allocator into a 12-byte list node appended to the working list. Finally partitions the rebuilt working list against the list at header offset 0xC via sub_490D00 and returns its result.
    // CALL: Destroy the previous working list state at header offset 0x1C via ListIteratorFullDestruction. [callee:0x004910D0, field:this:0x00000000]
    // ASSIGNMENT: Read the current ring-buffer index from header offset 0x4 into a local used to select the source slot. [field:obj:0x00000004]
    // LOOP: Outer loop runs exactly twice (pass 0 and pass 1), rebuilding from two distinct source lists. [source:raw]
    // CALCULATION: Select the source list: pass 1 uses the embedded list sentinel at header offset 0x2C; pass 0 uses the ring-buffer slot at ring base (header offset 0x8) plus 16 times the index (header offset 0x4). [field:obj:0x0000002C, field:obj:0x00000008, field:obj:0x00000004]
    // GUARD: Guard on the source sentinel head being null (header offset 0x2C for the embedded list): when the sentinel's stored head is zero the source is skipped entirely. [guard:0, field:obj:0x0000002C, field:*(obj+0x2C):0x00000000]
    // ASSIGNMENT: Initialize the sentinel's current slot from its head pointer to begin iteration; for the embedded list the sentinel current slot is header offset 0x34. [field:obj:0x00000034, field:*(obj+0x2C):0x00000000]
    // CALL: For each source node, allocate a pool node from the node's four shorts (AABB x1/y1/x2/y2 of the embedded source list head node) via ResourcePoolNodeAllocDealloc. [callee:0x00490940, field:*(*(obj+0x2C)+0x0):0x00000000, field:*(*(obj+0x2C)+0x0):0x00000002, field:*(*(obj+0x2C)+0x0):0x00000004, field:*(*(obj+0x2C)+0x0):0x00000006]
    // CALL: Allocate a 12-byte list node wrapper via OperatorNewNhMallocWrapper(12) for each copied entry. [callee:0x00587C03]
    // ASSIGNMENT: Initialize the new 12-byte node: store the pool node in its first word, zero its next pointer and its flag byte. [source:raw]
    // STATE_TRANSITION: Append the new node to the working list at header offset 0x1C: set head and current on the first append, update tail on every append, and increment the count at header offset 0x28. [field:obj:0x0000001C, field:obj:0x00000020, field:obj:0x00000024, field:obj:0x00000028]
    // LOOP: Inner loop advances through source nodes: read the current node pointer (embedded list sentinel current at header offset 0x34), read that node's next pointer (node + 0x4), write it back into the sentinel current slot, and continue until a null next or node terminates the walk. [field:obj:0x00000034, field:*(obj+0x34):0x00000004, field:*(*(obj+0x34)+0x4):0x00000000]
    // CALL: After both sources are rebuilt, partition the working list at header offset 0x1C against the list at header offset 0xC via sub_490D00. [callee:0x00490D00, field:this:0x00000000]
    // RETURN: Return the result of the sub_490D00 partition. [callee:0x00490D00]

    // Conservative worker pseudocode:
    //   void CollisionProxyListBuilder::RebuildCollisionProxyList() {
    //     ListIteratorFullDestruction(header + 0x1C);
    //     int index = *(header + 0x4);
    //     for (int pass = 0; pass < 2; ++pass) {
    //       sentinel = (pass == 1) ? (header + 0x2C) : (*(header + 0x8) + 0x10 * index);
    //       if (*(sentinel) == 0) continue;
    //       node = *(sentinel);
    //       while (node != 0) {
    //         pool = ResourcePoolNodeAllocDealloc(node[0], node[1], node[2], node[3]);
    //         if (pool != 0) {
    //           entry = new Entry(pool);
    //           Append(workingList, entry);
    //         }
    //         *(sentinel + 0x8) = *(node + 0x4);
    //         node = *(sentinel + 0x8);
    //       }
    //     }
    //     return sub_490D00(header + 0x1C, header + 0xC);
    //   }
    // UNRESOLVED: Meaning of the four shorts read per source node (AABB box vs other payload) is inferred from the surrounding collision context, not confirmed.
    // UNRESOLVED: Relationship and shared structure between the ring-buffer source list and the embedded list at header offset 0x2C is unknown.
    // UNRESOLVED: Role of the partition target list at header offset 0xC and the meaning of sub_490D00's return value are unknown.
    // UNRESOLVED: The 12-byte working-list node layout (value pointer, next, flag byte) is read from the raw writes, not from a named structure.
}
