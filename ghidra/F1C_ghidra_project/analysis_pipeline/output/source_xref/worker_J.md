# Source Cross-Reference: docs/09-track-system.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `SpecialFX` | FUN_004cee90 (Enter), FUN_004ceec0 (Setup), FUN_004cf070 (Init), FUN_004cfc90 (Restart), FUN_004cfed0 (Post), FUN_004cfff0 (Exit) | HIGH | Direct source path match: specialfx.cpp. All 6 functions match the SpecialFX module lifecycle (Enter/Setup/Init/Restart/Post/Exit). rFactor Dedicated has `.?AVSpecialFX@@` RTTI entry. |
| `BaseCameraManager` | FUN_00408e20 (Camera View System) | HIGH | rFactor Dedicated RTTI: `.?AVBaseCameraManager@@`. F1C camera init function allocates 5 camera types (SWINGMAN/COCKPIT/TVCOCKPIT/NOSECAM/LOCALCAM) — matches BaseCameraManager base class with 5 derived camera managers. |
| `AttachedCameraManager` | FUN_00408e20 (attached camera sub-type) | MEDIUM | rFactor RTTI: `.?AVAttachedCameraManager@@`. F1C +0x24 camera slot (2SEATER/3SEATER/pits) matches attached/pit camera concept. |
| `TracksideCameraManager` | FUN_0040c890 (Trackside Camera Target Lookup) | HIGH | rFactor RTTI: `.?AVTracksideCameraManager@@`. F1C function name and purpose match directly — resolves trackside camera targets via vtable dispatch. |
| `CameraManager` | FUN_0040ca30 (Main Camera Director Update), FUN_0040da30 (Camera Director Reset/Init) | HIGH | rFactor RTTI: `.?AVCameraManager@@`. F1C per-frame camera director update with target tracking, orientation, mode changes. |
| `isiBaseCam` / `isiLocalCam` / `isiStaticCam` / `isiTrackingCam` | FUN_0040b710 (Camera Transform), FUN_0040aa20 (3D Transform Object Allocator) | MEDIUM | rFactor RTTI: `.?AVisiBaseCam@isiCam@@`, `.?AVisiStaticCam@isiCam@@`, `.?AVisiLocalCam@isiCam@@`, `.?AVisiTrackingCam@isiCam@@`. F1C camera transform computation at +0x14 array with stride 0xd0 suggests camera object array matching this hierarchy. |
| `SearchGrid` | FUN_004cf070 (SpecialFX::Init — collision grid setup) | HIGH | rFactor RTTI: `.?AVSearchGrid@@`. F1C SpecialFX::Init calls FUN_0044c0e0 (collision system) and FUN_0044c4c0 (track grid) — these likely constitute the SearchGrid class. |
| `Weather` | FUN_004ade20 (TrackEnvironmentSelect) | MEDIUM | rFactor RTTI: `.?AVWeather@@`. F1C env selection checks DAT_007cb710 (wet flag) and DAT_007cbb0c (mixed flag) — weather class manages track environment conditions. Also WeatherMode global (DAT_007cf080) used in session logic. |
| `NetComm` | FUN_0045d890 (Session Message Dispatcher), FUN_0045fc50 (Player Slot Sync), FUN_00460520 (SetSelfAsReady), FUN_004637a0 (AutoJoin Retry), FUN_00461db0 (Session State Check), FUN_00464290 (SynchronizeWithServer), FUN_00460e90 (Server Open Track), FUN_00461020 (Server Close Track), FUN_00460cb0 (Clear Player Slots), FUN_004612e0 (Track Opening Timer), FUN_0045f950 (Session Synchronizer), FUN_00460380 (Client Grid Display), FUN_00461d20 (Booted Handler), FUN_00460470 (Send Server OK), FUN_0045eb50 (Node ID Lookup), FUN_00462160 (Filter/Sort), FUN_00462c00 (Send Join), FUN_00462010 (OpenPlay Query), FUN_00461de0 (Start Network Update) | HIGH | rFactor RTTI: `.?AVNetComm@@`. All 19+ F1C networking functions use consistent pattern of param_1 as NetComm instance with stride-0x8c player slots and 0x1230 network buffers. |
| `ReplayMan` | FUN_004fbd70 (Camera/Viewport Render Setup — HUD/map rendering) | MEDIUM | rFactor RTTI: `.?AVReplayMan@@`. F1C render setup processes player+opponent positions for HUD — ReplayMan manages replay state/rendering. |
| `OnScreen` | FUN_0046b0c0 (Key Binding UI), FUN_00470300 (UI Text Field), FUN_00470850 (Season Selection UI) | HIGH | rFactor RTTI: `.?AVOnScreen@@`. UI functions using DAT_005ec4cc (message buffer), popup/modal patterns match OnScreen class. |
| `Options` | FUN_00462160 (Network Filter/Sort UI) | MEDIUM | rFactor RTTI: `.?AVOptions@@`. Network lobby filter/sort uses Options UI patterns (sliders, spinboxes). |
| `PitMan` | FUN_004a24d0 (Pit Crew Animation Mapper) | MEDIUM | rFactor RTTI: `.?AVPitMan@@`. Pit crew animation string-to-code mapping matches PitMan pitstop management. |
| `VidMan` | FUN_0055b200 (Scene File Parser), FUN_0055a910 (Scene Node Parser) | MEDIUM | rFactor RTTI: `.?AVVidMan@@`. Scene file loading and node parsing are renderer/video manager responsibilities. |
| `Render` | FUN_004fbd70 (Camera/Viewport Render Setup) | MEDIUM | rFactor RTTI: `.?AVRender@@`. HUD rendering with lighting/color calculations per time-of-day. |
| `Steward` | FUN_0041d630 (Best Lap Tracking Commentary), FUN_00419c50 (Per-Driver Commentary) | MEDIUM | rFactor RTTI: `.?AVSteward@@`. Race commentary based on driver positions, championship context, DNF tracking — steward-level race management. |
| `Game` | FUN_004441f0 (Vehicle Main Physics Update) | MEDIUM | rFactor RTTI: `.?AVGame@@`. Central vehicle update with gearbox, terrain, steering, DRS, telemetry — Game class owns per-frame vehicle simulation. |
| `PFController` | FUN_00455290 (Input Action Registration) | MEDIUM | rFactor RTTI: `.?AVPFController@@`. Registers 50+ input action names into action system — controller manages bindings. |

