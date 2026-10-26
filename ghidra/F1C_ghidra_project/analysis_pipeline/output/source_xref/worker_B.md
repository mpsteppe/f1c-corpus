# Source Cross-Reference: docs/01-engine-architecture.md

## RTTI Class Mappings

rFactor Dedicated server RTTI classes mapped to F1C documented functions.

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `Game` | FUN_0042d370 (Game::Enter), FUN_0042d5d0 (Game::Setup), FUN_0042d6b0 (Game::Init), FUN_0042d7a0 (Game::Restart), FUN_0042d8a0 (Game::Post loop), FUN_0042da30 (Game::Post cleanup), FUN_0042db20 (Game::Exit) | HIGH | rFactor RTTI `.?AVGame@@` matches documented module name + lifecycle pattern. Source path `..\Source\game.cpp` in both binaries. 9 documented lifecycle functions. |
| `DynMan` | FUN_0042c130 (DynMan::Enter), FUN_0042c170 (DynMan::Setup), FUN_0042c1a0 (DynMan::Init), FUN_0042c3b0 (DynMan::Restart), FUN_0042c9f0 (DynMan::Post), FUN_0042ca70 (DynMan::Exit) | HIGH | rFactor RTTI `.?AVDynMan@@`. Source path `..\Source\dynman.cpp` in both. 6 lifecycle functions. |
| `SoundMan` | FUN_004c8a20 (Sound::Enter), FUN_004c8ab0 (Sound::Setup), FUN_004c8ae0 (Sound::Init), FUN_004c8b20 (Sound::Restart), FUN_004c8ca0 (Sound::Post), FUN_004c8d00 (Sound::Exit) | HIGH | rFactor RTTI `.?AVSoundMan@@`. Source path `..\Source\sound.cpp` in both. |
| `OnScreen` | FUN_0049ef40 (OnScreen::Enter), FUN_0049ef70 (OnScreen::Setup), FUN_0049efa0 (OnScreen::Init), FUN_0049f000 (OnScreen::Restart), FUN_0049f0d0 (OnScreen::Post), FUN_0049f120 (OnScreen::Exit) | HIGH | rFactor RTTI `.?AVOnScreen@@`. Source path `..\Source\onscreen.cpp` in both. |
| `HWInput` | FUN_00455bf0 (HWInput::Enter), FUN_00455c60 (HWInput::Setup), FUN_00455d50 (HWInput::Init), FUN_00455da0 (HWInput::Restart), FUN_00455e70 (HWInput::Post), FUN_00455f00 (HWInput::Exit) | HIGH | rFactor RTTI `.?AVHWInput@@`. Source path `..\Source\hwinput.cpp` in both. |
| `VidMan` | FUN_004fa000 (VidMan::Enter), FUN_004fa2f0 (VidMan::Setup), FUN_004fa320 (VidMan::Init), FUN_004fa640 (VidMan::Restart), FUN_004fac00 (VidMan::Post), FUN_004fad00 (VidMan::Exit) | HIGH | rFactor RTTI `.?AVVidMan@@`. Source path `..\Source\vidman.cpp` in both. |
| `Render` | FUN_004b4030 (Render::Init), FUN_004b4060 (Render::Restart), FUN_004b40a0 (screenshot), FUN_004b4170 (Render::Post) | HIGH | rFactor RTTI `.?AVRender@@`. Source path `..\Source\render.cpp` in both. |
| `BaseCameraManager` / `CameraManager` | FUN_0040c920 (CamMan::Init), FUN_0040c9e0 (CamMan::Restart), FUN_0040cce0 (CamMan::Post) | HIGH | rFactor RTTI `.?AVBaseCameraManager@@`, `.?AVCameraManager@@`, `.?AVAttachedCameraManager@@`, `.?AVTracksideCameraManager@@`. Source path `..\Source\camera.cpp`. |
| `OSMan` | FUN_004a18d0 (OSMan::Enter), FUN_004a1930 (OSMan::Exit) | HIGH | rFactor RTTI `.?AVOSMan@@`. Source path `..\Source\osman.cpp`. |
| `Steward` | FUN_004d36d0 (Steward::Setup), FUN_004d3cf0 (Steward::Restart), FUN_004d4580 (steward update, called in main loop), FUN_004d4600 (steward cleanup) | HIGH | rFactor RTTI `.?AVSteward@@`. Source path `..\Source\steward.cpp` in both. |
| `Options` / `AppOptions` | FUN_004a0eb0 (Options::Setup) | HIGH | rFactor RTTI `.?AVOptions@@`, `.?AVAppOptions@@`. Source path `..\Source\options.cpp`. Options UI class hierarchy (Options_Screens, Options_BaseMenuItem, Options_SliderBar, Options_CheckBox, etc.) all confirmed. |
| `PlayerFile` | FUN_004b18d0 (PlayerFile::Restart), FUN_004f9160 (player file load) | HIGH | rFactor RTTI `.?AVPlayerFile@@`. Source path `..\Source\plrfile.cpp` in both. |
| `SpecialFX` | FUN_004ceec0 (SpecialFX::Setup), FUN_004cfc90 (SpecialFX::Restart), FUN_004cfcc0 (SpecialFX::Post in game loop) | HIGH | rFactor RTTI `.?AVSpecialFX@@`. Source path `..\Source\specialfx.cpp` in both. |
| `NetComm` | FUN_00464290 (NetComm restart in Game::Restart), FUN_00463160 (NetComm cmdline), FUN_004643c0 (network update in main loop) | HIGH | rFactor RTTI `.?AVNetComm@@`. Source path `..\Source\NetComm.cpp`. |
| `ReplayMan` | FUN_004b1870 (replay/Bink setup gate in Game::Setup), FUN_004ba460 (replay restart), FUN_004ba180 (replay update in main loop) | HIGH | rFactor RTTI `.?AVReplayMan@@`. Source path `..\Source\Replay.cpp`. |
| `Controller` | FUN_0044f4e0, FUN_00455290, FUN_00455e50 (player/input update in main loop) | HIGH | rFactor RTTI `.?AVController@@`. Source path `..\Source\controls.cpp`. Controller handles all input binding. |
| `PitMan` | FUN_004a40f0 (called in Game::Restart as "steward" — may be PitMan instead) | MEDIUM | rFactor RTTI `.?AVPitMan@@`. The function labeled "steward" at FUN_004a40f0 may actually be PitMan. Check call chain. |
| `Weather` | Referenced indirectly through steward init (Game::Init calls steward init which configures weather) | MEDIUM | rFactor RTTI `.?AVWeather@@`. Source path `..\Source\weather.cpp` in both. Weather module functions not documented in doc/01 but called from game modules. |
| `SearchGrid` | FUN_004bdc10 (scene extent calculator) | HIGH | rFactor RTTI `.?AVSearchGrid@@`. Source path `..\Source\searchgrid.cpp` in both. |
| `AIDatabase` | Referenced indirectly through FUN_004333e0 (AI settings reload in DynMan::Restart) | MEDIUM | rFactor RTTI `.?AVAIDatabase@@`. Source path `..\Source\ai_db.cpp`. AI settings reloads confirmed. |

