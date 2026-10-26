## CriticalSectionLazyInitEnter_0058dfea — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_588410 (00588410), sub_588A34 (00588a34), sub_589901 (00589901), sub_589A35 (00589a35), sub_589D6B (00589d6b), sub_58A0BF (0058a0bf), sub_58A973 (0058a973), sub_58AA6F (0058aa6f), sub_58AB58 (0058ab58), sub_58B465 (0058b465), sub_58B5D4 (0058b5d4), SemaphoreGuardedQueryCall (0058b903), sub_58BB68 (0058bb68), StreamBufferLockViaCriticalSection (0058c1b1), CriticalSectionEnter (0058c1e0), sub_58C5AC (0058c5ac), LazyInitSingletonWithFlagGuard (005921c5), sub_5921F3 (005921f3), CriticalSectionGuardedCall (0059247a), sub_595801 (00595801), CriticalSectionEnterWithLazyInit (00595a61), sub_596030 (00596030), sub_596716 (00596716), sub_596C80 (00596c80), sub_596E40 (00596e40), sub_597388 (00597388), sub_598569 (00598569), sub_59B092 (0059b092), TypeInfoDestructor (0059baa3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e16c | InitializeCriticalSection | R | [LLM] |
| 0059e174 | EnterCriticalSection | R | [LLM] |
| 005e6c80 | dword_5E6C80 | R | CriticalSectionPtrArray [DERIVED] (also: ` — global array of CRITICAL_SECTION pointers) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a2a6 | CRTAmsgExit | [LLM] |
| 0058a935 | MallocWrapperForNhMalloc | [LLM] |
| 0058aa6f | sub_58AA6F | [LLM] |
| 0058dfea | CriticalSectionLazyInitEnter | [LLM] |
| 0058e04b | CritSectLeave | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
