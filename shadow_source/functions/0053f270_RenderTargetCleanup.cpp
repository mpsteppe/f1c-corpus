// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053F270
// Canonical corpus name: RenderTargetCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderTargetCleanup_0053f270.c

void UnknownObject::RenderTargetCleanup()
{
    // Conditional render-target resource cleanup gated on the flag at this+0x13A8 having the 0x10000000 bit set. Releases three resource pointers (this+0x1140/0x113C via ObjectResetWithVirtualRelease, this+0x1144 via DrainingLoopFinalizer), each freed through FreeWrapper_7bcf and nulled; resets a state counter at this+0x13A0 to 1 and five state flags (this+0x14F0..0x1500) to 0; then walks two linked lists of sub-objects (heads at this+0x1518 and this+0x1580) resetting children and running UICleanupIterator where a +84 flag is set; optionally cleans the a2 audio/D3D object; finally clears the 0x10000000 flag.
    // GUARD: Entire cleanup gated on flag at this+0x13A8 with the 0x10000000 bit set; the block ends by clearing that same bit with a mask-and-store [field:this:0x000013A8, source:raw]
    // CALL: Release block for pointer at this+0x1140: ObjectResetWithVirtualRelease, then FreeWrapper_7bcf if still non-null, then zero the field [callee:0x00540EB0, callee:0x00587BCF, field:this:0x00001140, source:raw]
    // CALL: Release block for pointer at this+0x113C: ObjectResetWithVirtualRelease, then FreeWrapper_7bcf if still non-null, then zero the field [callee:0x00540EB0, callee:0x00587BCF, field:this:0x0000113C, source:raw]
    // CALL: Release block for pointer at this+0x1144: DrainingLoopFinalizer, then FreeWrapper_7bcf if still non-null, then zero the field [callee:0x00541040, callee:0x00587BCF, field:this:0x00001144, source:raw]
    // ASSIGNMENT: State counter at this+0x13A0 is reset to 1 during cleanup [field:this:0x000013A0, source:raw]
    // ASSIGNMENT: State flags at this+0x14F0, this+0x14F4, this+0x14F8, this+0x14FC and this+0x1500 are all reset to 0 [field:this:0x000014F0, field:this:0x000014F4, field:this:0x000014F8, field:this:0x000014FC, field:this:0x00001500, source:raw]
    // LOOP: First list walk: nodes from head this+0x1518, loop counter seeded at this+0x1504 to 0, advancing via the next pointer at node+8 while the node is non-null; per node the child at node+20 is reset with ObjectResetWithVirtualRelease and zeroed, and when the pointer at node+16 plus its +84 flag are both non-zero UICleanupIterator runs on node+16 [field:this:0x00001518, field:this:0x00001504, field:*(this+0x1518):0x00000084, callee:0x00540EB0, callee:0x00554D70, source:raw]
    // LOOP: Second list walk: nodes from head this+0x1580, advancing via the next pointer at node+2160 while non-null; per node ConditionalFreeByFlag_28b0 runs, and when the pointer at node+2152 plus its +84 flag are both non-zero UICleanupIterator runs on node+2152 [field:this:0x00001580, callee:0x005528B0, callee:0x00554D70, source:raw]
    // CALL: Optional a2 cleanup: AudioNetworkStreamCleanup(a2) and D3DResourceListCleanup(a2), then ValueGetter(a2) result released via D3DResourceRelease, and the flag at a2+236 gets 0x10000 OR-ed in [callee:0x00544AF0, callee:0x00554E10, callee:0x00545F40, callee:0x00554CC0, source:raw]
    // CALL: Invoked by RendererResourceCleanup (0053ead0) and sub_555E50 (00555e50) [caller:0x0053EAD0, caller:0x00555E50, source:raw]

    // Conservative worker pseudocode:
    //   if ((this[0x13A8/4] & 0x10000000) != 0) {
    //     for each of {0x1140, 0x113C}:
    //       if (ptr) { ObjectResetWithVirtualRelease(ptr);
    //                  if (ptr) FreeWrapper_7bcf(ptr);
    //                  ptr = 0; }
    //     if (this[0x1144]) { DrainingLoopFinalizer(this[0x1144]);
    //                         if (this[0x1144]) FreeWrapper_7bcf(this[0x1144]);
    //                         this[0x1144] = 0; }
    //     this[0x13A0] = 1;
    //     this[0x14F0] = this[0x14F4] = this[0x14F8] = this[0x14FC] = this[0x1500] = 0;
    //     for (node = this[0x1518], this[0x1504] = 0; node; node = node[8]) {
    //       if (node[5]) { ObjectResetWithVirtualRelease(node[5]); node[5] = 0; }
    //       if (node[4] && *(node[4] + 84)) UICleanupIterator(node[4]);
    //     }
    //     for (node = this[0x1580]; node; node = *(node + 2160)) {
    //       ConditionalFreeByFlag_28b0(node);
    //       p = *(node + 2152);
    //       if (p && *(p + 84)) UICleanupIterator(p);
    //     }
    //     if (a2) { AudioNetworkStreamCleanup(a2); D3DResourceListCleanup(a2);
    //               D3DResourceRelease(ValueGetter(a2));
    //               *(a2 + 236) |= 0x10000; }
    //     this[0x13A8] &= ~0x10000000;
    //   }
    // UNRESOLVED: Indirect device/sub-object fields reached through this+0x1580 (deref chain 0x868/0x870 and 0x54) and sub-object vtable offsets 0x30/0x34/0x40 are flagged by packet facts but absent from the raw decompiled source; the skeleton attributes them to D3D device release internals, unverifiable from this packet
}
