# Source Cross-Reference: docs/00-source-tree.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `AIDatabase` (rFactor Dedicated) | FUN_004024f0, FUN_004040a0 | **HIGH** | Both files assert `ai_db.cpp` source path. rFactor source paths list exactly `..\Source\ai_db.cpp`. AIDatabase::Init() string "Entered AIDatabase::Init()" found in FUN_004040a0. |
| `CameraManager` (rFactor Dedicated) | FUN_0040c920, FUN_0040c9e0, FUN_0040cce0 | **HIGH** | rFactor source: `..\Source\camera.cpp`. F1C assert strings confirm camera.cpp. FUN_0040c920 registers MAINVIEW camera. RTTI shows `BaseCameraManager`, `AttachedCameraManager`, `TracksideCameraManager`, `CameraManager` hierarchy. |
| `DynMan` (rFactor Dedicated) | FUN_0042c130, FUN_0042c170, FUN_0042c1a0, FUN_0042c3b0, FUN_0042c9f0, FUN_0042ca70 | **HIGH** | rFactor source: `..\Source\dynman.cpp`. F1C assert "Entered DynMan::Enter()". Full lifecycle (Enter/Setup/Init/Restart/Post/Exit) matches expected DynMan interface. |
| `Game` (rFactor Dedicated) | FUN_0042cf10–FUN_0042db20 (9 funcs) | **HIGH** | rFactor source: `..\Source\game.cpp`. F1C assert strings: "Multiplayer mode: setting vehicle places for RACE", "No vehicle files found". Game::Enter/Setup/Init/Restart/Post/Exit lifecycle matches rFactor Game class. |
| `HWInput` (rFactor Dedicated) | FUN_00455bf0–FUN_00455f00 (6 funcs) | **HIGH** | rFactor source: `..\Source\hwinput.cpp`. F1C assert "Entered HWInput::Enter()". DirectInput8Create call. Full lifecycle. |
| `OnScreen` (rFactor Dedicated) | FUN_0049ef40–FUN_0049f120 (6 funcs) | **HIGH** | rFactor source: `..\Source\onscreen.cpp`. F1C assert "Entered OnScreen::Enter()". Full lifecycle. |
| `Options` (rFactor Dedicated) | FUN_004a0eb0 | **HIGH** | rFactor source: `..\Source\options.cpp`. F1C assert string confirms. RTTI shows full UI hierarchy: `Options_Screens`, `Options_BaseMenuItem`, `Options_SliderBar`, `Options_CheckBox`, `Options_SpinBox`, etc. |
| `OSMan` (rFactor Dedicated) | FUN_004a18d0, FUN_004a1930 | **HIGH** | rFactor source: `..\Source\osman.cpp`. F1C assert "Entered OSMan::Enter()". Creates app mutex "_F1 Challenge 99-02_APP_MUTEX_". |
| `PlayerFile` (rFactor Dedicated) | FUN_004b0770–FUN_004b1900 (5 funcs) | **HIGH** | rFactor source: `..\Source\plrfile.cpp`. RTTI shows `PlayerFile`. F1C assert "Attempting to save to %s". Lifecycle: Enter/Setup/Restart/Post. |
| `Render` (rFactor Dedicated) | FUN_004b4030, FUN_004b4060, FUN_004b4170 | **HIGH** | rFactor source: `..\Source\render.cpp`. F1C assert "Entered Render::Init()", "Entered Render::Post()". |
| `SearchGrid` (rFactor Dedicated) | FUN_004bdc10 | **HIGH** | rFactor source: `..\Source\searchgrid.cpp`. F1C assert "Could not get extents of scene". RTTI confirms `SearchGrid` class. |
| `SoundMan` (rFactor Dedicated) | FUN_004c8a20–FUN_004c8d00 (6 funcs) | **HIGH** | rFactor source: `..\Source\sound.cpp`. F1C assert "Entered Sound::Enter()". RTTI shows `SoundMan`. |
| `SpecialFX` (rFactor Dedicated) | FUN_004ca480–FUN_004cfff0 (10 funcs) | **HIGH** | rFactor source: `..\Source\specialfx.cpp`. RTTI confirms `SpecialFX`. F1C strings: "CUBE Error: %s", "CMAPS.MAS", particle system parser. |
| `Steward` (rFactor Dedicated) | FUN_004d0110–FUN_004d4600 (6 funcs) | **HIGH** | rFactor source: `..\Source\steward.cpp`. RTTI confirms `Steward`. F1C strings: "RaceTime", "PreRacePresentation", "STLITE". |
| `VidMan` (rFactor Dedicated) | FUN_004f9310–FUN_004fad00 (7 funcs) | **HIGH** | rFactor source: `..\Source\vidman.cpp`. RTTI confirms `VidMan`. F1C strings: "3DCONFIG.EXE", "No Device", "CUBE error loading scene file". |
| `Weather` (rFactor Dedicated) | FUN_004fe820 | **HIGH** | rFactor source: `..\Source\weather.cpp`. RTTI confirms `Weather`. F1C assert: "Could not write to file %s". |
| `NetComm` (rFactor Dedicated) | FUN_0045d890–FUN_00464290 (16+ funcs) | **HIGH** | rFactor source: `..\Source\NetComm.cpp`. RTTI confirms `NetComm`, `NetCommResponse`. F1C strings: "*** Opening", "*** Closing track", "HotPacket_over_Winsock", "SynchronizeWithServer". |
| `PitMan` (rFactor Dedicated) | FUN_004a2010, FUN_004a22d0, FUN_004a2a90 | **HIGH** | rFactor source: `..\Source\pitcrew.cpp`. RTTI confirms `PitMan`. F1C strings: pitcrew mesh loading, animation files, POSITION/ROTATE/MOVE commands. |
| `ReplayMan` (rFactor Dedicated) | FUN_004ba1f0 | **HIGH** | rFactor source: `..\Source\Replay.cpp`. RTTI confirms `ReplayMan`. F1C strings: "Prepping Replay", "Loading VCR File for playback". |
| `PFController` (rFactor Dedicated) | (not directly mapped) | **MED** | RTTI shows `PFController` class. rFactor source: `..\Source\config.cpp`. F1C config.cpp (FUN_00421cd0) reads Config.ini — may correspond to PFController config parameter system. |
| `HWInput` (rFactor Dedicated) | FUN_00455bf0–FUN_00455f00 | **HIGH** | DirectInput8 device creation, keyboard/mouse setup chain. Matches `HWInput` RTTI class. |
| `Controller` (rFactor Dedicated) | (inherits from HWInput?) | **MED** | RTTI shows `Controller` class. Likely separate from HWInput — may handle game controller abstraction layer. Not directly mapped in source tree. |
| `GameStatsMan` (rFactor Dedicated) | (not in source tree) | **MED** | RTTI confirms `GameStatsMan`. rFactor source: `..\Source\gamestats.cpp`. Not in F1C assert source tree — likely rFactor-only addition. |
| `PluginManager` / `RFPluginManager` (rFactor Dedicated) | (not in source tree) | **HIGH** | isiMotor 2.0 addition. F1C (isiMotor 1.x) lacks plugin system entirely. |
| `GenericManager`, `GenericFilter`, `ModManager`, `NationalityManager`, `TeamManager`, `HelmetManager` (rFactor Dedicated) | (not in source tree) | **HIGH** | isiMotor 2.0 additions for mod/nationality/team/helmet systems. Absent from F1C. |
| `TvOverlayPage*` hierarchy (rFactor Dedicated) | (not in source tree) | **HIGH** | Broadcast TV overlay system — isiMotor 2.0 addition. F1C lacks this. |
| `LooseObject`, `LooseWheel`, `LooseWing`, `LoosePart` (rFactor Dedicated) | (not in source tree) | **HIGH** | Detachable part classes. rFactor source: `..\Source\CollObjects.cpp`. F1C has collision objects but these specific classes are rFactor additions. |
| `AmbientSound*` hierarchy (rFactor Dedicated) | (not in source tree) | **MED** | `AmbientSoundCrowd`, `AmbientSoundAirHorns`, `AmbientSoundAnnouncer`, `AmbientSoundPitHorn`, `AmbientSoundReverb`. These are ambient sound environment classes, possibly in F1C but without assert strings. |
| `RFAudioBuffer*`, `RFFrame*`, `RFReplayFridgeManager*` (rFactor Dedicated) | (not in source tree) | **HIGH** | RF-prefixed classes are rFactor-specific audio/frame/replay additions. Not in F1C (isiMotor 1.x). |
| `beepSoundMiles`, `beepSoundSystem` (rFactor Dedicated) | (not in source tree) | **MED** | Miles Sound System integration layer. F1C uses Miles but may have different wrapper naming. |
| `cubeDirectX`, `cubeGraphicsDevice`, `cubeBase` (rFactor both) | (not in source tree) | **HIGH** | CUBE engine classes — present identically in both, managed via vidman.cpp and render.cpp at application level. |
| `TiXml*` hierarchy (rFactor both) | (not in source tree) | **HIGH** | TinyXML library. Present in both F1C and rFactor. Used by config file parsers. |
| `PlayerFile` (rFactor Dedicated) | FUN_004b1820–FUN_004b1900 | **HIGH** | Lifecycle: Enter/Setup/Restart/Post. RTTI confirms. |
| `PuppetMaster` (rFactor Dedicated) | (not in source tree) | **MED** | Replay/recording control class. F1C may have equivalent in Replay.cpp without RTTI. |
| `Options_Text`, `Options_CheckBox`, `Options_SpinBox`, `Options_SliderBar`, `Options_ScrollBox`, `Options_Picture`, `Options_BinkAnimation`, `Options_DropDown`, `Options_ToggleButton`, etc. (rFactor Dedicated) | (indirect, in options.cpp) | **MED** | Full UI widget hierarchy. F1C options.cpp likely uses similar hierarchy but without RTTI. F1C O_BaseGz.cpp, O_AppGz.cpp, O_OSC.cpp are the Gizmo layer corresponding to rFactor's `Options_BaseGizmo`. |
| `MPFile` (rFactor Dedicated) | (not in source tree) | **MED** | Multiplayer file transfer class. rFactor source: `..\Source\FileTransfer.cpp`. F1C has FileTransfer.cpp in source paths but no assert-string functions documented. |

