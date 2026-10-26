## VehicleSoundTrigger_004f12e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x3668)+0x54) | 0x30 | R | — | [LLM] |
| *(*(this+0x3668)+0x54) | 0x34 | R | — | [LLM] |
| *(this+0x3668) | 0x54 | R | — | [LLM] |
| this | 0x5FC | RW | 0 | [LLM] |
| this | 0x7A4 | R | — | [LLM] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x34EC | R | — | [LLM] |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |
| this | 0x3668 | R | — | [LLM] |
| this | 0x39B8 | R | — | [LLM] |
| this | 0x39C4 | R | — | [LLM] |
| this | 0x3A58 | R | — | [LLM] |
| this | 0x3A5C | R | — | [LLM] |
| this | 0x3A60 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x5FC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 005ac988 | flt_5AC988 | R | UVCoordScaleFactor [DERIVED] (also: ` — UV coordinate scale factor) |
| 005ad238 | flt_5AD238 | R | WeightTransferMultiplier [DERIVED] |
| 007c9138 | dbl_7C9138 | R | FuelConsumptionMult [DERIVED] |
| 007c9150 | dbl_7C9150 | R | Unknown_Double_Damage [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f0f40 | WheelContactForceAggregation | [LLM] |
| 004f1120 | WheelForceAggregation | [LLM] |
| 004f87c0 | HUDElementConfig | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
