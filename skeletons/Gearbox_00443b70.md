## Gearbox_00443b70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x80 | R | — | [LLM] |
| this | 0x170 | RW | — | [LLM] |
| this | 0x19C | R | — | [LLM] |
| this | 0x348 | R | — | [LLM] |
| this | 0x498 | R | — | [LLM] |
| this | 0x7AC | R | — | [LLM] |
| this | 0x8FC | R | — | [LLM] |
| this | 0xC10 | R | — | [LLM] |
| this | 0xD60 | R | — | [LLM] |
| this | 0x1074 | R | — | [LLM] |
| this | 0x11C4 | R | — | [LLM] |
| this | 0x1C58 | R | — | [LLM] |
| this | 0x1C5C | RW | — | [LLM] |
| this | 0x1C60 | RW | — | [LLM] |
| this | 0x1C7C | R | — | [LLM] |
| this | 0x1C84 | R | — | [LLM] |
| this | 0x1C88 | R | — | [LLM] |
| this | 0x1C8C | R | — | [LLM] |
| this | 0x1CDC | R | — | [LLM] |
| this | 0x1CE4 | R | — | [LLM] |
| this | 0x1CEC | R | — | [LLM] |
| this | 0x1D10 | RW | — | [LLM] |
| this | 0x1D28 | R | — | [LLM] |
| this | 0x1DAC | R | — | [LLM] |
| this | 0x1E14 | R | — | [LLM] |
| this | 0x1E38 | R | — | [LLM] |
| this | 0x1E78 | R | — | [LLM] |
| this | 0x1E7C | RW | — | [LLM] |
| this | 0x1E8C | R | — | [LLM] |
| this | 0x1E9C | R | — | [LLM] |
| this | 0x1EF0 | RW | — | [LLM] |
| this | 0x1EF4 | R | — | [LLM] |
| this | 0x1EF8 | RW | 0 | [LLM] |
| this | 0x1F00 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x170: recalc every frame — external poke does NOT persist
- this 0x1C5C: recalc every frame — external poke does NOT persist
- this 0x1C60: recalc every frame — external poke does NOT persist
- this 0x1D10: recalc every frame — external poke does NOT persist
- this 0x1E7C: recalc every frame — external poke does NOT persist
- this 0x1EF0: recalc every frame — external poke does NOT persist
- this 0x1EF8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059ec10 | dbl_59EC10 | R | DoublePhysicsZero [DERIVED] |
| 0059ed10 | dbl_59ED10 | R | TimeStepScale [DERIVED] (also: time-step scaling factor) |
| 0059ed98 | dbl_59ED98 | R | Dbl_Physics_TimingThreshold [DERIVED] |
| 0059edb0 | dbl_59EDB0 | R | DifferentialLockThreshold [DERIVED] |
| 0059edb8 | dbl_59EDB8 | R | ShiftPointFactor [DERIVED] |
| 0059edc0 | dbl_59EDC0 | R | DampingLerpCoeff [DERIVED] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cc6e0 | dword_7CC6E0 | R | TireSlipConstant [DERIVED] |
| 007cc6e4 | dword_7CC6E4 | R | ContactForceThreshold [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008acfb4 | flt_8ACFB4 | R | IdleSpeedTarget [DERIVED] (also: ` â€” idle/reverse speed target) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00447160 | VehicleActive | [LLM] |
| 004471f0 | SuspensionVibration | [LLM] |
| 00447b10 | RandomPhysicsParameterGenerator | [LLM] |
| 00447e00 | PositionLapStateUpdate | [LLM] |
| 004ef4f0 | PositionUpdateWithTelemetryRecording | [LLM] |
| 004f87c0 | HUDElementConfig | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1EF8 | < | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
