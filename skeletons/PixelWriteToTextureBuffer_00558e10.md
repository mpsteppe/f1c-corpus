## PixelWriteToTextureBuffer_00558e10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectBillboardQuadSetup (004cc500), F_3DBoundingBoxRender (004cc700), WheelContactParticle (004cd6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x50) | 0x0 | RW | — | [LLM] |
| *(this+0x50) | 0x4 | RW | — | [LLM] |
| *(this+0x50) | 0x8 | RW | — | [LLM] |
| *(this+0x50) | 0x18 | RW | — | [LLM] |
| *(this+0x50) | 0x20 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |

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
| 00558d10 | TextureAllocationWithFormatSizeFlags | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
