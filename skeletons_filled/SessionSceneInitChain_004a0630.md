## SessionSceneInitChain_004a0630 — SessionSceneInitChain

**Summary:** Initializes session scene: places multiplayer vehicles (phase 1), allocates node list, checks array init, loads track scene via settings path (with fallback to default directory), resets sound system, initializes buffer defaults, and calls sub-initializer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMode (0046d6d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr [DERIVED] (also: ` — engine interface pointer) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186a0 | BufferInitWith10fDefaults | Initializes buffer with 10f default values |
| 0042cf10 | MultiplayerVehiclePlacement | Places multiplayer vehicles for phase 1 |
| 004a09f0 | sub_4A09F0 | Session scene sub-initializer |
| 004c2780 | NodeAllocListInsert | Allocates and inserts node into list |
| 004c2810 | ArrayCheckInit | Initializes array bounds check structure |
| 004c55b0 | TrackSceneLoader | Loads track scene from path string |

**Guard conditions:** dword_7CE5EC null fallback to byte_5EA438 (default directory); dword_5EB10C sound guard — non-null calls sound interface vtable+12
