## VTableBooleanTestWrapper_0057a830 — VTableBooleanInvertTest

**Summary:** Calls virtual method at vtable offset 0x9C, passes a2, a3. Returns TRUE if method returns 0, FALSE otherwise. Boolean inversion wrapper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_23b0 (004623b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x9C | R | — | vtable function pointer at index 39 (0x9C/4) — predicate method |
| obj | 0x0 | R | — | object/interface pointer from *this; vtable base |
| this | 0x0 | R | — | COM-style pointer-to-pointer handle |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional call, comparison is post-call not guard

