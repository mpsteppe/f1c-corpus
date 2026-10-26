# 42 — F1CUI Virtual Safety Car (VSC) System

Fully reverse-engineered from `F1CUILive.jar` bytecode (2026-07-22).
Raw class files extracted to `source_material/F1CUI/`.
Primary classes: `f1c_VSCdata`, `f1c_memoryReaderAndWriterEngine`, `f1c_magicData`.

Trust tier: **FACT** (raw bytecode decompilation, not doc inference).

## Address Model Discovery

F1CUI's `DriverDataArrayBase` (0x005F0DEC) is **NOT** the vehicle struct base.
It is **0x4714 bytes into** each vehicle struct (whose real base is ~0x5EC6D8).

The Java bytecode uses `lsub` (subtract) and `ladd` (add) from this anchor:
```
Actual struct offset = 0x4714 - F1CUI_value    (lsub operations)
Actual struct offset = 0x4714 + F1CUI_value    (ladd operations)
```

**Proof:** `fillSingleDynData()` computes base as `processBase + 0x1F0DEC + stride*i`,
which equals `0x5F0DEC + 0x48C0*i`. The first read is `readMemoryAsString(base)` —
a driver file path. Then `coordinatesInTrack.x` at `base - 16136` (lsub) gives
actual offset `0x4714 - 0x3F08 = 0x080C`, confirmed as a valid struct field position.

This means ALL "Offset" values in docs/26 are **subtraction constants from the
0x4714 anchor**, not direct byte offsets from the vehicle struct start.

### IDA Cross-Reference Validation

| Field | F1CUI sub value | Actual offset | IDA xrefs | IDA context |
|-------|----------------|---------------|-----------|-------------|
| carConditions | 2472 (0x9A8) | **+0x3D6C** | 6 | AI driving adjusts when ==2; damage indicator |
| maxSpeed | 476 (0x1DC) | **+0x4538** | 2 | F1CUI speed cap write target |
| driverRaceStatus | 516 (0x204) | **+0x4510** | 4 | AI behavior state machine (0=race,4=retire,7=slow) |
| position | 1716 (0x6B4) | **+0x4060** | 9 | Race position tracking |
| FinishState | — | **+0x4064** | 19 | 1=racing, 2=DNF, 3=DSQ |
| failureCategory / ReasonCode | — | **+0x4068** | 1 | FailureCategoryNameLookup: 1-9 enum |

**Note on driverStatus:** F1CUI's `driverStatus` at subtraction value 516 maps to
actual offset +0x4510 — this is the **AI behavior state machine**, NOT the
FinishState at +0x4064. They are separate fields 0x4AC bytes apart.

## VSC Activation — Fully Automatic

No button, no user input. `f1c_VSCdata.updateSituation()` runs every frame.

### Detection pipeline

1. `checkSituation()` iterates all vehicles via `f1c_variables.dynData` TreeMap
2. For each vehicle that `isRacing()` AND `isOutOfPit()`:
   - `carConditions == 1` → `newNumberOfDamagedCarsOnTrack[0]++` (minor)
   - `carConditions != 0 && != 1` → `newNumberOfDamagedCarsOnTrack[1]++` (heavy)
3. Builds `carsInvolvedInAccidentTmp` list with driver names

### Trigger condition

`checkEnableVSC()` fires when:
- `new[0] > old[0]` OR `new[1] > old[1]` (new damage detected)
- Combined score: `damage_score = new[1]*2 + new[0]`
- If `damage_score > 0` AND `VSCFrequency > 0` (config not disabled): activate

### VSC end condition

When `damage_score == 0` (all damaged cars cleared):
- If VSC was active: set `VSCEndingTime = current + VSCEndingPreAlertTime`
- Play `VSCEndingBack` audio
- Set `VSCEnabled = false`, `VSCEnding = true`
- After ending time passes: full restore

## What VSC Does When Active

### 1. AI Speed Limiting

Two methods, chosen by config:

**`setLimitToAISpeed()`** — when `VSCMaxAISpeed > 0`:
- Iterates all vehicles
- Skips player (`isPlayer()` check)
- Writes `VSCMaxAISpeed` float to `maxSpeed` field (actual offset +0x4538)
- Memory write: `writeFloatToMemory(driverMemoryAddress - 476, value)`
- Retries up to 10 times if data not ready

**`setLimitToAIEngines()`** — fallback when `VSCMaxAISpeed == 0`:
- Computes RPM cap: `VSCMaxEngineRPM / 9.5493`
- Writes to `EngineMaxRPM` field (actual offset +0x39A4)
- Memory write: `writeFloatToMemory(driverMemoryAddress - 3440, value)`
- Also adjusts `carDefConsumptionInRace` for fuel consumption reduction

### 2. Fuel Consumption Reduction

`VSCFuelConsumptionReductionPercentage` config applied per-car to reduce fuel burn
during VSC period. Written alongside speed limits.

### 3. Forced Pit Calls

