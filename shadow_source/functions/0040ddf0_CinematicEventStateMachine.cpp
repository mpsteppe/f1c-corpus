// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040DDF0
// Canonical corpus name: CinematicEventStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CinematicEventStateMachine_0040ddf0.c

void UnknownObject::CinematicEventStateMachine()
{
    // State machine for cinematic event playback. When the state at this+0x0 is 2, 3, 4 or 5, searches the string-keyed linked list for the "CinematicEvent" key and hands the result together with the sub-struct at this+0x88 to RaceCommentaryDirectorSystem. On success clears the counters at this+0x98 and this+0x9C, sets state to 2 and returns 1; on failure sets state to -1. States -1, 0 and 1 are blocked and return 0 without changing state. Called by StateMachineInitializer.
    // GUARD: Switch on the state field at this+0x0, dispatched via the jump table at 0x0040DE4C. [field:this:0x00000000, global:0x0040DE4C, source:raw]
    // STATE_TRANSITION: States 0xFFFFFFFF (-1), 0 and 1 are blocked: return 0 without changing state. [field:this:0x00000000, source:raw]
    // CALL: v2 = StringKeyedLinkedListSearch(aCinematicevent) searches the string-keyed linked list for the "CinematicEvent" key. [callee:0x005679C0, global:0x005BEB50, source:raw]
    // CALL: RaceCommentaryDirectorSystem(this+0x88, v2) attempts to start the race commentary director using the sub-struct at this+0x88 and the search result. [callee:0x0040D4C0, field:this:0x00000088, source:raw]
    // GUARD: If RaceCommentaryDirectorSystem returns zero, fall through to the error path. [callee:0x0040D4C0, source:raw]
    // STATE_TRANSITION: On success: clear counters this+0x98 and this+0x9C to 0, set state this+0x0 = 2, and return 1. [field:this:0x00000000, field:this:0x00000098, field:this:0x0000009C, source:raw]
    // STATE_TRANSITION: On failure or unhandled state, set state this+0x0 = -1 and return 0. [field:this:0x00000000, source:raw]
    // RETURN: Return result (1 on successful cinematic start, 0 otherwise). [function:0x0040DDF0, source:raw]
    // CALL: Invoked by StateMachineInitializer (0040dcd0). [caller:0x0040DCD0, source:raw]

    // Conservative worker pseudocode:
    //   switch (*this) {
    //     case -1: case 0: case 1: return 0;
    //     case 2: case 3: case 4: case 5:
    //       v2 = StringKeyedLinkedListSearch(aCinematicevent);
    //       if (!RaceCommentaryDirectorSystem(this[34], v2)) { *this = -1; return 0; }
    //       this[38] = 0; this[39] = 0; *this = 2; return 1;
    //     default: *this = -1; return 0;
    //   }
    // UNRESOLVED: byte_40DE54 is flagged read but never appears in the raw decompiled source; possibly a switch lookup table used indirectly by the jump-table dispatch, unverifiable from this packet.
}
