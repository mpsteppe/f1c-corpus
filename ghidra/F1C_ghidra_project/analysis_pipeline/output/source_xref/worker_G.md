# Source Cross-Reference: docs/06-session-race-logic.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `Steward` | FUN_004d36d0 (Setup), FUN_004d38f0 (Init), FUN_004d3cf0 (Restart/Post), FUN_004d4600 (cleanup), FUN_004d0e20 (Light/Glow Node) | HIGH | Source path `steward.cpp` confirmed in rFactor binary strings (line 131, 723). F1C doc explicitly labels these as Steward methods. Matches rFactor RTTI `.?AVSteward@@` (line 570). |
| `NetComm` | FUN_0045d890 (Session Msg Dispatcher), FUN_0045fc50 (Player Slot Sync), FUN_00460520 (SetSelfAsReady), FUN_00460e90 (Track Open), FUN_00460f90 (Track Close), FUN_00461050 (Slot Reset), FUN_004610e0 (Session Sync Init), FUN_004611b0 (Socket Update Start), FUN_0045f390 (Session Metadata), FUN_0045f730 (Join Request), FUN_0045f950 (Server OK), FUN_0045eb50 (Node ID to Name), FUN_0045fb50 (Boot Detection), FUN_0045bc50 (Keep-Alive), FUN_00461e30 (Client Grid Timer), FUN_00463160 (ParseCommandLine), FUN_0057a920 (Network setup) | HIGH | Source path `NetComm.cpp` confirmed in rFactor (line 144) and F1C. Matches rFactor RTTI `.?AVNetComm@@` (line 642). Function behavior matches network message dispatch patterns. |
| `PitMan` | FUN_004a2010 (Pit crew mesh loader) — likely belongs to PitMan | MEDIUM | `PitMan` RTTI in rFactor (line 677). F1C pit functions documented in docs/07, not docs/06. Pit crew mesh loading is a PitMan concern. |
| `DynMan` | Indirect references to session state management | MEDIUM | rFactor has `.?AVDynMan@@` (line 556). Source path `dynman.cpp` in both binaries. DynMan manages dynamic objects/vehicles in session. |
| `Weather` | References to DAT_007cf080 (WeatherMode) and DAT_007cf134 | MEDIUM | rFactor `.?AVWeather@@` (line 679). F1C doc references weather mode in steward dispatch. Confirms Weather class ownership of weather globals. |
| `ScoringInfoV2` / `VehicleScoringInfoV2` | FUN_004c0f60 (Race Standings), FUN_004bc4e0 (Lap Completion), FUN_004c0910 (SeasonScoringInfo lookup), FUN_004bc240 (Standings update) | HIGH | F1C scoring struct offsets match rFactor SDK fields: `mDriverName` (+0x00), `mTotalLaps` (+0x60), `mFinishStatus` (+0x62), `mBestLapTime` (+0x6c). SDK definition lines 157–180. |
| `GameComponent` | All Steward, DynMan session lifecycle functions | HIGH | rFactor RTTI `.?AVGameComponent@@` (line 492). Steward/DynMan inherit from GameComponent. F1C lifecycle (Setup/Init/Restart/Post) matches game component pattern. |
| `RFPluginManager` / `PluginManager` | Not directly in docs/06 | LOW | rFactor RTTI (line 643-644). Plugin system may interact with session for multiplayer plugins. |
| `TvOverlayPage*` | FUN_0047e4b0 (Circuit Info HTML/Overlay), FUN_00469d30 (Player Stats Display) | MEDIUM | rFactor has `TvOverlayPageBase`, `TvOverlayPageRaceClassification`, `TvOverlayPageRaceHUD` (lines 626-638). F1C circuit info page and stats display serve similar overlay/HUD purposes. |
| `BaseCameraManager` / `CameraManager` | FUN_0040c920 (CamMan::Init) referenced in source-tree | LOW | CamMan is separate from session logic but session init calls CamMan methods. rFactor `.?AVCameraManager@@` (line 497). |
| `Options` | FUN_004aa270 (Player Options Initializer) | HIGH | rFactor `.?AVOptions@@` (line 585). F1C options initializer matches pattern — sets up 7 FailureRate slots with default values. |
| `LooseObject` / `LooseWheel` / `LoosePart` | Not in docs/06 directly | LOW | rFactor classes (lines 502-508). These are physics/collision objects, not session logic. |
| `ReplayMan` | FUN_004ba1f0 (Replay Playback), FUN_004b7500 (Replay Save), FUN_004b9fd0 (Replay Activation UI) | HIGH | rFactor `.?AVReplayMan@@` (line 535). F1C replay functions match ReplayMan lifecycle: load playback, save recording, activation UI. |
| `SoundMan` | References to audio commentary triggers in penalty/standings functions | LOW | rFactor `.?AVSoundMan@@` (line 670). Session events trigger audio via FUN_005506a0, FUN_004b33b0. |

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| `RaceLaps` | [GENERAL] | DAT_008acf8c | TotalRaceLaps | RaceLaps | HIGH — rFactor `MaxLaps` field in GDB matches F1C `DAT_008acf8c`. Used in docs/06 as session config param read from INI. |
| `QualifyLaps` | [GENERAL] | DAT_007d04a4 | QualifyLaps | QualifyLaps | HIGH — directly named in doc as loaded from config INI. |
| `StartStalls` | [RCD] | vehicle+0x112f | StartStalls | StartStalls | HIGH — confirmed as .rcd field in FUN_00424080 (docs/06). Formula: `rand()%10000 < StartStalls*10000`. |
| `NormalPitKPH` | [GDB] | session config | NormalPitKPH | NormalPitKPH | HIGH — read from GDB for practice/qualifying pit speed limit. |
| `RacePitKPH` | [GDB] | session config | RacePitKPH | RacePitKPH | HIGH — read from GDB for race pit speed limit. |
| `Recon_Pit_Open` | [GDB] | LAP_CONFIG+0x48 | ReconPitOpen | Recon_Pit_Open | MEDIUM — doc says "Recon_Pit_Open" loaded from INI. rFactor has `Pits Open To Lead Lap Vehicles` string. |
| `Recon_Pit_Closed` | [GDB] | LAP_CONFIG+0x4c | ReconPitClosed | Recon_Pit_Closed | MEDIUM — same source as Recon_Pit_Open. |
| `RaceTime` | [GENERAL] | DAT_008acf90/94 | RaceTimeOffset/Threshold | RaceTimeOffset/Threshold | HIGH — loaded from INI, used in penalty processing. |
| `FuelMult` | PLR | DAT_007d0b64 | FuelMult | FuelMult | HIGH — global fuel multiplier. rFactor has `AIFuelMult` parameter. |
| `TireWearMultiplier` | PLR | DAT_007d0c60 | TireWearMultiplier | TireWearMultiplier | HIGH — global tire wear scale. Read in physics functions. |
| `SeasonScoringInfo` | [GDB] | DAT_007d2e48+index*0x48c0 | SeasonScoringDB | SeasonScoringInfo | HIGH — string confirmed in rFactor (line 283). Section name in GDB for points table. |
| `ForceFormation` | PLR/GDB | DAT_007cebc4 | FormationLap | ForceFormation | HIGH — rFactor `Force Formation` (line 239): `0=standing start, 1=formation lap & standing start` etc. F1C FormationLap flag. |
| `FormationSpeedKPH` | [GDB] | session config | (unnamed) | FormationSpeedKPH | MEDIUM — rFactor string (line 318). F1C formation lap speed limit. |
| `CountCautionLaps` | [RFM] | DAT_008acf9c+? | (unnamed) | CountCautionLaps | MEDIUM — rFactor string (line 268). Caution lap counting mode. |
| `FinishUnderCaution` | [RFM] | DAT_008acf9c+? | (unnamed) | FinishUnderCaution | MEDIUM — rFactor string (line 270). Determines if race ends under yellow. |
| `FlagRuleSetting` | PLR | session config | (unnamed) | FlagRuleSetting | MEDIUM — rFactor RTTI `.?AV?$PFData@W4FlagRuleSetting@@@@` (line 543). Enum likely stored in player file. |
| `FormationAndStart` | PLR | DAT_007cebc4+? | FormationLap | FormationAndStart | MEDIUM — rFactor enum type (line 542, 915, 1036). F1C formation lap config. |
| `MechFailureRate` | PLR | DAT_007cea5c | EngineWearMode | MechFailureRate | MEDIUM — rFactor `.?AV?$PFData@W4MechFailureRate@@@@` (line 541). F1C EngineWearMode (0=off, 2=normal, 3=scripted). |
| `WeatherCond` | PLR | DAT_007cf080 | WeatherMode | WeatherCond | MEDIUM — rFactor enum type (line 544). F1C WeatherMode (0-5). |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| "Prepping Replay" | NASCAR_2003_Demo (shared 3145) | FUN_004ba1f0 | Confirms Replay.cpp source. Shared across all ISI games. |
| "Saving Replay" | NASCAR_2003_Demo (shared 3145) | FUN_004b7500 | Confirms replay save logic identical to NASCAR. |
| "Replay Recording - On" | NASCAR_2003_Demo (shared) | FUN_004b9fd0 | UI string shared across games. |
| "Loading VCR File for playback" | NASCAR_2003_Demo (shared) | FUN_004ba1f0 | VCR format confirmed across isiMotor1 titles. |
| "Stop/Go Penalty: " | NASCAR_2003_Demo (shared 3145) | FUN_004bbd60 | Penalty system strings identical across isiMotor1. |
| "Disqualified: " | NASCAR_2003_Demo (shared) | FUN_004bc0e0 | DSQ message format shared. |
| "Warning: " | NASCAR_2003_Demo (shared) | FUN_004bbc60 | Warning format shared. |
| "Ignored Stop/Go Penalty" | NASCAR_2003_Demo (shared) | FUN_004bc4e0 | DSQ trigger string shared. |
| "Jumped start" | NASCAR_2003_Demo (shared) | FUN_004bc9b0 | Grid penalty string shared. |
| "Penalty: " | NASCAR_2003_Demo (shared) | FUN_004bba90 | Penalty display header shared. |
| "Mechanical failure rate: 0=none..." | NASCAR_2004_Demo (Physics/Vehicle) | FUN_004aa270 | Failure rate UI label shared across NASCAR 2004. |
| `SeasonScoringInfo` | rFactor (line 283) | FUN_004c0910 | Section name for championship points in GDB. |
| `FormationLap` | rFactor (line 241) | FUN_004d3cf0 | rFactor: `Formation lap & standing start` vs F1C formation lap handling. |
| `Force Formation` | rFactor (line 239) | DAT_007cebc4 | 0=standing, 1=formation+standing, 2=safety car+rolling, 3=track default, 4=fast rolling. |
| `Caution Lap:` | rFactor (line 263) | FUN_004bc4e0 | Caution/safety car lap tracking. |
| `Stay Behind The Safety Car` | rFactor (line 265) | FUN_004d3cf0 | Safety car messaging during formation/restart. |
| `Pits Open To Lead Lap Vehicles` | rFactor (line 313) | DAT_007cec30/54 | Pit open/closed timing under caution. |
| `Skipping Formation Lap ...` | rFactor (line 316) | FUN_004d3cf0 | Player skip formation lap feature. |
| `Press SPACE To Skip Formation Lap` | rFactor (line 317) | FUN_004d3cf0 | UI prompt for skipping formation lap. |
| `%s finished before serving penalty, subtracted 1 lap...` | rFactor (line 266) | FUN_004bc4e0 | Penalty enforcement on race completion. Servable/not-servable penalty distinction. |
| `Incrementing MaxLaps because CountCautionLaps=0` | rFactor (line 268) | FUN_004d3cf0 | Caution lap counting logic for race length adjustment. |
| `Adding %d lap(s) to avoid finishing under caution` | rFactor (line 269) | FUN_004d3cf0 | FinishUnderCaution feature — extends race to avoid yellow-flag finish. |
| `Multiplayer mode: setting vehicle places for RACE` | rFactor (line 257) | FUN_004d3cf0 | SessionType 6→7 transition in MP mode. |
| `>Begin Formation Lap` | rFactor (line 258) | FUN_004d3cf0 | Formation lap start log message. |
| `RACECOND_formation` | rFactor (line 273) | DAT_007cebc4 | Race condition flag for formation lap display. |
| `Pitstop3Range` / `Pitstop3Setting` | rFactor (line 431-432) | FUN_004aa270 | Pitstop strategy parameters shared across ISI games. |
| `NumPitstopsRange` / `NumPitstopsSetting` | rFactor (line 437-438) | FUN_004c07f0 | Pit stop count configuration from .hdv. |