### UI Class Hierarchy Matches

rFactor RTTI reveals the full Options UI class hierarchy. These likely exist in F1C but are undocumented:

| rFactor Class | F1C Status | Notes |
|--------------|------------|-------|
| `Options_Screens` | Not documented | Screen management. May be merged into FUN_004a0eb0. |
| `Options_BaseMenuItem` | Not documented | Base class for all menu items |
| `Options_MenuItemSurface` | Not documented | Surface-based menu item |
| `Options_MenuItemText` | Not documented | Text menu items |
| `Options_MenuItemGizmo` | Not documented | Gizmo-backed menu items |
| `Options_BaseGizmo` | Not documented | Base UI gizmo class |
| `Options_GizmoBaseAttributes` | Not documented | Gizmo attribute container |
| `Options_SliderBar` | Not documented | Slider control |
| `Options_HSliderBar` | Not documented | Horizontal slider |
| `Options_CheckBox` | Not documented | Checkbox control |
| `Options_SpinBox` | Not documented | Spin control |
| `Options_IconSpinBox` | Not documented | Icon spin control |
| `Options_TextInputBox` | Not documented | Text input |
| `Options_DropDown` | Not documented | Dropdown control |
| `Options_DropDownSpinBox` | Not documented | Dropdown+spin hybrid |
| `Options_ScrollBox` / `Options_ScrollBoxDisplay` | Not documented | Scrollable container |
| `Options_Page` / `Options_NormalLayer` | Not documented | Page and layer containers |
| `Options_Bouncer` | Not documented | Animation/bounce effect |
| `Options_Animation_Gizmo` | Not documented | Animation gizmo |
| `Options_ToolTip` | Not documented | Tooltip support |
| `Options_Picture` | Not documented | Picture display |
| `Options_Text` | Not documented | Static text |
| `Options_BinkAnimation` / `Options_BinkAnimButton` | Not documented | Bink video UI elements |
| `Options_ToggleButton` | Not documented | Toggle button |
| `Options_ClickButton` | Not documented | Click button |
| `Options_ScrollingSelect` | Not documented | Scrolling selection |
| `Options_SceneDisplay` | Not documented | 3D scene in UI |
| `Options_SelectBoxItem` | Not documented | Selection box |
| `Options_TextBox` | Not documented | Text box |
| `Options_TabNavBar` | Not documented | Tab navigation |
| `Options_ThreeLineOpenTopBox` | Not documented | Three-line box |
| `Options_BaseLocation` | Not documented | Location base |
| `Options_IconSpinBoxItem` | Not documented | Icon spin item |

