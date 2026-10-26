## PixelFormatConverter_00513374 — PixelFormatTo8BitIndexed

**Summary:** Convert 4-byte or 5-byte RGBA pixels to 8-bit indexed via 15-bit color LUT (a3), or remap existing 8-bit indices via secondary table (a4). Updates format state fields on completion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_51389E (0051389e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pixel count |
| this | 0x4 | RW | — | output byte count |
| this | 0x8 | RW | 3 | format/phase (2=15-bit color→indexed, 6=5-byte→indexed, 3=index remap) |
| this | 0x9 | R | — | current state — must be 8 for processing |
| this | 0xA | RW | 1 | bytes per pixel after conversion (1 for 8-bit indexed) |
| this | 0xB | RW | — | output stride/pitch (set to current state value) |

**Written-by note (persistence):**
- this 0x4: always written — byte count; survives until overwritten
- this 0x8: set to 3 after v5==2/6 conversion; survives until overwritten
- this 0xA: set to 1; survives until overwritten
- this 0xB: set to current state (8); survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 2 | convert 4-byte RGBA to 8-bit indexed via 15-bit LUT |
| this | 0x8 | == | 6 | convert 5-byte format to 8-bit indexed via 15-bit LUT |
| this | 0x8 | == | 3 | index remap pass via a4 table |
| this | 0x9 | == | 8 | state — all paths require state 8 |
| param a3 | != | 0 | LUT table required for v5==2 and v5==6 paths |
| param a4 | != | 0 | remap table required for v5==3 path |

**Guard interpretation:** PASSES when (0x8==2 || 0x8==6) && a3!=0 && 0x9==8 → 15-bit RGBA→8-bit LUT conversion. PASSES when 0x8==3 && a4!=0 && 0x9==8 → index remap. BLOCKED (early return) when state 0x9 != 8, or when LUT/remap table missing for the required path.
