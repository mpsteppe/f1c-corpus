# Track System - Database, Materials, Commentary, SpecialFX
## Tier 4 - High String Count Infrastructure (8 functions)
### Tier 4 — High String Count Infrastructure Functions (8 functions)

These functions have high string counts but contain no game physics or AI logic.
They are UI, input, config, graphics, or networking infrastructure.

| Address | Strings | Identity | Domain |
|---------|---------|----------|--------|
### FUN_004accfa — Force Feedback Config Initializer

Reads DirectInput force feedback spring coefficient and saturation settings per joystick per axis. 225 string references for 2 joysticks × 8 axes × 4 parameters each.

**Key logic:**
- Iterates 2 joysticks, each with 8 axes
- Per axis: reads Spring Coefficient Neg/Pos and Spring Saturation Neg/Pos via FUN_004b1ac0 (multi-field setter with strings, docs/01)
- Calls FUN_004b1d90 and FUN_004b1c20 (config write operations) in fixed sequence
- Formats parameter names via FUN_0058815f (sprintf formatter, docs/08) with "FFB Joy[%2.2d] Axis[%2.2d] ..." patterns
- Calls FUN_004a1da0 (session catchup), FUN_0047aa60, FUN_004a7010 (repeated 34×), FUN_004a1e20 (triple dispatch wrapper)

**Calls:** FUN_004b1ac0 (multi-field setter), FUN_004b1d90, FUN_004b1c20, FUN_0058815f (format), FUN_004a1e20 (dispatch wrapper), FUN_004a1ec0 (settings path builder), FUN_004a1da0 (session catchup), FUN_0047aa60

**Moddability:** `configurable` — reads FFB spring coefficient/saturation from config via INI-like string patterns
| 0x00421cd0 | 60 | Config.ini parser | VERSION, IPADDRESS, VCRFILE, VCRCYCLE, LAUNCHTIME, Windows path |
| 0x004ca480 | 58 | Material shader system | COLOR, DESTBLEND, ALPHAFADE, DEFORMABLE, smoke types |

### FUN_004CA480 — Material Shader/Reaction Effect Parser

Parses .MTS file section configuring particle/shader material effects — smoke types, render states, scale/growth/duration envelopes.

**Key logic:**
- Reads "REACTION" token; compares against 14 smoke/particle type names: WHITESMOKE=1, BLUESMOKE=2, BLACKSMOKE=3, FLAMES=4, SPRAY=5, SOFTSKID=7, WETSKID=8, GROOVE=9, WETGROOVE=10, PARTICLE=0xb, SPARK=0xc
- Assigns type code to param_1+4
- Parses numeric fields: SCALE (float3), GROWTH, GROWTHVEL, DURATION, ASDENVELOPE, POWER, RAMPSPEED, OFFSETVEL via FUN_00565870
- RAMPSPEED clamped: below DAT_0059e43c → 1.0; above DAT_0059eae0 → FLT_MAX
- ASDENVELOPE scaled by DAT_0059e8b4 for type 5 (SPRAY)
- Allocates 0xb0-byte D3D material object at param_1+0x50
- Initializes render state flags at offsets +0x20, +0x58, +0x5c, +0x60, +0x64, +0x66, +0x68, +0x70, +0x38, +0x90
- Parses VERTEX, PIXEL, CHROMA, COLOR, DESTBLEND, ASRCBLEND shader sections setting bit flags

**Calls:** FUN_00565870 (INI float reader), FUN_00565520 (INI string reader), FUN_00557350 (D3D material ctor), FUN_004cad30 (color parser), FUN_004cada0 (blend mode parser)

**Globals:** DAT_0059e8b4 (ASD envelope scale), DAT_0059e43c (physics constant), DAT_0059eae0 (FLT_MAX)

**Moddability:** configurable — all fields read from .MTS files
| 0x004a24d0 | 48 | Pit crew action mapper | FRONT_JACK_UP/DOWN, REAR_JACK_UP/DOWN, LOLLIPOP_DOWN → action codes |
| 0x00455290 | 43 | Control binding UI | Registers 43 control name strings (Steer, Brake, Gears, LCD, etc.) |
| 0x00463160 | 35 | NetComm command line | -password, -connect, join request parsing |
| 0x0045d890 | 572 | NetComm session msg | Session setup, track sync, player join/leave, file mismatch |

**None are moddable.** All are infrastructure: input devices, config
files, graphics materials, pit crew animations, control bindings, multiplayer
networking. No physics, AI, or session logic.

---

## FUN_004cdd80 - Track Surface Material Loader
### FUN_004cdd80 — Track Surface Material Loader

Reads `MATERIALS` section. Material types: GUARDRAIL, SOLIDWALL, TIREWALL, RUMBLE.

