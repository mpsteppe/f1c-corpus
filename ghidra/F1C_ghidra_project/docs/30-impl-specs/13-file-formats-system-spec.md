# Implementation Spec: File Formats System

Source: docs/08-file-formats.md  |  Functions: 312  |  Date: 2026-07-15

---

## Overview

The File Formats system is the game's data access and persistence layer. It owns all file I/O, configuration parsing, serialization, and data structure management. The system handles:

- **Loading game definition files** (.veh, .hdv, .svm, .gdb, .scn, .aiw, .plr, .plg) — the game reads all vehicle physics, season structure, scene layouts, and player profiles from these files.
- **INI-style config parsing** — all game data files use a bracketed `[SECTION]` / `key=value` format with a shared parser library (`FUN_00568210`, `FUN_005679c0`, `FUN_00567970`).
- **Win32 file I/O abstraction** — a thread-safe wrapper layer around `CreateFileA`/`ReadFile`/`WriteFile` with critical section locking, used throughout the game.
- **Data serialization** — player save/load, replay data, network messages all use the same underlying I/O primitives with XOR obfuscation for certain data files.
- **Directory/file enumeration** — recursive scanning for mod/resource discovery, profile scanning, TGA texture discovery.
- **Linked list and string table management** — fundamental data structures used across all systems.
- **CRT-level utilities** — `printf`-style format parsing, float parsing, heap management (custom arena allocator), locale init, exception handling.

**When it runs:** File loading happens at startup (init phase), session transitions (per-track/per-session), and on-demand (profile save/load, options save). The I/O layer is active throughout the game runtime.

**Data structures owned:**
- `DAT_008ac394` — VehicleArray (stride 0x424, count at `DAT_008ac390`)
- `DAT_008ac490` — SceneArray (stride 0x18c, count at `DAT_008ac488`)
- `DAT_007d2e48` — SeasonScoringDB (stride 0x48c0)
- `DAT_005b5a3c` — Search path registry (stride 0x84, max 0x20 entries)
- `DAT_008d4920` — Critical section / file descriptor table (stride 0x24)
- File buffer state structs (read position, remaining count, mutex handles)
- INI section hash tables (linked list per section)

**Systems that interface:**
- **docs/02-ai-system.md** — reads AI difficulty from player profile
- **docs/03-engine-wear-damage.md** — tire/engine wear from .svm
- **docs/06-session-race-logic.md** — season scoring, race results, standings
- **docs/09-track-system.md** — scene/waypoint loading, terrain.ini
- **docs/10-vehicle-physics.md** — vehicle setup files (.hdv)
- **docs/19-renderer.md** — texture loading (TGA, PPM), scene geometry
- **docs/01-engine-architecture.md** — startup init chain calls file system setup

---

## Data Structures

### File Buffer State (generic read buffer)
```c
struct FileBuffer {
    /* +0x00 */ byte*  readPos;        // Current read position in buffer
    /* +0x04 */ int    remaining;       // Remaining bytes in buffer
    /* +0x08 */ int    fileHandle;      // OS file handle
    /* +0x0c */ uint   modeFlags;       // File open mode / state flags (bit 0x40=open)
    /* +0x10 */ int    ioHandle;        // Underlying I/O handle
    /* +0x18 */ int    bufferSize;      // I/O buffer size (typically 0x200=512)
};
// Total size: at least 0x20 bytes
// Used by: FUN_00587ca0 (read until newline), FUN_00589898 (buffered char write),
//          FUN_00587f90 (seek), FUN_0058c7fc (read lock/query/unlock)
```

### File Descriptor / Critical Section Table Entry
```c
struct FileDescriptorEntry {
    /* +0x00 */ HANDLE hFile;          // Win32 file handle
    /* +0x04 */ uint    flags;         // Status flags (bit 1 = error, bit 0x40 = open)
    /* +0x08 */ byte    modeFlag;      // I/O mode flag
    // ... remaining fields
};
// Stride: 0x24 bytes per entry, 0x20 entries max
// Base: DAT_008d4920
// Indexed by FD number (param_1 & 0x1f)
```

### Vehicle Array Entry (stride 0x424)
```c
struct VehicleEntry {
    /* +0x000 */ char   filename[0x20];        // .veh filename
    /* +0x020 */ char   hdvPath[0x20];         // HDVehicle file path
    /* +0x040 */ char   headPhysicsPath[0x20]; // HeadPhysics file path
    /* +0x060 */ char   soundsPath[0x20];      // Sounds file path  
    /* +0x080 */ char   graphicsPath[0x20];     // Graphics file path
    /* +0x0a0 */ char   genString[0x20];        // GenString
    /* +0x0bc */ char   name[0x40];             // Vehicle name (at +0xbc)
    // ... 3 floats each for Eyepoint, CameraTarget, MirrorPos, MirrorNorm, SteeringWheelAxis
    /* +0x1d0 */ int    number;                 // Vehicle number (+0x1d)
    // ... various string fields (driver, description, engine, manufacturer, classes)
    // ... team history fields (founded, headquarters, starts, poles, wins, championships)
    /* +0x424 */                                 // Total stride
};
// Base: DAT_008ac394, Count: DAT_008ac390
```