### TV Overlay Classes (Unconfirmed in F1C)

rFactor has `TvOverlayPage*` classes. F1C likely lacks these (isiMotor 2.0 feature):
- `TvOverlayPageBase`, `TvOverlayPageGridWalk`, `TvOverlayPageGridFocus`
- `TvOverlayPageGrandPrixTitle`, `TvOverlayPageStopGoPenalty`
- `TvOverlayPageFalseStart`, `TvOverlayPageComparisonGap`
- `TvOverlayPageLapOfHonor`, `TvOverlayPageRaceClassification`
- `TvOverlayPageLetterboxDependentHeader`, `TvOverlayPageInstantReplayHeader`
- `TvOverlayPageDemoModeHeader`, `TvOverlayPageRaceHUD`, `TvPitMenu`

These are rFactor broadcast/TV overlay features not present in F1C (isiMotor 1.5 vs 2.0).

### Loose Object Classes (Unconfirmed in F1C)

- `LooseObject`, `LooseCone`, `LoosePost`, `LooseSign` — likely in CollObjects.cpp
- `LooseWheel`, `LooseWing`, `LoosePart` — detached vehicle parts, likely in hdvehicle.cpp
- Not documented in docs/01-engine-architecture.md (separate system)

---

## Parameter-to-Offset Mappings

docs/01-engine-architecture.md describes engine architecture functions, not vehicle physics structs. Most struct offsets in this doc are for internal engine objects (timers, linked lists, mutexes, camera), NOT HDV-configurable vehicle parameters. However:

### Camera Manager Struct Offsets vs HDV Config

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| `CameraTarget` | .veh file | +0x08 (param_1) | CurrentCamera | CameraTarget | MEDIUM — CameraTarget is a float3 position in .veh; +0x08 is a pointer, not a position. Likely different layout. |
| N/A (camera index) | — | +0x2e | Flag | CameraActiveFlag | MEDIUM — likely a boolean/enum |
| N/A (camera index) | — | +0x38 | CameraIndex | CurrentCameraIndex | MEDIUM — set to -1 (none) |

### Performance Counter Timer Struct vs Config

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| N/A (internal timer) | — | +0x00 | Enabled | TimerEnabled | HIGH — flag at timer struct start |
| N/A | — | +0x48 | FlagByte | TimerModeFlags | HIGH — bit 0 = QPC mode |
| N/A | — | +0x08 | ScaleFactor | TimeScaleFactor | HIGH — double multiplier |

### No HDV Parameter Direct Matches

The engine architecture functions do NOT directly read HDV/PMM parameters. HDV parameters like `CGHeight`, `Mass`, `Inertia` etc. are consumed by hdvehicle.cpp / physics functions, not the state machine in docs/01. No parameter renames proposed.

