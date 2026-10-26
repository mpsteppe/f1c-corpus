# AI System - Ability, Qualifying, Speed Pipeline

## AI Qualifying â€” Synthetic vs Real

### Key finding: Two completely separate code paths

**Real laps (AI car on track):** Uses `RaceAbility` + quadratic AI-slider scaling +
track-specific characteristics. `QualifyingAbility` is NOT consulted during real driving.

**Synthetic time generation (player exits session early):** Uses `QualifyingAbility`
exclusively via `FUN_004bf6a0` (confirmed in decompile, address `0x004bf6a0`).

### QualifyingAbility â€” Storage and Noise

Loaded inverted from `.rcd`:
```c
param_1[0x1130] = (int)((1.0 - QA) * scale);
```
Higher QA value â†’ smaller stored delta â†’ faster synthetic lap time.

**Session-persistent noise ring buffer** (discovered in decompile, not documented):
```c
counter = DAT_008aae70 & 0xff;   // 256-slot ring buffer, wraps
DAT_008aae70++;
return (history[counter] * scale - offset) + QA_from_rcd / constant;
```
- The ring buffer is NOT reset between sessions
- Each AI driver consumes one slot per synthetic time generation
- Produces slightly different synthetic gaps each weekend even with identical `.rcd` files
- Explains observed quali variance in unchanged seasons

The `constant` in `QA / constant` is a track-specific time-per-ability-unit scalar
(likely loaded from `.gdb` or `.trk` â€” not recovered, in anonymous function mass).

---



---

## AI Strength Scaling - Quadratic

## AI Strength Scaling â€” Quadratic (NEW FINDING)

Source: `FUN_00424080` @ `0x00424080`, lines 146â€“149 in decompile.

```c
if (DAT_007d01a0 < 100) {   // DAT_007d01a0 = global AI difficulty slider
    RaceAbility = (slider/100.0) * (slider/100.0) * RaceAbility;
}
```

**The AI strength slider is NOT linear â€” it is quadratic.**

| Slider | Effective multiplier |
|--------|---------------------|
| 100%   | 1.00Ã— (no scaling)  |
| 90%    | 0.81Ã—               |
| 80%    | 0.64Ã—               |
| 70%    | 0.49Ã—               |
| 60%    | 0.36Ã—               |
| 50%    | 0.25Ã—               |

**Implication for modding:** `.rcd` RA delta values are compressed quadratically
at non-100% slider. At 70% slider, our chaos deltas are effectively halved in impact
relative to what they'd be at 100%. If users run 70â€“80% AI, chaos ranges should be
wider to achieve the same perceived variance.

Only applies when slider < 100. At exactly 100, the branch is skipped entirely
(no scaling applied).

---


---

## AI Ability Processing - Full Runtime Formulas

## AI Ability Processing â€” Full Runtime Formulas

Source: `FUN_00424080` @ `0x00424080` (AI profile loader), `FUN_004040a0` (AI database init)

### Global AI Speed Multiplier (NEW â€” undocumented)

`FUN_004040a0` computes `aiDB[0x46]` at startup via **linear interpolation** based on
the global AI difficulty slider (`DAT_007d01a0`):

```
slider â‰¤ 100:  aiSpeedMult = 0.5 + (slider - 70) Ã— (1/30)
               At 70 â†’ 0.50Ã—, at 85 â†’ 0.75Ã—, at 100 â†’ 1.00Ã—

slider > 100:  aiSpeedMult = 1.0 + (slider - 100) Ã— 0.05 Ã— 0.3
               At 100 â†’ 1.00Ã—, at 110 â†’ 1.15Ã—, at 120 â†’ 1.30Ã—
```

The curve endpoints are stored in `aiDB[0x47]=0.5`, `aiDB[0x48]=1.0`,
`aiDB[0x49]=1.3`. This is independent from and additive to per-car quadratic scaling.

**Two-tier scaling:** per-car RaceAbility uses quadratic (square law), global difficulty
uses linear. They operate on different internal values at different points in the pipeline.

### RaceAbility â†’ Runtime Speed Delta

Reference maximum: **22.0** (`_DAT_0059e85c`). In-game RA values cap around 20-22.

```
raw_delta = (22 - RaceAbility) / 22
            RA=22 â†’ 0.000 (ideal), RA=11 â†’ 0.500, RA=0 â†’ 1.000

stored at param_1[0x1131]

if slider < 100:
    param_1[0x1131] = (slider/100)Â² Ã— raw_delta
```

Stored value is a **slowness fraction** â€” 0 = ideal performance, 1 = worst.
Quadratic scaling at low difficulty makes this fraction smaller â†’ AI drives CLOSER to
ideal. Effect: at 70% difficulty, weakest AI (RA=3) runs at 42% of their raw gap from
ideal instead of 86%.

Secondary derived values also stored:
```
param_1[0x113d] = (1 - RaceAbility Ã— 0.01) Ã— DAT_005ea3d8   [speed target, runtime-scaled]
param_1[0x1136] = (1 - param_1[0x113d]) Ã— 0.67
param_1[0x1135] = (22 - RaceAbility Ã— 0.67) Ã— (1/22)
```

`DAT_005ea3d8` is a runtime variable (0 in file) â€” set during session init, likely
the track's AI reference lap time or speed scalar.

### RainAbility â€” Rain Sensitivity (INVERTED from intuition)

```
param_1[0x1132] = RainAbility Ã— 0.01 Ã— global_rain_scale
param_1[0x1160] = 1.0 - current_wetness Ã— param_1[0x1132]
```

**Higher RainAbility = MORE wet sensitivity = WORSE in rain.**
Lower RainAbility = rain specialist (less affected by wet track).

`param_1[0x1160]` is a speed multiplier applied during wet conditions.
At dry (wetness=0): multiplier = 1.0 always.
At full wet: multiplier = 1.0 - (RA Ã— 0.01 Ã— scale).

### Passing â†’ Overtake Effort Factor

```
param_1[0x1133] = Passing Ã— 0.001 + 0.9   (capped at 1.0)
```

Maps [0â€“100] â†’ [0.90â€“1.0]. Default raw Passing=50 â†’ stored 0.95. This is likely
an effort multiplier for overtaking maneuvers (90â€“100% throttle threshold).

### TrackAggression Runtime Scale

```
param_1[0x113e] = TrackAggression Ã— DAT_007d017c
if param_1[0x113e] < 0.01: enforce minimum 0.01
```

`DAT_007d017c` = global TrackAggression multiplier (runtime, per-track or session).

---


---

## Undocumented .rcd Fields

## Undocumented .rcd Fields (NEWLY DISCOVERED)

Source: `FUN_00424080` â€” reads these fields from .rcd that are NOT in any modding docs:

### CorneringAdd / CorneringMult

```
param_1[0x1140] = CorneringAdd    (default 1.5)
param_1[0x1141] = CorneringMult   (default â‰ˆ 0.967)
```

These modulate AI cornering speed. How exactly they interact with physics is in
anonymous functions â€” but they exist as settable .rcd fields.

### StartsDry / StartsWet

```
raw_start = current_wetness Ã— StartsWet + (1 - current_wetness) Ã— StartsDry
raw_start += rand() % 200 Ã— 0.01   [Â±1.0 random variation]
raw_start = clamp(raw_start, -4.0, 4.0)
param_1[0x112e] = raw_start Ã— 0.1 + 1.0   [maps to 0.60 â€“ 1.40]
```

This is a **tire start temperature multiplier**. Higher = warmer tires at race start.
Blended by track wetness between dry and wet tire temperature setups.

**No documentation exists for these fields in any modding guide.**

---


---

## AI Speed Pipeline - Full Chain

## AI Speed Pipeline â€” Full Chain

Source: `FUN_004040a0`, `FUN_00424080`, `FUN_0042a180` @ `0x0042a180`, `FUN_00429470` @ `0x00429470`

### Stage 1 â€” Global speed multiplier (session init, anonymous)

`FUN_004040a0` computes `aiDB[0x46]` from slider at startup (linear, 0.5â€“1.3Ã—, see
**AI Ability Processing** section). An anonymous session init function then does:

