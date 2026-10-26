// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005835F0
// Canonical corpus name: TimerInitWithSEH
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerInitWithSEH_005835f0.c

void UnknownObject::TimerInitWithSEH()
{
    // Initializes a high-precision timer object: zero-initializes the timer data area at this+1 (dword index), configures a QPC (QueryPerformanceCounter) timer, and applies a timing float parameter, then returns the this pointer. The body carries the SEH handler SEH_5835F0 (global 0x0059CE4B).
    // CALL: StructZeroInit_8ba0(this+1) zero-initializes the timer data area at this+1 (dword index); the body runs under the function's SEH handler SEH_5835F0 (global 0x0059CE4B). [callee:0x00568BA0, global:0x0059CE4B, source:raw]
    // CALL: QPCTimerInitialization(this+1, 1) configures the QueryPerformanceCounter-based high-precision timer with flag 1. [callee:0x00568BE0, source:raw]
    // CALL: FloatSetWithTimingCall(0) applies the timing float parameter with value 0. [callee:0x00583660, source:raw]
    // RETURN: Return the this pointer (thiscall object). [source:raw]
    // CALL: Called by sub_5837F0 (0x005837F0) and StartAddress (0x00583D90). [caller:0x005837F0, caller:0x00583D90, source:raw]

    // Conservative worker pseudocode:
    //   void TimerInitWithSEH(void* this) {
    //     double* timer = (double*)(this + 1);
    //     StructZeroInit_8ba0(this + 1);
    //     QPCTimerInitialization(timer, 1);
    //     FloatSetWithTimingCall(0);
    //     return this;
    //   }
    // UNRESOLVED: The owning class of the timer object is unknown.
    // UNRESOLVED: Whether SEH_5835F0 at 0x0059CE4B is the timer frame's own compiler-generated registration is not confirmed.
    // UNRESOLVED: The meaning of the flag argument 1 to QPCTimerInitialization and the float argument 0 to FloatSetWithTimingCall is not established.
}
