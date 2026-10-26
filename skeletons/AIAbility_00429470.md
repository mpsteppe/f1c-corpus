## AIAbility_00429470 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4354) | 0x34 | R | — | [LLM] |
| *(this+0x4354) | 0x38 | R | — | [LLM] |
| obj | 0xCD4 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x34F8 | RW | — | RenderZ [FACT] |
| this | 0x34FC | RW | — | [LLM] |
| this | 0x3500 | RW | — | [LLM] |
| this | 0x3984 | R | — | [LLM] |
| this | 0x3988 | R | — | [LLM] |
| this | 0x39FA | R | — | [LLM] |
| this | 0x3D6C | R | — | carConditions [CONFIRMED] |
| this | 0x4000 | R | — | [LLM] |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4040 | R | — | [LLM] |
| this | 0x4044 | R | — | [LLM] |
| this | 0x4064 | R | — | FinishState [FACT] |
| this | 0x4068 | RW | 6 | ReasonCode [FACT] |
| this | 0x4354 | R | — | [LLM] |
| this | 0x43F8 | RW | — | [LLM] |
| this | 0x4420 | RW | — | [LLM] |
| this | 0x4424 | RW | — | [LLM] |
| this | 0x4428 | R | — | [LLM] |
| this | 0x4434 | RW | — | [LLM] |
| this | 0x4438 | RW | — | [LLM] |
| this | 0x443C | RW | — | [LLM] |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x44B0 | RW | — | [LLM] |
| this | 0x44D4 | R | — | [LLM] |
| this | 0x44D8 | R | — | [LLM] |
| this | 0x44F4 | R | — | [LLM] |
| this | 0x4508 | RW | — | [LLM] |
| this | 0x450C | RW | — | [LLM] |
| this | 0x4510 | RW | 5 | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | — | [LLM] |
| this | 0x4534 | RW | — | timeOfNextExit [CONFIRMED] |
| this | 0x453C | RW | — | [LLM] |
| this | 0x4544 | RW | 1 | [LLM] |
| this | 0x4548 | RW | 1 | [LLM] |
| this | 0x454C | RW | — | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 1 | [LLM] |
| this | 0x4579 | RW | 0 | [LLM] |
| this | 0x457C | RW | — | [LLM] |
| this | 0x45E0 | R | — | [LLM] |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x45F8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x4068: recalc every frame — external poke does NOT persist
- this 0x43F8: recalc every frame — external poke does NOT persist
- this 0x4420: recalc every frame — external poke does NOT persist
- this 0x4424: recalc every frame — external poke does NOT persist
- this 0x4434: recalc every frame — external poke does NOT persist
- this 0x4438: recalc every frame — external poke does NOT persist
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x44B0: recalc every frame — external poke does NOT persist
- this 0x4508: recalc every frame — external poke does NOT persist
- this 0x450C: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4524: recalc every frame — external poke does NOT persist
- this 0x4534: recalc every frame — external poke does NOT persist
- this 0x453C: recalc every frame — external poke does NOT persist
- this 0x4544: recalc every frame — external poke does NOT persist
- this 0x4548: recalc every frame — external poke does NOT persist
- this 0x454C: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x4579: recalc every frame — external poke does NOT persist
- this 0x457C: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] (also: ` — scale factors) |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e808 | flt_59E808 | R | EngineTempThreshold [DERIVED] |
| 0059e908 | flt_59E908 | R | CollisionEventThreshold [DERIVED] (also: ` — collision time threshold) |
| 0059e968 | flt_59E968 | R | AIQualifyPushFrequency [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00424750 | AIDifficultyScalar | [LLM] |
| 00426430 | sub_426430 | [LLM] |
| 00429eb0 | RacePhasePitEntryTrigger | [LLM] |
| 0042a110 | ForcePitExit | [LLM] |
| 0042a3d0 | PitStopDecisionTireCompound | [LLM] |
| 0042a6f0 | PostPitCleanup | [LLM] |
| 0042acd0 | ParameterValueSetter | [LLM] |
| 0042ad20 | FuelMultiplierValue | [LLM] |
| 0042ad50 | FuelWeightLimitCheck | [LLM] |
| 0042ae00 | AIClearStateFlags | [LLM] |
| 004d1cf0 | RingBufferAccessWithWrap | [LLM] |
| 004efac0 | ConditionalGate | [LLM] |
| 004f1890 | SpeedValueSetterWithGlobalMirror | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4064 | == | 1 | FinishState [FACT] == finished |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