```
DAT_005ea3d8 = aiDB[0x46] Ã— track_reference_speed
```

`DAT_005ea3d8` is a `.data` runtime global (file value = 0.0, set each session). It is
the **track-scaled AI reference speed** after applying the global difficulty multiplier.
The anonymous setter lives outside the string-anchored decompile set.

### Stage 2 â€” Per-car speed targets (FUN_00424080, at vehicle load)

```c
param_1[0x113d] = (1 - RA * 0.01) * DAT_005ea3d8          // base speed target
param_1[0x1136] = (1 - param_1[0x113d]) * 0.67             // variation window
param_1[0x1135] = (22 - RA * 0.67) * (1/22)                // push probability threshold
param_1[0x114f] = 1.0                                       // current lap ratio (init)
```

`param_1[0x114f]` is the **live lap time ratio** â€” the speed the AI is actually
targeting this lap, relative to 0x113d. Initialized to 1.0 (neutral) at session start.

### Stage 3 â€” Rain penalty (FUN_0042a180, each physics update)

```c
// Recomputed continuously from live wetness:
param_1[0x1160] = 1.0 - DAT_008afee8 * param_1[0x1132]
// DAT_008afee8 = current track wetness (runtime)
// param_1[0x1132] = RainAbility * 0.01 * global_rain_scale
```

Clamped minimum `0.5`. Higher RainAbility = lower 0x1160 multiplier = slower in wet.

In **non-race sessions only**, FUN_0042a180 also updates 0x114f toward the target:
```c
// Non-race: drift 0x114f toward 0x113d + 0x1136 (fastest safe speed)
// Adjustment step = lap_count * 0.003 (faster improvement with more laps)
```

### Stage 4 â€” Per-lap speed update (FUN_00429470, each lap completion, race only)

```c
// At lap completion with session == 7 (Race):
if (param_1[0x1142] == 0) {       // was in "conservative" lap
    fVar2 = param_1[0x114f] - 0.01;
    if (fVar2 < param_1[0x113d]):  // floor at base target
        fVar2 = param_1[0x113d];
} else {
    // push lap: 0x114f moves toward (0x113d + 0x1136)
    fVar2 = param_1[0x1136] + param_1[0x113d];
    if (param_1[0x114f] + 0.01 <= that):
        fVar2 = param_1[0x114f] + 0.01;  // step up slowly
}
param_1[0x114f] = fVar2;

// Pushing probability (rolls each lap):
prob = (param_1[0x1135] - param_1[0x1143] * 0.5) * 100
if rand()%100 <= prob:
    // aggressive: jump 0x114f to maximum (0x113d + 0x1136)
else:
    // conservative: pull 0x114f back toward 0x113d * 0.5
param_1[0x1142] = 0;
param_1[0x1143] = 0;
```

`param_1[0x1143]` counts consecutive push laps; repeated pushing lowers push
probability via the `0x1143 * 0.5` subtraction â€” AI self-throttles sustained aggression.

### Difficulty-scaled finish predictor

`FUN_004bf0a0` passes `slider Ã— (1/120)` to `FUN_004be760` (finish time predictor).
At slider=100: parameter â‰ˆ 0.833. At slider=120: parameter = 1.0. Higher difficulty =
tighter predicted finish times. `_DAT_005acde0 = 1/120 â‰ˆ 0.00833` (confirmed `.rdata`).

### Runtime struct fields â€” quick reference

| Offset | Content |
|--------|---------|
| 0x113d | Base speed ratio this session (from RA + track ref) |
| 0x1136 | Speed variation window above 0x113d |
| 0x1135 | Push-lap probability reference |
| 0x114f | Live lap target this lap (Â±0.01/lap) |
| 0x1132 | RainSensitivity = RA Ã— 0.01 Ã— rain_scale |
| 0x1160 | WetSpeedMult = 1 - wetness Ã— 0x1132 (â‰¥ 0.5) |
| 0x1142 | Lap type flag (0=conservative) |
| 0x1143 | Consecutive push lap counter |

---

## ai_db.cpp - AI Waypoint Database (3 functions)
### ai_db.cpp â€” AI Waypoint Database (3 functions)

#### FUN_004040a0 â€” AIDatabase::Init()

Initializes the AI database struct (param_1). Confirms and expands existing
documentation of the global AI speed multiplier:

```c
// Default aiDB values:
param_1[0x00] = 4.5f      // 0x40980000
param_1[0x01] = 4.3125f   // 0x408a0000
param_1[0x47] = 0.5f      // min global speed mult
param_1[0x48] = 1.0f      // mid global speed mult
param_1[0x49] = 1.3f      // max global speed mult
param_1[0x58] = 104       // grid spots (0x68)
param_1[0x59] = 52        // pit spots (0x34)
param_1[0x5a] = 3         // garage spots
param_1[0x57] = 1         // unknown flag

// Global speed multiplier computation (aiDB[0x46]):
if (slider > 100):
    f = (slider - 100) * _DAT_0059e448
    aiDB[0x46] = f * aiDB[0x49] + (1.0 - f) * aiDB[0x48]
else:
    f = (slider - 70) * _DAT_0059e474
    aiDB[0x46] = f * aiDB[0x48] + (1.0 - f) * aiDB[0x47]
```

Then opens "AI Database File" config (from DAT_007ce608 path) and loads
waypoint database via FUN_00402690.

**New constants:**
- `_DAT_0059e448` = slider>100 interpolation rate
- `_DAT_0059e474` = sliderâ‰¤100 interpolation rate
- `_DAT_0059e478` = default value for param_1[0x4f..0x51] (3 entries)

#### FUN_00402690 â€” Waypoint Database Loader

Reads `.gdb` file sections: `Features`, `GRID`, `PITS`, and waypoint data.

**AI database struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x00 | GrooveWidth |
| +0x04 | GrooveWidthWet |
| +0x11c | WorstAdjust (AI racing line, clamped â‰¥0.5) |
| +0x120 | MidAdjust |
| +0x124 | BestAdjust (clamped â‰¤1.3) |
| +0x128 | RaceQualRatio |
| +0x12c | LeftHandedPits (bool) |
| +0x130 | waypoint count |
| +0x134 | waypoint array (stride 0x13c) |
| +0x13c | lap_length |
| +0x140 | sector_1_length |
| +0x144 | sector_2_length |
| +0x14c | FuelUse |
| +0x150 | grid array (stride 0x1c, max 104) |
| +0x154 | pit array (stride 0x1c, max 52) |
| +0x158 | garage array (stride 0x1c) |
| +0x15c | pitlanes count |
| +0x160 | startinggrid (min 104) |
| +0x164 | pitspots (min 52) |
| +0x168 | garagespots (min 3) |

**Waypoint struct (stride 0x13c = 316 bytes):**
| Offset | Field |
|--------|-------|
| +0x00 | wp_pos (3 floats: x, y, z) |
| +0x08 | wp_perp (3 floats: perpendicular vector) |
| +0x0b | wp_width (4 floats) |
| +0x16 | wp_dwidth (4 floats) |
| +0x12 | wp_score |
| +0x21 | wp_event (2 values) |
| +0x46 | wp_galpha |
| +0x47 | wp_groove_lat |
| +0x48 | wp_ptrs (3 next-waypoint pointers) |
| +0x4b | wp_branchID |
| +0x4c | wp_bitfields |
| +0x4d | wp_wpse (2 values) |
| +0x110 | next waypoint pointer (linked list) |
| +0x25 | wp_pos copy (backup) |

Also reads fog parameters: IntermediateFogLevel, IntermediateFogPlanes,
RainyFogPlanes, IntermediateFogColor, RainyFogColor, FogDensity, RainyDarkness.
These feed into globals DAT_008aff80â€“DAT_008affb8.

#### FUN_004024f0 â€” Waypoint Path Validator

Traverses waypoint linked list (via +0x110 next pointer), max 12000 iterations.
If path doesn't loop back to start â†’ "Incomplete waypoint path" warning.
Draws debug lines between consecutive waypoints (FUN_004cefa0, codes 9/10).

