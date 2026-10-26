## DrivingModeParameterSetup_004adf10 — DrivingModeParameterSetup

**Summary:** Applies driving mode specific parameter values to a vehicle physics/tuning struct. Based on the mode selector at offset 0x1CC0 (switch on 6 modes), writes clamped integer and float values into multiple parameter slots with their min/max range bounds.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4732D0 (004732d0), TrackEnvironmentSelect (004ade20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x214 | RW | 1 | Driving parameter 1: clamped value (min at 0x21C, max at 0x220) |
| this | 0x21C | R | — | Parameter 1 minimum bound |
| this | 0x220 | R | — | Parameter 1 maximum bound |
| this | 0x25C | RW | 2 | Driving parameter 2: clamped value (min at 0x264, max at 0x268) |
| this | 0x264 | R | — | Parameter 2 minimum bound |
| this | 0x268 | R | — | Parameter 2 maximum bound |
| this | 0x280 | RW | 0 | Driving parameter 3: clamped value (min at 0x288, max at 0x28C) |
| this | 0x288 | R | — | Parameter 3 minimum bound |
| this | 0x28C | R | — | Parameter 3 maximum bound |
| this | 0x2A4 | RW | 2 | Driving parameter 4: clamped value (min at 0x2AC, max at 0x2B0) |
| this | 0x2AC | R | — | Parameter 4 minimum bound |
| this | 0x2B0 | R | — | Parameter 4 maximum bound |
| this | 0x2C8 | RW | 0 | Driving parameter 5: clamped value (min at 0x2D0, max at 0x2D4) |
| this | 0x2D0 | R | — | Parameter 5 minimum bound |
| this | 0x2D4 | R | — | Parameter 5 maximum bound |
| this | 0x2EC | RW | 1 | Driving parameter 6: clamped value (min at 0x2F4, max at 0x2F8) |
| this | 0x2F4 | R | — | Parameter 6 minimum bound |
| this | 0x2F8 | R | — | Parameter 6 maximum bound |
| this | 0x310 | RW | 1 | Driving parameter 7: clamped value (min at 0x318, max at 0x31C) |
| this | 0x318 | R | — | Parameter 7 minimum bound |
| this | 0x31C | R | — | Parameter 7 maximum bound |
| this | 0x334 | RW | 0 | Driving parameter 8: clamped value (min at 0x33C, max at 0x340) |
| this | 0x33C | R | — | Parameter 8 minimum bound |
| this | 0x340 | R | — | Parameter 8 maximum bound |
| this | 0x358 | RW | 1 | Driving parameter 9: clamped value (min at 0x360, max at 0x364) |
| this | 0x360 | R | — | Parameter 9 minimum bound |
| this | 0x364 | R | — | Parameter 9 maximum bound |
| this | 0x40C | RW | 3 | Driving parameter 10: clamped value (min at 0x414, max at 0x418) |
| this | 0x414 | R | — | Parameter 10 minimum bound |
| this | 0x418 | R | — | Parameter 10 maximum bound |
| this | 0x1CC0 | R | — | Driving mode selector (0-5); controls which parameter profile to apply |
| this | 0x1CE4 | RW | 1048576000 → 0.25f | Float driving parameter: clamped value (min at 0x1CEC, max at 0x1CF0) |
| this | 0x1CEC | R | — | Float parameter minimum bound |
| this | 0x1CF0 | R | — | Float parameter maximum bound |
| this | 0x1D08 | RW | 85 | Driving parameter 11: clamped value (min at 0x1D10, max at 0x1D14) |
| this | 0x1D10 | R | — | Parameter 11 minimum bound |
| this | 0x1D14 | R | — | Parameter 11 maximum bound |

**Written-by note (persistence):**
- this 0x214: Once per call — unconditional write for modes 1–3. External poke does NOT survive re-call with mode 1–3.
- this 0x25C: Once per call — unconditional write for modes 1–3. External poke does NOT survive.
- this 0x280: Once per call — unconditional write for modes 1–3. External poke does NOT survive.
- this 0x2A4: Once per call — unconditional write for modes 1–3. External poke does NOT survive.
- this 0x2C8: Once per call — unconditional write for modes 1–3. External poke does NOT survive.
- this 0x2EC: Once per call — unconditional write for modes 1–3. External poke does NOT survive.
- this 0x310: Once per call — unconditional write for modes 1–3. External poke does NOT survive.
- this 0x334: Once per call — unconditional write for modes 1–3. External poke does NOT survive.
- this 0x358: Once per call — unconditional write for modes 1–3. External poke does NOT survive.
- this 0x40C: Once per call — unconditional write for modes 1–3. External poke does NOT survive.
- this 0x1CE4: Once per call — unconditional write for modes 1–5. External poke does NOT survive.
- this 0x1D08: Once per call — unconditional write for modes 1–2. External poke does NOT survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ae46c | jpt_4ADF22 | R | Jump table for switch on driving mode (6 entries: cases 0–5) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646c0 | FloatClamp | Clamp a float value between min and max bounds |
| 0047f1f0 | ClampByRange | Clamp an integer value between min and max bounds |
| 004b1de0 | ClampedFloatSetter_1de0 | Set a float parameter with a constant value (modes 4–5) |
| 004b20d0 | ArithmeticComparison_20d0 | Apply/set a driving parameter with a literal integer value |

**Guard conditions:** Switch on `this + 0x1CC0` (driving mode selector): case 0 = break (no parameters set); case 1 = full parameter set with specific values; case 2 = similar full set with different values; case 3 = reduced set + ArithmeticComparison_20d0 calls; case 4 = all-zero via ArithmeticComparison_20d0 + final float; case 5 = similar zero profile; default = only ArithmeticComparison_20d0(0). After switch, if mode != 0, two final ArithmeticComparison_20d0 calls (1, 100) execute regardless of mode. PASSES: any mode 0–5. BLOCKED: nothing — all modes handled.
