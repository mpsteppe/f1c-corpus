## ConditionalDualCleanup_00499b50 — DualConditionalResourceCleanup

**Summary:** Conditionally cleans up two resources held by the object. If field at offset 0x30 (pointer) is non-NULL, frees it via ResourceCascadeCleanup and clears the field to 0. If field at offset 0x2C is non-zero, invokes DestructorWithConditionalFreeFlagClear. Returns the original value of field 0x30.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithFreeCondition (00477ee0), ConditionalConstructorDestructor (00485720), DestructorWithTripleFree (00485870), DestructorWithConditionalFree_5900 (00485900), UIListObjectDestructor (00485960), LinkedListDtor (004859d0), DualCleanupWithConditionalFree (004881b0), TreeNodeRecursiveDestructor (00499da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | resource handle/flag checked for destructor call |
| this | 0x30 | RW | 0 | pointer to resource freed then cleared |

**Written-by note (persistence):**
- this 0x30: conditionally written to 0 after cleanup; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005539f0 | ResourceCascadeCleanup | cascading free of resource pointed to by field 0x30 |

**Guard conditions:** this[12] (offset 0x30) checked non-zero — if non-NULL, ResourceCascadeCleanup called and field cleared. this[11] (offset 0x2C) checked non-zero — if non-zero, DestructorWithConditionalFreeFlagClear called. Both conditions independent; both can fire in sequence.
