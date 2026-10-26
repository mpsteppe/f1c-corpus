// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C18B0
// Canonical corpus name: PlayerCareerStatsGameOptionsLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerCareerStatsGameOptionsLoader_004c18b0.c

void UnknownObject::PlayerCareerStatsGameOptionsLoader()
{
    // Loads player career statistics and game options from save data, building two linked lists anchored in this: a primary list of career-season records (head this+0x0, tail this+0x4, sentinel this+0x8, count this+0xC) and a secondary list of track/directory records (head this+0x10, tail this+0x14, sentinel this+0x18, count this+0x1C). Iterates config tokens via ConditionalDispatchBasedOnFlag over the unk_8AC1E8 token buffer; the CareerSeason token allocates and reads a season record and appends a 12-byte node; the PlayerTrackStats token recurses into itself; the default token branch parses career-summary counters, float averages (this+0x44/0x48/0x4C/0x50), mechanical-failure, race-condition and game-option values via the shared sub_565xxx tuple parsers. After the loop it deduplicates the track record through LinkedListSearchByName and frees the header on a hit, otherwise appends the track header as a node in the secondary list.
    // GUARD: Guard on the caller-supplied argument a2: if *a2 is 0, return 0 immediately (no save state to load). [source:raw]
    // CALL: Allocate a 24-byte track/directory header via OperatorNewNhMallocWrapper; if non-null initialize it with AlternatingInit, else leave the header pointer 0. [callee:0x00587C03, callee:0x004C03A0, source:raw]
    // LOOP: Iterate config tokens: while ConditionalDispatchBasedOnFlag(&unk_8AC1E8, 256) is true, dispatch on the current token. [callee:0x00566CC0, global:0x008AC1E8, source:raw]
    // CALL: Read the next token/record discriminator v5 from the token buffer via sub_5651B0(&unk_8AC050). [callee:0x005651B0, global:0x008AC050, source:raw]
    // GUARD: If v5 is 0 or v5 is 4 (v7 = v5 - 1; v7 == 0 or v7 == 3), break out of the token loop. [source:raw]
    // GUARD: Match the CareerSeason token: sub_587C20(&unk_8AC1E8, aCareerseason) selects the career-season branch. [callee:0x00587C20, global:0x008AC1E8, global:0x005D2B28, source:raw]
    // CALL: Allocate a 45396-byte career-season record via OperatorNewNhMallocWrapper and initialize it with AudioSubsystemInitializer. [callee:0x00587C03, callee:0x004C0AB0, source:raw]
    // CALL: Read the season state from the save data via CareerSeasonStateFileReader on the allocated record with a2. [callee:0x004C0B70, source:raw]
    // GUARD: If the read succeeded and the record is non-null, allocate a 12-byte list node (node[0] = record, node[4] = 0, node[8] = 1). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Append the node to the primary linked list: if the head (this+0x0) is non-null write the node at tail(this+0x4)+4; otherwise set head this+0x0 and sentinel this+0x8 to the node; always set tail this+0x4 to the node and increment the count at this+0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:*(this+0x4):0x00000004, source:raw]
    // CALL: If the season read failed but the record was allocated, release it via PitStopMemoryCleanup and FreeWrapper_7bcf. [callee:0x004C0B10, callee:0x00587BCF, source:raw]
    // GUARD: Match the PlayerTrackStats token: sub_587C20(&unk_8AC1E8, aPlayertracksta) selects the track-stats branch. [callee:0x00587C20, global:0x008AC1E8, global:0x005D2B14, source:raw]
    // CALL: Track-stats branch: recursively call this loader (callee 0x004C18B0) on a2 to process the nested track statistics. [callee:0x004C18B0, source:raw]
    // CALL: Default token branch: parse the career-summary integer counters (aAbortedseasons, aTotallaps, aTotalraces, aTotalraceswith, aTotalpointssco, aTotalchampions, aTotalwins, aTotalpoles, aTotallaprecord) into the career counter scalar fields via sub_565760. [callee:0x00565760, global:0x005D2B04, global:0x005D2AF8, global:0x005D2AEC, global:0x005D2AD8, global:0x005D2AC4, global:0x005D2AB0, global:0x005D2AA4, global:0x005D2A98, global:0x005D2A88, source:raw]
    // CALL: Parse the four career float averages (aAvgstartpositi, aAvgfinishposit, aAvgracedistanc, aAvgopponentstr) via sub_565520 plus sub_58850F into fields this+0x44, this+0x48, this+0x4C and this+0x50. [callee:0x00565520, callee:0x0058850F, global:0x005D2A74, global:0x005D2A60, global:0x005D2A50, global:0x005D2A3C, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // CALL: Parse the mechanical failure rate (aMechfailRate) via sub_565760 into the dword at this+0x54 when the parse succeeds. [callee:0x00565760, global:0x005D2A2C, field:this:0x00000054, source:raw]
    // CALL: Parse the race-condition options (aRacecondReconn, aRacecondWalkth, aRacecondFormat, aRacecondFlagRu, aRacecondWeathe) via sub_565760; the weather value lands in the dword at this+0x68 and the timescale value (aRacecondTimesc) is stored as a boolean byte at this+0x6C. [callee:0x00565760, global:0x005D2A14, global:0x005D29FC, global:0x005D29E8, global:0x005D29D4, global:0x005D29C0, global:0x005D29A4, field:this:0x00000068, field:this:0x0000006C, source:raw]
    // CALL: Parse the game options (aGameoptQualify, aGameoptRaceLap, aGameoptRaceTim, aGameoptRaceLen, aGameoptOpponen, aGameoptFuelMul, aGameoptTireMul, aGameoptSpeedCo) into the game-option scalar fields via sub_565760 and sub_565870. [callee:0x00565760, callee:0x00565870, global:0x005D298C, global:0x005D2978, global:0x005D2964, global:0x005D2950, global:0x005D293C, global:0x005D2928, global:0x005D2914, global:0x005D2900, source:raw]
    // CALL: Parse the total-laps and best-lap-time track stats (aTotalnumlaps, aBestlaptime) into the track header v4 fields via sub_565760 and sub_565870. [callee:0x00565760, callee:0x00565870, global:0x005D28F0, global:0x005D28E4, source:raw]
    // CALL: Parse the track name and track file strings (aTrackname_0, aTrackfile) via sub_5654A0 and copy them with StringCopyWithBufferRealloc when present. [callee:0x005654A0, callee:0x00566650, global:0x005D28D8, global:0x005D28CC, source:raw]
    // GUARD: After the token loop, pick the lookup key from track header field v4[2], falling back to the default byte_5EA438, and search the existing records with LinkedListSearchByName. [callee:0x004C2860, global:0x005EA438, source:raw]
    // GUARD: If LinkedListSearchByName found an existing entry, free the track header (v4[2], *v4, then v4) via FreeWrapper_7bcf and return 0 without inserting. [callee:0x00587BCF, source:raw]
    // GUARD: If no track header was allocated (v4 is null), return 0. [source:raw]
    // ASSIGNMENT: Allocate a 12-byte track-list node via OperatorNewNhMallocWrapper and populate node[0] = v4, node[4] = 0, node[8] = 1. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Append the node to the secondary linked list: if the head (this+0x10) is non-null write the node at tail(this+0x14)+4; otherwise set head this+0x10 and sentinel this+0x18 to the node; always set tail this+0x14 to the node and increment the count at this+0x1C. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:*(this+0x14):0x00000004, source:raw]
    // RETURN: Return 0 on all success paths. [source:raw]

    // Conservative worker pseudocode:
    //   char PlayerCareerStatsGameOptionsLoader(F1CStatsStore* this, char* a2) {
    //     if (!*a2) return 0;
    //     TrackHeader* v4 = OperatorNewNhMallocWrapper(24);
    //     if (v4) AlternatingInit(v4); else v4 = 0;
    //     while (ConditionalDispatchBasedOnFlag(&unk_8AC1E8, 256)) {
    //       int v5 = sub_5651B0(&unk_8AC050);
    //       if (v5) { int v7 = v5 - 1; if (!v7 || v7 == 3) break; }
    //       else if (sub_587C20(&unk_8AC1E8, aCareerseason)) {
    //         record = AudioSubsystemInitializer(OperatorNewNhMallocWrapper(45396));
    //         if (CareerSeasonStateFileReader(record, a2) && record) {
    //           node = OperatorNewNhMallocWrapper(12);
    //           node[0] = record; node[1] = 0; node[2] = 1;
    //           append_to_list(this, 0x0, 0x4, 0x8, 0xC, node);
    //         } else if (record) { PitStopMemoryCleanup(record); FreeWrapper_7bcf(record); }
    //       }
    //       else if (sub_587C20(&unk_8AC1E8, aPlayertracksta)) PlayerCareerStatsGameOptionsLoader(a2);
    //       else parse_default_tokens(this, v4);
    //     }
    //     key = v4[2] ? v4[2] : byte_5EA438;
    //     if (LinkedListSearchByName(key)) { if (v4) { if (v4[2]) FreeWrapper_7bcf(v4[2]); if (v4[0]) FreeWrapper_7bcf(v4[0]); FreeWrapper_7bcf(v4); } return 0; }
    //     if (!v4) return 0;
    //     node = OperatorNewNhMallocWrapper(12); node[0] = v4; node[1] = 0; node[2] = 1;
    //     append_to_list(this, 0x10, 0x14, 0x18, 0x1C, node);
    //     return 0;
    //   }
    // UNRESOLVED: The token-dispatch semantics of sub_5651B0 and sub_587C20 over the unk_8AC1E8 buffer, and the meaning of discriminator values 0, 4 and the special values that break the loop, are unknown.
    // UNRESOLVED: The recursion on a2 (callee 0x004C18B0) passes a2 as the receiving object; whether a2 is a second stats store or a sub-scope of the save data is unresolved.
    // UNRESOLVED: The exact structure of the 45396-byte season record and of a2's first dword (the *a2 == 0 guard) are unknown.
    // UNRESOLVED: The config/INI key semantics behind the 39 string globals (aTrackfile...aCareerseason) and the byte_5EA438 default lookup key are inferred from names only.
    // UNRESOLVED: The full format-spec contracts of the shared parsers sub_565760, sub_565520, sub_5654A0, sub_565870 and sub_58850F are not modeled here.
    // UNRESOLVED: The career counter and game-option scalar fields written by the default branch have no packet field references; their offsets are not asserted.
    // UNRESOLVED: The distinction between the two linked lists (career-season records vs track/directory records) is DERIVED from the token names, not packet evidence.
}
