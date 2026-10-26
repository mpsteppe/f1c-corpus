// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E1970
// Canonical corpus name: EffectDataTableInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EffectDataTableInitialization_004e1970.c

void UnknownObject::SubsystemReadyTableInit()
{
    // Initialization helper that queries subsystem readiness for indices 0 through 13 via SubsystemReadyQuery and stores each result into an array of 14 dwords at this+0xB70 (this+732). Runs unconditionally on all 14 indices and returns the last readiness value. Called from LoadingPhase1 (0x004B87C0) during startup initialization.
    // ASSIGNMENT: Initialize subsystem index v2 to 0 and the array cursor v3 to this+732 (offset 0xB70). [field:this:0x00000B70, source:raw]
    // LOOP: do-while loop that runs while v2 < 14, populating one table entry per subsystem index 0..13. [source:raw]
    // CALL: Call SubsystemReadyQuery(this, v2) to query readiness of subsystem v2 and store its return value as result. [callee:0x004E18C0, source:raw]
    // ASSIGNMENT: Store the readiness result into the current entry of the table at this+0xB70. [field:this:0x00000B70, source:raw]
    // CALCULATION: Advance index v2 and array cursor v3 for the next iteration. [source:raw]
    // RETURN: Return the last SubsystemReadyQuery result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4E1970(int *this) {
    //     int idx = 0;
    //     int *cursor = this + 732;
    //     int result;
    //     do {
    //       result = SubsystemReadyQuery(this, idx);
    //       *cursor = result;
    //       ++idx;
    //       ++cursor;
    //     } while (idx < 14);
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of each subsystem readiness value returned by SubsystemReadyQuery is unknown here; entries are stored verbatim.
    // UNRESOLVED: The packet field table lists only the array at this+0xB70; the 14 entry types are not enumerated.
}