## SDK Struct Alignment

### VehicleScoringInfo (rFactor SDK, lines 157–180) vs F1C Scoring Struct

| SDK Field | SDK Offset | F1C Offset | Status | Notes |
|-----------|-----------|------------|--------|-------|
| `mDriverName[32]` | +0x00 | +0x00 | MATCH | F1C driver name at +0x00 (char[32] or similar) |
| `mVehicleName[64]` | +0x20 | +0x20 | MATCH | F1C vehicle name field |
| `mTotalLaps` | +0x60 | +0x60 | MATCH | Short (2 bytes) in both |
| `mSector` | +0x62 | +0x62 | MATCH | Signed char sector indicator |
| `mFinishStatus` | +0x63 | +0x63 | MATCH | 0=none, 1=finished, 2=DNF, 3=DSQ |
| `mLapDist` | +0x64 | +0x64 | MATCH | Float, current distance around track |
| `mPathLateral` | +0x68 | +0x68 | MATCH | Float lateral position |
| `mTrackEdge` | +0x6c | +0x6c | MATCH | Float track edge |
| `mBestSector1` | +0x70 | +0x70 | MATCH | Float |
| `mBestSector2` | +0x74 | +0x74 | MATCH | Float |
| `mBestLapTime` | +0x78 | +0x78 (F1C: +0x409c in vehicle) | SHIFTED* | In rFactor SDK this is part of per-vehicle scoring info struct. In F1C, BestLapTime at vehicle+0x409c. The scoring struct is at different base. |
| `mLastSector1` | +0x7c | +0x7c | PRESUMED MATCH | Layout consistent |
| `mLastSector2` | +0x80 | +0x80 | PRESUMED MATCH | Layout consistent |
| `mLastLapTime` | +0x84 | +0x84 | PRESUMED MATCH | Layout consistent |
| `mCurSector1` | +0x88 | +0x88 | PRESUMED MATCH | Layout consistent |
| `mCurSector2` | +0x8c | +0x8c | PRESUMED MATCH | Layout consistent |
| `mNumPitstops` | +0x90 | +0x90 | MATCH | Short |
| `mNumPenalties` | +0x92 | +0x92 | MATCH | Short |