---

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `"F1 Challenge 99-02_APP_MUTEX"` | rFactor (shared game mutex pattern) | FUN_004a18d0 (OSMan::Enter), FUN_004a1930 (OSMan::Exit) | Confirms OSMan uses the exact same mutex name string as mutex name. Confirms F1C retail binary name. |
| `"Entered %s::%s()"` (debug log pattern) | All ISI binaries | FUN_0042ca70 (DynMan::Exit), FUN_0049ef70 (OnScreen::Setup), FUN_004b4170 (Render::Post), FUN_004fa2f0 (VidMan::Setup) | Debug log format consistent across all isiMotor versions. `FUN_004d7aa0` is the shared debug log writer. |
| `"SourceInOutTime"` | rFactor, NASCAR | Multiple lifecycle functions | Profile trace string appears in both rFactor and F1C trace calls, confirming shared profiling infrastructure. |
| `"CUBE error loading scene file %s: %s"` | rFactor (`CUBE error loading scene file %s: %s`) | FUN_004fa320 (VidMan::Init) | Confirms VidMan::Init scene loading error path. Error string identical in both binaries. |
| `"No Device"` | NASCAR_2003_Demo, rFactor | FUN_004fa000 (VidMan::Enter) | Device detection error string found in VidMan::Enter. Confirms Direct3D device detection code. |
| `"Could not get extents of scene"` | Not found in other binaries (F1C-specific) | FUN_004bdc10 (searchgrid::scene extent) | F1C-specific error string. Search grid is present (rFactor has `SearchGrid` RTTI class) but message differs between games. |
| `"3DCONFIG.EXE"` | Not in other binaries (config exe name differs) | FUN_004fa000 (VidMan::Enter) | F1C launches `3DCONFIG.EXE`; NASCAR 2003 launches `3DConfig.exe`; rFactor launches `rF Config.exe`. Config exe name is game-specific. |
| `"Screen Saved"` | NASCAR_2003_Demo: `"Screen Saved"` | FUN_004b40a0 (screenshot handler) | Confirmed screenshot notification string shared with NASCAR 2003. |
| `"MAINVIEW"` | Not in crossref but consistent across ISI | FUN_0040c920 (CamMan::Init) | Scene node name "MAINVIEW" used to find main camera in scene graph. Consistent across isiMotor engine. |
| `"Initializing ISI Dedicated Server..."` | rFactor Dedicated | N/A (not in F1C — server init string) | rFactor Dedicated has server init string. F1C does NOT have dedicated server mode at this string level. |
| `"Entered Sound::%s()"` | NASCAR_2003_Demo (identicle pattern) | FUN_004c8a20–FUN_004c8d00 (Sound lifecycle) | Debug log pattern identical across binaries. Confirms Sound::Enter/Setup/Init/Restart/Post/Exit lifecycle. |
| `"MPCLIENTGRID"` | NASCAR_2003_Demo, NASCAR_2004_Demo | FUN_0042cf10 (MP vehicle placement) | Multiplayer client grid string shared. Confirms MP grid logic in state transition function. |
| `"RACECOND_formation"` / `"Formation Lap:"` / `"FormationAndStart"` | NASCAR_2003_Demo, rFactor | FUN_0042cf10 (state transition) | Formation lap state shared across all isiMotor games. `FormationAndStart` is an enum type in rFactor RTTI (`.?AV?$PFData@W4FormationAndStart@@@@`). |
| `"Pitstop Description"` / `"Pitstop Requested"` | rFactor, NASCAR | N/A (not in docs/01 — pit system) | Pitstop strings shared across all isiMotor games. Pit system is separate module (docs/07). |
| `"HotPacket_over_Winsock"` / `"<HotPacket::Winsock>"` | rFactor, NASCAR_2003_Demo | FUN_00463160 (NetComm cmdline) | Network transport layer name shared across all network-enabled ISI binaries. |
| `"CC_ViewMyVehicle"` / `"Control - View Original Vehicle"` | rFactor, NASCAR_2003_Demo | Not in docs/01 directly | Vehicle view control bindings. These are in HWInput control binding string table (FUN_00455290 has 43 string names). |
| `"APP_Slider_ForceFeedBack..."` (multiple) | NASCAR_2003_Demo, NASCAR_2004_Demo | Not in docs/01 directly | FFB slider controls. Part of Options UI hierarchy. Confirms Options::Setup calls into UI builder. |
| `"CGRearRange"`, `"CGRightRange"`, `"FuelRange"`, etc. | rFactor, NASCAR | Not in docs/01 (consumed by physics) | HDV parameter names. Not directly parsed by engine architecture functions, but loaded by hdvehicle.cpp parsers. |

