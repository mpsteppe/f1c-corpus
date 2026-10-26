// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556510
// Canonical corpus name: PerformanceCounterTimerWithScaling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerformanceCounterTimerWithScaling_00556510.c

void UnknownObject::GetElapsedTimeSeconds()
{
    // High-resolution timer elapsed-time query. Reads the previous timestamp stored at this+0x20/0x24, dispatches a fresh timestamp through QueryPerformanceCounterWrapperWithModeDispatch, stores the new timestamp back to those fields, and converts the tick delta to seconds using the frequency word at this+0x0 and the reciprocal scaling factor at this+0x8.
    // ASSIGNMENT: Read previous timestamp low part from this+0x20. [field:this:0x00000020]
    // ASSIGNMENT: Read previous timestamp high part from this+0x24. [field:this:0x00000024]
    // CALL: Query the current performance counter timestamp through QueryPerformanceCounterWrapperWithModeDispatch, writing low part and high part. [callee:0x005564B0]
    // CALCULATION: Compute 64-bit delta as current timestamp minus previous timestamp. [field:this:0x00000020, field:this:0x00000024]
    // ASSIGNMENT: Store current timestamp low part back to this+0x20. [field:this:0x00000020]
    // ASSIGNMENT: Store current timestamp high part back to this+0x24. [field:this:0x00000024]
    // CALCULATION: Read timer frequency low word at this+0x0 and divide the delta low part by it. [field:this:0x00000000]
    // CALCULATION: Multiply the delta high part by the reciprocal scaling factor at this+0x8 and add the low-part quotient to obtain elapsed seconds. [field:this:0x00000008]
    // RETURN: Return the computed elapsed time in seconds. [function:0x00556510]

    // Conservative worker pseudocode:
    //   low_prev = this->prev_low;
    //   high_prev = this->prev_high;
    //   dispatch_timer(this, &current_low, &current_high);
    //   delta = (current_high << 32 | current_low) - (high_prev << 32 | low_prev);
    //   this->prev_low = current_low;
    //   this->prev_high = current_high;
    //   return (double)(unsigned int)delta / this->freq_low + (double)(int)(delta >> 32) * this->scale_factor;
    // UNRESOLVED: Exact signed/unsigned treatment of the delta high part in the returned expression depends on how the dispatcher packs the timestamp; not resolvable from this packet alone.
}
