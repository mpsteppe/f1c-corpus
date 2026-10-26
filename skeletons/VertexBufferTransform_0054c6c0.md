## VertexBufferTransform_0054c6c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioNetworkTreeWalker (00544d30), sub_557670 (00557670)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x138) | 0x3C | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x100 | RW | 0 | [LLM] |
| this | 0x104 | RW | 0 | [LLM] |
| this | 0x108 | RW | 0 | [LLM] |
| this | 0x10C | RW | 0 | [LLM] |
| this | 0x110 | RW | 0 | [LLM] |
| this | 0x114 | RW | 0 | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |
| this | 0x138 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x100: [LLM: once/conditional? does external poke survive?]
- this 0x104: [LLM: once/conditional? does external poke survive?]
- this 0x108: [LLM: once/conditional? does external poke survive?]
- this 0x10C: [LLM: once/conditional? does external poke survive?]
- this 0x110: [LLM: once/conditional? does external poke survive?]
- this 0x114: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053b130 | F_10FloatStructInitializer | [LLM] |
| 0053b160 | EmptyStub_b160 | [LLM] |
| 0053b200 | MultiFieldSetter | [LLM] |
| 0053b240 | EulerAngleToRotationMatrix | [LLM] |
| 0054b4d0 | sub_54B4D0 | [LLM] |
| 0054d080 | sub_54D080 | [LLM] |
| 0054d520 | F_3DBoundingBoxExtentsComputation | [LLM] |
| 0054e080 | FlagSetLoop | [LLM] |
| 0054e270 | BoundingBoxComputationFromVertexData | [LLM] |
| 0055d200 | StructZeroInitWithBaseCall | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x118 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
