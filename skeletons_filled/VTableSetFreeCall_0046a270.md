## VTableSetFreeCall_0046a270 — DestructorWithVTableSetAndFree

**Summary:** Destructor function. Sets vtable pointer at offset 0, conditionally frees a sub-object at offset 0x348 via FreeWrapper_7bcf if non-null, then chains to LinkedListDestructor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer |
| this | 0x348 | R | — | pointer to sub-object to free if non-null |

**Written-by note (persistence):**
- this 0x0: set to vtable address at entry; overwritten once

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f878 | off_59F878 | R | VTable_59F878 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees the sub-object at this[210] if non-null |

**Guard conditions:** this[210] (offset 0x348) checked against 0. PASSES if non-null → calls FreeWrapper_7bcf. BLOCKED if null → skips FreeWrapper.
