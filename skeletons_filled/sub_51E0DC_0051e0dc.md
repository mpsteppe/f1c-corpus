## sub_51E0DC_0051e0dc — TextureContextInit

**Summary:** Initializes texture processing context. Allocates main structure (44 bytes), sets dispatch function pointers, validates pixel mode (must be 3), allocates 32 row buffers (4KB each), allocates palette buffer, conditionally allocates dither resources when mode 2 activated.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | allocator vtable function (allocate) |
| *(this+0x4) | 0x4 | R | — | allocator vtable function (allocate array) |
| *(this+0x4) | 0x8 | R | — | allocator vtable function (allocate typed) |
| obj | 0x0 | R | — | object vtable pointer |
| obj | 0x14 | RW | 56 | error limit set when pixel width check fails |
| obj | 0x18 | RW | 256 | error limit set when pixel count too high |
| this | 0x0 | R | — | object vtable pointer |
| this | 0x4 | R | — | allocator pointer |
| this | 0x4C | RW | 2 | mode flag (set to 2 for block decompression) |
| this | 0x54 | R | — | pixel count field |
| this | 0x5A | R | — | palette presence flag (byte) |
| this | 0x5C | R | — | pixel width |
| this | 0x64 | R | — | channel count (must be 3) |
| this | 0x1A4 | RW | — | context pointer (allocated and written) |

**Written-by note (persistence):**
- obj 0x14: set to 56 only when pixel width validation fails
- obj 0x18: set to 256 only when pixel count exceeds limit
- this 0x4C: set to 2 when external flag at this+0x4C is set
- this 0x1A4: set once to allocated context; survives for lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051dfcb | sub_51DFCB | R | function pointer stored in context dispatch table |
| 0051e0cd | SetVehicleFlag | R | function pointer stored in context dispatch table |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | == | 2 | mode flag indicates block decompression enabled |
| this | 0x64 | != | 3 | channel count must be exactly 3 |

**Guard interpretation:** When this+0x64 != 3, trigger error 46 and abort initialization (line 15-18). When this+0x4C == 2, allocate dither buffer and symmetric table (lines 52-61). PASSES: channel count == 3 allows init; mode == 2 allocates extra resources. BLOCKED: channel count != 3 raises error.
