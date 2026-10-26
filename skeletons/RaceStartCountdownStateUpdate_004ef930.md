## RaceStartCountdownStateUpdate_004ef930 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70), SteeringAngleController (00425670), PhysicsGearShiftLogicWithThresholds (00426330), PitStopReadyCheck (004a6200), TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3578 | R | — | [LLM] |
| this | 0x3978 | R | — | [LLM] |
| this | 0x3994 | R | — | [LLM] |
| this | 0x3998 | R | — | [LLM] |
| this | 0x39EC | RW | 1 | [LLM] |
| this | 0x39EE | R | — | [LLM] |
| this | 0x39F0 | RW | 0 | [LLM] |
| this | 0x39FC | R | — | CurrentGear [FACT] (also: gearNumber) |
| this | 0x3A00 | R | — | [LLM] |
| this | 0x3A04 | RW | 0 | [LLM] |
| this | 0x3A08 | RW | 1 | [LLM] |

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
| 004ef4f0 | PositionUpdateWithTelemetryRecording | [LLM] |
| 004f88a0 | SoundEffectTrigger | [LLM] |
| 004f89a0 | SoundEffectTrigger_89a0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
