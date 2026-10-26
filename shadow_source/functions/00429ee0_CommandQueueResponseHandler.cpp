// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00429EE0
// Canonical corpus name: CommandQueueResponseHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CommandQueueResponseHandler_00429ee0.c

void UnknownObject::CommandQueueResponseHandler()
{
    // __thiscall handler that processes a dequeued AI command object by scanning for recognized command IDs with PairArrayLinearSearch and applying the matching side effects: phase-3 session cleanup, command-0 parameter/state setup, command-5 and command-4 flag/parameter updates, command-14 state reset, and phase-4 speed-delta reset. Mutates AI state fields 0x4544 (reset flag), 0x4510 (driver status) and 0x443C (AI state flag) and consults globals 0x007C56A8 (race phase) and 0x007C56A4 (session type).
    // GUARD: If race phase global dword_7C56A8 equals 3, run the session-cleanup block. [global:0x007C56A8]
    // CALL: SessionCleanupFlagClear(this): clear session-cleanup flags on the command object. [callee:0x0042ADB0]
    // ASSIGNMENT: Clear reset flag: this[4433] (offset 0x4544) = 0. [field:this:0x00004544]
    // CALL: WrapPlayerCallback(this): wrap up the player session callback for phase 3. [callee:0x0042AC90]
    // GUARD: If session type global dword_7C56A4 is not 7 AND PairArrayLinearSearch(this, 0) finds command 0, run command-0 handling. [global:0x007C56A4, callee:0x00424E30]
    // ASSIGNMENT: Clear reset flag: this[4433] (offset 0x4544) = 0. [field:this:0x00004544]
    // CALL: ParameterValueSetter(18): set parameter value 18. [callee:0x0042ACD0]
    // ASSIGNMENT: Set driver status: this[4420] (offset 0x4510) = 5. [field:this:0x00004510]
    // CALL: AISpeedDeltaSetter(1): set AI speed delta to 1. [callee:0x0042ACA0]
    // GUARD: If PairArrayLinearSearch(this, 5) finds command 5, run command-5 handling. [callee:0x00424E30]
    // CALL: ParameterValueSetter(99999): reset parameter value to 99999. [callee:0x0042ACD0]
    // ASSIGNMENT: Set reset flag: this[4433] (offset 0x4544) = 1. [field:this:0x00004544]
    // GUARD: If PairArrayLinearSearch(this, 4) finds command 4, run command-4 handling. [callee:0x00424E30]
    // ASSIGNMENT: Set AI state flag: this[4367] (offset 0x443C) = 1. [field:this:0x0000443C]
    // CALL: ParameterValueSetter(18): set parameter value 18. [callee:0x0042ACD0]
    // CALL: PairArrayLinearSearch(this, 14): look for command 14 and store the result as the return value. [callee:0x00424E30]
    // GUARD: If command 14 was found (result non-zero), run the reset block. [source:raw]
    // ASSIGNMENT: Clear reset flag: this[4433] (offset 0x4544) = 0. [field:this:0x00004544]
    // ASSIGNMENT: Set AI state flag: this[4367] (offset 0x443C) = 1. [field:this:0x0000443C]
    // GUARD: If race phase global dword_7C56A8 equals 4, run the phase-4 block. [global:0x007C56A8]
    // CALL: AISpeedDeltaSetter(0): reset AI speed delta to 0. [callee:0x0042ACA0]
    // CALL: ParameterValueSetter(99999): reset parameter value to 99999. [callee:0x0042ACD0]
    // ASSIGNMENT: Set reset flag: this[4433] (offset 0x4544) = 1. [field:this:0x00004544]
    // RETURN: Return result, the last computed value (command-14 search result or last parameter setter return). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_429EE0(CommandObj *this) {
    //     if (dword_7C56A8 == 3) { SessionCleanupFlagClear(this); this[4433] = 0; WrapPlayerCallback(this); }
    //     if (dword_7C56A4 != 7 && PairArrayLinearSearch(this, 0)) {
    //       this[4433] = 0; ParameterValueSetter(18); this[4420] = 5; AISpeedDeltaSetter(1); }
    //     if (PairArrayLinearSearch(this, 5)) { ParameterValueSetter(99999); this[4433] = 1; }
    //     if (PairArrayLinearSearch(this, 4)) { this[4367] = 1; ParameterValueSetter(18); }
    //     result = PairArrayLinearSearch(this, 14);
    //     if (result) { this[4433] = 0; this[4367] = 1; }
    //     if (dword_7C56A8 == 4) { AISpeedDeltaSetter(0); result = ParameterValueSetter(99999); this[4433] = 1; }
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of command IDs 0, 4, 5 and 14 in the AI command queue is unknown here.
    // UNRESOLVED: Meaning of magic parameter values 18 and 99999 depends on ParameterValueSetter's parameter table.
    // UNRESOLVED: Purpose of field 0x443C (this[4367]) vs reset flag 0x4544 (this[4433]) is not established.
    // UNRESOLVED: Phase constants 3 and 4 in dword_7C56A8, and the session-type inequality 7 in dword_7C56A4, are asserted as race-phase/session-type by prior analysis but not proven here.
}