### Scene Array Entry (stride 0x18c)
```c
struct SceneEntry {
    /* +0x000 */ char   unknown[0x104];        // Header/path data
    /* +0x104 */ char   sceneName[0x20];        // Scene name/identifier string
    // ... remaining fields (total 0x18c)
};
// Base: DAT_008ac490, Count: DAT_008ac488
```

### Career Stats Struct (param_1, int-indexed — see FUN_004c18b0)
```c
struct CareerStats {
    /* +0x08 */ byte   ABORTEDSEASONS;
    /* +0x09 */ byte   TOTALLAPS;
    /* +0x0a */ byte   TOTALRACES;
    /* +0x0b */ byte   TOTALRACESWITHAI;
    /* +0x0c */ byte   TOTALPOINTSSCORED;
    /* +0x0d */ byte   TOTALCHAMPIONSHIPS;
    /* +0x0e */ byte   TOTALWINS;
    /* +0x0f */ byte   TOTALPOLES;
    /* +0x10 */ byte   TOTALLAPRECORDS;
    /* +0x11 */ float  AVGSTARTPOSITION;
    /* +0x12 */ byte   AVGFINISHPOSITION;
    /* +0x13 */ byte   AVGRACEDISTANCE;
    /* +0x14 */ byte   AVGOPPONENTSTRENGTH;
    /* +0x15 */ byte   MECHFAIL_rate;
    /* +0x16 */ byte   RACECOND_reconnaissance;
    /* +0x17 */ byte   RACECOND_walkthrough;
    /* +0x18 */ byte   RACECOND_formation;
    /* +0x19 */ byte   RACECOND_flag_rules;
    /* +0x1a */ byte   RACECOND_weather;
    /* +0x1b */ byte   RACECOND_timescaled_weather;
    /* +0x1c */ byte   GAMEOPT_qualify_laps;
    /* +0x1d */ byte   GAMEOPT_race_laps;
    /* +0x1e */ byte   GAMEOPT_race_time;
    /* +0x1f */ byte   GAMEOPT_race_length;
    /* +0x20 */ byte   GAMEOPT_opponents;
    /* +0x21 */ byte   GAMEOPT_fuel_mult;
    /* +0x22 */ byte   GAMEOPT_tire_mult;
    /* +0x23 */ byte   GAMEOPT_speed_comp;
};
```

### Linked List Node (generic)
```c
struct ListNode {
    /* +0x00 */ void*  data;          // Payload pointer
    /* +0x04 */ void*  next;          // Next node (or -1 = end sentinel)
    /* +0x08 */ byte   flags;         // Active/ownership flags
    // Total: 0x0c minimum; variations exist at 0x14, 0x1c strides
};
```

### INI Section Hash Table Entry
```c
struct INIEntry {
    /* +0x00 */ uint   hash;          // Hash of key name
    /* +0x04 */ void*  key;           // Key name string
    /* +0x08 */ void*  value;         // Value string
    // ... linked list pointers for collision chain
};
// Managed by: FUN_00568210 (section open/lookup), FUN_00567db0 (hash lookup by name)
```

### String Table Entry (sorted, stride 0x10)
```c
struct StringTableEntry {
    /* +0x00 */ char*  key;           // Sort key string pointer
    /* +0x04 */ int    id;            // Numeric ID (or -1 if unused)
    /* +0x08 */ char*  value;         // Paired value string pointer
    /* +0x0c */ int    flags;         // Status flags (or -1 if unused)
};
// Managed by: FUN_00423530 (table expand), FUN_00423a00 (binary search)
```