---

## FUN_00433890 - AI Settings File Resolver
### FUN_00433890 â€” AI Settings File Resolver

Resolves which AI settings file to use for the current session. Checks in order:
1. `SettingsCopy` â€” if present, use that path (override)
2. `SettingsAI` â€” if present, use that path
3. If session == 5 (qualifying): `SettingsAIQual` â€” if present, use that path

Builds path from `DAT_005ec440` (settings directory) + resolved filename.
Returns path string in param_1 (max param_2-1 chars).

**Globals:**
- `DAT_007ce5ec` â€” settings file path
- `DAT_005ec440` â€” settings directory
- `DAT_007c56a4` â€” session type (5 = qualifying)

---

## FUN_004333e0 - AI Settings File Loader
### FUN_004333e0 â€” AI Settings File Loader

For each vehicle (loop by `DAT_005c329c`), loads AI settings file:

1. Calls `FUN_00433890` to resolve settings filename
2. If `DAT_007d03e0 == 0` (simple mode): copies settings path to vehicle +0x4794
3. Else (advanced mode): builds full path from settings dir + team name + suffix:
   - Session 5 (qualifying): `.qual` suffix
   - Other sessions: `.race` suffix
   - Falls back to `ai.svm` if no session-specific file found
4. Opens file, copies path to vehicle struct

**Vehicle struct offsets:**
| Offset | Field |
|--------|-------|
| +0x4714 | team/livery name |
| +0x4794 | AI settings file path (max 0xff) |
| +0x4893 | null terminator |
| +0x4894 | team/pit index |
| +13000 (0x32C8) | vehicle active flag |

**Globals:**
- `DAT_007d03e0` â€” AI settings mode (0=simple, nonzero=advanced)
- `DAT_005c329c` â€” vehicle count
- `DAT_007c54f0` â€” vehicle array
- `DAT_007c56a4` â€” session type

**Moddability:** Confirms the AI settings file resolution chain.
Mods write `.svm` files â€” this function shows the game looks for
`.race`, `.qual`, then `ai.svm` fallback per vehicle.

---

## FUN_0042b8d0 — AI Shift Pattern / Upshifts-Downshifts Config

Source: Likely `ai_db.cpp`. Reads shift pattern preferences for AI drivers.

Reads `Upshifts`, `Downshifts` fields from AI config. Also reads `Disallowed`
(flags for disallowed shift ranges). Calls `FUN_004b15d0` (shift validation)
and `FUN_00423a00` (string field reader).

If shift validation fails, copies shift string to `DAT_005ec4cc` (message buffer)
and displays via `FUN_0045bd10` (priority 3).

**Shift struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x00 | Upshift RPM target |
| +0x04 | Downshift RPM target |
| +0x08 | Flags (disallowed ranges) |

Not moddable — AI shift behavior config only.

---

## FUN_004bf790 — AI Opponent Selection / NotAI Slot Filler

Source: `ai_opponent.cpp`. Fills non-player (NotAI) grid slots with randomly selected AI opponents. Entry point for building the AI opponent list each session.

**Key logic:**
- If param_2 < 0xb and `FUN_004bfa00` returns same ID: returns early (slot already filled)
- Otherwise: randomly selects `param_2` AI drivers from pool (`FUN_004c5070`/`FUN_005871f0` random index)
- For each candidate:
  - Checks for duplicates via `FUN_00588410` (string compare)
  - Creates linked list node: stores AI entry pointer + QualifyingAbility score (`FUN_004bf6a0` from entry+0x2f)
  - Appends to linked list at param_1
- After selection: **merge-sorts** linked list by QualifyingAbility score (ascending)
- Returns count of AI drivers selected (`local_208`)

**Node struct (0xc bytes):**
| Offset | Field |
|--------|-------|
| +0x00 | AI entry sub-node pointer (8 bytes: ID + QA score float) |
| +0x04 | Next pointer (linked list) |
| +0x08 | Flag byte (set to 1) |

**Calls:** FUN_004bfa00 (slot check), FUN_004bf6a0 (QA score), FUN_004c5070/FUN_004c50e0 (AI pool access), FUN_00588410 (string compare), FUN_004c2e20 (free), FUN_0058815f (format "%s NOT: NotAI")

**Moddability:** Entry point for AI driver selection. The pool size and selection randomness govern which AI opponents appear in a session. Directly affects AI lineup variety.

---

## FUN_004122c0 — Session String/Name Lookup

Source: ai_db/setup.cpp. Resolves a string reference for a vehicle/player slot based on game mode and indexing parameters.

**Key logic:**
- Resolves target struct via FUN_00415650(param_3)
- If DAT_007d0398 == 0 and conditions met, computes offset into vehicle array (DAT_008ac394, stride 0x424)
- Selects one of 8 string pointer offsets based on param_2 (0/1), param_5, param_4
- Copies string metadata, returns comparison result

**Calls:** FUN_00415650, FUN_00566650, FUN_00415550, FUN_004134d0

**Moddability:** hardcoded

---

## FUN_00418ee0 — AI Target Driver Selection

Source: ai_db/driver_selection.cpp. Scans all drivers to find best candidate for AI priority targeting.

**Key logic:**
- Iterates driver slots (stride 0x48c0) from DAT_005f0cf8 up to 0x7c9af7
- Marks slots: invalid (-1), player's team (1), same class (2)
- When RaceMode==4, performs distance/speed comparison to find best ahead target
- Returns primary target or best-gap fallback

**Globals:** DAT_007d0410, DAT_007c54e8, DAT_005f0cf8, DAT_0059e43c, DAT_0059e7f4

**Calls:** FUN_0041e890, FUN_0041e840, FUN_004c2990

**Moddability:** hookable

---

## FUN_00419120 — AI Driver State Transition

Source: ai_db/ai_driver_state.cpp. Transitions AI driver to new state with audio triggers.

**Key logic:**
- Early exits if DAT_007d0308==0, DAT_007cf3c8==DAT_0059e440, DAT_007c56a8==8
- Random init via FUN_004144d0()
- If SessionType 7 (race) and same team as player: plays audio 0x103+0x78 or 0xc6
- Uses distance check with DAT_0059e804 threshold and ring buffer filter DAT_008aae70
- Updates state at param_1+0x1b0

**Calls:** FUN_004144d0, FUN_004189f0, FUN_004d1b50, FUN_004144f0, FUN_00418560

**Moddability:** configurable

---

## FUN_004193a0 — AI Session Mode Transition

Source: ai_db/session_mode.cpp. Handles AI session mode transitions (practice/quali/race).

**Key logic:**
- Early exits on session inactive guards
- Resolves driver index via FUN_004d7cc0, state via FUN_004d1ad0
- Only proceeds if state==2 and stored mode != 2
- Plays audio per mode: 0x89/0x8a (practice), 0x85/0x86 (quali), 0x87/0x88 (race)
- Updates stored mode at param_1+0x4f0

**Calls:** FUN_004d7c10, FUN_004d7cc0, FUN_004d1ad0, FUN_004144d0, FUN_00418a20, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_00419500 — AI Corner Speed Comparison

Source: ai_db/corner_speed.cpp. Compares AI speed vs player at corner sections, triggers audio commentary.

**Key logic:**
- Early exits on session guards
- Only proceeds if SessionType 5 and same team
- Reads AI speed from DAT_005f0780 + stride 0x1230
- Compares vs player speed at param_1+0x404c
- If AI slower: audio 0x0d/0x0e (corner entry/exit). If faster: 0x13/0x14
- If param_2==2 and pitState==1: calls FUN_0041a170

**Calls:** FUN_004144d0, FUN_004d1b50, FUN_004144f0, FUN_00418560, FUN_0041a170

**Moddability:** hardcoded

---

## FUN_00419690 — AI Overtake/Defend State Change

Source: ai_db/overtake_defend.cpp. Manages overtaking/defending state transitions with audio.

