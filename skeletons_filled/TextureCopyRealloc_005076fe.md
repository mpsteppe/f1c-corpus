## TextureCopyRealloc_005076fe — Reallocate staging buffer on format mismatch

**Summary:** Compares destination format vs source format (offset 8 in both objects). If they differ, reallocates a staging buffer (16 bytes × width) via OperatorNewNhMallocWrapper with vector construction, stores result at this[1043] and the new format at this[1042].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DContextInit (005063a5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x8 | R | — | source surface format code (to compare with dest format) |
| this | 0x8 | R | — | dest surface format code |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | element constructor for vector init |
| 0059c55c | loc_59C55C | R | SEH jump target or exception handling label |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | vector constructor for staging buffer elements |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 16 × width bytes for staging buffer |
| 0058a5d8 | SEHHandlerInit | initialises structured exception handler |

**Guard conditions:** If dest format (this+8) == source format (*(a1+8)+8) → returns 0 (no reallocation needed). If formats differ → allocates new buffer; if allocation fails → returns -2147024882. PASS: buffer stored at this[1043], format at this[1042].
