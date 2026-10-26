// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049ACC0
// Canonical corpus name: ScrollOffsetUpdateWithConditionalDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScrollOffsetUpdateWithConditionalDispatch_0049acc0.c

void UnknownObject::ScrollOffsetUpdateWithConditionalDispatch()
{
    // Applies scroll offsets a3 (vertical) and a2 (horizontal) to the four scroll fields this[1..4] (0x4, 0x8, 0xC, 0x10) with 16-bit overflow-aware boundary selection. When the render flag this[16] (0x40) is non-zero, obtains the render surface via Accessor() and calls RenderSurfaceFillCopy with the computed clamped extents. Then unconditionally accumulates the raw offsets into all four fields and returns the updated value of this[4].
    // CALCULATION: Compute the clamped vertical top extent from this[1] (0x4) plus a3 with 16-bit overflow-aware selection (v19). [field:this:0x00000004, source:raw]
    // CALCULATION: Compute the clamped vertical bottom extent from this[2] (0x8) plus a3 (v9). [field:this:0x00000008, source:raw]
    // CALCULATION: Compute the clamped horizontal left extent from this[3] (0xC) plus a2 (v11). [field:this:0x0000000C, source:raw]
    // CALCULATION: Compute the clamped horizontal right extent from this[4] (0x10) plus a2 (v12). [field:this:0x00000010, source:raw]
    // GUARD: If the render flag this[16] (0x40) is non-zero, perform the render surface fill copy with the clamped extents. [field:this:0x00000040, source:raw]
    // CALL: Call Accessor() to obtain the render surface pointer for the fill copy. [callee:0x00490920, source:raw]
    // CALL: Call RenderSurfaceFillCopy(surface, top, bottom, left, right) using the clamped extents (v19, v9, v11, v12). [callee:0x004918D0, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Accumulate the raw offsets unconditionally: this[1] += a3, this[2] = a3 + this[2], this[3] = a2 + this[3], this[4] = a2 + this[4]. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // RETURN: Return the accumulated right offset this[4] (0x10). [field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   top = clamp16(this[1] + a3);
    //   bottom = clamp16(this[2] + a3);
    //   left = clamp16(this[3] + a2);
    //   right = clamp16(this[4] + a2);
    //   if (renderFlag) {
    //       surface = Accessor();
    //       RenderSurfaceFillCopy(surface, top, bottom, left, right);
    //   }
    //   this[1] += a3;
    //   this[2] += a3;
    //   this[3] += a2;
    //   this[4] += a2;
    //   return this[4];
    // UNRESOLVED: The exact semantics of the 16-bit overflow-aware boundary selection (which operand wins on wrap) are not fully established by the packet.
    // UNRESOLVED: Whether the four fields are scroll offsets, a clip rectangle, or something else is not established by the packet.
}