**Key logic:**
- Guard checks on globals
- Three branches: param_2=0 (overtake attempt), 1 (defend), 2 (other)
- Sets param_1+0x1b0+param_3*4 = 1
- Plays different audio IDs based on session type and slot

**Calls:** FUN_004144d0, FUN_00418a20, FUN_004144f0, FUN_00418560

**Moddability:** hookable

---

## FUN_004198b0 — AI Position Change Event

Source: ai_db/position_change.cpp. Detects position changes and triggers audio.

**Key logic:**
- Compares stored position vs new +0x4060
- If different: plays improvement audio 0x11 or drop audio 0x12
- AI cars: 0x07 (2 cars), 0x08/0x09 (gain/drop multi-car)

**Calls:** FUN_004144d0, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_004199e0 — AI Retirement/Vehicle Failure Event

Source: ai_db/retirement.cpp. Handles retirement events with audio.

**Key logic:**
- Guard checks, audio 0x29 with position
- Checks retirement links at +0x40d0/+0x40d4
- If laps remaining == 1: audio 0x111. If 2..0x32: audio 0x110

**Calls:** FUN_004144d0, FUN_004144f0, FUN_00418560, FUN_0049b6d0

**Moddability:** configurable

---

## FUN_0041a0c0 — AI Out-of-Track Event

Source: ai_db/track_limits.cpp. Triggers audio when AI goes off-track.

**Key logic:**
- Guard checks, plays audio 0x108
- Full audio emit with driver index

**Calls:** FUN_00418a20, FUN_004144d0, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041a170 — AI Vehicle Damage Event

Source: ai_db/vehicle_damage.cpp. Triggers audio for collision/damage.

**Key logic:**
- Checks FUN_004c7bd0() for collision severity
- Collision: audio 0x34. No collision (SessionType 7): audio 0xc4

**Calls:** FUN_004c7bd0, FUN_004144d0, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041a200 — AI Pit Strategy State

Source: ai_db/pit_strategy.cpp. Checks pit state and triggers audio.

**Key logic:**
- If not in pit (param_1+0x3450 != 1): audio 0x2a
- If setupStrategy (+0x4040) == 2 or -1: audio 0x34. Else: 0x2a

**Calls:** FUN_00418a20, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041a2b0 — AI Session Phase Change

Source: ai_db/session_phase.cpp. Handles session phase transitions with audio.

**Key logic:**
- Session 5: audio 0x15/0x16 (phase count < 0xc or >=)
- Session 6/7: audio 0xb2, or 0xb3 if position==1
- If session 5: calls FUN_004198b0

**Calls:** FUN_004144d0, FUN_004144f0, FUN_00418560, FUN_004198b0

**Moddability:** hardcoded

---

## FUN_0041a3a0 — AI Formation Lap / Race Start

Source: ai_db/formation_start.cpp. Formation lap and race start audio.

**Key logic:**
- Session 7, RaceMode != 5: audio 0xb4/0xb5/0xb6 based on formationLapAction (1/2/3)
- Otherwise: audio 0x06

**Calls:** FUN_004144d0, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041a8c0 — AI Session Event Audio

Source: ai_db/session_event.cpp. Generic session event audio.

**Key logic:**
- Guard checks, emits audio 0x37 with all params -1

**Calls:** FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041aa10 — AI Session Phase Counter

Source: ai_db/phase_counter.cpp. Tracks phase count across 4 slots.

**Key logic:**
- Sets param_1+0xa44+param_2*4 = 1
- Counts active slots: if count < 3 audio 0x5f/0x61/0x63/0x65 per slot, if >= 3 audio 0x69

**Calls:** FUN_004144d0, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_00424750 — AI Difficulty Scalar (Low Range)

Source: ai_db. Returns difficulty-scaled float for low-difficulty AI.

**Key logic:**
- If AIDifficultySlider < 0x5f (95): linear interpolation
- If >= 0x5f: returns constant

**Globals:** DAT_007d01a0, _DAT_0059e860, _DAT_0059e7f8, _DAT_0059e7fc, _DAT_0059e43c

**Moddability:** configurable

---

## FUN_00424790 — AI Driver Struct Init

Source: ai_db. Initializes AI driver struct with defaults, name matching, difficulty scaling.

**Key logic:**
- Zeroes/resets fields, sets FLOAT_MAX, loops init arrays
- If param_2 != 0: full init with vehicle name matching, grid position, difficulty
- Finds matching vehicle by name comparison
- Initializes 7 callout slots from FUN_004a5c10
- Calls FUN_00424ac0 for difficulty scaling

**Calls:** FUN_0042ae00, FUN_00424080, FUN_00424cd0, FUN_00429960, FUN_004a5c10, FUN_00424ac0, FUN_004f1510

**Moddability:** hookable

---

## FUN_00424ac0 — AI Difficulty Interpolation

Source: ai_db. Piecewise linear interpolation of AI performance.

**Key logic:**
- If AIDifficultySlider < 0x65: lerps low→mid
- If >= 0x65: lerps mid→high

**Globals:** DAT_007d01a0, _DAT_005ea3dc, _DAT_005ea3e0, _DAT_005ea3e4, _DAT_0059e474, _DAT_0059e448

**Moddability:** configurable

---

## FUN_00424c80 — AI Ring Buffer Field Init

Source: ai_db. Sets field using ring-buffer lookup and difficulty offset.

**Key logic:**
- Reads RingBufferCounter, increments
- Computes formula: (ringBufferTable[counter] * _DAT_0059e868 + _DAT_0059e868) - AIDifficultySlider * _DAT_0059e444 * _DAT_0059e84c
- Stores at param_1 + 0x4448

**Globals:** DAT_008aae70, DAT_008aae74, DAT_007d01a0

**Moddability:** configurable

---

## FUN_00424cd0 — AI Command/Message Queue Dispatcher

Source: ai_driver.cpp. Dispatches commands to AI driver and maintains command queue.

**Key logic:**
- Branch on param_2: 4=valid lap, 5=clear pit flag, 1=store timestamp, 0xf=pit state logic
- Queue management at +0x112a (array), +0x112c (count), +0x112b (capacity)
- Appends (param_2, param_3) pair, dedup check
- Calls FUN_00429ee0 to process

**Calls:** FUN_004a46f0, FUN_0042adb0, FUN_004c6d90, FUN_004a5c80, FUN_00429ee0

**Moddability:** hookable

---

## FUN_00424e70 — AI Main Update / Race Phase State Machine

Source: ai_controller.cpp. Central AI tick; dispatches behavior based on session phase.

**Key logic:**
- Gate: param_1[0xcb2] must be 0 or 1 (AI active)
- Pit exit block: heading computation, lap push logic, ability update
- Behavior state machine at +0x1144: states 4/5 (pit window), 0/6 (follow), 1 (pursuit), 3 (pit entry), 2 (pit in), 7 (overtake)
- Race phase transition block: detects phase change, decrements timer
- Phase 4 (parked): computes steering with random offset

**Calls:** FUN_00426430, FUN_0042a180, FUN_00429470, FUN_0042ae00, FUN_004a4110, FUN_00425670, FUN_004258c0, FUN_0042a7d0, FUN_00425920, FUN_004270a0, FUN_00426100, FUN_00426cf0, FUN_00426330, FUN_00424c80, FUN_0042adb0

**Moddability:** hookable

---

## FUN_00425920 — AI Racing Line / Overtaking Gap

Source: ai_racing_line.cpp. Computes follow-target speed, distance-to-apex, overtaking gap.

**Key logic:**
- Reads AIFollowTarget (+0x4438)
- Chases forward chain up to 20 hops, builds speed/distance profile at +0x43a4
- Collision avoidance: lateral distance, dot-product check, bounding box
- Gap-follow: chain-scan closing speeds, set overtake target
- Overtake-abort: if overlap out of bounds, clear flags

**Calls:** FUN_0042a780, FUN_004e87e0, FUN_0042ae00

**Moddability:** hookable

---

## FUN_00426cf0 — AI Steering Correction / Stability

Source: ai_stability.cpp. Computes final steering angle and lateral tracking.

