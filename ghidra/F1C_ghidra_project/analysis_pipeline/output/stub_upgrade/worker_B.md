=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042d6b0 — Game::Init

Source: game.cpp. Sets game state machine to state 3, then calls all major subsystem initialization functions. Returns 0 on success, 1 if VidMan::Init fails.

**Key logic:**
- Sets `*param_1 = 3` (Game state 3 = Init)
- Calls FUN_004d7a50/7aa0 for scoped logging
- Calls FUN_004ba1f0 (replay/load state init)
- Calls FUN_004fa320 (VidMan::Init) — if non-zero return, abort with error code 1
- Calls subsystem inits in sequence: sound init (FUN_004c8ae0), physics (FUN_004040a0), file paths (FUN_004b0170), timers (FUN_004d38f0), hardware input (FUN_00455d50), special effects (FUN_004cf070), game state (FUN_0042c1a0), replay (FUN_0040c920), on-screen display (FUN_0049efa0), HUD (FUN_004b4030), pit UI (FUN_004a40e0), menu (FUN_00463f70)
- Returns 0

**Calls:** FUN_004ba1f0 (replay init), FUN_004fa320 (VidMan::Init, docs/01), FUN_004bdc10, FUN_004fcaa0, FUN_004040a0, FUN_004b0170, FUN_004d38f0, FUN_00455d50 (HWInput::Init, docs/01), FUN_004cf070 (SpecialFX::Init, docs/09), FUN_0042c1a0, FUN_0040c920, FUN_004c8ae0 (Sound::Init, docs/01), FUN_004b4030, FUN_004a40e0, FUN_0049efa0 (OnScreen::Init, docs/01), FUN_004a1830, FUN_00463f70

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_004c8ab0 — Sound::Setup

Source: sound.cpp. Log-only entry function. Part of the Sound Manager module lifecycle (state 2/Setup phase).

**Key logic:**
- Calls FUN_004d7a50 for assertion/scope entry
- Calls FUN_004d7aa0 for log message if assertions enabled
- No other operations

**Calls:** FUN_004d7a50 (assert/scope), FUN_004d7aa0 (log)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_0049f120 — OnScreen::Exit

Source: onscreen.cpp. Log-only cleanup function. Part of the OnScreen Manager module lifecycle (state 7/Exit phase).

**Key logic:**
- Calls FUN_004d7a50 for assertion/scope entry
- Calls FUN_004d7aa0 for log message if assertions enabled
- No other cleanup operations

**Calls:** FUN_004d7a50 (assert/scope), FUN_004d7aa0 (log)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_004fa640 — VidMan::Restart

Source: vidman.cpp. Pauses game and reconfigures render state based on current session type. Handles formation lap gate for race sessions.

**Key logic:**
- Calls FUN_0042d210(0) to pause game execution
- Switches on `DAT_007c56a4` (SessionType):
  - Cases 0-4 (practice): enables render state 0x40, disables 0x80
  - Case 5 (server): enables render state 0x40, enables 0x80
  - Cases 6-7 (quali/race): enables 0x40 and 0x80, conditionally 0x100
  - Race (7) specific: if ScoringGate != 2 AND HUD enabled AND network session OK, calls FUN_0042d210(1) to resume (formation lap gate)
  - Default: disables 0x40, 0x80, 0x100
- Calls FUN_004f9fc0(0), resets globals `DAT_008afea8`, `DAT_008afeac`, `DAT_008afe84`
- Calls FUN_004f8f10 (renderer callback) and FUN_004f9f70(0)

**Globals:**
- `DAT_007c56a4` — SessionType (7=race, 6=quali, 0-5=practice)
- `DAT_008ab6e4` — ScoringGate (skip if 2)
- `DAT_007ce254` — DisableHUDFlag

**Calls:** FUN_0042d210 (game pause/resume), FUN_0054a200 (render state set), FUN_00404f10, FUN_00461db0, FUN_004f9fc0, FUN_004f8f10, FUN_004f9f70

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_004a18d0 — OSMan::Enter

Source: osman.cpp. Creates named mutex to enforce single application instance (prevents multiple F1 Challenge 99-02 processes).

