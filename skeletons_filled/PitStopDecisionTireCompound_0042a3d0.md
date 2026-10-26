> **UPDATE 2026-07-24 (prose only, fact table untouched) — THIS FUNCTION
> PERFORMS AI RETIREMENT AT THE PIT BOX.** In the
> `if ( PitStopBlockingCondition(this) || dword_7C56A4 != 7 )` branch it writes
> `*((_BYTE *)this + 17424) = 1` (`veh+0x4410` RetiredFlag) and
> `*((_BYTE *)this + 17908) = 0` (`veh+0x45F4` ActiveFlag) in ONE tick, then
> `sub_4BC060(1)` writes the retirement log entry. `FinishState=2` comes later
> from the scoring pass reading RetiredFlag.
> It tests BOTH wing records for `StateTransition(1)` — front `*this+3284`/`3348`
> (`0xCD4`/`0xD14`) and rear `*this+3352`/`3416` (`0xD18`/`0xD58`) — but
> `PitStopBlockingCondition_0042aee0` tests only the REAR one, which is why a
> front wing is repaired and a rear wing retires.
> Also: placement at restart is decided by FinishState/RetiredFlag, NOT QualPos.
> Evidence: `investigations/part_detach_commentary/README.md`.

## PitStopDecisionTireCompound_0042a3d0 — AI Pit Stop Tire Compound Decision

**Summary:** Per-frame AI logic for selecting tire compounds during pit stops. Checks session type, race phase, remaining laps, and fuel level to schedule tire changes; also handles retired/active state flags and pit stop cleanup.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470), PitStopReadyCheck (004a6200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xCD4 | R | — | postProcessInput valid flag (non-zero = has valid input) |
| obj | 0xD14 | R | — | inputProcessed gate (byte, blocks re-entry into PostPitCleanup path) |
| obj | 0xD18 | R | — | pitDataReady flag (non-zero = pit-related data available) |
| obj | 0xD58 | R | — | sessionActiveOrQualifying gate (byte, 0 = allow early pit gate logic) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x3378 | R | — | nextChosenTires (rw) [CONFIRMED] |
| this | 0x3988 | R | — | fuelLoadOrTireWearCap (float, upper bound for compound scoring) |
| this | 0x39FA | R | — | retirementPending flag (byte, non-zero = retirement/session exit trigger) |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4410 | RW | 1 | RetiredFlag [FACT] |
| this | 0x4534 | RW | — | timeOfNextExit [CONFIRMED] |
| this | 0x4548 | RW | 1 | pitStrategyActive flag (byte, set to 1 at function entry) |
| this | 0x4584 | RW | 0 | pitStopReady flag (byte, 0=not ready, 1=pit can proceed) |
| this | 0x4588 | R | — | totalPitStops count (DWORD, max number of planned pit stops) |
| this | 0x458C | R | — | nextChosenTires [CONFIRMED] |
| this | 0x45E0 | R | — | currentPitStopIndex (DWORD, which pit stop we're on) |
| this | 0x45E8 | R | — | compoundScoreMultiplier (float, scales tire compound decision weight) |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x4600 | R | — | tireCompoundPreference array (7 ints, index = compound slot, value = desired compound) |

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
| 0042a6f0 | PostPitCleanup | resets pit-stop related state fields after pit decision is finalized |
| 0042aee0 | PitStopBlockingCondition | returns true if pit stop is blocked (damage, weather, race state) |
| 004a56b0 | StateTransition | transitions AI/race state machine to a new state (arg=1 = pit entry) |
| 004a5750 | UtilityFunction_5750 | advances an index counter within bounds (used to select tire compound slot) |
| 004a57a0 | IndexDecrementWithBoundsWrap | decrements an index with wrap-around at bounds (tire compound navigation) |
| 004a5bd0 | ClampedIndexAssignment | assigns a clamped index value (used to set tire compound index) |
| 004bc060 | sub_4BC060 | sets pit stop marker/flag (arg=1 = pit stop active) |
| 004c6d90 | SceneRenderUpdate | updates scene rendering state (arg=0 = disable/hide pit HUD) |
| 004efac0 | ConditionalGate | conditional gate/guard function (used as pre-pit-stop validation) |
| 004f1890 | SpeedValueSetterWithGlobalMirror | sets a speed/velocity value and mirrors to a global for other systems |

**Guard conditions:** 
- `PitStopBlockingCondition(this) || dword_7C56A4 != 7`: If pit stop is blocked OR session is not a race (7), the pit stop is skipped (`v16 = 0`), scene render is disabled, timeOfNextExit is pushed forward by 180s, and PostPitCleanup fires.
- `v17 >= 3.0`: If remaining laps estimate >= 3.0, use it directly; otherwise clamp to minimum 3.0 laps.
- `flt_8AFEE8` thresholds 0.01/0.33/0.66: Track grip level is used to select a tire compound index (4=low, 5=med, 6=high).
- `this[4450]` comparison: If currentPitStopIndex+1 > totalPitStops, use total-race-laps based calculation; otherwise use per-stop lap target arrays.
- `*(_DWORD *)(*this + 3352) && !*(_BYTE *)(*this + 3416) && dword_7C56A4 == 7`: Early pit gate — if pit data ready and session gate is open during race, allow immediate pit scheduling.
- `*((_BYTE *)this + 14842) && dword_7C56A4 == 7`: Retirement trigger — if retirement flag is set during race, force pit entry.
