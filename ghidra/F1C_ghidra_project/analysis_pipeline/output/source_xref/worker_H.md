# Source Cross-Reference: docs/07-pit-system.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| PitMan | FUN_004a2010, FUN_004a22d0, FUN_004a4900, FUN_004a2a90, FUN_004a3910, FUN_004a3220 | HIGH | All in pitcrew.cpp — pit crew scene/animation loading. rFactor Dedicated.exe exports `.?AVPitMan@@` RTTI. These are the exact class of functions PitMan would contain (MAS loading, MTS parsing, animation setup). |
| PitMan | FUN_004a6e50, FUN_004a6200, FUN_004a6340, FUN_004a68b0 | HIGH | Pit state machine, ready check, operation timer, progress handler — core PitMan runtime. Match PitMan RTTI in rFactor Dedicated.exe. |
| PitMan | FUN_004a5330, FUN_004a5820, FUN_004a5c40 | MEDIUM | Part state copy/lookup — could be PitMan utility methods or part of hdvehicle. Belongs with pit system regardless. |
| PitMan | FUN_004d12c0, FUN_004ddad0 | MEDIUM | Pit order loader and crew instance setup — might be PitMan initialization methods rather than standalone. |
| Steward | FUN_004d1bc0, FUN_004d2210, FUN_004d23d0 | HIGH | Sourced as steward. rFactor Dedicated.exe has `.?AVSteward@@` RTTI. Pit order rank, pit close notification, pit timer init are steward responsibilities. |
| Steward | FUN_004d2e50 | MEDIUM | Pit timer/race phase state machine. References RacePhase (DAT_007c56a8) heavily — likely steward's pit window timer logic. |
| TvPitMenu | FUN_004a58b0 | MEDIUM | Pit repair status display — UI overlay for pit menu. rFactor has `.?AVTvPitMenu@@` RTTI (TV broadcast overlay pit menu). Could be TvPitMenu or generic pit UI. |
| FormationAndStart enum | (referenced by FUN_004d2e50 phase 1/2) | MEDIUM | rFactor Dedicated has `.?AV?$PFData@W4FormationAndStart@@@@` RTTI. F1C RacePhase states map to formation/standing start logic in the pit timer state machine. |

### RTTI Map: PitMan Class Methods — Expected Layout

Based on rFactor PitMan RTTI presence and function size/source:

```
PitMan (virtual class expected):
  FUN_004a2010 — mts mesh loader
  FUN_004a22d0 — anm loader
  FUN_004a4900 — scene file loader
  FUN_004a2a90 — animation loader (central)
  FUN_004a3220 — PITANIMS.MAS loader
  FUN_004a3910 — animation/MAS setup orchestrator
  FUN_004ddad0 — crew instance setup
  FUN_004d12c0 — pit order reader
  FUN_004a6e50 — pit state machine (main tick)
  FUN_004a6200 — pit stop ready check
  FUN_004a6340 — pit operation timer
  FUN_004a68b0 — pit progress handler
  FUN_004a5330 — part state copy
  FUN_004a5820 — Nth part lookup
  FUN_004a5c40 — teammate part lookup
```

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| Preparation | PITMENU | param_1 (pit crew struct) | (param_1 holds timing constants) | PreparationParams | MEDIUM — doc mentions `Preparation` in code comments but exact offset not mapped |
| FuelTime | PITMENU | (FUN_004a6340 fuel timing) | Fuel timing constants | FuelTimeParams | MEDIUM — FUN_004a6340 adds fuel time with variance; matches FuelTime semantics |
| TireTime | PITMENU | (FUN_004a6340 wheel change timing) | Wheel change timing | TireTimeParams | MEDIUM — FUN_004a6340 has 4 random cubic durations matching "time to change two/four tires" |
| DamageTime | PITMENU | (FUN_004a6340 repair timing) | Repair timing | DamageTimeParams | MEDIUM — repair time added in pit operation timer matches DamageTime |
| AllTires | PITMENU | (PITORDER section) | `AllTires` not explicitly read | AllTires config | LOW — PITMENU.AllTires controls pit menu UI, not directly referenced in doc |
| NumPitstopsRange/Setting | GENERAL | +0x1a8 (pit order count) | pit order count | NumPitstopsSetting | HIGH — hdv GENERAL.NumPitstopsSetting maps to per-vehicle pit stop count read by FUN_004d12c0 |
| Pitstop1Range/Setting | GENERAL | (fuel per stop) | Pitstop1Setting | FuelPerStop | MEDIUM — hdv Pitstop1Range/Setting map to per-stop fuel amounts read by pit strategy loader FUN_00429960 |
| FuelRange/Setting | GENERAL | (initial fuel) | FuelSetting | FuelSetting | HIGH — matches doc's pit strategy format reference |
| StopGo | PITMENU | (penalty flag in pit timer) | StopGo flag | StopGoPenalty | MEDIUM — FUN_004d23d0 clears penalty flag; matches PITMENU.StopGo=1 |

