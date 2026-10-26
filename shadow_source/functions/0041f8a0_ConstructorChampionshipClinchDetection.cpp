// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041F8A0
// Canonical corpus name: ConstructorChampionshipClinchDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorChampionshipClinchDetection_0041f8a0.c

void UnknownObject::ConstructorChampionshipClinchDetection()
{
    // Determines whether the constructor team named by `this` has mathematically clinched the championship. Dereferences the standings linked list (dword_7D2DB0), reads the scoring-category count via FlagsGetter, resolves `this` against 14 constructor name strings to its team index, then for each category prefix v6 (0..FlagsGetter-2) verifies the team leads all other 13 teams in cumulative points via ChampionshipPointsAccumulator. Returns 1 on the first prefix where the team is ahead of every rival, otherwise 0.
    // CALL: LinkedListDereference(&dword_7D2DB0) obtains the race-standings node used for category data [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: FlagsGetter(v3) reads the number of scoring categories from the standings node into v4 [callee:0x004C11D0, source:raw]
    // LOOP: Team-index detection loop v2=0..13: switch on v2 (jump table jpt_41F8E5) selects one of 14 constructor name strings, StringCopyWithBufferRealloc copies it, then sub_566810(&byte_5EA438, this) compares it against the input team name; on a match v11 = v2 [callee:0x00566650, callee:0x00566810, global:0x0041FAA0, global:0x005C25F4, global:0x005C25E0, global:0x005C25C4, global:0x005C2618, global:0x005C25D8, global:0x005C2604, global:0x005C2620, global:0x005C25E4, global:0x005C25EC, global:0x005C25FC, global:0x005C260C, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, global:0x005EA438, source:raw]
    // GUARD: If v11 == -1 the input team name matched none of the 14 known constructors; return 0 [source:raw]
    // GUARD: If v4 - 2 <= 0 (fewer than 3 scoring categories) there is no prefix range to check; return 0 [source:raw]
    // LOOP: Category-prefix loop v6=0..v12-1: for each team i in 0..13, switch on i (jump table jpt_41F9AC) plus StringCopyWithBufferRealloc copies the team name, and ChampionshipPointsAccumulator(&byte_5EA438, v6) stores cumulative points in v13[i] [callee:0x0041F220, callee:0x00566650, global:0x0041FAD8, global:0x005C25F4, global:0x005C25E0, global:0x005C25C4, global:0x005C2618, global:0x005C25D8, global:0x005C2604, global:0x005C2620, global:0x005C25E4, global:0x005C25EC, global:0x005C25FC, global:0x005C260C, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, global:0x005EA438, source:raw]
    // GUARD: Clinch test: for every j != v5, if v13[j] > v13[v5] then some rival still leads at this prefix and v7 is cleared to 0 [source:raw]
    // STATE_TRANSITION: If v7 stays 1 after the rival comparison, the team leads at every prefix; return 1 (clinched) [function:0x0041F8A0, source:raw]
    // RETURN: Return 0 when the prefix loop exhausts (++v6 >= v12) without a clinching prefix, or when early guards fail [function:0x0041F8A0, source:raw]
    // CALL: Invocation context: called by ScoringClassificationDisplay (0041e320) to decide the constructor classification banner [caller:0x0041E320, source:raw]

    // Conservative worker pseudocode:
    //   node = LinkedListDereference(&dword_7D2DB0);
    //   categories = FlagsGetter(node);
    //   v11 = -1;
    //   for (v2 = 0; v2 < 14; v2++) {
    //     copyConstructorName(v2);   // switch via jpt_41F8E5
    //     if (sub_566810(&byte_5EA438, this)) v11 = v2;
    //   }
    //   if (v11 == -1) return 0;
    //   lastPrefix = categories - 2;
    //   if (lastPrefix <= 0) return 0;
    //   for (v6 = 0; ; v6++) {
    //     for (i = 0; i < 14; i++) {
    //       copyConstructorName(i);   // switch via jpt_41F9AC
    //       v13[i] = ChampionshipPointsAccumulator(&byte_5EA438, v6);
    //     }
    //     clinched = 1;
    //     for (j = 0; j < 14; j++)
    //       if (j != v11 && v13[j] > v13[v11]) clinched = 0;
    //     if (clinched) return 1;
    //     if (++v6 >= lastPrefix) return 0;
    //   }
    // UNRESOLVED: FreeWrapper_7bcf (0x00587BCF) is listed as a callee by static facts but does not appear in the raw decompiled source; its role (presumably releasing the buffers allocated by StringCopyWithBufferRealloc) is not verifiable here
    // UNRESOLVED: off_5C25E0 is the name source for constructor index 1, but its string content is not known from this function
    // UNRESOLVED: byte_5EA438 is used both as the team-name comparison source (sub_566810) and the championship-point accumulation source (ChampionshipPointsAccumulator); its underlying type and meaning are not derivable from this function alone
}
