// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2BE0
// Canonical corpus name: Accumulator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Accumulator_004c2be0.c

void UnknownObject::FieldAccumulator()
{
    // Field accumulator: saves the input a2 as the return value, then adds a2 to the running total stored at this[9] (this+0x24) unconditionally, and returns the original input. Called by SeasonScoringInfoUpdater (0x004C2A80) to accumulate session counters.
    // ASSIGNMENT: Save the input value: result = a2, so the original argument is preserved for the return. [source:raw]
    // CALCULATION: Accumulate unconditionally: this[9] += a2, i.e. the field at this+0x24 is increased by a2. [field:this:0x00000024, source:raw]
    // RETURN: Return result, which is the unchanged input a2. [source:raw]
    // CALL: Invoked by SeasonScoringInfoUpdater (0x004C2A80), consistent with accumulating a session scoring quantity. [caller:0x004C2A80]

    // Conservative worker pseudocode:
    //   int sub_4C2BE0(_DWORD *this, int a2) {
    //     int result = a2;
    //     this[9] += a2;    // this + 0x24
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the accumulated field at this+0x24 (laps, points, or another session counter) is inferred only from the SeasonScoringInfoUpdater calling context and is not documented in this function.
}