### VehicleScoringInfoV2 (rFactor SDK, lines 183–212) Additional Fields

| SDK Field | SDK Offset | F1C Offset | Status | Notes |
|-----------|-----------|------------|--------|-------|
| `mIsPlayer` | +0x94 | +0x94 | MATCH | Bool (F1C uses byte at vehicle+0x32c8 or similar) |
| `mControl` | +0x95 | +0x95 | MATCH | Signed char: -1=none, 0=local, 1=AI, 2=remote, 3=replay |
| `mInPits` | +0x96 | +0x96 | MATCH | Bool (F1C vehicle+0x3450 pit state) |
| `mPlace` | +0x97 | +0x97 | MATCH | Unsigned char, 1-based position |
| `mVehicleClass[32]` | +0x98 | +0x98 | MATCH | F1C vehicle class string |
| `mTimeBehindNext` | +0xb8 | +0xb8 | PRESUMED MATCH | Float |
| `mLapsBehindNext` | +0xbc | +0xbc | PRESUMED MATCH | Long |
| `mTimeBehindLeader` | +0xc0 | +0xc0 | PRESUMED MATCH | Float |
| `mLapsBehindLeader` | +0xc4 | +0xc4 | PRESUMED MATCH | Long |
| `mLapStartET` | +0xc8 | +0xc8 | PRESUMED MATCH | Float |
| `mPos (x,y,z)` | +0xcc | +0xcc | PRESUMED MATCH | TelemVect3 = 3 floats |
| `mLocalVel (x,y,z)` | +0xd8 | +0xd8 | PRESUMED MATCH | 3 floats |
| `mLocalAccel (x,y,z)` | +0xe4 | +0xe4 | PRESUMED MATCH | 3 floats |
| `mOriX (x,y,z)` | +0xf0 | +0xf0 | PRESUMED MATCH | Orientation matrix rows |
| `mOriY (x,y,z)` | +0xfc | +0xfc | PRESUMED MATCH | |
| `mOriZ (x,y,z)` | +0x108 | +0x108 | PRESUMED MATCH | |
| `mLocalRot (x,y,z)` | +0x114 | +0x114 | PRESUMED MATCH | 3 floats |
| `mLocalRotAccel (x,y,z)` | +0x120 | +0x120 | PRESUMED MATCH | 3 floats |

