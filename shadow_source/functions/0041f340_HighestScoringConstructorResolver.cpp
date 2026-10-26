// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041F340
// Canonical corpus name: sub_41F340
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_41F340_0041f340.c

void UnknownObject::HighestScoringConstructorResolver()
{
    // Resolves the constructor team with the highest championship-points score. Allocates an 8-byte [name, score] object via OperatorNewNhMallocWrapper (name=0, score=-1), then loops over the 14 constructor team name strings (Arrows, BAR/off_5C25E0, Renault, Ferrari, Jaguar, Jordan, McLaren, Minardi, Prost, Sauber, Williams, Toyota, Benetton, Stewart). For each team the name is staged through StringCopyWithBufferRealloc and scored with ChampionshipPointsAccumulator(&byte_5EA438, -1). A candidate beats the current best when its score is higher and (if a1 is non-null) it passes the sub_566810 filter; the best name is committed via StringCopyWithBufferRealloc(&byte_5EA438) and its score saved. If a2 is non-zero, returns the [name, score] object immediately; otherwise a second identical 14-team pass detects ties: if any team's score equals the stored best, returns 0. Falls through to return the object when no tie is found.
    // CALL: v4 = OperatorNewNhMallocWrapper(8); allocate the 8-byte char*[2] output object. [callee:0x00587C03, function:0x0041F340, source:raw]
    // ASSIGNMENT: Initialize the object: *v4 = 0 (name), v4[1] = (char*)-1 (score). [function:0x0041F340, source:raw]
    // GUARD: If allocation failed, v10 = 0; otherwise v10 = v4. [callee:0x00587C03, function:0x0041F340, source:raw]
    // LOOP: First pass: do/while v5 in 0..13, dispatch via jump table jpt_41F385; each case stages the corresponding constructor name (aArrows, off_5C25E0, aRenault, aFerrari, aJaguar, aJordan, aMclaren, aMinardi, aProst, aSauber, aWilliams, aToyota, aBenetton, aStewart) through StringCopyWithBufferRealloc. [global:0x0041F55C, global:0x005C25F4, global:0x005C25E0, global:0x005C25C4, global:0x005C2618, global:0x005C25D8, global:0x005C2604, global:0x005C2620, global:0x005C25E4, global:0x005C25EC, global:0x005C25FC, global:0x005C260C, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, callee:0x00566650, function:0x0041F340, source:raw]
    // CALCULATION: v6 = ChampionshipPointsAccumulator(&byte_5EA438, -1); compute the championship-points score of the team currently staged in byte_5EA438. [callee:0x0041F220, global:0x005EA438, function:0x0041F340, source:raw]
    // GUARD: If v11 < v6 AND (a1 is null OR sub_566810(&byte_5EA438, a1) returns false), the candidate is the new best: commit its name via StringCopyWithBufferRealloc(&byte_5EA438) and set v11 = v6. [callee:0x00566810, global:0x005EA438, function:0x0041F340, source:raw]
    // GUARD: If a2 is non-zero, return v10 immediately after the first pass (no tie-check). [function:0x0041F340, source:raw]
    // LOOP: Second pass (only when a2 == 0): infinite loop dispatching v7 0..13 via jump table jpt_41F465, staging each constructor name through StringCopyWithBufferRealloc exactly as the first pass. [global:0x0041F594, global:0x005C25F4, global:0x005C25E0, global:0x005C25C4, global:0x005C2618, global:0x005C25D8, global:0x005C2604, global:0x005C2620, global:0x005C25E4, global:0x005C25EC, global:0x005C25FC, global:0x005C260C, global:0x005C25B4, global:0x005C25CC, global:0x005C25BC, callee:0x00566650, function:0x0041F340, source:raw]
    // GUARD: Tie detection per candidate: v8 = *v10 (stored best name), or &byte_5EA438 when the stored pointer is null; if sub_566810(v8, &byte_5EA438) is false (names equal) AND v11 == ChampionshipPointsAccumulator(&byte_5EA438, -1), return 0 (another team ties the best score). [callee:0x00566810, callee:0x0041F220, global:0x005EA438, function:0x0041F340, source:raw]
    // RETURN: After all 14 second-pass teams, return v10 (the [name, score] object of the highest-scoring team). [function:0x0041F340, source:raw]

    // Conservative worker pseudocode:
    //   out = OperatorNewNhMallocWrapper(8);
    //   if (out) { out[0] = NULL; out[1] = (char*)-1; } else return NULL;
    //   best = -1;
    //   for (i = 0; i < 14; i++) {
    //     stageTeamName(i);
    //     score = ChampionshipPointsAccumulator(&byte_5EA438, -1);
    //     if (best < score && (!filter || !sub_566810(&byte_5EA438, filter))) {
    //       commitBestName();
    //       best = score;
    //     }
    //   }
    //   if (returnResults) return out;
    //   for (i = 0; i < 14; i++) {
    //     stageTeamName(i);
    //     stored = out[0] ? out[0] : &byte_5EA438;
    //     if (!sub_566810(stored, &byte_5EA438) && best == ChampionshipPointsAccumulator(&byte_5EA438, -1))
    //       return 0;
    //   }
    //   return out;
    // UNRESOLVED: StringCopyWithBufferRealloc destination semantics are unconfirmed: the raw source never writes *v10, yet the second pass reads it as the stored winner; the commit call StringCopyWithBufferRealloc(&byte_5EA438) is inferred to populate *v10 but this is not explicit in the source text.
    // UNRESOLVED: The raw source shows no call site for FreeWrapper_7bcf although the packet lists it as a callee; possibly elided or inline-optimized by the decompiler.
    // UNRESOLVED: sub_566810 return semantics (string-equality test assumed) and a1's role (filter/excluded team) not grounded.
    // UNRESOLVED: byte_5EA438 is treated as a staging buffer for team names and scoring; its fixed size and ownership are unknown.
}
