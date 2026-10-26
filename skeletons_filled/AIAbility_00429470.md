## AIAbility_00429470 — DriverAIAbilityTick

**Summary:** Per-frame AI ability update for a driver — manages AI difficulty scaling, pit stop decisions, fuel checks, and corner-exit behavior based on session type and race phase.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4354) | 0x34 | R | — | upper limit value from vehicle setup data |
| *(this+0x4354) | 0x38 | R | — | lower limit value from vehicle setup data |
| obj | 0xCD4 | R | — | postProcessInput field pointer in vtable (checked for non-null) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x34F8 | RW | — | RenderZ [FACT] |
| this | 0x34FC | RW | — | velocity / acceleration Y component |
| this | 0x3500 | RW | — | velocity / acceleration Z component |
| this | 0x3984 | R | — | speed magnitude threshold (checked > 0.001) |
| this | 0x3988 | R | — | elapsed time counter (compared against pit delay threshold) |
| this | 0x39FA | R | — | pit stop eligibility flag (byte, nonzero = eligible) |
| this | 0x3D6C | R | — | carConditions [CONFIRMED] |
| this | 0x4000 | R | — | pit decision delay counter (checked <= 0 for entry eligibility) |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4040 | R | — | lap completion status (2 = completed, -1 = unknown; used for final-lap check) |
| this | 0x4044 | R | — | ring buffer input read index (for AI engagement mode selection) |
| this | 0x4064 | R | — | FinishState [FACT] |
| this | 0x4068 | RW | 6 | ReasonCode [FACT] |
| this | 0x4354 | R | — | pointer to vehicle setup / physics limits data struct |
| this | 0x43F8 | RW | — | pit exit delay counter (zeroed during post-pit cleanup) |
| this | 0x4420 | RW | — | steering / directional target value (computed from setup limits) |
| this | 0x4424 | RW | — | accumulated timer value (zeroed after pit stop) |
| this | 0x4428 | R | — | half-extent width value (compared against setup limits for bound clamping) |
| this | 0x4434 | RW | — | post-pit state reset flag (zeroed after pit cleanup) |
| this | 0x4438 | RW | — | post-pit multiplier / scaling factor (reset to 1.0) |
| this | 0x443C | RW | — | pit timer reset value (zeroed after pit exit) |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x44B0 | RW | — | NAN sentinel value for invalidation (set to NAN at end of tick) |
| this | 0x44D4 | R | — | AI probability threshold (used in random chance override calculation) |
| this | 0x44D8 | R | — | AI upper bound value (used for clamping adjustments) |
| this | 0x44F4 | R | — | AI lower bound / base value (used for clamping adjustments) |
| this | 0x4508 | RW | — | AI temporary flag A (zeroed after use in session-type-7 branch) |
| this | 0x450C | RW | — | AI temporary flag B (zeroed after use in session-type-7 branch) |
| this | 0x4510 | RW | 5 | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | — | pit exit delay timer (zeroed during post-pit cleanup) |
| this | 0x4534 | RW | — | timeOfNextExit [CONFIRMED] |
| this | 0x453C | RW | — | continuously adjusted AI ability value (±0.01 per frame, probability overrides) |
| this | 0x4544 | RW | 1 | AI active / inhibit master flag (1 = active, 0 = inhibited) |
| this | 0x4548 | RW | 1 | post-pit service completed flag (set to 1 during pit service) |
| this | 0x454C | RW | — | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 1 | pit exit fully completed flag (set after all cleanup) |
| this | 0x4579 | RW | 0 | pit lane entry active flag (byte, cleared on entry or non-race session) |
| this | 0x457C | RW | — | additional lane / state flag (byte, cleared conditionally) |
| this | 0x45E0 | R | — | pit stop delay table index (used to look up delay value for tire compound) |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x45F8 | R | — | pointer to other vehicle object (for fuel weight cross-check) |

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
| 00424750 | AIDifficultyScalar | returns AI difficulty multiplier (0.0–1.0) scaled by difficulty setting |
| 00426430 | sub_426430 | post-pit state reset helper — reinitializes AI state after pit exit |
| 00429eb0 | RacePhasePitEntryTrigger | evaluates whether the car should enter pit lane based on race phase |
| 0042a110 | ForcePitExit | forces the car to immediately exit the pit lane |
| 0042a3d0 | PitStopDecisionTireCompound | selects tire compound and computes pit stop duration |
| 0042a6f0 | PostPitCleanup | resets driver state fields after pit stop completion |
| 0042acd0 | ParameterValueSetter | sets a global parameter (18 = pit-related event flag) |
| 0042ad20 | FuelMultiplierValue | returns fuel consumption multiplier for a vehicle |
| 0042ad50 | FuelWeightLimitCheck | checks whether fuel weight exceeds the allowable limit |
| 0042ae00 | AIClearStateFlags | clears temporary AI state flags after pit stop |
| 004d1cf0 | RingBufferAccessWithWrap | reads a ring buffer entry with wrap-around indexing |
| 004efac0 | ConditionalGate | conditional flow gate — blocks or passes based on state |
| 004f1890 | SpeedValueSetterWithGlobalMirror | sets a speed value and mirrors it to a global location |
| 005884ed | RandLCGRandomNumberGenerator | linear congruential generator for random numbers |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4064 | == | 1 | FinishState [FACT] == finished |

**Guard interpretation:** When FinishState == 1 (car has finished the race), the entire early-return branch at offset 0x4064 triggers — car is in finished state so most AI logic (difficulty, pit stops) is skipped; only post-processing like pit entry trigger still runs.
