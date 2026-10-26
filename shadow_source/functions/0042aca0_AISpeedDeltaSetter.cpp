// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042ACA0
// Canonical corpus name: AISpeedDeltaSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AISpeedDeltaSetter_0042aca0.c

void UnknownObject::AISpeedDeltaSetter()
{
    // Sets an AI speed-delta flag: when the input a2 is 0 or 1, writes a2 to the dword at this+0x4550; when a2 equals 1, additionally triggers an AI state transition via sub_4A46F0(this, 1, 0). Returns a2 unchanged in all other cases.
    // ASSIGNMENT: Seed result with a2 (the default return value). [source:raw]
    // GUARD: Guard on a2 <= 1; write the speed-delta flag this[0x4550] = a2 only for the allowed 0/1 values. [field:this:0x00004550, source:raw]
    // GUARD: Guard on a2 == 1; when the speed-delta flag is being activated, call sub_4A46F0(this, 1, 0) to trigger the AI state transition and return its result. [callee:0x004A46F0, source:raw]
    // RETURN: Return result (a2, or the sub_4A46F0 result when a2 == 1). [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int AISpeedDeltaSetter(unsigned int* this, unsigned int a2) {
    //     unsigned int result = a2;
    //     if (a2 <= 1) this[4436] = a2;
    //     if (a2 == 1) return sub_4A46F0(this, 1, 0);
    //     return result;
    //   }
    // UNRESOLVED: The global 0x007CE2F0 appears in the deterministic global set but is not visible in the raw source; its role is unknown.
    // UNRESOLVED: Meaning of the state-transition arguments (1, 0) passed to sub_4A46F0 is only caller-visible.
}
