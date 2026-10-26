# Source Cross-Reference: docs/05-weather-system.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `Weather` | ALL (FUN_004fcaa0, FUN_004fe350, FUN_004fe820, FUN_004fe7c0, FUN_004fe0d0, FUN_004fe1e0, FUN_004fcc30) | HIGH | rFactor Dedicated RTTI: `.?AVWeather@@` (line 679, rfactor_binaries.txt). Source path `..\Source\weather.cpp` present in rFactor.exe, rFactor_Dedicated.exe, and F1C. |
| `?$PFData@W4WeatherCond@@@@` (WeatherCond enum) | FUN_004fe0d0 (Weather Name → Wetness Multiplier), FUN_004fe1e0 (Weather Severity → Grip Multiplier) | MEDIUM | rFactor Dedicated has `.?AV?$PFData@W4WeatherCond@@@@` — a parameter file type wrapper around `WeatherCond` enum. These F1C functions convert weather name strings to wetness/grip multipliers, which would map to enum values. |

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| `WetWeather` | COMPOUND (tbc) | — | — | Tire wet-weather flag | MEDIUM — From config_params.txt line 6412, NASCAR_2003: `WetWeather=1` in generic.tbc. Tire compound property, not in weather struct. |
| `DryLatLong` | COMPOUND (tbc) | — | — | Dry weather lateral/longitudinal coefficients | MEDIUM — rFactor F1 .tbc: `DryLatLong=(2.33828545, 2.452861440)`. Tire grip in dry conditions, used by tire model not weather struct. |
| `WetLatLong` | COMPOUND (tbc) | — | — | Wet weather lateral/longitudinal coefficients | MEDIUM — rFactor F1 .tbc: `WetLatLong=(0.920, 0.932)`. Tire grip in wet. |
| `GripTempPress` | COMPOUND (tbc) | — | — | Grip effects from temperature/pressure dropoff | LOW — Related to how temperature affects grip, but config lives in tbc not weather struct. |
| `Temperatures` | COMPOUND (tbc) | — | — | Optimum operating temp & starting temp | LOW — rFactor F1: `(104.0, 75.0)`. Tire temp model param, not weather struct. |
| `RoadDryGrip` | TRACKVARS (terrain.ini) | — | — | Dry road grip scaling | LOW — Track surface property, not weather system. |
| `RoadWetGrip` | TRACKVARS (terrain.ini) | — | — | Wet road grip scaling | LOW — Track surface property, not weather system. |

No direct parameter-to-offset match found — weather system params (OnPathWetness, OffPathWetness, AmbientTemp, TrackTemp) are computed/runtime values, not loaded from .hdv/.tbc config files. They're stored in a per-session weather state struct (param_1 offsets +0x28 through +0x38 per docs).

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `(D%sweather.txt` | rFactor (unique), rFactor Dedicated (unique) | FUN_004fcaa0, FUN_004fe820 | Both rFactor and F1C use the same `weather.txt` filename format string. The `(D` prefix suggests a directory-relative path format (likely season directory). Confirms weather.txt is the persistent weather config file. |
| `..\Source\weather.cpp` | rFactor.exe, rFactor_Dedicated.exe | All | F1C's weather.cpp implementation is the same source module present in all ISI binaries. |
| `D:\Dev\NASCAR_2003\Source\weather.cpp` | NASCAR_2003_Demo, NASCAR_2003_Patch | All | Nascar 2003 PDB debug path confirms weather.cpp was ported from the NASCAR branch to F1C. |
| `F1_Circuit_AI_Qual_Setup_Wetness` | NASCAR_2003_Demo (unique), NASCAR_2003_Patch (unique) | — | NASCAR had per-circuit AI wetness setups for quali/race. Not present in F1C — suggests F1C simplified this. |
| `APP_SpinBox_RaceCond_Weather` | NASCAR_2003, NASCAR_2004, rFactor | FUN_00470da0 | Weather mode UI spinner. Present across ALL ISI binaries. |

## SDK Struct Alignment

