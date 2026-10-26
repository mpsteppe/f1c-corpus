## RandomWeightedTierSelection_00429fd0 — RandomWeightedTierSelection

**Summary:** Selects tire compound tier based on track grip level (flt_8AFEE8). Uses tier thresholds with randomized boundaries for variety at mid ranges. Falls back to this[0x458C] (nextChosenTires) at very low grip. Maps chosen tier to a compound index via CompoundIndexLookup and TireCompoundNameIDMapping.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70), sub_429960 (00429960), AISteeringRacingLineCorrection (0042b0e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3978 | R | — | unknown — not directly used in grip-based selection path |
| this | 0x3988 | R | — | unknown — not directly used in grip-based selection path |
| this | 0x458C | R | — | nextChosenTires [CONFIRMED] — fallback tier at very low grip (< 0.15) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold) |
| 0059e908 | flt_59E908 | R | CollisionEventThreshold [DERIVED] (also: ` — collision time threshold) |
| 0059e970 | flt_59E970 | R | TrackLayoutConstant [DERIVED] |
| 005ea438 | byte_5EA438 | R | default fallback string when compound name pointer is null |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] — current track grip level (0.0-1.0) used for compound selection |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a4830 | TireCompoundNameIDMapping | maps compound name string to tier ID (returns integer tier) |
| 004d7570 | CompoundIndexLookup | returns compound name/data for a given index |
| 005884ed | RandLCGRandomNumberGenerator | LCG PRNG for randomized tier selection at grip boundaries |

**Guard conditions:** BLOCKED (always executes — no early return). Grip thresholds branch deterministically: < 0.15 uses stored nextChosenTires; 0.15-0.2 uses random chance; 0.2-0.5 = tier 4; 0.5-0.55 = tier 4-5 random; 0.55-0.8 = tier 5; 0.8-0.85 = tier 5-6 random; >= 0.85 = tier 6.
