// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00544AF0
// Canonical corpus name: AudioNetworkStreamCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioNetworkStreamCleanup_00544af0.c

void UnknownObject::AudioNetworkStreamCleanup()
{
    // Teardown routine for an audio network stream subsystem. If the owner flags at this+0xEC have bit 0x100000 set, it destroys an array of sub-stream objects (count at this+0x160, stride 96, each destructed via DestructorWithConditionalFreeFlagClear), unlinks the array with DoublyLinkedListNodeRemovalWithArrayCleanup, zeroes this+0x160/0x164, frees the shared buffer global dword_8B78A0 via SubBufferFree, and clears the 0x100000 flag. It then destroys the two stream-handle globals dword_8B8DBC and dword_8B8DC0 (sub_542E50, EmptyStub_7470, FreeWrapper_7bcf). Finally it walks three owner lists: if any active tree is found in the list rooted at this+0x100 (child nodes via +0x1EC) or this+0x108 it returns -1 early, otherwise it runs TextureFlagTestWithDispatch over the list rooted at this+0x148 and finishes with sub_540760(dword_8B78A0), returning 0.
    // GUARD: Entry guard: proceed with array/flag cleanup only when owner flags at this+0xEC have bit 0x100000 set. [abi:lead, field:this:0x000000EC, function:0x00544AF0, source:raw]
    // GUARD: If the sub-stream array pointer at this+0x164 is nonzero, run the array destruction path. [field:this:0x00000164, source:raw]
    // LOOP: Iterate this+0x160 (this[88]) times over the sub-stream array at this+0x164, calling DestructorWithConditionalFreeFlagClear on each element and advancing by stride 96. [field:this:0x00000160, field:this:0x00000164, callee:0x005502C0, guard:0, source:raw]
    // CALL: Call DoublyLinkedListNodeRemovalWithArrayCleanup on the sub-stream array pointer at this+0x164 to unlink/detach the array. [callee:0x005478B0, field:this:0x00000164, source:raw]
    // ASSIGNMENT: Zero this+0x164 (array element count). [field:this:0x00000164, source:raw]
    // ASSIGNMENT: Zero this+0x160 (sub-stream array pointer). [field:this:0x00000160, source:raw]
    // CALL: Call SubBufferFree on the shared audio buffer global dword_8B78A0. [callee:0x00541420, global:0x008B78A0, source:raw]
    // ASSIGNMENT: Clear bit 0x100000 in the flags field at this+0xEC (this[59] &= ~0x100000). [field:this:0x000000EC, source:raw]
    // GUARD: If stream handle global dword_8B8DBC is nonzero, destroy it. [global:0x008B8DBC, source:raw]
    // CALL: Call sub_542E50 on dword_8B8DBC (stream teardown). [callee:0x00542E50, global:0x008B8DBC, source:raw]
    // CALL: Call EmptyStub_7470 on dword_8B8DBC. [callee:0x00557470, global:0x008B8DBC, source:raw]
    // CALL: Call FreeWrapper_7bcf to free the dword_8B8DBC allocation. [callee:0x00587BCF, global:0x008B8DBC, source:raw]
    // ASSIGNMENT: Set dword_8B8DBC = 0. [global:0x008B8DBC, source:raw]
    // GUARD: If stream handle global dword_8B8DC0 is nonzero, destroy it. [global:0x008B8DC0, source:raw]
    // CALL: Call sub_542E50 on dword_8B8DC0 (stream teardown). [callee:0x00542E50, global:0x008B8DC0, source:raw]
    // CALL: Call EmptyStub_7470 on dword_8B8DC0. [callee:0x00557470, global:0x008B8DC0, source:raw]
    // CALL: Call FreeWrapper_7bcf to free the dword_8B8DC0 allocation. [callee:0x00587BCF, global:0x008B8DC0, source:raw]
    // ASSIGNMENT: Set dword_8B8DC0 = 0. [global:0x008B8DC0, source:raw]
    // GUARD: If the list head at this+0x100 (this[64]) is nonzero, traverse the first tree list. [field:this:0x00000100, source:raw]
    // LOOP: Walk the first tree list: read child node at +0x1EC of the current node; if the child is nonzero, descend into its subtree; otherwise advance to the next sibling. During the walk, TreeActiveCheck is applied to the child node and to nodes reached through the +0x4C field chain; if any active tree is found the routine returns -1 early. [field:this:0x000001EC, field:*(*(this+0x1EC)+0x4C):0x0000004C, field:*(this+0x154):0x0000004C, callee:0x00544E20, source:raw]
    // RETURN: Return -1 when an active tree is found in the first tree list. [source:raw]
    // GUARD: If the list head at this+0x108 (this[66]) is nonzero, traverse the second tree list. [field:this:0x00000108, source:raw]
    // LOOP: Walk the second tree list from this+0x108, applying TreeActiveCheck to each node and following the +0x68 field chain; if an active tree is found the routine returns -1 early. [field:this:0x00000108, field:*(this+0x1B0):0x00000068, callee:0x00544E20, source:raw]
    // RETURN: Return -1 when an active tree is found in the second tree list. [source:raw]
    // LOOP: Iterate the texture list rooted at this+0x148 (this[82]), following next pointers at +0x104, and call TextureFlagTestWithDispatch on every node. [field:this:0x00000148, field:*(this+0x204):0x00000104, callee:0x00557630, source:raw]
    // CALL: Finalize by calling sub_540760 on the shared audio buffer global dword_8B78A0. [callee:0x00540760, global:0x008B78A0, source:raw]
    // RETURN: Return 0 on successful teardown (no active tree found). [source:raw]
    // CALL: This teardown is invoked by RenderTargetCleanup (0x0053F270) and ResourceCleanupDestructionForDirectXObjects (0x00543BF0) during shutdown paths. [caller:0x0053F270, caller:0x00543BF0]

    // Conservative worker pseudocode:
    //   // Teardown of the audio network stream subsystem.
    //   if (this->flags_0xEC & 0x100000) {
    //       if (this->stream_array_0x164) {
    //           for (i = 0; i < this->count_0x160; i++)
    //               DestructorWithConditionalFreeFlagClear(i * 96 + this->stream_array_0x164);
    //           DoublyLinkedListNodeRemovalWithArrayCleanup(this->stream_array_0x164);
    //           this->stream_array_0x164 = 0;
    //           this->count_0x160 = 0;
    //           SubBufferFree(dword_8B78A0);
    //       }
    //       this->flags_0xEC &= ~0x100000;
    //   }
    //   if (dword_8B8DBC) { sub_542E50(dword_8B8DBC); EmptyStub_7470(dword_8B8DBC); FreeWrapper_7bcf(dword_8B8DBC); dword_8B8DBC = 0; }
    //   if (dword_8B8DC0) { sub_542E50(dword_8B8DC0); EmptyStub_7470(dword_8B8DC0); FreeWrapper_7bcf(dword_8B8DC0); dword_8B8DC0 = 0; }
    //   for (node = this->list1_0x100; node; node = node->next_0x104) {
    //       child = node->child_0xEC;
    //       if (child) { while (!TreeActiveCheck(child, 0)) { child = child->next_0x4C; if (!child) break; } if (active) return -1; }
    //   }
    //   for (node = this->list2_0x108; node; node = node->next_0x68) {
    //       if (TreeActiveCheck(node, 0)) return -1;
    //   }
    //   for (node = this->texture_list_0x148; node; node = node->next_0x104)
    //       TextureFlagTestWithDispatch(node);
    //   sub_540760(dword_8B78A0);
    //   return 0;
    // UNRESOLVED: The list-walk offsets +260 (next) and +236/+76 (child/next fields) used in the raw source are not represented in the packet field evidence set; the exact node layout is unconfirmed.
    // UNRESOLVED: Meaning of the early return -1 (assumed 'an active tree still in use, do not finalize') is inferred from branch structure, not externally confirmed.
    // UNRESOLVED: Owner object identity is UNKNOWN; the packet provides no class evidence.
}
