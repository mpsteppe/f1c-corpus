## COMVTableCallVia0xc4_0057a8e0 — VTableBoolCheckAtOffset0xC4

**Summary:** Calls virtual method at vtable offset 0xC4 with one argument. Returns TRUE if method returns 0, FALSE otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BufferSendWithLocks (00462760), NetworkEntrantSetupWithIDCheck (004627c0), UniqueID (004630d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0xC4 | R | — | vtable function pointer at index 49 (0xC4/4) — predicate method |
| obj | 0x0 | R | — | object/interface pointer from *this; vtable base |
| this | 0x0 | R | — | COM-style pointer-to-pointer handle |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional call, comparison is post-call not guard

