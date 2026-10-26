=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042C170 — DynMan::Setup

Trace entry stub for dynamic manager setup. Logs "Entered DynMan::Setup()".

**Key logic:**
- Calls FUN_004d7a50 (assert/trace gate) with source path and line number
- If gate passes, calls FUN_004d7aa0 to log entry trace string

**Calls:** FUN_004d7a50 (trace gate, docs/21), FUN_004d7aa0 (trace log, docs/21)

<!-- target: docs/01-engine-architecture.md -->
### FUN_0042C1A0 — DynMan::Init

Initializes dynamic management system. Handles vehicle grid setup, session-dependent init paths, and per-vehicle UI setup.

**Key logic:**
- Iterates vehicle grid array DAT_005ef9a0 (stride 0x1230) up to 104 entries
- If RaceMode != 4 (championship), sets grid entry at +0x364 to slot index+1
- On empty slot or end, calls error handlers FUN_0042bbd0/FUN_0042bc40 if no vehicles found
- Branches on DAT_007c5690 (InitStateFlag): if 0, loads config via FUN_004b1520 then either race init (FUN_004bfd90, FUN_004bff70) or practice path
- If InitStateFlag != 0 and RaceMode == 4 (championship) and SessionType 1-4 (practice), calls FUN_004c01a0
- After init, iterates VehicleCount (DAT_005c329c) calling FUN_004c6c40 per vehicle
- If CurrentVehicleIndex (DAT_007c54e4) valid (0-0x67) and field +13000 == 0, calls FUN_004336f0

**Globals:** DAT_007d0410 (RaceMode), DAT_007c56a4 (SessionType), DAT_007c5690 (InitStateFlag), DAT_007cebc4 (FormationLap), DAT_005c329c (VehicleCount), DAT_007c54e4 (CurrentVehicleIndex), DAT_007c54f0 (VehiclePtrArray), DAT_005ef9a0 (VehicleGridArray)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_0040fe50, FUN_0042bbd0, FUN_0042bc40, FUN_004b1520, FUN_004bfd90, FUN_004bff70, FUN_004c01a0, FUN_0042bc80, FUN_005895a2, FUN_004f9480, FUN_004c6c40, FUN_004326e0, FUN_004336f0

**Moddability:** `hardcoded`

<!-- target: docs/01-engine-architecture.md -->
### FUN_0042C9F0 — DynMan::Post

Post-update processing for dynamic manager. Called after main update loop.

**Key logic:**
- Iterates all vehicles (VehicleCount DAT_005c329c) calling FUN_004c6e80 per vehicle
- Calls FUN_0043e230 (generic post-update)
- Calls FUN_0042bd60 (game state machine)
- Calls FUN_0040fb30 (memory/allocator cleanup)

**Globals:** DAT_005c329c (VehicleCount)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_004c6e80, FUN_0043e230, FUN_0042bd60 (Game::Post, docs/01), FUN_0040fb30

<!-- target: docs/01-engine-architecture.md -->
### FUN_004C8D00 — Sound::Exit

Sound module exit/cleanup. Shuts down sound subsystem.

**Key logic:**
- Calls FUN_00411740(1) and FUN_00411740(0) with channel IDs
- Calls FUN_00418900 (general cleanup)
- Calls FUN_004c8630 and FUN_004c8350 (sound tear-down)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_00411740, FUN_00418900, FUN_004c8630, FUN_004c8350

<!-- target: docs/01-engine-architecture.md -->
### FUN_0049EF40 — OnScreen::Enter

Empty trace-entry stub for OnScreen module. Logs "Entered OnScreen::Enter()".

**Key logic:**
- Calls FUN_004d7a50 (assert/trace gate), logs entry trace if gate passes
- No other logic — pure debug trace function

**Calls:** FUN_004d7a50 (trace gate, docs/21), FUN_004d7aa0 (trace log, docs/21)

<!-- target: docs/01-engine-architecture.md -->
### FUN_0049EFA0 — OnScreen::Init

Initializes on-screen display system (HUD, text overlays).

**Key logic:**
- Calls FUN_004d8220 (UI/widget pool init)
- If VehicleCount > 0, calls FUN_0049ca00 (vehicle HUD setup)
- Calls FUN_0045bbe0 (bitmap/texture load for UI)
- Calls FUN_0049b0a0 (HUD render state init)

**Globals:** DAT_005c329c (VehicleCount)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_004d8220, FUN_0049ca00, FUN_0045bbe0, FUN_0049b0a0

<!-- target: docs/01-engine-architecture.md -->
### FUN_00455DA0 — HWInput::Restart

Restarts hardware input system (keyboard/joystick/wheel). Resets input device state.