At VSC start, `updateVSC()` checks each AI car:
- Fuel% < `VSCFuelPercentageForBoxCall` → force pit
- Tire condition < `VSCForceAIPitStopTireLevel` → force pit
- Adds driver to `carsCalledToBoxDueToVSC` list
- Writes planned pit stop via `f1c_pitStopPlannedData.buildExtraPitFromDriver()`
- Memory write to `callToBox` field (actual offset +0x454C)

### 4. Average Speed Tracking

`checkSituationWithVSCOn()` maintains per-driver running average speed:
- `carsAvgSpeedFromStart` TreeMap: `{driverName: [count, avgSpeed]}`
- Rolling average: `newAvg = (oldAvg * count + currentSpeed) / (count + 1)`
- Skips player
- `maxSpeedLimit` = max of all AI avg speeds (used for calibration)

### 5. No-Overtake Enforcement (Post-Hoc)

F1CUI does **NOT** prevent overtaking in real-time. It **TRACKS** it.
`carsOvertakesSinceVSCStart` TreeMap accumulates overtake counts per driver.

At VSC end (`applyLogicAtVSCEnd()`):
- **Player:** ≥5 overtakes → DQ (`disqualifyDriverVSC`)
- **Player:** <5 overtakes → time penalty = overtakes * 10 seconds
- **Player:** `VSCOnlyConsiderPlayerForPenalties == 3` → exempt
- **AI:** ≥3 overtakes → DQ (if `VSCOnlyConsiderPlayerForPenalties == 0`)
- **AI:** <3 overtakes → penalty via `vscIsDTScenario` / `vscIsSGoScenario`
- **AI:** `VSCOnlyConsiderPlayerForPenalties >= 2` → AI exempt

### 6. Damage Disable (Optional)

`VSCDisableAIDamageDuringVSC` config flag — prevents AI mechanical failures
during VSC period so cars don't randomly break while slowed.

### 7. Audio

- VSC start: `VSCOnBack` audio clip
- VSC ending: `VSCEndingBack` audio clip
- Service messages: "Race Control: VSC deployed for %1" / "VSC ending for %1"

## Configuration Fields (f1c_magicData)

| Field | Type | Purpose |
|-------|------|---------|
| VSCFrequency | int | 0=disabled, nonzero=enabled |
| VSCMinDuration | int | Minimum VSC duration (seconds) |
| VSCMaxDuration | int | Maximum VSC duration (seconds) |
| VSCMinDelay | int | Minimum delay before VSC starts |
| VSCMaxEngineRPM | int | Engine RPM cap (÷9.5493 for radians/s) |
| VSCMaxAISpeed | float | Direct AI speed cap (0=use RPM method) |
| VSCFuelPercentageForBoxCall | int | Fuel% threshold for forced pit |
| VSCFuelConsumptionReductionPercentage | int | Fuel burn reduction during VSC |
| VSCEndingPreAlertTime | int | Seconds warning before VSC ends |
| VSCDisableAIDamageDuringVSC | int | Prevent AI failures during VSC |
| VSCOnlyConsiderPlayerForPenalties | int | 0=all, 1=player+AI, 2=player, 3=none |
| VSCConsiderOvertakingDamagedCarsLegal | int | Skip damaged cars in overtake count |
| VSCTireConsumptionForBoxCall | String | Tire threshold for forced pit |
| VSCForceAIPitStopTireLevel | float[] | Per-tire thresholds for forced pit |

## State Machine Summary

```
INACTIVE ──[new damage detected]──→ ACTIVE
   ↑                                   │
   │                                   ├─ speed cap applied
   │                                   ├─ fuel reduction applied
   │                                   ├─ forced pits triggered
   │                                   ├─ overtakes tracked
   │                                   │
   │                           [damage_score → 0]
   │                                   │
   │                                   ↓
   │                              VSC_ENDING
   │                                   │
   │                           [ending time passes]
   │                                   │
   │                                   ├─ speed restored
   │                                   ├─ forced pits cancelled
   │                                   ├─ overtake penalties applied
   │                                   │
   └───────────────────────────────────┘
```

## Relevance to Red Flag Mod

The F1CUI VSC detection logic (auto-trigger on `carConditions` change) maps
directly to automatic red flag activation. Key differences for our mod:

- F1CUI triggers VSC on ANY damage type; red flag should filter to `failureCategory == 6` (Accident) only
- F1CUI slows cars; red flag stops the race and restarts
- F1CUI runs as external Java overlay reading memory; our mod is an injected DLL writing memory
- F1CUI tracks overtakes post-hoc; we can skip this for red flag (race stops anyway)

### Offsets to poke-prove for gr27

1. `carConditions` (+0x3D6C) — read during crash to detect damage state
2. `failureCategory` (+0x4068) — read to filter accident vs mechanical
3. `maxSpeed` (+0x4538) — write to slow AI during pre-restart period
4. `FinishState` (+0x4064) — read to skip already-retired cars

All IDA-confirmed with xrefs. Need live game poke-verification before DLL code.
