## Direct3DTextureResampling_00504933 — 3D texture resampling with fixed-point scaling

**Summary:** Resamples a 3D texture from source to destination dimensions using fixed-point coordinate scaling ((val<<16)/dim). Allocates two staging buffers, samples source via vtable method, copies 16-byte blocks, and writes to destination via vtable method.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DContextInit (005063a5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | element constructor for vector init |
| 0059c46e | loc_59C46E | R | SEH jump target or exception handling label |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | vector constructor for staging buffer elements |
| 00587bcf | FreeWrapper_7bcf | frees staging buffers |
| 00587c03 | OperatorNewNhMallocWrapper | allocates staging buffer memory |
| 0058a5d8 | SEHHandlerInit | initialises structured exception handler |

**Guard conditions:** If byte at offset 8 != 2 → returns -2147467259. If first staging buffer allocation fails → returns -2147024882. If second allocation fails → frees first, returns -2147024882. PASS: dimensions validated, scale computed, nested loops process all dest texels.
