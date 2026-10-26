## BrakeBiasSetup_00438cc0 — Brake Bias and Vehicle Control Configuration Setup

**Summary:** Initializes brake bias, differential, and vehicle control settings from global configuration data. Copies 11 configuration byte slots, applies bitmask filtering to disable unsupported settings, sets control mapping mode based on input device type, and computes a scaled driver data factor.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIShiftPattern (0042b8d0), TireModelInit (0043e050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x72 | RW | — | brake bias front/rear balance setting byte (copied from dword_7CE6F4) |
| this | 0x73 | RW | 2 | differential/unknown module setting byte (copied from dword_7CE73C, may be overridden to 2) |
| this | 0x74 | RW | — | additional brake configuration byte (copied from dword_7CE7F0) |
| this | 0x75 | RW | — | pit/vehicle settings byte (copied from dword_7CE8A4, checked for non-zero to force byte at 0x76) |
| this | 0x76 | RW | 1 | UI control mapping byte (copied from dword_7CE850, forced to 1 if offset 0x75 is non-zero) |
| this | 0x77 | RW | — | text/UI data reference byte (copied from dword_7CE784) |
| this | 0x78 | RW | — | control mapping byte 7 (copied from dword_7CE7CC) |
| this | 0x79 | RW | — | control mapping byte 6 (copied from dword_7CE6AC) |
| this | 0x7A | RW | — | font/rendering reference byte (copied from dword_7CE718) |
| this | 0x7B | RW | — | accelerator control mapping byte (copied from dword_7CE760) |
| this | 0x7C | RW | — | brake/differential block byte (copied from dword_7CE7A8) |
| this | 0x80 | RW | — | vehicle control mode selector: 0 = keyboard only, 1 = controller + auto, 2 = controller + manual, 3 = controller + auto + keyboard |
| this | 0x9C | RW | — | scaled driver data factor (double, computed as flt_7CE934 * 0.95) |

**Written-by note (persistence):**
- this 0x72: recalc every frame — external poke does NOT persist
- this 0x73: recalc every frame — external poke does NOT persist
- this 0x74: recalc every frame — external poke does NOT persist
- this 0x75: recalc every frame — external poke does NOT persist
- this 0x76: recalc every frame — external poke does NOT persist
- this 0x77: recalc every frame — external poke does NOT persist
- this 0x78: recalc every frame — external poke does NOT persist
- this 0x79: recalc every frame — external poke does NOT persist
- this 0x7A: recalc every frame — external poke does NOT persist
- this 0x7B: recalc every frame — external poke does NOT persist
- this 0x7C: recalc every frame — external poke does NOT persist
- this 0x80: recalc every frame — external poke does NOT persist
- this 0x9C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eb98 | dbl_59EB98 | R | SetupParamMultiplier [DERIVED] (also: ` — multiplier) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce6ac | dword_7CE6AC | R | control mapping configuration value (byte at index 6 in the settings array) |
| 007ce6f4 | dword_7CE6F4 | R | BrakeDiffSettings [DERIVED] (also: ` to `DAT_007ce7a8` — 11 byte brake/diff settings) — brake bias front/rear setting |
| 007ce718 | dword_7CE718 | R | FontRendererRef [DERIVED] (also: referenced by field 199) — font/rendering configuration reference |
| 007ce73c | dword_7CE73C | R | UnknownModuleInterface [DERIVED] (also: ` — referenced but not in docs/12) — differential/module setting |
| 007ce760 | dword_7CE760 | R | ControlMapping_Accel [DERIVED] — accelerator pedal mapping configuration |
| 007ce784 | dword_7CE784 | R | UITextDataReference [DERIVED] — UI text data configuration reference |
| 007ce7a8 | dword_7CE7A8 | R | BrakeDiffBlock [DERIVED] (also: ` — BrakeDiffSettings byte (docs/12) — brake/differential block configuration |
| 007ce7cc | dword_7CE7CC | R | ControlMapping_UI7 [DERIVED] — control mapping configuration (index 7) |
| 007ce7f0 | dword_7CE7F0 | R | Unknown_Byte_7CE7F0 [DERIVED] — additional brake configuration value |
| 007ce850 | dword_7CE850 | R | UI_RefStore_ed [DERIVED] (also: ` — stored in param_1[199]) — UI reference store configuration |
| 007ce874 | byte_7CE874 | R | InputModeFlag [DERIVED] — input device mode flag (non-zero = keyboard enabled) |
| 007ce88c | byte_7CE88C | R | VehicleModeFlag [DERIVED] (also: ` — mode flags) — vehicle control mode flag (auto/manual) |
| 007ce8a4 | dword_7CE8A4 | R | ConfigByte_PitSettings [DERIVED] — pit/vehicle settings configuration byte |
| 007ce934 | flt_7CE934 | R | DriverDataScaleFactor [DERIVED] (also: ` — scale factor) — driver data scale factor, multiplied by 0.95 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b15d0 | BitmaskStateTest | tests if a specific bit index is enabled in a global bitmask (returns bool for configuration slot enable/disable) |

**Guard conditions:** none — unconditional initialization. All 11 configuration slots are always written (copied from globals then filtered). Control mode and scale factor are always computed. Specific conditional logic:
- **byte_7CE874 (InputModeFlag):** if non-zero → mode = 2 * (byte_7CE88C != 0) + 1 (controller modes). If zero → mode = (byte_7CE88C != 0) ? 2 : 0 (keyboard/auto modes). Both paths always execute.
- **BitmaskStateTest(i):** for each of the 11 slots, if bitmask test returns false → slot byte zeroed (setting disabled). Always iterates all 11 slots.
- **Offset 0x74 or 0x7A non-zero:** if either byte is set → offset 0x73 forced to 2 (differential setting override).
- **Offset 0x75 non-zero:** if the pit/vehicle byte is set → offset 0x76 forced to 1 (UI control override).
