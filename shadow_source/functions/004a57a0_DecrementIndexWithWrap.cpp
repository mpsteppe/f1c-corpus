// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A57A0
// Canonical corpus name: IndexDecrementWithBoundsWrap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexDecrementWithBoundsWrap_004a57a0.c

void UnknownObject::DecrementIndexWithWrap()
{
    // Decrements a per-entry index stored in a table whose stride is 64 bytes (this + 16*a2 DWORDs), then wraps the index back toward the per-entry bound when it underflows below zero. Wrap direction reverses the incremented counterpart's convention: when the flag byte at base+53 is set the index resets to bound-1, otherwise to 0. Entry 0 returns a conditional dispatch call, and selector a2 == 2 first normalizes the table via FindZeroResultIndex. Invoked from pit-stop tire-compound decision and a mode-based dispatch.
    // GUARD: If the entry selector a2 equals 2, call FindZeroResultIndex(this) first, normalizing the table before the decrement [callee:0x004A57F0, source:raw]
    // CALCULATION: Compute the entry base as this + 16*a2 DWORDs (64-byte stride table indexing); the index field lives at base+44 and the bound at base+40 [source:raw]
    // ASSIGNMENT: Read the index at base+44, subtract 1, and write it back [source:raw]
    // GUARD: If the decremented index is less than zero, wrap it: to bound-1 when the flag byte at base+53 is set, otherwise to 0, and write the wrapped value back to base+44 [source:raw]
    // RETURN: For selector a2 == 0 return the result of ConditionalDispatch_55e0(this) instead of the entry pointer; otherwise return the computed entry base. Called from PitStopDecisionTireCompound and ModeBasedDispatch [callee:0x004A55E0, caller:0x0042A3D0, caller:0x0049F790, function:0x004A57A0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 2) FindZeroResultIndex(this);
    //   base = (char*)this + 64 * a2;
    //   idx = *(int*)(base + 44) - 1;
    //   if (idx < 0) idx = *(char*)(base + 53) ? *(int*)(base + 40) - 1 : 0;
    //   *(int*)(base + 44) = idx;
    //   return (a2 == 0) ? ConditionalDispatch_55e0(this) : (void*)base;
    // UNRESOLVED: Why entry 0 returns a conditional dispatch call instead of its own base pointer is not explained by this function's evidence
    // UNRESOLVED: The meaning of the flag byte at base+53 (which selects the bound-1 vs 0 wrap direction) is not documented
}
