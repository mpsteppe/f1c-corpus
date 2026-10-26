## UIScrollListUpdate_0048a8d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | [LLM] |
| obj | 0x24 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x145 | R | — | [LLM] |
| this | 0x146 | R | — | [LLM] |
| this | 0x148 | RW | — | [LLM] |
| this | 0x150 | RW | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x148: [LLM: once/conditional? does external poke survive?]
- this 0x150: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489500 | DecrementCounterVirtualCall | [LLM] |
| 00489530 | UINavigationAdvanceHandler | [LLM] |
| 00489ee0 | ShortComputation_9ee0 | [LLM] |
| 00498880 | DualFieldRead | [LLM] |
| 00498940 | FunctionCallWrapper_8940 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x160 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
