## VTableSubInit_0048feb0 — VTableSubInit

**Summary:** Sets vtable pointer on this object and delegates rest of initialization to a sub-initializer. Part of a UI component construction chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_46FF40 (0046ff40), ScalarDeletingDestructor_fe90 (0048fe90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer |

**Written-by note (persistence):**
- this 0x0: Once — set to vtable pointer at construction; survives unless deliberately changed.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac6b0 | off_5AC6B0 | R | VTable_5AC6B0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional; no branches.
