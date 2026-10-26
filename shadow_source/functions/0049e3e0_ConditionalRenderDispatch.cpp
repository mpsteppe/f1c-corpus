// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E3E0
// Canonical corpus name: ConditionalDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatch_0049e3e0.c

void UnknownObject::ConditionalRenderDispatch()
{
    // Guarded rendering dispatch. Reads the render-surface pointer this[2] and the display-context pointer this[5]; when both are non-null, reads a sub-context pointer at this+0x68 (*(this[5]+84)) and, when that is also non-null, calls sub_49F1C0 with fixed parameters (1, 1, 0) plus the two guarded pointers. Any null check aborts the dispatch. Called by sub_49D5D0.
    // GUARD: Reads the render-surface pointer at this+0x8 (this[2]); if null, skips the dispatch [field:this:0x00000008, source:raw]
    // GUARD: Reads the display-context pointer at this+0x14 (this[5]); if null, skips the dispatch [field:this:0x00000014, source:raw]
    // GUARD: Reads the sub-context pointer at this+0x68 (*(this[5]+84)); if null, skips the dispatch [field:this:0x00000068, source:raw]
    // CALL: Calls sub_49F1C0 with fixed flags (1, 1, 0) and the two guarded pointers (render surface at this+0x8, sub-context at this+0x68) as trailing arguments [callee:0x0049F1C0, source:raw]
    // CALL: Invoked by sub_49D5D0 as a conditional rendering-dispatch step [caller:0x0049D5D0, source:raw]

    // Conservative worker pseudocode:
    //   surface = this[0x8/4];
    //   if (!surface) return;
    //   ctx = this[0x14/4];
    //   if (!ctx) return;
    //   sub = *(ctx + 84);
    //   if (sub) sub_49F1C0(1, 1, 0, surface, sub);
    // UNRESOLVED: Global dword_7CE048 is flagged by packet facts but appears nowhere in the raw decompiled source; the skeleton fill labels it RaceSessionState, not verifiable from this packet
    // UNRESOLVED: The exact rendering role of the fixed flags (1, 1, 0) and of sub_49F1C0 is not established from this packet
}