**Key logic:**
- Calls FUN_004d7a50/7aa0 for scoped logging
- Creates mutex with name "F1 Challenge 99-02_APP_MUTEX" via CreateMutexA
- If mutex handle is valid, checks GetLastError():
  - If ERROR_ALREADY_EXISTS (0xB7): mutex already held by another instance → return 1 (failure)
  - Otherwise: first instance → return 0 (success)
- Stores mutex handle in `DAT_007ce2d8`

**Globals:**
- `DAT_007ce2d8` — mutex handle (new)

**Calls:** CreateMutexA (Win32 API), GetLastError (Win32 API), FUN_004d7a50 (assert/scope), FUN_004d7aa0 (log)

**Moddability:** hardcoded

<!-- target: docs/09-track-system.md -->
### FUN_00421cd0 — Config.ini Parser / Initial Setup

Source: Unknown. Complex initialization function that detects Windows version (XP/NT/2000), copies Config.ini to Documents folder on first run, parses VERSION/IPADDRESS/VCRFILE/VCRCYCLE settings, and dispatches component setup via result-code-driven state machine.

**Key logic:**
- Detects Windows version by comparing OS version string against "Windows XP", "Windows NT", "Windows 2000"
- On XP/NT/2000: calls FUN_00423250 (admin check). If not admin, gets special folder path (CSIDL_DOCUMENTS=5) via SHGetSpecialFolderPathA, copies Config.ini to user documents folder on first launch
- Dispatches to ~20+ component setup functions via FUN_00587ca0/FUN_005651b0 state machine loop with 40+ branching paths (setting fields at extraout_ECX+ offset 0xb8–0xe8)
- Key settings parsed: system version, IP address, VCR file, VCR cycle from Config.ini sections

**Calls:** FUN_005881c0, FUN_004230c0, FUN_00423250, SHGetSpecialFolderPathA (Win32 SHFolder API), CopyFileA, FUN_0058ba75, FUN_00566650, FUN_0058815f, FUN_00589671, FUN_00587db0, FUN_00422be0, FUN_004d7a50, FUN_00587ca0, FUN_005651b0, FUN_00587c20, FUN_00565520, FUN_0058850f, FUN_005654a0, FUN_00565760, FUN_00404ef0, FUN_00404e60, FUN_00404d50, FUN_00404d30, FUN_00404cc0, FUN_00404d40, FUN_00421ad0, FUN_00421ab0, FUN_00421af0, FUN_00421b10, FUN_00421a70, FUN_00421a50, FUN_004219b0, FUN_00421a90, FUN_00421a30, FUN_00421a10, FUN_004219f0, FUN_004219d0, FUN_00421990, FUN_00421970, FUN_00421950, FUN_00421930, FUN_00421910, FUN_004218f0, FUN_004218d0

**Moddability:** hardcoded

<!-- target: docs/09-track-system.md -->
### FUN_004cfff0 — SpecialFX::Exit

Source: specialfx.cpp. Log-only exit function. Part of SpecialFX module lifecycle (state 7/Exit phase).

**Key logic:**
- Calls FUN_004d7a50 for assertion/scope entry
- Calls FUN_004d7aa0 for log message if assertions enabled
- No other cleanup operations

**Calls:** FUN_004d7a50 (assert/scope), FUN_004d7aa0 (log)

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->
### FUN_0040ef70 — Physics State Vector Conversion

Source: Unknown. Mode-switched state vector processing — converts float vectors to double, calls transform/math functions, copies results back. Already fully documented in docs/18-physics-dynamics.md (FUN_0040ef70).

**Key logic:**
- Switch on mode at param_1+0x1c (cases 0/1/2/3/4/5, paired into 0/2/4 and 1/3/5)
- Sets output values at target buffer +0x20 and +0x24
- Copies 6 float values to target buffer, converts to double for sub-calls
- Calls FUN_0054b4d0 (6-float transform), FUN_005691d0, FUN_00569280 (math functions)
- Copies 6 more floats to param_2+0x19
- Calls FUN_0040f0d0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1c | Mode | processing mode 0-5 |
| +0x20 | DataPtr | target data struct pointer |

**Globals:**
- `DAT_0059e6f8` — offset value added in mode processing

**Calls:** FUN_0054b4d0 (6-float transform), FUN_005691d0, FUN_00569280, FUN_0040f0d0

**Moddability:** hardcoded

**Note:** See full entry in docs/18-physics-dynamics.md
