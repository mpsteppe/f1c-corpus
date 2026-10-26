// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DFEA
// Canonical corpus name: CriticalSectionLazyInitEnter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CriticalSectionLazyInitEnter_0058dfea.c

void UnknownObject::CriticalSectionLazyInitEnter()
{
    // Enter a critical section indexed by a1 from the global lock-pointer table dword_5E6C80. On first use the CRITICAL_SECTION is lazily allocated (24 bytes), initialized via InitializeCriticalSection, and stored into the table under a double-checked lock guarded by recursively entering this same function for guard slot 17 and releasing it via CritSectLeave(17). A lost race frees the fresh allocation through sub_58AA6F. Allocation failure exits fatally via CRTAmsgExit(0x11u). Every path ends by calling EnterCriticalSection on the table entry.
    // GUARD: Fast-path guard: skip lazy init when the lock pointer *(&dword_5E6C80 + a1) is already non-null. [source:raw, global:0x005E6C80]
    // CALL: Allocate a 24-byte RTL_CRITICAL_SECTION via MallocWrapperForNhMalloc(24). [source:raw, callee:0x0058A935]
    // GUARD: Guard: if the allocation returned NULL, exit fatally via CRTAmsgExit(0x11u). [source:raw, callee:0x0058A2A6]
    // CALL: Acquire the table-guard lock by recursively calling this same function for slot 17 (CriticalSectionLazyInitEnter(17)). [source:raw, callee:0x0058DFEA]
    // GUARD: Double-checked re-test of *(&dword_5E6C80 + a1); another thread may have installed the lock while the guard was held. [source:raw, global:0x005E6C80]
    // CALL: Lost-race path: free the freshly allocated v1 via sub_58AA6F(v1). [source:raw, callee:0x0058AA6F]
    // CALL: Winner path: initialize v1 via InitializeCriticalSection and store it into *(&dword_5E6C80 + a1). [source:raw, global:0x0059E16C, global:0x005E6C80]
    // CALL: Release the table-guard lock via CritSectLeave(17). [source:raw, callee:0x0058E04B]
    // CALL: Enter the target critical section: EnterCriticalSection(*(&dword_5E6C80 + a1)). [source:raw, global:0x0059E174, global:0x005E6C80]

    // Conservative worker pseudocode:
    //   void sub_58DFEA(int a1) {
    //     if (!dword_5E6C80[a1]) {
    //       v1 = (RTL_CRITICAL_SECTION*)MallocWrapperForNhMalloc(24);
    //       if (!v1) CRTAmsgExit(0x11u);
    //       CriticalSectionLazyInitEnter(17);
    //       if (dword_5E6C80[a1]) { sub_58AA6F(v1); }
    //       else { InitializeCriticalSection(v1); dword_5E6C80[a1] = v1; }
    //       CritSectLeave(17);
    //     }
    //     EnterCriticalSection(dword_5E6C80[a1]);
    //   }
    // UNRESOLVED: Identity of sub_58AA6F (free/cleanup of the lost allocation) is not established from this packet alone.
    // UNRESOLVED: The recursive call with argument 17 reuses this same function as the table-guard lock; exact guard-slot semantics depend on the caller convention.
    // UNRESOLVED: a1 is an index into the global lock table dword_5E6C80; the table capacity and per-slot meaning are unknown here.
    // UNRESOLVED: EnterCriticalSection/InitializeCriticalSection are indirect global function pointers; their actual Win32 imports are not proven by this packet.
}