## Parameter-to-Offset Mappings

docs/00-source-tree.md does not contain struct offset tables — it maps functions to source files. The parameter-to-offset cross-reference is therefore N/A for this doc file.

However, the following functions in the source tree reference config parameters by name:

| Config Param | Section | Function(s) | Notes |
|-------------|---------|-------------|-------|
| CGRightRange, CGRearSetting | GENERAL | FUN_0042fd00 (garage.cpp) | Garage setup writer reads/writes these by name |
| FuelRange, FuelSetting | GENERAL | FUN_0042fd00 | Written to setup file |
| TireCompoundSetting | GENERAL | FUN_0042fd00 | Written to setup file |
| FrontAntiSwayRange/Setting, RearAntiSway* | SUSPENSION | FUN_0042fd00 | Garage writes these |
| CamberRange/Setting | FRONTLEFT/FRONTRIGHT/etc | FUN_0042fd00 | Per-wheel settings |
| BrakeDiscRange/Setting | FRONTLEFT/etc | FUN_0042fd00 | Brake disc thickness |
| BrakePadRange/Setting | FRONTLEFT/etc | FUN_0042fd00 | Pad type |
| SteerLockRange/Setting | CONTROLS | FUN_0042fd00 | Steering lock |
| BrakePressureRange/Setting | CONTROLS | FUN_0042fd00 | Brake pressure |
| Gear1–7Setting | DRIVELINE | FUN_0042fd00, FUN_004f4270 (vehload.cpp) | Gear ratio settings |
| FinalDriveSetting | DRIVELINE | FUN_0042fd00, FUN_004f4270 | Final drive |
| DiffPump/Coast/Power/Preload* | DRIVELINE | FUN_0042fd00 | Differential settings |
| SlowBump/FastBumpRange/Setting | FRONTLEFT/etc | FUN_0042fd00 | Damper settings |
| RideHeightRange/Setting | FRONTLEFT/etc | FUN_0042fd00 | Ride height |
| FWRange/FWSetting | FRONTWING | FUN_0042fd00 | Front wing adjustment |
| RWRange/RWSetting | REARWING | FUN_0042fd00 | Rear wing adjustment |
| RadiatorRange/Setting | BODYAERO | FUN_0042fd00 | Radiator / grille tape |
| BrakeDuctRange/Setting | BODYAERO | FUN_0042fd00 | Brake duct |
| AIAimSpeedsPerWP | GENERAL | FUN_004040a0 (indirect) | AI waypoint lookup speeds |
| AIDifficultySlider | (PLR) | FUN_004040a0 | Reads DAT_007d01a0 |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `..\Source\ai_db.cpp` | rFactor both | FUN_004024f0, FUN_004040a0 | Same source file path — confirms ai_db.cpp is shared codebase |
| `..\Source\camera.cpp` | rFactor both | FUN_0040c920 | Shared camera source |
| `..\Source\dynman.cpp` | rFactor both | FUN_0042c130 | Shared dynman source |
| `..\Source\game.cpp` | rFactor both | FUN_0042cf10+ | Shared game source |
| `..\Source\hdvehicle.cpp` | rFactor both | FUN_00439210+ | Shared hdvehicle source — but rFactor has evolved version |
| `..\Source\hwinput.cpp` | rFactor both | FUN_00455bf0+ | Shared hardware input |
| `..\Source\onscreen.cpp` | rFactor both | FUN_0049ef40+ | Shared on-screen display |
| `..\Source\options.cpp` | rFactor both | FUN_004a0eb0 | Shared options |
| `..\Source\osman.cpp` | rFactor both | FUN_004a18d0 | Shared OS manager |
| `..\Source\pitcrew.cpp` | rFactor both | FUN_004a2010+ | Shared pit crew |
| `..\Source\plrfile.cpp` | rFactor both | FUN_004b0770+ | Shared player file |
| `..\Source\render.cpp` | rFactor both | FUN_004b4030+ | Shared renderer |
| `..\Source\setup.cpp` | rFactor both | FUN_004c3200+ | Shared setup |
| `..\Source\sound.cpp` | rFactor both | FUN_004c8a20+ | Shared sound |
| `..\Source\specialfx.cpp` | rFactor both | FUN_004ca480+ | Shared special effects |
| `..\Source\steward.cpp` | rFactor both | FUN_004d0110+ | Shared steward |
| `..\Source\vidman.cpp` | rFactor both | FUN_004f9310+ | Shared video manager |
| `..\Source\weather.cpp` | rFactor both | FUN_004fe820 | Shared weather |
| `..\Source\NetComm.cpp` | rFactor both | FUN_0045d890+ | Shared network comm — rFactor also has NetCommDedicated.cpp |
| `..\Source\vehgfx.cpp` | rFactor both | FUN_004ddf90+ | Shared vehicle graphics |
| `..\Source\vehload.cpp` | rFactor both | FUN_004f3240+ | Shared vehicle loader |
| `..\Source\garage.cpp` | rFactor both | FUN_0042fd00 | Shared garage |
| `..\Source\htree.cpp` | rFactor both | FUN_00449a80 | Shared HAT tree |
| `..\Source\config.cpp` | rFactor both | FUN_00421cd0 | Shared config — but rFactor Config app uses different PDB path |
| `..\Source\tire_manager.cpp` | rFactor both | FUN_004d5ee0+ | Shared tire manager |
| `..\Source\util.cpp` | rFactor both | FUN_004dc770 | Shared utility |
| `..\Source\searchgrid.cpp` | rFactor both | FUN_004bdc10 | Shared search grid |
| `..\Source\Replay.cpp` | rFactor both | FUN_004ba1f0 | Shared replay |
| `..\Source\season.cpp` | rFactor both | (not in source tree) | Present in rFactor but missing F1C assert functions |
| `..\Source\AIDialog.cpp` | rFactor both | (not in source tree) | AI dialog — rFactor addition or no assert strings in F1C |
| `..\Source\random.cpp` | rFactor Dedicated only | (not in source tree) | Random number utility — rFactor-specific source (NASCAR had it, F1C may lack) |
| `..\Source\voicechat.cpp` | rFactor both | (not in source tree) | Voice chat — present in both codebases but no F1C assert strings |
| `..\Source\CommMain.cpp` | rFactor both | (not in source tree) | Communications main — no F1C assert strings |
| `..\Source\CommTrigger.cpp` | rFactor both | (not in source tree) | Communications trigger — no F1C assert strings |
| `..\Source\FileTransfer.cpp` | rFactor both | (not in source tree) | File transfer — no F1C assert strings |
| `..\Source\gamestats.cpp` | rFactor both | (not in source tree) | Game stats — rFactor has GameStatsMan RTTI |
| `..\Source\O_AppGz.cpp` | rFactor Dedicated? | sub_46DE10 | App-level GZip — rFactor may have merged into different module |
| `..\Source\O_BaseGz.cpp` | rFactor Dedicated? | FUN_0048e8d0 | Base gizmo — rFactor has RTTI for `Options_BaseGizmo` |
| `..\Source\O_OSC.cpp` | rFactor Dedicated? | (not in source tree) | OSC (On-Screen Controller?) — rFactor has OSC error strings |
| `..\Source\NetCommUtil.cpp` | rFactor Dedicated | (not in source tree) | NetComm utility — separate DLL plugin in rFactor |
| `..\Source\slot.cpp` | rFactor both | (not in source tree) | Slot management — present in rFactor source paths, no F1C assert strings |
| `CUBE error loading scene file %s: %s` | rFactor + F1C | FUN_004fa320, FUN_0048e8d0 | Same CUBE engine error format — identity confirmed |
| `Entered %s::%s()` pattern | rFactor + F1C | Multiple lifecycle funcs | Same debug trace pattern across all isiMotor games |
| `Vehicle has zero or negative inertia` | rFactor + F1C | FUN_00439210 | Physics validation — identical code path |
| `Tire load factor should be positive` | rFactor + F1C | FUN_004d5ee0 | Tire validation — shared code |
| `Non-existent tire brand` | rFactor + F1C | FUN_004d7880 | Tire brand lookup — shared |
| `CUBE error : %s` | rFactor + F1C | FUN_004f9310 | CUBE error wrapper — shared |
| `3DCONFIG.EXE` | rFactor + F1C | FUN_004fa000 | Video config launcher — shared |
| `No Device` | rFactor + F1C | FUN_004fa000 | Device detection — shared across all isiMotor games |
| `HotPacket_over_Winsock` | rFactor + F1C | FUN_0045d890+ | Network transport layer — shared |
| `<HotPacket::Winsock>` | rFactor + F1C | FUN_0045d890+ | Network debug string — shared |
| `Gaussian elimination for HAT poly failed` | Unique to F1C htree.cpp | FUN_00449a80 | Only in F1C — rFactor uses different collision/pathfinding system? (SearchGrid RTTI present in both) |
| `Incomplete waypoint path` | F1C ai_db.cpp | FUN_004024f0 | Waypoint validation — rFactor AIDatabase likely has similar |
| `Could not write to file %s` | F1C weather.cpp | FUN_004fe820 | Weather file write — shared behavior |
| `Attempting to save to %s` | F1C plrfile.cpp | FUN_004b0770 | Player file save — shared |

