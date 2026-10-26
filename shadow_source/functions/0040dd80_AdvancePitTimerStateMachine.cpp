// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040DD80
// Canonical corpus name: ShortComputation_dd80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_dd80_0040dd80.c

void UnknownObject::AdvancePitTimerStateMachine()
{
    // State machine driven by the state word at this+0x0 and called by PitTimer (0x004D2E50). States -1 (0xFFFFFFFF), 0, 1 and 5 are blocked and return 0 with no mutation. States 2 and 3 dispatch a virtual call through the pointer at this+0x4, store the dispatch result into this+0x8C and this+0x90, write the global dword_7C54DC (CurrentPlayerIndex) into this+0x94, transition to state 4 and return 1. State 4 is the active state and returns 1. Any other state value is treated as an error: the state word is set to -1 and the function returns 0.
    // GUARD: Dispatch on the state word at this+0x0 through the jump table jpt_40DD8B; states 0xFFFFFFFF, 0, 1 and 5 fall through to the blocked path. [field:this:0x00000000, global:0x0040DDC8, source:raw]
    // GUARD: Default case: a state value not in the handled set is an error, so the state word is set to 0xFFFFFFFF. [field:this:0x00000000, source:raw]
    // CALL: Call VirtualDispatchHelper with the pointer stored at this+0x4; the returned pointer is captured as v2. [callee:0x0040C870, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store the dispatch result into the two consecutive slots this+0x8C and this+0x90. [field:this:0x0000008C, field:this:0x00000090, source:raw]
    // ASSIGNMENT: Store the global dword_7C54DC (CurrentPlayerIndex) into this+0x94. [field:this:0x00000094, global:0x007C54DC, source:raw]
    // STATE_TRANSITION: On states 2 and 3 the state word is set to 4, entering the active state. [field:this:0x00000000, source:raw]
    // RETURN: Return 1 for the active states (4, and 2/3 after the transition); return 0 for the blocked, default and error paths. [source:raw]

    // Conservative worker pseudocode:
    //   bool AdvancePitTimerStateMachine(void **this) {
    //     switch ((unsigned)this[0]) {
    //       case 0xFFFFFFFF: case 0: case 1: case 5:
    //         return false;                       // blocked / inactive
    //       case 2: case 3:
    //         void *r = VirtualDispatchHelper(this[1]);
    //         this[0x8C/4] = r;
    //         this[0x90/4] = r;
    //         this[0x94/4] = dword_7C54DC;        // CurrentPlayerIndex
    //         this[0] = 4;                        // active
    //         return true;
    //       case 4:
    //         return true;                        // already active
    //       default:
    //         this[0] = 0xFFFFFFFF;               // error state
    //         return false;
    //     }
    //   }
    // UNRESOLVED: Why the VirtualDispatchHelper result is written to both this+0x8C and this+0x90.
    // UNRESOLVED: How PitTimer (0x004D2E50) consumes the returned boolean and the stored CurrentPlayerIndex at this+0x94.
}
