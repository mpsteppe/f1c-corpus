// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040DCD0
// Canonical corpus name: StateMachineInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateMachineInitializer_0040dcd0.c

void UnknownObject::StateMachineInitializer()
{
    // Two-phase state machine initializer. Phase 1 (state 1): zeroes +0x84, initializes sub-struct at +0x88, stops audio channel a2 and stores the result in +0x84; if audio stop failed, returns 0 staying in phase 1. Phase 2 (state 2): runs CinematicEventStateMachine; non-zero result returns 1 (success), otherwise state reverts to -1 and returns 0.
    // CALCULATION: Load v3 = this[34] (sub-struct pointer at +0x88). [field:this:0x00000088]
    // ASSIGNMENT: this+0x84 = 0. [field:this:0x00000084]
    // STATE_TRANSITION: Set state this+0x0 = 1 (phase 1 initializing). [field:this:0x00000000, source:raw]
    // CALL: StructFieldInit(sub-struct at +0x88). [callee:0x0040D490, source:raw]
    // CALL: v4 = AudioChannelStop(a2). [callee:0x00568210, source:raw]
    // ASSIGNMENT: this+0x84 = v4 (audio stop result). [field:this:0x00000084, source:raw]
    // GUARD: If v4 == 0, return 0 (blocked, stay in phase 1). [field:this:0x00000084, source:raw]
    // STATE_TRANSITION: Set state this+0x0 = 2 (phase 2 cinematic). [field:this:0x00000000, source:raw]
    // CALL: CinematicEventStateMachine(this). [callee:0x0040DDF0, source:raw]
    // GUARD: If cinematic result non-zero, return 1 (success). [callee:0x0040DDF0, source:raw]
    // STATE_TRANSITION: Revert state this+0x0 = -1 (error). [field:this:0x00000000, source:raw]
    // RETURN: Return 0 (failure). [function:0x0040DCD0, source:raw]

    // Conservative worker pseudocode:
    //   v3 = this[34];
    //   this[33] = 0;
    //   *this = 1;
    //   StructFieldInit(v3);
    //   v4 = AudioChannelStop(a2);
    //   this[33] = v4;
    //   if (!v4) return 0;
    //   *this = 2;
    //   if (CinematicEventStateMachine(this)) return 1;
    //   *this = -1;
    //   return 0;
    // UNRESOLVED: Semantic meaning of the numeric state values (1/2/-1) is not independently established; phase labels are DERIVED from control flow.
}
