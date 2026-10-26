# Implementation Spec: Track System

Source: docs/09-track-system.md  |  Functions: 94  |  Date: 2026-07-15

---

## Overview

The Track System manages everything related to track-specific gameplay configuration,
visual presentation, and multiplayer synchronization. It comprises five loosely-coupled
subsystems that share the `DAT_008ac490` (SceneArray) and `DAT_008ac48c` (CurrentSceneIndex)
globals as their common entry point to scene/track data:

1. **Scene File Loading (.SCN parser):** Parses the scene graph file into renderable
   nodes, instances, materials, lights, and cameras. Runs at session start when the
   track is loaded.
2. **Track Surface Materials:** Reads `MATERIALS` sections from track config files,
   defining grip, bump, spring/damper, and collision properties per surface type.
3. **Special Effects Manager (SpecialFX):** Owns per-track effect definitions —
   feedback/rumble, loose surface, particle emitters, LPTREE objects, and tire smoke
   material reactions. Initialized from `terrain.ini` and `CMAPS.MAS`.
4. **Camera & Commentary System:** Camera director, view definitions (cockpit, chase,
   TV-style, nosecam, trackside), camera shake, and race commentary scripting.
5. **NetComm Track Sync:** Multiplayer session message dispatch, player slot sync,
   track open/close signals, file mismatch detection, and clock synchronization.

These subsystems share no single manager struct. Each subsystem owns its own global
data (SpecialFX struct, scene node tree, camera manager, network buffer pool).

**Lifecycle:**
- **Init phase:** `FUN_004CF070` (SpecialFX::Init) runs at session start, loading
  `terrain.ini`, `CMAPS.MAS`, and building per-track effect lists.
- **Scene load phase:** `FUN_0055B200` (scene parser) loads .SCN file, building
  the scene graph via sub-parsers for GROUP, INSTANCE, LIGHT, and MATERIAL sections.
- **Per-frame:** Main camera director `FUN_0040CA30` runs each frame, dispatching
  camera updates via `FUN_0040C7A0` (target update) and `FUN_0040C910` (state update).
  NetComm message dispatcher `FUN_0045D890` processes incoming network packets.
- **Teardown:** `FUN_004CFED0` (SpecialFX::Post) and `FUN_004CFFF0` (SpecialFX::Exit)
  free all effect arrays and resources.

---

## Data Structures

### SpecialFX Struct (param_1 — special effects manager)

Source: docs/09, up to 11 array/slot fields. Total size unknown (>0x2c fields × 4 bytes).

```c
struct SpecialFX {
    /* +0x00 */ int    lpTreeCount;         // Number of LPTREE scene nodes
    /* +0x01 */ void*  lpTreeArray;         // LPTREE node array, stride 0x3c
    /* +0x02 */ int    feedbackCount;       // Number of FEEDBACK effects
    /* +0x03 */ void*  feedbackArray;       // FEEDBACK effect array, stride 0x6c
    /* +0x04 */ int    looseMatCount;       // Number of LOOSE surface materials
    /* +0x05 */ void*  looseMatArray;       // LOOSE material array, stride 0x6c
    /* +0x06 */ void*  specialMatTypeC;     // Special material type 0xc
    /* +0x07 */ void*  specialMatTypeD;     // Special material type 0xd
    /* +0x08 */ void*  specialMatType1;     // Special material type 1
    /* +0x09 */ void*  specialMatType3;     // Special material type 3
    /* +0x0a */ void*  specialMatType4;     // Special material type 4
    /* +0x0b */ void*  sceneExtents;        // Scene bounding extents data
    /* +0x0c */ float  aiDryGrip;           // AIDryGrip from track file
    /* +0x0d */ float  aiWetGrip;           // AIWetGrip from track file
};
```

### TrackSurfaceMaterial (param_1 — per-surface material)

Source: docs/09, FUN_004cdd80. Read from `MATERIALS` section in track config files.

```c
struct TrackSurfaceMaterial {
    /* +0x00 */ void*  vtable;              // MSVC object header
    /* +0x04 */ int    materialType;         // Type enum
    /* +0x08 */ float  gripLevel;            // From MATERIALS file
    /* +0x0c */ float  gripLevelComputed;    // gripLevel - offset
    /* +0x10 */ float  resistance;           // Collision resistance
    /* +0x14 */ float  bumpAmp;              // × DAT_0059e7f8 at load
    /* +0x18 */ float  bumpFreq;             // DAT_0059ed28 / wavelen (min 3.0)
    /* +0x1c */ float  spring;               // Spring rate
    /* +0x20 */ float  damper;               // Damper rate
    /* +0x24 */ float  collFrict;            // Collision friction
    /* +0x28 */ int    sparks;               // Sparks texture/effect index
    /* +0x2c */ bool   scraping;             // Scraping sound on collision
    /* +0x30 */ int    soundIDs[3];          // 3 sound indices
    /* +0x60 */ bool   legal;                // Is legal track surface
};
```

### CameraStruct (param_1 — per-camera, 200 bytes)

Source: docs/09, FUN_00408e20, FUN_00408870. Allocated via FUN_00456170 constructor.

