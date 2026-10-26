## BoundingBoxComputationFromVertexData_0054e270 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GlobalVectorOffsetUpdate (0040e1f0), PhysicsAudioVectorUpdate (004e2ad0), VertexBufferTransform (0054c6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8 | R | — | [LLM] |
| *(this+0x11C) | 0xC | R | — | [LLM] |
| *(this+0x11C) | 0x10 | R | — | [LLM] |
| *(this+0x11C) | 0x14 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xE4 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053b6f0 | QRDecomposition | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x11C) | 0x8 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
