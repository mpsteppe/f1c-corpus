## WheelForceAggregation_004f1120 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleSoundTrigger (004f12e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x3668)+0x54) | 0x30 | R | — | [LLM] |
| *(this+0x3668) | 0x54 | R | — | [LLM] |
| this | 0x3668 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059ec20 | flt_59EC20 | R | ForceClampMax [DERIVED] |
| 005ac988 | flt_5AC988 | R | UVCoordScaleFactor [DERIVED] (also: ` — UV coordinate scale factor) |
| 005ad234 | flt_5AD234 | R | ForceScaleFactor [DERIVED] (also: ` — force scale) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f8850 | PerIndexStructFieldSetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