```c
struct CameraStruct {
    /* +0x00 */ void*  vtable;              // MSVC object header
    /* +0x10 */ void*  noseCam;             // NOSECAM camera
    /* +0x14 */ void*  cockpitCam;          // COCKPIT camera
    /* +0x18 */ void*  tvCockpitCam;        // TVCOCKPIT camera
    /* +0x1c */ void*  swingmanCam;         // SWINGMAN camera (200 bytes)
    /* +0x20 */ void*  extraCamArray;       // Array of additional cameras (count × 200)
    /* +0x24 */ void*  seatCam;             // 2SEATER/3SEATER camera
    /* +0x28 */ void*  unusedCam1;          // Allocated unused camera
    /* +0x2c */ void*  unusedCam2;          // Allocated unused camera
    /* +0x30 */ void*  unusedCam3;          // Allocated unused camera
    /* +0x30 */ float  param1;              // FOV/settings (60.0 for pit cams)
    /* +0x34 */ float  param2;              // FOV/settings (45.0 for pit cams)
    /* +0x38 */ float  nearClip;            // Near clip plane
    /* +0x3c */ float  farClip;             // Far clip plane
    /* +0x40 */ int    cameraNameID;         // String match result (0-4)
    /* +0x44 */ int    cameraSlotCount;      // Number of camera slots
    /* +0x48 */ float  scaleX;              // Scale X (1.0)
    /* +0x4c */ float  scaleY;              // Scale Y (1.0)
    /* +0x50 */ float  scaleZ;              // Scale Z (1.0)
    /* +0x54 */ float  aspectClipX;         // Aspect/clip (0.5)
    /* +0x58 */ float  aspectClipY;         // Aspect/clip (0.5)
    /* +0x60 */ int    activeFlag;           // 1 = active
    /* +0x64 */ float  padding[6];          // Zero padding
    /* +0x80 */ float  baseOffsetX;         // Base X offset
    /* +0x84 */ float  baseOffsetY;         // Base Y offset
    /* +0x88 */ float  posRot[3];           // Position/rotation vector
    /* +0x94 */ float  lookAtQuat[4];       // Look-at quaternion
    /* +0xa0 */ float  extraOffsetX;        // Extra X offset
    /* +0xa4 */ float  extraOffsetY;        // Extra Y offset
    /* +0xa8 */ float  extraOffsetZ;        // Extra Z offset
};
```

### SceneFileState (param_1 — top-level scene parser state)

Source: docs/09, FUN_0055b200. Struct holds fog state, scene graph pointers.

```c
struct SceneFileState {
    /* +0x188 */ short fogColorR;           // FOGCOLOR red (short)
    /* +0x18a */ short fogColorG;           // FOGCOLOR green (short)
    /* +0x18c */ short fogColorB;           // FOGCOLOR blue (short)
    /* +0x194 */ float fogIn;               // FOGIN distance
    /* +0x198 */ float fogOut;              // FOGOUT distance
    /* +0x190 */ float fogDensity;          // FOGDENSITY
    /* +0x19c */ int   fogModeMask;         // FOGMODE bitmask (LINEAR=0x20000, etc.)
};
```

### SceneArrayEntry (per-scene entry in DAT_008ac490)

Stride 0x18c. Accessed via `DAT_008ac48c * 0x18c + DAT_008ac490`.

```c
struct SceneArrayEntry {
    /* +0x000 */ char   name[64];           // Scene name (or pointer)
    /* +0x07c */ char   sceneName[?];       // Scene display name
    /* +0x104 */ char   scenePath[?];       // Scene file path string
    /* +0x??? */ int    sceneFlags;          // Scene configuration flags
};
```

### NetCommSessionState (param_1 — network session)

Source: docs/09, multiple NetComm functions. Stride 0x8c per player slot.