---

## SDK Struct Alignment

Comparing rFactor SDK structs (from InternalsPlugin.hpp) against F1C internal structs documented in docs/01-engine-architecture.md.

**Note:** SDK structs are telemetry interfaces — F1C internal structs are game engine objects. Direct alignment is limited.

### Camera Manager Struct (param_1 in FUN_0040cce0)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| N/A (no SDK CameraManager struct) | — | +0x00: MAINVIEW scene node | NEW — internal CamMan struct, no SDK equivalent |
| N/A | — | +0x08: current camera pointer | NEW — internal |
| N/A | — | +0x18/+0x1c/+0x20: camera objects 1/2/3 | NEW — 3 temp camera slots |
| N/A | — | +0x2e: flag | NEW — state flag |
| N/A | — | +0x38: camera index (-1=none) | NEW — index into camera list |

**SDK Match:** `GraphicsInfo` / `GraphicsInfoV2` has `mCamPos` (+0x00) and `mCamOri` (+0x0c) — these are world camera transform, not the internal camera manager struct.

### Linked List Container (param_1 in FUN_005819c0, FUN_00586a40)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| N/A (no SDK linked list) | — | +0x00: HeadPtr | NEW — generic linked list container |
| N/A | — | +0x04: TailPtr | NEW — doubly-linked variant |
| N/A | — | +0x08: Count | NEW — node count |
| N/A | — | +0x0c: Capacity | NEW — capacity |

### Performance Timer struct (FUN_00556510, FUN_00568c60)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| N/A | — | +0x00: Enabled (int32) | NEW — internal performance timer |
| N/A | — | +0x08: ScaleFactor (double) | NEW — timer scaling |
| N/A | — | +0x10/+0x14: OtherAccum0/1 | NEW — accumulators |
| N/A | — | +0x18: CurrentLow (uint32) | NEW — QPC low |
| N/A | — | +0x1c: CurrentHigh (uint32) | NEW — QPC high |
| N/A | — | +0x20: LastLow (uint32) | NEW — previous sample low |
| N/A | — | +0x24: LastHigh (uint32) | NEW — previous sample high |
| N/A | — | +0x28/+0x2c: AccumLow/High (uint32) | NEW — accumulated time |
| N/A | — | +0x48: FlagByte (byte) | NEW — timer mode flags |

### Mutex/Sync Struct (FUN_00585770, FUN_00586560)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| N/A (no SDK mutex struct) | — | +0x54/+0xf0: MutexHandle (HANDLE) | NEW — Win32 mutex handle field at two different offset positions in different structs |
| N/A | — | +0x5c/+0x24: MutexValidFlag (byte) | NEW — active flag at different offsets |
| N/A | — | +0xec: SharedValue (int32) | NEW — value read under mutex |
| N/A | — | +0xf4: WaitTimeout (DWORD) | NEW — timeout for WaitForSingleObject |

### Message Node (FUN_00465300)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| N/A (no SDK message struct) | — | 0x1b0 byte allocation | NEW — message node size |

### VehicleGrid/Dynamics Array

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| N/A | — | stride 0x1230 | NEW — vehicle dynamics array stride in DAT_005ef9a0 |
| N/A | — | max 104 entries | NEW — max vehicles confirmed |

### SceneArray

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| N/A | — | stride 0x18c | NEW — scene array stride in DAT_008ac490 |

