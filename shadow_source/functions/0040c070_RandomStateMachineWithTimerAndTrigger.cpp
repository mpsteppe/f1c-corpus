// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C070
// Canonical corpus name: RandomStateMachineWithTimerAndTrigger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomStateMachineWithTimerAndTrigger_0040c070.c

void UnknownObject::RandomStateMachineWithTimerAndTrigger()
{
    // Per-call countdown timer that, while its gate byte (this+0x24) is clear, decrements the float timer at this+0x3C by the per-tick delta returned from ScoringGateConditionCheck. When the timer reaches zero or below it decodes the current session phase, picks a random target state from {0, 3, 4, 5} with an LCG modulo, requests the chosen state transition through GameActionStateMachine (twice when it differs from the decoded phase), and with one-third probability additionally targets the race leader camera via CameraTargetRaceLeader. On firing it runs ShortComputation_d360 over the dwords at this+0x30 and this+0x34 and returns a non-zero fired flag; otherwise it returns zero. Called from MainCameraDirectorUpdate (0040CA30).
    // ASSIGNMENT: Initializes the return flag v2 to 0 before the gate check [source:raw]
    // GUARD: Gate: when the byte at this+0x24 is non-zero the entire timer body is skipped and the function returns 0 [field:this:0x00000024, source:raw]
    // CALL: Reads the per-tick delta by calling ScoringGateConditionCheck on this [callee:0x0040C780, source:raw]
    // CALCULATION: Countdown update: subtracts the ScoringGateConditionCheck result from the float at this+0x3C and writes the new value back to this+0x3C [field:this:0x0000003C, source:raw]
    // GUARD: Timer expiry: when the updated countdown value is zero or below the random state transition fires [source:raw]
    // CALL: Decodes the current session phase into v4 via SessionPhaseDecode(this) [callee:0x0040CD60, source:raw]
    // CALL: Random target selection: takes RandLCGRandomNumberGenerator() modulo 4 and maps the result to a target state (0 -> 0, 1 -> 3, 2 -> 4, otherwise 5), compiled to the jump table jpt_40C0BD [callee:0x005884ED, global:0x0040C128, source:raw]
    // CALL: Requests the randomly selected state v5 with argument 1 through GameActionStateMachine [callee:0x0040CDE0, source:raw]
    // GUARD: When the selected state v5 differs from the decoded phase v4, GameActionStateMachine is called a second time with the same arguments [source:raw]
    // CALL: Re-issues the state transition GameActionStateMachine(v5, 1) when the selected state differs from the current phase [callee:0x0040CDE0, source:raw]
    // GUARD: Race-leader chance: fires only when RandLCGRandomNumberGenerator() modulo 3 is zero (one-in-three probability) [callee:0x005884ED, source:raw]
    // CALL: Targets the race leader camera via CameraTargetRaceLeader(1) on the one-in-three roll [callee:0x0040D290, source:raw]
    // ASSIGNMENT: Sets the fired flag v2 to 1 once the random transition has been issued [source:raw]
    // CALL: Runs ShortComputation_d360 with the dword at this+0x30 as first argument and the dword at this+0x34 as second argument [callee:0x0040D360, field:this:0x00000030, field:this:0x00000034, source:raw]
    // RETURN: Returns the fired flag v2 (1 when the timer fired this call, 0 otherwise) [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40C070(this) {
    //     int fired = 0;
    //     if (!this[0x24]) {
    //       this[0x3C] -= ScoringGateConditionCheck(this);
    //       if (this[0x3C] <= 0.0) {
    //         int phase = SessionPhaseDecode(this);
    //         int state = rand() % 4;
    //         state = (state == 0) ? 0 : (state == 1) ? 3 : (state == 2) ? 4 : 5;
    //         GameActionStateMachine(state, 1);
    //         if (state != phase) GameActionStateMachine(state, 1);
    //         if (rand() % 3 == 0) CameraTargetRaceLeader(1);
    //         fired = 1;
    //         ShortComputation_d360(this[0x30], this[0x34]);
    //       }
    //     }
    //     return fired;
    //   }
    // UNRESOLVED: The read-only global flt_59E440 is flagged by packet facts but appears nowhere in the raw decompiled source; the skeleton fill labels it a zero threshold, unverifiable from this packet
    // UNRESOLVED: The meaning of the two dwords at this+0x30 and this+0x34 consumed by ShortComputation_d360 is not evidenced here
    // UNRESOLVED: The exact semantic mapping of the target states 0, 3, 4 and 5 to camera or action modes is not evidenced by this packet
    // UNRESOLVED: The purpose of the duplicated GameActionStateMachine call when the selected state differs from the current phase is not resolved (state change vs. confirmation)
    // UNRESOLVED: How the countdown timer at this+0x3C is armed/reset is not evidenced; it is only decremented here
}