**Key logic:**
- Damper flag: multiply steering by random factor
- Lateral offset compensation at high speed
- Blend track-relative speeds, normalize steering
- Race time cutoff: compare speed vs target, adjust follow
- Pit limiter clamp

**Calls:** FUN_00424750, FUN_004e8780, FUN_004e88b0, FUN_0042b0e0

**Moddability:** configurable

---

## FUN_00429470 — AI Ability / Lap Ratio / Push Lap Update

Source: ai_ability.cpp. Updates AI current lap ratio, push-lap logic, pit entry triggers.

**Key logic:**
- Branch on vehicle type via FUN_004d1cf0
- Lap type: ability-based lap ratio, LiveLapRatio = min(QualiAbility + delta, RaceAbility + delta)
- Push lap: random chance based on RaceAbility
- Pit check: tire-lap counter vs current lap, calls FUN_0042a110
- Compound mismatch: compare current vs intended, call pit if mismatch
- Tire wear threshold check

**Calls:** FUN_004d1cf0, FUN_0042a3d0, FUN_004f1890, FUN_0042a6f0, FUN_0042a110, FUN_004f1630, FUN_004a4830, FUN_00429eb0

**Moddability:** configurable

---

## FUN_00429eb0 — Race-Phase Pit Entry Trigger

Source: ai_pit_logic.cpp. Triggers pit entry when race phase is paddock.

**Key logic:**
- Calls FUN_0042ad20 for random proximity check
- If result < 1 AND +0x4550==0 AND RacePhase==5: calls FUN_0042a110

**Calls:** FUN_0042ad20, FUN_0042a110

**Moddability:** hookable

---

## FUN_00429ee0 — Command Queue Response Handler

Source: ai_controller.cpp. Processes queued commands by RacePhase.

**Key logic:**
- RacePhase 3: enter pits, clear flag, call light sequence
- Queue commands: 0 (exit pit), 5 (formation lap), 4 (pit entry), 0xe (safety car)
- RacePhase 4: resume timer, set flag

**Calls:** FUN_0042adb0, FUN_0042ac90, FUN_0042acd0, FUN_0042aca0

**Moddability:** hookable

---

## FUN_0042a110 — Force Pit Exit / Advance State

Source: ai_pit_logic.cpp. Forces AI to exit pit lane or advance phase.

**Key logic:**
- SessionType 7: check SeasonPoints vs total laps - 1
- If not last: call advance. If last: skip
- Non-race: always advance

**Calls:** FUN_004a5c40, FUN_004a5e40, FUN_0042ac70

**Moddability:** hookable

---

## FUN_0042a180 — AI Push Lap / Closing Gap

Source: ai_push_lap.cpp. Manages push-lap ratio and aggression modifier.

**Key logic:**
- Early return if vehicle state != 1
- Non-race: LiveLapRatio = min(10, lap_index) * 0.01 + current
- Aggression modifier +0x1160 = max(0.5, 1.0 - TrackAggression * 0.1)
- Push active check at +0x1153
- Pit check: tire-lap counter <= current lap → call pit
- Compound mismatch → call pit. Tire wear threshold → call pit

**Calls:** FUN_0042a110, FUN_004f1630, FUN_004a4830

**Moddability:** configurable

---

## FUN_0042a3d0 — Pit Stop Decision & Tire Compound

Source: ai_pit_strategy.cpp. Decides pit timing and tire compound.

**Key logic:**
- Read planned stops at +0x1178 bitmask
- Compute remaining laps to next stop
- DRS override: randomize pit target to current lap
- Pit-blocking check via FUN_0042aee0
- Tire compound: aggression < 0.01→hard(4), 0.01-0.1→medium(5), >=0.1→soft(6)
- Scan 7 slots for matching compound, adjust gear ratios

**Calls:** FUN_0042aee0, FUN_004c6d90, FUN_004bc060, FUN_004a5bd0, FUN_004f1890, FUN_0042a6f0, FUN_004a5750, FUN_004a57a0

**Moddability:** configurable

---

## FUN_0042a6f0 — Post-Pit Cleanup / Exit

Source: ai_pit_logic.cpp. Runs after pit stop completes.

**Key logic:**
- Calls FUN_004bd760 for pit exit animation
- If +0x4584 clear: increment stint +0x45e0
- Session 7 race: clear +0x4534 pit crew timer
- Set +0x447c pit-exit timestamp to current time + 0.5s

**Calls:** FUN_004bd760

**Moddability:** hookable

---

## FUN_0042a7d0 — Opponent Proximity Scan & Team Recognition

Source: ai_awareness.cpp. Scans vehicles, builds sorted proximity list.

**Key logic:**
- Initialize 5 proximity rank slots (distance INF, team-match 0, owner -1)
- Get primary target from FUN_004a4710
- If no primary: iterate all vehicles, compute 2D distance
- Overtaking detection: cross product with heading → steering direction
- Team recognition: compare TeamID against 5 team slots
- Assign: set aggression, owner, team ID

**Calls:** FUN_004a4710

**Moddability:** hookable

---

## FUN_0042ae60 — Server Session Gate Check

Source: ai_network.cpp. Validates AI can operate in server mode.

**Key logic:**
- If SessionType != 5: pass through
- If AISpeedDelta != 1 AND engine state == 2: block AI
- Otherwise: pass

**Moddability:** hookable

---

## FUN_0042aee0 — Pit Stop Blocking Condition

Source: ai_pit_strategy.cpp. Checks if pit stop is blocked.

**Key logic:**
- Non-race: return bit 3 of +0x1167
- Race: return 0 only if lap < total AND RacePhase != 8 AND DRS clear AND (ERS disabled OR enabled)

**Moddability:** hookable

---

## FUN_0042af70 — Overtaking / Passing Decision

Source: ai_overtake.cpp. Compares two AI drivers for overtaking.

**Key logic:**
- If network locked: return 0
- Push counter sync: param_1[0x1143] = max(param_1[0x1143], param_2[0x1131])
- Race mode: compare SeasonPoints, driver numbers, DRS/ERS conditions
- Decision: set +0x117f target, steering direction (2=right, else=left)
- Server mode: FUN_0042ae60 check
- Practice mode: compare speeds

**Calls:** FUN_004f1c20, FUN_0042ae60

**Moddability:** hookable

---

## FUN_0042b0e0 — AI Steering & Racing Line Correction

Source: ai_steering.cpp. Computes steering corrections for racing line and pit merge.

**Key logic:**
- RacePhase 3: scans vehicles for match, random offset, steering correction
- Push lap counter capped at 0.9f
- RacePhase 1 or 3 with threshold: computes delta from vehicle position
- If recon pit open: finds nearest waypoint, computes steering angle
- Pit-out merge: triggers when race time + offset exceeds current time

**Calls:** (various internal calls)

**Moddability:** configurable

---

## FUN_0042caa0 — AI Lateral Force Computation

Source: ai_physics.cpp. Computes lateral steering forces between vehicle pairs.

**Key logic:**
- Phase 1: build per-vehicle descriptor with position, velocity, speed
- Phase 2: for each pair, compute distance to predicted arc
- Accumulate scaled repulsion/attraction force
- Writes X force to +0x3a64, Z force to +0x3a6c

**Globals:** DAT_005c329c, DAT_007c54f0

**Moddability:** configurable

---

## FUN_004336f0 — Load AI Driver Names from Config

Source: ai_config.cpp. Copies driver names from config to vehicle name buffers.

**Key logic:**
- Validates param_2 index in [0, VehicleCount)
- Gets default name, iterates vehicles
- AI (+0x32c8==0): lookup config name via FUN_004339e0. If found, copy to +0x4794
- Human: copy default name

**Calls:** FUN_00433890, FUN_004339e0

**Moddability:** hookable

---

## FUN_00434d60 — Steering Interpolation & Camera Follow

Source: ai_steering.cpp. Interpolates AI steering toward waypoint with smooth blending.

**Key logic:**
- Gets target waypoint index from +0x2c
- Computes interpolation factor lerp ratio along segment
- If target in pit: uses direct waypoint position
- If on track: blends between waypoints
- Adjusts camera height with smoothing

