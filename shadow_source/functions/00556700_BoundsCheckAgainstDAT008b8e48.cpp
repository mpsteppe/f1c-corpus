// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556700
// Canonical corpus name: BoundsCheckAgainstDAT008b8e48
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundsCheckAgainstDAT008b8e48_00556700.c

void UnknownObject::BoundsCheckAgainstDAT008b8e48()
{
    // Index bounds check for a fixed-size slot array. Computes the upper sentinel as dword_8B8E48 + 32. If a1 + 32 < dword_8B8E48 + 32, the index a1 is in range and the function returns HighResolutionTimerReset(&dword_8B6C28[19 * a1 + 608]), addressing slot a1 of a 19-dword-stride array anchored at dword_8B6C28 plus element 608. Otherwise it returns dword_8B8E48 + 32.
    // CALCULATION: Compute the upper bound sentinel: result = dword_8B8E48 + 32. [source:raw, global:0x008B8E48]
    // GUARD: Bounds check: if a1 + 32 < dword_8B8E48 + 32, index a1 is within the allowed range. [source:raw, global:0x008B8E48]
    // CALCULATION: Address the slot: &dword_8B6C28[19 * a1 + 608], i.e. dword_8B6C28 + (19 * a1 + 608) dwords. [source:raw, global:0x008B6C28]
    // RETURN: Index in range: return HighResolutionTimerReset(&dword_8B6C28[19 * a1 + 608]) on the addressed slot. [source:raw, callee:0x00556440]
    // RETURN: Index out of range: return the sentinel dword_8B8E48 + 32 unchanged. [source:raw, global:0x008B8E48]

    // Conservative worker pseudocode:
    //   int sub_556700(int a1) {
    //     int result = dword_8B8E48 + 32;
    //     if (a1 + 32 < dword_8B8E48 + 32)
    //       return HighResolutionTimerReset(&dword_8B6C28[19 * a1 + 608]);
    //     return result;
    //   }
    // UNRESOLVED: The semantics of dword_8B8E48 (slot count or end sentinel) and the +32 offsets are unknown; the +32 appears on both sides of the comparison and in the sentinel, suggesting an array-of-32-dword-slot layout or a stored byte-count conversion.
    // UNRESOLVED: The array dword_8B6C28 with a 19-dword stride and base element 608 has no established type; whether it holds timer/state records per slot a1 is unproven.
    // UNRESOLVED: The purpose of HighResolutionTimerReset on a per-slot address is unclear without the caller sub_4F9FC0 (0x004F9FC0) context.
    // UNRESOLVED: The AI subsystem tag and function name are legacy/semantic labels, not confirmed ownership.
}