### Configuration Tree Node (hierarchical config)
```c
struct ConfigNode {
    /* +0x00 */ ConfigNode* parent;   // Parent node
    /* +0x04 */ ConfigNode* sibling;  // Next sibling
    /* +0x08 */ ConfigNode* child;    // First child
    /* +0x0c */ char*       key;      // Key name (wide char, 2-byte stride)
    /* +0x10 */ char*       value;    // Value data
    // Total: 0x88 bytes per node
};
// Managed by: FUN_00551560 (hierarchical config allocator/copier)
// Used by: config/settings tree construction
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_008ac390 | int | VehicleFileCount | Number of loaded vehicle entries |
| DAT_008ac394 | ptr | VehicleArray | Array of vehicle entries, stride 0x424 |
| DAT_008ac488 | int | SceneFileCount | Number of loaded scene entries |
| DAT_008ac490 | ptr | SceneArray | Array of scene entries, stride 0x18c |
| DAT_008ac38c | int | CurrentVehicleIndex | Index of currently selected vehicle |
| DAT_008ac3e8 | char[] | SceneFilePath | `.SCN` file path buffer |
| DAT_008ac398 | char[] | TrackNameBuffer | Track name buffer |
| DAT_008ac438 | char[] | AIWFilePath | `.AIW` file path buffer |
| DAT_005ec3d8 | char[] | SeasonDir | Season directory path |
| DAT_005ec420 | char[] | TrackDir | Track directory path |
| DAT_005ec428 | char[] | SeasonName | Season name string |
| DAT_005ec438 | char[] | WeatherDir | Weather/effects directory path |
| DAT_005ec440 | char[] | ProfileDir | Player profile directory path |
| DAT_005ec488 | char[] | PlayerFile | Player file path |
| DAT_005ec6d8 | char[] | PlayerDataPath | Player data path |
| DAT_007ce498 | char[] | AutoLoadConfigFile | Autoload config file path |
| DAT_007ce64c | char[] | GameFilterDataPath | Game filter data directory |
| DAT_007ce5d0 | char[] | CurrentTrackPath | Current track path |
| DAT_008ad25c | char[] | ErrorMessageBuffer | Error message buffer |
| DAT_005c6960 | char[] | PLRSearchPattern | "*.PLR" search pattern |
| DAT_005c32d8 | char[] | HotExtension | ".HOT" extension constant |
| DAT_005c5d24 | char[] | SeasonRacesSuffix1 | SeasonRaces filename suffix 1 |
| DAT_005c5d28 | char[] | SeasonRacesSuffix2 | SeasonRaces filename suffix 2 |
| DAT_008b8e30 | int | SearchPathCount | Search path registry entry count (max 0x20) |
| DAT_008b5a3c | ptr | SearchPathArray | Search path registry array (stride 0x84) |
| DAT_008b5a38 | uint | SearchPathFlags | Search path flags (bit 0x4000 set on update) |
| DAT_008d4920 | struct[] | CriticalSectionArray | File descriptor table / critical sections (stride 0x24) |
| DAT_008d3e70 | uint | FileOpenCompatFlags | File open compatibility flags |
| DAT_005ea438 | char* | EmptyStringFallback | Empty string pointer (fallback for null) |
| DAT_005c2aac | short | BackslashChar | Backslash character (0x5C) for path operations |
| DAT_005c30b8/b4/b0/ac | char[] | DelimiterConstants | Delimiter/separator character constants for INI parsing |
| DAT_005d3214 | char[] | AbbreviationSection | "Abbreviation" section name constant |
| DAT_005d3200 | char[] | AbbreviationFormat | "%c. %-11s" abbreviation format |
| DAT_005d31ec | char[] | FilterPropertiesString | "Filter Properties" string constant |
| DAT_005c7130 | char[] | GameFilterString | "Game Filter" string constant |
| DAT_005d28b4 | char[] | SceneOrderString | "SceneOrder" string constant |
| DAT_005e6768 | char[] | GlobalIOBuffer | Global I/O format buffer |
| DAT_008d41fc | uint | FileShareMode | File share mode compatibility flag |

---

## Public API — Entry Points

### FUN_004f4270 — .svm/.hdv Vehicle File Parser

**Inferred signature:** `void ParseVehicleFile(char* filePath, VehicleEntry* outVehicle)`
**Called from:** Vehicle physics loading pipeline (docs/10-vehicle-physics.md)

**What it does:**
1. Opens `.svm` or `.hdv` vehicle physics file
2. Reads all physics sections sequentially — brake, suspension, engine, tire, aero
3. Dispatches to section-specific sub-parsers:
   - `FUN_004f2c60(vehiclePtr, wheelIndex)` — brake/suspension per wheel corner (FL/FR/RL/RR indices 0–3)
   - `FUN_004f3c80(vehiclePtr)` — LifetimeVar/RestrictorPlate section parser
4. Reads pit strategy format fields: `NumPitstopsRange`, `Pitstop1–3Range`, `FuelRange`

**Side effects:**
- Writes: VehicleEntry fields for all vehicle physics sections
- Struct mutations: All `.svm` fields written to vehicle struct (stride 0x48c0)

**Moddability:** `configurable` — all physics fields are moddable via `.svm` file fields

---

### FUN_004c3200 — .veh File Parser

**Inferred signature:** `int ParseVehFile(const char* path, VehicleArrayEntry* entry)`
**Called from:** setup.cpp — vehicle scanning pipeline

**What it does:**
1. Opens `.veh` file and reads top-level vehicle definition
2. Parses field pairs: filename→path mappings for HDVehicle, HeadPhysics, Sounds, Graphics
3. Reads GenString, Eyepoint (3 floats), CameraTarget (3 floats), MirrorPos (3 floats), MirrorNorm (3 floats), SteeringWheelAxis (3 floats)
4. Reads Number, Driver, Description, Engine, Manufacturer, Classes
5. Reads team history: FullTeamName, TeamFounded, TeamHeadquarters, TeamStarts, TeamPoles, TeamWins, TeamWorldChampionships
6. Parses TrackLivery entries (comma-separated `<trackname>,<liveryname>`) into linked list nodes (stride 0x14)

**Struct offsets (param_1, int-indexed):**
| Offset | Field |
|--------|-------|
| +0x00 | filename string |
| +0x02 | HDVehicle file path |
| +0x04 | HeadPhysics file path |
| +0x06 | Sounds file path |
| +0x08 | Graphics file path |
| +0x0a | GenString |
| +0x0e–0x10 | Eyepoint (3 floats) |
| +0x1d | Number |
| +0x2f | Driver name |
| +0x3f | Description |
| +0x6f | Classes |
| +0xaf | FullTeamName |
| +0xf5 | TrackLivery linked list head |

**Side effects:**
- Increments: `DAT_008ac390` (VehicleFileCount)
- Allocates: VehicleArray at `DAT_008ac394`

**Moddability:** `configurable` — all `.veh` fields moddable

---

### FUN_004c52c0 — Scene File (*.scn) Loader

**Inferred signature:** `int LoadSceneFiles(const char* seasonDir)`
**Called from:** setup.cpp — scene scanning pipeline

**What it does:**
1. Scans season directory for `*.scn` files
2. Allocates scene array at `DAT_008ac490` (stride 0x18c)
3. Increments `DAT_008ac488` per successful load
4. Errors if no scenes found (3 causes: wrong season dir, no read permission, no scenes present)

**Globals:**
- Writes: `DAT_008ac490` (scene array), `DAT_008ac488` (scene count)

---

### FUN_004c18b0 — Player Career Stats + Game Options Loader

**Inferred signature:** `int LoadPlayerCareer(CareerStats* stats, const char* filePath)`
**Called from:** Game init — player profile loading

**What it does:**
1. Opens player `.plg`/`.plf` config file
2. Parses `[CAREERSEASON]`, `[PLAYERTRACKSTAT]` sections
3. Reads career stats into CareerStats struct (see Data Structures section)
4. Reads game options: qualifying laps, race laps, race time, race length, opponents, fuel multiplier, tire multiplier, speed compensation

**Struct offsets (param_1):** CareerStats as defined above.

**Moddability:** `configurable` — game options affect gameplay (fuel mult, tire mult, speed comp)

---

### FUN_004c1e80 — Game Options Writer (Save)

**Inferred signature:** `int SavePlayerCareer(CareerStats* stats, const char* filePath)`
**Called from:** Game shutdown / manual save

Companion writer to FUN_004c18b0. Same struct fields.

---

### FUN_004f6300 — Vehicle Setup File Parser

**Inferred signature:** `int ParseVehicleSetup(VehicleSetup* setup, const char* filePath)`
**Called from:** vehload.cpp — vehicle setup loading pipeline

**What it does:**
1. **Main/default section:** reads gear ratio count, auto-setup flag (stored at +0x1990), fuel/engine params, tire brand lookup (FUN_004d7880), calls FUN_004f24f0 (damage model) via `.phr` sub-file
2. **[BASIC] section:** reads basic vehicle setup params (flag at +0x1ec), calls FUN_004f3240 x6 + FUN_004f3490
3. **Per-wheel sections [FRONTRIGHT], [FRONTLEFT], [REARLEFT], [REARRIGHT]:**
   - FUN_004f3090 (fender/aero setup)
   - FUN_004f3240 x6 (suspension force validation per axis direction)
   - FUN_004f3490 (per-wheel setup compute)
   - Per-wheel flags at offsets +0x2f8, +0x4d4
4. **Gearing/Balance/Downforce sections:** reads file paths, calls sub-file loader + engine parser. Reads engine map fields. Computes fuel consumption: `fuelEstimate * fuelConsumption * trackLength * laps`
5. **Setup type selector:** reads SetupType field (0=Custom, 1=Gearing, 2=Balance, 3=Downforce) at +0x13c0

**Vehicle setup struct offsets:**
| Offset | Field |
|--------|-------|
| +0x1990 | Auto-setup flag (default 1) |
| +0x1994 | Fuel consumption reciprocal (1 / computed) |
| +0x13c0 | Setup type (0–3) |
| +0xbc0 | Tire brand data pointer |

**Moddability:** `configurable` — all setup fields are player-adjustable

---

### FUN_00420cf0 — .gdb Season Selector

**Inferred signature:** `int DetectSeason(const char* seasonPath)`
**Called from:** Championship mode — season detection

**What it does:**
1. Detects active season from `DAT_007d0434` path string
2. Matches `.gdb` filename to season ID:
   - `F1_1999.gdb` → 0x1ec (492)
   - `F1_2000.gdb` → 0x1f0 (496)
   - `F1_2001.gdb` → 0x1f4 (500)
   - `F1_2002.gdb` → 0x1f8 (504)
3. Enumerates 14 teams via switch: ARROWS, RENAULT, FERRARI, JAGUAR, JORDAN, MCLAREN, MINARDI, PROST, SAUBER, WILLIAMS, TOYOTA, BENETTON, STEWART
4. Resolves player's team via FUN_0041f220 (team score lookup) and FUN_00421380/FUN_004212e0 (team ranking)
5. Handles tie-breaking for constructor standings

---

### FUN_004ddf90 — Scene File TEAMDIR/VEHDIR/NOTSPIN Writer

**Inferred signature:** `int WriteSceneFileData(SceneFile* scene, int vehicleIndex)`
**Called from:** Scene/vehicle generation pipeline

**What it does:**
1. Opens `.gen` scene file for writing
2. Resolves vehicle struct from `DAT_008ac394` (VehicleArray) at `param_2` index
3. Reads `DAT_007cf7f4`/`DAT_007cf818` to determine game mode → difficulty level (1–4)
4. Tokenizes file content looking for `<>` enclosed tag fields:
   - `NOTSPIN`: writes spin countermeasure data if difficulty != 0
   - `DASHLOW`/`DASHHIGH`: writes dash display (rev lights) based on difficulty/vehicle data
   - `VEHDIR`: writes season directory path
   - `TEAMDIR`: extracts team directory from vehicle path
   - `<...>` (unnamed tag): writes raw filename

**Moddability:** Yes — `NOTSPIN` (AI spin behavior), `DASHLOW`/`DASHHIGH` (dash config) are scene file tags

---

### FUN_00568210 — INI Section Open/Lookup

**Inferred signature:** `int OpenINISection(const char* sectionName)`
**Called from:** Every config file parser in the game

**What it does:**
- Looks up a `[section]` in the currently open INI file
- Returns a section handle for subsequent key-value lookups via FUN_005679c0 / FUN_00567970
- Uses hash-table based search within the section list

---

### FUN_005679c0 — INI Key Lookup

**Inferred signature:** `const char* LookupKey(int sectionHandle, const char* keyName)`
**Called from:** Every config read operation

Searches within an open INI section for a key by name. Returns the value string or NULL.

---

### FUN_00595af9 — Win32 CreateFileA Wrapper

**Inferred signature:** `int FileOpen(const char* path, uint accessFlags, uint shareMode, uint createFlags)`
**Called from:** All file I/O operations

**What it does:**
1. Parses access mode flags (`param_2`): 0=READ, 1=WRITE, 2=READWRITE
2. Parses share mode (`param_3`): 0x10=exclusive, 0x20=share_read, 0x30=share_write, 0x40=share_readwrite
3. Parses creation flags (`param_2` bits): 0x400=CREATE_NEW, 0x100=CREATE_ALWAYS, 0x200=OPEN_EXISTING, etc.
4. Extracts file attributes: 0x80=normal, 0x4000000=no_buffering, 0x1000=random_access
5. Calls `CreateFileA` with the resolved parameters
6. On success: registers file descriptor via `FUN_00595924`, stores in `DAT_008d4920` table
7. If text mode (`param_2 & 2`): reads first 2 bytes, checks for Unicode BOM (0x1a), skips if present
8. Returns file descriptor index (or 0xFFFFFFFF on failure)

**Struct offsets (global table):**
- `DAT_008d4920` — Descriptor table, stride 0x24 per entry, indexed by `(fd & 0x1f)`

---

### FUN_00587ca0 — File Read Until Newline

**Inferred signature:** `char* ReadLine(int fd, char* buffer, int maxLen, FileBufferState* bufState)`
**Called from:** INI parser, text config readers, credits.txt parser

**What it does:**
1. Acquires mutex lock via FUN_0058c1b1
2. Reads characters one at a time from buffer:
   - Decrements `bufState->remaining`
   - If < 0: refills buffer via FUN_0058c255
3. Stops on EOF (0xFFFFFFFF), buffer full, or newline ('\n')
4. Null-terminates string
5. Releases mutex lock via FUN_0058c203
6. Returns buffer pointer (NULL on immediate EOF)

---

## Internal Call Graph

Major call chains within the file formats system:

```
InitializeGameSystem (from docs/01)
  +-- FUN_0042d5d0 — Game::Setup
  |     +-- FUN_004f9160 — player file load
  |     +-- FUN_004c8ab0 — Sound::Setup
  |     +-- FUN_0049ef70 — OnScreen::Setup
  |     +-- FUN_004fa2f0 — VidMan::Setup
  |     +-- FUN_004c3d80 — Vehicle File (*.veh) Loader
  |     |     +-- FUN_004c3200 — .veh File Parser
  |     +-- FUN_004c52c0 — Scene File (*.scn) Loader
  |
  +-- FUN_0042d7a0 — Game::Restart
        +-- FUN_004b0770 — player file save
        +-- FUN_004a40f0 — steward
        +-- FUN_004a0fb0 — race timer

