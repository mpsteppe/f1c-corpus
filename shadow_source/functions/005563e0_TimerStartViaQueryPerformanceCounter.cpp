// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005563E0
// Canonical corpus name: TimerStartViaQueryPerformanceCounter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerStartViaQueryPerformanceCounter_005563e0.c

void UnknownObject::TimerStartViaQueryPerformanceCounter()
{
    // Timer start/capture: records a fresh high-resolution timestamp into the timer's previous-query fields (offset 0x30 low part, offset 0x34 high part) for later delta computation. Only writes when the timer is initialized (offset 0x0 non-zero) and both timestamp fields are currently zero, so it behaves as a one-shot start guard. Source of the timestamp is selected by a mode flag at offset 0x48: bit 0 set uses QueryPerformanceCounter, otherwise RDTSC via RDTSCTimestampRead.
    // GUARD: Read timer state at offset 0x0; if zero (timer not initialized) skip timestamp capture and return the existing value. [field:this:0x00000000, source:raw]
    // GUARD: If the previous-query high part at offset 0x34 is already non-zero, skip and return the existing value. [field:this:0x00000034, source:raw]
    // GUARD: If the previous-query low part at offset 0x30 is already non-zero, skip and return the existing value. [field:this:0x00000030, source:raw]
    // GUARD: Inspect the mode flags at offset 0x48; bit 0 set selects the QueryPerformanceCounter path, otherwise the RDTSC path. [field:this:0x00000048, source:raw]
    // CALL: QueryPerformanceCounter fills a 64-bit performance counter into a local LARGE_INTEGER. [global:0x0059E23C, source:raw]
    // ASSIGNMENT: Store the captured counter: high part to offset 0x34, low part to offset 0x30. [field:this:0x00000034, field:this:0x00000030, source:raw]
    // CALL: RDTSC path: call RDTSCTimestampRead with pointers to offsets 0x34 and 0x30 as the timestamp output targets. [callee:0x0055687B, source:raw]
    // RETURN: Return the timer state value; a zero result means the capture was skipped. [source:raw]

    // Conservative worker pseudocode:
    //   int TimerStartViaQueryPerformanceCounter(int *this) {
    //     if (!this[0]) return this[0];
    //     if (this[13] || this[12]) return this[0];
    //     if (this[18] & 1) { QueryPerformanceCounter(&pc); this[13] = pc.HighPart; this[12] = pc.LowPart; }
    //     else return RDTSCTimestampRead(&this[13], &this[12]);
    //     return this[0];
    //   }
    // UNRESOLVED: Meaning of the flag field at offset 0x48 beyond bit 0 (QPC vs RDTSC selection) is unknown.
    // UNRESOLVED: Whether the timer captures time elapsed or a raw tick for a specific subsystem is unproven.
    // UNRESOLVED: byte_FF00000000005406 is read by this function per deterministic facts but is not visible in the decompiled source; role unknown.
}
