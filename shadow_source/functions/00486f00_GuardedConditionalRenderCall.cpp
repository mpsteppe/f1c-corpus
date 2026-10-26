// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486F00
// Canonical corpus name: GuardedConditionalRenderCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedConditionalRenderCall_00486f00.c

void UnknownObject::GuardedConditionalRenderCall()
{
    // Guarded conditional rectangle render dispatch. If the enable flag a2 is set and the sub-renderer pointer at this+0x98 (this[38]) is non-null, dispatches a rectangle render through GuardedSubRectangleRenderDispatch (00499050) using four bounds read from this+0x4/0x8/0xC/0x10; otherwise returns the this pointer. Part of the UI conditional rendering system.
    // GUARD: If enable flag a2 is zero, skip the render entirely (leave v2 = this) [source:raw]
    // GUARD: If the sub-renderer pointer at this+0x98 (this[38]) is null, skip the render (no texture/delegate present) [field:this:0x00000098, source:raw]
    // CALL: Read the four rectangle bounds at this+0x4, this+0x8, this+0xC, this+0x10 and pass them with the sub-renderer to GuardedSubRectangleRenderDispatch (00499050); LOBYTE(v2) receives the dispatch result [callee:0x00499050, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // RETURN: return (char)v2 — dispatch result when the render ran, otherwise the low byte of the this pointer [function:0x00486F00, source:raw]

    // Conservative worker pseudocode:
    //   v2 = this;
    //   if (a2) {
    //     v3 = this[38];
    //     if (v3) LOBYTE(v2) = GuardedSubRectangleRenderDispatch(v3, this[1], this[2], this[3], this[4]);
    //   }
    //   return (char)v2;
    // UNRESOLVED: Return-type conflation: when the dispatch runs, the char return carries the dispatch result; otherwise it carries the low byte of the this pointer — the two meanings are indistinguishable to callers at this evidence level
    // UNRESOLVED: The interpretation of offsets 0x4/0x8/0xC/0x10 as rectangle bounds (left/right/top/bottom) comes from the existing analysis fill, not from the raw source alone
}
