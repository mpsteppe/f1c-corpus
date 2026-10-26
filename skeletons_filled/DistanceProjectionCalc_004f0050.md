## DistanceProjectionCalc_004f0050 — DistanceProjectionCalc

**Summary:** Computes projected signed distance along a direction vector between two monitored positions, clamped to TrackRefSpeed range. Part of position tracking system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_41AD80 (0041ad80), PitSelectionStateMachine (0041b3c0), AISteeringRacingLineCorrection (0042b0e0), ShortComputation_bad0 (0049bad0), sub_4BCCC0 (004bccc0), sub_4D1730 (004d1730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34D4 | R | — | Position offset X (subtracted from monitor origin) |
| this | 0x34D8 | R | — | Position offset Y |
| this | 0x34DC | R | — | Position offset Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` — waypoint accumulation weight) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e9630 | PositionChangeMonitor | Returns position monitor data with waypoint pointers and stored distance |

**Guard conditions:** Checks if direction vector between two monitored positions is zero. PASSES (computes projection) when nonzero. If zero, returns stored distance value directly. Also clamps result: if negative, offset by TrackRefSpeed with floor at 0.0; if > TrackRefSpeed, wraps with ceiling at TrackRefSpeed.