**Calls:** FUN_00456060, (vtable render)

**Moddability:** configurable

---

## FUN_004beb10 — AI Overtake / Collision Detection Loop

Source: ai_db. Core AI overtaking logic — iterates vehicles, checks overlap, triggers position swap.

**Key logic:**
- Initializes from globals, checks formation lap
- Accumulates param_1[0xd5] += param_1[0xd4]
- Main vehicle loop: updates position delta, checks distance via FUN_004bea10
- Collision types: 0=clean overtake (increment, call FUN_004bf390), 1=contact (sound + severity), 2=heavy contact
- Calls FUN_004bf4f0 if no collisions

**Calls:** FUN_004bf0a0, FUN_004bea10, FUN_004bef60, FUN_004bf390, FUN_004b33b0, FUN_004bf4f0

**Moddability:** configurable

---

## FUN_004bef60 — AI Collision / Out-of-Bounds Check

Source: ai_db. Determines collision type for a vehicle.

**Key logic:**
- If not race session: returns 0
- Checks 4 slot active flags at +0x834
- If vehicle state == 2: returns 2 (disabled)
- If EngineWearMode==3: position rank check
- Computes left/right force factors, stores in ring buffer

**Calls:** FUN_0042aeb0

**Moddability:** configurable

---

## FUN_004bf0a0 — AI Behavior Initialization / Tick

Source: ai_db. Initializes AI state arrays, computes gaps and positions.

**Key logic:**
- Stores current time, resolves track data
- Switch on EngineWearMode for initial gap
- Zeroes local float array (0x68 elements)
- Main vehicle loop: skips inactive, computes distance, tracks max gap
- Stores time/gap to each vehicle
- Calls FUN_004bf390 for re-sort

**Calls:** FUN_004ba140, FUN_004be760, FUN_004be9e0, FUN_004bea10, FUN_0042ae90, FUN_004bf390

**Moddability:** configurable

---

## FUN_004bf390 — AI Driver Sorting / Priority

Source: ai_db. Bubble-sort-like algorithm for driver ordering.

**Key logic:**
- Iterates VehicleCount times
- Race: compares +0x403c rank and +0x4098 time
- Non-race: compares +0x409c gap
- Calls FUN_004bc2f0 to swap positions

**Globals:** DAT_007c56a4, DAT_005c329c, DAT_0059e440

**Calls:** FUN_004bc2f0

**Moddability:** hookable

---

## FUN_004bf4f0 — AI Tick Update / Ring Buffer Reset

Source: ai_db. Updates vehicle time/gap and resets ring buffer.

**Key logic:**
- Sets DAT_008acfa0 = 1
- Iterates vehicles: compute time from gap + offset, store to vehicle
- Resets ring buffer pointers to initial state

**Globals:** DAT_008acfa0, DAT_005c329c, DAT_0059e440, DAT_008acf90

**Calls:** FUN_004bf390

**Moddability:** hardcoded

---

## FUN_004bfd90 — AI Driver Count Setup

Source: ai_db. Determines number of AI drivers, loads names, sets up grid.

**Key logic:**
- If VehicleCount < 1: skip
- If multiplayer: name list from DAT_007ce64c
- RaceMode 1: random count (3-5) or single driver
- Otherwise: match names via FUN_004bf790, register vehicles

**Calls:** FUN_004bf630, FUN_0042bc10, FUN_004b3c60, FUN_0042bc80, FUN_004bf790, FUN_004ef5a0, FUN_004bfd40, FUN_004c78f0, FUN_004c6960, FUN_004c3f80

**Moddability:** configurable

---

## FUN_004339e0 — Look Up Vehicle Config Entry

Source: config_manager.cpp. Searches linked list for matching session type config.

**Key logic:**
- If dirty flag unset: refresh config via FUN_00432e70
- Gets config source pointer
- Determines session type code, walks linked list for category/sub-name match
- Returns best match display name

**Calls:** FUN_00432e70, FUN_00432e50

**Moddability:** hookable

---

## FUN_00433b60 — Add Vehicle Config Entry to Linked List

Source: config_manager.cpp. Adds config entry node, deduplicates.

**Key logic:**
- If param_3==0: resolves session type
- Walks linked list for duplicate
- If duplicate and not allowed: returns 1
- Otherwise allocates 0x1c-byte node, links at tail, increments count

**Calls:** FUN_004326a0, FUN_00566650, FUN_00432cc0, FUN_004330d0

**Moddability:** hookable

---

## FUN_004a4710 — Find Nearest Vehicle

Source: game_logic. Scans VehiclePtrArray for closest vehicle by ability distance.

**Key logic:**
- Initializes bestDist = 99999.0, bestVehicle = 0
- Iterates vehicle pointer array
- Calls FUN_0042add0 + FUN_00426cc0 for distance
- Returns closest vehicle pointer

**Calls:** FUN_0042add0, FUN_00426cc0

**Moddability:** no — search utility

---

## FUN_00418560 — InsertDriverTableEntry

Source: ai_database. Inserts driver data record into sorted table (20 entries max, stride 0x20).

**Key logic:**
- Validates param_2[0] != -1 and passes FUN_00418b90 check
- Reads driver table base from param_1+0x864
- Iterates 0x14 (20) entries, each stride 8 floats (0x20 bytes)
- Compares entry +0x00 (time) against param_2[2] (reference time)
- Tracks max entry index by +0x14 (sort key)
- If insertion point found: shifts entries right (by memmove via FUN_004145c0)
- Writes param_2 data via FUN_004145c0

**Calls:** FUN_00418b90, FUN_00418b70, FUN_004145c0

**Moddability:** hardcoded 20-entry limit, stride 0x20

---

## FUN_0041e890 — AI/Entrant Lookup by Name

Source: ai_entrant.cpp. Searches active session entries (up to 0x66=102) for matching driver name. Uses FUN_004c2850/FUN_004c13a0 to iterate. Returns +0x198 value (score/laptime) of first match, or 0.

**Key logic:**
- Iterates up to 102 session entries
- Compares name string via FUN_00588410
- On match: returns +0x198 value
- Returns 0 if no match

**Calls:** FUN_004c2850, FUN_004c13a0, FUN_00588410

---

## FUN_004b51e0 — Driver Name/Team Copy

Source: ai_driver.cpp. Copies driver name from param_2+0x4620 and extracts team name from path at param_2+0x4714 (finds last backslash). Calls FUN_004b4f70 for setup.

**Struct offsets:** +0x4620 (DriverName), +0x4714 (VehicleDescription/path)

**Calls:** FUN_004b4f70, _strncpy

---

## FUN_004bfa00 — AI Path/Performance Function

Source: ai_perf.cpp. Large AI performance evaluation function. Processes vehicle properties to compute AI behavior parameters. Uses linked list iteration and vehicle data.

---

## FUN_004270a0 — AI Steering / Racing Line Controller

Source: ai_racing_line.cpp. Computes steering output, brake force, and per-rival driving state for one AI vehicle. The core path-following and overtaking logic.

**Key logic:**
- Input gate: reads param_1[0x10d5] (current vehicle ptr) and param_1[0x115b] (flag byte)
- Steering limits: initializes param_1[0x1103] from track-speed and speed-based clamping (param_1[0x1105]/[0x1106] left/right limits)
- Brake modifier: `local_58` = ratio of min rival speed to (min+max); scales steering when speed difference exists
- Main loop (0..4): iterates 5 path/rival candidates at struct stride +0x11 per candidate
  - Candidate struct base at param_1[0x105d + i*0x11]:
    - +0x0: vehicle pointer (offset +0x34e0)
    - +0x3: lateral distance ahead
    - +0xc: longitudinal gap
    - +0xd: threshold check (< _DAT_0059e95c → process candidate)
    - +0xe: path segment index from FUN_00403aa0/FUN_004039c0
    - +0x10: index offset for state machine
  - Computes cost ratio `fVar2` = lateral_ahead / longitudinal_gap, clamped, sorted into 5-slot array (local_14[0..4])
