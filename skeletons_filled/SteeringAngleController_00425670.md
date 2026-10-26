## SteeringAngleController_00425670 — AI Steering Angle & State Machine

**Summary:** Computes steering angle error (yaw delta to target) from vehicle position and optional target vehicle position, manages a driver-status state machine (states 0,1,6,7) for AI steering modes, and periodically snapshots position for trajectory recording.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4354) | 0x94 | R | — | target vehicle X position (from opponent/target struct) |
| *(this+0x4354) | 0x9C | R | — | target vehicle Z position (from opponent/target struct) |
| this | 0x34E0 | R | — | vehicle X position (world-space) |
| this | 0x34E4 | R | — | vehicle Y position (world-space) |
| this | 0x34E8 | R | — | vehicle Z position (world-space) |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F8 | R | — | RenderZ [FACT] |
| this | 0x3500 | R | — | direction vector Z component (for atan2 heading calc) |
| this | 0x39FC | R | — | CurrentGear [FACT] (also: gearNumber) |
| this | 0x4354 | R | — | pointer to target vehicle/waypoint struct |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x446C | RW | 0 | steering error accumulator counter (incremented/decremented per-frame based on heading error) |
| this | 0x4470 | RW | — | stored position snapshot X (saved when dbl_8AFEA0 > 0x447C) |
| this | 0x4474 | RW | — | stored position snapshot Y |
| this | 0x4478 | RW | — | stored position snapshot Z |
| this | 0x447C | RW | — | next position-snapshot timestamp (set to dbl_8AFEA0 + 4.0s) |
| this | 0x4510 | RW | 1 | driverStatus [CONFIRMED] |
| this | 0x4558 | R | — | max error-counter threshold (cap before state reset) |

**Written-by note (persistence):**
- this 0x446C: recalc every frame — external poke does NOT persist
- this 0x4470: recalc every frame — external poke does NOT persist
- this 0x4474: recalc every frame — external poke does NOT persist
- this 0x4478: recalc every frame — external poke does NOT persist
- this 0x447C: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e888 | flt_59E888 | R | TwoPi [DERIVED] (also: ` â€” 2Ï€ (360Â° in radians) |
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` â€” yaw error tolerance (radians) |
| 0059e898 | dbl_59E898 | R | CamberAngleLimitDeg [DERIVED] (also: ` = 90.0 (camber angle limit, degrees) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ae00 | AIClearStateFlags | reset AI state flags (called before transitioning to driverStatus=1) |
| 004ef930 | RaceStartCountdownStateUpdate | update race-start countdown (called when gear > 2 and error counter overflows) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x39FC | > | 2 | CurrentGear [FACT] |
| this | 0x4510 | == | 6 | driverStatus [CONFIRMED] |

**Guard interpretation:** When driverStatus==6, the AI uses a target-relative steering mode (computes heading from opponent position). When driverStatus!=6, it falls back to a direction-vector-based steering. The CurrentGear > 2 check gates the race-start countdown update: when the error counter (0x446C) exceeds the max threshold (0x4558) AND gear > 2, the countdown is decremented and driverStatus resets to 1. If gear ≤ 2, this reset is BLOCKED. Additionally, heading error magnitude ≤ 0.5 rad or low speed (≤ 0.5) rapidly decreases the counter toward reset; larger errors increase it.