**Key logic:**
- Skips trace log if SessionType5 (DAT_007c569c) == 5 (server mode)
- Calls FUN_0044f680 with device parameter buffers (DAT_005d6d60, DAT_005d6d64)
- Calls FUN_0044f0a0 (input device reset)
- If DAT_007d1ffc (AudioQualityLevel) != 0, calls FUN_0044ff50 (audio mixer)
- Sets byte at param_1+0x2428 to 0 or 1 based on scan of input device struct at +0x1f98 checking for non-zero entries paired with 0x59

**Globals:** DAT_007c569c (SessionType5), DAT_007d1ffc (AudioQualityLevel), DAT_005d6d60, DAT_005d6d64

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_0044f680, FUN_0044f0a0, FUN_0044ff50 (audio mixer)

<!-- target: docs/01-engine-architecture.md -->
### FUN_00455E70 — HWInput::Post

Post-update processing for hardware input. Releases input devices and cleans up.

**Key logic:**
- Skips trace log if SessionType5 == 5 (server mode)
- Calls FUN_0044f070(1) (device close)
- If param_1[0x665] != 0, calls FUN_004526c0 (force feedback / haptic cleanup)
- Calls FUN_0044fbe0 (input buffer flush) twice
- Calls FUN_0044efe0 (keyboard state cleanup)
- Checks if param_1[0] (vtable/device ptr) is non-null, calls virtual method at vtable+8 (release), then zeros the pointer

**Globals:** DAT_007c569c (SessionType5)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_0044f070, FUN_004526c0, FUN_0044fbe0, FUN_0044efe0

<!-- target: docs/01-engine-architecture.md -->
### FUN_004FA000 — VidMan::Enter

Video manager initialization. Detects display device, may launch 3DCONFIG.EXE for configuration, then initializes rendering.

**Key logic:**
- Starts timer via FUN_00568be0(1)
- Calls FUN_0053d470 to test Direct3D device; if fails, returns 1
- Reads device name from player file (DAT_005ec488) via FUN_0053d890
- If no device configured, copies "No Device" string
- Compares device name from file with current device handle (DAT_005ec480)
- On match: calls render init chain (FUN_004f9160, FUN_004f91b0, FUN_004a1200, FUN_0053c680, FUN_005408f0, FUN_004f9420, FUN_004f9310)
- On mismatch: launches 3DCONFIG.EXE via CreateProcessA and returns 1

**Globals:** DAT_005ec488 (PlayerFile), DAT_005ec480, DAT_005ec48c, DAT_005ec4a4, DAT_005ec4b4, DAT_005ea438, DAT_007ce2dc, DAT_007ce2a0, DAT_008afe74

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_00568be0 (timer init), FUN_0053d470, FUN_0053d890, FUN_0053d8e0, FUN_004f9160, FUN_004f91b0, FUN_004a1200, FUN_0053c680, FUN_005408f0, FUN_004f9420, FUN_004f9310, FUN_004f9f00, FUN_005434a0, FUN_0055c060, FUN_004f9f30, FUN_00494690, FUN_00422be0, CreateProcessA (Win32)

**Moddability:** `hardcoded` — reads device config from player file

<!-- target: docs/01-engine-architecture.md -->
### FUN_004B4060 — Render::Restart

Render module restart. Fills render context structure with default values.

**Key logic:**
- Fills 0x68 bytes (26 ints) of param_1 with 0x01010101 (default initializer)
- No other operations — pure state reset

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log)

<!-- target: docs/01-engine-architecture.md -->
### FUN_004B40A0 — Render::ScreenSave

Saves screenshot to file. Checks input device state for screenshot key ('X' marker) and writes screen capture.

**Key logic:**
- Iterates DAT_007cb21c array (count in DAT_007cb218) looking for entries == 0x58 ('X')
- When found, saves screenshot via FUN_00551fd0 to path from DAT_005ec478 (or DAT_005ea438 fallback)
- Writes "Screen Saved" message to message buffer (DAT_005ec4cc) and displays via FUN_0045bd10
- Posts screen save via FUN_004fbd70 (buffer swap), FUN_004b3dc0 (render flush), FUN_00557120

**Globals:** DAT_007cb218, DAT_007cb21c, DAT_005ec478, DAT_005ea438, DAT_008b8dd4, DAT_008b8dd8, DAT_005ec4cc (MessageBuffer)

**Calls:** FUN_00551fd0, FUN_00423a00, FUN_0045bd10, FUN_004fbd70, FUN_004b3dc0, FUN_00557120

<!-- target: docs/01-engine-architecture.md -->
### FUN_0040C920 — CamMan::Init

