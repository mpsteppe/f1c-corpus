// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00557120
// Canonical corpus name: sub_557120
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_557120_00557120.c

void UnknownObject::RenderFrameUpdate()
{
    // Per-frame rendering update on a render/scene manager object: runs an entry stub, clears per-sub-node flags through a descriptor array (+0x150, stride 24) and a tree linked list (+0x15C), conditionally clears buffer present/dirty flags at +0xEC (bits 0x800 / mask 0xFFBFF7FF) and dispatches dirty-list traversal, updates audio nodes when the +0x16C count is positive, walks the render-node linked list rooted at +0xF8, then refreshes animation time at +0xF0 via sub_556730 and feeds it to D3DAnimationTimeUpdate and AddFloatToAnimationChannels.
    // CALL: Entry call to EmptyStub_0170 with no arguments before any state is touched. [callee:0x004B0170, source:raw]
    // GUARD: If the sub-node descriptor count at +0x14C is greater than zero, run the descriptor array traversal. [guard:0, field:this:0x0000014C, source:raw]
    // LOOP: Iterate the descriptor array at +0x150 in 24-byte steps; for each descriptor take the pointer stored at descriptor+16 and call sub_5503A0 on it when non-null (clears a per-sub-node flag). [field:this:0x00000150, callee:0x005503A0, source:raw]
    // LOOP: Walk the tree/sub-node linked list rooted at +0x15C, advancing through the node's next pointer at +0x34, clearing bit 8 at node+0x24 on every node. [field:this:0x0000015C, field:*(*(this+0x15C)+0x34):0x00000024, field:*(*(this+0x15C)+0x34):0x00000034, source:raw]
    // GUARD: If the render-flag bitmask at +0xEC has the 0x800 present bit set, run the buffer-clear and dirty-mark path. [field:this:0x000000EC, source:raw]
    // CALL: Call ClearBuffersLoop(this) when the present flag is set. [callee:0x00545850, source:raw]
    // GUARD: If the global bitmask unk_600000 ANDed with the +0xEC render flags is nonzero, call NestedLinkedListTraversalWithDirtyMark(this, render-node list head at +0xF8). [global:0x00600000, callee:0x005570C0, field:this:0x000000F8, source:raw]
    // ASSIGNMENT: Clear the present/dirty bits from the render-flag mask at +0xEC using AND with 0xFFBFF7FF. [field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Reset the global buffer/reset flag dword_8CEF70 to zero. [global:0x008CEF70, source:raw]
    // GUARD: If the global gate flag dword_8B8DF0 is zero, call VTableGetterWrapper(dword_8B78A0) to fetch a graphics/sound vtable. [global:0x008B8DF0, global:0x008B78A0, callee:0x005550A0, source:raw]
    // GUARD: If the audio node count at +0x16C is greater than zero, call AudioNodeIterator(this). [guard:1, field:this:0x0000016C, callee:0x00548DD0, source:raw]
    // LOOP: Walk the render-node linked list rooted at +0xF8 via the next pointer at node+0x1B8, calling sub_556E70(node, this) for each node. [field:this:0x000000F8, field:*(*(this+0xF8)+0x1B8):0x000001B8, callee:0x00556E70, source:raw]
    // GUARD: If dword_8B8DF0 is still zero, call VTableDispatchGetter(dword_8B78A0) to dispatch into the fetched vtable. [global:0x008B8DF0, global:0x008B78A0, callee:0x005550C0, source:raw]
    // ASSIGNMENT: Compute the current animation time by calling sub_556730(-1) and store it at +0xF0. [callee:0x00556730, field:this:0x000000F0, source:raw]
    // CALL: Call D3DAnimationTimeUpdate(this, animation time) with the freshly computed time. [callee:0x00550310, source:raw]
    // RETURN: Return the result of AddFloatToAnimationChannels(this, animation time at +0xF0), the final per-frame animation channel update. [callee:0x00556900, field:this:0x000000F0, source:raw]

    // Conservative worker pseudocode:
    //   EmptyStub_0170();
    //   if (this->count /*+0x14C* / > 0)
    //       for (off = 0; off < this->count; off += 24)
    //           if (p = *(this->array /*+0x150* / + off + 16))
    //               sub_5503A0(p);
    //   for (n = this->treeHead /*+0x15C* /; n; n = *(n + 52))
    //       *(n + 36) &= ~8u;
    //   if (this->flags /*+0xEC* / & 0x800) {
    //       ClearBuffersLoop(this);
    //       if (unk_600000 & this->flags)
    //           NestedLinkedListTraversalWithDirtyMark(this, this->head /*+0xF8* /);
    //       this->flags &= 0xFFBFF7FF;
    //   }
    //   dword_8CEF70 = 0;
    //   if (!dword_8B8DF0) VTableGetterWrapper(dword_8B78A0);
    //   if (this->audioCount /*+0x16C* / > 0) AudioNodeIterator(this);
    //   for (r = this->head /*+0xF8* /; r; r = *(r + 440))
    //       sub_556E70(r, this);
    //   if (!dword_8B8DF0) VTableDispatchGetter(dword_8B78A0);
    //   this->time /*+0xF0* / = sub_556730(-1);
    //   D3DAnimationTimeUpdate(this, this->time);
    //   return AddFloatToAnimationChannels(this, this->time);
    // UNRESOLVED: Owner class is unnamed in the corpus; fields at +0x14C/+0x150 (descriptor array), +0x15C (tree list), +0xF8 (render list), +0xEC (flags), +0xF0 (time), +0x16C (audio count) are DERIVED from this function only.
    // UNRESOLVED: The 0x400008-related meaning of the 0xFFBFF7FF mask beyond the visible 0x800 present bit is not established by this function alone.
    // UNRESOLVED: Called by ArithmeticComparison_6200 (0x00546200); the per-frame context is not confirmed on a static frame path.
}
