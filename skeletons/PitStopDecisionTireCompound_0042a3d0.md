## PitStopDecisionTireCompound_0042a3d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470), PitStopReadyCheck (004a6200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xCD4 | R | — | [LLM] |
| obj | 0xD14 | R | — | [LLM] |
| obj | 0xD18 | R | — | [LLM] |
| obj | 0xD58 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x3378 | R | — | nextChosenTires (rw) [CONFIRMED] |
| this | 0x3988 | R | — | [LLM] |
| this | 0x39FA | R | — | [LLM] |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4410 | RW | 1 | RetiredFlag [FACT] |
| this | 0x4534 | RW | — | timeOfNextExit [CONFIRMED] |
| this | 0x4548 | RW | 1 | [LLM] |
| this | 0x4584 | RW | 0 | [LLM] |
| this | 0x4588 | R | — | [LLM] |
| this | 0x458C | R | — | nextChosenTires [CONFIRMED] |
| this | 0x45E0 | R | — | [LLM] |
| this | 0x45E8 | R | — | [LLM] |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x4600 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x4410: recalc every frame — external poke does NOT persist
- this 0x4534: recalc every frame — external poke does NOT persist
- this 0x4548: recalc every frame — external poke does NOT persist
- this 0x4584: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e808 | flt_59E808 | R | EngineTempThreshold [DERIVED] |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e974 | flt_59E974 | R | AI_TrackPosThreshold [DERIVED] |
| 0059e978 | flt_59E978 | R | Flt_AiGearShiftThreshold_9E978 [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042a6f0 | PostPitCleanup | [LLM] |
| 0042aee0 | PitStopBlockingCondition | [LLM] |
| 004a56b0 | StateTransition | [LLM] |
| 004a5750 | UtilityFunction_5750 | [LLM] |
| 004a57a0 | IndexDecrementWithBoundsWrap | [LLM] |
| 004a5bd0 | ClampedIndexAssignment | [LLM] |
| 004bc060 | sub_4BC060 | [LLM] |
| 004c6d90 | SceneRenderUpdate | [LLM] |
| 004efac0 | ConditionalGate | [LLM] |
| 004f1890 | SpeedValueSetterWithGlobalMirror | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
