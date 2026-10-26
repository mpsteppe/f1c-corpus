// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448330
// Canonical corpus name: AudioDSPStateUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioDSPStateUpdate_00448330.c

void UnknownObject::AudioDSPStateUpdate()
{
    // Per-frame audio DSP state update. When the float threshold at this+0x8 is positive it accumulates the incoming time (a2) with the stored offset at this+0x14, dispatches an interrupt, then walks the scene-graph children (count via SceneGraphChildCount on this+0x0) and conditionally dispatches each indexed child with the stored scene reference at this+0xC. Afterwards it always fetches a scene-node position and, when the DSP object at this+0x4 is non-null, calls its vtable method at slot +4 with literals 2, 1065353216 and 0, passing the fetched position, a zeroed scratch array and flt_7CF2CC. Finally it advances the linked state at this+0x10: ScrollingDataOffsetAcrossLinkedEntries when a2 equals the previous value at this+0x18, LinkedListAnimationTimerDecrement otherwise, always storing a2 back into this+0x18 and returning the call result (or the raw bits of a2 when the linked pointer is null). Called by sub_4D4580.
    // GUARD: Interrupt/dispatch block is gated on the float at this+0x8 being greater than 0.0 [field:this:0x00000008, source:raw]
    // CALCULATION: Accumulates the incoming time into v3 = a2 + this+0x14 [field:this:0x00000014, source:raw]
    // CALL: InterruptDispatch invoked with the accumulated time [callee:0x0058957A, source:raw]
    // CALL: SceneGraphChildCount run on the scene root handle at this+0x0 to obtain the child count [callee:0x0054C210, field:this:0x00000000, source:raw]
    // LOOP: Iterates the scene-graph children: LinkedListIndexedAccessor_c230 per index, then ConditionalDispatchByFlag with the scene reference at this+0xC and the accumulated time [callee:0x0054C230, callee:0x00551810, field:this:0x0000000C, source:raw]
    // CALL: SceneNodePositionGetter always called to fill the position outputs [callee:0x0054B950, source:raw]
    // CALL: Vtable dispatch on the DSP object at this+0x4 (vtable slot at +0, method pointer at +4): called with arguments 2, position, zeroed scratch, flt_7CF2CC, 1065353216 and 0 [field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(*(this+0x4)+0x0):0x00000004, global:0x007CF2CC, source:raw]
    // ASSIGNMENT: The scratch array v11 passed to the DSP method is zeroed with memset [source:raw]
    // GUARD: Linked-state advance only when the pointer at this+0x10 is non-null; otherwise the raw bits of a2 become the result [field:this:0x00000010, source:raw]
    // STATE_TRANSITION: When a2 equals the stored previous value at this+0x18, ScrollingDataOffsetAcrossLinkedEntries is called on the linked pointer; otherwise LinkedListAnimationTimerDecrement is called [callee:0x00550620, callee:0x005505A0, field:this:0x00000018, source:raw]
    // ASSIGNMENT: this+0x18 is written back to a2 on both the linked and null-linked paths, and the branch result (or a2) is returned [field:this:0x00000018, source:raw]
    // CALL: Invoked by the audio update driver sub_4D4580 [caller:0x004D4580, source:raw]

    // Conservative worker pseudocode:
    //   if (this[2] > 0.0) {
    //     v3 = a2 + this[5];
    //     InterruptDispatch(v3);
    //     count = SceneGraphChildCount(*(dword*)this);
    //     for (i = 0; i < count; ++i) {
    //       child = LinkedListIndexedAccessor_c230(i);
    //       ConditionalDispatchByFlag(child, *((dword*)this + 3), v3);
    //     }
    //   }
    //   SceneNodePositionGetter(&posx, &posy, &posz);
    //   dsp = *((dword*)this + 1);
    //   memset(scratch, 0, 12);
    //   if (dsp)
    //     (*(void (__thiscall**)(...))(*(dword*)dsp + 4))(dsp, 2, pos, scratch, flt_7CF2CC, 1065353216, 0);
    //   linked = *((dword*)this + 4);
    //   if (linked) {
    //     result = (a2 == this[6]) ? ScrollingDataOffsetAcrossLinkedEntries(linked, 0)
    //                            : LinkedListAnimationTimerDecrement(linked, 0);
    //     this[6] = a2;
    //   } else {
    //     result = LODWORD(a2); this[6] = a2;
    //   }
    //   return result;
    // UNRESOLVED: flt_59E440 appears in packet facts but nowhere in the raw decompiled source
    // UNRESOLVED: The purpose of the virtual DSP update (slot +4) and of its literal argument 1065353216 is not derivable from this packet
    // UNRESOLVED: The linked-state function choice encodes a scrolling-vs-animation branch whose meaning depends on the unnamed object at this+0x10
}
