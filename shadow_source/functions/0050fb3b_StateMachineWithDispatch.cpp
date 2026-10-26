// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FB3B
// Canonical corpus name: StateMachineWithDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateMachineWithDispatch_0050fb3b.c

void UnknownObject::StateMachineWithDispatch()
{
    // Multi-state processing state machine with a dispatch loop. State 202 initializes the object (ObjectConstructor_6f76), then either short-circuits to done (207) when the early-exit flag at this+0x40 is set or transitions to 203. State 203 runs a dispatch loop: it invokes the callback object at this+0x8, then the dispatch object vtable entry at *(this+0x18C); on result 2 it copies this+0x7C to this+0x84 and hands off to BufferProcessingStateMachine, and for results 1/3 it increments the callback counter at *(this+0x8+4) and extends the callback limit at *(this+0x8+8) by this+0x118 when the counter reaches it. Any other state (not 203/204) writes state code 18 plus the current state into the state dispatcher object at *this and dispatches through its vtable before falling through to BufferProcessingStateMachine.
    // GUARD: Guard on the state variable this+0x10: only the initial state 202 enters the construction path [guard:0, field:this:0x00000010, source:raw]
    // CALL: Call ObjectConstructor_6f76 on this when the state is 202 to initialize the object [callee:0x00516F76, field:this:0x00000010, source:raw]
    // STATE_TRANSITION: After construction, the early-exit flag byte at this+0x40 selects the done state 207 (return 1) or the dispatch state 203 written to this+0x10 [field:this:0x00000040, field:this:0x00000010, source:raw]
    // ASSIGNMENT: For a state that is neither 203 nor 204: resolve the state dispatcher object from this+0x0, write state code 18 to obj+0x14 and the current state to obj+0x18, then dispatch through obj vtable slot 0 [field:this:0x00000000, field:obj:0x00000000, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000010, source:raw]
    // CALL: Hand off to BufferProcessingStateMachine on the unknown-state path (204 and not-203/204 branches) [callee:0x0050FA0E, source:raw]
    // ASSIGNMENT: In state 203 with the dispatch flag byte at *(this+0x18C+0x10) clear: copy the source limit this+0x7C into this+0x84 and hand off to BufferProcessingStateMachine [field:this:0x0000018C, field:*(this+0x18C):0x00000010, field:this:0x00000084, field:this:0x0000007C, callee:0x0050FA0E, source:raw]
    // LOOP: Dispatch loop in state 203: invoke the callback at *(this+0x8+0) when present, then call the dispatch object vfunc0 through *(this+0x18C) [field:this:0x00000008, field:*(this+0x8):0x00000000, field:this:0x0000018C, field:*(this+0x18C):0x00000000, source:raw]
    // RETURN: Return 0 when the dispatch vfunc0 result is 0, aborting the dispatch loop [source:raw]
    // STATE_TRANSITION: On dispatch vfunc0 result 2, exit the loop through the copy-and-handoff path: this+0x84 = this+0x7C then BufferProcessingStateMachine [field:this:0x00000084, field:this:0x0000007C, callee:0x0050FA0E, source:raw]
    // ASSIGNMENT: On dispatch results 1 or 3 with a callback object present at this+0x8: increment the counter at *(this+0x8+4); when the counter reaches the limit at *(this+0x8+8), extend that limit by the increment value this+0x118 [field:this:0x00000008, field:*(this+0x8):0x00000004, field:*(this+0x8):0x00000008, field:this:0x00000118, source:raw]
    // CALL: Invoked by ImageTextureDecompressor (00501722) to drive the state machine [caller:0x00501722]

    // Conservative worker pseudocode:
    //   if (this[4] == 202) {
    //     ObjectConstructor_6f76(this);
    //     if (this[16] != 0) { this[4] = 207; return 1; }
    //     this[4] = 203;
    //   }
    //   state = this[4];
    //   if (state != 203) {
    //     if (state != 204) {
    //       obj = *this;
    //       obj[5] = 18;
    //       obj[6] = this[4];
    //       (obj->vfunc0)(this);
    //     }
    //     return BufferProcessingStateMachine(this);
    //   }
    //   if (*(*(this+396)+16) == 0) {
    //     this[33] = this[31];
    //     return BufferProcessingStateMachine(this);
    //   }
    //   for (;;) {
    //     cb = *(this+8);
    //     if (cb != 0) cb->fn(this);
    //     r = (*(*(this+396))->vfunc0)(this);
    //     if (r == 0) return 0;
    //     if (r == 2) { this[33] = this[31]; return BufferProcessingStateMachine(this); }
    //     cbp = *(this+8);
    //     if (cbp != 0 && (r == 3 || r == 1)) {
    //       cbp->counter = cbp->counter + 1;
    //       cbp2 = *(this+8);
    //       limit = cbp2->limit;
    //       if (cbp2->counter >= limit) cbp2->limit = limit + this[70];
    //     }
    //   }
    // UNRESOLVED: The exact role of the 204 state: it skips the state-code 18 write and vtable dispatch but still falls through to BufferProcessingStateMachine; no caller-side state 204 path is visible in this packet
    // UNRESOLVED: The semantics of the callback counter/limit pair at this+0x8 (chunk progress accounting versus block limit) are not established
    // UNRESOLVED: The state codes 18 (obj+0x14), 202, 203, 204, 207 (this+0x10) are not enumerated by this packet
}
