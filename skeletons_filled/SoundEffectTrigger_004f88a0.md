## SoundEffectTrigger_004f88a0 — randomized sound/HUD intensity trigger

**Summary:** Computes a clamped ratio of two sub-struct floats, combines with noise table values and random number to produce two intensity parameters, then configures an indexed HUD element. Used for randomized sound/feedback effects.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PositionLapStateUpdate (00447e00), RaceStartCountdownStateUpdate (004ef930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x39A0 | R | — | numerator for clamped ratio (engine/vehicle parameter) |
| obj | 0x39A4 | R | — | denominator for clamped ratio |
| this | 0x0 | R | — | pointer to sub-struct holding ratio fields and extra data |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
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

**Guard conditions:** Input ratio (obj 0x39A0 / obj 0x39A4) clamped to [0, 1] — negative results set to 0, values > 1 set to 1.
