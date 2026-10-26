## DrivingModeParameterSetup_004adf10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4732D0 (004732d0), TrackEnvironmentSelect (004ade20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x214 | RW | 1 | [LLM] |
| this | 0x21C | R | — | [LLM] |
| this | 0x220 | R | — | [LLM] |
| this | 0x25C | RW | 2 | [LLM] |
| this | 0x264 | R | — | [LLM] |
| this | 0x268 | R | — | [LLM] |
| this | 0x280 | RW | 0 | [LLM] |
| this | 0x288 | R | — | [LLM] |
| this | 0x28C | R | — | [LLM] |
| this | 0x2A4 | RW | 2 | [LLM] |
| this | 0x2AC | R | — | [LLM] |
| this | 0x2B0 | R | — | [LLM] |
| this | 0x2C8 | RW | 0 | [LLM] |
| this | 0x2D0 | R | — | [LLM] |
| this | 0x2D4 | R | — | [LLM] |
| this | 0x2EC | RW | 1 | [LLM] |
| this | 0x2F4 | R | — | [LLM] |
| this | 0x2F8 | R | — | [LLM] |
| this | 0x310 | RW | 1 | [LLM] |
| this | 0x318 | R | — | [LLM] |
| this | 0x31C | R | — | [LLM] |
| this | 0x334 | RW | 0 | [LLM] |
| this | 0x33C | R | — | [LLM] |
| this | 0x340 | R | — | [LLM] |
| this | 0x358 | RW | 1 | [LLM] |
| this | 0x360 | R | — | [LLM] |
| this | 0x364 | R | — | [LLM] |
| this | 0x40C | RW | 3 | [LLM] |
| this | 0x414 | R | — | [LLM] |
| this | 0x418 | R | — | [LLM] |
| this | 0x1CC0 | R | — | [LLM] |
| this | 0x1CE4 | RW | 1048576000 → 0.25f | [LLM] |
| this | 0x1CEC | R | — | [LLM] |
| this | 0x1CF0 | R | — | [LLM] |
| this | 0x1D08 | RW | 85 | [LLM] |
| this | 0x1D10 | R | — | [LLM] |
| this | 0x1D14 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x214: [LLM: once/conditional? does external poke survive?]
- this 0x25C: [LLM: once/conditional? does external poke survive?]
- this 0x280: [LLM: once/conditional? does external poke survive?]
- this 0x2A4: [LLM: once/conditional? does external poke survive?]
- this 0x2C8: [LLM: once/conditional? does external poke survive?]
- this 0x2EC: [LLM: once/conditional? does external poke survive?]
- this 0x310: [LLM: once/conditional? does external poke survive?]
- this 0x334: [LLM: once/conditional? does external poke survive?]
- this 0x358: [LLM: once/conditional? does external poke survive?]
- this 0x40C: [LLM: once/conditional? does external poke survive?]
- this 0x1CE4: [LLM: once/conditional? does external poke survive?]
- this 0x1D08: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ae46c | jpt_4ADF22 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646c0 | FloatClamp | [LLM] |
| 0047f1f0 | ClampByRange | [LLM] |
| 004b1de0 | ClampedFloatSetter_1de0 | [LLM] |
| 004b20d0 | ArithmeticComparison_20d0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
