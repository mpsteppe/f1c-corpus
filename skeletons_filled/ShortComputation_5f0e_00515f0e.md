## ShortComputation_5f0e_00515f0e — InitObjWithConstantAndParam

**Summary:** Writes constant 53 to obj+0x14 and parameter a2 to obj+0x18 via pointer read from this's first field, then dispatches virtual function 0 on this and returns its result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MemoryAllocator (00515f23), MemoryAllocatorWithAlignment (0051601f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | first field of sub-object (pointer), used as base for writes |
| obj | 0x14 | RW | 53 | written with constant 53 (sentinel/type tag) |
| obj | 0x18 | RW | — | written with caller-supplied parameter a2 |
| this | 0x0 | R | — | vtable pointer for virtual dispatch |

**Written-by note (persistence):**
- obj 0x14: written once with constant 53, survives until externally modified
- obj 0x18: written once with parameter, survives until externally modified

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — always executes unconditionally.
