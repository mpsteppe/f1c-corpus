## sub_4F1FE0_004f1fe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3450 | R | — | [LLM] |
| obj | 0x4064 | R | — | [LLM] |
| obj | 0x4170 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x828 | R | — | [LLM] |
| this | 0x868 | R | — | [LLM] |
| this | 0x1048 | R | — | [LLM] |
| this | 0x1051 | RW | 0 | [LLM] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x34D4 | R | — | [LLM] |
| this | 0x34D8 | R | — | [LLM] |
| this | 0x34DC | R | — | [LLM] |
| this | 0x3994 | R | — | [LLM] |
| this | 0x3A9C | RW | — | [LLM] |
| this | 0x3D48 | RW | 0 | [LLM] |
| this | 0x3D4C | RW | 0 | [LLM] |
| this | 0x3D50 | RW | 0 | [LLM] |
| this | 0x3D60 | RW | — | [LLM] |
| this | 0x3FF8 | RW | — | [LLM] |
| this | 0x3FFC | RW | — | [LLM] |
| this | 0x4000 | RW | — | [LLM] |
| this | 0x4004 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x1051: recalc every frame — external poke does NOT persist
- this 0x3A9C: recalc every frame — external poke does NOT persist
- this 0x3D48: recalc every frame — external poke does NOT persist
- this 0x3D4C: recalc every frame — external poke does NOT persist
- this 0x3D50: recalc every frame — external poke does NOT persist
- this 0x3D60: recalc every frame — external poke does NOT persist
- this 0x3FF8: recalc every frame — external poke does NOT persist
- this 0x3FFC: recalc every frame — external poke does NOT persist
- this 0x4000: recalc every frame — external poke does NOT persist
- this 0x4004: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |
| 0059eae0 | flt_59EAE0 | R | FLT_MAX_Infinity [DERIVED] (also: ` — infinity/FLT_MAX return value) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce258 | dword_7CE258 | W | InitZeroFieldSet [DERIVED] |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] |
| 007d0a8c | flt_7D0A8C | R | PitTimerFloat [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403640 | sub_403640 | [LLM] |
| 0041b250 | sub_41B250 | [LLM] |
| 004a5c80 | StateChangeNotify | [LLM] |
| 004bc060 | sub_4BC060 | [LLM] |
| 004d1140 | RenderCallWithGuard | [LLM] |
| 004d21d0 | sub_4D21D0 | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |
| 004ef7c0 | AIVehiclePathPositionTracking | [LLM] |
| 004effd0 | DistanceComparison | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3450 | != | 3 | [LLM] |
| this | 0x32BC | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