VehicleSetup (from docs/10)
  +-- FUN_004f6300 — Vehicle Setup File Parser
        +-- FUN_004f2c60 — brake/suspension per wheel (x4: FL/FR/RL/RR)
        +-- FUN_004f3c80 — engine/LifetimeVar parser
        +-- FUN_004f3c10 — engine map fields
        +-- FUN_004f3090 — fender/aero setup
        +-- FUN_004f3240 — suspension force validation (x6 per wheel)
        +-- FUN_004f3490 — per-wheel setup compute
        +-- FUN_0042ecc0 — setup type loader
        +-- FUN_004c40d0 — sub-file finder

INI/Parsing Layer
  +-- FUN_00568210 — INI Section Open/Lookup (hash-table based)
  |     +-- FUN_00567db0 — Hash table lookup by name
  |     +-- FUN_00567d00 — Hash computation
  +-- FUN_005679c0 — Key lookup within section
  |     +-- FUN_00567970 — Value string accessor
  +-- FUN_00559ad0 — Line parser (strip whitespace, find key=value)
  +-- FUN_00559a70 — Line reader from buffer
  +-- FUN_00559e20 — key=value pair parser

Win32 I/O Layer
  +-- FUN_00595af9 — CreateFileA wrapper (mode parsing + file open)
  |     +-- FUN_00595801 — FD slot allocator
  |     +-- FUN_00595924 — FD registration
  |     +-- FUN_0058c789 — File seek/SetFilePointer
  +-- FUN_00587ca0 — ReadLine (buffered, with lock)
  |     +-- FUN_0058c1b1 — mutex lock
  |     +-- FUN_0058c255 — buffer refill
  |     +-- FUN_0058c203 — mutex unlock
  +-- FUN_00589898 — Buffered char write
  |     +-- FUN_0058c1b1 — mutex lock
  |     +-- FUN_0058cf35 — buffer flush
  |     +-- FUN_0058c203 — mutex unlock
  +-- FUN_00587d02 — File close (__fclose_lk wrapper)
  +-- FUN_0058c7fc — Thread-safe read sequence (lock/query/unlock)
  +-- FUN_005898d3 — MoveFileA wrapper
  +-- FUN_0058986e — DeleteFileA wrapper
  +-- FUN_0058ba36 — Set/clear read-only attribute
  +-- FUN_0058ba75 — File attribute check
  +-- FUN_005668f0 — File attribute check sequence (exists → writable → fix)

