// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058AB58
// Canonical corpus name: sub_58AB58
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58AB58_0058ab58.c

void UnknownObject::AlignedCountedAllocator()
{
    // Multi-strategy counted-element allocator (cdecl, count a1 * element size a2). Rounds the request up to a 16-byte boundary (with a 1-byte minimum) when it fits in 0xFFFFFFE0, then dispatches through OS-version-specific pool allocator paths guarded by dword_8D4908 (3: large-pool style via sub_59416F with size limit dword_8D4900; 2: small-pool style via sub_594C12(v2 >> 4) with size limit dword_5E998C), zero-initializing successful pool allocations via sub_58BB10. Falls back to HeapAlloc(hHeap, 8u, v2) on the private heap for failures and oversized requests, and when the debug heap flag dword_8D41B0 is set retries through GlobalCallbackDispatcherWithNullCheck(v2). Returns the first successful pointer or NULL when the debug retry itself fails.
    // CALCULATION: Compute the requested byte count v2 = a2 * a1 and its copy v5, from the count and element-size arguments. [source:raw]
    // GUARD: If (unsigned int)(a2 * a1) <= 0xFFFFFFE0, clamp v2 to a minimum of 1 and round up to a 16-byte boundary with (v2 + 15) & 0xFFFFFFF0. [source:raw]
    // LOOP: Retry loop: reset v4 = 0 each iteration; for requests v2 <= 0xFFFFFFE0 try the pool allocator paths then the HeapAlloc fallback; for oversized requests fall through to the debug-heap callback retry. [source:raw]
    // GUARD: If dword_8D4908 == 3 (large-pool discriminator): when v5 > dword_8D4900 skip the pool and go straight to the HeapAlloc fallback. [global:0x008D4908, global:0x008D4900, source:raw]
    // CALL: On the dword_8D4908 == 3 path, enter critical section 9 via CriticalSectionLazyInitEnter, allocate from the pool via sub_59416F(v5), and leave via CritSectLeave(9). [callee:0x0058DFEA, callee:0x0059416F, callee:0x0058E04B, source:raw]
    // CALL: If the large-pool allocation succeeded, zero-fill it via sub_58BB10(v4, 0, v5). [callee:0x0058BB10, source:raw]
    // CALL: Fallback allocation: HeapAlloc(hHeap, 8u, v2) using the private heap handle global:0x008D4904 and the HeapAlloc import at global:0x0059E1C0. [global:0x008D4904, global:0x0059E1C0, source:raw]
    // GUARD: If dword_8D4908 == 2 (small-pool discriminator) and v2 <= dword_5E998C: enter critical section 9, allocate sub_594C12(v2 >> 4), leave; on failure go to the HeapAlloc fallback, otherwise zero-fill via sub_58BB10(v4, 0, v2). [global:0x008D4908, global:0x005E998C, callee:0x0058DFEA, callee:0x00594C12, callee:0x0058E04B, callee:0x0058BB10, source:raw]
    // RETURN: If v4 is non-null after a pool path on the small-request branch, return it; otherwise fall through to the HeapAlloc fallback. [source:raw]
    // GUARD: After the HeapAlloc fallback: if v4 is non-null, or the debug heap flag dword_8D41B0 is clear, return v4. [global:0x008D41B0, source:raw]
    // CALL: Retry through GlobalCallbackDispatcherWithNullCheck(v2) when the debug heap flag is set and the fallback returned null; if that also returns null, return it. [callee:0x00593DB8, source:raw]
    // CALL: Called by DelegationWrapper_803a (0x0052803A), DelegationWrapper_6fd0 (0x00536FD0), TLSAllocationThreadIDInit (0x0058E060), TLSValueRetrievalWithInit (0x0058E0C7), PhysicsAllocatorNodeInit (0x0058EF83) and PhysicsAllocatorNodeInit_f6fe (0x0058F6FE) as a shared allocation primitive. [caller:0x0052803A, caller:0x00536FD0, caller:0x0058E060, caller:0x0058E0C7, caller:0x0058EF83, caller:0x0058F6FE, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a2 * a1;
    //   v5 = a2 * a1;
    //   if ((unsigned int)(a2 * a1) <= 0xFFFFFFE0) {
    //       if (!v2) v2 = 1;
    //       v2 = (v2 + 15) & 0xFFFFFFF0;
    //   }
    //   for (;;) {
    //       v4 = 0;
    //       if (v2 <= 0xFFFFFFE0) {
    //           if (dword_8D4908 == 3) {
    //               if (v5 > dword_8D4900) goto LABEL_14;
    //               CriticalSectionLazyInitEnter(9);
    //               v4 = (LPVOID)sub_59416F(v5);
    //               CritSectLeave(9);
    //               if (v4) { sub_58BB10(v4, 0, v5); goto LABEL_14; }
    //   LABEL_15:
    //               v4 = HeapAlloc(hHeap, 8u, v2);
    //               goto LABEL_16;
    //           }
    //           if (dword_8D4908 == 2 && v2 <= dword_5E998C) {
    //               CriticalSectionLazyInitEnter(9);
    //               v4 = (LPVOID)sub_594C12(v2 >> 4);
    //               CritSectLeave(9);
    //               if (!v4) goto LABEL_15;
    //               sub_58BB10(v4, 0, v2);
    //           }
    //   LABEL_14:
    //           if (v4) return v4;
    //           goto LABEL_15;
    //       }
    //   LABEL_16:
    //       if (v4 || !dword_8D41B0) return v4;
    //       result = (LPVOID)GlobalCallbackDispatcherWithNullCheck(v2);
    //       if (!result) return result;
    //   }
    // UNRESOLVED: ScriptFrameProcessor (global:0x0058895C), stru_5B8D00 (global:0x005B8D00) and the TLS access bytes at 0xFF00000000001692, 0xFF00000000001695 and 0xFF0000000000169B are listed as read/written but do not appear in the raw pseudocode; they are presumably accessed inside the callees (the corpus fill identifies stru_5B8D00 as a CRT memory-allocation exception frame).
    // UNRESOLVED: Interpretation of dword_8D4908 (2/3 as OS-version pool discriminators, the corpus fill reads them as Win2K/WinXP styles), dword_8D4900, dword_5E998C (pool size limits), dword_8D41B0 (debug heap flag), sub_59416F and sub_594C12 (pool allocator routines) is DERIVED from the corpus fill; the packet only shows the numeric guards and calls.
    // UNRESOLVED: The 9 passed to CriticalSectionLazyInitEnter/CritSectLeave is a critical-section index whose table layout is not described by the packet.
    // UNRESOLVED: Semantics of the debug-heap callback GlobalCallbackDispatcherWithNullCheck and the HeapAlloc flag 8u (HEAP_ZERO_MEMORY-style) are not confirmed by the packet.
}
