// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5C80
// Canonical corpus name: StateChangeNotify
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/StateChangeNotify_004a5c80.c

void F1CPitMachine::StateChangeNotify()
{
    // Records a pit-machine state change. Reads the current state at this+0x184 (388) and returns unchanged when the new state a2 equals it. On a genuine transition, optionally stamps the session time from dbl_8AFEA0 into this+0x18C (396) for transitions to 1 or to 2 from a state other than 1, advances a ring-buffer write cursor (dword_8AAE64) once a bounded counter (dword_83EE60, cap 1023) permits, encodes a progress-bar event of type 6 using the event id at this+4, writes a2 into the new ring-buffer entry, and dispatches the AI state machine on that entry.
    // ASSIGNMENT: Read result = *(this + 0x184), the current pit-machine state. [field:this:0x00000184, source:raw]
    // GUARD: Guard: when a2 == result (no state change) return result immediately. [source:raw]
    // GUARD: Guard: stamp the session timestamp into this+0x18C when a2 == 1, or when result != 1 and a2 == 2. [field:this:0x0000018C, source:raw]
    // ASSIGNMENT: Write *(this + 0x18C) = dbl_8AFEA0 (record session time on the transition). [field:this:0x0000018C, global:0x008AFEA0, source:raw]
    // ASSIGNMENT: Read v3 = dword_8AAE64, the ring-buffer write pointer. [global:0x008AAE64, source:raw]
    // GUARD: Guard: only advance the ring buffer while dword_83EE60 < 1023. [global:0x0083EE60, source:raw]
    // CALCULATION: Increment dword_83EE60 and advance the write pointer: dword_8AAE64 += 432 (entry stride). [global:0x0083EE60, global:0x008AAE64, source:raw]
    // CALL: Call ProgressBarEventEncode(6, 1, 1, *(this + 4), LODWORD(dbl_8AFEA0), 0) to encode a progress-bar event using the event id at this+4. [callee:0x004B33B0, field:this:0x00000004, global:0x008AFEA0, source:raw]
    // ASSIGNMENT: Write the new state into the ring-buffer entry: *(v3 + 8) = a2. [source:raw]
    // CALL: Call AIStateMachineWithModeDispatch(v3) to process the newly recorded ring-buffer entry. [callee:0x004A5D10, source:raw]
    // RETURN: Return result (the prior state) when no transition occurred. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A5C80(F1CPitMachine* this, int a2) {
    //     int result = *(int*)((char*)this + 0x184);
    //     if (a2 != result) {
    //       if (a2 == 1 || (result != 1 && a2 == 2))
    //         *(float*)((char*)this + 0x18C) = dbl_8AFEA0;
    //       int v3 = dword_8AAE64;
    //       if (dword_83EE60 < 1023) {
    //         ++dword_83EE60;
    //         dword_8AAE64 += 432;
    //       }
    //       float v4 = dbl_8AFEA0;
    //       ProgressBarEventEncode(6, 1, 1, *(int*)((char*)this + 4), LODWORD(v4), 0);
    //       *(char*)(v3 + 8) = a2;
    //       return AIStateMachineWithModeDispatch(v3);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Exact meaning of state values 1 and 2 for the pit machine is not established by this packet.
    // UNRESOLVED: The 432-byte ring-buffer entry layout beyond offset +8 is unknown.
    // UNRESOLVED: Semantics of dbl_8AFEA0 (existing analysis proposes session time) are not proven by this packet.
}
