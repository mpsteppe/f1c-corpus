// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005564B0
// Canonical corpus name: QueryPerformanceCounterWrapperWithModeDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QueryPerformanceCounterWrapperWithModeDispatch_005564b0.c

void UnknownObject::QueryPerformanceCounterWrapperWithModeDispatch()
{
    // Timer-mode dispatcher on a __thiscall timer object. Always returns 0. If the timer is initialized (first dword at offset 0x0 non-zero) it loads the mode flags dword at offset 0x48; when bit 0 is set it queries QueryPerformanceCounter and stores HighPart/LowPart into the caller-provided output pointers a2/a3; when bit 1 is set it fills those same outputs via RDTSCTimestampRead.
    // GUARD: Guard on the timer object being initialized: read the first dword at offset 0x0; when it is zero, skip the mode dispatch and fall through to the final return of 0. [field:this:0x00000000, source:raw]
    // CALCULATION: Load the timer mode flags dword at offset 0x48 (this[18]) into a working register. [field:this:0x00000048, source:raw]
    // GUARD: Test mode bit 0 (flags & 1); when set, dispatch through the QueryPerformanceCounter path. [field:this:0x00000048, source:raw]
    // CALL: Call QueryPerformanceCounter (import address at global 0x0059E23C) with a stack LARGE_INTEGER to receive the performance counter value. [global:0x0059E23C, source:raw]
    // ASSIGNMENT: Store PerformanceCount.HighPart into the caller-provided output pointer a2. [source:raw]
    // ASSIGNMENT: Store PerformanceCount.LowPart into the caller-provided output pointer a3. [source:raw]
    // RETURN: Return 0 after the QueryPerformanceCounter branch. [source:raw]
    // GUARD: Test mode bit 1 (flags & 2); when set, dispatch to the RDTSC path. [field:this:0x00000048, source:raw]
    // CALL: Call RDTSCTimestampRead(a2, a3) to fill the output pointers from the CPU timestamp counter. [callee:0x0055687B, source:raw]
    // RETURN: Final unconditional return of 0 when the timer is uninitialized or neither mode bit is set. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5564B0(Obj *this, long *outHigh, unsigned long *outLow) {
    //     if (!this->field_0) return 0;
    //     unsigned flags = this->field_48;
    //     if (flags & 1) {
    //       LARGE_INTEGER c;
    //       QueryPerformanceCounter(&c);
    //       *outHigh = c.HighPart;
    //       *outLow = c.LowPart;
    //       return 0;
    //     }
    //     if (flags & 2) RDTSCTimestampRead(outHigh, outLow);
    //     return 0;
    //   }
    // UNRESOLVED: Purpose of the read of byte_FF00000000005406 is unknown; possibly processor feature flags the compiler folded into the mode decision.
    // UNRESOLVED: Owner object behind `this` is unknown; only offsets 0x0 (initialized/frequency marker) and 0x48 (mode flags) are observed here.
}
