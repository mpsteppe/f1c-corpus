## BrakeThermalModel_004e87e0 — brake thermal factor computation

**Summary:** Computes normalized brake thermal factor from squared suspension displacement divided by heat capacity, clamped to [0,1]. Part of brake thermal simulation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIRacingLine (00425920), AISteeringCorrection (00426cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] — rotation matrix Z-row X-column |
| this | 0x34C4 | R | — | rotation matrix Z-row Y-column |
| this | 0x34D0 | R | — | rotation matrix Z-row Z-column |
| this | 0x3500 | R | — | world-space position Z of wheel hub |
| this | 0x39A8 | R | — | current brake thermal offset numerator (subtracted from energy term) |
| this | 0x39AC | R | — | max brake thermal range denominator |
| this | 0x39C8 | R | — | thermal capacity divisor (heat capacity or reference energy) |
| this | 0x3A58 | R | — | suspension contact anchor point X in local frame |
| this | 0x3A5C | R | — | suspension contact anchor point Y in local frame |
| this | 0x3A60 | R | — | suspension contact anchor point Z in local frame |
| this | 0x3D40 | R | — | brake thermal stiffness/conversion factor 1 |
| this | 0x3D44 | R | — | brake thermal stiffness/conversion factor 2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[3698] (0x39C8) == 0.0 → BLOCKED (return 0, avoid div-by-zero). this[3691] (0x39AC) == 0.0 → BLOCKED (return 0, avoid div-by-zero). PASSES: both non-zero, compute thermal factor and clamp [0,1].
