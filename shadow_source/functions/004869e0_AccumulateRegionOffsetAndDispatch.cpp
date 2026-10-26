// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004869E0
// Canonical corpus name: MultiRegionOffsetAccumulationWithVTableDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiRegionOffsetAccumulationWithVTableDispatch_004869e0.c

void UnknownObject::AccumulateRegionOffsetAndDispatch()
{
    // Offsets four stored region bounds (left/right/top/bottom at this+0x4/0x8/0xC/0x10) by horizontal delta a3 and vertical delta a2, redraws the union of the old and new bounds via GuardedSubRectangleRenderDispatch, notifies self through vtable slot 44, then propagates the same deltas to every child in the linked list headed at this+0x90 and returns the result of vtable slot 160.
    // ASSIGNMENT: Read the four stored region bounds: left this+0x4, right this+0x8, top this+0xC, bottom this+0x10. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010]
    // CALCULATION: Compute the union (old plus offset) bounds for the damaged-area redraw: left uses an unsigned-carry select between the old value and old+a3; right and bottom take the maximum of old and offset values; top takes the minimum. [source:raw]
    // CALL: Call GuardedSubRectangleRenderDispatch with the computed union left/right/top/bottom to redraw the region now damaged by the offset. [callee:0x00499050]
    // ASSIGNMENT: Accumulate the deltas into the stored bounds: left this+0x4 += a3, right this+0x8 += a3, top this+0xC += a2, bottom this+0x10 += a2. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010]
    // CALL: Self-notify through vtable slot 44 (vtable pointer at this+0x0, member at obj+0x2C) called with this and argument 1. [field:this:0x00000000, field:obj:0x0000002C]
    // LOOP: Iterate the child linked list headed at this+0x90 (this[36] in the raw source); for each child recurse into MultiRegionOffsetAccumulationWithVTableDispatch with the same deltas and advance using the child's next pointer at offset 0x8C (evidence base *(this+0x11C)). [field:this:0x00000090, field:*(this+0x11C):0x0000008C, callee:0x004869E0]
    // CALL: Call the vtable handler at slot 160 (member at obj+0xA0) with this as its argument. [field:this:0x00000000, field:obj:0x000000A0]
    // RETURN: Return the value produced by the vtable-slot-160 handler. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4869E0(_DWORD *this, int a2, int a3) {
    //     int left = this[1], right = this[2], top = this[3], bottom = this[4];
    //     int uLeft   = (unsigned)(left < left + a3)   ? left : left + a3;
    //     int uRight  = (right <= right + a3)          ? right + a3 : right;
    //     int uTop    = (top >= top + a2)              ? top + a2 : top;
    //     int uBottom = (bottom <= bottom + a2)        ? bottom + a2 : bottom;
    //     GuardedSubRectangleRenderDispatch(uLeft, uRight, uTop, uBottom);
    //     this[1] += a3;
    //     this[2] += a3;
    //     this[3] += a2;
    //     this[4] += a2;
    //     (*(void (__thiscall **)(_DWORD *, int))(this[0] + 44))(this, 1);
    //     for (int i = this[36]; i; i = *(int *)(i + 140))
    //       MultiRegionOffsetAccumulationWithVTableDispatch(a2, a3);
    //     return (*(int (__thiscall **)(_DWORD *))(this[0] + 160))(this);
    //   }
    // UNRESOLVED: The recursive call in the child loop passes (a2, a3) with no explicit this in the decompiler rendering; the intended per-child invocation target is unresolved.
    // UNRESOLVED: Vtable slots 44 and 160 are indirect call targets with no static callee record; their behavior is labeled self-notify and end-state handler only as DERIVED from the existing fill.
    // UNRESOLVED: The child list head at this+0x90 is confirmed, but the child node layout beyond the next pointer at offset 0x8C is unknown.
    // UNRESOLVED: The region is plausibly a UI scroll/pan region given the bounds offset + redraw pattern, but no static class evidence grounds an owner proposal.
}
