## SteeringForceWithRandom_004f0dd0 — SteeringForceWithRandomNoise

**Summary:** Computes steering force with random sign noise and speed-squared factor, clamped to [-0.3, 0.3], then updates UI timer. Part of steering/force feedback system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1058 | R | — | Force feedback base value |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x34EC | R | — | Force direction X (used for speed magnitude calculation) |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |
| this | 0x3540 | R | — | Half steering value (multiplied by -0.5) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e99c | flt_59E99C | R | PhysicsConversionFactor [DERIVED] (also: ` — conversion factor) |
| 0059f128 | flt_59F128 | R | AeroDownforceCoeff [DERIVED] (also: ` — aero constant) |
| 005acd3c | flt_5ACD3C | R | AeroDragCoefficient [DERIVED] (also: ` — aero constant) |
| 005ad22c | flt_5AD22C | R | ControlClampLower [DERIVED] (also: ` — clamp lower threshold) |
| 007c56ac | byte_7C56AC | R | EnableFlag [DERIVED] (also: ` — enable flag (byte) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e0c90 | UITimerTweenUpdate | Updates UI timer with clamped steering force value |
| 005884ed | RandLCGRandomNumberGenerator | Generates random ±1 sign for steering noise |

**Guard conditions:** Checks enable flag (byte_7C56AC) and scoring gate (dword_8AB6E4==2). PASSES (computes speed-squared factor) when enabled or gate==2. BLOCKED (speed factor = 0) when disabled and gate!=2. Output clamped to [-0.3, 0.3] before UITimerTweenUpdate.