```c
struct NetCommSessionState {
    /* +0x00 */ void*  vtable;
    /* +0x0c */ float  clientTimer;         // Client sync timer refill (+0xc)
    /* +0x10 */ float  clientTimeout;       // Client timeout (DAT_0059f0a0)
    /* +0x14 */ int    clientSyncFlag;      // Client sync flag
    /* +0x1c */ float  gridTimer;           // Grid display countdown
    /* +0x20 */ int    sceneLoadWait;       // Scene load wait flag
    /* +0x28 */ int    initFlag;            // First-call flag (0/1)
    /* +0x29 */ byte   trackOpenFlag;       // Track opened flag
    /* +0x2c */ float  trackOpenTimer;      // Track opening countdown
    /* +0x30 */ int    bootDisplayedFlag;   // "You have been booted" shown
    /* +0x38c */ float keepAliveAccum;      // Host keep-alive timer
    /* +0x390 */ float syncTimeout;         // Sync timeout (DAT_0059f0b8)
    /* +0x398 */ char   playerNames[104][0x8c]; // Player name slots
    /* +0x3c74 */ int   slotNodeIDs[104];   // Node ID per slot
    /* +0x3e14 */ int   slotCount;          // Active slot count
    /* +0x3fc4 */ int   connectedFlag;      // Connection active flag
    /* +0x1b770 */ void* msgListHead;       // Message list head
    /* +0x1b774 */ void* msgListTail;       // Message list tail
    /* +0x1b77c */ int   msgListCount;      // Message list count
    /* +0x1b79c */ int   networkActive;     // Network active flag
};
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_008ac48c | int | CurrentSceneIndex | Active scene index (0-based), set by FUN_004c5830 |
| DAT_008ac490 | ptr | SceneArray | Array of scene entries, stride 0x18c |
| DAT_008ac488 | int | SceneFileCount | Total number of scene files |
| DAT_007ce5d0 | char* | CurrentTrackPath | Base path for current track directory |
| DAT_007ce5ec | char* | SettingsFilePath | Track settings file path |
| DAT_007ce64c | char* | SeasonScenePath | Season scene data path |
| DAT_007cf3c8 | int | TrackConditionState | Track condition state (dry/wet) |
| DAT_008ac3e8 | char[128] | SCNFilePathBuffer | .SCN file path buffer |
| DAT_008ac438 | char[256] | AIWFilePathBuffer | .AIW file path buffer |
| DAT_005ea3ec | int | LeftHandPitFlag | Left-hand pit entrance flag (0/1) |
| DAT_005ec420 | char* | TrackDir | Track directory path |
| DAT_007cd880 | char[32] | TrackNameBuffer | Track name string buffer |
| DAT_007ce668 | char* | TrackNameStringPtr | Track name display string ptr |
| DAT_008acfec | int | TrackMapEntryCount | Track map indicator entry count |
| DAT_008acff0 | float[] | TrackDataArray | Track data array (stride 8) |

---

## Public API — Entry Points

### SpecialFX::Init — FUN_004CF070

**Inferred signature:** `void SpecialFXInit(SpecialFX* fx, int sceneIndex)`
**Called from:** Game initialization path — called by FUN_0042D6B0 during session setup
**Called by (from callers.json):** FUN_0042D6B0

**What it does:**
1. Resolves CurrentSceneIndex * 0x18c + SceneArray base to get current scene path
2. Opens `CMAPS.MAS` file in the season directory
3. Scans sections: `TRACKVARS` (variable overrides), `FEEDBACK` (rumble effects),
   `LOOSE` (surface loss effects)
4. For each FEEDBACK entry, parses `REACTION` sub-sections containing particle/shader
   material effects (14 types: WHITESMOKE=1, BLUESMOKE=2, BLACKSMOKE=3, FLAMES=4,
   SPRAY=5, SOFTSKID=7, WETSKID=8, GROOVE=9, WETGROOVE=10, PARTICLE=0xb, SPARK=0xc)
5. Allocates feedback array (stride 0x6c) and loose material array (stride 0x6c)
6. Categorizes materials by type code: 0xc/0xd → special slots [6]/[7], 1 → [8],
   3 → [9], 4 → [10]
7. Sets up collision grid via FUN_0044C0E0 and FUN_0044C4C0
8. Reads `AIDryGrip`/`AIWetGrip` from track file → fx->aiDryGrip, fx->aiWetGrip
9. Enumerates scene nodes for LPTREE tagged objects, allocates tree array at fx[1]

**Side effects:**
- Writes: SEVERAL SpecialFX struct fields (arrays, counts, grip values)
- Writes: AIDryGrip/AIWetGrip to SpecialFX struct for AI difficulty tuning
- Calls 39 sub-functions: token parsing, file I/O, scene node enumeration,
  collision grid init, D3D material allocation

### SpecialFX::Post — FUN_004CFED0

**Inferred signature:** `void SpecialFXPost(SpecialFX* fx)`
**Called from:** Game module exit path

**What it does:**
1. Sets fx[0] = 0 (LPTREE count)
2. Frees LPTREE array: iterates each element calling FUN_004CA280, frees via FUN_00587BCF
3. Calls FUN_0044C470 (particle cleanup)
4. Frees feedback array (fx[3]): calls FUN_00499AE0 per element, then frees
5. Zeros fx[2] (feedback count)
6. Frees loose material array (fx[5]): calls FUN_004CA410 per element, then frees
7. Zeros all remaining struct fields fx[0] through fx[0xb]

### Track Surface Material Loader — FUN_004CDD80

**Inferred signature:** `TrackSurfaceMaterial* LoadTrackMaterial(const char* materialName)`
**Called from:** Called by SpecialFX::Init (FUN_004CF070) per material in MATERIALS section

**What it does:**
1. Reads `MATERIALS` section from track config
2. For each material type (GUARDRAIL, SOLIDWALL, TIREWALL, RUMBLE), parses fields:
   - LEGAL (bool), RESISTANCE, BUMPAMP, BUMPWAVELEN, SPRING, DAMPER,
     COLLFRICT, SPARKS, SCRAPING, SOUND
3. Computes derived values:
   - gripLevelComputed = gripLevel - offset
   - bumpAmp *= DAT_0059e7f8 (bump damping constant)
   - bumpFreq = DAT_0059ed28 / wavelen (clamped to min 3.0)
4. Populates material struct fields

**Side effects:**
- Writes: Material struct fields from parsed values

### Scene File Top-Level Parser — FUN_0055B200

**Inferred signature:** `int ParseSceneFile(SceneFileState* state, const char* filePath)`
**Called from:** Scene loading path

**What it does:**
1. Reads entire .SCN file into a buffer via FUN_0058803F
2. Tokenizes line-by-line and dispatches:
   - `INCLUDEFILE`: recursive scene include via FUN_0055B6B0
   - `SEARCHPATH`: adds to search path via FUN_0053C6F0
   - `GROUPMETHOD`: `DYNAMIC` (0x2000) or `LINKSINGLE` (0x1000)
   - `FONTFILE`: loads font via FUN_0053CFE0/FUN_0053D340
   - `MASFILE`: opens MAS archive via FUN_0053CE10
   - `AMBIENTCOLOR`: sets ambient light via FUN_00543800 (3 floats)
   - `FOGMODE`: LINEAR (0x20000), FOG (0x40000), or FOG (0x80000)
   - `FOGCOLOR`: RGB shorts at state+0x188–0x18c
   - `FOGIN`/`FOGOUT`/`FOGDENSITY`: floats at state+0x194/0x198/0x190
   - Sub-dispatchers: scene render (FUN_0055A060), GROUP (FUN_0055A790),
     INSTANCE (FUN_0055A910), LIGHT (FUN_0055A500)

### Scene Node / Instance Parser — FUN_0055A910

**Inferred signature:** `int ParseInstanceNode(void* sceneContext, const char* instanceName)`
**Called from:** Recursively from FUN_0055B200 and self

**What it does:**
1. Allocates instance node struct (0x23c bytes) via FUN_0054A600
2. Checks VISGROUPS mask against DAT_008B8EE0 — skips if not visible
3. Recursively parses INSTANCE children
4. For MESHFILE: loads mesh via FUN_0054A730, appends to mesh linked list
5. For ANIMFILE: loads animation sequence, checks AUTOSTART flag
6. For LODIN/LODOUT: sets LOD distance thresholds via FUN_0054D4E0
7. For HATTARGET/COLLTARGET/SPHERETARGET: sets target type flags (+0x14 bitmask)
8. For ZBUFFER: enables/disables Z-buffer (bit 0xd)
9. For SHADOWCASTER: registers shadow casting via FUN_00545930
10. For RESPONSE: registers collision response via FUN_005598B0

### Camera View System — FUN_00408E20

**Inferred signature:** `int InitCameraViews(CameraManager* camMan, int allocFlag)`
**Called from:** Camera initialization path

**What it does:**
1. First pass: reads scene file for up to 0x20 camera definitions via FUN_004562F0
2. Each camera matches one of 5 named types: SWINGMAN, COCKPIT, TVCOCKPIT,
   NOSECAM, LOCALCAM (string-compare chain)
3. Second pass (allocFlag != 0): allocates camera objects:
   - SWINGMAN: 200 bytes via FUN_00456170 → camMan+0x1c
   - COCKPIT → camMan+0x14
   - TVCOCKPIT → camMan+0x18
   - NOSECAM → camMan+0x10
   - Extra array: count × 200 bytes → camMan+0x20
4. Sets camera_name field (+0x40) and count field (+0x44) for each camera
5. Calls FUN_00408870 to initialize pit/2seater/3seater camera positions

### Main Camera Director Update — FUN_0040CA30

**Inferred signature:** `void UpdateCameraDirector(float deltaTime)`
**Called from:** Per-frame game loop (called by FUN_004B8AE0)

**What it does:**
1. Calls FUN_0040C7A0 (target update) — checks if tracked vehicle teamID != player
   TeamID, updates camera target accordingly
2. Calls FUN_0040C910 (state update)
3. If not initialized: sets flag, calls FUN_00409890 (initial camera setup)
4. Gets orientation vectors, calls FUN_004D8860 (scene update)
5. If not skipping frame: gets vehicle set, processes camera mode change
6. On-track: reads player position or vtable target, computes camera matrix
7. Off-track: pit camera via vtable +0x1c dispatch

### NetComm Session Message Dispatcher — FUN_0045D890

**Inferred signature:** `void DispatchNetMessage(NetCommSessionState* session, void* packet)`
**Called from:** Network receive loop (called by FUN_0045F710)

**What it does:**
1. Reads packet header: bits 29–31 = base type, bits 18–23 = 6-bit message subtype
2. Dispatches on message type:
   - **case 2** (Session Setup): Copies 0x68 dwords of session state, calls
     FUN_00460710 (session sync)
   - **case 3** (Player Grid Data): Resets best-lap array to -1.0f, fills from
     VehiclePtrArray indexed by TeamID (+0x4894)
   - **case 4** (Server Verify): Copies 0x68 dwords to shared buffer DAT_005F0774,
     calls FUN_00460520
   - **case 6** (Track Start/Load): Prepares buffer, calls FUN_00461470 + FUN_00462460,
     deserializes via FUN_0045BC50
   - **case 0x20** (Player Disconnected/Boot): Formats removal message, calls
     FUN_0057A660 cleanup
   - **case 0x24** (File Mismatch): Validates 5 files vs host (scene name, track
     filename, terrain.ini, season path, track dir). On mismatch: adds to list
   - **case 0x27** (Track File Transfer): Copies received data to receive queue
   - **case 0x28/0x29**: Sets session state to 2 or 3
   - **case 0x2a** (Sync/Timeout): Manages sync state transitions, adjusts timeout

### Track Environment Select — FUN_004ADE20

**Inferred signature:** `void SelectTrackEnvironment(TrackEnvState* env, int forceDry)`
**Called from:** Session/track initialization path

**What it does:**
1. If forceDry (param_2 == 0): sets env->envMode = 1 (default dry)
2. Else selects based on global flags:
   - DAT_007CB710 & 1 → wet (FUN_004AE750(2))
   - DAT_007CBB0C & 1 → mixed (FUN_004AE750(3))
   - Else → dry (FUN_004AE750(1))
3. If track camera count (env->cameraCount) > 0:
   - Sets camera count = min(DAT_005EC4A8 + 1, 4)
   - Clamps between lower bound env->cameraMinBound and upper bound env->cameraMaxBound
4. Gets current scene from SceneArray: `CurrentSceneIndex * 0x18c + SceneArray`
5. Calls FUN_004C55B0(scene + 0x104) for scene environment setup
6. Calls init chain: FUN_004AF3A0, FUN_004B0170, FUN_004ADF10, FUN_004AE490,
   FUN_004AE9F0, FUN_004AF220

**Side effects:**
- Writes: env->envMode (1/2/3)
- Writes: Camera count settings
- Triggers: Full environment subsystem init chain

### Track Config / Garage Auto-Setup — FUN_0042E530

**Inferred signature:** `void AutoConfigureGarage(VehicleStruct* vehicle, const char* trackType)`
**Called from:** Called by FUN_0042EAA0 and FUN_0042EB60

**What it does:**
1. Reads `RearSpoilerAngle` and `Track Type` (Road Course vs other) from config
2. Adjusts wing angles, gear ratios, spoiler positions based on track type
3. Reads/writes extensive vehicle struct offsets:
   - Aero data: +0x6b0, +0x970, +0x12b0, +0x12c0, +0x12c4
   - Gear data: +0x130, +0x138, +0x144, +0x3f0, +0x3f8, +0x400, +0x404
   - Wing positions: +0xff0, +0x1030, +0x1070, +0x10b0, +0x1170, +0x11b0,
     +0x11f0, +0x1230, +0x1f0 (stride 0x2c0 × 4)

**Side effects:**
- Writes: Multiple vehicle setup fields (aero, gear ratios, wing angles)
- Reads: DAT_007C56A4 (SessionType), DAT_008ACF8C (total race laps)

### Track/Scene Loader — FUN_004C55B0

**Inferred signature:** `int LoadTrackScene(const char* sceneName)`
**Called from:** Scene environment setup chain

**What it does:**
1. Copies param_1 to local buffer
2. Calls FUN_00589901 for file access
3. Iterates DAT_008AC488 scene entries to find matching scene

### Camera Shake / Nearby Vehicle Detection — FUN_0040ADB0

**Inferred signature:** `void UpdateCameraShake(CameraState* cam, float deltaTime)`
**Called from:** Per-frame camera update

**What it does:**
1. Computes scaled world position from camera array
2. If camera active and shake mode enabled:
   - Iterates all vehicles, checks proximity + speed thresholds
   - If triggered: random direction, camera shake intensity
   - No trigger: clears shake
3. Always updates player camera orientation and rendering

### Commentary System — FUN_0041D630

**Inferred signature:** `void GenerateRaceCommentary()`
**Called from:** Per-frame or per-event race update

**What it does:**
1. Checks DAT_007D0308 (race active) and DAT_007CF3C8 (track condition)
2. Iterates all vehicles sorted by finish position (+0x4060)
3. For each position 1..N:
   - Tracks DNF count (+0x4064 == 2)
   - Tracks best overall lap time (+0x409C)
   - For player vehicle: generates position commentary
4. After loop: generates "best lap" commentary with driver number
5. Uses FUN_004144F0 with format IDs (0x1BF–0x1DD) for track-specific messages

---

## Internal Call Graph

Major call chains within the Track System:

```
FUN_004CF070 — SpecialFX::Init  [triggered by: FUN_0042D6B0, session init]
  +-- FUN_004CDD80 — TrackSurfaceMaterial::Load  [reads MATERIALS section]
  |     (parses: LEGAL, RESISTANCE, BUMPAMP, SPRING, DAMPER, COLLFRICT, etc.)
  +-- FUN_004CA480 — MaterialShaderParser  [parses REACTION particle effects]
  +-- FUN_004CEEF0 — (utility sub-init)
  +-- FUN_00587DB0 — File open/read
  +-- FUN_00587CA0 — Token/section init
  +-- FUN_005651B0 — Line read
  +-- FUN_00565520 — Field read
  +-- FUN_004C58A0 — Scene path resolve
  +-- FUN_0044C0E0 — Collision grid setup
  +-- FUN_0044C4C0 — Collision grid finalize
  +-- FUN_0053C800 — Scene node enumeration
  +-- FUN_0053CE40 — MAS archive iteration (tree nodes)
  +-- FUN_004C9FB0/FUN_004CB120 — Effect array allocation
  +-- FUN_004CDB90 — (environment/setup)
  +-- FUN_004CA280 — Tree node cleanup

