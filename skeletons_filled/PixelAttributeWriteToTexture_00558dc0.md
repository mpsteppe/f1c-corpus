## PixelAttributeWriteToTexture_00558dc0 — PixelAttributeWriteToTexture

**Summary:** Write pixel attribute value into texture buffer at position computed from slot index (a2) and offset (a3), guarded by mode==1 and flag bit 31 set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4CD8D0 (004cd8d0), TelemetryBarIndicatorRenderer (004cd980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x50) | 0x20 | R | — | Texture buffer base pointer for pixel write |
| this | 0x20 | R | — | Flags byte at +32; bit 31 must be set (signed < 0) to proceed |
| this | 0x24 | R | — | Height (or width) dimension, used in pixel address calculation |
| this | 0x34 | R | — | Pointer to slot array (stride 128); slot at a2*128 + 4 provides width |
| this | 0x4C | R | — | Mode field; must equal 1 for write to proceed |
| this | 0x50 | R | — | Pointer to texture sub-context (field at +32 = texture buffer) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00558d10 | TextureAllocationWithFormatSizeFlags | Ensure texture allocation exists before writing |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | < | 0 | Flags byte bit 31 (signed negative) |
| this | 0x4C | == | 1 | Mode selector |

**Guard interpretation:** Both guards must PASS for pixel write to proceed: mode must be 1 AND flag bit 31 must be set. BLOCKED if mode != 1 or bit 31 clear.