- For each sorted rival (in priority order):
  - State machine at `param_1[(rivalIdx + 0x263) * 7]`:
    - 0: normal — pending overtake/block decision
    - 1: passing right (steer +)
    - 2: passing left (steer -)
    - 3: side-by-side right
    - 4: side-by-side left
    - 5: fall back / yield position
    - 7: defend right
    - 8: defend left
    - 0x10: alongside (blocked)
  - Brake computation: left brake (local_3c) / right brake (local_68) computed via sqrt(FUN_004fae70) of speed-based target + penalty adjustments
  - Lateral gap (local_64): angular offset to rival; if within threshold, maintains speed; if outside, adjusts steering toward pass gap
  - Overtake threshold chain: checks param_1[0x1110] (speed-related), lap count comparison at vehicle+0x48a4/0x48a8
  - Collision avoidance: if gap below threshold, sets state 5 (fall back); checks lateral offset sign for left/right pass decision
  - Brake accumulation: param_1[0x1157] incremented each frame brakes active; param_1[0x115c]/[0x115d] hold per-side brake timers
  - Steering overwrite: when flag param_1[0x1152] set, uses raw param_1[0x1108] (no correction)
- Final output: param_1[0x1103] (steering), param_1[0x1102] (filtered/clamped steering copy), param_1+0x4579 (brake active flag cleared at top, set when braking)

**Globals (all DAT_0059xxxx — tuning constants):**
- `DAT_0059e440` — zero literal (0.0f)
- `DAT_0059e43c` — small epsilon (1.0f)
- `DAT_0059e450` — 0.5f halving factor
- `_DAT_0059e800` — 1.0f
- `_DAT_0059e7ec` — small threshold (0.1f?)

**Calls:** FUN_00403aa0 (path segment resolve), FUN_004039c0 (alt path resolve), FUN_00423ca0/FUN_00423db0/FUN_00423b10 (segment handling), FUN_0042a740 (set throttle), FUN_0042af70 (vehicle-facing state dispatch), FUN_004fae70 (sqrtf)

**Moddability:** configurable (all thresholds via DAT_0059xxxx globals)

## FUN_00455580 ? Keyboard Scancode-to-ASCII

Source: likely input.cpp. Maps DirectInput scan codes to ASCII characters.

**Key logic:**
- First table: maps 0x83-0xff to shifted ASCII values
- Second table: maps key positions 0x10-0x33 to letters A-Z (0x41-0x5a) etc.
- Shift modifier encoded in param_2 bits
- Returns unmapped byte if no match

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0040de60 ? AI Behavior State Machine

Source: likely aibehavior.cpp. AI character behavior FSM with timer and random transitions.

**Key logic:**
- State machines with states: 1 (initial), 2 (active), 3 (transition), 4 (done)
- Timer at param_1[0x27] decrements
- Sub-state actions: 2-0xc (load/save, animation, camera, audio, event, etc.)
- Random probability check via _rand() * _DAT_0059e6e0
- Calls thunk_FUN_00434860, FUN_0040d1b0 (save), FUN_0042bbd0 (load), FUN_0041c3e0-1c090 (menu screens)
- Special case 12: param_1[0] = 5 (state transition)

**Calls:** 12+ action functions

**Moddability:** hookable

<!-- target: docs/08-file-formats.md -->

## FUN_004ae9f0 � AI Difficulty Configuration per Race Mode

Source: Unknown. Configures AI opponent behavior parameters based on difficulty/race mode (0x1b10).

**Key logic:**
- Switches on param_1+0x1b10 (race mode/difficulty selector, cases 1-4)
- Each case sets ~20 state values (0/1/2) across the struct controlling AI aggression, skill, consistency
- Cases 3-4 call FUN_004b20d0 repeatedly with values 0-4 to configure AI behavior parameters
- Sets float parameters: 0.5 (0x3f000000), 0.6 (0x3f19999a), 0.3 (0x3e99999a), 0.4 (0x3ecccccd), 0.95 (0x3f866666)
- Final switch on DAT_005ec4ac: 0?diff 1, 1-2?diff 2, 3?diff 3

**Globals:**
- DAT_005ec4ac � AI difficulty selector (0-3)

**Calls:** FUN_0047f1f0 (timer/state setter), FUN_004646c0, FUN_004b20d0 (AI param), FUN_004b1de0

**Moddability:** configurable (DAT_005ec4ac controls difficulty branch)

<!-- target: docs/10-vehicle-physics.md -->

## FUN_004faf60 � AI Opponent Relative Positioning

Source: Unknown. Computes distances and angles to nearby opponents via linked list for AI steering decisions.

**Key logic:**
- Reads threshold from DAT_005ea2cc (AI update gating)
- Computes relative position vector (param_1+0xa4/a8/ac) to linked opponent (offset +0x110)
- Normalizes direction vector with reciprocal sqrt
- Computes yaw angle via atan2 into +0xb8
- Follows linked list (+0x110) for up to 4 opponents
- For each: computes angle from direction dot product
- Uses FUN_005894a0 random for randomization of AI behavior
- Writes 4 float results to +0xbc

**Calls:** FUN_005894a0 (RNG), FUN_00588570

**Moddability:** hardcoded (DAT_005ea2cc gates update rate)

<!-- target: docs/17-physics-collision.md -->

## FUN_004af220 � Race Mode Parameter Configurator

Source: Unknown. Sets difficulty/gameplay parameters based on race mode selector.

**Key logic:**
- Switches on param_1+0x1b34 (mode 1-4)
- Sets value at +0xd98: 0xc (12), 0xe (14), or 0x10 (16) depending on mode
- Clamps between min (+0xda0) and max (+0xda4) bounds
- Sets flag at +0x1170 (0-3) based on mode
- Secondary clamp at +0x1178 (min) and +0x117c (max)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004ef7c0 — AI Vehicle Path Position Tracking

Source: unknown. Updates AI vehicle's path tracking offset based on current position and target direction.

**Key logic:**
- Copies target position from param_3 to param_1+0x34e0/0x34e4/0x34e8 (same AI state struct as FUN_00425670)
- Calls FUN_00566e40 and FUN_004ef680 to get orientation vectors
- Transforms target offset vector using orientation matrix components (param_1+0x34b0-0x34d0)
- Accumulates error into param_1+0x34d4/0x34d8/0x34dc (integrated position offset)
- Sets param_1+0x3a9c = 0 (path tracking flag)
- Calls FUN_004e9bd0 (update path state)
- If param_1+0x32bc == 0: calls FUN_0043e4b0 with accumulated offset and position for collision/terrain query

**Struct offsets (param_1 as AI vehicle state, shared with FUN_00425670):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x32bc | pathValid | path validity flag |
| +0x34b0-0x34d0 | orientMatrix | orientation matrix rows (3x4 floats) |
| +0x34d4 | offsetX | accumulated path offset X |
| +0x34d8 | offsetY | accumulated path offset Y |
| +0x34dc | offsetZ | accumulated path offset Z |
| +0x34e0 | targetPosX | target position X |
| +0x34e4 | targetPosY | target position Y |
| +0x34e8 | targetPosZ | target position Z |
| +0x3a9c | trackingFlag | path tracking flag (reset to 0) |

**Calls:** FUN_00566e40 (get orientation), FUN_004ef680 (get transform), FUN_004e9bd0 (update path), FUN_0043e4b0 (collision/terrain query)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004144f0 — Driver Data Table Lookup and Time Conversion

Source: unknown | Confidence: high (game_logic — AI/driver data)
Initializes param_1 fields from params and driver data table (DAT_005bf9a0). Converts float time via __ftol and scales.

**Key logic:**
- param_1[4] = param_3; param_1[6] = param_5
- *param_1 = param_2; param_1[5] = param_4; param_1[7] = param_6
- If param_6 == -1: param_1[7] = *(DAT_005bf9a0 + param_2 * 0x14) — driver data table lookup
- If param_8 == _DAT_0059e7f0 (sentinel): param_8 = *(DAT_005bf9a4 + param_2 * 0x14)
- Converts param_8 via __ftol, scales by _DAT_0059e7e8
- param_1[2] = (int)(float)__ftol_result * _DAT_0059e7e8
- If param_8 == _DAT_0059e670: param_1[3] = -0x40800000 (special flag)
- Else: param_1[3] = (int)(scaled_float + param_8 + _DAT_0059e7e8)