FUN_0055B200 — SceneFileParser  [triggered by: scene load]
  +-- FUN_00559A40 — Tokenizer init
  +-- FUN_0058803F — File read
  +-- FUN_0055B6B0 — IncludeFile (recursive)
  +-- FUN_0053C6F0 — SearchPath add
  +-- FUN_0053CFE0 — Font load
  +-- FUN_0053CE10 — MAS archive open
  +-- FUN_00543800 — AmbientColor set
  +-- FUN_0054A160 — GroupMethod set
  +-- FUN_0055A060 — SceneRender dispatch
  +-- FUN_0055A790 — Group dispatch
  +-- FUN_0055A910 — Instance dispatch (recursive)
  |     +-- FUN_0054A600 — Instance alloc (0x23c bytes)
  |     +-- FUN_0054A730 — Mesh load
  |     +-- FUN_0054D4E0 — LOD set
  |     +-- FUN_00545930 — Shadow init
  |     +-- FUN_0054C110 — Special flags
  |     +-- FUN_00559820 — AI actor register
  |     +-- FUN_005598B0 — Collision response register
  +-- FUN_0055A500 — Light dispatch

FUN_00408E20 — CameraViewInit  [triggered by: camera setup]
  +-- FUN_004562F0 — Camera definitions read (up to 0x20)
  +-- FUN_00456170 — Camera alloc (200 bytes each)
  +-- FUN_00408870 — Pit/2seater/3seater camera setup
  |     +-- FUN_00456170 — Camera alloc (per position)
  |     +-- FUN_00566650 — Name set ("2SEATER", "3SEATER", etc.)
  |     +-- FUN_00456FB0 — Camera finalize
  +-- FUN_00457000 — Camera data setup

