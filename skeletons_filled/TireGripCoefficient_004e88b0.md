## TireGripCoefficient_004e88b0 — tire grip coefficient with anti-roll cross-coupling

**Summary:** Computes per-corner tire grip coefficients with anti-roll bar cross-coupling term, selects min/max across axles based on mode selector, and clamps result to [0,1]. Part of tire dynamics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIRacingLine (00425920), AISteeringCorrection (00426cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x35CC | R | — | tire corner 0 (FL) grip base coefficient |
| this | 0x3610 | R | — | tire corner 0 (FL) camber/multiplier factor |
| this | 0x3618 | R | — | tire corner 0 (FL) weight distribution factor |
| this | 0x36C4 | R | — | tire corner 1 (FR) grip base coefficient |
| this | 0x3708 | R | — | tire corner 1 (FR) camber/multiplier factor |
| this | 0x3710 | R | — | tire corner 1 (FR) weight distribution factor |
| this | 0x37BC | R | — | tire corner 2 (RL) grip base coefficient |
| this | 0x3800 | R | — | tire corner 2 (RL) camber/multiplier factor |
| this | 0x3808 | R | — | tire corner 2 (RL) weight distribution factor |
| this | 0x38B4 | R | — | tire corner 3 (RR) grip base coefficient |
| this | 0x38F8 | R | — | tire corner 3 (RR) camber/multiplier factor |
| this | 0x3900 | R | — | tire corner 3 (RR) weight distribution factor |
| this | 0x39A8 | R | — | anti-roll bar coupling coefficient (multiplied with 0x39C8) |
| this | 0x39B4 | R | — | computation mode selector (0=axle-pair avg, 1=all-four, 2=individual) |
| this | 0x39C8 | R | — | anti-roll bar cross-coupling reference (paired with 0x39A8) |

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

**Guard conditions:** Mode selector at 0x39B4 (14772) determines branch — NOT a guard. No early-return or block conditions. Result always clamped [0,1] at end.
