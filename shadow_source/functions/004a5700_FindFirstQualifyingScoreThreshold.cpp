// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5700
// Canonical corpus name: ChampionshipScoreThresholdSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ChampionshipScoreThresholdSearch_004a5700.c

void UnknownObject::FindFirstQualifyingScoreThreshold()
{
    // Linear search over up to three stride-2 championship score thresholds starting at this+0x164 (this[89]). For each entry it tests whether the threshold value is greater than the player score at *this + 0x403C and lower than the total-race-laps global dword_8ACF8C; the first qualifying entry is returned via this[2*v2+89]. Returns -1 when no entry qualifies or the 3-entry cap is reached. Called by ShortComputation_c8a0 (0049C8A0).
    // ASSIGNMENT: Initializes result to -1, the loop counter to 0, and the walking pointer to the first entry at this+0x164 (this[89]) [field:this:0x00000164, source:raw]
    // LOOP: Iterates while the counter is below this[88] (the entry count at this+0x160), with a hard cap of 3 iterations and a stride of 2 dwords per entry [field:this:0x00000160, source:raw]
    // CALCULATION: Each stride-2 entry qualifies when its value is greater than the player score read at *this + 0x403C and lower than the total-race-laps global dword_8ACF8C [field:obj:0x0000403C, field:this:0x00000000, global:0x008ACF8C, source:raw]
    // RETURN: Returns the first qualifying threshold via this[2*v2+89]; if none qualifies or the 3-entry cap is reached, returns -1 [field:this:0x00000164, function:0x004A5700, source:raw]
    // CALL: Invoked by ShortComputation_c8a0 (0049C8A0) as a championship score-threshold lookup [caller:0x0049C8A0, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < this[88] && i < 3; ++i) {
    //     threshold = this[89 + 2*i];
    //     if (threshold > *(*this + 0x403C) && threshold < dword_8ACF8C)
    //       return threshold;
    //   }
    //   return -1;
    // UNRESOLVED: The stride-2 array layout (even elements threshold values, odd elements unused return slots) is inferred from the return index 2*v2+89; the meaning of the odd slots is not defined here
    // UNRESOLVED: The object behind *this is not identified; field obj:0x403C is the score compared against the thresholds
}