**Globals:**
- `DAT_005bf9a0` (DriverDataTable) — driver data at stride 0x14
- `DAT_005bf9a4` (DriverDataTable + 4) — second field per entry
- `_DAT_0059e7f0` — sentinel value (use default from table)
- `_DAT_0059e7e8` — time scaling constant
- `_DAT_0059e670` — sentinel flag constant

**Calls:** __ftol (MSVC CRT float-to-int)

**Used by system:** docs/02-ai-system.md — driver data initialization with time handling

**Moddability:** configurable (reads from driver data table, mods can edit .rcd)

<!-- target: docs/02-ai-system.md -->

## FUN_00418a60 — Driver Data Range Check Loop (20 entries)

Source: unknown | Confidence: high (game_logic — AI/driver)
Checks a block of 20 entries at param_1+0x864 (stride 0x20 = 32 bytes) and dispatches FUN_004144d0 on each valid entry.

**Key logic:**
- If *(param_1 + 0xaf4) != NULL (vtable object):
  - Calls vtable[8/4] method (query)
  - If query returns non-zero AND param_1+0xaec in range (0, 0x123): calls vtable[0xc/4] method
- Loop 20 times (iVar1 = 0x14 = 20):
  - piVar2 starts at param_1 + 0x864, stride = 8 ints (0x20 bytes)
  - If *piVar2 in range (0, 0x123): calls FUN_004144d0() (random init / text output, per docs/02)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x864 | DriverDataArray | int[20][8] | 20 entries × 8 ints |
| +0xaec | EntryCount | int | Range check upper bound 0x123 |
| +0xaf4 | VtablePtr | int* | Virtual method object |

**Calls:** FUN_004144d0 (random/text init, per docs/02)

**Used by system:** docs/02-ai-system.md — driver data validation and initialization

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a5d10 -- AI State Machine with Mode Dispatch

Source: unknown | Confidence: medium
Update AI state based on param_1[0x61] mode and param_2 input.

**Key logic:**
- Compares param_2+8 byte with current mode at param_1[0x61]; if changed, calls FUN_0041a200
- Sets param_1[0x62] from param_2+4
- If game mode 2 or 3 (championship): dispatches FUN_004a5f20 (mode 0) or FUN_004a5ea0 (mode 2)
- Mode 0: calls FUN_004a3440 if flag set
- Modes 1-2: calls FUN_004a6db0, dispatches FUN_004a3390, calls FUN_004d1100 and FUN_004a3320

**Calls:** FUN_0041a200, FUN_004a5f20, FUN_004a5ea0, FUN_004a55e0, FUN_004a3440, FUN_004a6db0, FUN_004a3390, FUN_004d1100, FUN_004a3320

**Used by system:** docs/02-ai-system.md -- AI state machine

<!-- target: docs/01-engine-architecture.md -->

## FUN_004C9BA0 — SortComparator_SpeedSum

Source: ai_race.cpp. Sort comparator for AI driver ordering. Compares two drivers by sum of two speed/performance fields at offsets 1848 and 1856 from their respective structs.

**Key logic:**
- Reads *(int*)a1 to get pointer to first driver struct
- Reads *(int*)a2 to get pointer to second driver struct
- Computes sum of floats at offsets +0x738 (1848) and +0x740 (1856) for each driver
- Returns 1 if first > second, -1 if first < second, 0 if equal
- Used by qsort for ordering drivers in race logic

**Struct access (through indirection):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x738 | TopSpeed_or_Performance | float |
| +0x740 | SpeedMaintenance_or_Other | float |

**Calls:** none (pure comparator)

**Moddability:** `hardcoded`

<!-- target: docs/01-engine-architecture.md -->

## FUN_0047ab35 — AIOvertakeGapCalc

Source: ai_vehicle.cpp. Calculates AI overtake distance/gap timing between vehicles.

**Key logic:**
- a4[60] = a1 (stores target position/offset)
- a4[64] = vtable(a2+24)(a4) − 2*a4[62] − a4[3] (compute available space minus margins)
- If sub_486460(3) returns true (overtaking aggression flag): a4[70] = 20 (threshold); else a4[70] = a3 (parameter threshold)
- a4[69] = vtable(a4[0]+36)(a4) − a4[70] (compute distance to target minus threshold)
- a4[69] -= vtable(a4[0]+28)(a4) (subtract vehicle length/braking distance)
- If result < 0: a4[69] = a3 (clamp to default)

**Struct offsets (a4 = vehicle struct):**
| Offset (dword index) | Field | Notes |
|----------------------|-------|-------|
| [3] | MarginBase | base margin for position calc |
| [60] | OvertakeTargetPos | target overtake position |
| [62] | OvertakeMarginExtra | additional margin factor |
| [64] | OvertakeAvailable | computed available space |
| [69] | OvertakeGapResult | resulting gap/time to overtake |
| [70] | OvertakeThreshold | aggression threshold (20 if aggressive) |

**Calls:** sub_486460 (check flag/ability), vtable[+24] (vehicle method: get space), vtable[+28] (vehicle method: get length), vtable[+36] (vehicle method: get distance)

**Moddability:** `hardcoded` — aggression threshold hardcoded to 20

<!-- target: docs/01-engine-architecture.md -->

## FUN_00447160 — Vehicle Active / AI Eligibility Check

Source: unknown. Determines whether a vehicle is in a valid state for AI processing. Checks engine lifetime, RPM, activity flags, and recent motion.

**Key logic:**
- **Guard 1:** checks `EffectiveLifetimeAtSpawn > 0` (+0x1db4 as double, > ZeroSentinel ~0.0)
  - If invalid (NaN or <= 0): returns 0 (inactive)
- **Guard 2:** checks `RPM_current > 0` (+0x19c as double, > ZeroSentinel)
  - If invalid: returns 0 (engine not running / invalid)
- **Guard 3:** checks byte at +0x1c59 (vehicle active/live flag)
  - If flag is 0: skips to fallthrough return 0
  - If flag != 0 and byte at +0x1d0c (subsystem flag) != 0: returns 1 immediately (fully active)
- **Fallthrough path:** reads pointer at +0x1f00 (some vehicle subsystem state), checks byte at +0x344c
  - If subsystem flag is set: reads pointer at +0x15f0 (wheel/suspension struct)
    - Computes squared velocity: `vx^2 + vy^2 + vz^2` from offsets +0x64, +0x6c, +0x74
    - If squared velocity < _DAT_0059e420 (BaseDoubleConstant = 1.0, i.e. speed < 1.0): returns 1 (vehicle stationary but valid)
  - Otherwise returns 0

**Struct offsets (param_1 — vehicle struct):**
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x19c | double | RPM_current | current engine RPM (or IntegrationFlag) |
| +0x1c59 | byte | vehicle_active_flag | vehicle alive/live flag |
| +0x1d0c | byte | subsystem_active_flag | subsystem-specific active flag |
| +0x15f0 | ptr | wheel_struct_ptr | pointer to wheel/suspension state (velocity read at +0x64/6c/74) |
| +0x1db4 | double | EffectiveLifetimeAtSpawn | engine lifetime parameter (docs/13) |
| +0x1f00 | ptr | subsystem_ptr | pointer to subsystem state struct |
| +0x344c | byte | subsystem_internal_flag | flag within subsystem struct |

**Globals:**
- `_DAT_0059e430` (ZeroSentinel ~0.0) — sentinel used in MSVC CRT NaN-safe >0 comparison
- `_DAT_0059e420` (BaseDoubleConstant = 1.0) — velocity^2 threshold for "stopped but valid"

**Calls:** none (pure comparison/branch logic)

**Used by system:** docs/20-math-utilities.md (physics vehicle state)

**Moddability:** `hardcoded` — threshold constants baked into global physics pool

<!-- target: docs/20-math-utilities.md -->

