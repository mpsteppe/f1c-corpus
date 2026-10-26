## RaceStartCountdownStateUpdate_004ef930 — RaceStartCountdownStateUpdate

**Summary:** Manages race start countdown sequence — advances countdown steps, triggers sound effects, records telemetry on green light, and manages timer state. Part of race start system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70), SteeringAngleController (00425670), PhysicsGearShiftLogicWithThresholds (00426330), PitStopReadyCheck (004a6200), TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3578 | R | — | Speed threshold for telemetry recording during countdown |
| this | 0x3978 | R | — | Engine state/speed threshold |
| this | 0x3994 | R | — | Throttle position |
| this | 0x3998 | R | — | Throttle comparison threshold |
| this | 0x399C | R | — | Alternate countdown step interval |
| this | 0x39EC | RW | 1 | Countdown in-progress flag (cleared each frame) |
| this | 0x39EE | R | — | Initial countdown block flag (nonzero blocks all) |
| this | 0x39F0 | RW | 0 | Countdown step index (current step being processed) |
| this | 0x39FC | R | — | CurrentGear [FACT] (also: gearNumber) |
| this | 0x3A00 | R | — | Countdown step interval timer value |
| this | 0x3A04 | RW | 0 | Countdown timer (counts down; <=0 triggers next step) |
| this | 0x3A08 | RW | 1 | Countdown state/phase |

**Written-by note (persistence):**
- this 0x39EC: recalc every frame — external poke does NOT persist
- this 0x39F0: recalc every frame — external poke does NOT persist
- this 0x3A04: recalc every frame — external poke does NOT persist
- this 0x3A08: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ef4f0 | PositionUpdateWithTelemetryRecording | Records telemetry snapshot during green-light countdown step |
| 004f88a0 | SoundEffectTrigger | Triggers countdown-step sound effect (final/start) |
| 004f89a0 | SoundEffectTrigger_89a0 | Triggers countdown-step sound effect (intermediate) |

**Guard conditions:** Checks initial block flag (this+0x39EE): if nonzero, returns immediately (BLOCKED). Then checks a2==0: resets state and returns (no countdown). Then checks countdown timer (this+0x3A04) > 0.0: BLOCKED (timer still running). When timer <= 0.0, processes next countdown step based on a2 vs step index (this+0x39F0).
