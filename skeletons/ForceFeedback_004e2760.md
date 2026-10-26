## ForceFeedback_004e2760 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4EF2E0 (004ef2e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x98 | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xC0 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x1E8 | R | — | [LLM] |
| this | 0x938 | RW | — | [LLM] |
| this | 0x93C | RW | — | [LLM] |
| this | 0x93E | RW | — | [LLM] |
| this | 0x93F | RW | 0 | [LLM] |
| this | 0x940 | RW | 0 | [LLM] |
| this | 0x944 | RW | 0 | [LLM] |
| this | 0x946 | RW | 0 | [LLM] |
| this | 0x948 | RW | 0 | [LLM] |
| this | 0x98C | R | — | [LLM] |
| this | 0x9A8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x938: [LLM: once/conditional? does external poke survive?]
- this 0x93C: [LLM: once/conditional? does external poke survive?]
- this 0x93E: [LLM: once/conditional? does external poke survive?]
- this 0x93F: [LLM: once/conditional? does external poke survive?]
- this 0x940: [LLM: once/conditional? does external poke survive?]
- this 0x944: [LLM: once/conditional? does external poke survive?]
- this 0x946: [LLM: once/conditional? does external poke survive?]
- this 0x948: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e708 | flt_59E708 | R | SoundVolumeLowThreshold [DERIVED] (also: ` — low threshold) |
| 0059e70c | flt_59E70C | R | FFBMinThreshold [DERIVED] (also: ` — FFB minimum threshold) |
| 0059e710 | flt_59E710 | R | FFB_SaturationThreshold [DERIVED] (also: ` — FFB maximum threshold) |
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x108 | < | 24 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
