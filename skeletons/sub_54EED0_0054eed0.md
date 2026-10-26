## sub_54EED0_0054eed0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneBatchRenderCheck (0054f5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | 1 | [LLM] |
| *(this+0x1E8) | 0x18 | R | — | [LLM] |
| *(this+0x1E8) | 0x28 | R | — | [LLM] |
| *(this+0x1E8) | 0x2C | R | — | [LLM] |
| *(this+0x1E8) | 0x30 | R | — | [LLM] |
| *(this+0x1E8) | 0x34 | RW | — | [LLM] |
| *(this+0x1E8) | 0x38 | RW | — | [LLM] |
| *(this+0x1E8) | 0x3C | RW | — | [LLM] |
| *(this+0x1E8) | 0x40 | RW | — | [LLM] |
| *(this+0x1E8) | 0x44 | RW | — | [LLM] |
| *(this+0x1E8) | 0x48 | RW | — | [LLM] |
| *(this+0x1E8) | 0x4C | RW | — | [LLM] |
| *(this+0x1E8) | 0x50 | RW | — | [LLM] |
| *(this+0x1E8) | 0x58 | RW | — | [LLM] |
| *(this+0x1E8) | 0x5C | RW | — | [LLM] |
| *(this+0x1E8) | 0x60 | RW | — | [LLM] |
| *(this+0x1E8) | 0x64 | RW | — | [LLM] |
| *(this+0x1E8) | 0x68 | RW | — | [LLM] |
| *(this+0x1E8) | 0x6C | RW | — | [LLM] |
| *(this+0x1E8) | 0x70 | RW | — | [LLM] |
| this | 0x1E0 | R | — | [LLM] |
| this | 0x1E4 | R | — | [LLM] |
| this | 0x1E8 | R | — | [LLM] |
| this | 0x204 | R | — | [LLM] |
| this | 0x2EC | R | — | [LLM] |
| this | 0x2F0 | R | — | [LLM] |
| this | 0x2F4 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x34: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x38: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x3C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x40: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x44: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x48: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x4C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x50: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x58: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x5C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x60: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x64: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x68: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x6C: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x70: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054eb40 | F_2D3DTrianglePointTest | [LLM] |
| 00559a30 | SingleFunctionCallWrapper_9a30 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x1E8) | 0x0 | == | 6 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
