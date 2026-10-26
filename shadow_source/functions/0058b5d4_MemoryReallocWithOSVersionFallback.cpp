// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B5D4
// Canonical corpus name: sub_58B5D4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58B5D4_0058b5d4.c

void UnknownObject::MemoryReallocWithOSVersionFallback()
{
    // Memory reallocation wrapper dispatching on an OS-version code (dword_8D4908). If lpMem is NULL it allocates through MallocWrapperForNhMalloc; if dwBytes is 0 it frees via sub_58AA6F and returns NULL. Otherwise three strategies: value 3 runs a critical-section/SEH-guarded region-tracked realloc (sub_593E1B/sub_594624/sub_59416F/sub_593E46 with a HeapAlloc fallback and HeapReAlloc last resort), value 2 runs a pool-allocator path (MemoryRegionValidationHeapLookup, sub_594F3E/sub_594C12/CounterThreshold with a HeapAlloc fallback and HeapReAlloc last resort), and any other value uses a raw HeapReAlloc. All three paths round the size up to a 16-byte boundary, guard against sizes above 0xFFFFFFE0, and when dword_8D41B0 is set retry a failed allocation after the GlobalCallbackDispatcherWithNullCheck out-of-memory callback.
    // GUARD: If lpMem is NULL the call is treated as an allocation: return MallocWrapperForNhMalloc(dwBytes). [callee:0x0058A935, source:raw]
    // GUARD: If dwBytes is 0 the call is treated as a free: sub_58AA6F(lpMem) releases the block and the function returns NULL. [callee:0x0058AA6F, source:raw]
    // GUARD: Strategy selection: dword_8D4908 == 3 selects the region-tracked realloc path (critical section 9 plus SEH frame). [global:0x008D4908, source:raw]
    // LOOP: Retry loop for the region-tracked path: re-entered when the last attempt produced no block and dword_8D41B0 is set, after the out-of-memory callback GlobalCallbackDispatcherWithNullCheck ran. [global:0x008D41B0, callee:0x00593DB8, source:raw]
    // CALL: Enter critical section 9 (CriticalSectionLazyInitEnter) and arm SEH try level 0; retrieve the old block's region info with sub_593E1B(lpMem). [callee:0x0058DFEA, callee:0x00593E1B, source:raw]
    // GUARD: Region in-place grow attempt: only when v4 <= dword_8D4900 and sub_594624(v5, lpMem, v4) succeeds is the block reused (v17 = lpMem). [global:0x008D4900, callee:0x00594624, source:raw]
    // CALL: Fresh region allocation: sub_59416F(v4) allocates, min(*(lpMem-1)-1, v4) bytes are copied with MemoryCopy_cc00, the old region is re-looked-up via sub_593E1B and freed via sub_593E46. [callee:0x0059416F, callee:0x0058CC00, callee:0x00593E1B, callee:0x00593E46, source:raw]
    // ASSIGNMENT: Region-tracked heap fallback: size rounded up to a 16-byte boundary (0xFFFFFFF0 mask) and allocated from hHeap via HeapAlloc, content copied with MemoryCopy_cc00, old region freed via sub_593E46. [global:0x008D4904, global:0x0059E1C0, callee:0x0058CC00, callee:0x00593E46, source:raw]
    // CALL: Disarm the SEH frame and leave critical section 9 with CritSectLeave. [callee:0x0058E04B, source:raw]
    // GUARD: Region-tracked last resort: when the old block was untracked (v16 == 0) fall back to a plain HeapReAlloc(hHeap, 0, lpMem, aligned v4). [global:0x008D4904, global:0x0059E1B4, source:raw]
    // GUARD: Strategy selection: dword_8D4908 == 2 selects the pool-allocator path. [global:0x008D4908, source:raw]
    // LOOP: Retry loop for the pool path: re-entered when the last attempt produced no block and dword_8D41B0 is set, after the out-of-memory callback GlobalCallbackDispatcherWithNullCheck ran. [global:0x008D41B0, callee:0x00593DB8, source:raw]
    // CALL: Pool lookup under critical section 9 with SEH try level 1: MemoryRegionValidationHeapLookup(v2, &v12, &v15) yields the region pointer that the remaining branch consumes. [callee:0x0058DFEA, callee:0x00594B76, source:raw]
    // GUARD: Pool in-place grow: only when v4 < dword_5E998C and sub_594F3E(v12, v15, v8, v4 >> 4) succeeds is the block reused (v17 = lpMem). [global:0x005E998C, callee:0x00594F3E, source:raw]
    // CALL: Pool allocation: sub_594C12(v4 >> 4) allocates the block, min(16 * *v9, v4) bytes are copied with MemoryCopy_cc00, and CounterThreshold(v12, v15, v9) releases the old region. [callee:0x00594C12, callee:0x0058CC00, callee:0x00594BCD, source:raw]
    // ASSIGNMENT: Pool heap fallback: allocate from hHeap via HeapAlloc, copy min(16 * *v9, v4) bytes with MemoryCopy_cc00, release the old region with CounterThreshold(v12, v15, v9). [global:0x008D4904, global:0x0059E1C0, callee:0x0058CC00, callee:0x00594BCD, source:raw]
    // GUARD: Pool last resort: when the region lookup failed (v8 == NULL) use a plain HeapReAlloc(hHeap, 0, v2, v4). [global:0x008D4904, global:0x0059E1B4, source:raw]
    // CALL: Disarm the pool-path SEH frame and leave critical section 9 with CritSectLeave. [callee:0x0058E04B, source:raw]
    // GUARD: Strategy selection: for any other dword_8D4908 value use the raw path - size rounded to a 16-byte boundary, HeapReAlloc(hHeap, 0, lpMem, v4), retried through the out-of-memory callback when dword_8D41B0 is set. [global:0x008D4908, global:0x008D4904, global:0x0059E1B4, source:raw]
    // CALL: Out-of-memory callback GlobalCallbackDispatcherWithNullCheck(v4); a NULL return aborts the whole function before any retry. [callee:0x00593DB8, source:raw]
    // RETURN: Return the resulting block pointer; callers are AccumulatorWithReallocOnGrowth (0x00564930), sub_587AC0 and sub_598323. [function:0x0058B5D4, caller:0x00564930, caller:0x00587AC0, caller:0x00598323, source:raw]

    // Conservative worker pseudocode:
    //   LPVOID MemoryReallocWithOSVersionFallback(DWORD *lpMem, SIZE_T dwBytes) {
    //     if (!lpMem) return MallocWrapperForNhMalloc(dwBytes);
    //     v4 = dwBytes;
    //     if (!dwBytes) { sub_58AA6F(lpMem); return 0; }
    //     if (dword_8D4908 == 3) {
    //       for (;;) {
    //         v17 = 0;
    //         if (v4 <= 0xFFFFFFE0) {
    //           CriticalSectionLazyInitEnter(9);      // SEH try level 0
    //           v16 = sub_593E1B(lpMem);
    //           if (v16) {
    //             if (v4 <= dword_8D4900 && sub_594624(v16, lpMem, v4)) v17 = lpMem;
    //             else {
    //               v17 = sub_59416F(v4);
    //               if (v17) {
    //                 n = *(lpMem-1)-1; if (n >= v4) n = v4;
    //                 MemoryCopy_cc00(v17, lpMem, n);
    //                 v16 = sub_593E1B(lpMem); sub_593E46(v16, lpMem);
    //               }
    //             }
    //             if (!v17) {
    //               if (!v4) v4 = 1; v4 = (v4+15) & 0xFFFFFFF0;
    //               v17 = HeapAlloc(hHeap, 0, v4);
    //               if (v17) {
    //                 n = *(lpMem-1)-1; if (n >= v4) n = v4;
    //                 MemoryCopy_cc00(v17, lpMem, n); sub_593E46(v16, lpMem);
    //               }
    //             }
    //           }
    //           CritSectLeave(9);
    //           if (!v16) { if (!v4) v4 = 1; v4 = (v4+15) & 0xFFFFFFF0; v17 = HeapReAlloc(hHeap, 0, lpMem, v4); }
    //         }
    //         result = v17;
    //         if (v17 || !dword_8D41B0) return result;
    //         if (!GlobalCallbackDispatcherWithNullCheck(v4)) return 0;
    //       }
    //     } else if (dword_8D4908 == 2) {
    //       if (dwBytes <= 0xFFFFFFE0) v4 = (dwBytes+15) & 0xFFFFFFF0;
    //       for (;;) {
    //         v17 = 0;
    //         if (v4 <= 0xFFFFFFE0) {
    //           CriticalSectionLazyInitEnter(9);      // SEH try level 1
    //           v8 = MemoryRegionValidationHeapLookup(v2, &v12, &v15);
    //           if (v8) {
    //             if (v4 < dword_5E998C && sub_594F3E(v12, v15, v8, v4 >> 4)) v17 = lpMem;
    //             else {
    //               v17 = sub_594C12(v4 >> 4);
    //               if (v17) { n = 16 * *v8; if (n >= v4) n = v4; MemoryCopy_cc00(v17, lpMem, n); CounterThreshold(v12, v15, v8); }
    //             }
    //             if (!v17) {
    //               v17 = HeapAlloc(hHeap, 0, v4);
    //               if (v17) { n = 16 * *v8; if (n >= v4) n = v4; MemoryCopy_cc00(v17, v2, n); CounterThreshold(v12, v15, v8); }
    //             }
    //           } else {
    //             v17 = HeapReAlloc(hHeap, 0, v2, v4);
    //           }
    //           CritSectLeave(9);
    //         }
    //         result = v17;
    //         if (v17 || !dword_8D41B0) return result;
    //         if (!GlobalCallbackDispatcherWithNullCheck(v4)) return 0;
    //       }
    //     } else {
    //       for (;;) {
    //         result = 0;
    //         if (v4 <= 0xFFFFFFE0) { if (!v4) v4 = 1; v4 = (v4+15) & 0xFFFFFFF0; result = HeapReAlloc(hHeap, 0, lpMem, v4); }
    //         if (result || !dword_8D41B0) return result;
    //         if (!GlobalCallbackDispatcherWithNullCheck(v4)) return 0;
    //       }
    //     }
    //   }
    // UNRESOLVED: The exact meaning of dword_8D4908 (labeled OSVersionCode by the skeleton fill) and dword_8D41B0 (labeled CRT_DebugHeapFlag) is not established from this packet alone
    // UNRESOLVED: Globals ScriptFrameProcessor (0x0058895C) and stru_5B8D18 (0x005B8D18) are flagged read-only by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them an SEH exception-handler reference and an SEH registration structure, both unverifiable from this packet
    // UNRESOLVED: The three TLS bytes (0xFF00000000001692, 0xFF00000000001695, 0xFF0000000000169B) are likewise absent from the raw source text and are likely EH-runtime state touched by the SEH frames
}
