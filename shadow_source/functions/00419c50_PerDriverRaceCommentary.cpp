// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00419C50
// Canonical corpus name: PerDriverRaceCommentary
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerDriverRaceCommentary_00419c50.c

void UnknownObject::PerDriverRaceCommentary()
{
    // Per-driver race-finish commentary generator. Guarded by race-active flag and non-zero track condition state, it initializes a local commentary-entry array, then branches on whether the finishing driver is the player. The player branch maps the current track name (via string comparison against 17 known track-name strings) to a track-specific commentary ID and emits it through the driver data table; non-player branches emit generic position-based IDs (261 for position 1, 260 for positions 2-5). In championship mode (value 4) an additional close-race/leader-gap check compares scene-order data to the best recorded lap and may emit a gap commentary ID (159).
    // GUARD: Race must be active: dword_7D0308 (RaceActiveFlag) must be nonzero, else the function does nothing. [global:0x007D0308]
    // GUARD: Track condition state flt_7CF3C8 must be non-zero before any commentary is generated. [global:0x007CF3C8]
    // CALL: Initialize the local commentary-entry array v13 with sentinel values via StructInitWithSentinelValues. [callee:0x004144D0]
    // GUARD: FinishState (this+0x4064) must equal 1 (finished) and noOfPenalties (this+0x4070) must be zero for a clean-finish commentary; other states blocked. [guard:0, field:this:0x00004064, field:this:0x00004070]
    // ASSIGNMENT: Read finishing position v1 from this+0x4060. [field:this:0x00004060, source:raw]
    // GUARD: Player check: the player's DriverID at dword_7C54E8 + 18580 (player-vehicle offset 0x4894) must equal this entry's DriverID at this+0x4894. [global:0x007C54E8, field:this:0x00004894]
    // GUARD: Player-finish branch requires finishing position v1 == 1. [field:this:0x00004060]
    // ASSIGNMENT: Default player commentary ID set to 167 (winner line). [source:raw]
    // GUARD: Track-specific player commentary only when ChampionshipMode/RaceMode dword_7D0410 is between 2 and 5. [global:0x007D0410]
    // CALCULATION: Resolve current scene record: v3 = dword_8AC490 + 396 * dword_8AC48C (scene array base plus stride-396 index); then v4 = v3 + 260 points at the track-name field. [global:0x008AC490, global:0x008AC48C, source:raw]
    // CALCULATION: Track-name switch: if v3 is nonzero, compare the track name at v4 against each of the 17 known track-name strings via sub_566810; a match selects a track-specific commentary ID (161 AlbertPark, 164 Interlagos, 175 Imola, 174 Monaco, 176 Barcelona, 165 Montreal, 166 MagnyCours, 169 Silverstone, 162 A1Ring, 168 Hockenheim, 170 Hungaroring, 163 Spa, 171 Monza, 160 Nurburgring, 173 Sepang, 172 Suzuka, 177 Indianapolis); otherwise the default 167 is kept. [callee:0x00566810, global:0x005C26E0, global:0x005C26D4, global:0x005C26CC, global:0x005C26C4, global:0x005C26B8, global:0x005C26AC, global:0x005C26A0, global:0x005C2694, global:0x005C2688, global:0x005C267C, global:0x005C2670, global:0x005C265C, global:0x005C2654, global:0x005C2648, global:0x005C2640, global:0x005C2638, global:0x005C2628]
    // ASSIGNMENT: Else branch (player finished outside position 1 in non-track-mapped modes): default commentary ID 158; upgraded to 157 when ChampionshipMode == 4 and position v1 > 6. [global:0x007D0410, field:this:0x00004060, source:raw]
    // CALL: Build the commentary table entry: DriverDataTableLookupAndTimeConversion(v13, commentaryId v2, position, sentinel params). [callee:0x004144F0, field:this:0x00004060]
    // CALL: Append the entry to the driver table: InsertDriverTableEntry(flt_5EA618, v13). [callee:0x00418560, global:0x005EA618]
    // GUARD: Close-race gap commentary only when ChampionshipMode dword_7D0410 == 4. [global:0x007D0410]
    // GUARD: Standings list (head dword_7D2DB0) must be non-empty: LinkedListDereference(&dword_7D2DB0) nonzero. [callee:0x004C2850, global:0x007D2DB0]
    // CALCULATION: Compute position gap v8 = SceneOrderReader(list node) - FlagsGetter(list node) - 1 from the standings list head. [callee:0x004C1190, callee:0x004C11D0, callee:0x004C2850]
    // GUARD: Gap commentary requires positionGap v8 > 1. [source:raw]
    // LOOP: Scan standings for the best recorded time: for i in [0, dword_5C329C - 1), dereference the standings list; when ShortComputation_13a0(i) is nonzero, check the byte at +432 (finished flag) and keep the maximum dword at +408 as v9 (bestTime). [callee:0x004C13A0, callee:0x004C2850, global:0x005C329C, source:raw]
    // GUARD: Leader-gap check: FixedOffsetReturn on the standings list head must be nonzero and its dword at +408 must exceed v9 + 10 * v8 (best time plus ten times the position gap). [callee:0x004C1390, callee:0x004C2850]
    // CALL: When the leader gap exceeds the threshold, emit close-race gap commentary ID 159 with the position gap v8, then InsertDriverTableEntry(flt_5EA618, v13). [callee:0x004144F0, callee:0x00418560, global:0x005EA618]
    // CALL: Non-player branch, position 1: emit generic winner commentary ID 261 using DriverID from this+0x489C, then InsertDriverTableEntry. [callee:0x004144F0, callee:0x00418560, field:this:0x0000489C]
    // CALL: Non-player branch, position v1 < 6: emit generic podium commentary ID 260 with position v1 and DriverID from this+0x489C, then InsertDriverTableEntry. [callee:0x004144F0, callee:0x00418560, field:this:0x00004060, field:this:0x0000489C]
    // RETURN: Function is void; returns after the guarded branches with no explicit value. [source:raw]

    // Conservative worker pseudocode:
    //   if (raceActive && trackCondition != 0.0f) {
    //     initWithSentinels(entry);
    //     if (finishState == 1 && penalties == 0) {
    //       if (playerDriverID == driverID) {
    //         if (position == 1) {
    //           cid = 167;
    //           if (mode in [2..5] && sceneRecord && trackName matches known track)
    //             cid = trackSpecificId;
    //           else if (mode == 4 && position > 6)
    //             cid = 157;
    //           emit(cid, position);
    //           if (mode == 4 && standingsGap() > 1 && leaderTime() > bestTime + 10 * gap)
    //             emit(159, gap);
    //         }
    //       } else {
    //         emit(position == 1 ? 261 : (position < 6 ? 260 : none), driverID);
    //       }
    //     }
    //   }
    // UNRESOLVED: Global 0x0059E440 (flt_59E440) is listed in the packet but does not appear in the raw source text for this function; no operation could be grounded for it.
    // UNRESOLVED: The exact meaning of offsets +408 (dword) and +432 (byte) on the standings linked-list nodes is DERIVED from decompiler output, not independently confirmed.
    // UNRESOLVED: dword_7D0410 is described by prior analysis as both ChampionshipMode and RaceMode; the exact mode semantics of the range checks (2..5, ==4) are not fully resolved.
    // UNRESOLVED: this+0x489C (a1[4647]) is passed as the driver identifier for non-player commentary IDs 260/261; its field role is inferred, not confirmed.
    // UNRESOLVED: ABI record 'Per_Driver_Race_Commentary' is LEGACY trust with a null prototype; not used as independent evidence.
    // UNRESOLVED: Caller RaceFinishHandler (0x004A0BA0) context is known but not examined for how this function is invoked.
}
