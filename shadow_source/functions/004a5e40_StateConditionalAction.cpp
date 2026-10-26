// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5E40
// Canonical corpus name: StateConditionalAction
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/StateConditionalAction_004a5e40.c

void F1CPitMachine::StateConditionalAction()
{
    // Pit-machine state-conditioned action: reads the current AI mode state at this[97] (offset 0x184) and, when it is 0 or 4, records and dispatches a state-1 transition by calling StateChangeNotify(this, 1). For any other state it returns the read state unchanged without triggering a transition. Called by ForcePitExit (0x0042A110) on the frame path (pit subsystem); a structural twin of SessionTransitionDispatch (004a5e10), differing in that this body only maps states 0 and 4 to state 1.
    // GUARD: Read the current AI mode state from this[97] (offset 0x184) and branch on its value. [field:this:0x00000184, caller:0x0042A110, source:raw]
    // GUARD: If the state is 0, take the transition path instead of returning the state unchanged. [field:this:0x00000184, source:raw]
    // GUARD: If the state is 4, also take the transition path; both 0 and 4 converge on the same handler. [field:this:0x00000184, source:raw]
    // CALL: State 0/4 path: call StateChangeNotify(this, 1) to record and dispatch the state-1 transition. [callee:0x004A5C80, source:raw]
    // RETURN: For any other state, return the read state value unchanged with no transition performed. [field:this:0x00000184, source:raw]

    // Conservative worker pseudocode:
    //   int StateConditionalAction(F1CPitMachine* this) {
    //     int state = this[97];                    // AI mode state at offset 0x184
    //     if (state == 0 || state == 4)
    //       return StateChangeNotify(this, 1);     // request the state-1 transition
    //     return state;
    //   }
    // UNRESOLVED: The full pit-machine state set is not visible in this body; states 0 and 4 both mapping to state 1 is observed but not explained by the packet.
    // UNRESOLVED: The meaning of the returned state value when no transition is taken is unknown.
    // UNRESOLVED: StateChangeNotify is recorded as a ring-buffer recorder/dispatcher in the existing analysis; its internal contract is not modeled here.
}
