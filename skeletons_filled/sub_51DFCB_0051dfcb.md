## sub_51DFCB_0051dfcb — TextureCodecModeDispatch

**Summary:** Dispatches between texture encoding modes based on state flag. Selects PackedPixelCopyWithPaletteLookup (mode 0/1) or BlockTextureDecompression (mode 2). Allocates dither buffer and symmetric table when entering mode 2, clears grid rows when dirty flag is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | object vtable pointer |
| obj | 0x14 | RW | 56 | allocation size / limit for dither buffer |
| obj | 0x18 | RW | 256 | row count limit |
| this | 0x0 | R | — | object vtable pointer |
| this | 0x4 | R | — | allocator pointer |
| this | 0x8 | R | — | object pointer (second vtable) |
| this | 0x4C | RW | 2 | codec mode flag (0=pass-through, 1=palette copy, 2=block decompression) |
| this | 0x5C | R | — | pixel width (stride) |
| this | 0x70 | R | — | palette count |
| this | 0x1A4 | R | — | context pointer |
| this | 0x1A8 | RW | — | unknown context field |
| this | 0x1AC | RW | — | unknown context field |
| this | 0x1BC | R | — | unknown field |
| this | 0x1C0 | RW | 0 | context field (initialized to 0) |
| this | 0x1C4 | RW | — | dither error buffer pointer |
| this | 0x1C8 | RW | 0 | context toggle field (initialized to 0) |
| this | 0x1CC | R | — | unknown field |

**Written-by note (persistence):**
- obj 0x14: set only when allocation needed (56); persists until overwritten
- obj 0x18: set to 256 only when row count exceeds limit; persists until overwritten
- this 0x4C: set to 2 when transitioning from 0; persists until changed externally
- this 0x1A8: set to function dispatch pointer; persists until overwritten
- this 0x1AC: set to function dispatch pointer; persists until overwritten
- this 0x1C0: set to 0 once; persists until changed externally
- this 0x1C4: allocated dither buffer pointer; persists until freed
- this 0x1C8: set to 0 once; persists until changed externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051d1db | TrackSurfaceHeightmapIncrement | R | function pointer for heightmap increment mode (a2!=0 path) |
| 0051dc01 | PackedPixelCopyWithPaletteLookup | R | function pointer for palette copy mode (mode 0/1) |
| 0051dcaa | BlockTextureDecompression | R | function pointer for block decompression mode (mode 2) |
| 0051dfa8 | VehicleUpdateFrameSetup | R | function pointer for update frame setup (a2!=0 path) |
| 0051dfca | nullsub_4 | R | no-op function pointer for palette copy mode |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | clears dither error buffer to zero |
| 0051df18 | SymmetricArrayInit | allocates and fills symmetric offset table |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | == | 0 | mode flag = pass-through (skip mode switch) |
| this | 0x4C | == | 2 | mode flag = block decompression (allocate dither resources) |

**Guard interpretation:** When this+0x4C == 0, skip mode transition and keep current function pointers (line 15-16). When this+0x4C == 2, switch to BlockTextureDecompression, allocate dither buffer and symmetric array on first entry. PASSES: mode 2 enables block decompression path with full resource allocation. BLOCKED: mode 0 keeps palette copy path without extra allocation.
