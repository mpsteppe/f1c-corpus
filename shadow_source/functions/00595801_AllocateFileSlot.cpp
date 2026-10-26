// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595801
// Canonical corpus name: sub_595801
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_595801_00595801.c

void UnknownObject::AllocateFileSlot()
{
    // Allocates one file slot from a global slot-group array. dword_8D4920 holds pointers to groups of 32 slots (36 bytes each); the array ends at the address of uNumber. Each slot has a flag byte at +4 (bit 0 = in use), an init counter at +8, and an embedded critical section at +12. Scans existing groups for a free slot under the per-slot critical section, lazily initializing that section on first use. If every group is exhausted it walks to an unallocated group pointer and allocates a fresh 1152-byte group via MallocWrapperForNhMalloc, initializes all 32 slots, and hands out slot index 32 * groupIndex. Returns the allocated slot index, or -1 when no group exists and allocation fails.
    // CALL: Enter the allocator-wide critical section (index 18) via CriticalSectionLazyInitEnter before scanning. [callee:0x0058DFEA, source:raw]
    // LOOP: Walk the group-pointer array dword_8D4920; each non-null group entry points to 32 slots of 36 bytes. A null entry (or the array end at the address of uNumber) ends the scan. [global:0x008D4920, global:0x008D4A20, source:raw]
    // GUARD: Free-slot test: bit 0 of the flag byte at slot + 4 clear means the slot is not in use. [source:raw]
    // GUARD: Double-checked per-slot critical-section init: if the counter at slot + 8 is zero, take the CS gate (index 17), re-check, call InitializeCriticalSection on slot + 12, increment the counter, and release the gate via CritSectLeave. [global:0x0059E16C, callee:0x0058DFEA, callee:0x0058E04B, source:raw]
    // CALL: EnterCriticalSection on the per-slot critical section at slot + 12, then re-check the free flag under the lock and mark the slot in use by storing -1 in the slot header. [global:0x0059E174, source:raw]
    // CALL: LeaveCriticalSection when the double-checked flag shows the slot was already claimed between the two checks. [global:0x0059E170, source:raw]
    // CALCULATION: Compute the flat slot index as group offset (32 per group) plus in-group slot number: v9 + (slot - groupBase) / 36. [source:raw]
    // GUARD: End-of-array test: when the group cursor reaches the address of uNumber, no free slot exists in any allocated group; fall through with the -1 result. [global:0x008D4A20, source:raw]
    // CALL: Allocate a new slot group of 1152 bytes (32 slots x 36 bytes) via MallocWrapperForNhMalloc. [callee:0x0058A935, source:raw]
    // ASSIGNMENT: Register the new group pointer at dword_8D4920[groupCount] and grow the total slot count uNumber by 32. [global:0x008D4920, global:0x008D4A20, source:raw]
    // LOOP: Initialize every slot of the fresh group: flag byte at +4 cleared to 0 (free), header at +0 set to -1, init counter at +8 zeroed, and byte at +5 set to 10. [source:raw]
    // CALL: Acquire the first slot of the new group by entering its critical section via CriticalSectionEnterWithLazyInit(32 * groupIndex). [callee:0x00595A61, source:raw]
    // RETURN: Release the allocator critical section (index 18) via CritSectLeave and return the allocated slot index, or -1 on failure. [callee:0x0058E04B, source:raw]

    // Conservative worker pseudocode:
    //   int AllocateFileSlot() {
    //     int result = -1;
    //     CriticalSectionLazyInitEnter(18);                       // allocator gate
    //     int groupIdx = 0, groupOffset = 0;
    //     int* group = dword_8D4920;                              // group pointer array
    //     for (;;) {
    //       char* base = *group;                                  // 32 slots x 36 bytes
    //       if (base == 0 || group >= &uNumber) break;            // allocate new group or none free
    //       for (int s = 0; s < 32; ++s) {
    //         char* slot = base + s * 36;
    //         if ((slot[4] & 1) == 0) {                           // free slot
    //           if (*(int*)(slot + 8) == 0) {
    //             CriticalSectionLazyInitEnter(17);
    //             if (*(int*)(slot + 8) == 0) {
    //               InitializeCriticalSection(slot + 12);
    //               ++*(int*)(slot + 8);
    //             }
    //             CritSectLeave(17);
    //           }
    //           EnterCriticalSection(slot + 12);
    //           if ((slot[4] & 1) == 0) {
    //             *(int*)slot = -1;                              // mark in use
    //             return groupOffset + s;
    //           }
    //           LeaveCriticalSection(slot + 12);
    //         }
    //       }
    //       groupOffset += 32; ++group; ++groupIdx;
    //     }
    //     int* fresh = MallocWrapperForNhMalloc(1152);
    //     if (fresh) {
    //       uNumber += 32;
    //       dword_8D4920[groupIdx] = fresh;
    //       for (char* p = fresh; p < fresh + 1152; p += 36) {
    //         p[4] = 0; *(int*)p = -1; *(int*)(p + 8) = 0; p[5] = 10;
    //       }
    //       CriticalSectionEnterWithLazyInit(32 * groupIdx);
    //       result = 32 * groupIdx;
    //     }
    //     CritSectLeave(18);
    //     return result;
    //   }
    // UNRESOLVED: Purpose and lifecycle of the per-slot critical section (who releases it and whether the returned slot keeps it held).
    // UNRESOLVED: Meaning of the byte at slot + 5 initialized to 10; not referenced elsewhere in this function.
    // UNRESOLVED: Why the group-pointer array is bounded by the address of uNumber (total slot count doubles as the array end sentinel).
    // UNRESOLVED: Decompiler shows a defensive check on the computed slot index being -1 whose false path resets the group cursor; treated as structural noise from the disassembly, not a distinct allocation path.
}
