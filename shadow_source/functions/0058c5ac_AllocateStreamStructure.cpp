// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C5AC
// Canonical corpus name: sub_58C5AC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58C5AC_0058c5ac.c

void UnknownObject::AllocateStreamStructure()
{
    // Allocates and claims a FILE stream structure from a global pool array at dword_8D4A24 with dword_8D5A40 slots, under critical-section protection (global pool section index 2 plus a per-stream embedded CRITICAL_SECTION at stream +0x20). Reuses an existing inactive slot whose flags at +0xC have no I/O bits (mask 0x83), or mallocs a new 56-byte stream, initializes its embedded critical section, and zeroes/resets the stream (handle -1). Returns the claimed stream pointer, or NULL when no slot is available.
    // ASSIGNMENT: Initialize local stream pointer v0 to NULL and slot counter v1 to 0 before entering the pool critical section. [source:raw]
    // CALL: Enter the global stream-pool critical section via CriticalSectionLazyInitEnter with index 2. [callee:0x0058DFEA, source:raw]
    // GUARD: Guard on dword_8D5A40 (slot count) > 0; when the pool has no slots the loop body is skipped. [global:0x008D5A40, source:raw]
    // LOOP: Scan the stream pool array dword_8D4A24 from slot 0, stepping by 4 bytes per slot until slot index reaches dword_8D5A40. [global:0x008D4A24, global:0x008D5A40, source:raw]
    // CALCULATION: Read slot pointer at dword_8D4A24 + 4*v1; a NULL slot pointer breaks the scan and switches to the new-allocation path. [global:0x008D4A24, source:raw]
    // GUARD: Candidate slot is reusable when flags at stream +12 have no I/O bits set: (byte at +12) & 0x83 == 0. [source:raw]
    // CALL: Enter the per-stream critical section of the candidate slot via CriticalSectionEnter(v1, slot). [callee:0x0058C1E0, source:raw]
    // GUARD: Re-check the candidate flags at stream +12 under the per-stream lock; if still (byte & 0x83) == 0, claim the slot into v0 and jump to the reset path. [source:raw]
    // CALL: When the double-check fails, leave the per-stream critical section via CriticalSectionLeave_c232(v1, slot). [callee:0x0058C232, source:raw]
    // GUARD: Loop increment: after each failed claim, ++v1; when v1 >= dword_8D5A40 the pool is exhausted and the function exits. [global:0x008D5A40, source:raw]
    // CALL: On the new-allocation path, allocate a 56-byte stream structure via MallocWrapperForNhMalloc(56) and store it into slot v1 of dword_8D4A24. [callee:0x0058A935, global:0x008D4A24, source:raw]
    // GUARD: If the malloc result is NULL, abandon allocation and exit. [source:raw]
    // CALL: Initialize the embedded CRITICAL_SECTION at stream +0x20 via InitializeCriticalSection (function pointer at 0x0059E16C). [callee:0x0058A935, global:0x0059E16C, source:raw]
    // CALL: Enter the newly initialized per-stream critical section via EnterCriticalSection (function pointer at 0x0059E174) and set v0 to the new stream. [callee:0x0058C1E0, global:0x0059E174, source:raw]
    // GUARD: Reset path guard: only touch the claimed stream (v0) when it is non-NULL. [source:raw]
    // ASSIGNMENT: Reset the claimed stream: handle at index 4 to -1 and index 0, 1, 2, 3, 7 to 0 (v0[4] = -1, v0[1] = 0, v0[3] = 0, v0[2] = 0, v0[0] = 0, v0[7] = 0). [source:raw]
    // CALL: Leave the global stream-pool critical section via CritSectLeave with index 2. [callee:0x0058E04B, source:raw]
    // RETURN: Return the claimed stream pointer v0, or NULL when no slot could be claimed or allocated. [source:raw]
    // CALL: Called by sub_587D7F (0x00587D7F) and sub_58AE69 (0x0058AE69) to obtain a stream structure. [caller:0x00587D7F, caller:0x0058AE69, source:raw]

    // Conservative worker pseudocode:
    //   Stream* AllocateStreamStructure() {
    //     Stream* s = NULL;
    //     CriticalSectionLazyInitEnter(2);
    //     for (int i = 0; i < dword_8D5A40; ++i) {
    //       Stream* c = pool[i];
    //       if (!c) break;
    //       if ((*(BYTE*)(c + 12) & 0x83) == 0) {
    //         CriticalSectionEnter(i, c);
    //         if ((*(BYTE*)(*(DWORD*)(dword_8D4A24 + 4*i) + 12) & 0x83) == 0) { s = c; goto reset; }
    //         CriticalSectionLeave_c232(i, c);
    //       }
    //     }
    //     pool[i] = MallocWrapperForNhMalloc(56);
    //     if (!pool[i]) goto done;
    //     InitializeCriticalSection((LPCRITICAL_SECTION)(pool[i] + 32));
    //     EnterCriticalSection((LPCRITICAL_SECTION)(pool[i] + 32));
    //     s = pool[i];
    //   reset:
    //     if (s) { s[4] = -1; s[1] = s[3] = s[2] = s[0] = s[7] = 0; }
    //   done:
    //     CritSectLeave(2);
    //     return s;
    //   }
    // UNRESOLVED: The 0x83 flag mask and the layout of the 56-byte stream structure (beyond embedded CRITICAL_SECTION at +0x20 and flags at +0xC) are not documented here.
    // UNRESOLVED: Semantic role of the per-slot critical-section double-check (why the flags are re-read under the lock) is inferred from the allocation pattern, not proven.
}
