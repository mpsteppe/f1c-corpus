// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054EAC0
// Canonical corpus name: sub_54EAC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54EAC0_0054eac0.c

void UnknownObject::Thunk_eac0()
{
    // Thunk that calls BooleanToIntConversion on the function pointer stored at 0x0054EAD0 and returns its result. The referenced global carries the name MainLoopHeartbeat1024 and is read only.
    // CALL: Call BooleanToIntConversion with the value at 0x0054EAD0 (global MainLoopHeartbeat1024) as its integer argument. [callee:0x00587B3E, global:0x0054EAD0, source:raw]
    // RETURN: Return the result of the BooleanToIntConversion call. [function:0x0054EAC0, source:raw]

    // Conservative worker pseudocode:
    //   int Thunk_eac0()
    //   {
    //     return BooleanToIntConversion((int)MainLoopHeartbeat1024);
    //   }
    // UNRESOLVED: Whether the global at 0x0054EAD0 holds a function pointer to a main-loop heartbeat (per its label) or a plain value, and why it is cast through BooleanToIntConversion, is not confirmed.
    // UNRESOLVED: The behavior and side effects of BooleanToIntConversion at 0x00587B3E are not examined here.
}
