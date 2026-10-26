## BrakeBiasSetup_00438cc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIShiftPattern (0042b8d0), TireModelInit (0043e050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x72 | RW | — | [LLM] |
| this | 0x73 | RW | 2 | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x75 | RW | — | [LLM] |
| this | 0x76 | RW | 1 | [LLM] |
| this | 0x77 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x79 | RW | — | [LLM] |
| this | 0x7A | RW | — | [LLM] |
| this | 0x7B | RW | — | [LLM] |
| this | 0x7C | RW | — | [LLM] |
| this | 0x80 | RW | — | [LLM] |
| this | 0x9C | RW | — | [LLM] |

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
| 007ce6ac | dword_7CE6AC | R | [LLM] |
| 007ce6f4 | dword_7CE6F4 | R | BrakeDiffSettings [DERIVED] (also: ` to `DAT_007ce7a8` — 11 byte brake/diff settings) |
| 007ce718 | dword_7CE718 | R | FontRendererRef [DERIVED] (also: referenced by field 199) |
| 007ce73c | dword_7CE73C | R | UnknownModuleInterface [DERIVED] (also: ` — referenced but not in docs/12) |
| 007ce760 | dword_7CE760 | R | ControlMapping_Accel [DERIVED] |
| 007ce784 | dword_7CE784 | R | UITextDataReference [DERIVED] |
| 007ce7a8 | dword_7CE7A8 | R | BrakeDiffBlock [DERIVED] (also: ` — BrakeDiffSettings byte (docs/12) |
| 007ce7cc | dword_7CE7CC | R | ControlMapping_UI7 [DERIVED] |
| 007ce7f0 | dword_7CE7F0 | R | Unknown_Byte_7CE7F0 [DERIVED] |
| 007ce850 | dword_7CE850 | R | UI_RefStore_ed [DERIVED] (also: ` — stored in param_1[199]) |
| 007ce874 | byte_7CE874 | R | InputModeFlag [DERIVED] |
| 007ce88c | byte_7CE88C | R | VehicleModeFlag [DERIVED] (also: ` — mode flags) |
| 007ce8a4 | dword_7CE8A4 | R | ConfigByte_PitSettings [DERIVED] |
| 007ce934 | flt_7CE934 | R | DriverDataScaleFactor [DERIVED] (also: ` — scale factor) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b15d0 | BitmaskStateTest | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
