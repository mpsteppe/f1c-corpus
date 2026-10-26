// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5E10
// Canonical corpus name: SessionTransitionDispatch
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/SessionTransitionDispatch_004a5e10.c

void F1CPitMachine::SessionTransitionDispatch()
{
    // Drives AI mode transitions on the pit machine: reads the current mode state at this+0x184 (this[97]) and, for states 0, 1 and 4, forwards an unchanged this to StateChangeNotify to record and dispatch the transition. State 0 and state 4 both request state 1; state 1 requests state 0. Any other state produces no transition and returns the remaining state-4 difference. Runs on the frame path, called by sub_42C440.
    // GUARD: Read the current AI mode state from this[97] (offset 0x184) and branch on its value. [field:this:0x00000184, source:raw]
    // GUARD: If the state is 0, return the result of StateChangeNotify immediately. [field:this:0x00000184, source:raw]
    // CALL: State 0 path: call StateChangeNotify(this, 1) to activate the state 1 transition. [callee:0x004A5C80, source:raw]
    // CALCULATION: Compute v2 = state - 1 to test whether the state is 1. [field:this:0x00000184, source:raw]
    // GUARD: If v2 is 0 (state was 1), return the result of StateChangeNotify immediately. [field:this:0x00000184, source:raw]
    // CALL: State 1 path: call StateChangeNotify(this, 0) to request the state 0 transition. [callee:0x004A5C80, source:raw]
    // CALCULATION: Compute result = v2 - 3, i.e. state - 4, to test whether the state was 4. [field:this:0x00000184, source:raw]
    // GUARD: If result is 0 (state was 4), return the result of StateChangeNotify immediately. [field:this:0x00000184, source:raw]
    // CALL: State 4 path: call StateChangeNotify(this, 1) to request the state 1 reactivation transition. [callee:0x004A5C80, source:raw]
    // RETURN: For all other states, return the computed difference (state - 4) with no transition performed. [field:this:0x00000184, source:raw]

    // Conservative worker pseudocode:
    //   int SessionTransitionDispatch(F1CPitMachine* this) {
    //     int state = this[97];            // AI mode state at offset 0x184
    //     if (state == 0) return StateChangeNotify(this, 1);
    //     int v2 = state - 1;
    //     if (v2 == 0) return StateChangeNotify(this, 0);
    //     int result = v2 - 3;
    //     if (result == 0) return StateChangeNotify(this, 1);
    //     return result;
    //   }
    // UNRESOLVED: Exact meaning of the StateChangeNotify arguments (0 vs 1) is DERIVED from the state labels in the existing analysis (activate/deactivate/reactivate) and not locked by the packet.
    // UNRESOLVED: The state machine roles of states 0, 1 and 4 on the pit machine are inferred from the transition pattern only; the full state set is not visible in this body.
    // UNRESOLVED: Semantics of the returned state - 4 value when no transition matches are unknown.
    // UNRESOLVED: StateChangeNotify is recorded as a ring-buffer recorder/dispatcher in the existing analysis; its internal contract is not modeled here.
}
