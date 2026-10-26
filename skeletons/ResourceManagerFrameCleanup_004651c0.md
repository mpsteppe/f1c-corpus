## ResourceManagerFrameCleanup_004651c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TeamRadioNetworkMessageProcessing (0045f710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x6C)+0x4) | 0x4 | R | — | [LLM] |
| *(*(obj+0x7C)+0x4) | 0x4 | R | — | [LLM] |
| *(obj+0x6C) | 0x0 | R | — | [LLM] |
| *(obj+0x6C) | 0x8 | R | — | [LLM] |
| *(obj+0x7C) | 0x0 | R | — | [LLM] |
| *(obj+0x7C) | 0x8 | R | — | [LLM] |
| obj | 0x60 | RW | — | [LLM] |
| obj | 0x6C | RW | 0 | [LLM] |
| obj | 0x70 | RW | 0 | [LLM] |
| obj | 0x74 | RW | 0 | [LLM] |
| obj | 0x78 | RW | 0 | [LLM] |
| obj | 0x7C | RW | 0 | [LLM] |
| obj | 0x80 | RW | 0 | [LLM] |
| obj | 0x84 | RW | 0 | [LLM] |
| obj | 0x88 | RW | 0 | [LLM] |
| obj | 0xE40C | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x60: [LLM: once/conditional? does external poke survive?]
- obj 0x6C: [LLM: once/conditional? does external poke survive?]
- obj 0x70: [LLM: once/conditional? does external poke survive?]
- obj 0x74: [LLM: once/conditional? does external poke survive?]
- obj 0x78: [LLM: once/conditional? does external poke survive?]
- obj 0x7C: [LLM: once/conditional? does external poke survive?]
- obj 0x80: [LLM: once/conditional? does external poke survive?]
- obj 0x84: [LLM: once/conditional? does external poke survive?]
- obj 0x88: [LLM: once/conditional? does external poke survive?]
- obj 0xE40C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00464ef0 | FloatFractionFromInt | [LLM] |
| 00568cf0 | HighResolutionTimerDelta | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(obj+0x6C) | 0x8 | == | 0 | [LLM] |
| *(obj+0x7C) | 0x8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
