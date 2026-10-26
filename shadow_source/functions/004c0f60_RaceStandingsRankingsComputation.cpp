// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0F60
// Canonical corpus name: RaceStandingsRankingsComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaceStandingsRankingsComputation_004c0f60.c

void UnknownObject::RaceStandingsRankingsComputation()
{
    // Computes driver rankings after a race, guarded by the race-over flag at this+0xB150 and the session-type check this+0xB14C == 7. Scores season points for the player (entry at this+44908) and for every active driver entry (active flag at +432, 436-byte stride), then ranks active drivers by comparing their position values (+408) and stores the resulting rank count (player rank to this+0xB108). Sets the race-over flag to 1 on completion.
    // GUARD: If the race-over flag at this+0xB150 is zero, run the full computation; if it is already set, the function returns immediately. [field:this:0x0000B150, source:raw]
    // CALL: Score the player entry at this+44908: call FlagsGetter to obtain the scoring flags, then SeasonScoring on the player entry. [callee:0x004C11D0, callee:0x004C0910, source:raw]
    // LOOP: Iterate 103 driver entries after the player slot, striding 436 bytes per entry. [source:raw]
    // GUARD: For each non-player entry, only score it when its active flag at +432 (field this+0x1B0 within the entry) is non-zero. [field:this:0x000001B0, source:raw]
    // CALL: For each active driver entry, call FlagsGetter and SeasonScoring to accumulate that driver's season points. [callee:0x004C11D0, callee:0x004C0910, source:raw]
    // GUARD: Only compute rankings when the race session value at this+0xB14C equals 7. [guard:0, field:this:0x0000B14C, source:raw]
    // LOOP: For each of the 104 slots (i=0..103) iterate all other slots (j) to count how many active drivers have a strictly larger position value. [source:raw]
    // CALCULATION: Read the current driver's position value at +408 (for the player slot i=0 this is field this+0xB104; for other slots it is 436*i+this-436+408) and compare it against each active competitor's +408 value; increment the rank counter for each active competitor with a larger value. [field:this:0x0000B104, source:raw]
    // ASSIGNMENT: Write the computed rank count: the player's rank to this+45320 (field this+0xB108) for i=0, and to 436*i+this-24 for other slots. [field:this:0x0000B108, source:raw]
    // ASSIGNMENT: Set the race-over flag at this+0xB150 to 1 so the computation is not repeated. [field:this:0x0000B150, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   char RaceStandingsRankingsComputation(int this) {
    //     if (!*(char *)(this + 0xB150)) {
    //       SeasonScoring((int *)(this + 44908), FlagsGetter(this));
    //       for (int i = 0; i < 103; ++i) {
    //         int entry = this + 436 * (i + 1);
    //         if (*(char *)(entry + 432)) SeasonScoring((int *)entry, FlagsGetter(this));
    //       }
    //       if (*(int *)(this + 0xB14C) == 7) {
    //         for (int i = 0; i < 104; ++i) {
    //           int cur = (i == 0) ? (this + 44908) : (this + 436 * i - 436);
    //           if (*(char *)(cur + 432)) {
    //             int pos = *(int *)(cur + 408);
    //             int rank = 0;
    //             for (int j = 0; j < 104; ++j) {
    //               if (i != j) {
    //                 int other = (j == 0) ? (this + 44908) : (this + 436 * j - 436);
    //                 if (*(char *)(other + 432) && *(int *)(other + 408) > pos) ++rank;
    //               }
    //             }
    //             if (i == 0) *(int *)(this + 45320) = rank;
    //             else *(int *)(this + 436 * i - 24) = rank;
    //           }
    //         }
    //       }
    //       *(char *)(this + 0xB150) = 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Field this+0xB11C (listed in the packet) is the player entry's active-flag offset (this+44908+432) but the visible source only reads it indirectly through the +432 selector logic; exact equivalence with field this+0xB104's entry is inferred, not shown as a distinct access.
    // UNRESOLVED: Ranking semantics depend on the unknown meaning of the position value at +408; larger value being worse (rank count of competitors ahead) is inferred from the comparison direction.
    // UNRESOLVED: Owner object is unknown; callers treat this as a standings/session object whose layout spans this+0x1B0 to this+0xB150.
}
