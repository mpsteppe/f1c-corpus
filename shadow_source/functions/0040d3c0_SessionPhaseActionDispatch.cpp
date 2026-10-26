// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D3C0
// Canonical corpus name: ShortComputation_d3c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_d3c0_0040d3c0.c

void UnknownObject::SessionPhaseActionDispatch()
{
    // Conditional session-phase-aware action dispatcher: guarded by the session-active flag dword_7D0350, decodes the current session phase, and when the action id a2 is in [7,10] stores the decoded phase at this+0x10 (if <= 5), dispatches GameActionStateMachine(this, a2, 0), sets the activity flag this+0x24 to 1, and runs ReciprocalWithSignCheck on flt_5EA4E8. Part of the pit-stop/session management path; called by PitStopReadyCheck.
    // GUARD: Session-active check: the body runs only when dword_7D0350 is non-zero. [global:0x007D0350, source:raw]
    // CALL: Decode the current session phase: v3 = SessionPhaseDecode(this). [callee:0x0040CD60, source:raw]
    // GUARD: Action-id range check: the dispatch body runs only when a2 is in [7, 10]. [source:raw]
    // ASSIGNMENT: Phase store: when the decoded phase v3 is <= 5, store it at this+0x10. [field:this:0x00000010, source:raw]
    // CALL: Dispatch the game action: GameActionStateMachine(this, a2, 0). [callee:0x0040CDE0, source:raw]
    // ASSIGNMENT: Set the activity flag at this+0x24 to 1. [field:this:0x00000024, source:raw]
    // CALL: Reciprocal computation on the global flt_5EA4E8: ReciprocalWithSignCheck(&flt_5EA4E8, 0.75). [global:0x005EA4E8, source:raw]
    // CALL: Invoked from PitStopReadyCheck (0x004A6200). [caller:0x004A6200, source:raw]

    // Conservative worker pseudocode:
    //   void sub_40D3C0(int this, int a2) {
    //     if (!dword_7D0350) return;
    //     unsigned int phase = SessionPhaseDecode((_DWORD *)this);
    //     if (a2 >= 7 && a2 <= 10) {
    //       if (phase <= 5) *(_DWORD *)(this + 0x10) = phase;
    //       GameActionStateMachine((_DWORD *)this, a2, 0);
    //       *(_BYTE *)(this + 0x24) = 1;
    //       ReciprocalWithSignCheck(&flt_5EA4E8, 0.75);
    //     }
    //   }
    // UNRESOLVED: ReciprocalWithSignCheck is invoked per the raw source but its target address is absent from the packet callee list; no callee evidence reference exists for it.
    // UNRESOLVED: Meaning of the stored phase at this+0x10 and of the action-id range [7,10] depend on the session/action state machines, which are not resolved here.
}