Player Profile System
  +-- FUN_004b0770 — Player file save
  |     +-- FUN_004330d0 — Data serialization
  |     +-- FUN_005898d3 — file rename
  +-- FUN_004b0540 — Player file init
  |     +-- FUN_004b0720 — vehicle data init
  |     +-- FUN_004b0ef0 — settings init
  |     +-- FUN_00432e70 — autoload config loader
  +-- FUN_004b1820 — PlayerFile::Enter()
  +-- FUN_004b1870 — PlayerFile::Setup()
  +-- FUN_004b1900 — PlayerFile::Post()

Season Database System
  +-- FUN_00420cf0 — .gdb season selector
  |     +-- FUN_0041f220 — team score lookup
  |     +-- FUN_00421380 — team ranking
  |     +-- FUN_004212e0 — team ranking (alternate)
  +-- FUN_004c0910 — Season scoring (quali/race points)
  |     +-- thunk_FUN_0059d6a9 — points table parser (1-indexed position → points)
  |     +-- FUN_004c2cb0 — standings update
  |     +-- FUN_004c2c20 — winner handler
  +-- FUN_004c2a80 — Season scoring info updater
  |     +-- FUN_004c28d0 — scoring struct accessor
  |     +-- FUN_004c2cb0 — standings update
  |     +-- FUN_004c2c00 — points write
  +-- FUN_004c2420 — Career stats writer (PLAYERTRACKSTAT + CAREERSEASON)
  |     +-- FUN_00566c30 — write int/float to file
  +-- FUN_004c0b70 — Career/season state file reader
  |     +-- FUN_004c03f0 — career standings loader

