## DirectXTextureSurfaceFormatInitialization_0050afe2 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50B797 (0050b797), ObjectInit_b7cb (0050b7cb), ConstructorWithInit_b7e3 (0050b7e3), ShortComputation_b7fb (0050b7fb), ShortComputation_b813 (0050b813)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x1030 | R | — | [LLM] |
| this | 0x1034 | R | — | [LLM] |
| this | 0x1038 | R | — | [LLM] |
| this | 0x103C | R | — | [LLM] |
| this | 0x1040 | R | — | [LLM] |
| this | 0x1044 | R | — | [LLM] |
| this | 0x1074 | RW | — | [LLM] |
| this | 0x1078 | RW | 3 | [LLM] |
| this | 0x107C | RW | 3 | [LLM] |
| this | 0x1080 | RW | 16 | [LLM] |
| this | 0x1084 | RW | — | [LLM] |
| this | 0x1088 | RW | — | [LLM] |
| this | 0x108C | RW | — | [LLM] |
| this | 0x1090 | RW | — | [LLM] |
| this | 0x1094 | RW | — | [LLM] |
| this | 0x1098 | RW | — | [LLM] |
| this | 0x109C | RW | — | [LLM] |
| this | 0x10A0 | RW | — | [LLM] |
| this | 0x10A4 | RW | — | [LLM] |
| this | 0x10A8 | RW | — | [LLM] |
| this | 0x10AC | RW | — | [LLM] |
| this | 0x10B0 | RW | 18446744073709551615 | [LLM] |
| this | 0x10B4 | RW | 18446744073709551615 | [LLM] |
| this | 0x10B8 | RW | 0 | [LLM] |
| this | 0x10BC | RW | 0 | [LLM] |
| this | 0x10C0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1074: [LLM: once/conditional? does external poke survive?]
- this 0x1078: [LLM: once/conditional? does external poke survive?]
- this 0x107C: [LLM: once/conditional? does external poke survive?]
- this 0x1080: [LLM: once/conditional? does external poke survive?]
- this 0x1084: [LLM: once/conditional? does external poke survive?]
- this 0x1088: [LLM: once/conditional? does external poke survive?]
- this 0x108C: [LLM: once/conditional? does external poke survive?]
- this 0x1090: [LLM: once/conditional? does external poke survive?]
- this 0x1094: [LLM: once/conditional? does external poke survive?]
- this 0x1098: [LLM: once/conditional? does external poke survive?]
- this 0x109C: [LLM: once/conditional? does external poke survive?]
- this 0x10A0: [LLM: once/conditional? does external poke survive?]
- this 0x10A4: [LLM: once/conditional? does external poke survive?]
- this 0x10A8: [LLM: once/conditional? does external poke survive?]
- this 0x10AC: [LLM: once/conditional? does external poke survive?]
- this 0x10B0: [LLM: once/conditional? does external poke survive?]
- this 0x10B4: [LLM: once/conditional? does external poke survive?]
- this 0x10B8: [LLM: once/conditional? does external poke survive?]
- this 0x10BC: [LLM: once/conditional? does external poke survive?]
- this 0x10C0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00514fee | KeyframeQuadInterpolationWithBitPackedSelector | R | [LLM] |
| 0051512c | sub_51512C | R | [LLM] |
| 005151af | sub_5151AF | R | [LLM] |
| 005152eb | FileIOWrapper | R | [LLM] |
| 00515303 | QuantizationColorSpaceConversion | R | [LLM] |
| 00515417 | sub_515417 | R | [LLM] |
| 00515869 | FileOpenAndValidate | R | [LLM] |
| 0051588c | sub_51588C | R | [LLM] |
| 005158af | DelegationWithErrorCheck | R | [LLM] |
| 005158e3 | InitProcessWrapper | R | [LLM] |
| 005adb90 | off_5ADB90 | R | VTable_D3DWrap [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507496 | DirectXTextureCreationWithMipmapChain | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1078 | != | 3 | [LLM] |
| this | 0x107C | != | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
