// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556330
// Canonical corpus name: TimerAccumulateViaQueryPerformanceCounter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerAccumulateViaQueryPerformanceCounter_00556330.c

void UnknownObject::TimerAccumulateViaQueryPerformanceCounter()
{
    // __thiscall timer tick accumulator. When the timer is initialized and a previous timestamp is recorded, samples the current high-resolution timestamp via QueryPerformanceCounter (bit 0 of mode flags at +0x48 set) or RDTSC read, subtracts the previous timestamp to get the elapsed delta, and adds it to the running accumulator at +0x28/+0x2C. Clears the previous-timestamp fields at +0x30/+0x34 afterward. Returns 0 when any guard fails.
    // GUARD: Entry guard: skip the entire accumulation when the dword at +0x00 is zero (timer frequency / initialized flag not set). [field:this:0x00000000, function:0x00556330]
    // GUARD: Guard on previous timestamp high part at +0x34 (this[13]); accumulation proceeds only when nonzero. [field:this:0x00000034]
    // GUARD: Guard on previous timestamp low part at +0x30 (this[12]); accumulation proceeds only when nonzero. [field:this:0x00000030]
    // GUARD: Mode flag check: bit 0 of the dword at +0x48 (this[18]) selects QueryPerformanceCounter when set, RDTSC otherwise. [field:this:0x00000048]
    // CALL: QueryPerformanceCounter(&PerformanceCount) samples the current count when the QPC mode bit is set. [global:0x0059E23C]
    // CALL: RDTSCTimestampRead fills the timestamp (v5) when the QPC mode bit is clear; the referenced feature-flag byte is consulted by this read path. [callee:0x0055687B, global:0xFF00000000005406]
    // CALCULATION: Elapsed delta = new timestamp - previous timestamp, where previous comes from this[12]/this[13] at +0x30/+0x34. [field:this:0x00000030, field:this:0x00000034]
    // CALCULATION: Accumulate delta into the running total: low part added to +0x28 (this[10]), high part plus carry added to +0x2C (this[11]). [field:this:0x00000028, field:this:0x0000002C]
    // ASSIGNMENT: Clear the previous-timestamp fields this[12]=0 and this[13]=0 after the delta has been accumulated. [field:this:0x00000030, field:this:0x00000034]
    // RETURN: Return 0 when any entry guard fails; otherwise fall through with the accumulation performed. [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   unsigned int TimerAccumulateViaQueryPerformanceCounter(void *this) {
    //     if (!*(unsigned int*)this) return 0;
    //     if (!*((unsigned int*)this + 13)) return 0;
    //     if (!*((unsigned int*)this + 12)) return 0;
    //     LARGE_INTEGER prev, now, delta;
    //     if (*((unsigned int*)this + 18) & 1) QueryPerformanceCounter(&now);
    //     else RDTSCTimestampRead((char*)&now.QuadPart + 4, &now);
    //     prev.LowPart = *((unsigned int*)this + 12);
    //     prev.HighPart = *((unsigned int*)this + 13);
    //     delta.QuadPart = now.QuadPart - prev.QuadPart;
    //     *((unsigned int*)this + 10) += delta.LowPart;
    //     *((unsigned int*)this + 11) += delta.HighPart;
    //     *((unsigned int*)this + 12) = 0;
    //     *((unsigned int*)this + 13) = 0;
    //     return result;
    //   }
    // UNRESOLVED: Owner class of the timer object is unknown; no static callers were found, so lifecycle and field-role confirmation (+0x00 frequency, +0x48 mode flags) are unproven.
    // UNRESOLVED: Purpose of global byte at 0xFF00000000005406 (RW) is unknown; possibly processor feature flags consulted during the RDTSC path.
    // UNRESOLVED: Return value of the fall-through path is an unspecified leftover register value.
}
