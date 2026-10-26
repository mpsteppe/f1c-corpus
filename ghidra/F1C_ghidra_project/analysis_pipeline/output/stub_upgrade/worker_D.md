=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042db20 — Game::Exit()

Full game teardown. Sets state to 7 (exit), logs entry, calls shutdown sequence for all subsystems.

**Key logic:**
- Writes `*param_1 = 7` — transitions game state to Exit
- Logs "Entered Game::Exit()" via debug channel
- Calls exit/cleanup: Sound::Exit, render shutdown, string cleanup (×2), HWInput::Exit, game vars cleanup, OnScreen::Exit, VidMan::Exit, UI manager, game state machine, session cleanup

**Calls:** FUN_004c8d00 (Sound::Exit, docs/01), FUN_004cfff0, FUN_004b0170 (string buffer), FUN_00455f00 (HWInput::Exit, docs/01), FUN_0042ca70, FUN_004ba770, FUN_0049f120 (OnScreen::Exit), FUN_004fad00 (VidMan::Exit, docs/01), FUN_00464670, FUN_0042d350, FUN_004a1930

<!-- target: docs/01-engine-architecture.md -->
### FUN_004c8b20 — Sound::Restart()

Restarts the sound system. Logs entry, calls sound subsystem restart and audio manager re-init.

**Key logic:**
- Logs "Entered Sound::Restart()" from sound.cpp line 0x2b6
- Calls sound buffer restart (FUN_004c8630), sound channel reset (FUN_004c7dd0), audio manager init (FUN_004186a0)

**Calls:** FUN_004c8630 (sound buffer restart), FUN_004c7dd0 (sound channel reset), FUN_004186a0 (audio manager init)

<!-- target: docs/01-engine-architecture.md -->
### FUN_00455c60 — HWInput::Setup()

Initializes DirectInput for the hardware input subsystem.

**Key logic:**
- Skips debug log if `DAT_007c569c == 5` (server mode — no local input)
- Calls `DirectInput8Create(DAT_007ce2a0, 0x800, &DAT_005ad4a0, param_1, 0)` to create DirectInput device
- On failure (return != 0): calls DirectInput cleanup functions (FUN_0044ee10, FUN_0044fa60×3, FUN_0044fbe0×2, FUN_004533a0)

**Globals:**
- `DAT_007c569c` — SessionType5 (5=server)
- `DAT_007ce2a0` — DirectInput instance handle
- `DAT_005ec4a4` — input config path
- `DAT_007ce2dc` — DirectInput device pointer

**Calls:** DirectInput8Create, FUN_0044ee10, FUN_0044fa60, FUN_0044fbe0, FUN_004533a0

<!-- target: docs/01-engine-architecture.md -->
### FUN_004fad00 — VidMan::Exit()

Shuts down the video manager. Logs entry, tears down renderer resources, releases device handle.

**Key logic:**
- Logs "Entered VidMan::Exit()" from vidman.cpp line 0x5b1
- Calls: texture manager cleanup, specialized renderer shutdown, memory cleanup (×2), scene object release
- If `DAT_008afe64` (display device handle) non-zero: calls FUN_0053d4c0 (device release) and sets to 0

**Globals:**
- `DAT_008afe64` — display device handle (cleared on exit)

**Calls:** FUN_00494900 (texture manager), FUN_0055c040, FUN_004a1830×2 (memory cleanup), FUN_004a14e0 (scene object release), FUN_0053d4c0

<!-- target: docs/01-engine-architecture.md -->
### FUN_004a0eb0 — Options::Setup()

Options menu main loop. Displays options screen, processes keyboard input, handles mode switching.

**Key logic:**
- Logs "Entered Options::Setup()" from options.cpp
- If `DAT_007ce260` == 0 (not in special init mode):
  - Sub-mode 0: enters menu loop — processes frame timing (FUN_004f9f00), renders UI (FUN_004537b0), increments frame counter (DAT_007ce250), checks keyboard (FUN_00485b90), dispatches frame (FUN_004186f0), calls UI/input handlers (FUN_004f9ad0, FUN_00404b60). Exits on DAT_007ce25c flag or ESC (key -1) or Enter (key 1).
  - Sub-mode non-0: checks DAT_005ccfe4 flag, clears and exits if set. Returns 1 otherwise.
- If DAT_007ce260 != 0: sets DAT_007c5690 = 1 (init state), returns 0.

