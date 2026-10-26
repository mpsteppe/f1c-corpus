// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568CB0
// Canonical corpus name: QPCTimestampReadWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QPCTimestampReadWrapper_00568cb0.c

void UnknownObject::QPCTimestampReadWrapper()
{
    // Conditionally reads the high-resolution performance counter into two caller-supplied output values. When the timer object at this+0x0 is non-zero (initialized) and bit 0 of the flags at this+0x48 is set, it invokes QueryPerformanceCounter (via the API pointer at global 0x0059E23C) and stores the HighPart into *a2 and LowPart into *a3. Always returns 0.
    // GUARD: Guard: proceed only when the dword at this+0x0 is non-zero AND bit 0 of the dword at this+0x48 is set; otherwise skip the counter read and leave the output parameters untouched. [field:this:0x00000000, field:this:0x00000048]
    // CALL: Call QueryPerformanceCounter through the function pointer stored at global 0x0059E23C, filling the local LARGE_INTEGER PerformanceCount. [global:0x0059E23C]
    // ASSIGNMENT: Store PerformanceCount.HighPart into the caller's first output pointer *a2. [source:raw]
    // ASSIGNMENT: Store PerformanceCount.LowPart into the caller's second output pointer *a3. [source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_568CB0(_BYTE* this, LONG* a2, DWORD* a3) {
    //     LARGE_INTEGER PerformanceCount;
    //     if (*(DWORD*)this && (this[72] & 1) != 0) {
    //       QueryPerformanceCounter(&PerformanceCount);
    //       *a2 = PerformanceCount.HighPart;
    //       *a3 = PerformanceCount.LowPart;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The byte at global 0xFF00000000005406 is referenced by the corpus but does not appear in the raw source; its role is unknown.
    // UNRESOLVED: Semantics of field this+0x0 (assumed initialized-timer marker) and of bit 0 of this+0x48 (assumed QPC-enable mode flag) are inferred from the guards and callers, not proven.
    // UNRESOLVED: How the callers HighResolutionTimerDelta (0x00568CF0) and PerformanceCounterDiffWithScaling (0x00568D90) consume the HighPart/LowPart values is unresolved.
}