### ScoringInfoV2 (rFactor SDK, lines 233–280) vs F1C Session Struct

| SDK Field | SDK Offset | F1C Analog | Status | Notes |
|-----------|-----------|------------|--------|-------|
| `mTrackName[64]` | +0x00 | DAT_007d1d8c (saved game name) | SHIFTED | F1C stores track/scene name separately. |
| `mSession` | +0x40 | DAT_007c56a4 (SessionType) | MATCH | Long integer session type 0-7. |
| `mCurrentET` | +0x44 | DAT_008afea0/98 (RaceTimeOffset) | MATCH | Float, elapsed time. |
| `mEndET` | +0x48 | DAT_008acf94 (RaceTimeThreshold) | MATCH | Float, session end time. |
| `mMaxLaps` | +0x4c | DAT_008acf9c (TotalRaceLaps) | MATCH | Long, maximum race laps. |
| `mLapDist` | +0x50 | GDB lap distance | MATCH | Float, track lap distance. |
| `mNumVehicles` | +0x58 | DAT_005c329c (VehicleCount) | MATCH | Long, current number of vehicles. |
| `mGamePhase` | +0x5c | DAT_007c56a8 (RacePhase) | MATCH | Unsigned char, 0-8 phases. SDK values (lines 236-245) match F1C RacePhase values. **KEY CONFIRMATION** |
| `mYellowFlagState` | +0x5d | (unnamed) | NEW | Signed char, -1 to 7. F1C may not have this field in global scope — caution flag state likely per-vehicle. |
| `mSectorFlag[3]` | +0x5e | (unnamed) | NEW | 3 signed chars for per-sector local yellows. |
| `mStartLight` | +0x61 | session config | PRESUMED MATCH | Frame number for start lights. |
| `mNumRedLights` | +0x62 | session config | PRESUMED MATCH | Count of red lights in sequence. |
| `mInRealtime` | +0x63 | DAT_007d0308 (RaceActiveFlag) | PRESUMED MATCH | Bool, realtime vs monitor. |
| `mPlayerName[32]` | +0x64 | DAT_007d1d8c | MATCH | Player name string. |
| `mPlrFileName[64]` | +0x84 | PLR file path | PRESUMED MATCH | Encoded filename. |
| `mDarkCloud` | +0xc4 | DAT_007cf134 | MATCH | Float 0.0-1.0, cloud darkness. |
| `mRaining` | +0xc8 | DAT_007cf080 (WeatherMode) | MATCH | Float 0.0-1.0, rain severity. |
| `mAmbientTemp` | +0xcc | track config | PRESUMED MATCH | Float, air temperature. |
| `mTrackTemp` | +0xd0 | track config | PRESUMED MATCH | Float, surface temperature. |
| `mWind` | +0xd4 | track config (TelemVect3) | PRESUMED MATCH | 3 floats wind vector. |
| `mOnPathWetness` | +0xe0 | track state | PRESUMED MATCH | 0.0-1.0 |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| DAT_008acf8c → TotalRaceLaps | `RaceLaps` | rFactor SDK field `mMaxLaps` and GDB config parameter name. F1C doc already reads from INI as "RaceLaps". |
| DAT_008acf9c → TotalRaceLaps (same) | `MaxLaps` | rFactor SDK `ScoringInfoV2.mMaxLaps`. Distinguish from configured RaceLaps value. |
| DAT_007cebc4 → FormationLap | `ForceFormation` | rFactor has both `Force Formation` (config: 4 modes) and `FormationLap` (bool). F1C DAT_007cebc4 stores formation mode, not just boolean. |
| DAT_007d04a4 → QualifyLaps | `QualifyLaps` | Confirmed by doc string — loaded as "QualifyLaps" from INI. |
| DAT_007cef84 → PenaltiesEnabled | `PenaltiesEnabled` | No change needed — already correct per rFactor behavior. |
| DAT_007c56a8 → RacePhase | `RacePhase` / `GamePhase` | rFactor SDK calls this `mGamePhase` (0-8 values). F1C name "RacePhase" is reasonable but SDK name "GamePhase" may be more accurate since phase 0 is pre-session. |
| DAT_007d0b28 → MultiplayerFlag | `MultiplayerFlags` | rFactor has `MultiplayerFlag` at DAT_007C56A0 with bitmask. F1C may have split this into multiple globals. |
| DAT_008ab6e4 → ScoringGate | `ScoringGate` | No change — widely used name. rFactor SDK doesn't have this exact field but it maps to `mInRealtime` check behavior. |
| DAT_007c569c → SessionType5 | `InternalState` | rFactor has no direct analog. F1C state machines doc calls it `InternalState`. Value 5 = server mode. |
| DAT_007d0410 → RaceMode | `RaceMode` | rFactor has `CURRENTRACE` and `RACESESSION` strings but not direct analog. Name is well-established. |
| DAT_008acfa0 → half-distance flag | `HalfDistanceFlag` | Simple descriptive name for lap ≥ (total+1)/2 flag. |
| DAT_007d0c60 → TireWearMultiplier | `TireWearMultiplier` | No change — matches rFactor config pattern. |
| DAT_007cea5c → EngineWearMode | `MechFailureRate` | rFactor RTTI has `W4MechFailureRate@@@@` enum. F1C uses 0/2/3 values matching rFactor failure rate slots. |

