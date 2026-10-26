## DoubleBufferFree_004f83b0 — DoubleBufferFree

**Summary:** Frees two double-buffered arrays of 45 objects each (offset 0x694 and 0x6D8). Destroys each object via ObjectDestructor, frees the buffer memory, nulls pointers, and clears active flag at offset 4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C6E80 (004c6e80), ArithmeticComparison_8370 (004f8370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | Active flag (set to 0 after buffers freed) |
| this | 0x694 | RW | 0 | First double-buffer pointer (45 objects) |
| this | 0x6D8 | RW | 0 | Second double-buffer pointer (45 objects) |

**Written-by note (persistence):**
- this 0x4: Set to 0 after free; external poke overwrites
- this 0x694: Set to 0 after free; external poke overwrites
- this 0x6D8: Set to 0 after free; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f8250 | ObjectDestructor | Calls vtable destruction chain on each object in the buffer |
| 00587bcf | FreeWrapper_7bcf | Frees the heap-allocated buffer memory |

**Guard conditions:** Each buffer pointer checked: if non-null, iterates all 45 objects (180 bytes / 4-byte pointers) for destruction, then frees buffer and nulls pointer. If null, skip.