SDK struct: `ScoringInfoV2` (rFactor InternalsPlugin.hpp)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `ScoringInfoV2.mDarkCloud` (float 0.0-1.0) | ~+0x84 | — | NEW — F1C likely tracks this but not at the offsets documented in 05-weather-system.md (which covers a different struct — the per-session weather state struct, not ScoringInfoV2) |
| `ScoringInfoV2.mRaining` (float 0.0-1.0) | ~+0x88 | — | NEW |
| `ScoringInfoV2.mAmbientTemp` (float) | ~+0x8C | param_1+0x30 (AmbientTemp) | MATCH — same field, F1C weather struct offset +0x30 matches conceptual slot |
| `ScoringInfoV2.mTrackTemp` (float) | ~+0x90 | param_1+0x34 (TrackTemp) | MATCH — same field, F1C offset +0x34 |
| `ScoringInfoV2.mWind` (TelemVect3, 3 floats) | ~+0x94 | — | NEW — F1C weather struct doesn't document wind field at +0x20 range. Check if +0x20 is wind vector (3 floats)? |
| `ScoringInfoV2.mOnPathWetness` (float 0.0-1.0) | ~+0xA0 | param_1+0x28 (OnPathWetness) | MATCH — confirmed |
| `ScoringInfoV2.mOffPathWetness` (float 0.0-1.0) | ~+0xA4 | param_1+0x2c (OffPathWetness) | MATCH — confirmed |
| `VehicleScoringInfoV2.mInPits` | ~+0xBA | — | NEW — F1C likely has inPits flag in vehicle struct |

**F1C weather struct vs ScoringInfoV2 weather block comparison:**
The F1C weather state struct (param_1 bases at +0x28 onwards) aligns well with the weather
block inside ScoringInfoV2 (mAmbientTemp, mTrackTemp, mOnPathWetness, mOffPathWetness).
F1C lacks the wind vector (mWind) documentation — offset +0x20 in the weather struct
(initialized 0 in FUN_004fcaa0) could be a 3-float wind vector (x, y, z).

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| `DAT_007cf080` | WeatherMode | Already named correctly in docs. rFactor enum type `.?AV?$PFData@W4WeatherCond@@@@` confirms this is a `WeatherCond` enum. |
| `DAT_005ec438` | WeatherDir | Already documented as weather directory. rFactor source paths show `..\Source\weather.cpp` is shared. |
| `param_1 + 0x20` | WindVector or AmbientWetness | In FUN_004fcaa0, +0x20 is initialized to 0. In SDK ScoringInfoV2, this slot aligns with mWind (TelemVect3 = 3 floats). Alternatively could be mDarkCloud/mRaining pair. |

## Key Findings

1. **Weather is a first-class ISI engine module**: The `Weather` RTTI class and `WeatherCond` enum exist in rFactor Dedicated, confirming `weather.cpp` is a proper engine component with a class interface, not just utility code.

2. **F1C weather struct is a subset of rFactor ScoringInfoV2**: The per-session weather state (OnPathWetness, OffPathWetness, AmbientTemp, TrackTemp) matches the weather block in `ScoringInfoV2`. F1C likely doesn't have the wind vector (mWind) or cloud/rain fields at the same struct level.

3. **Code lineage**: `weather.cpp` was added in the NASCAR 2003 codebase (`D:\Dev\NASCAR_2003\Source\weather.cpp`) and carried forward into F1C's merged source tree. Not present in F1 2000 or the Common source set.

4. **Config difference**: F1C weather severity values (monsoon=0.61 wetness, etc. from FUN_004fe0d0) are internal hardcoded mappings. rFactor's approach uses the WeatherCond enum as a parameter file type, allowing modders to define custom weather condition names and values via .gdb files.

5. **AI wetness setup**: NASCAR 2003 had `F1_Circuit_AI_Qual_Setup_Wetness` and `F1_Circuit_AI_Race_Setup_Wetness` per-circuit AI tuning strings not found in F1C — suggesting the AI wet-weather adaptation system was simplified in F1C or uses a different mechanism.
