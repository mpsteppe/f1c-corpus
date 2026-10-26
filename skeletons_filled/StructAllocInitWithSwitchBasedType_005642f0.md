## StructAllocInitWithSwitchBasedType_005642f0 — Allocate20ByteStructWithTypedArray

**Summary:** Allocates a 20-byte struct, initializes fields with a1 (data), a2 (short), a3 (type), and a4 (extra). Based on type a3 (0-3 → size 2, default → size 4), allocates a sub-array via AllocateIntArrayViaFactory with sub_5645F0 as factory and IntegerDifferenceComparator for comparison.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalNetworkUtility (00563160), DisplayModeQueryWrapper (005633d0), sub_564110 (00564110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00564378 | jpt_56431C | R | jump table for type-based array size selection |
| 005645f0 | sub_5645F0 | R | element factory for array allocation |
| 00564620 | IntegerDifferenceComparator | R | comparison callback for array sorting |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005646d0 | AllocateIntArrayViaFactory | create typed dynamic array with factory/comparison callbacks |
| 0058a935 | MallocWrapperForNhMalloc | heap memory allocation wrapper |

**Guard conditions:** switch on a3 (type): 0, 1, 2, 3 allocate 2-element array; default (>=4) allocates 4-element array.

