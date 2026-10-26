// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A610
// Canonical corpus name: AnimationValueFetchWithTiming
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AnimationValueFetchWithTiming_0057a610.c

void UnknownObject::AnimationValueFetchWithTiming()
{
    // Timed animation-value query wrapper. Reads the current timer value through MutexGuardedTimerRead on the object pointed to by *this (this+0x0), passes it together with a3 and a4 into PhysicsQueryGetterWithReadyFlag, and fills the caller-supplied output a2 with an 8-byte (double) value on success, returning 1; on query failure returns 0 without writing a2.
    // CALL: MutexGuardedTimerRead(*this): reads the guarded timer value from the object referenced by this+0x0 [callee:0x00584F90, field:this:0x00000000, source:raw]
    // CALL: PhysicsQueryGetterWithReadyFlag((int)v6, a3, a4, v4): fills the v6 stack buffer, forwarding a3, a4 and the captured timer value [callee:0x00583790, source:raw]
    // GUARD: When PhysicsQueryGetterWithReadyFlag returns 0 the function exits early with 0 and leaves a2 unwritten [callee:0x00583790, source:raw]
    // ASSIGNMENT: On success the 8-byte value in v6 is copied into the caller's float buffer a2 [source:raw]
    // RETURN: Return 1 on success, 0 on query failure [source:raw]
    // CALL: Used by RunCollisionDetectionLoop (0x0045F390) and SessionSynchronizer (0x0045F950) to fetch a timed animation value during their per-frame work [caller:0x0045F390, caller:0x0045F950, abi:lead]

    // Conservative worker pseudocode:
    //   bool AnimationValueFetchWithTiming(this, float *a2, int a3, int a4) {
    //     double v4 = MutexGuardedTimerRead(*this);
    //     int v6[2];
    //     if (!PhysicsQueryGetterWithReadyFlag((int)v6, a3, a4, v4)) return 0;
    //     *a2 = *(double *)v6;
    //     return 1;
    //   }
    // UNRESOLVED: The meaning of the a3/a4 query selectors and the semantics of the fetched value are unknown
    // UNRESOLVED: The owner class behind the this handle is unknown
}
