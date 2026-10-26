// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D75D0
// Canonical corpus name: TireSlipCurveNameLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireSlipCurveNameLookup_004d75d0.c

void UnknownObject::TireSlipCurveNameLookup()
{
    // Searches a tire slip curve name table for an entry whose name matches a2. Reads entry count this[0x8] and the entry-array base this[0xC]; iterates with a 24-byte stride, comparing each entry name (falling back to byte_5EA438 when the name pointer is null) via sub_588410. Returns this[0xC] + 24*v3 for the matching entry, or 0 when the table is empty or exhausted (optionally logging a tire-brand-not-found error through StringSplitLoop/DebugLogWrite).
    // ASSIGNMENT: Initialize the entry index counter v3 = 0. [source:raw]
    // GUARD: Empty-table guard: if this[0x8] <= 0 there are no slip curve name entries; jump to the not-found error path. [field:this:0x00000008, guard:0, source:raw]
    // LOOP: Iterate the name table: v4 = 0, while v3 < this[0x8], stepping v4 by 24 bytes per entry. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Load the entry name pointer v5 = *(char **)(v4 + this[0xC]); if it is null, substitute the default byte_5EA438. [field:this:0x0000000C, global:0x005EA438, source:raw]
    // CALL: Compare the queried name against the entry name: sub_588410(a2, v5); returns 0 on equality. [callee:0x00588410, source:raw]
    // GUARD: Match guard: if sub_588410 reports equality, return the entry address this[0xC] + 24*v3. [field:this:0x0000000C, source:raw]
    // CALCULATION: Advance to the next entry: v3 += 1 and v4 += 24. [source:raw]
    // GUARD: Loop-exhaustion guard: when v3 >= this[0x8], no entry matched; fall through to the not-found error path. [field:this:0x00000008, source:raw]
    // CALL: Not-found error logging: if StringSplitLoop(1, aDDevF119992002_4, 995) returns nonzero, DebugLogWrite(&dword_8AD25C, aTireBrandDoesn_0). [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D45E4, global:0x005D497C, global:0x008AD25C, source:raw]
    // RETURN: Return 0 when the table is empty or no entry matches a2. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D75D0(_DWORD *self, int name) {
    //     int v3 = 0;
    //     if ((int)self[2] <= 0) goto not_found;
    //     int v4 = 0;
    //     for (;;) {
    //       char *v5 = *(char **)(v4 + self[3]);
    //       if (!v5) v5 = byte_5EA438;
    //       if (!sub_588410(name, v5)) return self[3] + 24 * v3;
    //       ++v3; v4 += 24;
    //       if (v3 >= self[2]) break;
    //     }
    //   not_found:
    //     if ((unsigned __int8)StringSplitLoop(1, aDDevF119992002_4, 995))
    //       DebugLogWrite(&dword_8AD25C, aTireBrandDoesn_0);
    //     return 0;
    //   }
    // UNRESOLVED: sub_588410's exact comparison semantics (case sensitivity, path awareness) are visible only through its return-0-on-equality contract and are not established by the packet.
    // UNRESOLVED: byte_5EA438's role as a default/fallback name is inferred from its substitution when an entry name pointer is null.
    // UNRESOLVED: aDDevF119992002_4 is passed as a source-path argument to StringSplitLoop along with the literal 995, matching a debug-source validation pattern, but the exact role of the literal 995 is not established by the packet.
}
