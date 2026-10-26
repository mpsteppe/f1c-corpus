## VTableBoolCheck_0057a850 — VTableBoolCheckAt0xA0

**Summary:** Calls virtual method at vtable offset 0xA0 with three arguments. Returns TRUE if method returns 0, FALSE otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FunctionCallWrapper_23e0 (004623e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0xA0 | R | — | vtable function pointer at index 40 (0xA0/4) — predicate method |
| obj | 0x0 | R | — | object/interface pointer from *this; vtable base |
| this | 0x0 | R | — | COM-style pointer-to-pointer handle |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional call, comparison is post-call not guard

