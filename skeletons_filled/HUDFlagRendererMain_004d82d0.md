## HUDFlagRendererMain_004d82d0 — HUD flag render main

**Summary:** Collects race flag bytes (yellow=62, blue=65, black=63, pit=102, checkered=66, plus fuel/penalty flags) into a buffer based on various game-state checks, then renders them via sub_553070 with a white color override. Skips if input display mode is 0, a conditional flag is set, scoring gate is at state 2, or participant slot is invalid.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D8450 (004d8450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Participant slot ID or driver index; when != -1, blocks flag rendering (uninitialized slot) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = checkered flag phase) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |
| 007cfea0 | dword_7CFEA0 | R | InputDisplayMode [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ad394 | dword_8AD394 | R | AudioEmitter3 [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f10 | ConditionalFlagReturn | Checks a conditional flag; non-zero return blocks entire flag rendering |
| 0049b9a0 | sub_49B9A0 | Unknown flag condition check (flag -126) |
| 0049ba30 | sub_49BA30 | Returns 0/1/2 to select between flag -116 or -115 |
| 0049ba50 | FuelWeightComputation | Fuel-related flag condition (flag 68) |
| 0049ba90 | PitStateFlagCheck | Pit state flag condition (flag 102) |
| 0049bab0 | DisqualificationCheck | Disqualification flag condition (flag 63) |
| 0049bad0 | ShortComputation_bad0 | Returns bool for yellow flag (62) |
| 0049bb20 | VehicleFlagCheck | Vehicle-related flag condition (blue flag 65) |
| 00552fc0 | FieldSetterAt0x48 | Sets render color to 0xFFFFFF (white) |
| 00553070 | sub_553070 | Renders collected flag byte array as HUD elements |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | != | 18446744073709551615 | Participant slot must be -1 (invalid/available) to proceed |

**Guard interpretation:** PASSES when `this[2] == -1` (slot available), `dword_7CFEA0 != 0` (input display enabled), `ConditionalFlagReturn()` returns false, and `dword_8AB6E4 != 2` (scoring gate not in state 2). BLOCKED (early return) if any of: `dword_7CFEA0 == 0`, `ConditionalFlagReturn()` true, `dword_8AB6E4 == 2`, or `this[2] != -1`.