### Options Struct (FUN_0047e960)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| N/A | — | +0x44 (+0x11 int-indexed) | NEW — UI item list head |
| N/A | — | +0x48 (+0x12 int-indexed) | NEW — UI item list tail |
| N/A | — | +0x4c (+0x13 int-indexed) | NEW — current item |
| N/A | — | +0x50 (+0x14 int-indexed) | NEW — item count |
| N/A | — | +0xf0 (+0x3c int-indexed) | NEW — end marker (-1) |
| N/A | — | +0xf4 (+0x3d int-indexed) | NEW — option ID |

### Config/Race Mode Struct (FUN_00404890)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| N/A | — | +0x14 (+0x05 int-indexed) | NEW — InitFlag (byte) |
| N/A | — | +0x15 | NEW — InitFlag2 (byte) |
| N/A | — | +0x20 (+0x08 int-indexed) | NEW — StateCondition |
| N/A | — | +0x50 (+0x14 int-indexed) | NEW — Saved_DAT_007d2e44 |
| N/A | — | +0x54 (+0x15 int-indexed) | NEW — Saved_RaceMode |

### ScoringInfoV2 Alignment (rFactor SDK vs F1C Globals)

rFactor's `ScoringInfoV2` has `mGamePhase` (+0x48 F1C align estimate) which maps to:
- F1C `DAT_007c56a8` (RacePhase, 0–7)

| SDK Field | SDK Struct | F1C Global | Status |
|-----------|-----------|------------|--------|
| `mGamePhase` (0–8) | ScoringInfoV2 +0x48 | `DAT_007c56a8` (RacePhase 0–7) | MATCH — same values (0=beforesession, 5=green, 6=caution, 8=over) |
| `mSession` | ScoringInfoBase +0x40 | `DAT_007c56a4` (SessionType 0–7) | MATCH — session type |
| `mMaxLaps` | ScoringInfoBase +0x50 | `DAT_008acf9c` (TotalRaceLaps) | MATCH | 
| `mDarkCloud` / `mRaining` | ScoringInfoV2 +0x6c | `DAT_007cf080` (WeatherMode) | PARTIAL — F1C uses WeatherMode enum, SDK uses floats |
| `mAmbientTemp` / `mTrackTemp` | ScoringInfoV2 +0x74 | — | MISSING in F1C docs |

**Key finding:** F1C's `DAT_007c56a4` (SessionType) maps to SDK `mSession`. F1C's `DAT_007c56a8` (RacePhase) maps to SDK `mGamePhase` with the same values. This confirms the global naming and usage.

### VehicleScoringInfoV2 Alignment

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mDriverName` (+32 char) | +0x00 | vehicle+0x4620 (DriverName, docs/10) | MATCH — char[32], confirmed |
| `mVehicleName` (+64 char) | +0x20 | vehicle+0x4678 (VehicleDescription) | PARTIAL — 64 bytes at correct position |
| `mTotalLaps` (short) | +0x60 | vehicle+0x4060 (FinishPosition area) | SHIFTED — F1C uses FinishState at +0x4064 |
| `mFinishStatus` (-128..127) | +0x62 | vehicle+0x4064 (FinishState: 0=running,1=finished,2=DNF,3=DSQ) | MATCH — signed char field |
| `mBestLapTime` | +0x6c | vehicle+0x409c (BestLapTime) | MATCH — float at ~same relative position |
| `mNumPitstops` (short) | +0x7c | vehicle+0x1162 (PitStopCount) | SHIFTED — SDK struct doesn't match F1C vehicle layout |
| `mIsPlayer` (bool) | VehicleScoringInfoV2 +0x80 | — | MISSING in F1C vehicle struct |
| `mPlace` (unsigned char) | VehicleScoringInfoV2 +0x87 | vehicle+0x4060 (FinishPosition) | MATCH — 1-based position |
| `mPos` (TelemVect3, float x3) | VehicleScoringInfoV2 +0x98 | vehicle physics position | PARTIAL — F1C has position in physics state, not in scoring struct |

### TelemWheel / TelemWheelV2 Alignment (F1C tire struct)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mRotation` (float) | +0x00 | — | Missing in F1C wheel struct docs |
| `mSuspensionDeflection` (float) | +0x04 | — | Missing |
| `mRideHeight` (float) | +0x08 | — | Missing |
| `mTireLoad` (float) | +0x0c | — | Missing |
| `mLateralForce` (float) | +0x10 | — | Missing |
| `mGripFract` (float) | +0x14 | — | Missing |
| `mBrakeTemp` (float) | +0x18 | — | Missing |
| `mPressure` (float) | +0x1c | — | Missing |
| `mTemperature[3]` (float x3) | +0x20 | — | Missing |
| `mWear` (TelemWheelV2) | +0x2c | vehicle tire wear fields | PARTIAL — F1C has tire wear in tire model, not at this offset |