Camera manager initialization. Sets up camera system with MAINVIEW camera handle.

**Key logic:**
- Gets "MAINVIEW" camera object via FUN_00544f50, stores in param_1
- Zeros camera globals DAT_005ea550/554/558/500/504/508
- Calls camera subsystem inits: FUN_0040c240, FUN_0040c3b0, FUN_0040c520
- Sets byte at param_1+0x2d to 0
- Calls FUN_0040c140; if returns 0, copies param_1[6] into param_1[2]
- Enables render culling via FUN_0054a200(0x20, 1)

**Globals:** DAT_005ea550, DAT_005ea554, DAT_005ea558, DAT_005ea500, DAT_005ea504, DAT_005ea508

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_00544f50, FUN_0040c240, FUN_0040c3b0, FUN_0040c520, FUN_0040c140, FUN_0054a200

<!-- target: docs/01-engine-architecture.md -->
### FUN_004B1870 — PlayerFile::Setup

Sets up player file subsystem. Initializes configuration file I/O.

**Key logic:**
- Calls FUN_004b0770(1) — if returns non-zero, returns true
- Otherwise calls FUN_004b0540(1) and returns its result

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_004b0770, FUN_004b0540

<!-- target: docs/01-engine-architecture.md -->
### FUN_004B18D0 — PlayerFile::Restart

Empty stub for PlayerFile restart. Just logs "Entered PlayerFile::Restart()".

**Key logic:**
- Pure trace entry, no functional logic

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log)

<!-- target: docs/08-file-formats.md -->
### FUN_004C6980 — SetDriverName

Sets driver name string in vehicle struct. Copies name parameter to vehicle DriverName field.

**Key logic:**
- Copies param_2 (driver name) to vehicle struct at offset +0x4620 (DriverName, docs/13) via _strncpy (max 63 bytes)
- Null-terminates at +0x465f
- Calls FUN_004c6a10 (post-name-set processing)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4620 | DriverName | char[64], set via _strncpy with max 63 chars |
| +0x465f | NullTerminator | Always 0 |

**Calls:** FUN_004c6a10

<!-- target: docs/09-track-system.md -->
### FUN_00463160 — NetComm::ParseCommandLine

Parses command-line arguments for network session configuration. Extracts password, autojoin/autohost settings, game name, network name, and max player count.

**Key logic:**
- Reads command line via FUN_00566810 repeatedly, looking for flags: /password, /connect, /gamename, /maxplayers
- Parses `/password <value>` → sets password via FUN_00463710
- Parses `/connect <host:port>` → stores server address at param_1+200, extracts port, sets autojoin flag at +0xc6, appends local address
- Parses `/gamename <name>` → sets autohost flag at +0xc5, stores game name at +0x16c
- Parses `/maxplayers N` → stores at +0x1ac, clamps to [2, 104]
- All paths guard trace output against SessionType5 == 5 (server mode)

**Globals:** DAT_007c569c (SessionType5), DAT_007d1004

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_00566810, FUN_00587c20, FUN_00587ece, FUN_0058815f, FUN_005897ca, FUN_00463710, _strncpy

<!-- target: docs/09-track-system.md -->
### FUN_004CEE90 — SpecialFX::Enter

Empty stub for SpecialFX module. Logs "Entered SpecialFX::Enter()".

**Key logic:**
- Pure trace entry, no functional logic

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log)

<!-- target: docs/09-track-system.md -->
### FUN_004CF070 — SpecialFX::Init

Complex initialization of special effects system. Parses CMAPS.MAS track mapping files and builds per-track effect lists.

**Key logic:**
- Parses track directory from scene array at (CurrentSceneIndex * 0x18c + DAT_008ac490 + 0x104)
- Opens CMAPS.MAS file in season directory via FUN_00587db0
- Scans file sections: TRACKVARS (track variable overrides), FEEDBACK (rumble effects), LOOSE (surface loss effects)
- For each FEEDBACK section, parses REACTION entries with SearchPath/MasFile directives
- Allocates effect arrays (param_1[3] and param_1[5]) with 0x6c-byte stride
- Categorizes effects by type code at +4: 0xc/0xd → param_1[6]/[7], 1 → param_1[8], 3 → param_1[9], 4 → param_1[10]
- Sets up collision grid via FUN_0044c0e0 and FUN_0044c4c0
- Reads AIDryGrip/AIWetGrip from track file for param_1[0xc]/[0xd]
- Enumerates scene nodes for LPTREE tagged objects, allocates tree array at param_1[1]

