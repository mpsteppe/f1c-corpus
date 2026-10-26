## ParticleEffectBillboardQuadSetup_004cc500 — BillboardQuadVertexWriter

**Summary:** Compute and write 4 billboard quad vertices for a particle sprite. Computes perpendicular vectors relative to camera direction, scales by particle size, writes each vertex position to texture buffer via PixelWriteToTextureBuffer.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleSpawnFunction (004cce90), ParticleSystemUpdateWithWindAndDamping (004cd220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | particle size (half-extent for quad) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00558e10 | PixelWriteToTextureBuffer | write vertex position + color to particle texture buffer |

**Guard conditions:** Cross-product magnitude > 0.0 determines perpendicular vector direction. If zero (degenerate), falls back to axis-aligned perpendicular.
