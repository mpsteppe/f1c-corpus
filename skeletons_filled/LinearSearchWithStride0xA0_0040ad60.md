## LinearSearchWithStride0xA0_0040ad60 — Linear Search With Stride 160

**Summary:** Linear search for pointer a2 in stride-160 array at this+0xC with this[4] entries. Returns matching index (0-based) or -1 if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LookupWithOptionalCallback (0040b450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Base pointer of stride-160 array (entries compared against a2) |
| this | 0x10 | R | — | Array entry count (loop bound) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[4] (offset 0x10) must be > 0 for loop to execute. If 0 or negative, returns -1 immediately. Loop exits when index >= this[4] without match, returning -1.
