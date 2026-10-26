// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C232
// Canonical corpus name: CriticalSectionLeave_c232
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CriticalSectionLeave_c232_0058c232.c

void UnknownObject::CriticalSectionLeave()
{
    // Dispatcher-style critical-section leave helper (cdecl), paired with the enter helper. Takes an index a1 and a context pointer a2. When a1 >= 20 it calls the imported LeaveCriticalSection on the LPCRITICAL_SECTION at a2 + 32; otherwise it delegates to CritSectLeave(a1 + 28), the lazy-init path. Callers include file and stream I/O paths.
    // GUARD: Dispatch on a1 >= 20: high indices use the direct path, low indices use the lazy-init path. [source:raw]
    // CALCULATION: Direct path computes the LPCRITICAL_SECTION pointer as a2 + 32. [source:raw]
    // CALL: Direct path calls the imported LeaveCriticalSection (function pointer global 0x0059E170) on the critical section at a2 + 32. [global:0x0059E170, source:raw]
    // CALCULATION: Lazy path computes the per-index critical-section slot address as a1 + 28. [source:raw]
    // CALL: Lazy path calls CritSectLeave(a1 + 28) to release the critical section for indices below 20. [callee:0x0058E04B, source:raw]
    // CALL: Invoked by FileOpWithGlobalBuffer (0x00588821), sub_58A0BF (0x0058A0BF) and sub_58C5AC (0x0058C5AC) to release their critical sections after buffered file operations. [caller:0x00588821, caller:0x0058A0BF, caller:0x0058C5AC, source:raw]

    // Conservative worker pseudocode:
    //   void sub_58C232(int index, int ctx) {
    //     if (index >= 20)
    //       LeaveCriticalSection((LPCRITICAL_SECTION)(ctx + 32));
    //     else
    //       CritSectLeave(index + 28);
    //   }
    // UNRESOLVED: Exact meaning of a1 (critical-section array index) and a2 (context/base) depends on the three callers.
    // UNRESOLVED: Why 20 slots are handled by the lazy-init array while higher indices use the direct path is caller-data dependent.
}
