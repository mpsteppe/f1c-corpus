// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053CED0
// Canonical corpus name: DoublyLinkedListNodeRemovalByFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeRemovalByFlag_0053ced0.c

void UnknownObject::pruneListByFlag8()
{
    // Walks the global doubly-linked list rooted at dword_8B8F14 (nodes linked through +0x12C prev / +0x130 next), removing and freeing every node whose flag byte at +0x114 has bit 3 (value 8) set. The loop iterates one node ahead of the node it inspects, so a look-ahead node's predecessor is tested; a trailing check processes the final node that the loop advances past. Each removal unlinks the node with null-checked reciprocal pointer patches, runs DualFieldCleanupWithNullChecks and EmptyStub_7470 on it, frees it via FreeWrapper_7bcf, and decrements the global node count dword_8B6AC0. Returns 0.
    // ASSIGNMENT: Seed the traversal cursor v0 with the list head global dword_8B8F14; the head's +0x130 next link supplies the first loop iterate. [source:raw, global:0x008B8F14]
    // GUARD: If the list head dword_8B8F14 is null, skip the whole traversal and fall through to the return. [source:raw, global:0x008B8F14]
    // LOOP: Iterate the list starting from the head's +0x130 next link; each iteration re-cursors v0 to the current iterate and reads v2 = iterate's +0x12C prev link, then advances through the current node's +0x130 link. [source:raw, function:0x0053CED0]
    // GUARD: Test the inspected node v2's flag byte at +0x114 for bit 3 (value 8); only matching nodes are unlinked, cleaned and freed. [source:raw, function:0x0053CED0]
    // ASSIGNMENT: Unlink: if the inspected node v2's +0x12C prev link is non-null, patch that prev node's +0x130 next link to skip over v2 (pointing at v2's own +0x130). [source:raw, function:0x0053CED0]
    // ASSIGNMENT: Unlink: if the inspected node v2's +0x130 next link is non-null, patch that next node's +0x12C prev link to skip back over v2 (pointing at v2's own +0x12C). [source:raw, function:0x0053CED0]
    // ASSIGNMENT: If the inspected node v2 has no +0x12C prev link (it was the list head), promote v2's +0x130 successor into the head global dword_8B8F14. [source:raw, global:0x008B8F14]
    // CALL: Run DualFieldCleanupWithNullChecks on the removed node v2. [source:raw, callee:0x0055FE30]
    // CALL: Invoke the empty stub EmptyStub_7470 on the removed node v2. [source:raw, callee:0x00557470]
    // CALL: Release the removed node's heap block v2 via FreeWrapper_7bcf. [source:raw, callee:0x00587BCF]
    // ASSIGNMENT: Decrement the global node count dword_8B6AC0 by one for each removal. [source:raw, global:0x008B6AC0]
    // GUARD: After the loop, re-test the last visited node v0 for the same bit-3 flag at +0x114 and apply the identical unlink/cleanup/free sequence, covering the tail node whose flag is never tested during the look-ahead iteration. [source:raw, function:0x0053CED0]
    // RETURN: Return 0 unconditionally; the function reports no error or status value. [function:0x0053CED0, source:raw]

    // Conservative worker pseudocode:
    //   int pruneListByFlag8() {
    //     node* cur = dword_8B8F14;
    //     if (cur) {
    //       for (node* n = cur->next; n; n = cur->next) {
    //         cur = n;
    //         node* t = n->prev;
    //         if (t->flags & 8) {
    //           if (t->prev) t->prev->next = t->next;
    //           if (t->next) t->next->prev = t->prev;
    //           if (!t->prev) dword_8B8F14 = t->next;
    //           DualFieldCleanupWithNullChecks(t);
    //           EmptyStub_7470(t);
    //           FreeWrapper_7bcf(t);
    //           --dword_8B6AC0;
    //         }
    //       }
    //       if (cur->flags & 8) {
    //         if (cur->prev) cur->prev->next = cur->next;
    //         if (cur->next) cur->next->prev = cur->prev;
    //         if (!cur->prev) dword_8B8F14 = cur->next;
    //         DualFieldCleanupWithNullChecks(cur);
    //         EmptyStub_7470(cur);
    //         FreeWrapper_7bcf(cur);
    //         --dword_8B6AC0;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The +0x12C/+0x130 link fields and the +0x114 flag byte are read from the raw source with decimal offsets; their roles (prev/next/flag) are DERIVED from the traversal and unlink pattern, not confirmed by packet field evidence.
    // UNRESOLVED: The meaning of bit 3 (value 8) at +0x114 -- which property marks a node for pruning -- is unknown.
    // UNRESOLVED: The owner object type of the list nodes and the list's purpose (existing analysis ties it to vertex buffer resources) is not established by this packet.
    // UNRESOLVED: dword_8B8F14 as list head and dword_8B6AC0 as node count are DERIVED labels from prior analysis, not CONFIRMED.
}
