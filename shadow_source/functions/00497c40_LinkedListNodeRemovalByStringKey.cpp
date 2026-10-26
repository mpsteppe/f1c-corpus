// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497C40
// Canonical corpus name: LinkedListNodeRemovalByStringKey
// Owner: SurfaceNodeRegistry [DERIVED]
// Raw source: functions/LinkedListNodeRemovalByStringKey_00497c40.c

void SurfaceNodeRegistry::LinkedListNodeRemovalByStringKey()
{
    // Removes the first node of a singly linked list whose name string (node+0x4) equals a2, comparing with sub_588410. Head lives at this+0x104; each node stores name at +0x4, data at +0xC and next at +0x10. On match the node is unlinked (predecessor's next or the head is re-pointed to the matched node's next), its data is processed via ThunkToFUN0053cb90 and cleared, then name and node are freed. Returns 1 on successful removal, 0 when the list is empty or no node matches. Callers are profile-icon BMP loaders, so the list is a per-owner surface/node registry keyed by name.
    // GUARD: If the head at this+0x104 is null, return 0 immediately (empty list). [field:this:0x00000104, source:raw]
    // LOOP: Traverse from the head at this+0x104, tracking the previous node; the current node pointer is held at this+0x114. [field:this:0x00000104, field:this:0x00000114, source:raw]
    // CALL: Compare the current node's name at node+0x4 against a2 with sub_588410; an equal result ends the traversal at a match, and running out of nodes returns 0. [field:*(this+0x114):0x00000004, callee:0x00588410, source:raw]
    // ASSIGNMENT: Name defaulting: when the node name pointer at node+0x4 is null, substitute the byte_5EA438 string before comparison. [field:*(this+0x114):0x00000004, global:0x005EA438, source:raw]
    // ASSIGNMENT: Unlink the matched node: the previous node's next (node+0x10), or the head at this+0x104 when there is no previous node, is re-pointed to the matched node's next (node+0x10). [field:this:0x00000104, field:*(this+0x114):0x00000010, source:raw]
    // CALL: Process the node data at node+0xC through ThunkToFUN0053cb90, then clear the data field to 0. [callee:0x00494FD0, field:*(this+0x114):0x0000000C, source:raw]
    // GUARD: Dead-path cleanup: if the data field at node+0xC is non-null (it was just cleared, so unreachable in straight-line flow) call sub_542E50, then EmptyStub_7470 and FreeWrapper_7bcf on the data pointer. [field:*(this+0x114):0x0000000C, callee:0x00542E50, callee:0x00557470, callee:0x00587BCF, source:raw]
    // GUARD: If the node name at node+0x4 is non-null, free it with FreeWrapper_7bcf. [field:*(this+0x114):0x00000004, callee:0x00587BCF, source:raw]
    // CALL: Free the node itself with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return 1 on successful removal; 0 when the list is empty or the key is not found. [function:0x00497C40, source:raw]
    // CALL: Invoked by ProfileIconBmpLoader (004692b0) and CopyProfileIconBMP (0046cd20) to remove a named surface/node from the registry. [caller:0x004692B0, caller:0x0046CD20, source:raw]

    // Conservative worker pseudocode:
    //   if (this->head_0x104 == NULL) return 0;
    //   prev = NULL; cur = this->head_0x104;
    //   while (cur != NULL) {
    //     name = (cur->name_0x4 != NULL) ? cur->name_0x4 : byte_5EA438;
    //     if (sub_588410(name, a2) != 0) break;
    //     prev = cur; cur = cur->next_0x10;
    //   }
    //   if (cur == NULL) return 0;
    //   if (prev != NULL) prev->next_0x10 = cur->next_0x10;
    //   else this->head_0x104 = cur->next_0x10;
    //   ThunkToFUN0053cb90(cur->data_0xC);
    //   cur->data_0xC = 0;
    //   if (cur->data_0xC != NULL) { sub_542E50(); EmptyStub_7470(cur->data_0xC); FreeWrapper_7bcf(cur->data_0xC); }
    //   if (cur->name_0x4 != NULL) FreeWrapper_7bcf(cur->name_0x4);
    //   FreeWrapper_7bcf(cur);
    //   return 1;
    // UNRESOLVED: this+0x108 is listed by packet facts as a read field but is never referenced in the decompiled body; its counter/role is unverified
    // UNRESOLVED: global 0x007CDE00 (unk_7CDE00) is listed as read by packet facts but does not appear in the decompiled body; purpose unknown
    // UNRESOLVED: the sub_542E50 / EmptyStub_7470 cleanup branch reads a data field that was zeroed one statement earlier, so it is dead in straight-line execution
    // UNRESOLVED: the comparison semantics of sub_588410 (string equality vs. prefix) are not established by this packet
}