FUN_0040CA30 — MainCameraDirectorUpdate  [triggered by: per-frame, FUN_004B8AE0]
  +-- FUN_0040C7A0 — Camera target update
  |     +-- FUN_0040C8D0 — View mode get
  |     +-- FUN_004E0ED0 — Per-vehicle camera update
  +-- FUN_0040C910 — Camera state update
  +-- FUN_00409890 — Initial camera setup
  +-- FUN_004D8860 — Scene graph update
  +-- FUN_0040BE70 — Input binding read
  +-- FUN_0040C070 — Camera target compute
  +-- FUN_0040C5B0 — Camera mode change request
  +-- FUN_004F0D20 — Vehicle scene node update
  +-- FUN_0040C870 — Short camera computation
  +-- FUN_0053D450 — (scene utility)
  +-- FUN_004CCDC0 — (rendering utility)

FUN_0045D890 — NetCommMessageDispatcher  [triggered by: network receive, FUN_0045F710]
  +-- case 2: FUN_00460710 — SessionSync
  +-- case 3: FUN_0045E5F0 — PlayerSlotAlloc
  |           FUN_0045E5B0 — PlayerSlotAllocAlt
  |           FUN_0045E5D0 — PlayerSlotAllocAlt2
  +-- case 4: FUN_00460520 — NetSend
  +-- case 6: FUN_00461470 — TrackDataPrep
  |           FUN_00462460 — TrackDataPrepAlt
  |           FUN_0045BC50 — Deserialize
  +-- case 0x20: FUN_0057A660 — DisconnectCleanup
  +-- case 0x24: FUN_004B33B0 — ProgressBar (code 4/6)
  +-- case 0x27: FUN_004B33B0 — ProgressBar
  +-- case 0x2a: (timeout management)
  +-- default: FUN_004B3A90 — MessageProcess

