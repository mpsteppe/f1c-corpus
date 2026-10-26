// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00420CF0
// Canonical corpus name: GdbSeasonSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GdbSeasonSelector_00420cf0.c

void UnknownObject::GdbSeasonSelector()
{
    // Season-database team selector. When `this` is null it allocates a temporary 8-byte working object, then selects the F1 team with the most active drivers (ChampionshipPointsAccumulator-scoped count via CountActiveEntitiesByState), tie-broken by ShortComputation_12e0, walking a 14-team name table (Arrows..Stewart). The winning team name then locates the correct season GDB file (aF11999Gdb..aF12002Gdb probed through sub_588410 on dword_7D0434), and DriverDataTableLookupAndTimeConversion fills a sentinel-initialized driver record (season index 492/496/500/504) after a LinkedListIndexScannerWithValidation over dword_5EA5E8 keyed on the selected name; InsertDriverTableEntry publishes it into the global table via flt_5EA618. Called from ScoringClassificationDisplay (0041E320).
    // GUARD: When `this` is null, allocate an 8-byte working object via OperatorNewNhMallocWrapper(8); on success initialize obj[0]=0 and obj[1]=-1, otherwise leave the pointer null. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Zero the 14-entry candidate arrays v36 and v37, clear counters v33 and the tie flags v31/v13, and fetch the seed team-name list from sub_41F340(0,1); an empty seed name falls back to byte_5EA438. [callee:0x0041F340, global:0x005EA438, source:raw]
    // CALL: Compute the reference points v9 = ChampionshipPointsAccumulator(seedName, -1) against which every team's active-driver count is measured. [callee:0x0041F220, source:raw]
    // LOOP: First selection pass over the 14 teams: copy each team's name via StringCopyWithBufferRealloc (Arrows, off_5C25E0, Renault, Ferrari, Jaguar, Jordan, Mclaren, Minardi, Prost, Sauber, Williams, Toyota, Benetton, Stewart) and, when ChampionshipPointsAccumulator(empty, -1) equals v9, record the active-driver count from CountActiveEntitiesByState into v36 and track the maximum (v5=team, v2=count). [callee:0x00566650, global:0x005C25F4, global:0x005C25E0, global:0x005C25C4, global:0x005C2618, global:0x005C25D8, global:0x005C2604, global:0x005C2620, global:0x005C25E4, global:0x005C25EC, global:0x005C25FC, global:0x005C260C, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, callee:0x0041F220, callee:0x00421380, global:0x005EA438, source:raw]
    // RETURN: If no team matched (v5 == -1) return 0 without loading any season. [source:raw]
    // LOOP: Tie scan over the first pass: if any other team j has v36[j] == v2, set the first-pass tie flag v31. [source:raw]
    // LOOP: Tie-break pass (v31 set): for each team k with v36[k] == v2, recompute the team name via StringCopyWithBufferRealloc and evaluate ShortComputation_12e0 into v37, tracking the maximum (v14=team, v33=metric). [callee:0x00566650, callee:0x004212E0, global:0x005C25F4, global:0x005C25E0, global:0x005C25C4, global:0x005C2618, global:0x005C25D8, global:0x005C2604, global:0x005C2620, global:0x005C25E4, global:0x005C25EC, global:0x005C25FC, global:0x005C260C, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, source:raw]
    // RETURN: If the tie-break produced no winner (v14 == -1) return 0. [source:raw]
    // LOOP: Second tie scan: if any other team m has v37[m] == v33, set the second tie flag v13. [source:raw]
    // CALL: When a second tie still holds (v13): copy the seed team name v18 (empty fallback byte_5EA438) via StringCopyWithBufferRealloc and free the temporary seed list v34 with FreeWrapper_7bcf. [callee:0x00566650, callee:0x00587BCF, global:0x005EA438, source:raw]
    // STATE_TRANSITION: Final team selection switch on the winning index v5 (no tie) or v14 (tie): map index 0..13 to the team-name literal (Arrows, off_5C25E0, Renault, Ferrari, Jaguar, Jordan, Mclaren, Minardi, Prost, Sauber, Williams, Toyota, Benetton, Stewart) via the jump tables at 0x00421200/0x00421238/0x00421270/0x004212A8 and feed it to StringCopyWithBufferRealloc. [global:0x00421200, global:0x00421238, global:0x00421270, global:0x004212A8, callee:0x00566650, global:0x005C25F4, global:0x005C25E0, global:0x005C25C4, global:0x005C2618, global:0x005C25D8, global:0x005C2604, global:0x005C2620, global:0x005C25E4, global:0x005C25EC, global:0x005C25FC, global:0x005C260C, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, source:raw]
    // CALL: Prepare the driver-data record with StructInitWithSentinelValues(v35), then select the season GDB by probing the season path dword_7D0434 (empty fallback byte_5EA438) through sub_588410 against aF11999Gdb, aF12000Gdb, aF12001Gdb and aF12002Gdb in order, choosing the season index 492, 496, 500 or 504. [callee:0x004144D0, global:0x005EA438, global:0x007D0434, callee:0x00588410, global:0x005BF994, global:0x005BF988, global:0x005BF97C, global:0x005BF970, source:raw]
    // CALL: Resolve the season record: LinkedListIndexScannerWithValidation over the dword_5EA5E8 list keyed on the selected team name (empty fallback byte_5EA438), then DriverDataTableLookupAndTimeConversion(v35, seasonIndex, idx, -1, -1, -1, -2.0, -2.0) fills the driver table record. [global:0x005EA5E8, callee:0x00415550, field:this:0x00000000, callee:0x004144F0, global:0x005EA438, source:raw]
    // CALL: InsertDriverTableEntry(flt_5EA618, v35) publishes the filled driver record into the global driver table. [callee:0x00418560, global:0x005EA618, source:raw]
    // RETURN: Cleanup: when the temporary-object path was taken (v3 && v1), free *v1 and then v1 via FreeWrapper_7bcf; otherwise return the insert result. Called from ScoringClassificationDisplay (0041E320). [callee:0x00587BCF, caller:0x0041E320, source:raw]

    // Conservative worker pseudocode:
    //   char GdbSeasonSelector(this) {
    //     v32 = null;
    //     if (!this) {
    //       v32 = OperatorNewNhMallocWrapper(8);
    //       if (v32) { v32[0] = 0; v32[1] = -1; }
    //       seed = sub_41F340(0, 1);
    //       if (!seed) return 0;
    //       v9 = ChampionshipPointsAccumulator(seed[0] ?: byte_5EA438, -1);
    //       for (i in 0..13) {
    //         copy team name table[i];
    //         if (ChampionshipPointsAccumulator(byte_5EA438, -1) == v9) {
    //           v36[i] = CountActiveEntitiesByState();
    //           if (v36[i] > v2) { v2 = v36[i]; v5 = i; }
    //         }
    //       }
    //       if (v5 == -1) return 0;
    //       for (j in 0..13) if (j != v5 && v36[j] == v2) v31 = 1;
    //       if (v31) {
    //         for (k in 0..13) if (v36[k] == v2) {
    //           copy team name table[k];
    //           v37[k] = ShortComputation_12e0();
    //           if (v37[k] > v33) { v33 = v37[k]; v14 = k; }
    //         }
    //         if (v14 == -1) return 0;
    //         for (m in 0..13) if (m != v14 && v37[m] == v33) v13 = 1;
    //         if (v13) { copy seed name; free seed list; v1 = v32; goto load; }
    //         winner = v14;
    //       } else winner = v5;
    //       copy team name table[winner];
    //       v1 = v32;
    //     }
    //   load:
    //     StructInitWithSentinelValues(v35);
    //     season = 492;
    //     if (sub_588410(dword_7D0434 ?: byte_5EA438, aF11999Gdb)) { season = 496;
    //       if (sub_588410(..., aF12000Gdb)) { season = 500;
    //         if (sub_588410(..., aF12001Gdb)) {
    //           if (sub_588410(..., aF12002Gdb)) return result; season = 504;
    //         }
    //       }
    //     }
    //     idx = LinkedListIndexScannerWithValidation(&dword_5EA5E8, v1[0] ?: byte_5EA438);
    //     DriverDataTableLookupAndTimeConversion(v35, season, idx, -1, -1, -1, -2.0, -2.0);
    //     result = InsertDriverTableEntry(flt_5EA618, v35);
    //     if (v3 && v1) { if (v1[0]) free(v1[0]); return free(v1); }
    //     return result;
    //   }
    // UNRESOLVED: The semantics of the -2.0/-2.0 sentinel arguments and the 492/496/500/504 season constants passed to DriverDataTableLookupAndTimeConversion are not documented by this packet.
    // UNRESOLVED: The meaning of the 8-byte working object (obj[0]=0, obj[1]=-1) allocated when `this` is null is not recoverable from this function alone.
    // UNRESOLVED: The seed name from sub_41F340(0,1) and the driver whose points are compared by ChampionshipPointsAccumulator are not named within this function.
}
