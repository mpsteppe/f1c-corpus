## VibrationStateMachine_004e2230 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0), SubslotCleanup (004e0e70), sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB6C | R | — | [LLM] |

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
| 005506a0 | sub_5506A0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
