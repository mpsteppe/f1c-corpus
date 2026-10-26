## VehiclePhysicsTimeStep_004c73f0 — Vehicle Physics Per-Frame Timestep

> **PERSISTENCE VERDICT CORRECTED 2026-07-24 (live poke — fact table untouched).**
> The written-by note below marks BOTH `0x105D` and `0x1065` as "recalc every frame —
> external poke does NOT persist". Live test, single-player race, side by side on the
> same healthy moving car (E. TesterA, 89 m/s):
>   - `0x1065` — note is CORRECT. Write reverts within 0.5 s. It mirrors packed-word
>     bit `0x4000000`; poking it is a no-op. Read-only **indicator** of braking.
>   - `0x105D` — note is **WRONG**. The write **PERSISTS** and is visibly effective
>     (poked 1->0 on M. SALO: helmet + arms vanished, car kept driving). So the
>     conditional rewrite here (`if (this[4189] != v26)`) does not fire in a normal
>     single-player race — presumably this packet path (`a2+56`) is only driven in
>     replay/network contexts.
> Do NOT skip poking `0x105D` on the strength of the note below. `0x105D` is
> **DriverModelVisible**, not an "audio effect toggle"; `sub_4E0ED0` is the render-state
> update, not an audio controller.
> Detail: `mods/ai_pit_retire/RETIRE_SOLVED_2026-07-24.md`.


**Summary:** Per-frame vehicle physics update: computes position/velocity from input data, applies suspension parameters, runs subsystem state machines (mode 2/3), and updates audio/vibration/braking effects based on bitfield flags.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TeamColorLoader (004f03e0), sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | — | PhysX [FACT] |
| this | 0x20 | RW | — | PhysY [FACT] |
| this | 0x24 | RW | — | PhysZ [FACT] |
| this | 0x58 | RW | — | velocity X component |
| this | 0x5C | RW | — | velocity Y component |
| this | 0x60 | RW | — | velocity Z component |
| this | 0xA0 | RW | — | EngineAngVel [FACT] |
| this | 0xA4 | RW | — | engine revs / rpm input |
| this | 0x8C0 | R | — | base pointer to suspension data array (4 wheels × 74 floats each) |
| this | 0x1040 | RW | — | steering input clamped to [-1, 1] (from a2 bitfield, clamped) |
| this | 0x1044 | R | — | steering sensitivity multiplier (read, multiplied with clamped steering for front wheels) |
| this | 0x1054 | R | — | audio effect handle/param read for sound controller |
| this | 0x105D | RW | — | audio effect toggle byte (flag 0x8000000 from a2+56, triggers AudioSoundEffectController on change) |
| this | 0x1065 | RW | — | boolean flag for brake effect state (bit 0x4000000 from a2+56) |
| this | 0x1067 | RW | — | boolean flag for additional effect (bit 0x2000000 from a2+56) |
| this | 0x1069 | RW | — | byte flag: bit 0x80 from a2+52 |
| this | 0x32C8 | R | — | physics mode selector: 2 = vehicle setup copy mode, 3 = vibration/state machine mode |
| this | 0x344C | RW | — | byte flag set from a2+56 sign bit (negative check), stored when mode==2 |
| this | 0x3580 | RW | — | cached steering input (stored when mode==2) |
| this | 0x3584 | RW | 0 | BrakeFactor [CONFIRMED] |
| this | 0x35BC | RW | — | wheel contact forces array (4 floats, one per wheel) |
| this | 0x4024 | RW | — | byte flag copied from a2+59 bit 0 (lowest bit) |
| this | 0x4028 | RW | — | float result from BitfieldExtractionWithScale on input bitfield |
| this | 0x48B0 | RW | — | short value from BitfieldExtract_2b80 (16-bit field from input) |
| this | 0x48B4 | RW | — | timestamp for 15-second subsystem state machine update gate (last update time) |
| this | 0x48B8 | RW | — | previous frame timestamp (stored at start, used for delta time computation) |

**Written-by note (persistence):**
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x5C: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0xA0: recalc every frame — external poke does NOT persist
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0x1040: recalc every frame — external poke does NOT persist
- this 0x105D: recalc every frame — external poke does NOT persist
- this 0x1065: recalc every frame — external poke does NOT persist
- this 0x1067: recalc every frame — external poke does NOT persist
- this 0x1069: recalc every frame — external poke does NOT persist
- this 0x344C: recalc every frame — external poke does NOT persist
- this 0x3580: recalc every frame — external poke does NOT persist
- this 0x3584: recalc every frame — external poke does NOT persist
- this 0x35BC: recalc every frame — external poke does NOT persist
- this 0x4024: recalc every frame — external poke does NOT persist
- this 0x4028: recalc every frame — external poke does NOT persist
- this 0x48B0: recalc every frame — external poke does NOT persist
- this 0x48B4: recalc every frame — external poke does NOT persist
- this 0x48B8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b2420 | ArithmeticComparison_2420 | reads packed data from input struct, decomposes into rotation matrix and position vectors |
| 004b2580 | ShortVectorToFloatWithScale | converts short vector from input to float velocity vector with scaling |
| 004b26d0 | FloatTruncation | extracts and truncates float values from input data |
| 004b2800 | ShortToFloatVectorUnpack | unpacks short integers to float array from input bitfield |
| 004b28f0 | sub_4B28F0 | reads per-wheel contact force/deflection data from input bitfield |
| 004b2980 | BitfieldExtractScale | extracts and scales a float value from input bitfield |
| 004b29f0 | ShortComputation_29f0 | computes engine revs from input bitfield (short→float) |
| 004b2a30 | BitfieldExtract | extracts a bitfield value from input data for vehicle setup |
| 004b2a80 | BitfieldToFloatConversion | converts bitfield to float (steering input raw value, before clamp) |
| 004b2ad0 | BitTest | tests a specific bit in input bitfield for subsystem state machines |
| 004e0ed0 | AudioSoundEffectController | triggers an audio sound effect by handle ID |
| 004e17c0 | SubsystemStateMachine | runs a subsystem state machine step for one of 14 subsystems |
| 004e2230 | VibrationStateMachine | runs vibration/force feedback state machine for one of 4 channels |
| 004e23d0 | F_3x3MatrixTransform | transforms input position by rotation matrix |
| 004e24a0 | SuspensionParamUpdate | updates suspension parameters for one wheel (index, deflection, time-weighted position) |
| 004f1650 | VehicleSetupDataCopy | copies vehicle setup data (position, rotation, velocity, etc.) from input to this object |
| 004f17a0 | EffectParameterSetter | sets an effect parameter with scaled engine value |
| 004f17d0 | MatrixVectorSetup | sets up matrix-vector transformation data from rotation and short→float vector |
| 00566e40 | EulerToRotationMatrix | converts Euler angles to a 3×3 rotation matrix |

**Guard conditions:** Mode selector at this+0x32C8: if == 2, runs vehicle setup copy + wheel forces + subsystem state machines (gated by 15-second timer at this+0x48B4). If == 3, runs vibration state machines + subsystem state machines (no timer gate). Audio effect toggle at this+0x105D: if byte changed vs new bit 0x8000000 from a2+56, triggers AudioSoundEffectController. Bit 0x4000000 sets BrakeFactor to 1.0f (else 0). Bit 0x2000000 sets byte flag at this+0x1067. Bit 0x80 from a2+52 sets byte flag at this+0x1069.