## ObjectResetWithVTableDispatch_00499af0 — Object reset with sub-object destruction

**Summary:** Destroys sub-object at this+0x50 (virtual destructor call) if non-null, then zeroes entire structure via memset(0x50 bytes). Part of object reset/recycle.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4963D0 (004963d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x50) | 0x0 | R | — | vtable pointer of sub-object — first virtual method (destructor) called |
| this | 0x50 | R | — | pointer to sub-object to destroy before reset |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard: `this+0x50 != NULL` — PASSES calls virtual destructor (vtable[0] with arg 1) on sub-object; BLOCKED skips destruction. memset(this, 0, 0x50) is unconditional.