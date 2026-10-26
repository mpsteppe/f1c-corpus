// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494E60
// Canonical corpus name: CollisionGeometryFreeList
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGeometryFreeList_00494e60.c

void UnknownObject::CollisionGeometryFreeList()
{
    // Frees a global collision-geometry linked list. First walks the list with StringCompareLinkedListSearch on each node's data pointer (node+0), advancing through next pointers (node+4). Then walks again freeing every node with FreeWrapper_7bcf, additionally freeing the node's data payload (via EmptyStub_7470 then FreeWrapper_7bcf) when the ownership byte at node+8 is non-zero and the data pointer is non-null. Finally zeroes the four collision globals dword_7CDDF0/7CDDF4/7CDDF8/7CDDFC. Returns immediately when the list head is null.
    // ASSIGNMENT: Copy list head dword_7CDDF0 into iterator dword_7CDDF8. [global:0x007CDDF0, global:0x007CDDF8, source:raw]
    // GUARD: If list head dword_7CDDF0 is null, skip both walks and jump to the zeroing tail. [global:0x007CDDF0, source:raw]
    // LOOP: First walk: while data at the current node (node+0) and the iterator dword_7CDDF8 are non-null, call StringCompareLinkedListSearch on the node data pointer and advance dword_7CDDF8 through the next pointer at node+4. [global:0x007CDDF0, global:0x007CDDF8, callee:0x0053D130, source:raw]
    // LOOP: Second walk: iterate every node via the next pointer at node+4, reading the ownership byte at node+8. [source:raw]
    // CALL: For nodes whose ownership byte at node+8 is non-zero and whose data pointer at node+0 is non-null, call EmptyStub_7470(data) then FreeWrapper_7bcf(data). [callee:0x00557470, callee:0x00587BCF, source:raw]
    // CALL: Free every node allocation with FreeWrapper_7bcf(node). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four collision globals: dword_7CDDF0, dword_7CDDF4, dword_7CDDF8 and dword_7CDDFC. [global:0x007CDDF0, global:0x007CDDF4, global:0x007CDDF8, global:0x007CDDFC, source:raw]

    // Conservative worker pseudocode:
    //   void CollisionGeometryFreeList() {
    //     dword_7CDDF8 = dword_7CDDF0;
    //     if (dword_7CDDF0) {
    //       // walk 1: StringCompareLinkedListSearch on each node data (node+0), advance via node+4
    //       // walk 2: if (byte at node+8) and data then EmptyStub_7470(data), FreeWrapper_7bcf(data)
    //       //         FreeWrapper_7bcf(node) for every node
    //     }
    //     dword_7CDDF0 = 0;
    //     dword_7CDDF4 = 0;
    //     dword_7CDDF8 = 0;
    //     dword_7CDDFC = 0;
    //   }
    // UNRESOLVED: Global 0x008AFE64 is read by this function per the fact table; the read is not visible in the Hex-Rays pseudocode, so its role (possibly timing/context input for the free pass) is unresolved.
    // UNRESOLVED: The exact semantic roles of dword_7CDDF4 and dword_7CDDFC (only written, both zeroed here) are not resolved from this packet alone.
}