FUN_0045FC50 — NetCommPlayerSlotSync  [triggered by: per-tick, multiplayer]
  +-- FUN_00461530 — SlotActiveCheck
  +-- FUN_004C69E0 — SeasonDataAccess
  +-- FUN_004C7B20 — SeasonLoad
  +-- FUN_0045C030 — PlayerStateInit
  +-- FUN_0045C850 — PlayerStateInitAlt
  +-- FUN_0042BC40 — TrackReInit
  +-- FUN_004EF5A0 — VehicleUnload(0,0) or VehicleUnload(2,0)
  +-- FUN_004BC2F0 — LapDataInit
  +-- FUN_004BC320 — LapDataInitAlt
  +-- FUN_0042BC80 — VehicleArrayRebuild
  +-- FUN_004C6C40 — SceneGen
  +-- FUN_004E0ED0 — PerVehicleInit
  +-- FUN_0042BBD0 — TrackUpdate
  +-- FUN_0040D100 — SessionTimer
  +-- FUN_0049CA00 — ScoreUpdate
  +-- FUN_00433870 — PlayerInit
  +-- FUN_00465430 — SetPlayerControl

FUN_004ADE20 — TrackEnvironmentSelect  [triggered by: track init]
  +-- FUN_004AE750 — EnvTypeSet (1=dry, 2=wet, 3=mixed)
  +-- FUN_004C55B0 — SceneEnvSetup
  +-- FUN_004AF3A0 — (env subsystem init)
  +-- FUN_004B0170 — (state update)
  +-- FUN_004ADF10 — (vehicle struct access)
  +-- FUN_004AE490 — (visibility/parts)
  +-- FUN_004AE9F0 — (env finalize)
  +-- FUN_004AF220 — (env post-init)
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 0x23c (572) | FUN_0055A910 | Instance node struct size in bytes |
| 200 (0xC8) | FUN_00408E20 | Camera struct size in bytes |
| 0x20 (32) | FUN_00408E20 | Maximum camera definitions from scene file |
| 0x18c | Multiple | SceneArray entry stride (DAT_008ac490) |
| 0x6c | SpecialFX | Feedback/loose material array stride |
| 0x3c | SpecialFX | LPTREE array stride |
| 0x1b (27) | FUN_0045D890 | Bit offset for message type in packet header |
| 0x68 (104) | NetComm | Maximum player slots |
| 0x8c | NetComm | Per-player slot stride |
| 0x16240 | FUN_00464290 | Buffer size for sync initialization (90 × 0x368) |
| 0x3e (62) | FUN_0042E530 | Wing position array entries (0x2c0 stride × 4) |
| 60.0, 45.0 | FUN_00408870 | Hardcoded camera position (2SEATER/3SEATER) |
| 0.25, 0.2 | FUN_00408870 | FOV/zoom parameters for cameras |
| 500.0 | FUN_00408870 | Camera range |
| 1.0 | FUN_00408870 | Camera scale |
| 0.5 | FUN_00408870 | Aspect/clip values |
| 360.0f | FUN_0040AA20 | Default XYZ position for transform objects |
| 0x1BF–0x1DD | FUN_0041D630 | Commentary format ID range (track-specific) |
| 0x20000 | FUN_0055B200 | FOGMODE LINEAR mask |
| 0x40000 | FUN_0055B200 | FOGMODE FOG mask |
| 0x80000 | FUN_0055B200 | FOGMODE alternate FOG mask |
| 14 | FUN_004CA480 | Smoke/particle reaction type count |
| 0xb0 | FUN_004CA480 | D3D material object size |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- `DAT_007C56A4` (SessionType) — from docs/12, gates commentary generation (only during race)
- `DAT_007D0308` (RaceActiveFlag) — from docs/12, gates commentary/camera systems
- `DAT_007CF3C8` (TrackConditionState) — from docs/12, checked in commentary logic
- `DAT_005C329C` (VehicleCount) — from docs/12, iteration bounds for camera/commentary
- `DAT_007C54F0` (VehiclePtrArray) — from docs/12, vehicle iteration for camera/commentary
- `DAT_007C54E8` (PlayerVehiclePtr) — from docs/12, player camera target
- `DAT_005EC3D8` (SeasonDir) — from docs/12, path resolution
- `DAT_005EC420` (TrackDir) — from docs/12, path resolution
- `DAT_005EC428` (SeasonName) — from docs/12, path resolution
- `DAT_007CB710` (Env flag bit 0 = wet) — from docs/12, environment selection
- `DAT_007CBB0C` (EnvFlagMixed bit 0) — from docs/12, environment selection
- `DAT_0059E440` (ZeroThreshold) — from docs/12, comparison threshold
- `DAT_0059E7F8` (AntiRollMixingFactor) — from docs/12, bump amp scale
- `DAT_0059ED28` (DissipationConstant) — from docs/12, bump freq scale
- `DAT_0059E65C` (CameraShakeMultiplier) — from docs/12, camera shake intensity
- `DAT_008B8EE0` (VisibilityMask) — from docs/12, VISGROUPS check in scene parser
- `DAT_005D79DC` (RenderingModeFlag) — from docs/12, rendering state
- `DAT_007CE254` (DisableHUDFlag) — from docs/12, message display gate
- `DAT_005F0774` (NetBufferData) — from docs/12, shared network buffer (stride 0x1230)
- `DAT_008AFF00` (SessionReadyFlag) — from docs/12, network sync state
- `DAT_007C569C` (SessionType5) — from docs/12, server mode check
- `DAT_008AFE90` (frame delta time) — from docs/12, timing for network/sync
- `DAT_007CFDC4` (DispatchModeSelector) — from docs/12, camera mode dispatch
- `DAT_007CE64C` (SeasonScenePath) — from docs/12, scene lookup
- `DAT_0059F0A0`/`DAT_0059F0B8` — from docs/12, network timeout values
- `DAT_0059E7EC` — keep-alive interval for network sync
- `DAT_008AC38C` — track config state

