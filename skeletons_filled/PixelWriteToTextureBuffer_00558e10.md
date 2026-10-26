## PixelWriteToTextureBuffer_00558e10 — PixelDataTextureWriter

**Summary:** Writes pixel/vertex data (4 values: colour/attribute) into a texture buffer at a computed offset, gated on format type and overflow flag. Allocates texture buffer if needed.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectBillboardQuadSetup (004cc500), F_3DBoundingBoxRender (004cc700), WheelContactParticle (004cd6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x50) | 0x0 | RW | — | pixel/vtx colour/attribute component 0 |
| *(this+0x50) | 0x4 | RW | — | pixel/vtx colour/attribute component 1 |
| *(this+0x50) | 0x8 | RW | — | pixel/vtx colour/attribute component 2 |
| *(this+0x50) | 0x18 | RW | — | pixel/vtx colour/attribute component 3 |
| *(this+0x50) | 0x20 | R | — | texture buffer stride or offset fields |
| this | 0x20 | R | — | flags (bit 7 = overflow/ready flag checked) |
| this | 0x24 | R | — | row stride / buffer dimension |
| this | 0x34 | R | — | texture data array pointer |
| this | 0x4C | R | — | format type identifier (checked == 1) |
| this | 0x50 | R | — | texture lock/format descriptor pointer |

**Written-by note (persistence):**
- *(this+0x50) 0x0: recalc every frame — external poke does NOT persist
- *(this+0x50) 0x4: recalc every frame — external poke does NOT persist
- *(this+0x50) 0x8: recalc every frame — external poke does NOT persist
- *(this+0x50) 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00558d10 | TextureAllocationWithFormatSizeFlags | allocates texture buffer if not yet allocated |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | == | 1 | format type check (must be 1 to write pixels) |

**Guard interpretation:** If format type != 1 → return early (BLOCKED: wrong format). If bit 7 of flags (this+0x20) is NOT set (>= 0) → skip write (BLOCKED: overflow/ready flag not set). PASSES: format type == 1 AND overflow flag bit 7 set → call TextureAllocationWithFormatSizeFlags if needed, compute buffer offset, write 4 data values to buffer.
