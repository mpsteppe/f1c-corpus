// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058AA6F
// Canonical corpus name: sub_58AA6F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58AA6F_0058aa6f.c

void UnknownObject::FreeMemoryDispatched()
{
    // NULL-safe memory deallocation dispatcher. Reads an OS-version discriminator global: value 3 runs a pool-free path (lookup then paired free under critical section 9), value 2 runs a validation path (heap-region lookup plus counter update under critical section 9), and any other value falls back to HeapFree(hHeap, 0, lpMem). If the specialized path reports no owning allocation, execution falls through to the same HeapFree fallback. SEH TryLevel setup surrounds the critical-section bodies.
    // GUARD: If lpMem is null, return immediately (NULL-safe deallocation). [source:raw, function:0x0058AA6F]
    // GUARD: Dispatch on the OS-version discriminator dword_8D4908: value 3 selects the pool-free path, value 2 selects the heap-region-validation path, and any other value jumps directly to the HeapFree fallback. [global:0x008D4908, source:raw]
    // CALL: Enter critical section 9 via CriticalSectionLazyInitEnter before the discriminator-specific deallocation work. [callee:0x0058DFEA, global:0x008D4908, source:raw]
    // CALL: Pool-free path (discriminator 3): call sub_593E1B(lpMem); if it returns non-null, complete the free by calling sub_593E46(handle, lpMem). [callee:0x00593E1B, callee:0x00593E46, global:0x008D4908, source:raw]
    // CALL: Validation path (discriminator 2): call MemoryRegionValidationHeapLookup(lpMem, &v4, &v6); if it returns non-null, feed the region/counter values to CounterThreshold. [callee:0x00594B76, callee:0x00594BCD, global:0x008D4908, source:raw]
    // CALL: Leave critical section 9 via CritSectLeave after the discriminator-specific work. [callee:0x0058E04B, source:raw]
    // GUARD: If the discriminator-specific path reported no owning allocation (lookup returned null), fall through to the HeapFree fallback instead of returning. [global:0x008D4908, source:raw]
    // CALL: Fallback deallocation: HeapFree(hHeap, 0, lpMem) on the process heap. [global:0x008D4904, global:0x0059E1BC, source:raw]
    // RETURN: Return after the HeapFree fallback, or directly after a successful specialized free. [source:raw, function:0x0058AA6F]

    // Conservative worker pseudocode:
    //   void FreeMemoryDispatched(void* lpMem) {
    //       if (!lpMem) return;
    //       if (dword_8D4908 == 3) {
    //           CriticalSectionLazyInitEnter(9);
    //           handle = sub_593E1B(lpMem);
    //           if (handle) sub_593E46(handle, lpMem);
    //           CritSectLeave(9);
    //           if (handle) return;
    //       } else if (dword_8D4908 == 2) {
    //           CriticalSectionLazyInitEnter(9);
    //           handle = MemoryRegionValidationHeapLookup(lpMem, &v4, &v6);
    //           if (handle) CounterThreshold(v4, v6, handle);
    //           CritSectLeave(9);
    //           if (handle) return;
    //       }
    //       HeapFree(hHeap, 0, lpMem);
    //   }
    // UNRESOLVED: The semantics of sub_593E1B / sub_593E46 (the OS-version 3 pool-free pair) are not evidenced in this packet.
    // UNRESOLVED: MemoryRegionValidationHeapLookup / CounterThreshold interplay (region size, counter domain) is not evidenced here.
    // UNRESOLVED: The SEH TryLevel manipulation (ms_exc.registration) around the critical-section bodies implies C++ exception unwinding that the raw text does not detail.
    // UNRESOLVED: Globals ScriptFrameProcessor, stru_5B8CE8 and the byte_FF... high-address globals appear in the fact table but not in the visible function body; their exact role is unknown.
}
