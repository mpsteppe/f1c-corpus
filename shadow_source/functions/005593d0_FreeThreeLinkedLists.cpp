// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005593D0
// Canonical corpus name: sub_5593D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5593D0_005593d0.c

void UnknownObject::FreeThreeLinkedLists()
{
    // Frees three singly-linked lists rooted at this offsets 0x0, 0x4 and 0x8. Each node carries its next pointer at node offset 0x1C (node[7]). For each non-null head, the list is walked, every node is released via EmptyStub_7470 then FreeWrapper_7bcf, and the head is nulled afterwards. Used as part of DirectX object teardown.
    // ASSIGNMENT: Load the first list head from this[0] into the traversal pointer. [field:this:0x00000000, source:raw]
    // GUARD: Guard on the first head (this[0]) being non-null; a null head skips that list entirely. [field:this:0x00000000, source:raw]
    // LOOP: Walk the first list while the current node's next pointer (node offset 0x1C, node[7]) is non-null, advancing to it after each release. [field:obj:0x0000001C, source:raw]
    // CALL: Invoke EmptyStub_7470 on each node being released before freeing it. [callee:0x00557470, source:raw]
    // CALL: Release each node through FreeWrapper_7bcf, including the final node of the list. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Null the first list head this[0] after its list is fully freed. [field:this:0x00000000, source:raw]
    // GUARD: Guard on the second head (this[4]) being non-null before traversing and freeing the second list. [field:this:0x00000004, source:raw]
    // LOOP: Walk the second list while each node's next pointer (node offset 0x1C) is non-null, releasing every node with EmptyStub_7470 and FreeWrapper_7bcf. [field:obj:0x0000001C, callee:0x00557470, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Null the second list head this[4] after its list is fully freed. [field:this:0x00000004, source:raw]
    // GUARD: Guard on the third head (this[8]) being non-null before traversing and freeing the third list. [field:this:0x00000008, source:raw]
    // LOOP: Walk the third list while each node's next pointer (node offset 0x1C) is non-null, releasing every node with EmptyStub_7470 and FreeWrapper_7bcf. [field:obj:0x0000001C, callee:0x00557470, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Null the third list head this[8] after its list is fully freed. [field:this:0x00000008, source:raw]
    // CALL: Called by ResourceCleanupDestructionForDirectXObjects (0x00543BF0) to tear down three related object lists at DirectX resource cleanup. [caller:0x00543BF0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5593D0(_DWORD *this) {
    //     for (int list = 0; list < 3; list++) {
    //       _DWORD *node = this[list];
    //       if (node) {
    //         while (node[7]) { _DWORD *nxt = node[7]; EmptyStub_7470(node); FreeWrapper_7bcf(node); node = nxt; }
    //         EmptyStub_7470(node); FreeWrapper_7bcf(node);
    //         this[list] = 0;
    //       }
    //     }
    //   }
    // UNRESOLVED: The identity of the object type behind the three lists is unknown; nodes expose only a next pointer at offset 0x1C.
    // UNRESOLVED: The role of the read-only this fields at offsets 0x20 and 0x24 is not exercised by this function's own instructions.
}
