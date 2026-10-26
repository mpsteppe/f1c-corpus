// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042A110
// Canonical corpus name: ForcePitExit
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/ForcePitExit_0042a110.c

void F1CVehicle::ForcePitExit()
{
    // Per-frame AI pit-state forcing call on an F1CVehicle. For race sessions (dword_7C56A4 == 7) it only acts when the current lap (+0x403C) is not the last lap (dword_8ACF8C - 1) AND TeammatePartValueLookup returns 0, 4, or FinishState (+0x4064) equals 1; on pass it runs StateConditionalAction on the pit controller (this+3251) and returns AIStateFlagSetter(1). For non-race sessions it runs the same two calls unconditionally. When blocked it returns the last-lap or teammate value.
    // GUARD: If session type dword_7C56A4 == 7, take the race-session path; otherwise force exit unconditionally. [global:0x007C56A4, source:raw]
    // CALCULATION: Compute the last-lap value as dword_8ACF8C - 1. [global:0x008ACF8C, source:raw]
    // GUARD: If lapNumber at +0x403C (this[4111]) is not the last lap, continue to the teammate check; otherwise stay blocked. [field:this:0x0000403C, global:0x008ACF8C, source:raw]
    // CALL: Call TeammatePartValueLookup(this + 3251) on the pit controller and keep the result. [callee:0x004A5C40, source:raw]
    // GUARD: Proceed only if the teammate lookup result is 0, is 4, or FinishState at +0x4064 equals 1 (guard:0). [callee:0x004A5C40, field:this:0x00004064, guard:0, source:raw]
    // CALL: Call StateConditionalAction(this + 3251) on the pit controller. [callee:0x004A5E40, source:raw]
    // CALL: Call AIStateFlagSetter(1) and return its result on the pass path. [callee:0x0042AC70, source:raw]
    // CALL: Non-race path: call StateConditionalAction(this + 3251) and return AIStateFlagSetter(1). [callee:0x004A5E40, callee:0x0042AC70, source:raw]
    // RETURN: When blocked (race path but not passing the guards), return the previously computed result (last-lap value or teammate value). [source:raw]

    // Conservative worker pseudocode:
    //   force_pit_state(vehicle) {
    //       if (dword_7C56A4 == 7) {
    //           result = dword_8ACF8C - 1;
    //           if (this[4111] != dword_8ACF8C - 1) {
    //               result = TeammatePartValueLookup(this + 3251);
    //               if (!result || result == 4 || this[4121] == 1) {
    //                   StateConditionalAction(this + 3251);
    //                   return AIStateFlagSetter(1);
    //               }
    //           }
    //       } else {
    //           StateConditionalAction(this + 3251);
    //           return AIStateFlagSetter(1);
    //       }
    //       return result;
    //   }
    // UNRESOLVED: The historical name 'ForcePitExit' conflicts with the packet ABI name 'RequestPitEntry': the abi evidence states the disassembly enters pit state 1 and sets CallToBox=1, implying pit-entry request semantics, while the established canonical name remains ForcePitExit. Not resolvable from packet evidence alone.
    // UNRESOLVED: The pit controller pointer this+3251 (byte offset +0x32CC) is passed to both callees but is not packet-listed as a field; only the raw source indexes it.
}