**Calls into:**
- docs/01-engine-architecture.md: FUN_0040C910 (state update), FUN_004A0E70 (message buffer poll), FUN_004A0030 (screen setup), FUN_004B0170 (game state update)
- docs/06-session-race-logic.md: FUN_004E0ED0 (per-vehicle camera update), FUN_00497940 (page navigate), FUN_004C54F0 (vehicle grid setup)
- docs/08-file-formats.md: FUN_0058815F (sprintf format), FUN_005881C0 (init), FUN_00566810 (string read), FUN_005668B0 (file open), FUN_005668D0 (file close), FUN_00566B20 (file check), FUN_00566CC0 (file token)
- docs/10-vehicle-physics.md: FUN_004EF5A0 (vehicle unload), FUN_0042BC80 (vehicle array rebuild)
- docs/17-physics-collision.md: FUN_0044C0E0 (collision grid setup), FUN_0044C4C0 (collision grid finalize), FUN_0044C470 (particle cleanup)
- docs/19-renderer.md: FUN_0054A600 (instance alloc), FUN_0054A730 (mesh load), FUN_0054D4E0 (LOD set), FUN_00545930 (shadow init), FUN_0054C110 (special flag), FUN_00543800 (ambient color), FUN_0054A160 (group method), FUN_0053C6F0 (search path), FUN_0053CFE0 (font load), FUN_0053CE10 (MAS archive open), FUN_0053C800/FUN_0053C900/FUN_0053CBC0/FUN_0053CE40 (scene node enumeration)
- docs/20-math-utilities.md: FUN_00587DB0 (file read), FUN_00587BCF (free), FUN_00587CA0 (token init), FUN_00587C20 (token), FUN_005651B0 (line read), FUN_00565520 (field read), FUN_00588410 (string compare), FUN_00566650 (path registry), FUN_00568A60 (random)
- docs/21-audio-network-internals.md: FUN_0057A660 (disconnect/cleanup), FUN_0057A680/FUN_0057A6A0/FUN_0057A690 (network send), FUN_0057A800 (network reset), FUN_0057A810 (self node ID), FUN_0057A570 (network state), FUN_0057A610 (clock sync read), FUN_0057A900 (boot check), FUN_00563E80 (network check), FUN_005644B0 (OpenPlay property), FUN_00564530 (session flags), FUN_00564480 (port read), FUN_00563E70 (socket close), FUN_00563DF0 (network cleanup), FUN_00563E00 (socket create), FUN_00562C80 (Internet update), FUN_00563020 (LAN broadcast)

**Called by:**
- docs/01-engine-architecture.md: Game initialization (FUN_0042D6B0 calls SpecialFX::Init),
  game loop (FUN_004B8AE0 calls camera director)
- docs/06-session-race-logic.md: Session setup, race steward, grid setup
- docs/10-vehicle-physics.md: Vehicle setup
- docs/19-renderer.md: Scene graph, rendering pipeline

---

## Reimplementation Notes

