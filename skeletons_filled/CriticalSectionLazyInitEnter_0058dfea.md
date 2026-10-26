## CriticalSectionLazyInitEnter_0058dfea — _lock: lazy-initializing critical section enter

**Summary:** CRT `_lock` implementation that enters a critical section by index from the global lock table. Lazily allocates and initializes the CRITICAL_SECTION on first use with thread-safe double-checked locking. Exits fatally via CRTAmsgExit if allocation fails.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_588410 (00588410), sub_588A34 (00588a34), sub_589901 (00589901), sub_589A35 (00589a35), sub_589D6B (00589d6b), sub_58A0BF (0058a0bf), sub_58A973 (0058a973), sub_58AA6F (0058aa6f), sub_58AB58 (0058ab58), sub_58B465 (0058b465), sub_58B5D4 (0058b5d4), SemaphoreGuardedQueryCall (0058b903), sub_58BB68 (0058bb68), StreamBufferLockViaCriticalSection (0058c1b1), CriticalSectionEnter (0058c1e0), sub_58C5AC (0058c5ac), LazyInitSingletonWithFlagGuard (005921c5), sub_5921F3 (005921f3), CriticalSectionGuardedCall (0059247a), sub_595801 (00595801), CriticalSectionEnterWithLazyInit (00595a61), sub_596030 (00596030), sub_596716 (00596716), sub_596C80 (00596c80), sub_596E40 (00596e40), sub_597388 (00597388), sub_598569 (00598569), sub_59B092 (0059b092), TypeInfoDestructor (0059baa3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e16c | InitializeCriticalSection | R | Win32 InitializeCriticalSection function pointer |
| 0059e174 | EnterCriticalSection | R | Win32 EnterCriticalSection function pointer |
| 005e6c80 | dword_5E6C80 | R | Global array of CRITICAL_SECTION pointers by index |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a2a6 | CRTAmsgExit | Fatal exit when CS allocation fails (arg 0x11 = out of memory) |
| 0058a935 | MallocWrapperForNhMalloc | Allocate 24-byte CRITICAL_SECTION structure |
| 0058aa6f | sub_58AA6F | Free allocated CS if another thread already initialized the slot |
| 0058dfea | CriticalSectionLazyInitEnter | Recursive call to enter table-guard CS (index 17) for double-check |
| 0058e04b | CritSectLeave | Leave table-guard CS (index 17) after initialization |

**Guard conditions:** If CS pointer at dword_5E6C80[a1] is NULL, attempts lazy init. If MallocWrapperForNhMalloc returns NULL (allocation failure), calls CRTAmsgExit(0x11) to terminate with out-of-memory error. Uses recursive enter of CS 17 as table-guard lock for thread-safe double-checked initialization. After init, enters the target CS.
