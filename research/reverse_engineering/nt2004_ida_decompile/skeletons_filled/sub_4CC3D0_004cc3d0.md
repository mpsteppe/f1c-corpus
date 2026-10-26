## sub_4CC3D0_004cc3d0 — VehicleHandlingPresetInitializer

**Summary:** Initializes vehicle handling/setup parameters from a preset index (0–3). Each case sets default values for 35+ parameter groups (each with current/min/max triplets) controlling suspension, steering, tire grip, aero, and other physics tunables for different track surfaces or difficulty levels.

**Called by:** sub_4CA940 (004ca940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4948 | R | — | Preset selector index (0=default, 1=alt, 2=surface2, 3=surface3) |
| this | 0x49B4 | RW | 0 | Parameter group 0: current value (clamped to range) |
| this | 0x49BC | R | — | Parameter group 0: minimum bound |
| this | 0x49C0 | R | — | Parameter group 0: maximum bound |
| this | 0x49D8 | RW | 0 | Parameter group 1: current value |
| this | 0x49E0 | R | — | Parameter group 1: minimum bound |
| this | 0x49E4 | R | — | Parameter group 1: maximum bound |
| this | 0x49FC | RW | 1056964608 → 0.5f | Parameter group 2: current (initialized to 0.5) |
| this | 0x4A04 | R | — | Parameter group 2: min bound |
| this | 0x4A08 | R | — | Parameter group 2: max bound |
| this | 0x4A20 | RW | 1039516303 → 0.12f | Parameter group 3: current (initialized to 0.12) |
| this | 0x4A28 | R | — | Parameter group 3: min bound |
| this | 0x4A2C | R | — | Parameter group 3: max bound |
| this | 0x4A44 | RW | 0 | Parameter group 4: current value |
| this | 0x4A4C | R | — | Parameter group 4: min bound |
| this | 0x4A50 | R | — | Parameter group 4: max bound |
| this | 0x4A68 | RW | 0 | Parameter group 5: current value |
| this | 0x4A70 | R | — | Parameter group 5: min bound |
| this | 0x4A74 | R | — | Parameter group 5: max bound |
| this | 0x4A8C | RW | 1058642330 → 0.6f | Parameter group 6: current |
| this | 0x4A94 | R | — | Parameter group 6: min bound |
| this | 0x4A98 | R | — | Parameter group 6: max bound |
| this | 0x4AB0 | RW | 1065353216 → 1.0f | Parameter group 7: current |
| this | 0x4AB8 | R | — | Parameter group 7: min bound |
| this | 0x4ABC | R | — | Parameter group 7: max bound |
| this | 0x4AD4 | RW | 1183621120 → 18000.0f | Parameter group 8: current (large value) |
| this | 0x4ADC | R | — | Parameter group 8: min bound |
| this | 0x4AE0 | R | — | Parameter group 8: max bound |
| this | 0x4AF8 | RW | 1074790400 → 2.25f | Parameter group 9: current |
| this | 0x4B00 | R | — | Parameter group 9: min bound |
| this | 0x4B04 | R | — | Parameter group 9: max bound |
| this | 0x4B1C | RW | 1058642330 → 0.6f | Parameter group 10: current |
| this | 0x4B24 | R | — | Parameter group 10: min bound |
| this | 0x4B28 | R | — | Parameter group 10: max bound |
| this | 0x4B40 | RW | 1014350479 → 0.015f | Parameter group 11: current |
| this | 0x4B48 | R | — | Parameter group 11: min bound |
| this | 0x4B4C | R | — | Parameter group 11: max bound |
| this | 0x4B64 | RW | 1033476506 → 0.075f | Parameter group 12: current |
| this | 0x4B6C | R | — | Parameter group 12: min bound |
| this | 0x4B70 | R | — | Parameter group 12: max bound |
| this | 0x4B88 | RW | 1065353216 → 1.0f | Parameter group 13: current |
| this | 0x4B90 | R | — | Parameter group 13: min bound |
| this | 0x4B94 | R | — | Parameter group 13: max bound |
| this | 0x4BAC | RW | 1065353216 → 1.0f | Parameter group 14: current |
| this | 0x4BB4 | R | — | Parameter group 14: min bound |
| this | 0x4BB8 | R | — | Parameter group 14: max bound |
| this | 0x4BD0 | RW | 1033476506 → 0.075f | Parameter group 15: current |
| this | 0x4BD8 | R | — | Parameter group 15: min bound |
| this | 0x4BDC | R | — | Parameter group 15: max bound |
| this | 0x4C18 | RW | 1036831949 → 0.1f | Parameter group 16: current |
| this | 0x4C20 | R | — | Parameter group 16: min bound |
| this | 0x4C24 | R | — | Parameter group 16: max bound |
| this | 0x4C3C | RW | 1034147594 → 0.08f | Parameter group 17: current |
| this | 0x4C44 | R | — | Parameter group 17: min bound |
| this | 0x4C48 | R | — | Parameter group 17: max bound |
| this | 0x4C60 | RW | 0 | Parameter group 18: current |
| this | 0x4C68 | R | — | Parameter group 18: min bound |
| this | 0x4C6C | R | — | Parameter group 18: max bound |
| this | 0x4C84 | RW | 0 | Parameter group 19: current |
| this | 0x4C8C | R | — | Parameter group 19: min bound |
| this | 0x4C90 | R | — | Parameter group 19: max bound |
| this | 0x4CA8 | RW | 1034147594 → 0.08f | Parameter group 20: current |
| this | 0x4CB0 | R | — | Parameter group 20: min bound |
| this | 0x4CB4 | R | — | Parameter group 20: max bound |
| this | 0x4CCC | RW | 1065353216 → 1.0f | Parameter group 21: current |
| this | 0x4CD4 | R | — | Parameter group 21: min bound |
| this | 0x4CD8 | R | — | Parameter group 21: max bound |
| this | 0x4CF0 | RW | 1041865114 → 0.15f | Parameter group 22: current |
| this | 0x4CF8 | R | — | Parameter group 22: min bound |
| this | 0x4CFC | R | — | Parameter group 22: max bound |
| this | 0x4D14 | RW | 0 | Parameter group 23: current |
| this | 0x4D1C | R | — | Parameter group 23: min bound |
| this | 0x4D20 | R | — | Parameter group 23: max bound |
| this | 0x4D38 | RW | 0 | Parameter group 24: current |
| this | 0x4D40 | R | — | Parameter group 24: min bound |
| this | 0x4D44 | R | — | Parameter group 24: max bound |
| this | 0x4D5C | RW | 1028443341 → 0.05f | Parameter group 25: current |
| this | 0x4D64 | R | — | Parameter group 25: min bound |
| this | 0x4D68 | R | — | Parameter group 25: max bound |
| this | 0x4D80 | RW | 1049414861 → 0.275f | Parameter group 26: current |
| this | 0x4D88 | R | — | Parameter group 26: min bound |
| this | 0x4D8C | R | — | Parameter group 26: max bound |
| this | 0x4DA4 | RW | 1060320051 → 0.7f | Parameter group 27: current |
| this | 0x4DAC | R | — | Parameter group 27: min bound |
| this | 0x4DB0 | R | — | Parameter group 27: max bound |
| this | 0x4DC8 | RW | 0 | Parameter group 28: current |
| this | 0x4DD0 | R | — | Parameter group 28: min bound |
| this | 0x4DD4 | R | — | Parameter group 28: max bound |
| this | 0x4DEC | RW | 1069547520 → 1.5f | Parameter group 29: current |
| this | 0x4DF4 | R | — | Parameter group 29: min bound |
| this | 0x4DF8 | R | — | Parameter group 29: max bound |
| this | 0x4E10 | RW | 1033476506 → 0.075f | Parameter group 30: current |
| this | 0x4E18 | R | — | Parameter group 30: min bound |
| this | 0x4E1C | R | — | Parameter group 30: max bound |
| this | 0x4E34 | RW | 1073741824 → 2.0f | Parameter group 31: current |
| this | 0x4E3C | R | — | Parameter group 31: min bound |
| this | 0x4E40 | R | — | Parameter group 31: max bound |
| this | 0x4E58 | RW | — | Parameter group 32: current |
| this | 0x4E60 | R | — | Parameter group 32: min bound |
| this | 0x4E64 | R | — | Parameter group 32: max bound |
| this | 0x5098 | RW | — | Parameter group 33: current |
| this | 0x50A0 | R | — | Parameter group 33: min bound |
| this | 0x50A4 | R | — | Parameter group 33: max bound |
| this | 0x52D8 | RW | — | Parameter group 34: current |
| this | 0x52E0 | R | — | Parameter group 34: min bound |
| this | 0x52E4 | R | — | Parameter group 34: max bound |
| this | 0x5518 | RW | — | Parameter group 35: current |
| this | 0x5520 | R | — | Parameter group 35: min bound |
| this | 0x5524 | R | — | Parameter group 35: max bound |

**Written-by note (persistence):**
- All parameter current-value fields: initialized once with preset defaults, then clamped against min/max bounds. External poke survives until next preset change (switch case re-triggered). These are setup parameters, not per-frame — written once per session/level load.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cd4fc | jpt_4CC3EA | R | Jump table for switch dispatch on preset index |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466720 | FloatClamp [exact] | Clamp current parameter value between min and max bounds |
| 004cef90 | sub_4CEF90 | Set a parameter current/min/max triplet from a single default value |
| 004cf370 | sub_4CF370 | Set an integer parameter triplet (used for boolean/enum params) |
| 004cf410 | ClampByRange [exact] | Clamp an integer parameter within range |

**Guard conditions:** Switch on `*(this+0x4948)` — only values 0-3 handled; default case returns immediately (no preset applied). Each case applies different default values for the same parameter groups.
