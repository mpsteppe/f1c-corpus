// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418B90
// Canonical corpus name: ScoreThresholdGateCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScoreThresholdGateCheck_00418b90.c

void UnknownObject::ScoreThresholdGateCheck()
{
    // Mode-dependent score threshold check. Returns true (1) by default. Dispatches on global dword_7D0308 (via jump table jpt_418B9D): mode 0 tests dword_5BF9A0[5*a1] == 0x7FFFFFFF, mode 1 tests >= 70, mode 2 tests >= 40, mode 3 tests > 0; any other mode leaves the default result 1. The 5*a1 index implies a 5-dword-per-entry record stride in dword_5BF9A0. Called by InsertDriverTableEntry and CarSelectionStateMachine.
    // ASSIGNMENT: result = 1; the default answer is 'pass'. [source:raw]
    // GUARD: Switch on global dword_7D0308 (mode selector), dispatched through jump table jpt_418B9D. [global:0x007D0308, global:0x00418BFC, source:raw]
    // STATE_TRANSITION: Mode 0: result = dword_5BF9A0[5*a1] == 0x7FFFFFFF. [global:0x005BF9A0, source:raw]
    // STATE_TRANSITION: Mode 1: result = dword_5BF9A0[5*a1] >= 70. [global:0x005BF9A0, source:raw]
    // STATE_TRANSITION: Mode 2: result = dword_5BF9A0[5*a1] >= 40. [global:0x005BF9A0, source:raw]
    // STATE_TRANSITION: Mode 3: result = dword_5BF9A0[5*a1] > 0. [global:0x005BF9A0, source:raw]
    // RETURN: Return result; the default branch returns the unchanged initial value 1. [function:0x00418B90, source:raw]

    // Conservative worker pseudocode:
    //   bool sub_418B90(int a1) {
    //     bool result = true;
    //     switch (dword_7D0308) {
    //       case 0: result = dword_5BF9A0[5*a1] == 0x7FFFFFFF; break;
    //       case 1: result = dword_5BF9A0[5*a1] >= 70; break;
    //       case 2: result = dword_5BF9A0[5*a1] >= 40; break;
    //       case 3: result = dword_5BF9A0[5*a1] > 0; break;
    //       default: return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the dword_7D0308 mode enum (0..3) is unknown.
    // UNRESOLVED: Semantics of dword_5BF9A0 and its 5-dword-per-entry record stride are unknown from this function alone.
    // UNRESOLVED: Callers InsertDriverTableEntry and CarSelectionStateMachine are the only known call sites.
}
