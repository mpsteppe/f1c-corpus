// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AE90
// Canonical corpus name: StateFlagsLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateFlagsLookup_0042ae90.c

void UnknownObject::StateFlagsLookup()
{
    // Read-only table getter. Reads the state selector from this[4450] (dword at byte offset 0x4588), normalizes it to a 1-based index, selects a base dword index of 1113, and returns the dword table entry at dword index (4 * base), i.e. this[4 * ((selector - 1 < 0) ? 1113 : 1113 + selector - 1)]. Invoked by sub_4A4110, EngineFailureCheck and AIBehaviorInitialization.
    // CALCULATION: Load the state selector from this[4450], the dword at byte offset 0x4588. [field:this:0x00004588, source:raw]
    // GUARD: Selection guard: when (selector - 1) < 0 the base table index is 1113; otherwise the base is 1113 + selector - 1. [source:raw]
    // CALCULATION: Effective dword address = 4 * base, indexing this at dword index 1113 or 1113 + selector - 1. [source:raw]
    // RETURN: Return the dword entry at this[4 * base]; when the selector is 0 or negative this is the entry at dword index 1113. [function:0x0042AE90, source:raw]
    // CALL: Invoked by sub_4A4110 (004A4110), EngineFailureCheck (004BEC55) and AIBehaviorInitialization (004BF0A0) to fetch a per-state flag/selector value. [caller:0x004A4110, caller:0x004BEC55, caller:0x004BF0A0]

    // Conservative worker pseudocode:
    //   int state = this[4450]; /* dword at byte offset 0x4588 * /
    //   int base = (state - 1 < 0) ? 1113 : 1113 + state - 1;
    //   return this[4 * base];
    // UNRESOLVED: The returned dword table (entries starting at dword index 1113) has unknown length and element semantics; only the single selector field at 0x4588 is captured by the packet.
    // UNRESOLVED: Whether dword index 1113 corresponds to a default/sentinel state when the selector is 0 or negative is not provable from this packet alone.
}