**Note:** Hdv_pm_full.txt reveals the [PITMENU] section is a post-F1C addition (rFactor-era). F1C likely reads fewer PITMENU params or reads them differently. The timing params (FuelTime, TireTime, etc.) may be hardcoded in F1C rather than read from HDV files.

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `CUBE error loading pitcrew mesh %s: %s` | rFactor Dedicated.exe, rFactor.exe | FUN_004a2010 | Confirms pitcrew.cpp as source. Error format matches exactly. |
| `PITANIMS.MAS` | Not in crossref explicitly, but MAS pattern matches | FUN_004a3220 | Pit animation MAS archive — consistent across all ISI games |
| `PITS.MAS` | NASCAR_2003_Demo (shared with F1C), NASCAR_2004 | FUN_004a4900 | Pit area textures MAS — appears in all ISI games |
| `CMAPS.MAS` | NASCAR_2003_Demo (shared with F1C) | FUN_004a4900 | Circuit maps MAS — shared binary string |
| `TEAM.MAS` | (expected, not in crossref output) | FUN_004a4900, FUN_004ddad0 | Team textures MAS — pit crew livery resolution |
| `Crew Is Ready For Pitstop` | rFactor.exe, rFactor Dedicated.exe | (not in doc — commentary function?) | rFactor has this pit crew readiness string; F1C likely has equivalent |
| `Pitstop Requested` / `Pitstop Unrequested` | rFactor.exe, rFactor Dedicated.exe | FUN_004a6e50 (pit state machine) | rFactor has pit request strings; F1C pit state machine has similar state transitions |
| `Entered Closed Pitlane (Cannot Make Pitstop)` | rFactor Dedicated.exe | (not in doc — steward function) | Pit lane closed check — relates to FUN_004d2210 (pit close) |
| `Pitstop Description` | rFactor.exe | (UI) | "Gives extra info about what's taking time in pitstop" — matches FUN_004a58b0 repair status display concept |
| `Pit\pitSounds.mp3` | NASCAR_2003_Demo, NASCAR_2004 | (not in doc — audio) | Pit audio file — exists in multiple ISI games |
| `APP_SpinBox_Garage_PitStopThree/Two/One/NumPitstops` | NASCAR_2003, NASCAR_2004 | (UI gizmo references) | Garage pit stop UI controls — confirmed across ISI games |
| "Time that pits are closed before formation lap" | rFactor.exe | FUN_004d2e50 phase 1 | Pit close timing string matches the `pit_open_time + session_lap_time - race_time` computation |
| "Offset each scheduled pitstop in case you want to carry extra fuel" | rFactor.exe | FUN_00429960 | Pit strategy offset — confirms extra fuel per stop concept |
| `..\Source\pitcrew.cpp` | rFactor.exe, rFactor Dedicated.exe | All FUN_004a2xxx | Confirms pitcrew.cpp as source module across all ISI games |
| `..\Source\hdvehicle.cpp` | rFactor.exe, rFactor Dedicated.exe | (part functions) | HDVehicle is adjacent module for part state management |
| `..\Source\steward.cpp` | rFactor.exe, rFactor Dedicated.exe | FUN_004d1bc0, FUN_004d2210, FUN_004d23d0 | Confirms steward.cpp source mapping |

## SDK Struct Alignment

### VehicleScoringInfo vs F1C Vehicle Struct (pit fields)

| SDK Field | SDK Offset (approx) | F1C Offset | Status |
|-----------|--------------------|------------|--------|
| mNumPitstops (short) | VehicleScoringInfo + 0x60 (after lap times, ~short at +0x60) | +0x1162 (PitStopCount, docs/13) | ALIGNED — F1C offset +0x1162 is a short in vehicle struct; matches SDK mNumPitstops |
| mFinishStatus (signed char, 0=none/1=finished/2=DNF/3=DSQ) | VehicleScoringInfo + 0x42 | +0x4064 (FinishState, 0=running/1=finished/2=DNF/3=DSQ) | ALIGNED — Same enum values per docs/07, FinishState at +0x4064 |

### VehicleScoringInfoV2 vs F1C Vehicle Struct

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| mInPits (bool) | VehicleScoringInfoV2 + 0x72 (after mControl at +0x70, mIsPlayer at +0x6e) | (not explicitly in docs/07 offsets) | NEW — F1C likely has equivalent pit flag; FUN_004a6e50 reads +0x61 (PitState) and +0x62 (PitEntryTimer) |
| mPlace (unsigned char, 1-based) | VehicleScoringInfoV2 + 0x73 | +0x4058 (QualifyingPosition), +0x4060 (FinishPosition) | SHIFTED — SDK uses single mPlace, F1C splits quali/finish |

### ScoringInfoV2 vs F1C globals