**Globals:**
- `DAT_007ce260` — options init guard
- `DAT_007ce264` — sub-mode selector
- `DAT_007ce250` — frame counter
- `DAT_007ce25c` — exit flag
- `DAT_005ccfe4` — sub-mode exit flag
- `DAT_007c5690` — init state flag

**Calls:** FUN_004f9f00 (frame timing), FUN_004537b0, FUN_00485b90 (keyboard input), FUN_004186f0, FUN_004f9ad0, FUN_00404b60, FUN_004a1830

<!-- target: docs/09-track-system.md -->
### FUN_004a24d0 — Pit Crew Animation String Mapper

Maps pit crew animation name strings to byte action codes for the pit system.

**Key logic:**
- Linear string comparison against 24 pit crew animation names
- Returns byte code 0x00–0x17 corresponding to each animation:
  - 0x00=FRONT_JACK_UP, 0x01=FRONT_JACK_DOWN, 0x02=REAR_JACK_UP, 0x03=REAR_JACK_DOWN
  - 0x04=LOLLIPOP_DOWN, 0x05=LOLLIPOP_UP, 0x06=FUEL_IN, 0x07=FUEL_OUT
  - 0x08=FRONT_LEFT_WHEEL, 0x09=FRONT_RIGHT_WHEEL, 0x0A=REAR_LEFT_WHEEL, 0x0B=REAR_RIGHT_WHEEL
  - 0x0C=REAR_RIGHT_WHEEL2, 0x0D=10SEC_LOLLIPOP_DOWN, 0x0E=10SEC_LOLLIPOP_UP
  - 0x0F=10SEC_FMAN_FLEFT, 0x10=10SEC_NMAN, 0x11=10SEC_RMAN
  - 0x12=10SEC_RMAN2, 0x13=10SEC_SMAN, 0x14=10SEC_SMAN2
  - 0x15=10SEC_SMAN3, 0x16=10SEC_SMAN4, 0x17=10SEC_STARTERREAR
- Falls through all comparisons; if last match fails, returns 0x17 (STARTERREAR as default)
- Called by FUN_00589901 (string preprocess)

**Calls:** FUN_00589901 (string preprocessing)

**Moddability:** `configurable` — animation name strings from pit crew definition files

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004d75d0 — Tire Slip Curve Name Lookup

Linear search through tire brand's slip curve array for a matching name string. Used to resolve curve references from vehicle setup files.

**Key logic:**
- param_1 = tire manager struct: +0x8 = curve count, +0xc = pointer array (stride 0x18)
- param_2 = curve name string to find
- Iterates curves, calls FUN_00588410 (strcmp equivalent) to compare names
- Falls back to DAT_005ea438 if curve pointer is NULL
- Returns pointer to matching curve entry (base + index × 0x18), or 0 on failure
- On failure: logs "Tire brand doesn't have curve name %s" warning

**Globals:**
- `DAT_005ea438` — fallback directory/file path pointer

**Calls:** FUN_00588410 (string compare), FUN_004d7a50 (debug logging), FUN_004d7aa0 (trace output)

**Moddability:** `configurable` — curve names from tire brand .svm files

<!-- target: docs/10-vehicle-physics.md -->
### FUN_00441bb0 — Rigid Body Torque Accumulation

Computes cross-product torque from suspension forces and accumulates into body angular velocity.

**Key logic:**
- Reads body A pointer at param_1+0x15f0, body B pointer at param_1+0x1d4
- Gets orientation matrix via FUN_00435e00(param_1+0x1bc)
- Computes inertia scaling factor: `SQRT(damping * stiffness) * scale` from body fields at +0xac, param_1+0x1d8, +0x1e0
- Computes cross-product torque for X, Y, Z axes from force offset × force vectors using orientation matrix rows
- Applies linear spring/damper forces from offset terms
- Accumulates into body angular velocity at +0x134, +0x13c, +0x144
- Calls FUN_00569b70 (numerical integration) to step state

**Struct offsets (body struct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x14 | PositionOffset | double, 3rd component |
| +0x6c | ForceTermY | double |
| +0x74 | ForceTermZ | double |
| +0x7c | OrientationRowX | double |
| +0x84 | OrientationRowY | double |
| +0x8c | OrientationRowZ | double |
| +0x100 | SpringOffset | double |
| +0x134 | AngularVelAccumX | double |
| +0x13c | AngularVelAccumY | double |
| +0x144 | AngularVelAccumZ | double |

**Calls:** FUN_00435e00 (orientation matrix extract), FUN_00569b70 (numerical integration)

**Moddability:** `hardcoded`
