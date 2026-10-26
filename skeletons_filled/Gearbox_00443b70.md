## Gearbox_00443b70 — Gearbox RPM Matching and Shift Control Simulation

**Summary:** Computes engine RPM blending during gear changes, throttle control for auto/manual shift modes, RPM limiting, and shift-timing logic based on current gear ratio relative to target RPM. Also handles temperature-based RPM clamping, speed limiter engagement, and telemetry position updates. Part of the vehicle drivetrain/gearbox physics simulation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | throttle blend output coefficient (double, clamped to [0,1]) |
| this | 0xC | RW | 0 | throttle blend accumulator / base value (double, init to 1.0 or 0.0) |
| this | 0x10 | R | — | RPM ratio threshold (double, used for gear-ratio comparison) |
| this | 0x18 | RW | 0 | clutch/shift progress timer (double, 0→1 ramps during shift) |
| this | 0x1C | RW | 0 | shift progress component / secondary clutch timer |
| this | 0x20 | RW | — | maximum shift progress threshold (double, clamps shift timing) |
| this | 0x68 | R | — | timing delta / time-step value (double) |
| this | 0x80 | R | — | shift mode flags byte (bit 0 = upshift allowed, bit 1 = downshift allowed) |
| this | 0x170 | RW | — | maximum RPM rate-of-change (double, written as damped derivative) |
| this | 0x19C | R | — | wheel/road speed value (double) |
| this | 0x348 | R | — | RPM input / drivetrain speed (double, gear-ratio numerator) |
| this | 0x498 | R | — | RPM input / drivetrain speed (double, gear-ratio denominator) |
| this | 0x7AC | R | — | engine RPM readback / secondary speed input |
| this | 0x8FC | R | — | engine RPM input (doubles with 0xC10 variant) |
| this | 0xC10 | R | — | engine RPM / drivetrain speed input |
| this | 0xD60 | R | — | engine RPM / drivetrain speed input |
| this | 0x1074 | R | — | engine RPM / drivetrain speed input |
| this | 0x11C4 | R | — | engine RPM / drivetrain speed input |
| this | 0x1C58 | R | — | RPM target / gear ratio reference value (double) |
| this | 0x1C5C | RW | — | written gear-ratio intermediate value |
| this | 0x1C60 | RW | — | written gear-ratio intermediate value |
| this | 0x1C7C | R | — | RPM target threshold (double, upper) |
| this | 0x1C84 | R | — | RPM target threshold (double, lower) |
| this | 0x1C88 | R | — | RPM limit / speed threshold (double) |
| this | 0x1C8C | R | — | RPM limiter threshold (double) |
| this | 0x1CDC | R | — | RPM shift-point threshold (double) |
| this | 0x1CE4 | R | — | RPM rev-limit threshold (double) |
| this | 0x1CEC | R | — | RPM idle threshold (double) |
| this | 0x1D10 | RW | — | written RPM limiter output (double, engine RPM clamp target) |
| this | 0x1D28 | R | — | RPM limiter intermediate value |
| this | 0x1DAC | R | — | temperature/heat accumulator input |
| this | 0x1E14 | R | — | RPM threshold for speed limiter |
| this | 0x1E38 | R | — | RPM scaling factor for speed limiter |
| this | 0x1E78 | R | — | target gear RPM (desired RPM after shift) |
| this | 0x1E7C | RW | — | computed target RPM for next gear |
| this | 0x1E8C | R | — | gear-ratio table value |
| this | 0x1E9C | R | — | gear-ratio table value |
| this | 0x1EF0 | RW | — | shift timer accumulator (double) |
| this | 0x1EF4 | R | — | shift timer threshold (double) |
| this | 0x1EF8 | RW | 0 | engine RPM low-pass filter state / shift-active flag (negative = mid-shift) |
| this | 0x1F00 | R | — | engine RPM input for throttle blending |

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
| 00447160 | VehicleActive | check if vehicle is active/on-track |
| 004471f0 | SuspensionVibration | trigger suspension vibration effect (bumps/curbs) |
| 00447b10 | RandomPhysicsParameterGenerator | generate random perturbation for physics parameters |
| 00447e00 | PositionLapStateUpdate | update position/lap state tracking |
| 004ef4f0 | PositionUpdateWithTelemetryRecording | update race position and record telemetry data |
| 004f87c0 | HUDElementConfig | configure HUD element (e.g. show shift indicator) |
| 00587bdc | CRTFtol | convert floating-point to integer (truncation) |
| 0058957a | InterruptDispatch | dispatch interrupt / call interrupt handler |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1EF8 | < | 0 | shift-state check: when shift timer is negative (mid-shift active), RPM-matching logic for gear ratio detection is bypassed |

**Guard interpretation:** this[0x1EF8] < 0: this field acts as a shift-active flag. When negative (mid-shift in progress), the function skips the RPM-matching throttle blend logic (LABEL_21 branch) because the engine is being rev-matched during the shift. When >= 0 (shift complete or not shifting), normal RPM-matching proceeds. PASSES (skips blending) when shifting is active; BLOCKED (runs blending) when not shifting.
