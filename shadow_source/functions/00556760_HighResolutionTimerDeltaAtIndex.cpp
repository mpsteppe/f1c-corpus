// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556760
// Canonical corpus name: sub_556760
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_556760_00556760.c

void UnknownObject::HighResolutionTimerDeltaAtIndex()
{
    // Indexed accessor over the high-resolution timer delta table. Guards the slot index a1 against the slot count at dword_8B8E48; when in range, computes the entry address dword_8B6C28[19 * a1 + 608] and returns HighResolutionTimerDeltaCalculation on it. Out-of-range slots return 0.0.
    // GUARD: Guard: if (a1 + 32) >= (dword_8B8E48 + 32), the slot is out of range and the function returns 0.0. [source:raw, global:0x008B8E48]
    // CALCULATION: Compute the entry address: dword_8B6C28 + (19 * a1 + 608) dwords; a1 selects a slot in an array of 19-dword entries. [source:raw, global:0x008B6C28]
    // CALL: Call HighResolutionTimerDeltaCalculation on the selected entry to obtain its delta value. [source:raw, callee:0x00556650, global:0x008B6C28]
    // RETURN: Return 0.0 when the guard fails (slot index out of range). [source:raw]
    // RETURN: Return the HighResolutionTimerDeltaCalculation result for the in-range slot. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_556760(int a1) {
    //     if (a1 + 32 >= dword_8B8E48 + 32) return 0.0;
    //     return HighResolutionTimerDeltaCalculation(&dword_8B6C28[19 * a1 + 608]);
    //   }
    // UNRESOLVED: dbl_59E430 is listed as a read global but does not appear in the raw source body; its role is unresolved.
    // UNRESOLVED: The array base layout (19-dword entries starting at offset 608 dwords) and the meaning of the dword_8B8E48 count depend on the caller's structure; see caller sub_4F9FC0.
    // UNRESOLVED: Structural twin of sub_556730 per the cluster_copy prelabel; the two slots are presumed parallel entries but their shared container is not identified.
}
