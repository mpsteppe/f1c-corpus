## NodeDestructionWithVirtualCall_00586620 — ConditionalVirtualDestructorCall

**Summary:** Checks flag byte at offset 0x8; if non-zero and vtable pointer at offset 0x0 is non-null, calls virtual destructor method with parameter 1. Returns the flag value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_585870 (00585870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | Dereferenced vtable pointer from this (first virtual method table entry) |
| obj | 0x0 | R | — | Object pointer (this) used as vtable base |
| this | 0x0 | R | — | Vtable pointer; if non-null, dispatch virtual destructor |
| this | 0x8 | R | — | Flag byte: if non-zero, destructor should be called |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Flag byte at offset 0x8 must be non-zero AND vtable pointer at offset 0x0 must be non-null to dispatch virtual destructor (**v2)(v2, 1). If flag is 0, returns 0 immediately without any call.