**Material struct (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | GripLevel | From file |
| +0x0c | GripLevel2 | Computed (grip - offset) |
| +0x10 | Resistance | Collision resistance |
| +0x14 | BumpAmp | × _DAT_0059e7f8 at load |
| +0x18 | BumpFreq | _DAT_0059ed28 / wavelen (min 3.0) |
| +0x1c | Spring | Spring rate |
| +0x20 | Damper | Damper rate |
| +0x24 | CollFrict | Collision friction |
| +0x28 | Sparks | Sparks texture/effect |
| +0x2c | Scraping | Bool — scraping sound on collision |
| +0x30–0x38 | Sound IDs | 3 sound indices |
| +0x60 | Legal flag | Bool — is material legal (track surface) |

Also reads: LEGAL (bool), RESISTANCE, BUMPAMP, BUMPWAVELEN, SPRING, DAMPER,
COLLFRICT, SPARKS, SCRAPING, SOUND.

---

## FUN_0040d4c0 - Race Commentary/Director System
### FUN_0040d4c0 — Race Commentary/Director System

Reads scripted event sequences for race direction/commentary.

**Event types (param_1 + 0x24):**
| Code | Event |
|------|-------|
| 0 | Unknown/default |
| 2 | CAMERA_ACQUIRE_CONTROL |
| 3 | CAMERA_RELEASE_CONTROL |
| 4 | CAMERA_SELECT |
| 5 | CAMERA_TARGET_SELECT |
| 6 | CAMERA_SET_LAST |
| 7 | COMMENTARY_START |
| 8 | COMMENTARY_STOP |
| 9 | FLY_OVER |
| 10 | GRIDWALK |
| 0xb | (unknown) |
| 0xc | SCRIPT_END |

Each event has `Probability` (default 1.0) and additional parameters.
This is the race director scripting system — controls camera cuts, commentary
triggers, and visual events during race sessions.

**Event struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x04 | event ID |
| +0x0c | Probability |
| +0x10 | (param) |
| +0x24 | event type code |
| +0x28 | (unknown) |

---

## FUN_0049ca00 - Cockpit Dashboard LED/Gauge Setup
### FUN_0049ca00 — Cockpit Dashboard LED/Gauge Setup

Loads cockpit textures and LED indicators.

**Gauge textures (stride 0x4c per gauge):**
| Offset | Texture |
|--------|---------|
| +0x60 | TAC_01.TGA (tachometer) |
| +0xac | WATERTEMP_COCKPIT.TGA |
| +0xf8 | OILTEMP_COCKPIT.TGA |
| +0x144 | OILPRESS_COCKPIT.TGA |
| +0x190 | FUEL_COCKPIT.TGA |

**LED textures (at param_1 + 0x20–0x48):**
| Offset | LED |
|--------|-----|
| +0x20 | LED165 (165°C temp) |
| +0x24 | LED170 |
| +0x28 | LED175 |
| +0x2c | LED182 |
| +0x30 | LEDSL (shift light) |
| +0x34 | LEDPSY (pit speed yellow) |
| +0x38 | LEDPSR (pit speed red) |
| +0x3c | LEDLF (low fuel) |
| +0x40 | LEDFR (fuel red) |
| +0x44 | LEDFY (fuel yellow) |
| +0x48 | LEDFB (fuel blue) |

**Font textures:** FONTREAD, FONTLCD, FONTAIDS, LCD00, LCD01.

Not moddable — cockpit display only.

---

## FUN_0042e530 - Track Config / Garage Auto-Setup
### FUN_0042e530 — Track Config / Garage Auto-Setup

Reads `RearSpoilerAngle` and `Track Type` (Road Course vs other) from config.
Adjusts wing angles, gear ratios, spoiler positions based on track type.

Complex garage auto-configuration logic. Uses many vehicle struct offsets for
aero data (+0x6b0, +0x970, +0x12b0, +0x12c0, +0x12c4), gear data (+0x130,
+0x138, +0x144, +0x3f0, +0x3f8, +0x400, +0x404), and wing position arrays
(+0xff0, +0x1030, +0x1070, +0x10b0, +0x1170, +0x11b0, +0x11f0, +0x1230,
+0x1f0 stride 0x2c0 × 4).

**Globals:**
- `DAT_007c56a4` — session type (nonzero = active)
- `DAT_008acf8c` — total race laps

---

## FUN_00417f60 - Track Name Lookup
### FUN_00417f60 — Track Name → Display ID Lookup

Similar to driver name database (FUN_00415d90). Uses scene array
(`DAT_008ac490`, stride 0x18c). 20+ nested `FUN_00566810` string compares
returning track display IDs. Lookup table only — no game logic.

---

## specialfx.cpp - Special Effects Manager (6 functions)
### specialfx.cpp — Special Effects Manager (6 functions)

| Function | Name | Content |
|----------|------|---------|
| FUN_004cee90 | SpecialFX::Enter() | Log only |
### FUN_004ceec0 — SpecialFX::Setup()

Empty setup stub. Logs entry only.

**Key logic:**
- Logs entry via FUN_004d7aa0, no other operations

**Moddability:** hardcoded
| FUN_004cf070 | SpecialFX::Init() | **490 lines.** Loads terrain.ini. Reads TRACKVARS, FEEDBACK, LOOSE sections. REACTION materials. INCLUDETRACKS/EXCLUDETRACKS. Loads CMAPS.MAS. Material system init (FUN_004ca480 per material). Reads AIDryGrip, AIWetGrip. Counts LPTREE scene nodes. |
### FUN_004cfc90 — SpecialFX::Restart()

Debug-logging-only stub. Logs "Entered SpecialFX::Restart()" when debug enabled. No state changes.

**Key logic:**
- Calls FUN_004d7a50(2) to check debug logging at source line 0xcdf
- If enabled, writes "Entered SpecialFX::Restart()" to debug buffer
- No special effects state reset performed

**Calls:** FUN_004d7a50 (debug gate), FUN_004d7aa0 (debug log write)
| FUN_004cfed0 | SpecialFX::Post() | Log + cleanup (frees arrays, releases resources) |

### FUN_004cfed0 — SpecialFX::Post()

Special effects manager post-update cleanup. Frees all allocated effect arrays.

**Key logic:**
- Sets param_1[0] = 0 (LPTREE count)
- Frees LPTREE array (param_1[1]): iterates each element calling FUN_004ca280, then frees array via FUN_00587bcf
- Calls FUN_0044c470 (particle cleanup)
- Frees feedback array (param_1[3]): iterates FUN_00499ae0 per element, then frees
- Zeros param_1[2] (feedback count)
- Frees loose material array (param_1[5]): iterates FUN_004ca410 per element, then frees
- Zeros all remaining struct fields param_1[0] through param_1[0xb]

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| [0] | LPTREE count |
| [1] | LPTREE array ptr |
| [2] | Feedback count |
| [3] | Feedback array ptr |
| [4] | Loose material count |
| [5] | Loose material array ptr |
| [6]–[0xb] | Zeros |

**Calls:** FUN_004ca280 (LPTREE destroy), FUN_00499ae0 (feedback destroy), FUN_004ca410 (loose material destroy), FUN_00587bcf (free), FUN_0044c470 (particle cleanup)
| FUN_004cfff0 | SpecialFX::Exit() | Log only |

**SpecialFX struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x00 | LPTREE count |
| +0x01 | LPTREE array (stride 0x3c) |
| +0x02 | feedback count |
| +0x03 | feedback array (stride 0x6c) |
| +0x04 | loose material count |
| +0x05 | loose material array (stride 0x6c) |
| +0x06–0x0a | special material pointers (types 0xc, 0xd, 1, 3, 4) |
| +0x0b | scene extents |
| +0x0c | AIDryGrip |
| +0x0d | AIWetGrip |

**New globals:**
- `DAT_008ac48c` — current scene index
- `DAT_007ce5ec` — settings file path

### FUN_004d4a80 — Telemetry Data Dump

Debug telemetry logger. Outputs comprehensive vehicle state data to log stream via FUN_004d5be0.

**Key logic:**
- Gate: checks VehicleCount > 0, DAT_007ce9d0 > 0, and (SessionType != 7 or DAT_007ce9f4 != 0)
- Finds first vehicle in VehiclePtrArray (DAT_007c54f0) with param_2+13000 == 0 (active)
- Generates random 4-byte seed, computes XOR-based session identifier (DAT_007c935c ^ 0x516141f2)
- Outputs labeled telemetry per wheel: wheelspin, suspension deflection, ride height, tire temps (left/center/right), tire pressure, tire wear, corner weight
- Outputs vehicle-level: water temp, oil temp, RPM, clutch, throttle, brake, steering (raw/filtered), elapsed time, position, yaw, accelerations
- Reads vehicle struct: DriverName (+0x4620), VehicleDescription (+0x4678), FilePath (+0x4714), data at +0x4794, UnknownID1 (+0x4898) for vehicle file lookup

**Struct offsets (param_2 - vehicle):**
| Offset | Field |
|--------|-------|
| +0x4620 | DriverName |
| +0x4678 | VehicleDescription |
| +0x4714 | FilePath |
| +0x4794 | Data field |
| +0x4898 | UnknownID1 |

**Globals:**
- `DAT_007c56a4` — SessionType (7 = race, gates output)
- `DAT_005c329c` — VehicleCount
- `DAT_007c54f0` — VehiclePtrArray
- `DAT_007ce9d0` — telemetry enable flag
- `DAT_007ce9f4` — telemetry gate flag
- `DAT_008ac488` — SceneFileCount
- `DAT_008ac394` — VehicleArray (stride 0x424)
- `DAT_007ce5ec` — settings file path
- `DAT_007ce5d0` — scene file path

**Calls:** FUN_004d5be0 (log output), FUN_0042bc10 (telemetry allowed?), FUN_004d5840 (time stamp), FUN_00587db0 (random), FUN_00588678 (RNG seed), FUN_004ceef0, FUN_004f34e0, FUN_0042e320, FUN_004f4270, FUN_004b3c60, FUN_00568a60, FUN_00566650, FUN_00588410, FUN_0042ddd0, FUN_004d5af0

---

## FUN_00408e20 — Camera View System (SWINGMAN/COCKPIT/TVCOCKPIT/NOSECAM/LOCALCAM)

Source: camera/scene module. Initializes camera views: SWINGMAN (TV broadcast cam), COCKPIT (driver cockpit), TVCOCKPIT (TV-style cockpit), NOSECAM (nose-mounted), LOCALCAM (local/free camera).

**Key logic:**
- First pass: reads scene file for up to 0x20 (32) camera definitions via FUN_004562f0
- Each camera matches one of 5 named types (string-compare chain)
- Second pass (param_2 != 0): allocates camera objects:
  - +0x1c: SWINGMAN camera (200 bytes, FUN_00456170)
  - +0x14: COCKPIT camera
  - +0x18: TVCOCKPIT camera
  - +0x10: NOSECAM camera
  - +0x20: array of additional cameras (param_1 count × 200 bytes, stride 200)
  - +0x24: (set by FUN_00408870 — 2SEATER/3SEATER/pits)
  - +0x28: UNUSED allocated camera
  - +0x2c: UNUSED allocated camera
  - +0x30: UNUSED allocated camera
- Sets camera_name field (+0x40) and count field (+0x44) for each camera
- Calls FUN_00408870 to initialize pit/2seater/3seater camera positions
- Allocates and initializes camera buffers (200 × count)

**Camera struct (200 bytes):**
| Offset | Field |
|--------|-------|
| +0x30 | FOV/settings |
| +0x34 | FOV/settings |
| +0x38 | Near clip plane |
| +0x3c | Far clip plane |
| +0x40 | Camera name ID (string match result) |
| +0x44 | Camera slot count |

**Globals used:**
- `DAT_005ea510` — (flag for additional camera setup)

**Calls:** FUN_005881c0 (init), FUN_005668b0 (file open), FUN_00456170 (camera alloc), FUN_00566b20 (file check), FUN_00566cc0 (file token), FUN_005651b0 (line read), FUN_00565520 (field read), FUN_00588410 (string compare), FUN_004562f0 (camera init), FUN_00457000 (camera data setup), FUN_00408870 (pit/camera pos), FUN_00456080 (camera field set), FUN_005668d0 (file close)

**Moddability:** No — camera system setup.

---

## FUN_0041d630 — Race Commentary / Best Lap Tracking

Source: commentary module. Generates race commentary messages based on driver positions, best lap times, and championship context. Uses track name formatting IDs (parameter to FUN_004144f0).

**Key logic:**
- Checks `DAT_007d0308` (race active flag) and `DAT_007cf3c8` (track condition)
- Iterates all vehicles sorted by finish position (+0x4060)
- For each position 1..N:
  - Tracks DNF count (+0x4064 == 2)
  - Tracks best overall lap time (+0x409c)
  - For player vehicle: generates position commentary (P1, leading, qualifying position comparison)
  - Logs driver number (+0x489c) and position
- After loop: generates "best lap" commentary with driver number
- Uses `FUN_004144f0` with format IDs (0x1bf–0x1dd) corresponding to track names (Indianapolis, Suzuka, Sepang, etc.)

**Commentary format IDs (subset):**
| ID | Meaning |
|----|---------|
| 0x1bf | Indianapolis (position 1 context) |
| 0x1c0 | Suzuka |
| 0x1c1 | Sepang |
| ... | ... |
| 0x1d9 | Last track |
| 0x1da | Leading message |
| 0x1dc | Best lap announcement |
| 0x1dd | Championship leader context |

**Globals used:**
- `DAT_007c54e8` — PlayerVehiclePtr
- `DAT_007c54f0` — VehiclePtrArray
- `DAT_005c329c` — VehicleCount
- `DAT_007d0308` — race active flag
- `DAT_007cf3c8` — track condition
- `DAT_008ac48c` — current scene index
- `DAT_008ac490` — SceneArray
- `DAT_007d2de8` — (flag for position tracking)

**Calls:** FUN_004144d0/FUN_004144f0 (commentary text dispatch), FUN_00418560 (text output), FUN_00566810 (file/string read)

**Moddability:** No — race commentary, writes no file fields.

---

## FUN_00408870 — Camera Position Definitions (2SEATER/3SEATER/Pits)

Source: camera module. Initializes fixed camera positions for 2SEATER, 3SEATER, LEFT_OF_PITS, and RIGHT_OF_PITS camera modes. Called by FUN_00408e20.

**Key logic:**
- Each camera allocated as 200-byte struct via `operator_new` + FUN_00456170 constructor
- Each camera named via FUN_00566650 (`"2SEATER"`, `"3SEATER"`, `"LEFT_OF_PITS"`, `"RIGHT_OF_PITS"`)
- Hardcoded position/rotation/scale values (float hex):
  - **2SEATER**: position (60.0, 45.0), FOV/zoom = 0.25, 500.0 range, scale = 1.0
  - **3SEATER**: position (60.0, 45.0), slightly different FOV/zoom = 0.2
  - **LEFT_OF_PITS**: position (60.0, 45.0), FOV = 0.2, offset (2.0, 0.4, 2.0)
  - **RIGHT_OF_PITS**: position (60.0, 45.0), FOV = 0.2, offset (-2.4, -2.28)
- Calls `FUN_00456fb0` for each camera to finalize setup

**Camera struct (+0x00):**
| Offset | Field |
|--------|-------|
| +0x30 | Parameter 1 (60.0 for all) |
| +0x34 | Parameter 2 (45.0 for all) |
| +0x38 | Parameter 3 (60.0 for all) |
| +0x3c | Parameter 4 (45.0 for all) |
| +0x40 | FOV/Zoom parameter |
| +0x44 | Range (500.0) |
| +0x48 | Scale X (1.0) |
| +0x4c | Scale Y (1.0) |
| +0x50 | Scale Z (1.0) |
| +0x54 | Aspect/clip X (0.5) |
| +0x58 | Aspect/clip Y (0.5) |
| +0x60 | Active flag (1) |
| +0x64–0x78 | Zero (padding) |
| +0x80 | Base offset X |
| +0x84 | Base offset Y |
| +0x88–0x90 | Position/rotation vector |
| +0x94–0xa8 | Look-at/direction quaternion |
| +0xa0 | Extra offset X |
| +0xa4 | Extra offset Y |
| +0xa8 | Extra offset Z |

**Calls:** FUN_00456170 (camera alloc), FUN_00566650 (name set), FUN_00456fb0 (camera finalize)

**Moddability:** No — camera position configuration only.

---

## FUN_0055b200 — Scene File Top-Level Parser

Source: scene/graphics module (`.scn` file loader). Top-level scene file parser that dispatches to sub-parsers for INCLUDEFILE, SEARCHPATH, GROUPMETHOD, FONTFILE, MASFILE, AMBIENTCOLOR, fog parameters, GROUP, INSTANCE, and LIGHT sections.

**Key logic:**
- Reads entire file into a buffer
- Tokenizes line-by-line:
  - `INCLUDEFILE`: recursive scene include via FUN_0055b6b0
  - `SEARCHPATH`: adds to search path via FUN_0053c6f0
  - `GROUPMETHOD`: `DYNAMIC` (0x2000) or `LINKSINGLE` (0x1000) — sets group behavior via FUN_0054a160
  - `FONTFILE`: loads font via FUN_0053cfe0/FUN_0053d340
  - `MASFILE`: opens MAS archive via FUN_0053ce10
  - `AMBIENTCOLOR`: sets ambient light via FUN_00543800 (3 floats)
  - `FOGMODE`: `LINEAR` (0x20000), `FOG` (0x40000), or `FOG` (0x80000) — stored at param_1 + 0x19c
  - `FOGCOLOR`: RGB shorts at param_1 + 0x188–0x18c
  - `FOGIN`/`FOGOUT`/`FOGDENSITY`: float values at param_1 + 0x194/0x198/400
  - Sub-dispatchers: scene rendering (FUN_0055a060), GROUP (FUN_0055a790), INSTANCE (FUN_0055a910), LIGHT (FUN_0055a500)

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x188 | Fog color R (short) |
| +0x18a | Fog color G (short) |
| +0x18c | Fog color B (short) |
| +0x194 | Fog in distance (float) |
| +0x198 | Fog out distance (float) |
| +0x190 (400) | Fog density (float) |
| +0x19c | Fog mode mask |

**Calls:** FUN_00559a40 (token init), FUN_0058803f (read file), FUN_00559a70 (token next), FUN_00559e20 (string token match), FUN_00559f00 (float token parse), FUN_0055b6b0 (include file), FUN_0053c6f0 (search path add), FUN_0053cfe0/FUN_0053d340 (font load), FUN_0053ce10 (MAS archive open), FUN_00543800 (ambient color), FUN_0054a160 (group method), FUN_0055a060 (scene render dispatch), FUN_0055a790 (group dispatch), FUN_0055a910 (instance dispatch), FUN_0055a500 (light dispatch), FUN_00587bcf (free buffer)

**Moddability:** No — scene file loading infrastructure.

---

## FUN_0055a910 — Scene Node / Instance Parser

Source: scene/graphics module. Parses a scene INSTANCE node from a `.scn` file. Handles child nodes: MESHFILE, ANIMFILE, LODIN/OUT, HATTARGET, COLLTARGET, SPHERETARGET, ZBUFFER, SHADOWCASTER/RECEIVER, REFLECTOR, MORPHTARGET, LIGHTOBJECT, ORIENT, MOVEABLE, STAMP, BILLBOARD, RENDER, CHANGE, SPECIAL1/2, PLANES, ACTOR, HATACTOR, RESPONSE.

**Key logic:**
- Allocates instance node struct (0x23c bytes) via FUN_0054a600
- Checks VISGROUPS mask against global DAT_008b8ee0 — skips if not visible
- Recursively parses INSTANCE children (self-call)
- For each supported token:
  - **MESHFILE**: loads mesh via FUN_0054a730, appends to mesh linked list
  - **ANIMFILE**: loads animation sequence, checks AUTOSTART flag
  - **LODIN**/**LODOUT**: sets LOD distance thresholds
  - **HATTARGET**/**COLLTARGET**/**SPHERETARGET**: sets target type flags (+0x14 bitmask)
  - **ZBUFFER**: enables/disables Z-buffer (bit 0xd)
  - **SHADOWCASTER**/**SHADOWOBJECT**: registers shadow casting via FUN_00545930
  - **SHADOWRECEIVER**: enables shadow receiving (bit 0xe), increments param_1+0x13c count
  - **REFLECTOR**: enables reflection (bit 0x11), increments param_1+0x174 count
  - **MORPHTARGET**: enables morph target (bit 0x15)
  - **LIGHTOBJECT**/**ORIENT**: sets orientation/light data, flags local_328
  - **MOVEABLE**/**STAMP**/**BILLBOARD**/**RENDER**/**CHANGE**: sets instance flags (+0x3c bitmask)
  - **SPECIAL1**/**SPECIAL2**: sets special rendering flags via FUN_0054c110
  - **PLANES**: stores clipping plane data at +0x50
  - **ACTOR**/**HATACTOR**: registers AI actor via FUN_00559820
  - **RESPONSE**: registers collision response via FUN_005598b0

**Node flags (+0x14 bitmask):**
| Bit | Flag |
|-----|------|
| 0x6 | COLLTARGET |
| 0x7 | SPHERETARGET |
| 0x8 | HATTARGET |
| 0xd | ZBUFFER disable |
| 0xe | Shadow receiver |
| 0x11 | Reflector |
| 0x15 | Morph target |
| 0x19 | Shadow caster |

**Instance flags (+0x3c bitmask):**
| Bit | Flag |
|-----|------|
| 0x1 | MOVEABLE |
| 0x4 | RENDER disable |
| 0x8 | CHANGE disable |
| 0x9 | BILLBOARD |
| 0x10 | STAMP |
| 0x11 | (stamp sub-flag) |

**Calls:** FUN_00545f50, FUN_0054a600 (instance alloc), FUN_00559a70 (token next), FUN_00559f00 (float parse), FUN_00559e20 (token match), FUN_0054a730 (mesh load), FUN_0054d4e0 (LOD set), FUN_00545930 (shadow init), FUN_0054c110 (special flag), FUN_00559820 (actor register), FUN_005598b0 (response register), FUN_0054a770/FUN_0054a710 (cleanup), FUN_0054bb40/FUN_00551560/FUN_00551790 (anim), FUN_00551480 (anim start), FUN_0054b4d0 (orientation apply)

**Moddability:** No — scene graph rendering infrastructure.

---

## FUN_00419c50 — Per-Driver Race Commentary

Source: commentary module. Generates per-driver race commentary messages during a session. Related to FUN_0041d630 but handles individual driver events rather than overall race state.

**Key logic:**
- Checks DAT_007d0308 (race active) and DAT_007cf3c8 (track condition)
- Only for finished drivers (+0x4064 == 1) with no previous message (+0x4070 == 0)
- If driver is player (matching +0x4894 team ID):
  - Position 1 (winning): championship context — checks remaining races (FUN_004c2850/FUN_004c11d0/FUN_004c1190) for clinch scenario
  - Position 2+: generates position commentary (P2 "good", P7+ "need improvement")
- If driver is not player:
  - Position 1: announces driver name in lead
  - Position 2–5: announces driver gaining position

**Commentary format IDs (subset):**
| ID | Context |
|----|---------|
| 0x9d | Championship race count context |
| 0x9e | Normal position (non-winning) |
| 0x9f | Championship clinch announcement |
| 0xa0–0xb1 | Track-specific position commentary (same 18 tracks as FUN_0041d630) |
| 0x104 | Non-player position 2–5 |
| 0x105 | Non-player position 1 (lead) |

**Calls:** FUN_004144d0/FUN_004144f0 (commentary text), FUN_00418560 (text output), FUN_00566810 (string read), FUN_004c2850 (season data), FUN_004c11d0 (race count), FUN_004c1190 (remaining races), FUN_004c13a0 (driver points)

**Moddability:** No — race commentary only.

---

## FUN_00414e60 — Commentary TV/PWS Path Builder

Source: commentary module. Builds file paths for TV broadcast and PWS (pit wall screen) commentary files. Resolves season directory, track directory, circuit name, and language (English/???).

**Key logic:**
- Builds path: `SeasonDir\TrackDir\CircuitName\tvCircuitName_`
- Appends suffix from known values: `CountryB`, `CountryE`, `CircuitB`, `CircuitE`
- `CountryB` / `CountryE`: language-specific country name (E=English, B=??? maybe broadcast language)
- `CircuitB` / `CircuitE`: language-specific circuit name
- Checks file existence via FUN_00414900
- Registers valid paths via FUN_00417f60 with language/circuit flags

**Struct offsets (param_1 — list of 5 entries, +0x00/0x02/0x05/0x0a/0x12):**
| Offset | Field |
|--------|-------|
| +0x00 | Circuit/season name pointer |
| +0x02 | Path data |
| +0x05 | (entry 2, CountryE) |
| +0x0a | (entry 3, CountryB) |
| +0x12 | (entry 4, CircuitE) |
| +0x17 | (entry 5, CircuitB) |

**Calls:** FUN_0058815f (path format), FUN_00414900 (file check), FUN_00417f60 (path register)

**Moddability:** No — commentary file path builder.

---

## FUN_0040db00 — Camera Target Name Resolver

Source: camera module. Maps camera target name strings to vehicle/driver pointers. Used by cinematic camera system to resolve camera focus target.

**Mappings:**
- `"<player>"` → player vehicle pointer (via FUN_0040d0b0)
- `"<original>"` → param_1 + 0x8c (original target)
- `"<last>"` → param_1 + 0x90 (last target)
- `"<any trackside>"` → track-side position (via FUN_0040c890)
- `"<none>"` → 0 (no target)

**Calls:** FUN_00588410 (string compare), FUN_0040d0b0 (player vehicle), FUN_0040c890 (trackside target)

**Moddability:** No — camera target system.

---

## FUN_004fc2f0 — Cloud Scene Object Random Selector

Source: SpecialFX / sky module. Scans scene nodes for cloud objects (name prefix `CLOUDS` = static cloud layer, `CLOUDR` = random cloud layer). Randomly selects one instance from each category to display.

**Key logic:**
- Scans param_2 scene nodes (param_2 + 0x118 = count, param_2 + 0x128 = list start, stride 0x100)
- Matches node name at +0x14 against `"CLOUDS"` (6 chars) or `"CLOUDR"` (6 chars)
- Builds two arrays of matching nodes (max 0x100 each)
- For CLOUDS: copies random node name to param_1 + 0x50
- For CLOUDR: copies random node name to param_1 + 0x84
- Random selection via `rand() % count`

**Calls:** _strncmp (name match), _rand (random selection)

**Moddability:** No — sky rendering, random visual selection only.

---

## FUN_0045d890 — NetComm Session Message Dispatcher

Source: NetComm.cpp [ida:fact]. Main network message handler for multiplayer sessions. Receives packets (param_2) and dispatches by message type encoded in first uint header bits 18–23.

**Key logic:**
- Header: `*param_2` bit 29–31 = base type, bits 18–23 = 6-bit message subtype
- **case 2** (Session Setup): Copies 0x68 dwords of session state, calls FUN_00460710 (session sync), posts "Next session" to message buffer
- **case 3** (Player Grid Data): Resets best-lap array to -1.0f (0xbf800000), fills from vehicle array DAT_007c54f0 indexed by TeamID (+0x4894), stores each vehicle's BestLapTime (+0x409c). If new player slot needed, allocates via FUN_0045e5f0/FUN_0045e5b0/FUN_0045e5d0. Sets DAT_008aff00 = 1
- **case 4** (Server Verify): Verifies server identity, copies 0x68 dwords to shared network buffer DAT_005f0774 (stride 0x1230), then calls FUN_00460520 to send
- **case 5** (Next Track): Posts "Next Track" to message buffer, validates, sleeps 1s
- **case 6** (Track Start/Load): Prepares buffer for track data receive, calls FUN_00461470 + FUN_00462460, deserializes via FUN_0045bc50, allocates linked list node
- **case 0x20** (Player Disconnected/Boot): If player matches local ID (FUN_00462300): posts "You have been booted", cleans up (FUN_0057a660), displays message. If other player: formats "[name] was removed from the game" from FUN_0045eb50 name lookup, displays
- **case 0x24** (File Mismatch Check): Validates 5 files against host: scene name, selected track filename, terrain.ini, season path, track dir. On mismatch: formats "mismatch" message, adds to mismatch linked list, calls FUN_004b33b0 (progress bar, code 4/6)
- **case 0x27** (Track File Transfer): Iterates linked file list, copies received data via _strncpy, adds to receive queue linked list, calls FUN_004b33b0 (progress bar)
- **case 0x28**: Sets session state to 2
- **case 0x29**: Sets session state to 3
- **case 0x2a** (Sync/Timeout): Compares time values, manages sync state transitions, adjusts timeout accumulator (+0x390)
- **default**: If session type matches or special flag, increments counters DAT_007d2e50/DAT_0083ee54 (+0x1b0 each), calls FUN_004b3a90

**Globals:**
- `DAT_005f0774` — shared network data buffer (stride 0x1230)
- `DAT_008aff00` — session ready flag
- `DAT_007d2e50` — session message counter
- `DAT_0083ee54` — session data offset
- `DAT_007c569c` — SessionType5 check
- `DAT_007ce254` / `DAT_007d1044` — flags for message display
- `DAT_0059f0b0` / `DAT_0059f0ac` — float constants

**Calls:** FUN_00460710 (session sync), FUN_00423a00 (string copy), FUN_004a0e70 (message buffer poll), FUN_0045bd10 (message display), FUN_004b33b0 (progress bar/event), FUN_0045e5f0/FUN_0045e5b0/FUN_0045e5d0 (player slot mgmt), FUN_00462250 (buffer write), FUN_00460520 (network send), FUN_00462300 (local player ID), FUN_0045eb50 (node ID → name), FUN_0057a660 (disconnect/cleanup), FUN_00461470/FUN_00462460 (track data prep), FUN_0045bc50 (deserialize), FUN_00566650 (path registry), FUN_00434030 (list mgmt), FUN_0045ebd0 (network cleanup), FUN_004b0170 (game state), FUN_004b3a90 (message process)

**Moddability:** No — multiplayer networking infrastructure, no file field access.

---

## FUN_0045fc50 — NetComm Player Slot Sync

Source: NetComm.cpp [ida:fact]. Scans player slots on each tick, detects join/leave events. Loads new players and unloads disconnected ones during a multiplayer session.

**Key logic:**
- Iterates active player slots (param_1 + 0x3e14 count, stride 0x8c starting at param_1 + 0x3d0)
- For each slot, checks activity via FUN_00461530
- **Player join**: If slot active and not previously tracked:
  - Checks season/scene data existence via FUN_004c69e0/FUN_00588410
  - Calls FUN_004c7b20 (season load), FUN_00566650 (path registry), FUN_0045c030/FUN_0045c850 (player state init)
  - If host slot: calls FUN_0042bc40 (track re-init), FUN_004ef5a0(0,0)
  - If client slot: calls FUN_004ef5a0(2,0)
  - Calls FUN_004bc2f0/FUN_004bc320 (lap/race data init)
  - Increments DAT_005c329c (VehicleCount)
  - Calls FUN_0042bc80 (vehicle array re-init), FUN_004c6c40 (scene gen), FUN_004c6d90, FUN_004d1030
  - If first player on track: calls FUN_004e0ed0 (per-vehicle), FUN_0042bbd0, FUN_0040d100, FUN_0049ca00, FUN_00433870
  - For non-host join: calls FUN_00465430 (set player control)
  - Displays "[name] has entered the game!" message
- **Player leave**: If previously active slot now inactive:
  - Displays "[name] left the game!" message
  - If host/client session: iterates receive queue to remove pending files for this player
  - Calls FUN_004c6e80 (scene cleanup), FUN_004ef5a0(-1, 0)
  - If leaver was current player: reassigns DAT_007c54e0/DAT_007c54dc to next available vehicle
  - Decrements DAT_005c329c, calls FUN_0042bc80
- Updates DAT_005c329c to match actual active count if mismatch detected

**Globals:**
- `DAT_005c329c` — VehicleCount
- `DAT_005ef9a0` — vehicle grid array (stride 0x1230)
- `DAT_005ecdcc` — per-player data (stride 0x1230)
- `DAT_005f0cf8` — player name array (stride 0x48c0)
- `DAT_005f0f6c` — per-player scene data (stride 0x1230)
- `DAT_007c54f0` — VehiclePtrArray
- `DAT_007c54dc` — current player index
- `DAT_007c54e0` — current vehicle ptr
- `DAT_007c54e4` — some vehicle index
- `DAT_008afea0` — elapsed time float
- `DAT_008ad25c` — debug message buffer

**Calls:** FUN_00461530 (slot active check), FUN_004c69e0 (season data access), FUN_00588410 (string compare), FUN_004c7b20 (season load), FUN_00566650 (path registry), FUN_0045c030/FUN_0045c850 (player init), FUN_00462330 (get slot ID), FUN_004ef5a0 (vehicle unload), FUN_0042bc40 (track init), FUN_004bc2f0/FUN_004bc320 (lap data init), FUN_0042bc80 (vehicle array rebuild), FUN_004c6c40 (scene gen), FUN_004c6d90/FUN_004d1030 (session state), FUN_004e0ed0 (per-vehicle init), FUN_0042bbd0 (track update), FUN_0040d100 (session timer), FUN_0049ca00 (score update), FUN_00433870 (player init), FUN_00465430 (set player control), FUN_004c6e80 (scene cleanup), FUN_00460cb0 (slot cleanup), FUN_004c8de0 (notify), FUN_00423a00 (string copy), FUN_0058815f (format), FUN_0045bd10 (message display), FUN_004d7a50/FUN_004d7aa0 (debug logging)

**Moddability:** No — networking infrastructure.

---

## FUN_0046b0c0 — Key Binding UI "Press key or controller"

Source: UI/input module. Modal key binding dialog. Captures key or controller button press and assigns to a control action.

**Key logic:**
- Gets current input device via FUN_00489940; validates index range
- State machine at param_1+0x1fc:
  - **State 1** (init): Stores device index at param_1+500, shows popup "POPUP_CONTROL_SET", displays "Press key or controller (ESC to skip) -" message, appends current control name, copies to pending buffer at DAT_005ec4cc. Advances to state 2.
  - **State 2** (await input): Reads input via FUN_00454d30. If ESC (0x59), handles "Reserved Key" warning (re-displays prompt). Stores raw input values at param_1+0x200 (data) and param_1+0x204 (type). Advances to state 3.
  - **State 3** (confirm): Calls FUN_0046a9c0 to finalize binding, re-enables UI via FUN_004988c0, closes popup. Resets to state 0.

**Strings:** Press key or controller (ESC to skip) -, POPUP_CONTROL_SET, Reserved Key

**Moddability:** No — input binding UI infrastructure.

---

## FUN_00470300 — UI Text Field Initialization (WWWW padding)

Source: UI module. Initializes various input text fields with WWWW... padding and clears buffers based on dialog control ID.

**Key logic:**
- Switch on param_1+0x304 (control ID):
  - 0x1AF: Clear DAT_007cd818 (26 chars), set pointer to "WWWWWWWWWWWWWWWWW" (17 Ws)
  - 0x1B0: Clear DAT_007cd834 (26 chars), reset param_1+0x2e8, set pointer to "WWWWWWWWWWWWWWW" (15 Ws)
  - 0x1B1: Clear DAT_007cd850 (15 chars), reset param_1+0x2e8
  - 0x1B2: Clear DAT_007cd860 (32 chars), set param_1+0x2e8 = 2
  - 0x1B3: Reset param_1+0x2e8, call FUN_0048b8f0(0xA0), set param_1+0xe5 = 1
  - 0x1B5: Clear DAT_007cd880 (32 chars)

**Strings:** WWWWWWWWWWWWWWWWW, WWWWWWWWWWWWWWW

**Moddability:** No — UI text field initialization.

---

## FUN_00470850 — "Selected Season" UI Init

Source: UI/season module. Initializes the season selection page with three option labels and calls FUN_00470960 to populate the season list.

**Key logic:**
- Sets virtual function table pointer for param_1
- Sets control ID param_1[199] = 0x191
- Outputs labels via FUN_00486f30:
  - "Selected Season" (heading via PTR_DAT_005be704)
  - "Normal" (mode option)
  - "Time Scaled" (mode option)
- Calls FUN_00470960 to populate season list

**Strings:** Selected Season, Time Scaled, Normal

**Moddability:** No — season selection page UI infrastructure.

---

## FUN_00462160 — Network Filter/Sort (numplayers/mapname/hostname)

Source: NetComm module. Selects network session filter or sort field for lobby display. Sets DAT_007d1020 to the selected filter type.

**Key logic:**
- If param_3 non-zero: toggles or sets active flag at param_1+0xc4
- Clamps DAT_007d1020 between DAT_007d1028 (min) and DAT_007d102c (max)
- Calls FUN_00461fc0 to apply filter:
  - If filter returns non-zero: sets DAT_007cd2a0 = 1 (refresh flag)
  - Based on filter type (DAT_007d1020):
    - 1: calls FUN_00563ec0 with 0 args (default sort)
    - 2: calls FUN_00563ec0("mapname", 3)
    - 3: calls FUN_00563ec0("numplayers", 0)
    - default: calls FUN_00563ec0("hostname", 3)
- If param_4 non-zero: sets refresh flag

**Strings:** numplayers, mapname, hostname

**Moddability:** No — multiplayer lobby filter/sort UI.

---

## FUN_004637a0 — AutoJoin Retry Loop

Source: NetComm.cpp [ida:fact]. Attempts auto-join with retry count. On success transitions to `Client Team Select`. On failure shows `AutoJoin Failure Page`.

**Key logic:**
- Checks flag at `*param_1 + 0xc6` — if zero, returns immediately
- Selects timeout values from `DAT_007d0410`/`DAT_007d0418`/`DAT_007d041c`
- Calls `FUN_00463750(0)` then `FUN_00462ce0` to attempt join
- If join fails: logs "Could not autojoin session"
- If join succeeds: enters retry loop displaying "Joining Session"
  - Checks session state via `FUN_00461cd0` — if state == 3 (connected): calls `FUN_004630d0`, on success cleans up vehicles, sets `DAT_007c5690=1`, `DAT_007c56a0=2`, transitions to `Client Team Select`
  - On timeout or join failure reason: calls `FUN_00466080`, if not already connected navigates to `AutoJoin Failure Page`
- Retries every `_DAT_0059e5fc` seconds (accumulated frame time)

**Globals:**
- `DAT_007d0410` — current timeout
- `DAT_007d0418`/`DAT_007d041c` — alternate timeout sources
- `DAT_007c5690` — session active flag
- `DAT_007c56a0` — session type
- `DAT_005cc9e8` — exit/cancel flag
- `DAT_007d0f28` — join timeout threshold
- `DAT_0059e5fc` — retry interval

**Calls:** FUN_00463750 (autojoin init), FUN_00462ce0 (join attempt), FUN_00461cd0 (session state), FUN_004630d0 (join complete check), FUN_00461550 (session finalize), FUN_004ef5a0 (vehicle unload), FUN_0042bc80 (vehicle array rebuild), FUN_00497940 (page navigate), FUN_00466080 (join failure check), FUN_00462da0 (failure reason string), FUN_004b0170 (game state update), FUN_00568ba0/FUN_00568be0/FUN_00568c60/FUN_00568cf0/FUN_00568d90 (frame/poll)

**Moddability:** No — multiplayer autojoin UI flow.

---

## FUN_00460520 — NetComm::SetSelfAsReady

Source: NetComm.cpp [ida:fact]. Registers self as ready with server. Host allocates a player slot; client uses server-assigned slot ID.

**Key logic:**
- Prepares buffer via `FUN_00461470` + `FUN_004623e0`
- If host (type != 1): sets type to 2
- If host (type 1 or 2): calls `FUN_0045e5b0`/`FUN_0045e5d0` to allocate local slot, sets flag via `FUN_004614f0(1,1)`
- If client (param_2 != -1): uses passed slot ID directly
- Restores buffer via `FUN_004623b0`
- Logs appropriate message: "Setting self as server node", "Setting self as slot %d", or "UNKNOWN NODE ID"

**Globals:**
- `DAT_007d0e50` — readiness flag
- `DAT_007c569c` — session type (5 = dedicated server)
- `DAT_008ad25c` — debug message buffer

**Calls:** FUN_00461470 (buffer write init), FUN_004623e0 (buffer lock), FUN_004614f0 (flag set/message type), FUN_0045e5b0/FUN_0045e5d0 (slot allocate), FUN_0057a810 (self node ID), FUN_004623b0 (buffer unlock), FUN_004b0170 (game state update)

**Moddability:** No — networking slot registration.

---

## FUN_00460e90 — Server Open Track Signal

Source: NetComm.cpp [ida:fact]. Sends "opening track" signal to clients, allocates message node.

**Key logic:**
- Calls `FUN_004b33b0(4,0x26,...)` — progress bar event for opening
- Calls `FUN_0057a680`/`FUN_0057a6a0`/`FUN_0057a690` — network send setup with header data
- Sets `param_1 + 0x29 = 1` (opening flag)
- Allocates 8-byte message node, fills with 0 and -1
- Formats "*** Opening " string via `FUN_00566650`
- If `DAT_007d0398` (network active): appends to param_1 linked list (at +0x1b770 head, +0x1b774 tail, +0x1b77c count)

**Globals:**
- `DAT_008afea0` — elapsed time (progress bar)
- `DAT_007c569c` — session type check
- `DAT_007d0398` — network active flag

**Calls:** FUN_004b33b0 (progress bar), FUN_0057a680/FUN_0057a6a0/FUN_0057a690 (network send), FUN_004c5920 (format buffer), FUN_00566650 (path registry / string set), FUN_004d7a50/FUN_004d7aa0 (debug log), FUN_00587bcf (free)

**Moddability:** No — networking track open signal.

---

## FUN_00461190 — Server Opened/Closed Notification

Source: NetComm.cpp [ida:fact]. Formats and broadcasts "The server %s %s" (opened/closed) message.

**Key logic:**
- If `param_2 == 0`: sets string to "closed", sets `+0x2c = -1.0f` (0xbf800000), clears `+0x29`
- If `param_2 != 0`: sets string to "opened", sets `+0x2c = DAT_0059f0b4`
- Allocates 8-byte message node
- Formats `"*** The server %s %s"` with opened/closed + session identifier
- Appends to param_1 linked list
- Calls `FUN_0045bd10` to display the message on screen

**Calls:** FUN_004c5920 (session ID format), FUN_0058815f (string format), FUN_00566650 (path set), FUN_0045bd10 (message display), FUN_004d7aa0 (debug log)

**Moddability:** No — networking server status message.

---

## FUN_00461020 — Server Close Track Signal

Source: NetComm.cpp [ida:fact]. Sends "closing track" signal, allocates message node. Mirror of FUN_00460e90.

**Key logic:**
- Calls `FUN_004b33b0(4,0x25,...)` — progress bar event for closing
- Network send via `FUN_0057a680`/`FUN_0057a6a0`/`FUN_0057a690`
- Sets `param_1 + 0x29 = 0` (closing flag)
- Allocates 8-byte message node
- Formats "*** Closing track" string
- Appends to linked list (same structure as FUN_00460e90)

**Globals:**
- `DAT_007d0398` — network active flag

**Calls:** Same pattern as FUN_00460e90: FUN_004b33b0, FUN_0057a680/.../.../..., FUN_00566650, FUN_00587bcf, FUN_004d7a50/FUN_004d7aa0

**Moddability:** No — networking track close signal.

---

## FUN_00460cb0 — Clear Player Slots

Source: NetComm.cpp [ida:fact]. Resets all player slot data and optionally allocates empty slots.

**Key logic:**
- Sets `param_1 + 0x3e14` (slot count) to 0
- Fills `param_1 + 0x3c74` array (104 slots × 4 bytes each) with -1 (unused)
- Calls `FUN_0057a800` (reset network state)
- If `param_2 != 0`: adds up to 0x68 (104) empty slots via `FUN_00461480`
- If connection type != 3 (not dedicated server): scans `param_1 + 0x1d4` array (104 node IDs) — marks orphaned entries (present in node list but not in slot list) as -1 and logs "Marking slot %d as unused, couldn't find nodeid %d in player list"

**Globals:**
- `DAT_007c569c` — session type check
- `DAT_008ad25c` — debug message buffer

**Calls:** FUN_0057a800 (network reset), FUN_00461480 (slot alloc), FUN_004d7a50/FUN_004d7aa0 (debug log)

**Moddability:** No — networking slot management.

---

## FUN_00464290 — SynchronizeWithServer

Source: NetComm.cpp [ida:fact]. Entry point for session sync. On first call initializes large buffer; on subsequent calls clears slots and sets network state.

**Key logic:**
- If `param_1 + 0x3fc4 == 0`: returns immediately (not connected)
- If `param_1 + 0x28 == 0` (first call):
  - Sets `+0x28 = 1`
  - Zeroes a buffer via `thunk_FUN_00500170` — 0x16240 bytes at stride 0x368 (90 iterations)
- If already initialized (subsequent calls):
  - Calls `FUN_00460c60` + `FUN_00460cb0(1)` — clear/refresh slots
  - If dedicated server (type 3): logs "Entering SynchronizeWithServer()", calls `FUN_0045f390`
- If host (type 1 or 2):
  - If `DAT_007c56a4 == 7` or (`DAT_007d105c != 0` && `DAT_007c56a4 == 5`): calls `FUN_0057a570(0)` (network inactive)
  - Else: calls `FUN_0057a570(1)` (network active)
- If client (type 3): sets `+0x14 = 1`, `+0x10 = DAT_0059f0a0`, `+0x390 = DAT_0059f0b8` (timeout values)
- Resets `+0x388` and `+0x380` to 0
- Calls `FUN_0045c8b0(1)` + `FUN_0045d4c0` — finalize sync

**Globals:**
- `DAT_007c56a4` — session state (5 = race, 7 = qualifying)
- `DAT_007d105c` — session flag
- `DAT_0059f0a0` / `DAT_0059f0b8` — float constants (timeout/default)

**Calls:** FUN_00460c60 (slot refresh), FUN_00460cb0 (clear slots), FUN_0045f390 (server sync), FUN_0057a570 (network state), FUN_0045c8b0 (sync finalize), FUN_0045d4c0 (session dispatch)

**Moddability:** No — networking sync initialization.

---

## FUN_00461de0 — Start Network Update (Internet/LAN)

Source: NetComm.cpp [ida:fact]. Starts network socket update for session discovery. Internet or LAN mode.

**Key logic:**
- If `param_1 + 0x1b79c != 0` (network active):
  - Closes existing socket via `FUN_00563e70`/`FUN_00563df0`
  - Opens new socket via `FUN_00563e00`
  - If `DAT_007d0e74 == 1` (Internet): calls `FUN_00562c80()`, logs "Starting Internet update..."
  - Else (LAN): calls `FUN_00563020(port, port+99, 1)`, logs "Starting LAN update on ports %d - %d..."

**Globals:**
- `DAT_007d0e74` — network type (0=LAN, 1=Internet)
- `DAT_007d0fe8` — base LAN port

**Calls:** FUN_00563e70 (socket close), FUN_00563df0 (network cleanup), FUN_00563e00 (socket create), FUN_00562c80 (Internet update init), FUN_00563020 (LAN broadcast init)

**Moddability:** No — networking socket management.

---

## FUN_00462010 — OpenPlay Session Query

Source: NetComm.cpp (OpenPlay API). Reads current session metadata from OpenPlay networking layer.

**Key logic:**
- Calls `FUN_00563e80` — if no network, returns 0
- Calls `FUN_005644b0("openplaying")` — gets session status string
- Compares against `"openstaging"` and `"openplaying"` — sets `param_5` boolean
- Calls `FUN_00564530(0)` — gets session flags
- Calls `FUN_004615c0(2, flag)` — sets team select mode
- Reads `"<NONAME>"` via `FUN_005644b0`, copies to `param_2` via `_strncpy` (max 0x1f chars)
- Reads `hostport` via `FUN_00564480` → stores at `param_2 + 0x70`
- Reads`maxplayers` via `FUN_00564530(0)` → stores at `param_2 + 0x72`
- Reads flags → stores at `param_2 + 0x65`/`0x66`
- If `param_3` provided: reads `"<NO MAP>"` via `FUN_005644b0`, copies to `param_3`

**Strings:** `openplaying`, `openstaging`, `gamemode`, `maxplayers`, `numplayers`, `mapname`, `hostport`, `hostname`

**Calls:** FUN_00563e80 (network check), FUN_005644b0 (OpenPlay session property), FUN_00588410 (string compare), FUN_00564530 (session flags), FUN_004615c0 (team select set), FUN_00564480 (host port read)

**Moddability:** No — OpenPlay API network query.

---

## FUN_004612e0 — Track Opening Progress Timer

Source: NetComm.cpp [ida:fact]. Counts down the track opening timer by frame delta. When timer expires, marks track as opened.

**Key logic:**
- Only runs for clients (type != 1 and type != 2) and when `+0x2c >= DAT_0059e440`
- If `+0x2c == DAT_0059f0b4`: calls `FUN_0045e570` (initial open setup)
- Subtracts frame time `_DAT_008afe90` from `+0x2c` (clamped to 0.01–0.5 range)
- When `+0x2c < DAT_0059e440`: sets `+0x29 = 1` (track opened), resets `+0x2c = -1.0f`

**Globals:**
- `DAT_008afe90` — frame delta time
- `DAT_0059e440` — zero threshold (~0.0f)
- `DAT_0059e444` / `DAT_0059e450` — frame time clamps (0.01 / 0.5)
- `DAT_0059f0b4` — initial open flag value

**Calls:** FUN_0045e570 (track open init), FUN_004d7a50/FUN_004d7aa0 (debug log)

**Moddability:** No — networking client track open timer.

---

## FUN_00462c00 — Send Join Request

Source: NetComm.cpp [ida:fact]. Formats and sends a join request to a remote server.

**Key logic:**
- Calls `FUN_00563e80` — if no network, returns 0
- Zeroes a buffer (0x50 bytes + null terminator)
- Calls `FUN_00564530(0)` + `FUN_00564490` — gets IP address string
- Formats `"%s:%d"` (IP:port) via `FUN_0058815f`
- Logs `"Sending Join Request to \"%s\""`
- Resets `*param_1 + 0x378 = 0` (join timeout)
- Calls `FUN_00462ce0(&local_50, param_3)` — sends join request with IP:port string

**Globals:**
- `DAT_007c569c` — session type check
- `DAT_008ad25c` — debug buffer

**Calls:** FUN_00563e80 (network check), FUN_00564530 (session flags), FUN_00564490 (IP address), FUN_0058815f (string format), FUN_00462ce0 (send join), FUN_004d7a50/FUN_004d7aa0 (debug log)

**Moddability:** No — networking join request.

---

## FUN_00460470 — Send Server OK Request

Source: NetComm.cpp [ida:fact]. Sends server OK packet. If host, delegates to SetSelfAsReady. If client, sends type-2 packet directly.

**Key logic:**
- If host (type 1 or 2): calls `FUN_00460520` (SetSelfAsReady) and returns
- If client (type 3): calls `FUN_004b33b0` progress bar (code 4, type 3)
- Calls `FUN_00462250` with header (type=2) — sends OK request packet
- Logs "Sending server OK request (ret=%s)" with success/failure string

**Calls:** FUN_00460520 (SetSelfAsReady), FUN_004b33b0 (progress bar), FUN_00462250 (packet send), FUN_004d7a50/FUN_004d7aa0 (debug log)

**Moddability:** No — networking server OK handshake.

---

## FUN_0045eb50 — Node ID to Player Name Lookup

Source: NetComm.cpp [ida:fact]. Maps a network node ID to a player slot name string.

**Key logic:**
- Iterates `param_1 + 0x3c74` array (up to `param_1 + 0x3e14` entries)
- Compares each entry against `param_2` (node ID)
- If match found: returns pointer to name at `param_1 + 0x398 + index * 0x8c`
- If not found: logs "*** Could not find name for nodeid %d", returns `&DAT_005c5dbc` (empty string)

**Struct layout (stride 0x8c per player slot):**
| Offset | Field |
|--------|-------|
| +0x00–0x03 | Node ID (at +0x3c74 array) |
| +0x04–0x8b | Player name string (at +0x398 + i*0x8c) |

**Globals:**
- `DAT_005c5dbc` — default empty name string
- `DAT_008ad25c` — debug buffer

**Calls:** FUN_004d7a50/FUN_004d7aa0 (debug log)

**Moddability:** No — networking name lookup utility.

---

## FUN_00461d20 — "You Have Been Booted" Handler

Source: NetComm.cpp. Detects boot notification and displays "You have been booted" message.

**Key logic:**
- Calls `FUN_00461cd0` — if session state not in 1..3, returns
- Decrements `*param_1 + 0x380` by frame time `_DAT_008afe90`
- Calls `FUN_0057a900` — checks if booted signal received
- If booted and flag `+0x30 == 0` (not yet displayed):
  - Copies "You have been booted" to `DAT_005ec4cc` message buffer
  - Displays via `FUN_0045bd10` with priority 3 and color 0x1020304
  - Sets `+0x30 = 1` (booted flag)

**Globals:**
- `DAT_008afe90` — frame time
- `DAT_005ec4cc` — message display buffer

**Calls:** FUN_00461cd0 (session state), FUN_0057a900 (boot check), FUN_00423a00 (string copy), FUN_0045bd10 (message display)

**Moddability:** No — networking boot/ban message.

---

## FUN_0045f950 — Session Synchronizer (Host/Client)

Source: NetComm.cpp. Host sends periodic keep-alive packets. Client receives clock sync and displays "Synchronizing game (%d ms)" message.

**Key logic:**
- **Host mode (type 1 or 2):**
  - Accumulates `param_2` (frame time) into `+0x38c`
  - When `+0x38c > DAT_0059e7ec` (timeout): resets accumulator, iterates all player slots
  - For each active slot: calls `FUN_0045ca20` (ping check), if OK sends type-2 keep-alive packet via `FUN_00462250`
- **Client mode (type 3):**
  - Decrements `+0x10` by `param_2`
  - When `+0x10 <= 0`: if `+0x14` flag set, clears it and resets `+0x10 = +0xc` (refill timeout)
  - Checks clock sync via `FUN_0057a610`:
    - If session type changed: triggers reload (`FUN_0042cf10`, `FUN_004a0da0`)
    - Calculates clock offset between server and local time
    - If offset > threshold: displays "Synchronizing game (%d ms)" message
    - If offset > large threshold: adjusts game time via `FUN_0042bda0`
    - Calls `FUN_004f9fc0` (clock sync)

**Globals:**
- `DAT_0059e7ec` — keep-alive interval
- `DAT_0059e440` — zero threshold
- `DAT_0059ea08` — clock sync tolerance
- `DAT_0059e84c` — display message threshold
- `DAT_0059e450` — large offset threshold
- `DAT_007c56a4` — session state
- `DAT_007ce254` — screen display flag

**Calls:** FUN_00461530 (slot active check), FUN_0045ca20 (ping), FUN_004b33b0 (progress bar), FUN_00462250 (packet send), FUN_0057a610 (clock sync read), FUN_0042cf10 (session reload), FUN_004a0da0 (screen update), FUN_0045e570 (open init), FUN_0045bd10 (message display), FUN_0042bda0 (time adjust), FUN_004f9fc0 (clock sync), FUN_004f9f60 (clock read)

**Moddability:** No — networking session sync/keep-alive.

---

## FUN_00460380 — Client Grid Display Timer

Source: NetComm.cpp. After entering `MPCLIENTGRID` page, waits for timer, then activates grid display and transitions to grid screen.

**Key logic:**
- Only runs for dedicated server client (type == 3)
- Decrements `+0x1c` by frame time `_DAT_008afe98`
- When `+0x1c < 0`:
  - Calls `FUN_00461550` + `FUN_004630d0` — finalize session and check grid readiness
  - If `+0x20 == 0` and scene index changed: sets `+0x20 = 1` (wait for scene load)
  - If `+0x20 == 1` (scene loaded):
    - Calls `FUN_00461900` + `FUN_004c54f0` + `FUN_004a0dc0` — finalize grid display
    - Calls `FUN_00497940("MPCLIENTGRID")` — navigate to grid screen
    - Resets `+0x20 = 0`
  - Resets `+0x1c = DAT_0059f0ac` (timer refill)

**Globals:**
- `DAT_008afe98` — frame time (alternate source)
- `DAT_0059e440` — zero threshold
- `DAT_008ac48c` — current scene index
- `DAT_007ce254` — screen display flag
- `DAT_0059f0ac` — timer refill constant

**Calls:** FUN_00461550 (session finalize), FUN_004630d0 (grid check), FUN_004c5690 (scene name format), FUN_00461900 (grid init), FUN_004c54f0 (vehicle grid setup), FUN_004a0dc0 (display), FUN_004a0030 (screen setup), FUN_00497940 (page navigate), FUN_004b0170 (game state update)

**Moddability:** No — networking client grid page timer.

---

## FUN_0040adb0 — Camera Shake / Nearby Vehicle Detection

Source: camera.cpp. Detects fast-moving vehicles near player and triggers camera shake/sound.

**Key logic:**
- Computes scaled world position from camera array
- If camera active and shake mode enabled:
  - Iterates all vehicles: checks proximity + speed thresholds
  - If triggered: random direction, camera shake intensity
  - No trigger: clear shake
- Always updates player camera orientation and rendering

**Vehicle offsets:** +0x58..0x60 (Velocity), +0x704..0x70c (Orientation), +0x744..0x74c (World position)

**Calls:** FUN_0040c780, FUN_00457a00, FUN_00457b00, FUN_004084a0, FUN_00541cd0, FUN_00456060, FUN_00456080, FUN_00542050, FUN_005423c0, FUN_00542680

**Moddability:** distance/speed thresholds via globals

---

## FUN_0040c540 — Get TeamID by Finish Position

Source: camera.cpp. Looks up vehicle TeamID by finish position offset.

**Key logic:**
- Computes target position from current finish position + direction
- Clamps to [1, VehicleCount]
- Scans vehicles for +0x4060 match, returns +0x4894 TeamID

**Globals:** DAT_005f0738 (stride 0x1230), DAT_005c329c, DAT_007c54f0

**Moddability:** no — pure lookup

---

## FUN_0040c5b0 — Camera Mode Change Request

Source: camera.cpp. Requests camera view mode change from director.

**Key logic:**
- Guard: player team differs from tracked vehicle team
- Switch on requested mode: case 2 blocked if DAT_007cfcc8, cases -1/1/2 set queued mode, call FUN_0040cde0(5,0)

**Calls:** FUN_0040cde0

**Moddability:** no

---

## FUN_0040c650 — Camera View Assignment (In-Car vs Chase)

Source: camera.cpp. Assigns view mode based on whether param_2 matches camera target.

**Key logic:**
- If param_2 == target: execute queued mode via FUN_0040cde0
- Else: switch to chase/free cam or reset
- If mode 3 + player flag: assign in-car (2) or director (5)

**Calls:** FUN_0040cde0, FUN_0040c610

**Moddability:** no

---

## FUN_0040c720 — Camera Lock Check

Source: camera.cpp. Returns 0 if camera should lock to player (mode 3), 1 otherwise.

**Key logic:**
- Returns 0 only if: player team != target team AND flag clear AND player vehicle flag set AND mode 3

**Moddability:** no

---

## FUN_0040c7a0 — Camera Target Update on Player Change

Source: camera.cpp. Updates camera target when player vehicle changes.

**Key logic:**
- If tracked TeamID != player TeamID:
  - If tracked < 0 (init): loop season data, determine view mode from DAT_007cfdc4
  - Else: get view mode from FUN_0040c8d0
  - Calls FUN_004e0ed0 with mode

**Calls:** FUN_004e0ed0, FUN_0040c8d0

**Moddability:** no

---

## FUN_0040ca30 — Main Camera Director Update

Source: camera.cpp. Per-frame camera director update.

**Key logic:**
- Calls FUN_0040c7a0 (target update), FUN_0040c910 (state update)
- If not initialized: set flag, call FUN_00409890
- Gets orientation vectors, calls FUN_004d8860 (scene update)
- If not skipping: get vehicle set, process mode change
- On-track: read player position or vtable target, compute camera matrix
- Off-track: pit camera via vtable +0x1c

**Calls:** FUN_0040c7a0, FUN_0040c910, FUN_00409890, FUN_00542460, FUN_00542420, FUN_004d8860, FUN_0040be70, FUN_0040c070, FUN_0040c5b0, FUN_004f0d20, FUN_0040c870, FUN_0053d450, FUN_004ccdc0

**Moddability:** no

---

## FUN_0040d290 — Camera Target: Race Leader

Source: camera.cpp. Sets camera to race leader (+/- offset).

**Key logic:**
- Gets player TeamID, calls FUN_0040c540(direction) where direction=1 or -1
- Calls FUN_0040d240 to set target

**Calls:** FUN_0040c540, FUN_0040d240

**Moddability:** no

---

## FUN_0040d2d0 — Camera Target: Next/Prev Vehicle

Source: camera.cpp. Cycles to next or previous vehicle.

**Key logic:**
- Computes target index +/-1, wraps at [0, VehicleCount)
- Gets TeamID, calls FUN_0040d240, refreshes scene nodes

**Calls:** FUN_0040d240, FUN_004f0d20

**Moddability:** no

---

## FUN_0040d340 — Camera Target: Current Tracked Vehicle

Source: camera.cpp. Sets camera to currently tracked vehicle.

**Key logic:**
- Gets TeamID from DAT_007c54f0[DAT_007c54e4], calls FUN_0040d240

**Calls:** FUN_0040d240

**Moddability:** no

---

## FUN_0040da30 — Camera Director Reset/Init

Source: camera.cpp. Resets camera director state.

**Key logic:**
- Sets active flag, clears state fields
- If player index >= 0: sets DAT_007c54e0 and DAT_007c54dc
- Allocates or resets director substruct

**Calls:** FUN_0040d1b0, FUN_00567f10, FUN_0040d470, FUN_0040d490

**Moddability:** no

---

## FUN_0040f600 — Camera Shake Ring Buffer Write

Source: camera.cpp. Writes shake/rumble data to ring buffer.

**Key logic:**
- Clears trigger flag, advances ring buffer
- Switch on shake type 0-5: each reads position, TeamID, maps to rumble code
- Writes orientation data, angular velocity, linear velocity
- Clamps and scales values

**Calls:** FUN_004b33b0 (force feedback), FUN_004b21f0 (orientation normalize), FUN_00588570

**Moddability:** yes — shake scale factors via globals

---

## FUN_004109d0 — Per-Vehicle Camera Update Iterator

Source: camera.cpp. Iterates all vehicles for camera/director effects.

**Key logic:**
- If ScoringGate==2: loops vehicles calling FUN_004f0430 and FUN_004ef180
- Else: loops objects, calls FUN_0040f300
- If ScoringGate==1 and time threshold exceeded: calls FUN_0040f600 per active object

**Calls:** FUN_004f0430, FUN_004ef180, FUN_0040f300, FUN_0040f600

**Moddability:** no

---

## FUN_004349a0 — Track Spline Extrapolation

Source: track_spline.cpp. Extends track centerline waypoints for smooth AI path.

**Key logic:**
- Zeroes 3x109 float array
- Computes midpoint and tangent for each waypoint pair
- Extrapolates 3 points forward and backward
- Negates X values, applies Y offset -0.15

**Calls:** FUN_00403cd0, FUN_00457f90

**Moddability:** configurable

---

## FUN_00443b70 — Gearbox / AI Shift Logic

Source: gearbox_ai.cpp. Computes gear shift points, throttle, clutch for AI.

**Key logic:**
- Determines shift direction from RPM vs shift point
- Downshift: clamps throttle to RPM ratio
- Blends throttle between shift point and redline
- If below torque peak: assist intervention
- Coasting/braking: decay, audio feedback on crossing threshold
- Anti-lag: interpolate torque from ring buffer

**Calls:** FUN_00447e00, FUN_004471f0, FUN_004f87c0, FUN_00447b10

**Moddability:** configurable

---

## FUN_004441f0 — Vehicle Main Physics Update

Source: vehicle.cpp. Central vehicle update — gearbox, wheels, terrain, steering, speed.

**Key logic:**
- Saves gear shift state, handles neutral/in-gear states
- 4-wheel collision/terrain/suspension loop
- DRS detection and deployment
- Speed modulation by grip, gradient, aero
- Steering response: slip angle, self-aligning torque
- Engine braking, clutch slip, ratio transitions
- Telemetry ring buffer output

**Calls:** FUN_00454da0, FUN_00447c70, FUN_004388d0, FUN_00403640, FUN_004352c0, FUN_004361d0, FUN_004d1100, FUN_004efb20, FUN_00566e40, FUN_004d1140, FUN_004ef6c0, FUN_0054b950, FUN_00447e00, FUN_00443af0, FUN_0059dab7

**Moddability:** extremely moddable — gear ratios, torque curves, grip, aero, steering

---

## FUN_004a3b50 — Camera / Position Animation

Source: game_logic. Computes camera position relative to vehicle using ring buffer random offsets.

**Key logic:**
- Gets vehicle position, bone transform
- If valid bone: compute direction, dot product, random offset from ring buffer
- Else: random offset, rotation matrix transform
- Collision/projection check adjusts height

**Calls:** FUN_004d1140, FUN_00403640, FUN_00566e40, FUN_004dd550, FUN_0044c4c0, FUN_004a2800

**Moddability:** no

---

## FUN_004fbd70 — Camera/Viewport Render Setup

Source: renderer. Processes player+opponent positions for HUD/map rendering.

**Key logic:**
- Gets camera position via FUN_00542460
- Positions player entity relative to camera
- Iterates 3 opponent slots with position updates
- Two render loops: head indicators and map/track indicators
- Lighting/color calculations based on time-of-day

**Calls:** FUN_004fc550, FUN_0040c910, FUN_00542460, FUN_0054b3b0, FUN_0054bf60, FUN_0054c230, FUN_0054c030, FUN_0054e100, FUN_0054e120, FUN_0054b3f0

**Moddability:** HUD sprite positions, global brightness

---

## FUN_004fc700 — String Name Matching

Source: renderer. Checks name string against stored names, updates selection.

**Key logic:**
- Compares full and short name strings
- If match: store selection index
- If no match: copy names, reset selection
- Calls FUN_004fc550(0) if scoring gate override

**Calls:** FUN_004b9a00, _strncpy, FUN_004fc550

**Moddability:** DAT_007c56a0 bit 0 toggles name matching

---

## FUN_0040aa20 — 3D Transform Object Allocator

Source: renderer.cpp. Allocates up to 4 transform objects (200 bytes each) plus one render object (0xcc bytes) if not yet created. Each transform stores position data at +0x88 (x), +0x8c (y), +0x90 (z), initialized to 360.0f.

**Key logic:**
- Checks if +0x10, +0x14, +0x18, +0x1c are null — allocates if needed
- Each new transform calls FUN_00456170 (object init)
- Sets XYZ position to 360.0f (0x43b40000) for each
- Allocates render object at +0x20, sets instance count=1

**Calls:** FUN_00456170, FUN_00566650

---

## FUN_0040b710 — Camera Transform Computation

Source: camera.cpp. Reads player vehicle position (DAT_007c54e0+0x58/0x5c/0x60), calls FUN_0040c780 and FUN_004084a0 for random/angle components. Invokes vtable method on +0x14 element through index*0xd0 into array at param_1+0xc.

**Key logic:**
- Computes pointer into vehicle array at stride 0xd0 from param_1+0xc
- Reads player vehicle position globals
- Calls random angle functions
- Calls camera shake transform
- Calls rendering position updates (FUN_00456060, FUN_00456080)

**Globals:** DAT_007c54e0 (PlayerVehiclePtr), _DAT_0059e65c

**Calls:** FUN_0040c780, FUN_004084a0, FUN_00456060, FUN_00456080, FUN_00541cd0, FUN_00542050, FUN_005423c0, FUN_00542680

**Moddability:** camera shake multiplier (_DAT_0059e65c)

---

## FUN_0040cde0 — Game Action State Machine

Source: input.cpp. Manages action state transitions. Uses param_2 as action ID (0-10). Switches between states: 3=neutral, 4=drive, 5=reverse lookback, 7-10=special modes. Manages camera views, screen modes, reverse gear.

**Key logic:**
- Cases 0-2: pass through
- Case 3 (neutral): checks if need to engage, calls FUN_00409440 and FUN_004e0ed0
- Case 4 (drive): same pattern
- Case 5 (reverse/lookback): checks speed vectors, calls vtable method
- Cases 7-10: mode-specific dispatch
- Sets param_1+0xc to new state

**Calls:** FUN_004e0ed0, FUN_00409440

**Globals:** DAT_007c54e0 (PlayerVehiclePtr), DAT_007cfe88

**Moddability:** state machine actions

---

## FUN_0040dc00 — String Path Extension Manipulation

Source: path_util.cpp. Builds a full path by concatenating DAT_007ce5d0 (base path) with DAT_005beb4c (extension). Finds last '.' and replaces with new extension from _DAT_005beb48.

**Key logic:**
- Concatenates base path with extension string
- Finds last '.' and replaces with extension
- Allocates new string buffer

**Globals:** DAT_007ce5d0 (base path), DAT_005beb4c, _DAT_005beb48

**Calls:** _strncpy, operator_new

---

## FUN_00475920 — Scene Load and Name Match

Source: scene_load.cpp. Calls DirectX scene setup (FUN_004cd8c0+0x1c). Gets entry name via FUN_0048d360/FUN_004693e0. Iterates scene list at param_1+0xe8 (count +0xf4/+0xf8). Compares names for match.

**Globals:** DAT_007cd8c0

**Calls:** FUN_0048d360, FUN_004693e0

---

## FUN_00476ec0 — Season Scene Search by Name

Source: season_scene.cpp. Calls vtable +0xa0, looks up DAT_007ce64c season via FUN_004c40b0. Searches linked list at param_1[0x3c] for matching entry at +4 field. Compares against scene name at +0x7c.

**Globals:** DAT_007ce64c

**Calls:** FUN_004c40b0

---

## FUN_00477640 — Season/Scene Name Accessor

Source: season_scene.cpp. Gets season entry via FUN_0048f590. Copies name from +0x3c to path registry via FUN_00566650.

**Calls:** FUN_0048f590, FUN_00566650

---

## FUN_00477680 — Track/Scene Config Loader

Source: scene_config.cpp. Gets season entry via FUN_0048f590. Calls FUN_004b1520 (track config) and FUN_004c4d50 (track load). Looks up scene via FUN_004c4ff0. Sets DAT_008ac38c and reads scene name.

**Globals:** DAT_008ac38c

**Calls:** FUN_0048f590, FUN_004b1520, FUN_004c4d50, FUN_004c4ff0, FUN_004c5130, FUN_004c4080, FUN_00566650

---

## FUN_00477720 — Season Scene Initialization

Source: season_init.cpp. Calls DirectX scene setup (DAT_007cd8c0+0x1c, type 0x14). Calls FUN_00476660 and FUN_00477810. If scene loaded: calls FUN_00476ec0, reads +0x174. Searches list matching DAT_007ce64c.

**Globals:** DAT_007cd8c0, DAT_007ce64c

**Calls:** FUN_00476660, FUN_00477810, FUN_00476ec0

---

## FUN_00477ba0 — Scene List Search by Path

Source: scene_search.cpp. Iterates scene list at param_1+0xf0 (count +0xfc). Compares each entry's name at +0x3c→+0x104 against DAT_007ce5ec (track directory).

**Globals:** DAT_007ce5ec

---

## FUN_0047f300 — Scene Filename Match Against Base Path

Source: scene_match.cpp. Iterates DAT_008ac488 scene entries at stride from DAT_008ac490. Compares each scene's name at +4 against DAT_007ce5d0 (base path) using FUN_00596c80. Returns on first match.

**Globals:** DAT_008ac488, DAT_008ac490, DAT_007ce5d0

**Calls:** FUN_00596c80

---

## FUN_004b16b0 — Track Configuration Name Builder

Source: track_cfg.cpp. Reads track name at param_1+0x2d50. If non-empty, calls FUN_004b1410 for configuration lookup. Copies result to path registry.

**Calls:** FUN_004b1410, FUN_00566650

---

## FUN_004c0a20 — Scene Name Lookup by Season

Source: scene_lookup.cpp. Looks up scene name from season config. Uses FUN_004c3f80/FUN_004c4080 to get scene data. Copies name from +0x7c to param_2 buffer.

**Globals:** DAT_005ea438

**Calls:** FUN_004c3f80, FUN_004c4080, _strncpy

---

## FUN_004c0a80 — Scene Name Pointer

Source: scene_lookup.cpp. Returns pointer to scene name at +0x7c. Uses FUN_004c3f80/FUN_004c4080 for lookup.

**Calls:** FUN_004c3f80, FUN_004c4080

---

## FUN_004c4ff0 — Season/Scene Match by Index

Source: season_scene.cpp. Searches linked list at param_1+8 for entries matching param_2 name. Iterates using DAT_008ac394 vehicle array with stride 0x424. Compares names via FUN_00588410.

**Globals:** DAT_008ac394 (VehicleArray, stride 0x424)

**Calls:** FUN_00588410

---

## FUN_004c51a0 — Track File Path Builder

Source: track_path.cpp. Builds scene/track file path. Strips extension (last '.') from param_3 filename. Concatenates with path components.

---

## FUN_004c55b0 — Track/Scene Loader

Source: track_load.cpp. Loads track/scene by name. Copies param_1 to local buffer. Calls FUN_00589901 for file access. Iterates DAT_008ac488 scene entries.

**Globals:** DAT_008ac488 (SceneFileCount)

**Calls:** FUN_00589901

---

## FUN_004c5690 — Scene Data Parser

Source: scene_parse.cpp. Parses scene configuration data. Reads param_1 string, formats into output buffer. Processes scene properties.

---

## FUN_004c5bb0 — Scene File Path Formatter

Source: scene_path.cpp. Copies param_1 to buffer (512 chars). Handles path formatting with extension.

---

## FUN_004c5d30 — Scene Sort Comparator

Source: scene_sort.cpp. Compares two scene entries for sorting. Primary key: param_1[3] vs param_2[3]. Secondary: compares names at stride 0x18c from DAT_008ac490, offset +0x104.

**Globals:** DAT_008ac490 (SceneArray, stride 0x18c)

**Calls:** FUN_00588410

---


## FUN_0040c240 — SceneFile Load by CurrentIndex

Source: track_setup.cpp (uses DAT_008ac48c CurrentSceneIndex). Loads scene file for the current scene index, extracts filename from path, and invokes scene object load method.

**Key logic:**
- If object's internal pointer at +0x1c is null, allocates 0x18 bytes and calls FUN_0040ac00 (scene object constructor)
- Reads CurrentSceneIndex (DAT_008ac48c) * stride 0x18c + SceneArray base (DAT_008ac490) to get scene entry
- Copies the scene file path string from the scene entry
- Backtracks from end of path to find '\\' separator, extracts filename portion
- Strips file extension after '.' from the extracted filename
- Compares result against DAT_005be880 (likely scene directory prefix)
- Concatenates directory prefix with stripped filename
- Calls virtual method at vtable+4 on the scene object at param_1+0x1c, passing the full path
- Returns 0 on success

**Globals:**
- `DAT_008ac48c` — CurrentSceneIndex (read)
- `DAT_008ac490` — SceneArray (read, stride 0x18c)
- `DAT_005be880` — Scene directory path string (read)

**Calls:** FUN_0040ac00 (scene object constructor)

**Moddability:** `hardcoded` — scene loading driven by current index

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c5830 — Current Scene Index Setter

Source: likely setupscene.cpp. Sets the global current scene index.

**Key logic:**
- Assign param_1 → DAT_008AC48C (CurrentSceneIndex)

**Globals:**
- `DAT_008AC48C` — CurrentSceneIndex, tracks active scene

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ade20 — TrackEnvironmentSelect (track env/weather handler)

Source: likely track/environment.cpp. Handles track environment selection based on boolean flag, sets camera count, and initializes environment subsystems.

**Key logic:**
- If param_2 == 0: sets *(param_1+0x1aec) = 1 (default env mode)
- Else: selects environment type based on global flags:
  - If `DAT_007cb710 & 1`: calls FUN_004ae750(2) (wet env)
  - Else if `DAT_007cbb0c & 1`: calls FUN_004ae750(3) (mixed env)
  - Else: calls FUN_004ae750(1) (dry env)
- If *(param_1+0x1b10) > 0 (track camera count):
  - Sets camera count = min(DAT_005ec4a8 + 1, 4)
  - Clamps between lower bound +0x1b18 and upper bound +0x1b1c
- Gets current scene from global scene array: `DAT_008ac48c * 0x18c + DAT_008ac490`
- Calls FUN_004c55b0(scene + 0x104) (scene environment setup)
- Calls initialization chain: FUN_004af3a0, FUN_004b0170, FUN_004adf10, FUN_004ae490, FUN_004ae9f0, FUN_004af220

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1aec | EnvMode | int, environment mode |
| +0x1b10 | CameraCount | int, number of track cameras |
| +0x1b18 | CameraMinBound | int, minimum cameras |
| +0x1b1c | CameraMaxBound | int, maximum cameras |

**Globals:**
- `DAT_007cb710` — Env flag (bit 0 = wet)
- `DAT_007cbb0c` — Env flag (bit 0 = mixed)
- `DAT_005ec4a8` — Camera index increment
- `DAT_008ac48c` — CurrentSceneIndex
- `DAT_008ac490` — SceneArray

**Calls:** FUN_004ae750 (env type set), FUN_004c55b0 (scene env setup), FUN_004af3a0, FUN_004b0170, FUN_004adf10, FUN_004ae490, FUN_004ae9f0, FUN_004af220

**Moddability:** `configurable` — scene/camera params from track .scn files

<!-- target: docs/06-session-race-logic.md -->

## FUN_0040c890 — Trackside Camera Target Lookup

Source: unknown | Confidence: medium
Looks up a trackside camera target by dispatching through 3 vtable interfaces.

**Key logic:**
- If param_2 != 0:
  - Dispatches vtable+0x1c through `**(param_1+0x18)` — if result non-zero, returns it
  - Falls through to `**(param_1+0x1c)` vtable+0x1c
  - Falls through to `**(param_1+0x20)` vtable+0x1c
- Returns 0 if param_2 == 0 or all dispatches return 0

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x18 | Interface1 | int* | First vtable interface |
| +0x1c | Interface2 | int* | Second vtable interface |
| +0x20 | Interface3 | int* | Third vtable interface |

**Calls:** vtable dispatch at +0x1c on 3 interfaces

**Used by system:** docs/09-track-system.md — trackside camera positioning (per docs/09)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00461db0 — Session State Check Wrapper

Source: unknown | Confidence: high
Returns whether FUN_00461cd0 returns non-zero.

**Key logic:**
- Calls FUN_00461cd0() — session state check (docs/01)
- Returns boolean: result != 0

**Calls:** FUN_00461cd0 (session state check, docs/01)

**Used by system:** docs/09-track-system.md — session state query

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0040f1c0 — Scene Object Loader State Machine

Source: unknown | Confidence: medium
Switch on param_1+0x1c (7 states). Loads objects, handles vehicle struct access in case 6.

**Used by system:** docs/09-track-system.md — track/scene loading

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

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

### FUN_00455290 — Input Action Registration

Registers all game input action names into the action system. Registers ~50 named actions covering all player controls.

**Key logic:**
- Calls FUN_00566650 for each action name constant — registers action string into input system
- Actions registered: steering, acceleration, braking, gears 1-7, neutral, reverse, clutch, TC override, launch control, LCD controls, pit request, RPM limiter, brake bias (F/R), look (left/right/behind/up/down/roll), instant replay, pause, restart race, zero head tracker, vehicle labels, ignition, starter, headlights, handbrake

**Note:** This function is about input action setup, not track system. Assigned to docs/09 per stub upgrade routing.

**Calls:** FUN_00566650 (register action name)

<!-- target: docs/10-vehicle-physics.md -->

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



### FUN_004cf070 — SpecialFX::Init

Special effects system initialization (specialfx.cpp). Parses CMAPS.MAS archive to load track effects, feedback materials, reaction triggers, and tree models.

**Key logic:**
- Determines scene path from CurrentSceneIndex (DAT_008ac48c) into SceneArray (DAT_008ac490), stride 0x18c
- Opens CMAPS.MAS file via FUN_00587db0; logs error "Could not open %s" if missing
- Parses TRACKVARS section: reads key=value pairs, allocates track effect entries (0x28-byte objects), stores position/name at FUN_004c9d10 result+0x20/0x24
- Parses FEEDBACK section: counts REACTION entries, tracks INCLUDETRACKS/EXCLUDETRACKS per track
- Parses LOOSE section: counts REACTION entries
- Allocates two arrays: track effects (param_1[3], stride 0x6c) and feedback entries (param_1[5], stride 0x6c)
- For each FEEDBACK track: allocates REACTION materials via FUN_004ca480, links to track effect slots
- Constructs path from SeasonDir (DAT_005ec3d8) and SeasonName (DAT_005ec428)
- Loads CMAPS.MAS search paths for additional content
- Categorizes effect types into param_1[6..10] slots by type code (0xc, 0xd, 1, 3, 4)
- Reads AIDryGrip and AIWetGrip parameters from config via FUN_004c58a0
- Counts LPTREE scene nodes and allocates tree model array (param_1[1], stride 0x3c)
- Initializes collision system (FUN_0044c0e0) and track grid (FUN_0044c4c0)

**Calls:** FUN_004ceef0, FUN_00587db0, FUN_00587ca0, FUN_00587c20, FUN_005651b0, FUN_00565520, FUN_004c9d10, FUN_004c58a0, FUN_004ca480, FUN_004caed0, FUN_004cdd80, FUN_004c9fb0, FUN_0044c0e0, FUN_0044c4c0, FUN_0058815f, FUN_00587f64, FUN_00587d02

**Moddability:** configurable — reads AIDryGrip, AIWetGrip from track config (moddable in .gdb files per docs/16)
