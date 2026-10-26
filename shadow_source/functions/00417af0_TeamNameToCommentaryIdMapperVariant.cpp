// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00417AF0
// Canonical corpus name: sub_417AF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_417AF0_00417af0.c

void UnknownObject::TeamNameToCommentaryIdMapperVariant()
{
    // Structural twin of sub_417640 (00417640) mapping F1 team names to a different commentary audio ID table. Indexes the team entry array rooted at dword_8AC394 with stride 1060*car index, reads the team name string at entry+124, and runs the same chain of sub_566810 string comparisons against the team-name globals (McLaren, Ferrari, Williams, Jordan, Sauber, Arrows, Prost, Minardi, off_5C25E0, Jaguar, Renault, Toyota, Benetton, Stewart). The matched branch selects an ID via the a3 value (0 or 1 selects a different ID table) and the a4 language-variant flag: the a3 == 1 branch yields IDs 121-140 and low values (Renault 328-(a4!=0), Toyota 452-(a4!=0), Benetton 20-(a4!=0), Stewart 416-(a4!=0)); the a3 == 0 branch yields low even IDs 66-84 and high values (Renault 472-(a4!=0), Toyota 488-(a4!=0), Benetton 458-(a4!=0), Stewart 478-(a4!=0)). ShortComputation_41a0(a3) computes v5; when v5 > 0 and v4 > 0, StringCopyWithBufferRealloc(&byte_5EA438) runs, *(a1+8) = v4, *(a1+12) = v5, *(a1+16) = 0, and 0 is returned; otherwise 1 is returned.
    // ASSIGNMENT: Initialize the result v4 = -1 and compute v5 = ShortComputation_41a0(a3); when v5 < 0 the function fails. [callee:0x004141A0, source:raw]
    // GUARD: Guard on a2 >= 0: compute the entry pointer v6 = dword_8AC394 + 1060 * a2 and proceed only when v6 is non-null. [global:0x008AC394, source:raw]
    // CALCULATION: Point v7 at the team name field v6 + 124; the a3 value (0 or 1) selects which commentary ID table the string comparisons consult. [source:raw]
    // CALCULATION: a3 == 1 branch: chain of sub_566810(v7, team_name) comparisons mapping each team to a commentary ID with the a4 flag choosing the variant: McLaren 121/131, Ferrari 122/132, Williams 123/133, Jordan 124/134, Sauber 125/135, Arrows 126/136, Prost 127/137, Minardi 128/138, off_5C25E0 129/139, Jaguar 130/140, Renault 328-(a4!=0), Toyota 452-(a4!=0), Benetton 20-(a4!=0), Stewart 416-(a4!=0). [callee:0x00566810, global:0x005C2620, global:0x005C2618, global:0x005C260C, global:0x005C2604, global:0x005C25FC, global:0x005C25F4, global:0x005C25EC, global:0x005C25E4, global:0x005C25E0, global:0x005C25D8, global:0x005C25C4, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, source:raw]
    // CALCULATION: a3 == 0 branch: chain of sub_566810(v7, team_name) comparisons mapping each team to a commentary ID with the a4 flag choosing the variant: McLaren 66-(a4!=0), Ferrari 68-(a4!=0), Williams 70-(a4!=0), Jordan 72-(a4!=0), Sauber 74-(a4!=0), Arrows 76-(a4!=0), Prost 78-(a4!=0), Minardi 80-(a4!=0), off_5C25E0 82-(a4!=0), Jaguar 84-(a4!=0), Renault 472-(a4!=0), Toyota 488-(a4!=0), Benetton 458-(a4!=0), Stewart 478-(a4!=0). [callee:0x00566810, global:0x005C2620, global:0x005C2618, global:0x005C260C, global:0x005C2604, global:0x005C25FC, global:0x005C25F4, global:0x005C25EC, global:0x005C25E4, global:0x005C25E0, global:0x005C25D8, global:0x005C25C4, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, source:raw]
    // CALL: On success, run StringCopyWithBufferRealloc(&byte_5EA438), which refreshes the shared name buffer. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: When v5 > 0 and v4 > 0 (a team was matched): write the commentary ID v4 to *(a1+8), the computed value v5 to *(a1+12), clear the flag byte *(a1+16) to 0, and return 0. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // RETURN: Return 1 on any failure path (v5 < 0, invalid car index, or no team name matched). Called by sub_414A90. [caller:0x00414A90, source:raw]

    // Conservative worker pseudocode:
    //   int sub_417AF0(int a1, int carIdx, unsigned int a3, char a4) {
    //     int id = -1;
    //     int v5 = ShortComputation_41a0(a3);
    //     if (v5 < 0) return 1;
    //     if (carIdx >= 0) {
    //       char* team = *(char**)(dword_8AC394 + 1060 * carIdx + 124);
    //       if (team) {
    //         // table = (a3 == 1) ? variant_ids : base_ids; a4 selects variant offset
    //         id = match_team(team, a4);   // sub_566810 compare chain against team globals
    //       }
    //     }
    //     if (v5 > 0 && id > 0) {
    //       StringCopyWithBufferRealloc(&byte_5EA438);
    //       *(int*)(a1 + 8)  = id;
    //       *(int*)(a1 + 12) = v5;
    //       *(char*)(a1 + 16) = 0;
    //       return 0;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: The global flt_5EA618 appears in the deterministic global list but has no visible use in the raw source text; its role in this function is unknown.
    // UNRESOLVED: The exact semantic difference between the a3 == 0 and a3 == 1 ID tables (e.g. race vs qualifying commentary set) is not established.
    // UNRESOLVED: Whether the 0x14 team-name strings come from a per-driver or per-team entry depends on the dword_8AC394 array layout and the car index interpretation.
}