**Globals:** DAT_008ac48c (CurrentSceneIndex), DAT_008ac490 (SceneArray), DAT_005ec428 (SeasonName), DAT_005ec3d8 (SeasonDir), DAT_005ea438, DAT_0059e440 (ZeroThreshold)

**Calls:** FUN_004d7a50, FUN_004d7aa0, FUN_004ceef0, FUN_00568a60, FUN_00587db0, FUN_00587ca0, FUN_005651b0, FUN_00587c20, FUN_00589db0, FUN_0058850f, FUN_00565520, FUN_00566810, FUN_004c58a0, FUN_004c9d10, FUN_004ca3e0, FUN_004ca480, FUN_004caed0, FUN_004cdd80, FUN_004c9d30, FUN_00587bcf, FUN_0053c800, FUN_0053cbc0, FUN_0053ce40, FUN_0053c900, FUN_004cef30, FUN_0044c0e0, FUN_004024f0, FUN_00403cd0, FUN_0044c4c0, FUN_005452f0, FUN_00545340, FUN_0054bda0, FUN_004c9fb0, FUN_004cb120, FUN_004ca280, FUN_0058815f, FUN_00587f64, FUN_00587d02, FUN_004cdb90, _strncmp

**Moddability:** `configurable` — reads AIDryGrip/AIWetGrip from track files

<!-- target: docs/10-vehicle-physics.md -->
### FUN_00410F60 — SceneNodeDecoder

Decodes packed scene node command and dispatches vertex transform. Reads 6-bit opcode from param_2 header to select data source array, then transforms vertex positions.

**Key logic:**
- Extracts 6-bit opcode from param_2[0] >> 0x12 & 0x3f
- Cases 1-6 select different array sources from param_1 struct (+0x24/+0x2c through +0x60/+0x68)
- Validates index from param_2[2] against array bounds
- Computes data pointer as `index * stride + 0xd0 + base`
- When pointer non-null, calls FUN_0054b4d0 with decoded vertex data (position + normal) scaled by DAT_0059e780 (VertexScaleFactor) and DAT_0059e77c (unknown render scale)
- Byte extraction from packed fields at param_2 offsets +0xa, +0xe, +0x12, +0x13, +0x15, +0x17

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x24 | Size1 | Bounds check for case 1/3/5 arrays |
| +0x2c | BasePtr1 | Data array base for case 1 |
| +0x30 | Size2 | Bounds for case 2 |
| +0x38 | BasePtr2 | Data array base for case 2 |
| +0x3c | Size3 | Bounds for case 3 |
| +0x44 | BasePtr3 | Data array base for case 3 |
| +0x48 | Size4 | Bounds for case 4 |
| +0x50 | BasePtr4 | Data array base for case 4 |
| +0x54 | Size5 | Bounds for case 5 |
| +0x5c | BasePtr5 | Data array base for case 5 |
| +0x60 | Size6 | Bounds for case 6 |
| +0x68 | BasePtr6 | Data array base for case 6 |

**Globals:** DAT_0059e780 (VertexScaleFactor), DAT_0059e77c

**Calls:** FUN_0054b4d0 (scene transform, docs/19)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_0052835F — VectorTransformDSP

Fixed-point vertex transform or DSP mixing function. Performs SIMD-like multiply-accumulate on short arrays with bit manipulation and table lookup.

**Key logic:**
- Reads params from param_1+0x11c (base offset +0x80) and param_2+0x50, param_3+0x30
- First loop (8 iterations): checks short arrays at incrementing offsets; when all zero, uses simple multiply; otherwise computes weighted sum with fixed-point coefficients (0x1b37, -0x1712, 0x73fc, -0x28ba)
- Second loop (2 iterations): writes results to param_4 + param_5, using computed index into lookup table at base offset
- Scaling constants: 0x8000, 0x1000, 0xd (13-bit), 0x14 (20-bit) shift patterns indicate fixed-point math

**Globals:** DAT_0059e780 (VertexScaleFactor)

**Calls:** none (leaf function, no subroutine calls)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004AF220 — TireCompoundClamp

Clamps tire compound selection for vehicle. Selects compound based on mode at +0x1b34 and clamps within allowed range.

**Key logic:**
- Switch on param_1+0x1b34 (mode selector 1-4):
  - Case 1: sets compound at +0xd98 = 12, compound index +0x1170 = 0
  - Case 2: sets compound at +0xd98 = 14, compound index +0x1170 = 1
  - Case 3: sets compound at +0xd98 = 16, compound index +0x1170 = 2
  - Case 4: sets compound at +0xd98 = 16, compound index +0x1170 = 3
