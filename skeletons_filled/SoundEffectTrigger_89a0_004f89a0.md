## SoundEffectTrigger_89a0_004f89a0 — randomized sound/HUD trigger (variant 2, higher indices)

**Summary:** Variant of SoundEffectTrigger that computes intensity via ratio and noise, then configures HUD element with base indices 15-17 (vs 12-14 in the other variant). Same noise/random jitter pattern.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PositionLapStateUpdate (00447e00), RaceStartCountdownStateUpdate (004ef930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to sub-struct passed to RatioComputationWithClamping |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 0059e908 | flt_59E908 | R | CollisionEventThreshold [DERIVED] (also: ` — collision time threshold) |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: random noise table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f1b10 | RatioComputationWithClamping | computes absolute ratio clamped to [0,1] |
| 004f87c0 | HUDElementConfig | writes gain/magnitude to indexed HUD element |
| 005884ed | RandLCGRandomNumberGenerator | generates 15-bit LCG random number |

**Guard conditions:** Ratio clamped via RatioComputationWithClamping. Random index selection: rand < 10922 → 17, 10922 <= rand < 21844 → 16, rand >= 21844 → 15.