**Note:** F1C's wheel/tire struct layout differs from the rFactor SDK TelemWheel. The SDK struct is a telemetry-only output struct, not the internal physics tire state.

---

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| FUN_004a40f0 labeled "steward" | PitMan | rFactor RTTI has `.?AVPitMan@@` and `.?AVSteward@@` as separate classes. FUN_004a40f0 is called in Game::Restart without the preceding "Steward::Restart" context of FUN_004d3cf0. Check whether FUN_004a40f0 calls pit crew or steward logic. |
| `DAT_007c56a4` described as "session type" | `mSession` (ScoringInfoBase::mSession) | SDK struct field name matches F1C usage. Aligns with rFactor SDK naming convention. |
| `DAT_007c56a8` described as "RacePhase" | `mGamePhase` (ScoringInfoV2::mGamePhase) | SDK field name mGamePhase is more descriptive. Values 0–8 match. |
| `DAT_008ac490` described as "SceneArray" | `mTrackList` or `SceneArray` | Name is already appropriate. No change needed. |
| DAT_005ef9a0 stride 0x1230 | VehicleDynamicsArray | Name is already appropriate. No change needed. |
| FUN_0042d370 "Game::Enter" | Game::Enter (confirmed) | rFactor RTTI confirms class name. Already correct. |
| FUN_0042c130 "DynMan::Enter" | DynMan::Enter (confirmed) | rFactor RTTI confirms class name. Already correct. |
| FUN_00455bf0 "HWInput::Enter" | HWInput::Enter (confirmed) | rFactor RTTI confirms class name. Already correct. |
| FUN_004c8a20 "Sound::Enter" | Sound::Enter (confirmed) | rFactor RTTI confirms class name. Already correct. |
| FUN_0049ef40 "OnScreen::Enter" | OnScreen::Enter (confirmed) | rFactor RTTI confirms class name. Already correct. |
| FUN_0040c920 "CamMan::Init" | CamMan::Init or CameraManager::Init | rFactor has `CameraManager` as primary name. Consider renaming to CameraManager::Init for consistency. |
| FUN_004bdc10 "Scene Extent Calculator" | SearchGrid::ComputeExtents | rFactor RTTI `.?AVSearchGrid@@` and source path `searchgrid.cpp` confirm class name. Rename to SearchGrid for consistency. |
| FUN_004fa000 "VidMan::Enter" | VidMan::Enter (confirmed) | rFactor RTTI confirms class name. Already correct. |
| DAT_007ce2d8 | AppMutexHandle | Already described as mutex handle. Name ok. |
| DAT_007d0398 | PhotoModeFlag | SDK doesn't have an equivalent. Name ok (photo/free camera mode). |
| DAT_007cbf24 | SomeInputFlag | No SDK equivalent. Needs more analysis. |

### Class Name Alignment Summary

The F1C module naming convention (Game, DynMan, Sound, OnScreen, HWInput, VidMan, Render, CamMan, OSMan) is confirmed by rFactor RTTI. Two minor proposals:

1. **CamMan → CameraManager** — rFactor uses `CameraManager` as the primary class name (with `BaseCameraManager`, `AttachedCameraManager`, `TracksideCameraManager` subclasses). F1C likely uses the same class hierarchy. `CamMan` is an acceptable abbreviation but `CameraManager` is more standard.

2. **FUN_004bdc10 → SearchGrid** — rFactor class name is `SearchGrid`, source is `searchgrid.cpp`. The F1C function should be documented as `SearchGrid::ComputeExtents` or similar.

---

## Source Path Confirmation

