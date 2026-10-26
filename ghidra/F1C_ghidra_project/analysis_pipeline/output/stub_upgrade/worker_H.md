=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042c3b0 — DynMan::Restart()

Resets dynman state, reloads AI settings, and refreshes all vehicles. Part of dynman.cpp lifecycle.

**Key logic:**
- Logs entry via FUN_004d7aa0
- Zeroes DAT_007c5694 and DAT_007c5698 (dynman state counters)
- Calls FUN_004333e0 (AI settings reload)
- Iterates all vehicles (DAT_005c329c count), calls FUN_004c6d90 per vehicle
- Calls FUN_00410890 (post-processing)
- Copies player index: DAT_007c54dc = DAT_007c54e4, DAT_007c54e0 = VehiclePtrArray[DAT_007c54e4]

**Calls:** FUN_004d7a50 (logging gate), FUN_004d7aa0 (logging), FUN_004333e0 (AI settings), FUN_004c6d90 (per-vehicle reset), FUN_00410890 (post-processing)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_0049ef70 — OnScreen::Setup()

Empty setup stub. Logs entry only.

**Key logic:**
- Logs entry via FUN_004d7aa0, no other operations

**Calls:** FUN_004d7a50 (logging gate), FUN_004d7aa0 (logging)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_00455f00 — HWInput::Exit()

Shuts down hardware input subsystem. Releases DirectInput device, cleans up force feedback.

**Key logic:**
- Logs entry via FUN_004d7aa0
- Calls FUN_0044fbe0 ×2, FUN_0044f5f0, FUN_0044efe0 (DirectInput cleanup sequence)
- Releases DirectInput device via vtable call (+8) on *param_1, zeroes param_1
- If DAT_007d13a0 == 1: calls FUN_004f8c90 (force feedback cleanup), sets param_1[0x6c4] = -1

**Calls:** FUN_004d7a50, FUN_004d7aa0, FUN_0044fbe0, FUN_0044f5f0, FUN_0044efe0, FUN_004f8c90

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_004b4170 — Render::Post()

Empty post-frame stub. Logs entry only.

**Key logic:**
- Logs entry via FUN_004d7aa0, no other operations

**Calls:** FUN_004d7a50 (logging gate), FUN_004d7aa0 (logging)

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->
### FUN_004b1900 — PlayerFile::Post()

Saves player file and checks state transition condition.

**Key logic:**
- Logs entry via FUN_004d7aa0
- Calls FUN_004b0770(1) — player file save
- Checks param_1+0x1f78 (state field): if != 4, calls FUN_004b17b0 (state handler) and returns

**Calls:** FUN_004d7a50, FUN_004d7aa0, FUN_004b0770 (player save), FUN_004b17b0 (state handler)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1f78 | StateFlag | Compared to 4; if not 4, triggers alternate path |

**Moddability:** hardcoded

<!-- target: docs/09-track-system.md -->
### FUN_004ceec0 — SpecialFX::Setup()

Empty setup stub. Logs entry only.

**Key logic:**
- Logs entry via FUN_004d7aa0, no other operations

**Calls:** FUN_004d7a50 (logging gate), FUN_004d7aa0 (logging)

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004a2840 — Parameter Interpolation

Float-keyed piecewise linear parameter interpolation with dispatch. Evaluates input param_2 against a threshold table, interpolates between entries, and dispatches result to registered targets.

**Key logic:**
- Struct at param_1: +0x6c (entry array ptr), +0x70 (entry count), +0x74 (float table ptr), +0x44 (current value), +0x68 (dispatch target count)
- Each table entry: stride 7 floats [lo_threshold, hi_threshold, slope_mult, val_at_lo, val_at_hi, ?, ?]
- If param_2 below lo_threshold: updates current value to lo_threshold value, dispatches lo val to all targets via FUN_00551210
- If param_2 above hi_threshold: updates current value to hi_threshold value, dispatches hi val
- If param_2 between thresholds: interpolates linearly: `(hi_val - lo_val) * (param_2 - lo_thresh) * slope + lo_val`, dispatches interpolated value
- If param_2 matches an existing breakpoint: returns early without dispatch

**Calls:** FUN_00551210 (parameter dispatch to registered targets)

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004414d0 — WheelDataCopy (redirect)

Full entry exists at docs/18-physics-dynamics.md. Physics state backup and stepping with wheel state copy.

**Key logic:**
- Copies 4× wheel state blocks (stride 0x119*4 bytes each)
- Transfers +0x1c5c/0x1c60 → +0x1c64/0x1c68 (frame history)
- Transfers +0x1e38/0x1e3c → +0x1e40/0x1e44 (secondary state)
- Copies per-wheel suspension data from +0x340 region to -2 offset region (4 wheels)
- Iterates linked state array: param_1+0x15ac count, param_1+0x162c base, param_1+0x15b0 source stride 0x244
- Copies 12 dwords per entry: 6 from +0x134, 6 from +0x14c
- Calls FUN_0043f7f0, FUN_0056ecf0, FUN_0056ee40, FUN_0056f020, FUN_00441450

**Calls:** FUN_0043f7f0, FUN_0056ecf0, FUN_0056ee40, FUN_0056f020, FUN_00441450

**Moddability:** hardcoded
