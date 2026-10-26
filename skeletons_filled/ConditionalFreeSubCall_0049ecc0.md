## ConditionalFreeSubCall_0049ecc0 — ConditionalFreeSubObject

**Summary:** Conditionally frees a sub-object at this+0xC if non-null. Calls destructor, empty stub helper, and heap free wrapper, then nulls the pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiStageCleanupWithRepeatedCallCycle (0049d150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | Pointer to sub-object being freed; non-null triggers free sequence |

**Written-by note (persistence):**
- this 0xC: Set to 0 after free; pointer lives in heap-allocated parent struct, survives via external allocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005502c0 | DestructorWithConditionalFreeFlagClear | Calls destructor on sub-object and clears associated free-guard flag |
| 00557470 | EmptyStub_7470 | Empty stub called before free (possibly placeholder or virtual dispatch) |
| 00587bcf | FreeWrapper_7bcf | Wraps heap deallocation for the sub-object |

**Guard conditions:** Checks this+0xC != 0 — non-null PASSES (triggers destructor+free+null), zero BLOCKS (skip entire body)
