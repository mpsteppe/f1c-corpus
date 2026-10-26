## UIComponentScrollUpdate_0047b1e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | [LLM] |
| obj | 0x54 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0xE4 | RW | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x108 | RW | — | [LLM] |
| this | 0x110 | RW | 0 | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0x108: [LLM: once/conditional? does external poke survive?]
- this 0x110: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047b3c0 | jpt_47B22B | R | [LLM] |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047b850 | MenuItemLayoutCalculator | [LLM] |
| 0047bae0 | BoundedCounterUpdate | [LLM] |
| 0047bb40 | sub_47BB40 | [LLM] |
| 0047be00 | sub_47BE00 | [LLM] |
| 00498730 | FloatFieldAccessor | [LLM] |
| 00498880 | DualFieldRead | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
