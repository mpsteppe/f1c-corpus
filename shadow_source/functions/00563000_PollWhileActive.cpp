// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563000
// Canonical corpus name: PollingLoopWithProcessCalls
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PollingLoopWithProcessCalls_00563000.c

void UnknownObject::PollWhileActive()
{
    // Blocking poll loop: while the flag at this+0x0 is non-zero, calls sub_563410(this) to process the object, then assigns the return value of SleepWrapper(0xA) (a 10 ms sleep) as the loop update. Returns the last SleepWrapper result.
    // LOOP: Iterate while the active flag at this+0x0 is non-zero; each iteration runs the body then sleeps. [field:this:0x00000000, source:raw]
    // CALL: Call sub_563410(this) to perform per-iteration processing on the object. [callee:0x00563410]
    // CALL: Call SleepWrapper(0xA) (10 ms) as the loop update action and assign its return value to result. [callee:0x00564650, source:raw]
    // RETURN: Return the last SleepWrapper result after the flag clears. [source:raw]

    // Conservative worker pseudocode:
    //   int PollWhileActive(_DWORD* this) {
    //     int result;
    //     for (; *this; result = SleepWrapper(0xA))
    //       sub_563410(this);
    //     return result;
    //   }
    // UNRESOLVED: Identity of the object and of the flag at this+0x0; it is likely an active/running state, but who clears it is not visible here.
    // UNRESOLVED: What sub_563410 actually processes is not recoverable from this function alone.
    // UNRESOLVED: If the flag is false on entry the loop body never runs and the returned result is uninitialized.
}
