## MemoryAllocationWithVectorConstructor_00504640 — Staging buffer alloc, fill via surface methods, free

**Summary:** Allocates a staging buffer (16 bytes × width), initialises it via vector constructor, fills it by calling source and destination surface vtable methods per block coordinate, then frees the buffer. Validates surface dimensions match before processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DContextInit (005063a5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | element constructor for vector (called per-element during allocation init) |
| 0059c432 | loc_59C432 | R | SEH jump target or exception handling label |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | vector constructor: initialises N elements of size 16 using sub_5007EC |
| 00587bcf | FreeWrapper_7bcf | frees the allocated staging buffer |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 16 * width bytes for staging buffer |
| 0058a5d8 | SEHHandlerInit | initialises structured exception handler for this function |

**Guard conditions:** If source width != dest width, or heights mismatch, or depths mismatch → returns -2147467259. If staging buffer allocation returns NULL → returns -2147467259. Otherwise proceeds to fill buffer via surface methods and free.
