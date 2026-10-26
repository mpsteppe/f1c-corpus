## TexturePathParsingAndDimensionCalculation_00552f20 — TexturePathParsingAndDimensionCalculation

**Summary:** Parses font texture file path and computes texture coordinate scale factors. Dispatches to sub_552BA0 (16-bit pixel format 5/6) or sub_552D70 (32-bit pixel format 7/8) for font sheet analysis. Extracts filename without path or extension (stored at this+0x14). Computes 1.0/width and 1.0/height as floats for UV calculation, stores at offsets 0x0 and 0x4. Sets the texture's field 13 (offset 0x34) to the key color from offset 0x2C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_552470 (00552470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x64) | 0x1C | R | — | Source texture width in pixels (used for 1.0/width) |
| *(this+0x64) | 0x20 | R | — | Source texture height in pixels (used for 1.0/height) |
| *(this+0x64) | 0x30 | R | — | Pixel format enum (5/6 → sub_552BA0, 7/8 → sub_552D70) |
| *(this+0x64) | 0x34 | RW | — | Texture surface field 13 (set to key color from this+0x2C) |
| this | 0x0 | RW | — | 1.0 / width (float, U texcoord scale factor) |
| this | 0x4 | RW | — | 1.0 / height (float, V texcoord scale factor) |
| this | 0x2C | R | — | Key color value (copied to texture surface field) |
| this | 0x64 | R | — | Source surface pointer (read for format, width, height) |

**Written-by note (persistence):**
- *(this+0x64) 0x34: set to key color from this+0x2C; survives external poke
- this 0x0..0x4: computed from texture dimensions; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00552fac | jpt_552F31 | R | Jump table for switch on pixel format (5/6 vs 7/8 dispatch) |
| 0059e43c | flt_59E43C | R | Unreferenced in this function (constant in binary) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00552ba0 | sub_552BA0 | Font texture sheet analyzer for 16-bit pixel formats (5/6) |
| 00552d70 | sub_552D70 | Font texture sheet analyzer for 32-bit pixel formats (7/8) |
| 0058b050 | CRTStrrchr | C runtime strrchr — finds last backslash in path for filename extraction |

**Guard conditions:** No early return. Switch on pixel format: 5/6 dispatches 16-bit analyzer; 7/8 dispatches 32-bit analyzer; default does nothing. Always proceeds to filename extraction and scale computation.
