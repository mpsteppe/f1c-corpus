## UtilityFunction_03f0_004903f0 — StateDispatchGroupsC

**Summary:** State-based dispatch using ShortComputation_6720 result: groups 0-2 select arg 1, groups 3-5 select arg 4 for vtable method at offset 64. Then iterates child dispatch list.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | Vtable function pointer at entry 16 (state dispatch) |
| this | 0x0 | R | — | VTable pointer (used for dispatch) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0049042c | jpt_4903FD | R | Jump table for switch/case |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486720 | ShortComputation_6720 | Returns state/computation value (0-5) for dispatch selection |
| 00490660 | VTableDispatchListIteration | Iterates child dispatch list for further processing |

**Guard conditions:** Switch on ShortComputation_6720 result: cases 0-2 → dispatches vtable+64 with arg 1, then iteration; cases 3-5 → dispatches vtable+64 with arg 4, then iteration; default → iteration only.