## Parameter-to-Offset Mappings

### Track Surface Material (FUN_004cdd80 — param_1 material struct)

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| GripLevel | MATERIALS | +0x08 | GripLevel | GripLevel | HIGH — exact name match to .MTS MATERIALS section parameter |
| Resistance | MATERIALS | +0x10 | Resistance | Resistance | HIGH — collision resistance, matches .MTS section |
| BumpAmp | MATERIALS | +0x14 | BumpAmp | BumpAmp | HIGH — bumped amplitude × global at load |
| BumpWavel.en | MATERIALS | +0x18 | BumpFreq | BumpWavelength | MEDIUM — F1C reads wavelen, divides into global; actual param name is BUMPWAVELEN |
| Spring | MATERIALS | +0x1c | Spring | Spring | HIGH — spring rate, matches .MTS |
| Damper | MATERIALS | +0x20 | Damper | Damper | HIGH — damper rate |
| CollFrict | MATERIALS | +0x24 | CollFrict | CollFriction | MEDIUM — collision friction; parameter name in .MTS is COLLFRICT |
| Sparks | MATERIALS | +0x28 | Sparks | Sparks | HIGH — sparks texture/effect |
| Scraping | MATERIALS | +0x2c | Scraping | Scraping | HIGH — scraping sound bool |
| Legal | MATERIALS | +0x60 | Legal flag | Legal | HIGH — bool, material is legal track surface |

