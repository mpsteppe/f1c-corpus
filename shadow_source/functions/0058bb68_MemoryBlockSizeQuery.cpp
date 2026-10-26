// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BB68
// Canonical corpus name: sub_58BB68
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58BB68_0058bb68.c

void UnknownObject::MemoryBlockSizeQuery()
{
    // Returns the usable size of a memory allocation, selecting strategy by OS version code dword_8D4908. Version 3 reads the region header via sub_593E1B and computes *(lpMem - 1) - 9. Version 2 resolves the pool block index via MemoryRegionValidationHeapLookup and computes 16 * *v3. Both paths run under critical section 9 and fall back to HeapSize(hHeap, 0, lpMem) when the lookup failed or the version is neither 2 nor 3. Called by sub_587AC0.
    // GUARD: OS version guard: when dword_8D4908 == 3 the region-header size path (critical section + sub_593E1B lookup) is taken; otherwise the code checks the OS version 2 path or falls back [global:0x008D4908, source:raw]
    // GUARD: When dword_8D4908 is neither 3 nor 2 the function returns HeapSize(hHeap, 0, lpMem) immediately (default heap-size query) [global:0x008D4908, global:0x008D4904, global:0x0059E178, source:raw]
    // CALL: CriticalSectionLazyInitEnter(9) enters critical section 9 for thread safety [callee:0x0058DFEA, source:raw]
    // CALL: sub_593E1B(lpMem) looks up region metadata for the allocation (OS v3 path) [callee:0x00593E1B, source:raw]
    // ASSIGNMENT: On successful region lookup, v1 = *(lpMem - 1) - 9 computes the usable block size from the allocation header dword immediately preceding the pointer [source:raw]
    // CALL: CritSectLeave(9) releases critical section 9 [callee:0x0058E04B, source:raw]
    // CALL: MemoryRegionValidationHeapLookup(lpMem, v5, v7) resolves the pool block index for the allocation (OS v2 pool path) [callee:0x00594B76, source:raw]
    // ASSIGNMENT: v1 = 16 * *v3 scales the pool block index byte by a stride of 16 to obtain the block size [source:raw]
    // CALL: HeapSize(hHeap, 0, lpMem) queries the private heap for the block size as the fallback when the active lookup failed [global:0x0059E178, global:0x008D4904, source:raw]
    // RETURN: Return the computed size v1 when the lookup succeeded, or the HeapSize(hHeap, 0, lpMem) fallback when the lookup failed [source:raw]
    // CALL: Invoked by sub_587AC0 (00587ac0) [caller:0x00587AC0]

    // Conservative worker pseudocode:
    //   if (dword_8D4908 == 3) {
    //       CriticalSectionLazyInitEnter(9);
    //       v9 = sub_593E1B(lpMem);
    //       v1 = v9 ? *(lpMem - 1) - 9 : v8;
    //       CritSectLeave(9);
    //       v2 = (v9 == 0);
    //   } else if (dword_8D4908 == 2) {
    //       CriticalSectionLazyInitEnter(9);
    //       v6 = MemoryRegionValidationHeapLookup(lpMem, v5, v7);
    //       v1 = v6 ? 16 * *v6 : v8;
    //       CritSectLeave(9);
    //       v2 = (v6 == 0);
    //   } else {
    //       return HeapSize(hHeap, 0, lpMem);
    //   }
    //   if (v2)
    //       return HeapSize(hHeap, 0, lpMem);
    //   return v1;
    // UNRESOLVED: ScriptFrameProcessor (0x0058895C) and stru_5B8D30 (0x005B8D30) are SEH exception-handler registrations embedded in the ms_exc frame; their exact error-recovery role is not documented
    // UNRESOLVED: TLS guard bytes byte_FF00000000001692/95/9B are written and read by the SEH prologue/epilogue; their purpose is unknown
    // UNRESOLVED: The relationships '*(lpMem - 1) - 9' and '16 * *v3' are inferred as block-size computations; the exact allocation-header and pool layout are unknown
    // UNRESOLVED: The fallback through the uninitialized v8 when a lookup returns zero is a decompiler artifact and its effective value is not trustworthy
}
