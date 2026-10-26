## PlayerFileInit_004b0540 — PlayerFileLoadAndInit

**Summary:** Loads a player file by opening an audio stream on the file path, then initializes game subsystems: parses scene data, computes vehicle count from scoring, builds vehicle arrays, loads auto-load entries, and runs 5-step init — all conditioned on environment flags (wet/dry) and internal state flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringCopyFileCheckDispatch (004b04e0), PlayerFile_Setup (004b1870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x114 | RW | 1 | file-readonly flag (set to 1 if file attribute has FILE_ATTRIBUTE_READONLY bit set) |
| this | 0x138 | R | — | scene data file path string pointer — passed to SceneDataParser |
| this | 0x1B4 | R | — | file path string pointer — passed to ShortComputation_5730 for memory cleanup list |
| this | 0x1F00 | RW | — | boolean flag: set to 1 if >0 (normalized to truth value) |
| this | 0x1F78 | R | — | game mode identifier — if == 5, vehicle count forced to 0 |
| this | 0x2ED8 | R | — | boolean flag (this+11992): if set, clamps 0x2F8C to minimum 33 |
| this | 0x2F08 | R | — | boolean flag (this+12040): if set, clamps 0x2F8C to minimum 34 |
| this | 0x2F8C | RW | 33 | minimum value/clamp target (this+12172): set to 34 or 33 based on boolean flags at 0x2F08/0x2ED8 |

**Written-by note (persistence):**
- this 0x114: written once during file load init — external poke overwritten on next init
- this 0x1F00: written once during file load init — external poke overwritten on next init
- this 0x2F8C: written once during file load init — external poke overwritten on next init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d8 | GetFileAttributesA | R | Win32 API: checks file attributes to detect if file is read-only |
| 005c329c | dword_5C329C | W | VehicleCount — set to computed value from scoring gate (clamped 1-104), or 0 if game mode == 5 |
| 005ea438 | byte_5EA438 | R | default application directory fallback (empty string), used when path pointers are NULL |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 — passed to ShortComputation_5730 for cleanup operations |
| 005ec6d0 | unk_5EC6D0 | R | unknown reference — passed to SceneDataParser context |
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 — passed to AutoLoadEntryListLoader |
| 007cb710 | byte_7CB710 | R | environment flags — bit 0 tested: if set (wet conditions), sub_4AE750 called with mode=2; else mode=1 |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415730 | ShortComputation_5730 | Performs computation on memory cleanup list with file path |
| 0042bc10 | ScoringGateCheck | Computes scoring/points value used to determine vehicle count |
| 0042bc80 | BuildActiveVehiclePointerArray | Builds array of active vehicle pointers for race simulation |
| 00432e70 | AutoLoadEntryListLoader | Loads entries from device identity handle |
| 004a1d10 | LinkedListWalker | Walks a linked list on the player struct using provided context struct |
| 004ae750 | sub_4AE750 | Sets up mode (1 = dry, 2 = wet) based on environment flag bit 0 |
| 004b0720 | F_5StepInit | Runs 5-step initialization sequence on the player struct |
| 004b0ef0 | sub_4B0EF0 | Called with the game mode identifier (this+0x1F78) as argument |
| 004c5690 | SceneDataParser | Parses scene data file at given path with additional context |
| 005668b0 | ZeroInitSmallStruct | Zero-initializes a small stack struct used for linked list walking |
| 005668d0 | SubCallWithConditionalFieldFree | Conditionally frees fields in the init struct (cleanup) |
| 00566b20 | AudioStreamOpen | Opens an audio stream on the file path — success indicates valid player file |
| 00568620 | sub_568620 | Pre-initialization alloc/setup call (argument 512) |
| 00568910 | sub_568910 | Cleanup/deinit call matching sub_568620 (argument 512) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1F00 | > | 0 | boolean normalization: if value > 0, set to 1 |
| this | 0x1F78 | == | 5 | game mode check: if mode is 5, vehicle count forced to 0 |
| this | 0x2F8C | < | 34 | lower-bound clamp: if flag at 0x2F08 is set and value < 34, clamp to 34 |
| this | 0x2F8C | < | 33 | lower-bound clamp: if flag at 0x2ED8 is set and value < 33, clamp to 33 |

**Guard interpretation:** The function first attempts to open an audio stream on the file path — this is the primary gate: if AudioStreamOpen fails, SubCallWithConditionalFieldFree cleans up and returns -1. If it succeeds, the function proceeds through full initialization. The boolean flags at 0x2ED8 and 0x2F08 enforce minimum clamp values (33 and 34) on the field at 0x2F8C. The game mode field at 0x1F78, if equal to 5, overrides the computed vehicle count to 0. All other guards are clamp/normalize operations, not early-return blocks.