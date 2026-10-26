## RandomVariationScaler_004bea10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EngineFailureCheck (004bec55), AIBehaviorInitialization (004bf0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x360 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 005acdb4 | flt_5ACDB4 | R | Unknown_Float_FFB [DERIVED] (also: constant scaler (docs/12) |
| 005acdd0 | dbl_5ACDD0 | R | Double5ACDD0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005881f0 | sub_5881F0 | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x360 | == | 7 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
