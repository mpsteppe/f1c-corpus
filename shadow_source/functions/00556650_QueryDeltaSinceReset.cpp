// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556650
// Canonical corpus name: HighResolutionTimerDeltaCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HighResolutionTimerDeltaCalculation_00556650.c

void UnknownObject::QueryDeltaSinceReset()
{
    // High-resolution timer reference-delta query. Dispatches a fresh timestamp through QueryPerformanceCounterWrapperWithModeDispatch, subtracts the stored reference timestamp at this+0x18/0x1C, and converts the tick delta to seconds using the frequency word at this+0x0 and the reciprocal scaling factor at this+0x8. Does not modify any stored field.
    // ASSIGNMENT: Read reference timestamp low part from this+0x18. [field:this:0x00000018]
    // ASSIGNMENT: Read reference timestamp high part from this+0x1C. [field:this:0x0000001C]
    // CALL: Query the current performance counter timestamp through QueryPerformanceCounterWrapperWithModeDispatch, writing low part and high part. [callee:0x005564B0]
    // CALCULATION: Compute 64-bit delta as current timestamp minus the stored reference timestamp. [field:this:0x00000018, field:this:0x0000001C]
    // CALCULATION: Read timer frequency low word at this+0x0 and divide the delta low part by it. [field:this:0x00000000]
    // CALCULATION: Multiply the delta high part by the reciprocal scaling factor at this+0x8 and add the low-part quotient to obtain elapsed seconds. [field:this:0x00000008]
    // RETURN: Return the computed elapsed time in seconds since the reference timestamp. [function:0x00556650]

    // Conservative worker pseudocode:
    //   low_ref = this->ref_low;
    //   high_ref = this->ref_high;
    //   dispatch_timer(this, &current_low, &current_high);
    //   delta = (current_high << 32 | current_low) - (high_ref << 32 | low_ref);
    //   return (double)(unsigned int)delta / this->freq_low + (double)(int)(delta >> 32) * this->scale_factor;
    // UNRESOLVED: Whether the reference timestamp at this+0x18/0x1C is set by a separate reset call is not established by this packet.
}
