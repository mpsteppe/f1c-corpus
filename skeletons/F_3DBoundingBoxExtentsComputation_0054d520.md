## F_3DBoundingBoxExtentsComputation_0054d520 — [LLM: short descriptive name]

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
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x54 | RW | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x5C | RW | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x6C | RW | — | [LLM] |
| this | 0x70 | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0xDC | RW | — | [LLM] |
| this | 0xE0 | RW | — | [LLM] |
| this | 0xE4 | RW | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x44: recalc every frame — external poke does NOT persist
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x4C: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x5C: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x64: recalc every frame — external poke does NOT persist
- this 0x68: recalc every frame — external poke does NOT persist
- this 0x6C: recalc every frame — external poke does NOT persist
- this 0x70: recalc every frame — external poke does NOT persist
- this 0x74: recalc every frame — external poke does NOT persist
- this 0x78: recalc every frame — external poke does NOT persist
- this 0xDC: recalc every frame — external poke does NOT persist
- this 0xE0: recalc every frame — external poke does NOT persist
- this 0xE4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005b8984 | flt_5B8984 | R | MeshBoundMaxInit [DERIVED] |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x11C) | 0x8 | > | 0 | [LLM] |
| this | 0x118 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