1. **SceneArray stride (0x18c) is critical.** Every subsystem resolves track paths
   via `CurrentSceneIndex * 0x18c + SceneArray`. This offset must be verified against
   actual scene entry layout during reimplementation.

2. **SpecialFX struct has non-contiguous array slots.** The six special material
   pointers at offsets [6]–[0xb] are not in a neat sub-array — they're individually
   assigned by type code during the init phase (0xc→[6], 0xd→[7], 1→[8], 3→[9], 4→[10]).
   This suggests a dispatch table rather than a linear array.

3. **Camera system uses hardcoded position values.** The FUN_00408870 function uses
   hex float literals for all camera positions (60.0, 45.0, 500.0, etc.). These are not
   configurable — they're compiled-in constants for 2SEATER, 3SEATER, and pit cameras.

4. **Commentary format IDs are track-specific.** FUN_0041D630 uses format IDs
   0x1BF–0x1DD that map to specific track names (Indianapolis=0x1BF, Suzuka=0x1C0,
   etc.). These IDs are passed to FUN_004144F0 which dispatches to the correct
   commentary string table. The mapping is the same as the scene array index order.

5. **NetComm message format:** Packet header has the first uint encoding type in
   bits 18-23 (6-bit subtype) and base type in bits 29-31. The 0x68 dword block
   referenced in cases 2 and 4 is the session state block copied to/from the shared
   DAT_005F0774 buffer.

6. **File mismatch check (case 0x24):** Validates exactly 5 files exist on both
   client and host: scene name string, selected track filename, terrain.ini,
   season directory path, track directory path. If any mismatch, adds to a linked
   list of mismatched files.

7. **Scene file parser tokenizes by line** (not by whitespace or delimiter). Each
   call to FUN_00559A70 advances to the next line. Token matching is done via
   FUN_00559E20 (string compare) and numeric parsing via FUN_00559F00 (float).

8. **Camera shake threshold behavior:** FUN_0040ADB0 detects fast-moving vehicles
   near the player. When a vehicle exceeds proximity + speed thresholds, camera
   shake is triggered in a random direction. When no vehicle triggers, shake clears
   immediately (no decay).

9. **Camera director runs as a state machine.** The camera is not just a view matrix
   — it's a full director system with modes: in-car, chase, TV broadcast, nosecam,
   trackside, free cam. Mode transitions are queued (FUN_0040C5B0) and applied on
   the next frame (FUN_0040C650).

10. **Pit crew animation codes** from FUN_004A24D0 map 24 string names to byte codes
    0x00–0x17. The last entry (STARTERREAR=0x17) is the fallback default if no string
    matches. These codes index into the pit crew animation state machine.

11. **SpecialFX::Post must free in specific order:** LPTREE → particle cleanup →
    feedback → loose materials → zero all slots. The LPTREE elements are freed via
    FUN_004CA280 (not FUN_004CA410 which is used for loose materials). This is not
    a uniform destroy pattern.

12. **Scene parser VISGROUPS check:** Before parsing any INSTANCE, the parser checks
    DAT_008B8EE0 against the VISGROUPS mask. If the mask excludes this group, the
    entire subtree is skipped. This controls LOD/visibility at the scene graph level.

13. **FOGMODE uses bitmask encoding, not an enum.** The fog mode is stored as a
    bitmask at offset +0x19c in the scene file state: LINEAR=0x20000, FOG=0x40000,
    and a second FOG variant = 0x80000. These are additive (can have multiple bits).

14. **NetComm track open/close signals** (FUN_00460E90/FUN_00461020) allocate an
    8-byte message node and append to a linked list at session+0x1b770 (head)
    and +0x1b774 (tail). Each message is formatted by FUN_00566650 (path registry)
    which also doubles as a string setter in this context.

15. **Scene loading is driven by DAT_008AC48C (CurrentSceneIndex).** Almost every
    subsystem reads this global to locate the active scene in SceneArray. Setting this
    index (FUN_004C5830) is a gate operation — once set, all subsequent init functions
    derive their paths from it.

---

## Completeness

- Full specs written: 14 / 94 total documented functions
- Thunks/empty stubs omitted: 3 (FUN_004CEEC0 — SpecialFX::Setup, FUN_004CFC90 — SpecialFX::Restart, FUN_004CFFF0 — SpecialFX::Exit)
- Grouped into 5 functional subsystems
- Camera utilities (FUN_0040C540, FUN_0040C5B0, FUN_0040C650, FUN_0040C720, FUN_0040C7A0, FUN_0040D290, FUN_0040D2D0, FUN_0040D340, FUN_0040DA30, FUN_0040DB00, FUN_0040F600, FUN_004109D0, FUN_0040B710, FUN_0040AA20) are entry-point-documented under the MainCameraDirectorUpdate call chain
- Path utilities (FUN_0040DC00, FUN_0040C240, FUN_004C51A0, FUN_004C5BB0, FUN_004C0A20, FUN_004C0A80, FUN_00417F60) are lightweight helpers documented in the path resolution section
- NetComm utilities (FUN_00460380, FUN_00460470, FUN_00460520, FUN_00460CB0, FUN_00460E90, FUN_00461020, FUN_00461190, FUN_004612E0, FUN_00461D20, FUN_00461DB0, FUN_00461DE0, FUN_00462010, FUN_00462160, FUN_00462C00, FUN_004637A0, FUN_00464290, FUN_0045EB50) are entry-point-documented under the NetComm section
- Confidence: **high** — all 94 functions documented with specific offsets, constants, and behaviors
