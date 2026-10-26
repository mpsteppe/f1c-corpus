## WheelTireForceUpdate_004ed810 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8CC | RW | — | [LLM] |
| this | 0x3500 | R | — | [LLM] |
| this | 0x35B0 | R | — | [LLM] |
| this | 0x35D8 | R | — | [LLM] |
| this | 0x35DC | RW | — | [LLM] |
| this | 0x36A8 | R | — | [LLM] |
| this | 0x36D0 | R | — | [LLM] |
| this | 0x36D4 | RW | — | [LLM] |
| this | 0x37A0 | R | — | [LLM] |
| this | 0x37C8 | R | — | [LLM] |
| this | 0x37CC | RW | — | [LLM] |
| this | 0x3898 | R | — | [LLM] |
| this | 0x38C0 | R | — | [LLM] |
| this | 0x38C4 | RW | — | [LLM] |
| this | 0x3A38 | R | — | [LLM] |
| this | 0x3A3C | R | — | [LLM] |
| this | 0x3A40 | R | — | [LLM] |
| this | 0x3A4C | R | — | [LLM] |
| this | 0x3A50 | R | — | [LLM] |
| this | 0x3A54 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8CC: recalc every frame — external poke does NOT persist
- this 0x35DC: recalc every frame — external poke does NOT persist
- this 0x36D4: recalc every frame — external poke does NOT persist
- this 0x37CC: recalc every frame — external poke does NOT persist
- this 0x38C4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059eec0 | dbl_59EEC0 | R | NormalizationScale [DERIVED] |
| 0059eec8 | dbl_59EEC8 | R | NormalizationBias [DERIVED] |
| 005acafc | flt_5ACAFC | R | TemperatureOffset [DERIVED] (also: ` — additive offset) |
| 008afef0 | flt_8AFEF0 | R | TemperatureOffset [CONFIRMED] (also: GlobalForceReference, ` — global force/torque reference) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
