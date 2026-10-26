## CollisionPositionStepper_0048cb00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_48D0A0 (0048d0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x328 | R | — | [LLM] |
| this | 0x32C | R | — | [LLM] |
| this | 0x334 | RW | — | [LLM] |
| this | 0x338 | R | — | [LLM] |
| this | 0x33C | R | — | [LLM] |
| this | 0x340 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x334: [LLM: once/conditional? does external poke survive?]
- this 0x340: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac108 | flt_5AC108 | R | TexDecompress_1_15th [DERIVED] (also: ` — 4-bit color scale factor (1/15 ≈ 0.0667) |
| 005ac10c | flt_5AC10C | R | AudioPanningStep [DERIVED] |
| 005ac110 | flt_5AC110 | R | TrackMapScrollSpeed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
