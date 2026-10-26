// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583680
// Canonical corpus name: FloatAdditionReturnsFUN00568d90Param1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatAdditionReturnsFUN00568d90Param1_00583680.c

void UnknownObject::FloatAdditionReturnsFUN00568d90Param1()
{
    // Accumulated-timer read: computes a scaled QueryPerformanceCounter difference from the 8-byte double at this+4 via PerformanceCounterDiffWithScaling (0x00568D90), then adds the float at this+0 and returns the resulting double. Used by the mutex-guarded and thread-resume timer read paths.
    // CALL: Compute the scaled performance-counter difference on the double at this+4 via PerformanceCounterDiffWithScaling (0x00568D90). [callee:0x00568D90, source:raw]
    // CALCULATION: Add the float read at this+0 to the scaled counter difference to form the accumulated double. [field:this:0x00000000, source:raw]
    // RETURN: Return the double sum of the scaled counter difference and the float at this+0. [source:raw]
    // CALL: Called by StartAddress (0x00583D90), MutexGuardedTimerRead (0x00584F90) and ThreadResumeWithMutexWait (0x00585680). [caller:0x00583D90, caller:0x00584F90, caller:0x00585680, source:raw]

    // Conservative worker pseudocode:
    //   double FloatAdditionReturnsFUN00568d90Param1(char* this) {
    //     return PerformanceCounterDiffWithScaling((double*)(this + 4)) + *(float*)this;
    //   }
    // UNRESOLVED: The packet field list records only this+0x0; the this+4 double (the counter base) has no packet field evidence reference, only the raw source text.
    // UNRESOLVED: Whether the float at this+0 is a running accumulator or a fixed offset is not established.
    // UNRESOLVED: The owner class of the timer object is unknown.
}
