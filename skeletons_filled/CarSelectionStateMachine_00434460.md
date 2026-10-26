## CarSelectionStateMachine_00434460 — Pre-Race Car Selection / Grid Camera State Machine

**Summary:** State machine controlling pre-race car selection and grid-position camera: transitions through init → countdown → wait → vehicle-advance → end states, iterates over vehicle slots, validates against VehicleCount, triggers pit-exit/camera setup, and passes camera parameters to the rendering subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40DE60 (0040de60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0xC | R | — | camera/session parameter 1 (integer) passed to camera config utility |
| *(this+0xC) | 0x10 | R | — | camera/session parameter 2 (integer) passed to camera config utility |
| *(this+0xC) | 0x14 | R | — | camera/session float parameter passed to camera config utility |
| *(this+0xC) | 0x18 | R | — | camera parameter 4 (integer) — also compared against stride-element threshold |
| *(this+0xC) | 0x1C | R | — | camera parameter 5 (integer) passed to camera config utility |
| *(this+0xC) | 0x20 | R | — | camera parameter 6 (integer) passed to camera config utility |
| *(this+0xC) | 0x48 | R | — | camera float parameter at offset 0x48 (e.g., FOV / zoom) passed to ConditionalFloatSetter |
| *(this+0xC) | 0xB0 | R | — | session-object validity flag at offset 0xB0 (non-null check gate for camera block) |
| *(this+0xC) | 0xBC | R | — | camera threshold float at offset 0xBC (compared against stride element field) |
| this | 0x0 | R | — | initialization-complete flag byte (0 = first-run init, non-zero = state machine active) |
| this | 0x4 | RW | 4 | state machine phase (0=init, 1=countdown→2, 2=wait, 3/4=advance, 5=end countdown) |
| this | 0xC | R | — | pointer to camera/session object (source of all camera params) |
| this | 0x18 | RW | — | current vehicle slot index counter (incremented per advance step) |
| this | 0x1C | RW | — | matched vehicle array position (int index) / temporarily zeroed float |
| this | 0x24 | RW | — | state-transition countdown timer (float, counts toward 0.0) |
| this | 0x28 | RW | — | progressive accumulator float (frame-scaled accumulation, added to each tick) |
| this | 0x2C | RW | 1 | car selection offset/base index (1-based, passed to StridedArrayElementPointer) |
| this | 0x34 | RW | — | cooldown timer for non-gated vehicle index advance (reset to 2.25s) |

**Written-by note (persistence):**
- this 0x4: written conditionally per state transition — external poke overwrites state
- this 0x18: written conditionally (incremented during advance) — external poke persists until next transition
- this 0x1C: written conditionally (set to matched vehicle index or zeroed) — external poke persists
- this 0x24: written every tick in states 1, 2, 5 (countdown decrement) — external poke overwritten next tick
- this 0x28: written every tick (accumulates dbl_8AFE98) — external poke overwritten next tick
- this 0x2C: written once in state 2, or recomputed as index+3 during advance — external poke persists
- this 0x34: written conditionally (decremented or reset to 2.25) — external poke persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] (also: ` — camera shake multiplier / conversion factor (docs/09, 19) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ea535 | byte_5EA535 | W | byte_5EA535 [DERIVED] |
| 005ea538 | dword_5EA538 | W | FileInitCounter [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c910 | ShortComputation_c910 | brief update computation on session manager (camera/state tick) |
| 00418b90 | ScoreThresholdGateCheck | test if score threshold 520 is met — gates car-advance logic |
| 0041c0f0 | PitExit | process pit-exit / car-change event for given vehicle index |
| 00434820 | ModuleInitializationWithFallback | first-run module initialisation with fallback path |
| 00434d60 | SteeringInterpolationCameraFollow | configure steering interpolation / camera follow mode based on byte flag |
| 00435240 | StateFlagCheck_5240 | check boolean state-dependent flag on state-machine object |
| 00456060 | DualFieldGetter | retrieve two camera-related fields into output variables |
| 00456080 | ShortComputation_6080 | short camera computation producing two output values |
| 004582a0 | StridedArrayElementPointer | get pointer to strided array element by index (vehicle grid slot) |
| 004d8760 | sub_4D8760 | trigger sub-system notification with (mode, param) — e.g., UI/audio event |
| 004d88b0 | IteratorCheck | check or advance session-mode iterator |
| 00541cd0 | UtilityFunction_1cd0 | configure camera/view with 6 position/orientation parameters |
| 00542050 | sub_542050 | set rotation / camera angles from degree-to-radian converted values |
| 005423c0 | TwoFieldSetterCall | apply two output fields from ShortComputation_6080 to camera |
| 00542680 | ConditionalFloatSetter | conditionally set a float camera parameter (e.g., FOV override) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | initialization-complete byte — 0 means first-run |

**Guard interpretation:** The byte at `this+0x0` gates the entire state machine:
- `this+0x0 == 0`: PASSES the initialization branch — calls `ModuleInitializationWithFallback`, then jumps to camera block (LABEL_40). State machine phases are **BLOCKED** (skipped entirely).
- `this+0x0 != 0`: PASSES the state machine — enters the state-dispatch chain. Additional nested guards:
  - State 0: auto-transitions to state 1 via `sub_4D8760(2,1)`.
  - State 1: countdown decrements `this[9]`; when exhausted, transitions to state 2.
  - State 2: triggers `StateFlagCheck_5240`; if true, transitions to state 4.
  - States 3/4: `ScoreThresholdGateCheck(520)` must pass for vehicle advance; if blocked, `this[13]` cooldown decrements. Vehicle index checked against `VehicleCount` — exceeding it transitions to state 5 (end).
  - State 5: countdown decrements; when exhausted, sets return value 1 (complete).
  - The trailing camera block (LABEL_40) is gated by `this+0xC == 0` OR `*(this+0xC)+0xB0 == 0` — either null skips all camera processing.

(End of file - total 84 lines)
