// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9F60
// Canonical corpus name: TimeOffsetGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimeOffsetGetter_004f9f60.c

void UnknownObject::TimeOffsetGetter()
{
    // __thiscall double-valued getter: computes a scaled performance-counter difference from this via PerformanceCounterDiffWithScaling (0x00568D90), adds the read-only global double dbl_8AFEA0 (0x008AFEA0), and returns the sum. Called by SessionSynchronizer (0x0045F950). The ABI name Time_Offset_Getter and the caller context are consistent with a time-offset (session clock offset) readout, but that semantic rests on the caller, not on this packet.
    // CALL: Compute the scaled performance-counter difference for this via PerformanceCounterDiffWithScaling (0x00568D90). [callee:0x00568D90, source:raw]
    // CALCULATION: Add the read-only global double dbl_8AFEA0 (0x008AFEA0) to the scaled counter difference. [global:0x008AFEA0, source:raw]
    // RETURN: Return the resulting double sum as the getter result. [source:raw]
    // CALL: Invoked by SessionSynchronizer (0x0045F950), which reads the resulting time offset. [caller:0x0045F950, source:raw]

    // Conservative worker pseudocode:
    //   double TimeOffsetGetter(void* this) {
    //     return PerformanceCounterDiffWithScaling(this) + dbl_8AFEA0;
    //   }
    // UNRESOLVED: Meaning of the additive global dbl_8AFEA0 (a session start time, a fixed offset, or a per-session bias) is not determinable from this packet alone.
}