### Scene File Parser (FUN_0055b200 — param_1 scene struct)

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| FOGMODE | scene | +0x19c | Fog mode mask | FogMode | HIGH — .scn file parameter, set to LINEAR(0x20000)/FOG(0x40000)/FOG(0x80000) |
| FOGCOLOR | scene | +0x188 | Fog color R/G/B | FogColor | HIGH — RGB shorts from .scn file |
| FOGIN | scene | +0x194 | Fog in distance | FogNear | MEDIUM — .scn parameter for fog start distance |
| FOGOUT | scene | +0x198 | Fog out distance | FogFar | MEDIUM — .scn parameter for fog end distance |
| FOGDENSITY | scene | +0x190 (400) | Fog density | FogDensity | HIGH — .scn parameter |
| AMBIENTCOLOR | scene | (via FUN_00543800) | — | AmbientColor | HIGH — .scn section, parsed via FUN_00543800 (3 floats) |

### Camera System (FUN_00408e20 — camera struct, 200 bytes)

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| CameraTarget | .veh | +0x30 | FOV/settings | CameraFOV | MEDIUM — .veh file camera target position config; F1C camera struct has position/FOV fields at +0x30–0x3c |

### Track Environment (FUN_004ade20 — param_1 track env struct)

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| — | — | +0x1aec | EnvMode | EnvironmentMode | MEDIUM — 0/default, 1=dry, 2=wet, 3=mixed |
| — | — | +0x1b10 | CameraCount | TrackCameraCount | MEDIUM — number of track cameras |
| — | — | +0x1b18 | CameraMinBound | CameraMinClamp | LOW — minimum camera count bound |
| — | — | +0x1b1c | CameraMaxBound | CameraMaxClamp | LOW — maximum camera count bound |

### SpecialFX Module (FUN_004cf070 — param_1 SpecialFX struct)

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| AIDryGrip | terrain.ini | +0xc | AIDryGrip | AIDryGrip | HIGH — AI grip on dry track, read from terrain.ini per docs/09 |
| AIWetGrip | terrain.ini | +0xd | AIWetGrip | AIWetGrip | HIGH — AI grip on wet track |

### Race Commentary (FUN_0041d630 — param_1 format ID usage)

