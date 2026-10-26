// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00420820
// Canonical corpus name: ConstructorStandingsParser
// Owner: UnknownObject [DERIVED]
// Raw source: functions/ConstructorStandingsParser_00420820.c

void UnknownObject::ParseConstructorStandings()
{
    // Parses constructor team standings: accumulates championship points for the 14 F1 teams into a local array, selects the top three teams with strict value ordering plus tie detection, emits the podium team names via StringCopyWithBufferRealloc, and — when a1 is set — builds driver display-table entries (IDs 423, 424, or combined 488) through DriverDataTableLookupAndTimeConversion and InsertDriverTableEntry. Returns 0 on every path. Called by ScoringClassificationDisplay.
    // ASSIGNMENT: Initialize local maxima v1 = -1, v22 = -1, v3 = -1, loop index v2 = 0, and zero the 14-dword points array v24 via memset. [function:0x00420820, source:raw]
    // LOOP: Iterate team index v2 from 0 to 13. For each index a switch on v2 (jump table jpt_420875) selects that constructor's name string from the 14 team literals (Arrows, off_5C25E0, Renault, Ferrari, Jaguar, Jordan, McLaren, Minardi, Prost, Sauber, Williams, Toyota, Benetton, Stewart) and copies it via StringCopyWithBufferRealloc. Loop exits when v2 reaches 14. [function:0x00420820, callee:0x00566650, global:0x00420C44, global:0x005C25F4, global:0x005C25E0, global:0x005C25C4, global:0x005C2618, global:0x005C25D8, global:0x005C2604, global:0x005C2620, global:0x005C25E4, global:0x005C25EC, global:0x005C25FC, global:0x005C260C, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, source:raw]
    // CALCULATION: v24[v2++] = ChampionshipPointsAccumulator((int)&byte_5EA438, -1): accumulate the constructor's championship points and store into the per-team points array. [function:0x00420820, callee:0x0041F220, global:0x005EA438, source:raw]
    // LOOP: Scan all 14 entries of v24 tracking the running maximum v1 and its index v22; each strictly larger value updates both (v22 = i, v1 = v24[i]). [function:0x00420820, source:raw]
    // LOOP: Scan v24 for the second-largest value: index j must differ from v22 and satisfy v3 < v24[j] < v1; the largest such value is stored as v5/v3 (second-place team). [function:0x00420820, source:raw]
    // CALCULATION: Tie check for second place: v20 is set to 1 when any index k other than v5 has points equal to v24[v5]. [function:0x00420820, source:raw]
    // GUARD: Second-place handling runs only when v20 is clear (no tie) and v5 != -1 (a valid second-place team exists). [function:0x00420820, source:raw]
    // CALCULATION: Switch on second-place index v5 (jump table jpt_420984) selects that team's name string and copies it via StringCopyWithBufferRealloc. [function:0x00420820, callee:0x00566650, global:0x00420C7C, source:raw]
    // GUARD: if (a1): build the second-place display entry; when a1 is 0 the second-place name was still emitted but no table entry is inserted. [function:0x00420820, source:raw]
    // CALL: Second-place display entry (display ID 423): StructInitWithSentinelValues(v23); v9 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)&byte_5EA438); DriverDataTableLookupAndTimeConversion(v23, 423, v9, -1, -1, -1, -2.0, -2.0); InsertDriverTableEntry(flt_5EA618, v23). [function:0x00420820, callee:0x004144D0, callee:0x00415550, callee:0x004144F0, callee:0x00418560, global:0x005EA5E8, global:0x005EA438, global:0x005EA618, source:raw]
    // LOOP: Scan v24 for the third-largest value: index m must differ from v22 and v5 and satisfy v11 < v24[m] < v3; the largest such value is stored as v10/v11 (third-place team). [function:0x00420820, source:raw]
    // CALCULATION: Tie check for third place: v14 is set to 1 when any index n other than v10 has points equal to v24[v10]. [function:0x00420820, source:raw]
    // GUARD: If v20, v14, or v10 == -1, the third-place individual insertion is skipped and control jumps to the early-return path LABEL_84. [function:0x00420820, source:raw]
    // CALCULATION: Switch on third-place index v10 (jump table jpt_420ABA) selects that team's name string and copies it via StringCopyWithBufferRealloc. [function:0x00420820, callee:0x00566650, global:0x00420CB4, source:raw]
    // CALL: Third-place display entry (display ID 424): StructInitWithSentinelValues(v23); v16 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)&byte_5EA438); DriverDataTableLookupAndTimeConversion(v23, 424, v16, -1, -1, -1, -2.0, -2.0); InsertDriverTableEntry(flt_5EA618, v23). LABEL_84 then returns 0 when a1, v20 or v14 is set. [function:0x00420820, callee:0x004144D0, callee:0x00415550, callee:0x004144F0, callee:0x00418560, global:0x005EA5E8, global:0x005EA438, global:0x005EA618, source:raw]
    // GUARD: Combined podium entry (LABEL_87) runs only when both v5 != -1 and v10 != -1 (second and third places exist). [function:0x00420820, source:raw]
    // CALL: Combined second+third display entry (display ID 488): StructInitWithSentinelValues(v23); v19 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)&byte_5EA438); v17 = LinkedListIndexScannerWithValidation(&dword_5EA5E8, (int)&byte_5EA438); DriverDataTableLookupAndTimeConversion(v23, 488, v17, v19, -1, -1, -2.0, -2.0); InsertDriverTableEntry(flt_5EA618, v23). [function:0x00420820, callee:0x004144D0, callee:0x00415550, callee:0x004144F0, callee:0x00418560, global:0x005EA5E8, global:0x005EA438, global:0x005EA618, source:raw]
    // RETURN: All paths return 0. [function:0x00420820, source:raw]

    // Conservative worker pseudocode:
    //   v24[14] = {0}; v1 = v3 = v22 = -1; v2 = 0;
    //   do { copy_team_name(v2); v24[v2++] = ChampionshipPointsAccumulator(&byte_5EA438, -1); } while (v2 < 14);
    //   v22/v1 = team with max points; v5/v3 = next strictly lower; v20 = second-place tie flag;
    //   v10/v11 = third strictly lower than v3; v14 = third-place tie flag;
    //   emit 2nd/3rd team names; when a1, insert display entries for IDs 423, 424, or combined 488; return 0;
    // UNRESOLVED: callee:0x00587BCF (FreeWrapper_7bcf) is listed as a packet callee but does not appear in the decompiled body; no freed-buffer or cleanup call is evidenced inside this function.
    // UNRESOLVED: The tie-detection loops evaluate v24[v5] / v24[v10] even when v5 or v10 is -1 (v24[-1]), which in the Hex-Rays frame aliases the preceding v23 storage; the tie flags are therefore unreliable unless a second/third place was actually found.
    // UNRESOLVED: Semantics of the display IDs passed to DriverDataTableLookupAndTimeConversion (423, 424, 488) are not derived.
    // UNRESOLVED: The points source read by ChampionshipPointsAccumulator(&byte_5EA438, -1) and the meaning of the -1 argument are not grounded; existing analysis labels byte_5EA438 as a path/application-directory value.
    // UNRESOLVED: Parameter a1's exact meaning (display-entry insertion enable) is DERIVED from the branches, not confirmed; a1 == 0 still emits team names but skips the individual 423/424 entries.
}
