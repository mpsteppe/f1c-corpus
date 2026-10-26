## OBBFittingAndProjection_0051427f — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureFilterAndLayerCompositing (005147ea)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 005ad1b8 | flt_5AD1B8 | R | SuspensionMomentArm [DERIVED] (also: ` — moment arm constant) |
| 005adb14 | flt_5ADB14 | R | DegreeWrap360 [DERIVED] (also: ` — 360.0 (degree wrap) |
| 005ade40 | flt_5ADE40 | R | NearZeroEpsilonPtr [DERIVED] (also: small threshold pointer (near-zero) |
| 005af5dc | flt_5AF5DC | R | Render_MatrixCoeff_Five [DERIVED] |
| 005af5e0 | unk_5AF5E0 | R | TextureRowStartData [DERIVED] |
| 005af5f0 | unk_5AF5F0 | R | RendererMatrixConst [DERIVED] |
| 005af600 | unk_5AF600 | R | D3DVertexConstArray [DERIVED] |
| 005af60c | unk_5AF60C | R | TexCoordNormalizeData [DERIVED] |
| 005d79bc | flt_5D79BC | R | BVHMinBounds [DERIVED] |
| 008b00a0 | dword_8B00A0 | R | FPUControlStore [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513e5d | FPUControlWordMerger | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
