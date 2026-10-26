// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00433890
// Canonical corpus name: AISettingsFileResolver
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AISettingsFileResolver_00433890.c

void UnknownObject::AISettingsFilePathResolver()
{
    // Resolves the full AI settings file path into caller buffer a1. Chooses a base directory (dword_7CE5EC, falling back to byte_5EA438), validates it with SeasonRacesSectionFinder (returns 1 on failure), then locates a settings data entry by string key from lookup tables off_5C3FA8, off_5C3FB0 and, when IterationCountMap(dword_7C56A4) equals 5, off_5C3FAC, taking the first found via DataEntryAccessor. Returns 1 if no entry is found. Copies the base directory into a local buffer (dword_5EC440 or byte_5EA438), appends the data entry with strcat, copies the result into a1 via sub_587DD0 with capacity a2-1, null-terminates a1[a2-1], and returns 0.
    // ASSIGNMENT: a1[0] = 0: clear/null-terminate the output buffer before resolving. [field:this:0x00000000, function:0x00433890, source:raw]
    // GUARD: Choose base directory: v2 = dword_7CE5EC, or &byte_5EA438 if dword_7CE5EC is null. [global:0x007CE5EC, global:0x005EA438, source:raw]
    // GUARD: if (!SeasonRacesSectionFinder(v2)) return 1: fail when the season/races section lookup fails. [callee:0x004C5840, function:0x00433890, source:raw]
    // CALL: v4 = StringKeyedLinkedListSearch(off_5C3FA8[0]); if non-null v3 = DataEntryAccessor(v4) — first candidate settings entry. [global:0x005C3FA8, callee:0x005679C0, callee:0x00567970, source:raw]
    // CALL: v5 = StringKeyedLinkedListSearch(off_5C3FB0); if non-null v3 = DataEntryAccessor(v5) — second candidate settings entry. [global:0x005C3FB0, callee:0x005679C0, callee:0x00567970, source:raw]
    // GUARD: If IterationCountMap(dword_7C56A4) == 5 (session iteration count), v6 = StringKeyedLinkedListSearch(off_5C3FAC[0]) and if non-null v3 = DataEntryAccessor(v6) — session-specific entry. [global:0x007C56A4, global:0x005C3FAC, callee:0x00432E50, callee:0x005679C0, callee:0x00567970, source:raw]
    // GUARD: if (!v3) return 1: fail when no settings entry was found in any lookup table. [function:0x00433890, source:raw]
    // ASSIGNMENT: Copy the settings directory string v7 (dword_5EC440, or &byte_5EA438 if null) into the local path buffer v11. [global:0x005EC440, global:0x005EA438, source:raw]
    // CALCULATION: strcat(v11, v3): append the selected data entry string to the local path buffer. [source:raw]
    // CALL: sub_587DD0(a1, v11, a2 - 1): copy the resolved path into the output buffer with capacity a2-1, then a1[a2-1] = 0 to null-terminate. [callee:0x00587DD0, field:this:0x00000000, function:0x00433890, source:raw]
    // RETURN: return 0 on success (1 on section lookup or entry-lookup failure). [function:0x00433890, source:raw]

    // Conservative worker pseudocode:
    //   a1[0] = 0;
    //   base = dword_7CE5EC ? dword_7CE5EC : &byte_5EA438;
    //   if (!SeasonRacesSectionFinder(base)) return 1;
    //   entry = 0;
    //   node = StringKeyedLinkedListSearch(off_5C3FA8[0]); if (node) entry = DataEntryAccessor(node);
    //   node = StringKeyedLinkedListSearch(off_5C3FB0);    if (node) entry = DataEntryAccessor(node);
    //   if (IterationCountMap(dword_7C56A4) == 5) { node = StringKeyedLinkedListSearch(off_5C3FAC[0]); if (node) entry = DataEntryAccessor(node); }
    //   if (!entry) return 1;
    //   dir = dword_5EC440 ? dword_5EC440 : &byte_5EA438;
    //   copy(dir, v11);
    //   strcat(v11, entry);
    //   sub_587DD0(a1, v11, a2 - 1);
    //   a1[a2 - 1] = 0;
    //   return 0;
    // UNRESOLVED: global:0x008AC368 (unk_8AC368) is listed in the packet globals but absent from the raw source; assumed VehicleSetupBase via existing analysis, unverified.
    // UNRESOLVED: Keys and meaning of the off_5C3FA8 / off_5C3FB0 / off_5C3FAC lookup tables, and why the session iteration count of 5 selects off_5C3FAC, are unconfirmed.
    // UNRESOLVED: The local path buffer is 256 bytes; strcat into it assumes the concatenated base-dir plus entry string fits within that size.
}
