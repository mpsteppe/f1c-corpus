## SetVtablePointerAndCallInit_005870d0 — Set vtable and free pointer field

**Summary:** Sets vtable at offset 0x0 to VTable_TaskBase, then frees pointer at offset 0x4 (calls FreeIfNonNull on this+1). Partial cleanup/re-init pattern for TaskBase objects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_581070 (00581070), sub_5813E0 (005813e0), sub_583AE0 (00583ae0), sub_585870 (00585870), DestructorWithConditionalFree_7070 (00587070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5B8C30 | VTable pointer set to TaskBase |

**Written-by note (persistence):**
- this 0x0: set to vtable pointer each call; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8c30 | off_5B8C30 | R | VTable_TaskBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — vtable always set; FreeIfNonNull handles null internally.
