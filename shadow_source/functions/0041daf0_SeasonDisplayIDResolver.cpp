// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041DAF0
// Canonical corpus name: SeasonDisplayIDResolver
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonDisplayIDResolver_0041daf0.c

void UnknownObject::SeasonDisplayIDResolver()
{
    // Dispatches season/championship results display messages (ids 478-503) into the shared driver data table: emits a base message-478 entry, then in race-session mode returns early when no best-lap entrant exists, otherwise selects between season standings messages (490-503, chosen by which track database version files are present under the season path via sub_588410) and leader/best-lap messages (479/480/481/397, chosen by scoring-aggregator equality, championship score, and a CRT time comparison), resolves each entrant's display id through NamedEntryLookupInFormatList against the format list dword_5EA5E8 with byte_5EA438 as the null fallback, and finalizes with InsertDriverTableEntry plus PositionChangeDetector.
    // GUARD: Early guard: proceed only when dword_7D0308 (race active flag) is non-zero and flt_7CF3C8 (track condition state) is non-zero; otherwise the function performs no work. [global:0x007D0308, global:0x007CF3C8, source:raw]
    // CALL: Initialize the local driver-table entry buffer v91 with sentinel/default values via StructInitWithSentinelValues. [callee:0x004144D0, source:raw]
    // CALL: Populate v91 as a driver-data entry with message id 478 and sentinel arguments -1 and -2.0 via DriverDataTableLookupAndTimeConversion. [callee:0x004144F0, source:raw]
    // CALL: Insert the message-478 entry into the shared driver table target flt_5EA618 via InsertDriverTableEntry. [callee:0x00418560, global:0x005EA618, source:raw]
    // CALL: Re-initialize v91 with sentinel values before the per-entrant message dispatch. [callee:0x004144D0, source:raw]
    // CALL: Find the best-lap entrant in the standings via BestLapEntrantFinder(0, 0), kept in v3; a null result means no best-lap entrant exists. [callee:0x0041E920, source:raw]
    // CALL: Fetch the session scoring aggregator via ScoringSessionStatsAggregator(0, 0) into v4. [callee:0x0041EB30, source:raw]
    // CALL: Dereference the race-standings sort buffer dword_7D2DB0 via LinkedListDereference to obtain the standings list node. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // GUARD: Branch on the standings node's session flags: FlagsGetter(node) equal to 1 selects the race-session path; otherwise the standings/season path is taken. [callee:0x004C11D0, source:raw]
    // GUARD: On the race-session path, return immediately when no best-lap entrant was found (v3 null); this early return bypasses the final driver-table insert and position-change dispatch. [source:raw]
    // GUARD: On the standings path, when the dword at node offset 45380 equals 3, enter the season display branch (message ids 490/494/498/502 for a single entrant or 491/495/499/503 for champion and runner-up, selected by the track database version files that exist). [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // LOOP: When no best-lap entrant exists in season mode, iterate the standings entries (entry index from ShortComputation_13a0 while the index stays below the ActiveEntityCounter count), skip entries whose dword at offset 412 is zero via FixedOffsetReturn, and track the top two entries v21/v22 using ObjectComparisonWithTiebreak to resolve ties. [callee:0x004C1370, callee:0x004C13A0, callee:0x004C1390, callee:0x0041EF40, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: Single-entrant season dispatch: test the season path (dword_7D0434, falling back to byte_5EA438) against the track database version filenames aF11999Gdb, aF12000Gdb, aF12001Gdb and aF12002Gdb via sub_588410, and for the matched version emit message 490, 494, 498 or 502 for the best-lap entrant. [callee:0x00588410, global:0x007D0434, global:0x005EA438, global:0x005BF994, global:0x005BF988, global:0x005BF97C, global:0x005BF970, source:raw]
    // CALL: Two-entrant season dispatch: apply the same database-version cascade and emit message 491, 495, 499 or 503 for champion v21 together with runner-up v22 when present, else a single message (502, 498, 494 or 490) for v21 alone. [callee:0x00588410, global:0x007D0434, global:0x005EA438, global:0x005BF994, global:0x005BF988, global:0x005BF97C, global:0x005BF970, source:raw]
    // GUARD: When not in season mode, proceed only if the scoring aggregator is non-null (v4, or retried via ScoringSessionStatsAggregator(0, 1)); then branch on whether the best-lap entrant v3 equals the scoring leader v4. [callee:0x0041EB30, source:raw]
    // CALCULATION: When v3 equals the scoring leader, compare best-lap timing: read the dword at v3+408 and at BestLapEntrantFinder(name, 1)+408, then compare CRTMathHelper-derived values; the comparison selects message 481, otherwise message 397 with argument 1. [callee:0x0041ED30, callee:0x0041E920, source:raw]
    // GUARD: When v3 differs from the scoring leader, gate the champion message on ChampionshipScore(v3): a non-zero championship score emits message 480, a zero score falls through to the default message 479. [callee:0x0041EDA0, source:raw]
    // CALL: Resolve the entrant's display id for the chosen message via NamedEntryLookupInFormatList against the format list dword_5EA5E8, using the entrant name (dword at +0, byte_5EA438 fallback) and team (pointer at +8, byte_5EA438 fallback), then emit the message through DriverDataTableLookupAndTimeConversion. [callee:0x00415230, callee:0x004144F0, global:0x005EA5E8, global:0x005EA438, source:raw]
    // CALL: Finalize on the shared exit path: insert the accumulated entry via InsertDriverTableEntry(flt_5EA618, v91) and dispatch position changes via PositionChangeDetector(0). [callee:0x00418560, callee:0x00420490, global:0x005EA618, source:raw]
    // RETURN: Return void; every completed path ends at the shared finalize block or the early race-session return. [function:0x0041DAF0, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7D0308 && flt_7CF3C8 != 0.0) {
    //     emit base message 478 entry (DriverDataTableLookupAndTimeConversion + InsertDriverTableEntry)
    //     node = LinkedListDereference(&dword_7D2DB0)
    //     if (FlagsGetter(node) == 1) { if (!bestLapEntrant) return; }
    //     else if (*(dword*)(LinkedListDereference(&dword_7D2DB0)+45380) == 3)
    //       season standings: emit 490/494/498/502 (single) or 491/495/499/503 (top two), selected by which aF11999Gdb/aF12000Gdb/aF12001Gdb/aF12002Gdb files exist under the season path
    //     else {
    //       if (!bestLapEntrant) goto finalize
    //       if (scoringLeader && (bestLapEntrant == scoringLeader))
    //         emit 481 or 397 (CRT time comparison)
    //       else if (ChampionshipScore(bestLapEntrant) != 0) emit 480
    //       else emit 479
    //     }
    //     finalize: InsertDriverTableEntry(flt_5EA618, v91); PositionChangeDetector(0);
    //   }
    // UNRESOLVED: flt_59E440 is listed in the static fact table as read but does not appear in the decompiled body; its claimed ZeroThreshold role is not grounded here.
    // UNRESOLVED: Semantics of message ids 397 and 478-503 are inferred from callee names and dispatch position only, not packet-confirmed.
    // UNRESOLVED: Meaning of standings node fields at offsets 408, 412 and 45380 (timing value, active flag, season-mode selector) is inferred from surrounding logic.
    // UNRESOLVED: What CRTMathHelper computes and the units of the two timed values being compared are unresolved.
    // UNRESOLVED: Owner is unknown: the packet carries no this pointer or object evidence for this function.
}
