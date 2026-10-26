## VibrationStateMachine_004e2230 — VibrationStateMachine

**Summary:** State machine for vibration/force feedback — transitions between off (0), low (1), and high (2) states based on |a3| thresholds (16.0 and 64.0). Updates hardware slots and audio slots on state change. Part of input/haptic feedback system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0), SubslotCleanup (004e0e70), sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB6C | R | — | Vibration intensity value passed to hardware update |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e708 | flt_59E708 | R | SoundVolumeLowThreshold [DERIVED] (also: ` — low threshold) |
| 0059eed0 | flt_59EED0 | R | BrightnessMultiplierRB [DERIVED] (also: ` — brightness multiplier for R/B channels) |
| 008ad3ec | dword_8AD3EC | R | SoundEffectArray [DERIVED] |
| 008ad3f8 | unk_8AD3F8 | R | slot table base (stride 14 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005506a0 | sub_5506A0 | Updates vibration/sound effect hardware slot state |

**Guard conditions:** Checks fabs(a3) against thresholds: < 16.0 -> state 0 (off); >= 16.0 and < 64.0 -> state 1 (low); >= 64.0 -> state 2 (high). If this[74*a2+123] equals new state, skips update (no state change). On state change, stores new state, calls sub_5506A0, and iterates sound effect array.
