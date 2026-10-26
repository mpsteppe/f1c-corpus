## SuspensionSpringDampingRateReset_004e4f40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStateMachine (004e4e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x354C | RW | 0 | [LLM] |
| this | 0x3550 | RW | 0 | [LLM] |
| this | 0x3554 | RW | 0 | [LLM] |
| this | 0x3558 | RW | 0 | [LLM] |
| this | 0x355C | RW | 0 | [LLM] |
| this | 0x3560 | RW | 0 | [LLM] |
| this | 0x35E4 | R | — | [LLM] |
| this | 0x35E8 | RW | — | [LLM] |
| this | 0x35EC | RW | — | [LLM] |
| this | 0x36E0 | RW | — | [LLM] |
| this | 0x36E4 | RW | — | [LLM] |
| this | 0x37D4 | R | — | [LLM] |
| this | 0x37D8 | RW | — | [LLM] |
| this | 0x37DC | RW | — | [LLM] |
| this | 0x38D0 | RW | — | [LLM] |
| this | 0x38D4 | RW | — | [LLM] |
| this | 0x3988 | R | — | [LLM] |
| this | 0x39B4 | R | — | [LLM] |
| this | 0x39C8 | RW | 0 | [LLM] |
| this | 0x39F0 | R | — | [LLM] |
| this | 0x39F4 | RW | — | [LLM] |
| this | 0x3A04 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x354C: recalc every frame — external poke does NOT persist
- this 0x3550: recalc every frame — external poke does NOT persist
- this 0x3554: recalc every frame — external poke does NOT persist
- this 0x3558: recalc every frame — external poke does NOT persist
- this 0x355C: recalc every frame — external poke does NOT persist
- this 0x3560: recalc every frame — external poke does NOT persist
- this 0x35E8: recalc every frame — external poke does NOT persist
- this 0x35EC: recalc every frame — external poke does NOT persist
- this 0x36E0: recalc every frame — external poke does NOT persist
- this 0x36E4: recalc every frame — external poke does NOT persist
- this 0x37D8: recalc every frame — external poke does NOT persist
- this 0x37DC: recalc every frame — external poke does NOT persist
- this 0x38D0: recalc every frame — external poke does NOT persist
- this 0x38D4: recalc every frame — external poke does NOT persist
- this 0x39C8: recalc every frame — external poke does NOT persist
- this 0x39F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e5080 | BrakeCoolingPostTreatment | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
