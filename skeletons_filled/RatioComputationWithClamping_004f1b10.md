## RatioComputationWithClamping_004f1b10 — normalized absolute ratio clamp

**Summary:** Computes absolute ratio of two float fields, clamps result to [0.0, 1.0]. Used by sound effect triggering for normalized intensity calculation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SoundEffectTrigger (004f88a0), SoundEffectTrigger_89a0 (004f89a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3964 | R | — | numerator value for ratio |
| this | 0x3968 | R | — | denominator value for ratio |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always computes abs(numerator/denominator) and clamps. Dead-code check `result < 0.0` after fabs never triggers.
