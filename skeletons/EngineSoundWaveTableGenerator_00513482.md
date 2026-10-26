## EngineSoundWaveTableGenerator_00513482 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureImageColorTransform (0051378b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | R | — | [LLM] |
| this | 0x61 | R | — | [LLM] |
| this | 0x116 | R | — | [LLM] |
| this | 0x117 | R | — | [LLM] |
| this | 0x12C | RW | — | [LLM] |
| this | 0x130 | R | — | [LLM] |
| this | 0x138 | RW | — | [LLM] |
| this | 0x144 | RW | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x151 | R | — | [LLM] |
| this | 0x152 | R | — | [LLM] |
| this | 0x153 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x12C: [LLM: once/conditional? does external poke survive?]
- this 0x138: [LLM: once/conditional? does external poke survive?]
- this 0x144: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 005adb58 | dbl_5ADB58 | R | Unknown_5ADB58 [DERIVED] |
| 005adb60 | dbl_5ADB60 | R | Unknown_DInput_5ADB60 [DERIVED] |
| 005adb68 | dbl_5ADB68 | R | AudioCodecConst [DERIVED] |
| 005af430 | dbl_5AF430 | R | D3DDeviceFlag [DERIVED] |
| 005af438 | dbl_5AF438 | R | AudioCompressionDouble [DERIVED] |
| 005af440 | dbl_5AF440 | R | Audio_QuantizeThreshold [DERIVED] |
| 005af448 | dbl_5AF448 | R | TimerFreqScale [DERIVED] (also: ` — timer frequency scaling constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00517e92 | sub_517E92 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 005881f0 | sub_5881F0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x117 | > | 8 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
