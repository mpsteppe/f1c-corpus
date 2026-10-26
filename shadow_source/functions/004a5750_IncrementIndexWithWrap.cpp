// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5750
// Canonical corpus name: UtilityFunction_5750
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_5750_004a5750.c

void UnknownObject::IncrementIndexWithWrap()
{
    // Increments a per-entry index stored in a table whose stride is 64 bytes (this + 16*a2 DWORDs), then applies a wrap so the index stays below a per-entry bound. Entry 0 of the table is special: for selector a2 == 0 the function returns a conditional dispatch call on the container instead of the entry pointer, and for selector a2 == 2 it first normalizes the table via FindZeroResultIndex. Invoked from pit-stop tire-compound decision and a mode-based dispatch.
    // GUARD: If the entry selector a2 equals 2, call FindZeroResultIndex(this) first, normalizing the table before the increment [callee:0x004A57F0, source:raw]
    // CALCULATION: Compute the entry base as this + 16*a2 DWORDs (64-byte stride table indexing); the index field lives at base+44 and the bound at base+40 [source:raw]
    // ASSIGNMENT: Read the index at base+44, add 1, and write it back [source:raw]
    // GUARD: If the incremented index is not less than the bound at base+40, wrap it: to 0 when the flag byte at base+53 is set, otherwise to bound-1, and write the wrapped value back to base+44 [source:raw]
    // RETURN: For selector a2 == 0 return the result of ConditionalDispatch_55e0(this) instead of the entry pointer; otherwise return the computed entry base. Called from PitStopDecisionTireCompound and ModeBasedDispatch [callee:0x004A55E0, caller:0x0042A3D0, caller:0x0049F790, function:0x004A5750, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 2) FindZeroResultIndex(this);
    //   base = (char*)this + 64 * a2;
    //   idx = *(int*)(base + 44) + 1;
    //   if (idx >= *(int*)(base + 40)) idx = *(char*)(base + 53) ? 0 : *(int*)(base + 40) - 1;
    //   *(int*)(base + 44) = idx;
    //   return (a2 == 0) ? ConditionalDispatch_55e0(this) : (void*)base;
    // UNRESOLVED: Why entry 0 returns a conditional dispatch call instead of its own base pointer is not explained by this function's evidence
    // UNRESOLVED: The meaning of the flag byte at base+53 (which selects the 0 vs bound-1 wrap direction) is not documented
}
