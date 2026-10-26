## CarCrashDamageProcessing_00496030 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x157C) | 0x4 | R | — | [LLM] |
| *(this+0x157C) | 0xC | R | — | [LLM] |
| this | 0xDC | RW | 0 | [LLM] |
| this | 0x1578 | RW | — | [LLM] |
| this | 0x157C | RW | 0 | [LLM] |
| this | 0x1580 | RW | 800 | [LLM] |
| this | 0x1584 | RW | 18446744073709551016 | [LLM] |
| this | 0x18EC | RW | 0 | [LLM] |
| this | 0x18F0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xDC: [LLM: once/conditional? does external poke survive?]
- this 0x1578: [LLM: once/conditional? does external poke survive?]
- this 0x157C: [LLM: once/conditional? does external poke survive?]
- this 0x1580: [LLM: once/conditional? does external poke survive?]
- this 0x1584: [LLM: once/conditional? does external poke survive?]
- this 0x18EC: [LLM: once/conditional? does external poke survive?]
- this 0x18F0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00496250 | jpt_4960A2 | R | [LLM] |
| 00496264 | jpt_4960C3 | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] (also: ` — scale factors) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495dc0 | sub_495DC0 | [LLM] |
| 00497100 | SceneEntityCleanup | [LLM] |
| 00497250 | ShortComputation_7250 | [LLM] |
| 00498730 | FloatFieldAccessor | [LLM] |
| 00498740 | InitViewportDimensions | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xDC | == | 1008981770 → 0.01f | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