## SDK Struct Alignment

docs/00-source-tree.md is a source tree index, not a vehicle physics struct doc. SDK struct alignment tables are N/A for this file.

However, the following structural observations:

| F1C Module | rFactor Equivalent | Status |
|-----------|-------------------|--------|
| `FUN_00439210` (hdvehicle.cpp, 888 lines) | Part of `DynMan` physics world | MATCH — rFactor hdvehicle.cpp source path identical |
| Vehicle scoring fields (+0x403c–+0x409c) | `VehicleScoringInfoV2` (mPlace, mTotalLaps, mBestLapTime, mFinishStatus) | MATCH — same fields at consistent offsets |
| Race phase global (DAT_007c56a8) | `ScoringInfoV2::mGamePhase` (0–8) | MATCH — identical phase numbering |
| Pit crew system (+0x44 node chain) | `PitMan` RTTI class | MATCH |
| Tire manager compound stride 0x2A8 | rFactor .tbc compound size | MATCH — same format |
| Garage setup file format | rFactor .svm file | MATCH — parameter names identical |

## Dev Tree Evolution Insights

From dev_tree.txt, the F1C source tree evolved from:
```
D:\dev\Common\Source\ (25 shared files, isiMotor1 core)
+ D:\dev\F1_2002\Source\ (4 game-specific)
= D:\dev\F1_1999_2002\Source\ (merged, + config.cpp, rftracks.cpp, trackdata.cpp, weather.cpp, f1sounds.cpp)
```