From dev_tree.txt, the F1C source path `D:\Dev\F1_1999_2002\Source\` matches all documented modules in docs/01:

| Module | Source path | Confirmed in | 
|--------|-------------|-------------|
| game.cpp | `..\Source\game.cpp` | rFactor + F1C asserts |
| dynman.cpp | `..\Source\dynman.cpp` | rFactor |
| sound.cpp | `..\Source\sound.cpp` | rFactor |
| onscreen.cpp | `..\Source\onscreen.cpp` | rFactor |
| hwinput.cpp | `..\Source\hwinput.cpp` | rFactor |
| vidman.cpp | `..\Source\vidman.cpp` | rFactor |
| render.cpp | `..\Source\render.cpp` | rFactor |
| camera.cpp | `..\Source\camera.cpp` | rFactor |
| osman.cpp | `..\Source\osman.cpp` | rFactor |
| options.cpp | `..\Source\options.cpp` | rFactor |
| searchgrid.cpp | `..\Source\searchgrid.cpp` | rFactor |
| NetComm.cpp | `..\Source\NetComm.cpp` | rFactor |
| plrfile.cpp | `..\Source\plrfile.cpp` | rFactor |
| specialfx.cpp | `..\Source\specialfx.cpp` | rFactor |
| Replay.cpp | `..\Source\Replay.cpp` | rFactor |

No corrections needed — all source path associations in docs/01-engine-architecture.md are correct.

---

## Dev Tree Insights

From dev_tree.txt timeline:

- F1C retail (April 2003) uses merged tree `D:\Dev\F1_1999_2002\Source\` with 31 files
- Common shared files (25 from `D:\Dev\Common\Source\`): ai.cpp, camera.cpp, hdvehicle.cpp, controls.cpp, etc.
- F1C-specific additions: config.cpp, rftracks.cpp, trackdata.cpp, weather.cpp, f1sounds.cpp
- NASCAR 2003 (2002-2003) added pitman.cpp, random.cpp (not in F1C)
- The subsystem lifecycle pattern (Enter/Setup/Init/Restart/Post/Exit) exists in BOTH F1C and rFactor, meaning it was carried forward from isiMotor 1.x into isiMotor 2.0

---

## Enum Type Confirmation

rFactor RTTI reveals these enum types via `PFData` template specializations:

| Enum | rFactor RTTI | F1C Usage | Status |
|------|-------------|-----------|--------|
| `FormationAndStart` | `.?AV?$PFData@W4FormationAndStart@@@@` | FUN_0042cf10 (formation lap state), DAT_007cebc4 (formation lap flag) | CONFIRMED — matches F1C formation lap logic |
| `WeatherCond` | `.?AV?$PFData@W4WeatherCond@@@@` | DAT_007cf080 (WeatherMode) | CONFIRMED — 0-5 weather modes |
| `MechFailureRate` | `.?AV?$PFData@W4MechFailureRate@@@@` | DAT_007cea5c (EngineWearMode 0/2/3) | PARTIAL — F1C has fewer modes |
| `FlagRuleSetting` | `.?AV?$PFData@W4FlagRuleSetting@@@@` | DAT_007cef84 (PenaltiesEnabled) | PARTIAL — F1C likely has simpler flag rules |
| `RaceFinishCriteria` | `.?AV?$PFData@W4RaceFinishCriteria@@@@` | Not documented | MISSING in F1C docs |
| `InCarDashSetting` | `.?AV?$PFData@W4InCarDashSetting@@@@` | Not documented | F1C likely has dash settings |
| `GarageFreeSettings` | `.?AV?$PFData@W4GarageFreeSettings@@@@` | Referenced through DAT_007ceaa4 | PARTIAL |
| `SettingsMode` | `.?AV?$PFData@W4SettingsMode@@@@` | Not documented | MISSING |
| `SimpleDetailLevel` | `.?AV?$PFData@W4SimpleDetailLevel@@@@` | FUN_0047e960 (UI detail levels) | CONFIRMED — "5 detail levels" mentioned |
| UnitSystem, TextureFilter, StartingCameraView, DisplayIcons, cubeFileType, FFBDeviceType, FFBEffectsLevel, FFBWaveType | All present in rFactor RTTI | Not documented in docs/01 | MISSING — likely in options/settings UI code |
