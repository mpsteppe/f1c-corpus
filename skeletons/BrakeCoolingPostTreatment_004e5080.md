## BrakeCoolingPostTreatment_004e5080 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionSpringDampingRateReset (004e4f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34A8 | R | — | [LLM] |
| this | 0x3570 | RW | 0 | [LLM] |
| this | 0x35B0 | R | — | [LLM] |
| this | 0x36A8 | R | — | [LLM] |
| this | 0x37A0 | R | — | [LLM] |
| this | 0x3898 | R | — | [LLM] |
| this | 0x3990 | R | — | fuelConsumptionFactor [CONFIRMED] |
| this | 0x3994 | R | — | [LLM] |
| this | 0x39B4 | R | — | [LLM] |
| this | 0x39EC | R | — | [LLM] |
| this | 0x39F0 | RW | — | [LLM] |
| this | 0x3A04 | RW | — | [LLM] |
| this | 0x3A08 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x3570: recalc every frame — external poke does NOT persist
- this 0x39F0: recalc every frame — external poke does NOT persist
- this 0x3A04: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3A08 | == | 18446744073709551615 | [LLM] |
| this | 0x3A08 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