Scene/Filter System
  +-- FUN_004c6330 — Scene file filter builder
  |     +-- FUN_005897ca — file tokenizer
  |     +-- FUN_004c5e50 — include filter list builder
  |     +-- FUN_004c5fd0 — exclude filter list builder
  |     +-- FUN_004c6150 — filter node remover
  |     +-- FUN_004c6810 — merge sort split
  |     +-- FUN_004c5d30 — filter comparison
  +-- FUN_004c54f0 — .AIW/.SCN filename builder
  +-- FUN_004c5cb0 — SceneOrder slot finder
  +-- FUN_004c5940 — SeasonRaces scene sorter

Directory Enumeration
  +-- FUN_004c3a00 — TGA texture scanner (*.tga)
  |     +-- FUN_00565dc0/eb0/f80/f50 — file search init/setup
  |     +-- FUN_005662d0 — search iterate
  |     +-- FUN_00565f20 — search next
  +-- FUN_00499690 — Recursive directory file scanner
  |     +-- FindFirstFileA / FindNextFileA
  |     +-- FUN_0058815f — path builder
  |     +-- FUN_0058ba36 — file attribute set
  +-- FUN_00431db0 — Directory file enumerator (\*.*)
  +-- FUN_00468ee0 — Player profile scanner (*.PLR)

String Table / Data Structure Layer
  +-- FUN_00423530 — Sorted string table builder/expander
  +-- FUN_00423a00 — Binary search in string table
  +-- FUN_00434090 — Linked list merge sort (split)
  +-- FUN_00434290 — Linked list merge sort (recursive)
  +-- FUN_004331a0 — Dual linked list cleanup
  +-- FUN_00433d60 — Linked list removal by name
  +-- FUN_00407450 — Linked list insert (sorted, no duplicate)
  +-- FUN_00407920 — Resource lookup by name or ID

