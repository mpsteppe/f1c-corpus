## WheelForceAggregation_004f1120 — WheelForceAggregation

**Summary:** Aggregates wheel forces across all 4 wheels by surface type with speed-clamped weighting, computing normalized direction for PerIndexStructFieldSetter. Part of wheel force/tire physics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleSoundTrigger (004f12e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x3668)+0x54) | 0x30 | R | — | Force parameter within contact struct |
| *(this+0x3668) | 0x54 | R | — | Contact surface type/data field within wheel struct |
| this | 0x3668 | R | — | Wheel array base pointer (4 wheels, 62 floats per entry) |

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
| 004f8850 | PerIndexStructFieldSetter | Stores aggregated wheel force data (normalized direction + intensity) to indexed struct field |

**Guard conditions:** Iterates 4 wheels; PASSES (processes wheel) if wheel pointer is valid AND wheel's surface type (*(wheel+84)+48) matches a2. Speed parameter a3 clamped to 32.0 max. After loop, if max force (v15) > 0.001, normalizes and calls PerIndexStructFieldSetter; otherwise skips output.
