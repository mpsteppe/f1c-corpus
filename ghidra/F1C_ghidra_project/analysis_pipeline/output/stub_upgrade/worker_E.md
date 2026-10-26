=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042C130 — DynMan::Enter

DynMan module entry point. Called during engine module lifecycle to enter DynMan (Dynamic Manager) subsystem.

**Key logic:**
- Calls debug trace guard (FUN_004d7a50, level 2) to check if tracing enabled
- If enabled, logs "Entered DynMan::Enter()" to global trace buffer (DAT_008ad25c)
- Delegates to FUN_0042bd60 (Game::Post or engine tick) — drives engine state machine

**Calls:** FUN_004d7a50 (trace guard), FUN_004d7aa0 (trace printf), FUN_0042bd60 (game state tick, docs/01)

<!-- target: docs/01-engine-architecture.md -->
### FUN_004C8CA0 — Sound::Post

Sound module post-frame update. Called during engine Post phase for audio subsystem.

**Key logic:**
- Calls debug trace guard (FUN_004d7a50, level 2) — logs "Entered Sound::Post()" if enabled
- Calls four sub-functions in sequence for sound processing pipeline
- No return value — void dispatch

**Calls:** FUN_004d7a50 (trace guard), FUN_004d7aa0 (trace printf), FUN_004c8180 (sound update), FUN_004c7e80 (sound update), FUN_004c8a10 (sound update), FUN_00418a60 (unknown utility)

<!-- target: docs/01-engine-architecture.md -->
### FUN_00455D50 — HWInput::Init

Hardware input module initialization. Called during engine Init phase for input subsystem.

**Key logic:**
- Guards on DAT_007c569c (SessionType5, docs/12) — skips debug trace if SessionType5 == 5 (server mode)
- Calls debug trace guard (FUN_004d7a50, level 2) — logs "Entered HWInput::Init()" if not server
- Calls three initialization sub-functions in sequence

**Globals:**
- `DAT_007c569c` — SessionType5 (5=server, docs/12)

**Calls:** FUN_004d7a50 (trace guard), FUN_004d7aa0 (trace printf), FUN_004532d0 (input init), FUN_004533a0 (input init), FUN_00453560 (input init)

<!-- target: docs/01-engine-architecture.md -->
### FUN_004B4030 — Render::Init

Render module initialization entry point. Called during engine Init phase for rendering subsystem.

**Key logic:**
- Calls debug trace guard (FUN_004d7a50, level 2) — logs "Entered Render::Init()" if enabled
- Pure tracing function — no additional initialization calls
- Returns immediately after trace

**Calls:** FUN_004d7a50 (trace guard), FUN_004d7aa0 (trace printf)

<!-- target: docs/08-file-formats.md -->
### FUN_004B1820 — PlayerFile::Enter

PlayerFile module entry point. Initializes player file subsystem by setting player data path reference.

**Key logic:**
- Calls debug trace guard (FUN_004d7a50, level 2) — logs "Entered PlayerFile::Enter()" if enabled
- Sets struct field at param_1 + 0x49b0 to DAT_005ec6d8 (PlayerDataPath, docs/12) — stores player file directory pointer
- Delegates to FUN_004b03f0 (player file processing)

**Globals:**
- `DAT_005ec6d8` — PlayerDataPath (player file directory, docs/12)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x49b0 | PlayerDataPathPtr | Pointer to player data directory string |

**Calls:** FUN_004d7a50 (trace guard), FUN_004d7aa0 (trace printf), FUN_004b03f0 (player file processing)

<!-- target: docs/09-track-system.md -->
### FUN_00455290 — Input Action Registration

Registers all game input action names into the action system. Registers ~50 named actions covering all player controls.

**Key logic:**
- Calls FUN_00566650 for each action name constant — registers action string into input system
- Actions registered: steering, acceleration, braking, gears 1-7, neutral, reverse, clutch, TC override, launch control, LCD controls, pit request, RPM limiter, brake bias (F/R), look (left/right/behind/up/down/roll), instant replay, pause, restart race, zero head tracker, vehicle labels, ignition, starter, headlights, handbrake

**Note:** This function is about input action setup, not track system. Assigned to docs/09 per stub upgrade routing.

**Calls:** FUN_00566650 (register action name)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_005215DB — SIMD Vector Normalization (RSQRT)

Computes vector normalization using SIMD reciprocal square root approximation. Takes two input vectors (param_2, param_3), computes normalized result into param_1 using Newton-Raphson refinement.

**Key logic:**
- Calls FastExitMediaState() — saves FPU/MMX state for SIMD operations
- Computes dot product of param_2 and param_3 via PackedFloatingMUL + ADD
- Computes reciprocal square root of param_4 using Newton-Raphson iteration:
  - PackedFloatingReciprocalSQRAprox for initial approximation
  - PackedFloatingReciprocalIter1/Iter2 for refinement
  - FloatingReciprocalAprox for accuracy
- Applies sign handling via DAT_005af9d0 mask
- Performs final multiplication: result × param_2 and result × param_3 → stored in param_1[0:1]
- Calls FastExitMediaState() to restore FPU/MMX state

**Globals:**
- `DAT_005af988` — SIMD constant (used in reciprocal computation)
- `DAT_005af9d0` — SIMD sign mask (bitwise AND for sign correction)
- `DAT_005af9e8` — SIMD comparison threshold for iteration gating

**Calls:** FastExitMediaState, PackedFloatingMUL, PackedFloatingADD, PackedFloatingSUB, PackedFloatingAccumulate, PackedFloatingCompareGE, PackedFloatingReciprocalSQRAprox, PackedFloatingReciprocalIter1/Iter2, FloatingReciprocalAprox, FUN_00528f00, FUN_00529700

**Moddability:** `hardcoded` — SIMD math leaf function, uses constants

<!-- target: docs/10-vehicle-physics.md -->
### FUN_0051E2BA — Image Buffer Stride Fill

Fills a destination buffer with repeated pattern data using stride-based division. Processes pixel/byte array with inner loops over rows and columns, computing fill values from position and iteration index.

**Key logic:**
- Reads unaff_ESI[0x69] as source struct pointer, reads unaff_ESI[0x19] as dimension count
- Branch on unaff_ESI[0x19] == 3: sets pattern mode to 0x5d, copies 3 source values to dest header
- Branch else: sets pattern mode to 0x5e
- Calls virtual function via vtable dispatch: (**(code **)(*unaff_ESI + 4))()
- Allocates working buffer via virtual call on unaff_ESI[1]+8
- Nested loop: iterates over dimensions (unaff_ESI[0x19] count), computing fill value `(iVar1/2 + iVar8) / iVar1` for each cell
- Writes computed byte values into destination buffer at calculated offsets
- Stores result pointer and byte count back to source struct at +0x10 and +0x14

**Struct offsets (unaff_ESI):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | VTablePtr | Virtual method table |
| +0x04 | SecondaryPtr | Secondary object with vtable at +8 |
| +0x14 | ModeValue | Pattern mode (0x5d or 0x5e) |
| +0x18 | ByteCount | Bytes to process |
| [+0x19]×4 | DimensionCount | Number of dimensions for stride loop |

**Calls:** FUN_0051e1ef, virtual dispatch via vtable

**Moddability:** `hardcoded` — pixel processing utility
