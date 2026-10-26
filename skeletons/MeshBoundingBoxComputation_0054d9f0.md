## MeshBoundingBoxComputation_0054d9f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneNodeStateUpdateWithTransform (005569f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x144)+0xC) | 0x11C | R | — | [LLM] |
| *(this+0x13C) | 0x4 | RW | — | [LLM] |
| *(this+0x13C) | 0x18 | R | — | [LLM] |
| *(this+0x13C) | 0x24 | R | — | [LLM] |
| *(this+0x144) | 0x0 | R | — | [LLM] |
| *(this+0x144) | 0x4 | R | — | [LLM] |
| *(this+0x144) | 0x8 | RW | 0 | [LLM] |
| *(this+0x144) | 0xC | R | — | [LLM] |
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
| this | 0x13C | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x13C) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0x144) 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x54: [LLM: once/conditional? does external poke survive?]
- this 0x58: [LLM: once/conditional? does external poke survive?]
- this 0x5C: [LLM: once/conditional? does external poke survive?]
- this 0x60: [LLM: once/conditional? does external poke survive?]
- this 0x64: [LLM: once/conditional? does external poke survive?]
- this 0x68: [LLM: once/conditional? does external poke survive?]
- this 0x6C: [LLM: once/conditional? does external poke survive?]
- this 0x70: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]
- this 0xDC: [LLM: once/conditional? does external poke survive?]
- this 0xE0: [LLM: once/conditional? does external poke survive?]
- this 0xE4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054e0e0 | SingleCallWrapper_e0e0 | [LLM] |
| 0054e0f0 | Wrapper_e0f0 | [LLM] |
| 0055d900 | sub_55D900 | [LLM] |
| 0055da50 | sub_55DA50 | [LLM] |
| 0055e320 | sub_55E320 | [LLM] |
| 0055eb30 | sub_55EB30 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x144) | 0x0 | != | 1 | [LLM] |
| *(this+0x144) | 0x0 | == | 2 | [LLM] |
| this | 0x118 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
