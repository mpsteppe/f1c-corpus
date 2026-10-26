## PitStopProgress_004a68b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStateUpdateMachine (004a6e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1054 | R | — | [LLM] |
| obj | 0x105C | RW | 1 | [LLM] |
| obj | 0x32C8 | R | — | [LLM] |
| obj | 0x4064 | R | — | [LLM] |
| obj | 0x4068 | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x1A0 | R | — | [LLM] |
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1A8 | RW | — | [LLM] |
| this | 0x1AC | RW | 0 | [LLM] |
| this | 0x1B0 | R | — | [LLM] |
| this | 0x1B4 | R | — | [LLM] |
| this | 0x1B8 | R | — | [LLM] |
| this | 0x1C0 | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1D0 | R | — | [LLM] |
| this | 0x1D4 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x105C: recalc every frame — external poke does NOT persist
- obj 0x4068: recalc every frame — external poke does NOT persist
- this 0x1A8: recalc every frame — external poke does NOT persist
- this 0x1AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e96c | flt_59E96C | R | DamageInterpFactor [DERIVED] |
| 005acb60 | flt_5ACB60 | R | PitRepairThreshold [DERIVED] |
| 005acb64 | flt_5ACB64 | R | BrakeBias_Rate [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` â€” detail level (â‰¤1 = load pitcrew meshes) |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d410 | ShortComputation_d410 | [LLM] |
| 00424cd0 | AICommandMessageQueueDispatcher | [LLM] |
| 0042a6f0 | PostPitCleanup | [LLM] |
| 004a34a0 | PerElementConditionalActionDispatcher | [LLM] |
| 004a5c80 | StateChangeNotify | [LLM] |
| 004d8760 | sub_4D8760 | [LLM] |
| 004f1890 | SpeedValueSetterWithGlobalMirror | [LLM] |
| 004f1b50 | CameraModeSetter | [LLM] |
| 004f1ba0 | WheelForceParameterSet | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | == | 1 | [LLM] |
| obj | 0x4064 | != | 1 | [LLM] |
| obj | 0x4068 | == | 9 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
