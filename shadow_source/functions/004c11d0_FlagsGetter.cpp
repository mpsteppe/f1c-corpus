// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C11D0
// Canonical corpus name: FlagsGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagsGetter_004c11d0.c

void UnknownObject::FlagsGetter()
{
    // Thiscall getter that returns this[11346] (dword field at offset 0xB148) of the this object. Pure read, no side effects. Widely called by scoring, session, commentary, championship and race-standings computations (00419C50, 0041DAF0, 0041E320, 0041EB30, 0041ED30, 0041EDA0, 0041EF00, 0041EFE0, 0041F100, 0041F150, 0041F190, 0041F1E0, 0041F5D0, 0041F8A0, 0041FC60, 004203F0, 00421380, 004C0F60, 004C1050), which together read a shared flags/status field on a season/session record.
    // RETURN: Return this[11346], i.e. the dword field at offset 0xB148 of this [field:this:0x0000B148, source:raw]
    // CALL: Called by PerDriverRaceCommentary (00419C50) [caller:0x00419C50, source:raw]
    // CALL: Called by SeasonDisplayIDResolver (0041DAF0) [caller:0x0041DAF0, source:raw]
    // CALL: Called by ScoringClassificationDisplay (0041E320) [caller:0x0041E320, source:raw]
    // CALL: Called by ScoringSessionStatsAggregator (0041EB30) [caller:0x0041EB30, source:raw]
    // CALL: Called by CRTMathHelper (0041ED30) [caller:0x0041ED30, source:raw]
    // CALL: Called by ChampionshipScore (0041EDA0) [caller:0x0041EDA0, source:raw]
    // CALL: Called by ArrayScanForValue10 (0041EF00) [caller:0x0041EF00, source:raw]
    // CALL: Called by CountMatchingSeasonEntries (0041EFE0) [caller:0x0041EFE0, source:raw]
    // CALL: Called by TripleValueEqualityCheck (0041F100) [caller:0x0041F100, source:raw]
    // CALL: Called by SeasonRaceCountCheck (0041F150) [caller:0x0041F150, source:raw]
    // CALL: Called by ShortComputation_f190 (0041F190) [caller:0x0041F190, source:raw]
    // CALL: Called by ShortComputation_f1e0 (0041F1E0) [caller:0x0041F1E0, source:raw]
    // CALL: Called by sub_41F5D0 (0041F5D0) [caller:0x0041F5D0, source:raw]
    // CALL: Called by ConstructorChampionshipClinchDetection (0041F8A0) [caller:0x0041F8A0, source:raw]
    // CALL: Called by SessionStateSearch (0041FC60) [caller:0x0041FC60, source:raw]
    // CALL: Called by sub_4203F0 (004203F0) [caller:0x004203F0, source:raw]
    // CALL: Called by CountActiveEntitiesByState (00421380) [caller:0x00421380, source:raw]
    // CALL: Called by RaceStandingsRankingsComputation (004C0F60) [caller:0x004C0F60, source:raw]
    // CALL: Called by sub_4C1050 (004C1050) [caller:0x004C1050, source:raw]

    // Conservative worker pseudocode:
    //   return this->dword_0xB148;
    // UNRESOLVED: The class of the this object and the meaning of the dword at 0xB148 are not established; the caller set (commentary, scoring, championship, session-state) suggests a season/session record holding a flags field, but that owner is not verifiable from this packet
}
