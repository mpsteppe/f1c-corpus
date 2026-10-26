## FloatStoreWithConversion_00464a60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5430 (00465430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x220 | RW | — | [LLM] |
| this | 0x22A | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x220: [LLM: once/conditional? does external poke survive?]
- this 0x22A: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059e940 | flt_59E940 | R | Flt_PhysicsLimit_9E940 [DERIVED] |
| 0059ec20 | flt_59EC20 | R | ForceClampMax [DERIVED] |
| 0059eed0 | flt_59EED0 | R | BrightnessMultiplierRB [DERIVED] (also: ` — brightness multiplier for R/B channels) |
| 0059f138 | flt_59F138 | R | RadToDegFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