- For each case, clamps +0xd98 between lower bound +0xda0 and upper bound +0xda4
- After selection, clamps compound index (+0x1170) between +0x1178 (min) and +0x117c (max)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1170 | CurrentFrontCompoundIndex | docs/13 — per docs/13 tire compound |
| +0x1178 | PitStopCount/MinCompound | Lower bound for compound index |
| +0x117c | MaxCompound | Upper bound for compound index |
| +0xd98 | CompoundSelector | Intermediate compound value |
| +0xda0 | CompoundMin | Lower clamp bound |
| +0xda4 | CompoundMax | Upper clamp bound |
| +0x1b34 | TireMode | Mode selector (1-4) |

**Moddability:** `hardcoded` — compound values (12, 14, 16) are constant

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004C6810 — MergeSortLinkedList

Generic merge sort for linked list. Recursively splits list at midpoint, sorts halves, and merges by comparison via FUN_004c5d30.

**Key logic:**
- Walks list to count nodes (linked via offset +4)
- Splits at midpoint (count/2 - 1)
- Recursively sorts both halves via tail recursion
- Merges using FUN_004c5d30(*first_element) for comparison
- Returns sorted list head

**Struct (linked list node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Key/Data | Passed to comparison function |
| +0x04 | NextPtr | Next node pointer |

**Calls:** FUN_004c6810 (self, recursive), FUN_004c5d30 (comparator)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004C2E20 — MergeSortLinkedListByFloat

Generic merge sort for linked list. Sorts by comparing float value at element+4. Same structure as FUN_004C6810 but uses float comparison.

**Key logic:**
- Walks list to count nodes (linked via offset +4)
- Splits at midpoint
- Recursively sorts both halves
- Merges comparing *(float*)(*node_ptr + 4) — ascending order (<= places first)
- Returns sorted list head

**Struct (linked list node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | DataPtr | Pointer to data element |
| +0x04 | NextPtr | Next node pointer |

**Data element:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x04 | SortKey | float comparison value |

**Calls:** FUN_004c2e20 (self, recursive)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_005418E0 — SoundInstanceInit

Initializes sound instance struct with default parameters. Sets volume, pitch, position, and copies name string.

**Key logic:**
- Sets param_1+4 = 1.0f (volume), +8 = 1000.0f (pitch), +0xc through +0x20 = 0 (position/velocity)
- Calls FUN_00541cd0 (init audio system state)
- Zeros offsets +0x3c through +0x78
- Sets +0x6c = 90.0f, +0x70 = 75.0f (cone angles), +0x74 = 1.0f (cone outside volume)
- Sets +0x7c = LAB_00484848 (function pointer/callback), +0x80 = 0x22 (flags), +0x84 = -1, +0x88 = 1.0f
- Zeros offsets +0x19c through +0x1b8
- Copies null-terminated param_2 string to +0x8c (name/path)
- Zeros 0x60 bytes starting at +0x9c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x04 | Volume | 1.0f default |
| +0x08 | Pitch | 1000.0f default |
| +0x0c | Position | Zeroed (3 floats?) |
| +0x6c | InnerConeAngle | 90.0f |
| +0x70 | OuterConeAngle | 75.0f |
| +0x74 | OuterConeVolume | 1.0f |
| +0x7c | CallbackPtr | Function pointer |
| +0x80 | Flags | 0x22 |
| +0x84 | Unset | -1 |
| +0x88 | Scale | 1.0f |
| +0x8c | NameBuffer | String copy destination |

**Calls:** FUN_00541cd0

<!-- target: docs/10-vehicle-physics.md -->
### FUN_0054F5C0 — SceneBatchRenderCheck

Rendering visibility and batching check. Tests if a rendered object is within draw distance and dispatches to appropriate render path.

**Key logic:**
- Checks param_2+0x3c for flag bit 1; if set, returns early
- Compares render counter (DAT_008c5f40) against capacity from param_1+0x1e0
- If param_2 has flag bit 4 (shadow/alternate): calls FUN_0054b570 to reset batch state
  - Sets iVar6+0x14 bit 0x20000000 if not already set
  - Calls D3D device transform via DAT_008b8f24 vtable+4
- When flag bit 0x40 set on iVar6:
  - Computes distance vector (position differences)
  - If squared distance < (radius)^2 and param_3 has bit 0 set:
    - Dispatches to FUN_0054f2f0 (primary) or FUN_0054eed0 (alternate) based on flag bit 4
    - Increments render counter DAT_008c5f40 and returns 0
- Returns 1 if render capacity exceeded (buffer full)

**Globals:** DAT_008c5f40 (render batch counter), DAT_008b8f24 (D3DDeviceWrapperPtr)

**Calls:** FUN_0054b570, FUN_0054f2f0, FUN_0054eed0
