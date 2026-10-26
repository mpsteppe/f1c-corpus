// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A0BF
// Canonical corpus name: sub_58A0BF
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58A0BF_0058a0bf.c

void UnknownObject::ValidateAllHeapSlots()
{
    // Iterates every thread heap slot in the global slot array (pointer at dword_8D4A24, count at dword_8D5A40). Each slot whose entry is non-null and has the 0x83 flag bits set at entry+12 is validated inside its per-slot critical section via MemoryBlockValidationCheck. In mode a1==1 the function counts slots that validate cleanly; in mode a1==0 it returns -1 when any writable stream (bit 2 of entry+12) fails validation. A global critical section (slot 2) brackets the whole sweep.
    // CALL: Enter the global critical section (slot 2) via CriticalSectionLazyInitEnter(2) before sweeping the slot array. [callee:0x0058DFEA]
    // LOOP: For loop over i in [0, dword_8D5A40), reading each slot pointer from the slot array dword_8D4A24 + 4*i. [global:0x008D5A40, global:0x008D4A24]
    // GUARD: Guard: skip the slot unless its entry pointer is non-null and its flag field at entry+12 has any of the 0x83 bits set. [global:0x008D4A24, source:raw]
    // CALL: Enter the per-slot critical section via CriticalSectionEnter(i, slot) before validating that slot. [callee:0x0058C1E0]
    // GUARD: Re-check the entry flag field at +12 for the 0x83 bits after acquiring the per-slot lock; skip if no longer set. [source:raw]
    // STATE_TRANSITION: Mode a1==1: when MemoryBlockValidationCheck(slot) does not return -1, increment the valid-slot counter v1. [callee:0x0058A02C]
    // STATE_TRANSITION: Mode a1==0: when the entry has writable bit 2 set at entry+12 and MemoryBlockValidationCheck(slot) returns -1, set the error flag v2 to -1. [callee:0x0058A02C, source:raw]
    // CALL: Leave the per-slot critical section via CriticalSectionLeave_c232(i, slot). [callee:0x0058C232]
    // CALL: Leave the global critical section (slot 2) via CritSectLeave(2). [callee:0x0058E04B]
    // RETURN: Return the valid-slot count when a1==1, otherwise return the error flag v2 (0 on success, -1 on any failed writable stream). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_58A0BF(int mode) {
    //     int valid = 0, err = 0;
    //     CriticalSectionLazyInitEnter(2);
    //     for (int i = 0; i < dword_8D5A40; ++i) {
    //       Slot* s = *(Slot**)(dword_8D4A24 + 4 * i);
    //       if (s && (*(BYTE*)((char*)s + 12) & 0x83)) {
    //         CriticalSectionEnter(i, s);
    //         int flags = *(int*)((char*)s + 12);
    //         if (flags & 0x83) {
    //           if (mode == 1) {
    //             if (MemoryBlockValidationCheck(s) != -1) ++valid;
    //           } else if (mode == 0 && (flags & 2) && MemoryBlockValidationCheck(s) == -1) {
    //             err = -1;
    //           }
    //         }
    //         CriticalSectionLeave_c232(i, s);
    //       }
    //     }
    //     CritSectLeave(2);
    //     return mode == 1 ? valid : err;
    //   }
    // UNRESOLVED: Semantics of the 0x83 flag bits at entry+12 (which bits mark an open/writable stream) are DERIVED from existing analysis, not packet-confirmed.
    // UNRESOLVED: Meaning of the per-slot index i passed to the critical-section helpers is not established.
    // UNRESOLVED: Slot array element type and the meaning of dword_8D4A24/dword_8D5A40 naming are DERIVED.
}
