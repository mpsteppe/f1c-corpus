// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583660
// Canonical corpus name: FloatSetWithTimingCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatSetWithTimingCall_00583660.c

void UnknownObject::FloatSetWithTimingCall()
{
    // Stores the integer parameter a2 into the dword field at this+0x0, then resets the high-precision timer sub-object at this+1 (dword index) via TimerResetUsingQueryPerformanceCounter (0x00568C60) and returns that call's result. Combines a value write with a timer reset; used by timer-init and thread-resume paths.
    // ASSIGNMENT: Write a2 into the field at this+0x0 (the first dword of this). [field:this:0x00000000, source:raw]
    // CALL: Reset the timer sub-object at this+1 via TimerResetUsingQueryPerformanceCounter (0x00568C60). [callee:0x00568C60, source:raw]
    // RETURN: Return the result of TimerResetUsingQueryPerformanceCounter(this+1). [source:raw]
    // CALL: Called by TimerInitWithSEH (0x005835F0), sub_5837F0 (0x005837F0), StartAddress (0x00583D90) and ThreadResumeWithMutexWait (0x00585680). [caller:0x005835F0, caller:0x005837F0, caller:0x00583D90, caller:0x00585680, source:raw]

    // Conservative worker pseudocode:
    //   int FloatSetWithTimingCall(_DWORD* this, int a2) {
    //     this[0] = a2;
    //     return TimerResetUsingQueryPerformanceCounter(this + 1);
    //   }
    // UNRESOLVED: The meaning of the stored value a2 (timing float/flag) is not established from this packet.
    // UNRESOLVED: The owner class exposing both the value field and the timer sub-object is unknown.
}