| SDK Field | SDK Offset | F1C Equivalent | Status |
|-----------|-----------|----------------|--------|
| mGamePhase (0-8 phases) | ScoringInfoV2 + 0x48 | DAT_007c56a8 (RacePhase 0-7) | MATCH — rFactor phases 0-8 vs F1C 0-7, very close mapping |
| mSession (long) | ScoringInfoBase + 0x40 | DAT_007c56a4 (SessionType) | ALIGNED — both represent session type/ID |
| mMaxLaps (long) | ScoringInfoBase + 0x4C | DAT_008acf9c (TotalRaceLaps) | ALIGNED — both track max laps |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| FUN_004a2010 — Pitcrew Mesh Loader | PitMan::LoadMesh | pitcrew.cpp; RTTI PitMan; loads mesh via FUN_005450e0 |
| FUN_004a22d0 — Pitcrew Animation Loader | PitMan::LoadAnimation | pitcrew.cpp; loads .anm files |
| FUN_004a4900 — Pitcrew Scene File Loader | PitMan::LoadScene | pitcrew.cpp; MAS/scene loading |
| FUN_004a2a90 — Pit Crew Animation Loader | PitMan::ParseMTS | pitcrew.cpp; MTS file parsing |
| FUN_004a3220 — PITANIMS.MAS Animation File Loader | PitMan::LoadPitAnims | pitcrew.cpp; MAS archive wrapper |
| FUN_004a3910 — Pit Crew Animation/MAS Setup | PitMan::InitAnimations | pitcrew.cpp; orchestrator |
| FUN_004ddad0 — Pit Crew Instance Setup | PitMan::SetupCrewInstance | TrackLivery resolution, 9 roles |
| FUN_004d12c0 — Pit Stop Order Loader | PitMan::ReadPitOrder | PITORDER section reader |
| FUN_004a6e50 — Pit State Update Machine | PitMan::UpdatePitState | Main pit state machine (entering/in-pits/exiting) |
| FUN_004a6200 — Pit Stop Ready Check | PitMan::ReadyCheck | Ready flag, position distance |
| FUN_004a6340 — Pit Stop Operation Timer | PitMan::CalcOperationTime | Phase duration accumulator |
| FUN_004a68b0 — Pit Stop Progress Handler | PitMan::UpdateProgress | Animation progression driver |
| FUN_004a5330 — Pit Part State Copy | PitMan::CopyPartState | Part setup copy utility |
| FUN_004a5820 — Nth Valid Part Lookup | PitMan::GetNthPart | Part list iterator |
| FUN_004a5c40 — Teammate Part Value Lookup | HDVehicle::FindTeammatePart | Compares TeamID +0x48a4 |
| FUN_004d1bc0 — Pit Stop Order Rank | Steward::GetPitRank | steward.cpp; precomputed table |
| FUN_004d2210 — Pit Close: Team Ready Check | Steward::ClosePitWindow | steward.cpp; penalty checks |
| FUN_004d23d0 — Pit Timer State Init | Steward::InitPitTimer | steward.cpp; green flag set |
| FUN_004d2e50 — Pit Timer / Race Phase State Machine | Steward::UpdatePitTimer | RacePhase state machine |
| FUN_004a58b0 — Pit Repair Status Display | TvPitMenu::FormatRepairStatus | UI overlay; part wear/cost display |
| FUN_0041be60 — Pit/Race Status Message Dispatcher | HUD::DispatchPitMessage | hud_messages.cpp; commentary IDs |
| FUN_0041ab30 — Pit State Slot Activation / Commentary | Commentary::ActivatePitSlot | Commentary dispatch, slot IDs |
| FUN_0041b3c0 — Pit Selection State Machine | Commentary::PitSelectionState | Commentary buckets, tire/strategy |
| FUN_0041b910 — Clear Pit Selection Flags | Commentary::ClearPitSelection | Clears 3 commentary flags |
| FUN_0041c0f0 — Pit Exit / Release Order Commentary | Commentary::PitExitCommentary | State machine (entering/in/exiting) |

## Summary

**PitMan** is the dominant RTTI class for docs/07 — ~15 of 29 functions likely belong to it. **Steward** claims ~4 functions for race-rule pit management. **TvPitMenu** and **Commentary** systems account for the remaining functions.

The PITMENU section config parameters (Preparation, FuelTime, TireTime, DamageTime, etc.) visible in rFactor's hdv files are likely **post-F1C additions** or read differently in F1C. F1C may hardcode timing values that rFactor reads from .hdv.

The SDK struct alignment confirms:
- VehicleScoringInfo.mNumPitstops ↔ F1C +0x1162 (PitStopCount)
- VehicleScoringInfo.mFinishStatus ↔ F1C +0x4064 (FinishState)
- ScoringInfoV2.mGamePhase ↔ DAT_007c56a8 (RacePhase)