No direct config parameter mapping — commentary uses format IDs (0x1bf–0x1dd) for track-specific messages. These IDs correspond to scene index positions in the season database, not HDV parameters.

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `Formation Lap:` | NASCAR_2003_Demo, rFactor | FUN_0041d630 (commentary) | RACE condition strings shared across ISI games — confirms commentary uses same formation lap terminology |
| `Caution Lap:` | NASCAR_2003_Demo, rFactor | — | Related to F1C track caution system |
| `FormationAndStart` | rFactor (RTTI: `.?AVPFData@W4FormationAndStart@@@@`) | — | Enum type `FormationAndStart` used in rFactor config — F1C uses similar formation/standing start logic |
| `FormationSpeedKPH` | rFactor | — | Speed parameter during formation lap |
| `FormationStandingStartloc` | rFactor | — | Start location for standing start |
| `WeatherCond` | rFactor (RTTI: `.?AVPFData@W4WeatherCond@@@@`) | FUN_004ade20 (TrackEnvironmentSelect) | rFactor enum `WeatherCond` matches F1C env mode logic (dry/wet/mixed) — DAT_007cb710 and DAT_007cbb0c flags correspond to weather conditions |
| `RadiatorRange` | rFactor HDV | FUN_0055b200 (scene parser) | Radiator setting parsed in BODYAERO section — F1C +0x1aec EnvMode related to radiator config |
| `CameraEditorResourceDir` | rFactor Config | — | rFactor uses same CAMED directory pattern for camera editing tools |
| `DevFiles\CamEd\` | NASCAR_2003_3DConfig, NASCAR_2003_Demo | FUN_00408e20, FUN_00408870 | Camera editor resource directory shared across all ISI games |
| `CUBE error loading scene file %s: %s` | rFactor | FUN_0055b200 (scene parser) | Scene file error format shared across ISI — CUBE engine scene loader pattern |
| `SourceInOutTime` | rFactor Dedicated | — | Debug timing instrumentation shared across binaries |
| `CUBE 3D Engine v` | F1_2000_Config | — | CUBE engine version string — earlier ISI versions used this in scene files |
| `Scoring` | rFactor | FUN_0041d630 (commentary) | Scoring-related commentary strings shared |
| `PLAYERVEHICLEID` | rFactor | — | Network session state variable across binaries |
| `CURRENTRACE` | rFactor | — | Session counter shared across games |
| `RACESESSION` | rFactor | — | Session type variable shared |
| `CUBEMAS4.00` / `CUBEMAS4.01` / `CUBEMAS4.10` | NASCAR_2003_Demo, NASCAR_2004_Demo | FUN_004cf070 (SpecialFX::Init) | MAS archive version strings — F1C opens CMAPS.MAS in season directory; these MAS versions are the container format for track data |
| `If 1, search specific vehicle directory for "<track>.<qual/race>.svm" ...` | NASCAR_2003_Demo | — | SVM file search pattern — confirms .svm files are track-specific AI setup files used across ISI games |
| `engine is knocked off`, `Couldn't find cam file or load cam file %s for vehicle %s` | rFactor | — | Camera file loading error shared — camera files (.cam) per vehicle per track |
| `GameData\Vehicles\` | rFactor | — | Vehicle directory path pattern |
| `TerrainName[16]` | rFactor SDK | FUN_004cdd80 | SDK TelemWheelV2.mTerrainName[16] — matches F1C material surface type codes (0=dry, 1=wet, 2=grass, 3=dirt, 4=gravel, 5=rumblestrip) used in track surface material system |
| `mSurfaceType` | rFactor SDK | FUN_004cdd80 | rFactor SDK field matches F1C track surface types — GUARDRAIL, SOLIDWALL, TIREWALL, RUMBLE in MATERIALS section |

## SDK Struct Alignment

### ScoringInfoV2 vs F1C Session/Track State

| SDK Field | SDK Offset | F1C Offset | Status | Notes |
|-----------|-----------|------------|--------|-------|
| mTrackName[64] | +0x00 | — | NOT FOUND | F1C stores track name in scene array DAT_008ac490 at +0x104, not in scoring struct |
| mSession | +0x40 | — | NOT FOUND | F1C uses globals DAT_007c56a4 (SessionType), DAT_007c56a8 (RacePhase) |
| mCurrentET | +0x44 | — | PARTIAL | F1C DAT_008afea0 (elapsed time) used in networking code |
| mEndET | +0x48 | — | NOT FOUND | — |
| mMaxLaps | +0x4c | — | PARTIAL | F1C DAT_008acf9c (TotalRaceLaps) — global, not struct field |
| mLapDist | +0x50 | — | NOT FOUND | — |
| mGamePhase | +0x58 | — | PARTIAL | F1C DAT_007c56a8 (RacePhase 0-7) — maps to rFactor game phases 0-8 but with different numbering |
| mYellowFlagState | +0x59 | — | PARTIAL | F1C has caution flag logic in session code — exact offset not identified |
| mSectorFlag[3] | +0x5a | — | NOT FOUND | — |
| mDarkCloud | +0x60 | — | NOT FOUND | F1C weather uses DAT_007cf080 (WeatherMode 0-5) + DAT_007cb710 flags — simpler model than rFactor |
| mRaining | +0x64 | — | PARTIAL | F1C DAT_007cf3c8 (track condition) — rain severity |
| mAmbientTemp | +0x68 | — | NOT FOUND | Track temperature not in known F1C globals |
| mTrackTemp | +0x6c | — | NOT FOUND | — |
| mWind | +0x70 | — | NOT FOUND | F1C has no wind vector in known globals |
| mOnPathWetness | +0x7c | — | NOT FOUND | — |
| mOffPathWetness | +0x80 | — | NOT FOUND | — |
| mVehicle (VehScoringInfoV2*) | +0x180 | — | NOT FOUND | F1C uses VehiclePtrArray DAT_007c54f0 with stride-based access instead |

### TelemWheelV2 vs F1C Track Surface System

| SDK Field | SDK Offset | F1C Offset | Status | Notes |
|-----------|-----------|------------|--------|-------|
| mTerrainName[16] | +0x24 | — | SHIFTED | F1C stores terrain type as byte code in material struct +0x60 (Legal flag), not as string |
| mSurfaceType | +0x34 | — | MATCH | F1C surface material types (GUARDRAIL=0, SOLIDWALL=1, TIREWALL=2, RUMBLE=3) map to rFactor surface type codes |

### VehicleScoringInfo vs F1C Commentary Positions

| SDK Field | SDK Offset | F1C Offset | Status | Notes |
|-----------|-----------|------------|--------|-------|
| mDriverName[32] | +0x00 | +0x4620 | MATCH | F1C vehicle struct at +0x4620 (DriverName) |
| mVehicleName[64] | +0x20 | +0x4678 | MATCH | F1C vehicle struct at +0x4678 (VehicleDescription) |
| mTotalLaps | +0x60 | — | PARTIAL | F1C lap count accessible via season scoring |
| mFinishStatus | +0x63 | +0x4064 | MATCH | F1C +0x4064 FinishState: 0=running, 1=finished, 2=DNF, 3=DSQ — matches SDK values exactly |
| mBestLapTime | +0x74 | +0x409c | SHIFTED | Same field, different offset — F1C struct layout differs from SDK |
| mNumPitstops | +0x98 | +0x1162 | SHIFTED | F1C pit stop count at +0x1162 |
| mPlace | V2:+0x6b | — | NOT FOUND | F1C finish position at +0x4060 — SDK has 1-based mPlace in V2 only |
| mTimeBehindNext | V2:+0x78 | — | NOT FOUND | — |
| mTimeBehindLeader | V2:+0x84 | — | NOT FOUND | — |

### TelemInfoBase vs F1C Vehicle Physics (FUN_004441f0)

| SDK Field | SDK Offset | F1C Offset | Status | Notes |
|-----------|-----------|------------|--------|-------|
| mEngineRPM | +0x60 | +0x1310/0x1318 | PARTIAL | F1C stores lifetime RPM range (+0x1310 min, +0x1318 max), not instantaneous RPM |
| mGear | +0x5c | — | NOT FOUND | Gear state in F1C likely in driveline struct |
| mUnfilteredThrottle | +0x70 | — | NOT FOUND | — |
| mUnfilteredBrake | +0x74 | — | NOT FOUND | — |
| mUnfilteredSteering | +0x78 | — | NOT FOUND | — |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| docs/09-track-system.md — doc file name | **docs/09-track-scene-specialfx.md** | File contains 100+ functions spanning track surfaces, scene loading, cameras, special effects, commentary, networking, and UI. Only ~15 are genuinely track-system. Rename would better reflect actual content. |
| FUN_004cdd80 field +0x18 "BumpFreq" | **BumpWavelength** | Parameter name in .MTS file is BUMPWAVELEN. The function computes frequency = global/wavelen, so the stored value is wavelength, not frequency. |
| FUN_004cdd80 field +0x0c "GripLevel2" | **GripReduced** | Computed as GripLevel - offset during load — it's the reduced grip value, not a second independent grip level. |
| FUN_004ade20 field +0x1aec "EnvMode" | **TrackEnvironmentMode** | Maps to the three rFactor WeatherCond enum states: dry(1)/wet(2)/mixed(3). Current name too generic. |
| FUN_0055b200 field +0x19c "Fog mode mask" | **FogMode** | Direct .scn file parameter name. The mask values (0x20000/0x40000/0x80000) map to rFactor fog mode enums. |
| FUN_0055b200 field +0x194 "Fog in distance" | **FogNear** | .scn parameter FOGIN — start distance for fog effect. |
| FUN_0055b200 field +0x198 "Fog out distance" | **FogFar** | .scn parameter FOGOUT — end distance for fog effect. |
| Section "Tier 4 — High String Count Infrastructure" | **Infrastructure Functions (non-track)** | All 8 functions in this section (FFB config, material shader, pit crew mapper, control binding, NetComm cmdline, NetComm session msg, Config.ini parser, SpecialFX::Exit) are NOT track-system — they're UI, input, networking, and config infrastructure routed here by stub upgrade automation. |
| FUN_004a24d0 "Pit Crew Animation Mapper" | **Move to docs/07-pit-system.md** | Pit crew animation string-to-code mapping belongs in pit system, not track system. |
| FUN_00455290 "Input Action Registration" | **Move to docs/01-engine-architecture.md** or **docs/21-audio-network-internals.md** | Input action name registration is engine infrastructure, not track system. |
| FUN_00463160 "NetComm::ParseCommandLine" | **Move to docs/21-audio-network-internals.md** | Network command-line parsing — belongs in network docs. |
| FUN_0045d890 and all other NetComm functions | **Move to docs/21-audio-network-internals.md** | All 19+ NetComm functions in this doc are networking infrastructure, not track system. |
| FUN_0046b0c0, FUN_00470300, FUN_00470850, FUN_00462160, FUN_004637a0 | **Move to docs/01-engine-architecture.md** or **keep if new UI doc** | UI functions for key binding, text field init, season selection, network filter, autojoin — none are track-system. |
| FUN_0040adb0, FUN_0040c540, FUN_0040c5b0, FUN_0040c650, FUN_0040c720, FUN_0040c7a0, FUN_0040ca30, FUN_0040d290, FUN_0040d2d0, FUN_0040d340, FUN_0040da30, FUN_0040f600, FUN_004109d0, FUN_00408e20, FUN_00408870, FUN_0040b710, FUN_0040cde0, FUN_0040db00, FUN_0040c890, FUN_0040aa20 | **Move to docs/01-engine-architecture.md** (or new **camera.md**) | 20+ camera functions dominate this doc file (~30% of content). Camera system is its own subsystem, not track system. |
| FUN_0041d630, FUN_00419c50, FUN_00414e60 | **Move to docs/06-session-race-logic.md** | Race commentary and best lap tracking belong in session/race logic. |
| FUN_00443b70, FUN_004441f0, FUN_004a3b50 | **Move to docs/10-vehicle-physics.md** | Gearbox AI shift logic, vehicle main physics update, camera position animation — vehicle physics. |
| FUN_004fbd70, FUN_004fc700 | **Move to docs/19-renderer.md** | Camera/viewport render setup and HUD name matching — rendering, not track. |
| FUN_0055b200, FUN_0055a910 | **Move to docs/19-renderer.md** | Scene file parser and scene node/instance parser — graphics rendering infrastructure. |
| FUN_004fc2f0 | **Move to docs/19-renderer.md** | Cloud scene object rendering — sky/visual, not track physics. |

## Summary

### RTTI Discoveries
17 rFactor classes map directly to F1C functions in this doc file. The strongest matches are:
- **SpecialFX** (6 functions, HIGH confidence) — exact source path match specialfx.cpp
- **NetComm** (19+ functions, HIGH confidence) — consistent network buffer patterns
- **CameraManager hierarchy** (20+ functions, HIGH confidence) — 4 rFactor camera manager classes match F1C camera system
- **OnScreen** (3 functions, HIGH confidence) — UI patterns match

### Structural Issues
This doc file is a **catch-all for stub-upgrade routing**. Only ~15 of ~100 functions belong in a "track system" doc. The remainder are:
- ~20 camera functions (30% of file)
- ~19 NetComm functions (20% of file)
- ~10 scene/rendering functions
- ~10 UI functions
- ~6 SpecialFX functions
- ~6 commentary functions
- ~5 vehicle physics functions
- ~4 infrastructure/config functions

### Config Parameters
Track surface material parameters from .MTS files map directly to FUN_004cdd80's struct offsets with HIGH confidence. Scene file parameters (fog, ambient) also map cleanly. No HDV-level parameters are directly used in track system functions.

### SDK Alignment
F1C's scoring/track state model is simpler than rFactor's ScoringInfoV2. F1C uses individual globals (SessionType, RacePhase, WeatherMode) rather than a unified struct. VehicleScoringInfo has shifted offsets compared to SDK (different struct layout in F1C vs rFactor).
