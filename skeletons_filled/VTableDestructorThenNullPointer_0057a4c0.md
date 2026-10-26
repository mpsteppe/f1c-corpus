## VTableDestructorThenNullPointer_0057a4c0 — VTableScopedDestructAndNull

**Summary:** Safely destroys an object through its vtable: calls destructor at vtable+0x4C, then operator delete at vtable+0x44 with flag 1, and nulls the pointer. Returns the result of the destructor call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57AA80 (0057aa80), sub_57AB50 (0057ab50), sub_57ACB0 (0057acb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x44 | R | — | vtable entry at offset 0x44 (operator delete with flag) |
| *(obj+0x0) | 0x4C | R | — | vtable entry at offset 0x4C (destructor) |
| obj | 0x0 | R | — | vtable pointer of the object being destroyed |
| this | 0x0 | RW | 0 | pointer slot (nulled after destruction) |

**Written-by note (persistence):**
- this 0x0: written to 0 after destruction; survives as nulled pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if *this (object pointer) is NULL, skip all destruction and return.
