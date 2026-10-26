// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595A61
// Canonical corpus name: CriticalSectionEnterWithLazyInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CriticalSectionEnterWithLazyInit_00595a61.c

void UnknownObject::CriticalSectionEnterWithLazyInit()
{
    // Enters the critical section belonging to a per-slot index a1. The section array is bucketed: the low 5 bits of a1 (mask 0x1F) select a slot with a 36-byte stride, and the high bits (a1 >> 5) select a bucket whose base pointer is read from the dword_8D4920 array. Each entry carries an init counter at +8 and a CRITICAL_SECTION at +12. When the counter is zero the entry is lazily initialized under a global guard lock (CriticalSectionLazyInitEnter/CritSectLeave on slot 17) with a double-check, calling InitializeCriticalSection and incrementing the counter. It then always calls EnterCriticalSection on the resolved entry.
    // CALCULATION: Compute v1 = 36 * (a1 & 0x1F): the low 5 bits of a1 select the slot scaled by a 36-byte per-slot stride. [source:raw]
    // CALCULATION: Resolve v2 = v1 + dword_8D4920[a1 >> 5]: the high bits of a1 select a bucket base pointer from the dword_8D4920 array. [source:raw, global:0x008D4920]
    // GUARD: If the init counter at v2 + 8 is zero, the entry has never been initialized. [source:raw]
    // CALL: Acquire the global lazy-init guard: CriticalSectionLazyInitEnter(17). [source:raw, callee:0x0058DFEA]
    // GUARD: Double-check the init counter at v2 + 8 under the guard; another thread may have initialized it in the meantime. [source:raw]
    // CALL: Initialize the CRITICAL_SECTION at v2 + 12 through the InitializeCriticalSection function pointer global (0x0059E16C). [source:raw, global:0x0059E16C]
    // ASSIGNMENT: Increment the init counter at v2 + 8 to mark the entry initialized. [source:raw]
    // CALL: Release the global lazy-init guard: CritSectLeave(17). [source:raw, callee:0x0058E04B]
    // CALL: Enter the now-initialized critical section at v2 + 12 through the EnterCriticalSection function pointer global (0x0059E174). [source:raw, global:0x0059E174]

    // Conservative worker pseudocode:
    //   void sub_595A61(int a1) {
    //     int v1 = 36 * (a1 & 0x1F);
    //     int v2 = v1 + dword_8D4920[a1 >> 5];
    //     if (*(_DWORD *)(v2 + 8) == 0) {
    //       CriticalSectionLazyInitEnter(17);
    //       if (*(_DWORD *)(v2 + 8) == 0) {
    //         InitializeCriticalSection((LPCRITICAL_SECTION)(v2 + 12));
    //         ++*(_DWORD *)(v2 + 8);
    //       }
    //       CritSectLeave(17);
    //     }
    //     EnterCriticalSection((LPCRITICAL_SECTION)(dword_8D4920[a1 >> 5] + v1 + 12));
    //   }
    // UNRESOLVED: dword_8D4920 is a read-only array of bucket base pointers (derived stride); its allocation size and element count are unknown.
    // UNRESOLVED: Guard slot 17 and the 36-byte stride are exactly as decompiled; the 12-byte header plus the platform CRITICAL_SECTION layout is not confirmed by packet evidence.
    // UNRESOLVED: InitializeCriticalSection and EnterCriticalSection are data globals (function pointers at 0x0059E16C and 0x0059E174); whether they are IAT imports is not recorded in the packet.
    // UNRESOLVED: The meaning of the per-slot index a1 (existing analysis suggests CRT file descriptors, DERIVED tier) is not established by this packet alone.
}