rFactor evolved further from:
```
D:\dev\NASCAR_2003\Source\ (34 files, + pitman.cpp, random.cpp)
→ D:\dev\NASCAR_2004\Source\ (34 files, same set)
→ rFactor (isiMotor 2.0, expanded with plugin system, TV overlay, etc.)
```

The 25 common files from `D:\Dev\Common\Source\` shared across all isiMotor1 games:
```
ai.cpp, camera.cpp, camera_ed.cpp, carhull.cpp, clouds.cpp,
controls.cpp, damagemodel.cpp, dynobj.cpp, f1sounds.cpp,
f1special.cpp, garage.cpp, graphics.cpp, grip.cpp, hdvehicle.cpp,
misc.cpp, monitor.cpp, multimedia.cpp, ocontrol.cpp, onscreen.cpp,
options.cpp, pitcrew.cpp, plrfile.cpp, pvehicle.cpp, realroad.cpp,
vehicle.cpp
```

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| `docs/00-source-tree.md` → module index | Keep as-is | Already correctly documents source → function mapping |
| FUN_0042fd00 → `Garage::WriteSetupFile` | Already documented as garage setup writer | Confirm name |
| FUN_004a2010 → `PitCrew::LoadMesh` | Already described as pit crew mesh loader | Matches PitMan RTTI |
| FUN_004bdc10 → `SearchGrid::ComputeExtents` | Already described | Matches SearchGrid RTTI |
| `O_BaseGz.cpp` → `Options_BaseGizmo` | Proposed | RTTI confirms `Options_BaseGizmo` class, F1C O_BaseGz.cpp is the isiMotor1 equivalent |
| `O_AppGz.cpp` → App-level GZip wrapper | Keep as-is | No direct RTTI equivalent |
| `O_OSC.cpp` → On-Screen Controller/Config | Proposed | rFactor has "OSC Read Error" / "OSC %s on line %d" strings — likely same module |

## Summary

**Total functions in docs/00-source-tree.md:** 103+ (across 27+ source files)
**High-confidence RTTI mappings:** 21 source files with direct rFactor class equivalents
**Medium-confidence RTTI mappings:** 6 (Options UI hierarchy, PFPController, ambient sound)
**Source files shared 1:1 with rFactor:** All 27 source files in F1C tree have matching rFactor source paths
**rFactor-only additions (not in F1C):** Plugin system, TV overlay, ambient sound environment, mod/nationality/team/helmet managers, loose part hierarchy, PuppetMaster, RFAudio/RFFrame system