## Additional Findings

### RacePhase Mapping — F1C vs rFactor SDK

F1C RacePhase (DAT_007c56a8) values align with rFactor SDK `ScoringInfoV2.mGamePhase`:

| F1C | rFactor SDK Value | Notes |
|-----|-------------------|-------|
| 0 | 0 | Before session begun |
| 1 | 1 | Reconnaissance laps (race only) |
| 2 | 2 | Grid walk-through (race only) |
| 3 | 3 | Formation lap (race only) |
| 4 | 4 | Starting-light countdown (race only) |
| 5 | 5 | Green flag |
| 6 | 6 | Full course yellow / safety car |
| 7 | 7 | Session stopped |
| 8 | 8 | Session over |

F1C documentation confirms: Phase 2 = formation lap, Phase 3 → 4 transition at ~+12.4s (green flag), Phase 4 → 5 at ~+157s (leader finished), Phase 5 → 8 at ~+221s.

### Caution/Yellow Flag State

rFactor SDK defines `mYellowFlagState` (-1 invalid, 0 none, 1 pending, 2 pits closed, 3 pit lead lap, 4 pits open, 5 last lap, 6 resume, 7 race halt). F1C appears to handle caution states through DAT_007cec30 (ReconPitOpen), DAT_007cec54 (ReconPitClosed), DAT_007cec78 (PitTimerVisible) rather than a single global. This is an evolution between isiMotor1 (F1C) and isiMotor2 (rFactor).

