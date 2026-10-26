// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556730
// Canonical corpus name: sub_556730
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_556730_00556730.c

void UnknownObject::AudioChannelGetTimerElapsed()
{
    // Returns the elapsed time of an indexed channel's high-resolution timer. Bounds-checks the channel index a1 against the global channel count dword_8B8E48 (0x008B8E48): when a1 + 32 >= dword_8B8E48 + 32, i.e. a1 >= dword_8B8E48, the index is out of range and the function returns 0.0. Otherwise it computes the per-channel entry at &dword_8B6C28[19 * a1 + 608] (global 0x008B6C28, 19-DWORD stride per channel with a 608-DWORD base offset) and returns PerformanceCounterTimerWithScaling on that entry.
    // GUARD: Bounds check: when a1 + 32 >= dword_8B8E48 (0x008B8E48) + 32, equivalently a1 >= dword_8B8E48, the channel index is out of range. [global:0x008B8E48, source:raw]
    // RETURN: Return 0.0 on the out-of-range path. [source:raw]
    // CALCULATION: Compute the per-channel entry address as &dword_8B6C28[19 * a1 + 608] (global 0x008B6C28): a 19-DWORD stride per channel with a 608-DWORD base offset into the array. [global:0x008B6C28, source:raw]
    // CALL: PerformanceCounterTimerWithScaling on the computed entry (0x00556510): return the elapsed time in seconds from the channel's embedded high-resolution timer. [callee:0x00556510, global:0x008B6C28, source:raw]
    // RETURN: Return the timer result from the in-range path. [source:raw]

    // Conservative worker pseudocode:
    //   if (a1 + 32 >= dword_8B8E48 + 32) return 0.0;
    //   return PerformanceCounterTimerWithScaling((double *)&dword_8B6C28[19 * a1 + 608]);
    // UNRESOLVED: The packet lists global 0x0059E430 (dbl_59E430) as read, but it does not appear in the raw source text; its role is not established.
    // UNRESOLVED: The interpretation of dword_8B8E48 as an audio channel count and dword_8B6C28 as an audio channel array is DERIVED from the existing analysis fill and is not independently evidenced, so it is not adopted as CONFIRMED.
    // UNRESOLVED: The semantic meaning of the 19-DWORD per-channel stride and the 608-DWORD base offset is not explained by the packet.
    // UNRESOLVED: The callers 0x004F9480, 0x004F9AD0, 0x004FA7E0 and 0x00557120 are not resolved to a shared context, so the owning subsystem remains unknown.
}