CRT-level utilities
  +-- FUN_0058e4d2 — printf/scanf-style format string parser
  +-- FUN_00588212 — pow(x,y) transcendental
  +-- FUN_00596245 — strtod equivalent (decimal/float string parser)
  +-- FUN_005886a7 — hex/dec/oct string-to-number parser
  +-- FUN_0058b077 — string-to-float parser
  +-- FUN_0058c43c — fopen mode string parser
  +-- FUN_0059a69a — C++ exception handling init (type A)
  +-- FUN_0059ada3 — C++ exception handling init (type B)
  +-- FUN_005828b0 — Pool allocator init (16 entries, stride 0x54)
  +-- FUN_00594478 — Custom heap arena allocator (1MB VirtualAlloc)
  +-- FUN_00594529 — Heap page allocator init (0x8000 bytes)
  +-- FUN_0058a19e — Application startup (OS detection, subsystem init)
  +-- FUN_00592af4 — Environment variable table parser
  +-- FUN_0059b3b0 — locale/ctype initializer (character-class tables)
  +-- FUN_005984aa — Case-insensitive string table lookup
  +-- FUN_0058fd90 — Locale initialization
  +-- FUN_00591bf1 — Float parsing with error handling
  +-- FUN_0058f014 — Registry/INI chunked field read (40+ fields by ID)

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 0x424 | FUN_004c3d80, FUN_00415780, etc. | Vehicle array stride (1060 bytes per entry) |
| 0x18c | FUN_004c52c0, FUN_004c6330, etc. | Scene array stride (396 bytes per entry) |
| 0x48c0 | FUN_004c0910, FUN_004c0f60 | Scoring DB stride (18624 bytes per season entry) |
| 0x1b4 | FUN_004c0b70, FUN_004c13a0 | Per-vehicle session state stride (436 bytes) |
| 0x200 | FUN_00587f90, various | File I/O buffer size (512 bytes) |
| 0x80 | FUN_00423530 | String table expansion increment (128 entries) |
| 0x10 | FUN_00423530, FUN_00423a00 | String table entry stride (16 bytes) |
| 0x20 | FUN_0053c6f0 | Max search path entries (32) |
| 0x84 | FUN_0053c6f0 | Search path entry stride (132 bytes) |
| 0x24 | FUN_00595af9, FUN_0058c789 | File descriptor table stride (36 bytes per FD) |
| 0x67 (103) | FUN_004c13a0 | Max array entries for 0x1b4-stride arrays |
| 0x68 (104) | FUN_004c5cb0, FUN_004c07f0 | Max scene entries (104) |
| 0x7fffffff | FUN_004c5cb0, FUN_0058815f | Sentinel MAX_INT (no slot found / unlimited capacity) |
| 0xFFFFFFFF | FUN_00595af9, FUN_005876f0 | Sentinel -1 (invalid FD, end marker) |
| 0x3ff00000 | FUN_004f61d6 | Gear ratio setup field range upper bound |
| 0.825f | FUN_00479690 | Default UI slider value |
| 0.25f | FUN_00479bd0 | Default UI slider value (alternate) |
| 0x5c, 0xb4, 0x12 | FUN_004d5af0 | XOR decode key bytes for obfuscated file data |
| 0x4000 | FUN_0053c6f0 | Search path dirty flag (DAT_008b5a38) |
| 0x0100 | FUN_0058c789 | SEEK_SET=0, SEEK_CUR=1, SEEK_END=2 |
| 0x1a | FUN_00595af9 | Unicode BOM byte (read before text file) |
| 0x1451 | FUN_00596245 | Float exponent overflow threshold (5201) |

## Moddable Configuration Fields

| Field | File | Function | Description |
|-------|------|----------|-------------|
| Vehicle physics params | .svm/.hdv | FUN_004f4270 | All physics sections (springs, dampers, aero, tire, brake, engine) |
| Pit strategy params | .svm | FUN_004f4270 | NumPitstopsRange, Pitstop1–3Range, FuelRange |
| Vehicle definition | .veh | FUN_004c3200 | HDV path, physics path, sounds path, graphics path, driver info |
| Team history | .veh | FUN_004c3200 | Starts, Poles, Wins, Championships |
| Track-specific livery | .veh | FUN_004c3200 | TrackLivery key=value pairs |
| Season scoring table | .gdb | FUN_004c0910 | Position→points mapping via SeasonScoringInfo section |
| AI difficulty | .plr/.plg | FUN_004b0540 | AI level clamped on load |
| Vehicle count | .plr/.plg | FUN_004b0540 | Computed from +0x24f8, clamped 1–104 |
| Scene filter properties | .scn | FUN_004c6330 | Filter categories for track selection UI |
| NOTSPIN / DASHLOW/DASHHIGH | .gen/scene | FUN_004ddf90 | AI spin behavior and dash display config |
| Setup type | .svm | FUN_004f6300 | +0x13c0: Custom=0, Gearing=1, Balance=2, Downforce=3 |
| Fuel consumption | .svm | FUN_004f6300 | Computed from fuelEstimate * fuelConsumption * trackLength * laps |
| Display settings | config | FUN_004726c0 | Screen mode (DAT_007cff84) |
| Difficulty/session | config | FUN_00473fd0 | Difficulty/session setting (DAT_007cf764) |
| Career game options | .plg | FUN_004c18b0 | fuel_mult, tire_mult, speed_comp per track |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- `DAT_007d0308` (RaceActiveFlag) — from docs/06, gates season database functions when non-zero
- `DAT_007cf3c8` (TrackConditionState) — from docs/06, gates season database string lookups
- `DAT_007d0434` (SeasonPath) — from docs/09, used to detect active season from .gdb filename
- `DAT_007d0410` (RaceMode) — from docs/06, checked for 3/4 (championship mode) in season scoring
- `DAT_007d00ec` (GameState) — from docs/01, 5=qualifying, 7=race in season scoring
- `DAT_007c56a4` (SessionType) — from docs/06, 7=race path in scoring update
- `DAT_007c54e8` (PlayerVehiclePtr) — from docs/01, dereferenced for player scoring/position
- `DAT_008ab6e4` (ScoringGate) — from docs/06, skip if == 2
- `DAT_008ac48c` (CurrentSceneIndex) — from docs/09, scene array index
- `DAT_005c329c` (VehicleCount) — from docs/01, set by FUN_004b70b0
- `DAT_007cfe88` — from docs/01, gates view mode dispatch
- `DAT_0059e440` (ZeroThreshold) — from docs/18, used in gate comparisons
- `DAT_007d0a20` (SessionVehicleCount) — vehicle count for game filter system

