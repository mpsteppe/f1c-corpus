// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D2210
// Canonical corpus name: PitCloseTeamReadyCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitCloseTeamReadyCheck_004d2210.c

void UnknownObject::PitCloseTeamReadyCheck()
{
    // Iterates the active-vehicle array dword_7C54F0 over dword_5C329C entries; for each vehicle whose dword at offset 13000 (0x32C8) is <= 1, calls sub_4BC9B0 on the field at offset 16436 (0x4034) with arguments (1, 0). Returns the active-vehicle count. Invoked from PitTimer, consistent with a pit-close/team-ready state sweep during pit sequences.
    // ASSIGNMENT: Seed result with the active-vehicle count dword_5C329C. [global:0x005C329C, source:raw]
    // LOOP: Iterate index i from 0 up to the active-vehicle count dword_5C329C. [global:0x005C329C, source:raw]
    // ASSIGNMENT: Load the i-th active vehicle pointer from the dword_7C54F0 array into v2. [global:0x007C54F0, source:raw]
    // GUARD: Proceed only when the vehicle's dword at offset 13000 (0x32C8) is <= 1. [source:raw]
    // CALL: Call sub_4BC9B0 on the field at vehicle + 16436 (0x4034) with arguments (1, 0) for each matching vehicle. [callee:0x004BC9B0, source:raw]
    // ASSIGNMENT: Refresh result from dword_5C329C at the end of each iteration. [global:0x005C329C, source:raw]
    // RETURN: Return the final active-vehicle count stored in result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D2210() {
    //     int result = dword_5C329C;
    //     for (int i = 0; i < dword_5C329C; ++i) {
    //       int v2 = dword_7C54F0[i];
    //       if (*(int*)(v2 + 13000) <= 1)
    //         sub_4BC9B0((int*)(v2 + 16436), 1, 0);
    //       result = dword_5C329C;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the state dword at vehicle + 13000 and the exact pit/team-ready effect of sub_4BC9B0(field, 1, 0) are unconfirmed.
    // UNRESOLVED: Why result is re-read from dword_5C329C every iteration rather than kept stable is unclear.
    // UNRESOLVED: Relation between dword_5C329C and the pit-close team-ready state is unconfirmed.
}
