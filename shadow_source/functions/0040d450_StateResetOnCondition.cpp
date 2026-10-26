// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D450
// Canonical corpus name: StateResetOnCondition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateResetOnCondition_0040d450.c

void UnknownObject::StateResetOnCondition()
{
    // Conditional state-field reset on this+0x14 (dword index 5). If the state field equals 3, it is reset to -1 and GameActionStateMachine(this, 3, 0) is called, returning the state-machine result. Otherwise the function returns without action; the decompiled else path returns an uninitialized result register.
    // GUARD: Test state field this[5] (byte offset +0x14); proceed only when it equals 3. [guard:0, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Reset the state field this[5] (byte offset +0x14) to -1 before dispatching the state transition. [field:this:0x00000014, source:raw]
    // CALL: Call GameActionStateMachine(this, 3, 0) to process game action 3 with sub-action 0, and return its result. [callee:0x0040CDE0, source:raw]
    // RETURN: Return: the state-machine result on the reset path; on the non-matching path control falls through to the uninitialized result register. [source:raw]

    // Conservative worker pseudocode:
    //   if (this[5] == 3) {
    //     this[5] = -1;
    //     return GameActionStateMachine(this, 3, 0);
    //   }
    //   return result;  // decompiler artifact: uninitialized on this path
    // UNRESOLVED: Semantics of state value 3 and sentinel -1 (which state is being exited and reset) depend on the caller TrackTemperatureDisplay's state machine; not established by this packet.
    // UNRESOLVED: The else path returns an uninitialized result register; likely dead code or a decompiler artifact, but no raw-source evidence decides it.
    // UNRESOLVED: The +0x14 field is a dword (state code); the exact owner object type is unknown.
}
