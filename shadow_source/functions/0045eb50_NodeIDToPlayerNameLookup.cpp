// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045EB50
// Canonical corpus name: NodeIDToPlayerNameLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NodeIDToPlayerNameLookup_0045eb50.c

void UnknownObject::NodeIDToPlayerNameLookup()
{
    // __thiscall lookup of a player-name string by node ID in a session player array. Reads the active entry count from this[3973] (offset 0x3E14), linearly searches the node-ID array at this + 3869 (offset 0x3C74) for the requested a2, and on a match returns the name entry pointer &this[35 * v3 + 230]. On an empty array, end-of-search, or count <= 0 it returns the empty name string asc_5C5DBC, optionally logging a 'could not find name' debug message (gated on dword_7C569C != 5). Called from NetCommSessionMessageDispatcher.
    // ASSIGNMENT: Load the active entry count from this[3973] (dword index of offset 0x3E14) into the loop bound. [field:this:0x00003E14, source:raw]
    // ASSIGNMENT: Initialize the search index v3 to 0. [source:raw]
    // GUARD: If the entry count is <= 0, skip the search entirely and take the failure path. [field:this:0x00003E14]
    // LOOP: Linear search over the node-ID array at this + 3869 (dword index of offset 0x3C74): compare *v4 against a2, advance the pointer and the index v3, and jump to the failure path when v3 reaches the count. [field:this:0x00003C74, field:this:0x00003E14]
    // RETURN: On a match return the name entry pointer &this[35 * v3 + 230] for the found node ID. [field:this:0x00003C74]
    // GUARD: Debug logging fires only when dword_7C569C != 5 (session type is not server). [global:0x007C569C]
    // CALL: Sanitize/format the debug message source with StringSplitLoop(1, aDDevF119992002_1, 3094) before logging. [callee:0x004D7A50, global:0x005C5CE4]
    // CALL: Write the 'could not find name' debug message into the buffer at dword_8AD25C via DebugLogWrite. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C5DC0]
    // RETURN: On the failure path return the empty name string asc_5C5DBC. [global:0x005C5DBC]

    // Conservative worker pseudocode:
    //   const char *NodeIDToPlayerNameLookup(_DWORD *this, int nodeId) {
    //     int count = this[3973];
    //     int i = 0;
    //     if (count > 0) {
    //       while (this[3869 + i] != nodeId) {
    //         if (++i >= count) goto fail;
    //       }
    //       return (const char *)&this[230 + 35 * i];
    //     }
    //   fail:
    //     if (dword_7C569C != 5) {
    //       StringSplitLoop(1, aDDevF119992002_1, 3094);
    //       DebugLogWrite(&dword_8AD25C, aCouldNotFindNa);
    //     }
    //     return asc_5C5DBC;
    //   }
    // UNRESOLVED: The relationship between the node-ID array at this + 3869 and the per-entry name records at this[35 * v3 + 230] is DERIVED from prior analysis; the exact record layout (stride 35 dwords, base index 230) is not confirmed by a struct definition here.
    // UNRESOLVED: The meaning of the aDDevF119992002_1 format source is not established beyond its use as a StringSplitLoop argument.
}
