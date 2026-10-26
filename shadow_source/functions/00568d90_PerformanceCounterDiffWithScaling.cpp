// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568D90
// Canonical corpus name: PerformanceCounterDiffWithScaling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerformanceCounterDiffWithScaling_00568d90.c

void UnknownObject::PerformanceCounterDiffWithScaling()
{
    // Reads a fresh performance-counter timestamp via QPCTimestampReadWrapper, subtracts two stored 64-bit counter pairs (this+0x18/0x1C and this+0x28/0x2C), and converts the 64-bit difference into a scaled double: the low dword divided by a divisor derived from the integer at this+0x0, plus the high dword scaled by the double at this+0x8, plus the double at this+0x10. Twin of HighPrecisionTimerCounterArithmetic (005565b0) per the packet prelabel.
    // ASSIGNMENT: Snapshot the two stored 64-bit counter pairs from this+0x18/0x1C (low/high) and this+0x28/0x2C before sampling the timestamp. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000028, field:this:0x0000002C]
    // CALL: Call QPCTimestampReadWrapper(this, high_ptr, low_ptr) to capture the current performance-counter timestamp into v7. [callee:0x00568CB0]
    // CALCULATION: Subtract both stored counter pairs from the fresh sample: v7 = v7 - pair(0x18,0x1C) - pair(0x28,0x2C). [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000028, field:this:0x0000002C]
    // ASSIGNMENT: Read the integer at this+0x0 to seed the divisor used in the result conversion. [field:this:0x00000000]
    // CALCULATION: Scale the difference into a double: (double)(unsigned int)v7 / divisor + (double)(unsigned int)(v7 >> 32) * this[1] + this[2], using the scale double at this+0x8 and the offset double at this+0x10. [field:this:0x00000008, field:this:0x00000010, abi:lead]
    // RETURN: Return the scaled double result. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_568D90(double *this) {
    //     unsigned __int64 now;
    //     QPCTimestampReadWrapper(this, (LONG *)&now + 1, (DWORD *)&now);
    //     unsigned __int64 d = now - __PAIR64__(this[7], this[6]) - __PAIR64__(this[11], this[10]);
    //     unsigned __int64 v11 = ((d >> 32) << 32) | (unsigned int)this[0];
    //     return (double)(unsigned int)d / (double)v11 + (double)(unsigned int)(d >> 32) * this[1] + this[2];
    //   }
    // UNRESOLVED: Exact composition of the divisor (integer at this+0x0 combined with the sample high dword) is decompiler-artifacted; the source-level intent is not recoverable from this packet.
    // UNRESOLVED: What the two stored 64-bit counter pairs at this+0x18/0x1C and this+0x28/0x2C represent (prior samples vs. per-frame accumulations) is unknown.
    // UNRESOLVED: The semantics of the scale double at this+0x8 and the offset double at this+0x10 depend on the owning timer object, which is unidentified.
}