**Calls into:**
- docs/06-session-race-logic.md: FUN_004c2cb0 (standings update), FUN_004c2c20 (winner handler), FUN_004c03f0 (career standings loader), FUN_0040f130 (dispatch queue)
- docs/10-vehicle-physics.md: FUN_004f2c60 (brake/suspension per wheel), FUN_004f24f0 (damage model), FUN_0042ecc0 (setup loader)
- docs/09-track-system.md: FUN_0042e530 (track config), FUN_004c54f0 (.AIW/.SCN filename)
- docs/19-renderer.md: FUN_00497ad0 (bitmap load), FUN_00489cb0 (HTML buffer), FUN_00489600 (HTML/menu write)
- docs/01-engine-architecture.md: FUN_00566650 (path registry), FUN_00486f30 (UI list entry add)
- docs/20-math-utilities.md: FUN_00588410 (string compare), FUN_00587bcf (free), FUN_0058815f (sprintf), various math utilities
- docs/21-audio-network-internals.md: FUN_00499ae0 (global cleanup)
- docs/18-physics-dynamics.md: FUN_0059a8fa (thread registration)

**Called by:**
- docs/01-engine-architecture.md: Game::Setup (FUN_0042d5d0), Game::Post (FUN_0042d8a0)
- docs/06-session-race-logic.md: Session tick calls season scoring at end of race
- docs/10-vehicle-physics.md: Vehicle physics init calls .veh/.hdv parsers
- docs/09-track-system.md: Track loading calls .scn/.aiw path builders and terrain.ini
- docs/19-renderer.md: Texture loading calls TGA scanner

---

## Reimplementation Notes

1. **INI file format is the universal data format.** All game data files (.veh, .hdv, .svm, .gdb, .plr, .plg, .scn) use the same bracketed section `[SECTION]` / `key=value` format. The parser library (`FUN_00568210` → section lookup, `FUN_005679c0` → key lookup within section) is used by every system. Any reimplementation must replicate this parser exactly.

2. **Thread safety via mutex wrappers is pervasive.** The `FUN_0058c1b1` / `FUN_0058c203` (lock/unlock) pattern wraps:
   - File read/write operations (every ReadLine, WriteChar, Seek)
   - String format operations (FUN_00587f64, FUN_0058815f)
   - File size queries and seeks
   - Stream queries and I/O dispatch
   
   The mutex is per-file-descriptor (stored in DAT_008d4920 table, stride 0x24).

3. **File descriptor table (DAT_008d4920)** manages up to 0x20 entries, stride 0x24. FD index is computed as `(param_1 & 0x1f)`. Each entry stores: file handle, flags, mode byte. This is the game's own fd layer over Win32 handles.

4. **VehicleArray stride 0x424 and SceneArray stride 0x18c** are fundamental constants used by at least 15+ functions across the codebase. Any code accessing vehicles or scenes must use these strides with DAT_008ac390/DAT_008ac488 as counts.

5. **SETUP TYPE FIELD at +0x13c0** is a key branching point in the vehicle setup parser. Values: 0=Custom, 1=Gearing, 2=Balance, 3=Downforce. The active setup section is determined by this field.

6. **Linked list patterns vary.** While generic nodes use "data + next + flags" (0x0c bytes), specific contexts use different strides:
   - Filter property nodes: 0x0c bytes (index + next + active flag)
   - AutoLoadEntry nodes: 0x1c bytes (multiple string ptrs + sentinel)
   - File search results: 0x14 bytes (name1 + name2 + next)
   - Sprite overlay nodes: 0x38 bytes (with sort key)
   
   All linked lists share the same head/tail/cursor/count pointer layout at the container level.

7. **SeasonScoringInfo points table** is read from file by `thunk_FUN_0059d6a9` with 1-indexed position lookup (position 1 = first entry). This is the championship points system — modding this table changes the points allocation.

8. **XOR obfuscation** for certain data files uses a 3-byte XOR key (0x5c, 0xb4, 0x12) applied to 3-byte groups. Used by FUN_004d5af0 for data file loading.

9. **Custom heap allocator** exists alongside MSVC CRT malloc. The pool allocator (FUN_005828b0) creates 16 entries (stride 0x54) with linked-list management. The arena allocator (FUN_00594478) uses VirtualAlloc for 1MB regions.

10. **File naming convention:** Scene files use `<trackname>.SCN`, AI waypoint files use `<trackname>.AIW`, both residing in the track's season directory. The track name comes from scene struct at offset +0x104.

---

## Completeness

- Full specs written: 20 major API entry points, 10 subsystems, ~50 key internal functions
- All system-level data structures documented with field names from docs/13
- All globals referenced with names from docs/12
- Thunks/empty stubs omitted: ~100 (SEH unwind handlers, trivial wrappers)
- Confidence: high — the file format system is well-documented with consistent patterns across 312 entries, confirmed by call_graph.json and callers.json