### Config Parameter Naming — .hdv Field Mapping

From the full Form06.hdv analysis, the following .hdv parameters map to F1C session-related struct fields:

| HDV Param | Section | Used By | Notes |
|-----------|---------|---------|-------|
| `FuelRange`/`FuelSetting` | [GENERAL] | FUN_004aa270 | Default fuel load config |
| `NumPitstopsRange`/`NumPitstopsSetting` | [GENERAL] | FUN_004c07f0 | Stored in vehicle struct |
| `Pitstop1Range`/`Pitstop1Setting` | [GENERAL] | FUN_004aa270 | Pit strategy — stop 1 fuel |
| `Pitstop2Range`/`Pitstop2Setting` | [GENERAL] | FUN_004aa270 | Pit strategy — stop 2 fuel |
| `Pitstop3Range`/`Pitstop3Setting` | [GENERAL] | FUN_004aa270 | Pit strategy — stop 3 fuel |
| `FeelerFlags` | [GENERAL] | FUN_004e3360 | Collision feeler configuration |
| `StopGo` | [PITMENU] | steward | Pit menu stop/go penalty option |
| `Preparation` | [PITMENU] | pit system | Pit crew timing |

### rFactor Source Path Confirmation

rFactor binary contains source paths that match F1C function sources:
- `..\Source\steward.cpp` — rFactor line 131 = F1C Steward functions
- `..\Source\game.cpp` — rFactor line 126 = Game::Enter/Post/Restart
- `..\Source\NetComm.cpp` — rFactor line 144 = network session functions
- `..\Source\Replay.cpp` — rFactor line 122 = replay functions
- `..\Source\season.cpp` — rFactor line 128 = season standings functions
- `..\Source\options.cpp` — rFactor line 138 = player options init
- `..\Source\sound.cpp` — rFactor line 148 = audio commentary triggers

### ISI Dev Tree Evolution

From dev_tree.txt:
- F1 2002 Demo had `steward.cpp` as game-specific (not common). By F1C retail, steward was fully integrated.
- NASCAR 2003 introduced `pitman.cpp` + `random.cpp` — not present in F1C. Pit logic embedded in steward/session in F1C.
- rFactor separated steward into dedicated module with RTTI. F1C has no RTTI so class hierarchy is inferred from calling patterns.

### Unique NASCAR_2003 Strings not in F1C

Strings from NASCAR_2003_Demo unique set that F1C does NOT have — confirming features not in F1C:
- `AIAimSpeedsPerWP` (line 79 config_params.txt) — rFactor only, F1C uses simpler AI speed model
- `AICornerReductionBase` — rFactor only
- `AIRaceTimeFast/Mid/Slow` — NASCAR qualifying estimation not in F1C
- `All Vehicles Equal` — NASCAR multiplayer option
- `EngineBrakeMapRange/Setting` — engine braking map not in F1C
- `TireWearMulti` — separate wear multiplier in NASCAR
