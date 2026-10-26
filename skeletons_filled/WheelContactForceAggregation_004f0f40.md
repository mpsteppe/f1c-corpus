## WheelContactForceAggregation_004f0f40 — WheelContactForceAggregation

**Summary:** Aggregates contact forces across all 4 wheels by surface type, computing weighted average direction and sending to PerIndexStructFieldSetter. Part of wheel contact/tire physics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleSoundTrigger (004f12e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x3668)+0x54) | 0x34 | R | — | Contact parameter used for slip/wear weighting |
| *(this+0x3668) | 0x54 | R | — | Contact surface type/data field within wheel contact struct |
| this | 0x32BC | R | — | Rigid body constraint pointer (controls grip factor: 0.86/0.5) |
| this | 0x3668 | R | — | Wheel contact array base pointer (4 wheels, 62 floats per entry) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 0059e9e4 | flt_59E9E4 | R | ForceBiasTerm [DERIVED] |
| 005ac988 | flt_5AC988 | R | UVCoordScaleFactor [DERIVED] (also: ` — UV coordinate scale factor) |
| 005ad230 | flt_5AD230 | R | ContactGripMultiplier [DERIVED] (also: ` — grip/multiplier for contact force) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f8850 | PerIndexStructFieldSetter | Stores aggregated contact force data (normalized direction + intensity) to indexed struct field |

**Guard conditions:** Iterates 4 wheels; PASSES (processes wheel) if wheel pointer is valid AND wheel's surface type (*(wheel+84)+52) matches a2. BLOCKED per wheel if null or wrong surface. After loop, if max contact force (v14) > 0.001, normalizes and calls PerIndexStructFieldSetter; otherwise skips output.
