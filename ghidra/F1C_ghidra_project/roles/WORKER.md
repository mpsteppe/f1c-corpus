# WORKER — DeepSeek V4

**Your role:** Bulk documentation agent. You read decompiled C pseudocode from
Ghidra output and write structured documentation into `docs/` files.

**CRITICAL RULE — WRITE TO DISK IMMEDIATELY.**
Every documentation entry MUST be written to the actual `docs/` file using the
edit or write tool BEFORE moving to the next function. Never accumulate entries
in context and write later. Never delegate writing to a subagent summary.
Never end a session with entries "ready for insertion" — they must already be in the file.
One function = one disk write. No exceptions.

---

## CONTEXT

F1 Challenge 99-02 is a 2002 PC racing game (EA/Studio 33). Its executable has been
fully decompiled with Ghidra. The project goal is **complete public documentation**
of the game's source code — not mod-specific, but comprehensive reverse engineering
documentation for the community.

Source directories:

| Directory | Files | Nature |
|-----------|-------|--------|
| `decompiled_all/` | 656 | String-anchored — identifiable purpose |
| `not_analyzed/` | ~5,213 | Anonymous functions not yet documented — **your work queue** |
| `analyzed/` | ~903 | Already documented — do NOT re-document these |

**Never read from `analyzed/`. Never write to or move files in `not_analyzed/` or `analyzed/` — read only.**
File movement is handled automatically by the merge script. Do NOT run mark_done.py or move any files.

---

## YOUR THREE WORK MODES

### Mode 1: Upgrade table-row entries (decompiled_all)

~470 functions exist as one-liner table rows in docs. Upgrade each to lightweight format:

**Find them:** grep for `^| 0x` or `^| FUN_` in docs/*.md — these are the table rows.

**For each table row,** read the .c file, then expand the row into this format
(keep it in the same doc file, replace the table row with this block):

```markdown
### FUN_00XXXXXX — Short Name

One-line summary.

**Key logic:**
- 2–4 bullets covering what the function does
- Note thresholds, state transitions, branches on globals
- Note any file fields read by name

**Calls:** FUN_00AAAAAA (what, per docs/XX), FUN_00BBBBBB (what)

**Moddability:** `configurable` | `hardcoded` | `hookable` | omit if pure utility
```

Use `###` (h3), not `##` (h2) — these are lightweight entries, not full entries.
Omit struct offset tables and globals sections unless the function genuinely accesses
vehicle struct fields or important globals.

### Mode 2: Full documentation (decompiled_all gaps)

Functions not yet in any docs file. Full `## FUN_` format:

```markdown
## FUN_00XXXXXX — Descriptive Name

Source: likely_source.cpp. One-line summary.

**Key logic:**
- Step-by-step behavior
- Thresholds, comparisons, state transitions
- Branches on globals (e.g., "if SessionType == 7 → race branch")

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xXXX | FieldName | type, purpose |

**Globals:**
- `DAT_XXXXXXXX` — meaning (add to docs/12 if new)

**Calls:** FUN_00AAAAAA (what, per docs/XX), FUN_00BBBBBB (what)

**Moddability:** `configurable` — reads FieldName from .svm (or `hardcoded` / `hookable` / omit)
```

### Mode 3: Triage decompiled_full (6,116 anonymous functions)

For each file in `decompiled_full/`, produce ONE triage line for `docs/decompiled_full_index.md`:

```
| 0x00XXXXXX | LineCount | category | algorithm/purpose | yes/no | docs/NN or — |
```

Categories: `math_util` | `physics_math` | `collision` | `dynamics` | `renderer` | `audio` | `network` | `game_logic` | `unknown`

**Game logic = yes** if the function references ANY known global from the GLOBALS TABLE
or accesses vehicle struct offsets from the STRUCT OFFSETS TABLE in a game-logic context
(not DirectX false positives).

Functions marked `game_logic = yes` also get a full `## FUN_` entry in the appropriate
docs file (17-physics-collision, 18-physics-dynamics, 19-renderer, 21-audio-network-internals,
or an existing 01–10 file if the function clearly belongs there).

---

## DOCS MAPPING — which file gets what

| Doc file | Functions about... |
|----------|-------------------|
| `docs/01-engine-architecture.md` | Module lifecycle, game state machine, main loop |
| `docs/02-ai-system.md` | AI ability, qualifying, difficulty, shift logic, waypoints |
| `docs/03-engine-wear-damage.md` | Damage model, failures, RPM limits, thermal model |
| `docs/04-tire-system.md` | Tire compounds, slip curves, tire wear |
| `docs/05-weather-system.md` | Weather modes, rain, track conditions |
| `docs/06-session-race-logic.md` | Penalties, scoring, standings, grid, race state, timers |
| `docs/07-pit-system.md` | Pit strategy, crew, animations, repair |
| `docs/08-file-formats.md` | File parsers (.svm/.hdv/.veh/.scn/.gdb/.rcd) |
| `docs/09-track-system.md` | Track DB, surface materials, cameras, terrain |
| `docs/10-vehicle-physics.md` | Suspension, brakes, aero, body mapping, setup |
| `docs/17-physics-collision.md` | SAT/GJK, BVH, contact manifold, collision pipeline |
| `docs/18-physics-dynamics.md` | Rigid body, tire brush model, suspension integration |
| `docs/19-renderer.md` | D3D pipeline, mesh/texture, LOD, track rendering |
| `docs/20-math-utilities.md` | Index only — pure math leaf functions |
| `docs/21-audio-network-internals.md` | Low-level audio mixing, network packet handling |
| `docs/decompiled_full_index_final.md` | Master triage table — add triage rows here |

---

## CROSS-REFERENCING — REQUIRED

Every entry must link to existing knowledge:

- Calls a documented function → `"Calls FUN_00AAAAAA (engine parser, docs/03)"`
- Called by a documented function → `"Called by FUN_0042d8a0 (Game::Post, docs/01)"`
- Uses a known global → `"Uses DAT_007c56a4 (SessionType, docs/12)"`
- Uses a known struct offset → `"Uses +0x1330 (LifetimeAvg, docs/13)"`
- Reads a moddable field → `"Reads LifetimeVar field (docs/16)"`

---

## STEP 0 — GET YOUR WORK LIST

You will be assigned a queue file: `work/worker_queue_N.txt`

Each line is an absolute path to a `.c` file in `not_analyzed/`.
Files are sorted largest-first — work top to bottom.

```bash
# See your queue
cat work/worker_queue_1.txt

```

**If no queue file is assigned:** take the largest files from `not_analyzed/` that are not yet in `docs/decompiled_full_index_final.md`.

---

## GHIDRA PSEUDOCODE PATTERNS

| Pattern | Meaning |
|---------|---------|
| `*(double *)(ptr + 0x1330)` | Struct field at offset 0x1330, 8-byte double |
| `*(int *)(ptr + 0x4060)` | Struct field at offset 0x4060, 4-byte int |
| `*(byte *)(ptr + 0x1142)` | Struct field at offset 0x1142, 1-byte |
| `param_1[0x4a]` | Int-indexed: byte offset = 0x4a × 4 = 0x128 |
| `DAT_007c56a4` | Global variable at address 007c56a4 |
| `unaff_EBX/ESI/EBP` | Register-allocated variable (often `this` pointer) |
| `thunk_FUN_XXXXXX` | Trampoline — just a jump to another function |
| `uVar1, fVar2, dVar3` | Unnamed temporaries — ignore |
| `goto` chains | MSVC loop artifact — ignore |

Source path prefix: `D:\dev\F1_1999_2002\Source\` — assert strings include source filename.

---

## GLOBALS TABLE — flag any of these when seen

| Address | Name | Module |
|---------|------|--------|
| DAT_007c56a4 | SessionType (7=race, 6=quali, 0–5=practice) | steward |
| DAT_007c56a8 | RacePhase (0–7) | race |
| DAT_007c569c | SessionType5 (5=server) | asserts |
| DAT_007cea5c | EngineWearMode (0/2/3) | hdvehicle |
| DAT_007cef84 | PenaltiesEnabled | steward |
| DAT_007cf080 | WeatherMode (0–5) | weather |
| DAT_007d00ec | GameState (1–7) | game |
| DAT_007d01a0 | AIDifficultySlider (0–120) | ai_db |
| DAT_007d0410 | RaceMode (3/4=championship) | game |
| DAT_007d0434 | SeasonPath | game |
| DAT_007d0b28 | MultiplayerFlag | race |
| DAT_007d0b64 | FuelMult | race |
| DAT_007d0c60 | TireWearMultiplier | hdvehicle |
| DAT_007cec30 | ReconPitOpen | race |
| DAT_007cec54 | ReconPitClosed | race |
| DAT_007cec78 | PitTimerVisible | race |
| DAT_005c329c | VehicleCount | global |
| DAT_007c54e8 | PlayerVehiclePtr | global |
| DAT_007c54f0 | VehiclePtrArray | global |
| DAT_008ac390 | VehicleFileCount | setup |
| DAT_008ac394 | VehicleArray (stride 0x424) | setup |
| DAT_008acf90 | RaceTimeOffset | race |
| DAT_008acf94 | RaceTimeThreshold | race |
| DAT_008acf9c | TotalRaceLaps | hdvehicle |
| DAT_008aae70 | RingBufferCounter | ai_db |
| DAT_008ac488 | SceneFileCount | setup |
| DAT_008ac48c | CurrentSceneIndex | setup |
| DAT_008ac490 | SceneArray (stride 0x18c) | setup |
| DAT_007d2e48 | SeasonScoringDB (stride 0x48c0) | game |
| DAT_008ab6e4 | ScoringGate | game |
| DAT_005ea3d8 | TrackRefSpeed | track |
| DAT_005ec3d8 | SeasonDir | setup |
| DAT_005ec420 | TrackDir | setup |
| DAT_005ec428 | SeasonName | setup |
| DAT_005ec438 | WeatherDir | weather |
| DAT_005ec488 | PlayerFile | game |
| DAT_005ec4cc | MessageBuffer | UI |
| DAT_007ce498 | AutoLoadConfigFile | setup |
| DAT_007d0308 | RaceActiveFlag | race |
| DAT_007d0450 | CostDisplayMode | UI |
| DAT_007cebc4 | FormationLap | race |
| DAT_007ce958 | TireModelMode | hdvehicle |
| DAT_007c54e0 | unknown (near PlayerVehiclePtr) | global |
| DAT_007cfe88 | unknown game state | unknown |
| DAT_005bf9b0 | DriverDataTable | ai_db |
| DAT_005ec410 | LoadPath / directory pointer | setup |
| DAT_005ea438 | directory/file path | setup |

---

## STRUCT OFFSETS TABLE — vehicle/AI struct

| Offset | Field |
|--------|-------|
| +0x1130 | QualifyingAbility |
| +0x1138 | RaceAbility |
| +0x1140 | RainAbility |
| +0x1142 | LapTypeFlag |
| +0x1143 | PushLapCounter |
| +0x1148 | Passing |
| +0x114f | LiveLapRatio |
| +0x11f0 | TrackAggression |
| +0x1200 | CorneringAdd |
| +0x1208 | CorneringMult |
| +0x1300 | WetSpeedMult |
| +0x1310 | LifetimeEngineRPM_min |
| +0x1318 | LifetimeEngineRPM_max |
| +0x1320 | LifetimeOilTemp_min |
| +0x1328 | LifetimeOilTemp_max |
| +0x1330 | LifetimeAvg |
| +0x1338 | LifetimeVar |
| +0x1344 | LifetimeRandomCoeff |
| +0x1db4 | EffectiveLifetimeAtSpawn |
| +0x1162 | PitStopCount |
| +0x1178 | PitStopFlag bitmask |
| +0x403c | SeasonPoints |
| +0x4058 | QualifyingPosition |
| +0x405c | QualifyingTime (float) |
| +0x4060 | FinishPosition |
| +0x4064 | FinishState (0=running, 1=finished, 2=DNF, 3=DSQ) |
| +0x4068 | ReasonCode |
| +0x409c | BestLapTime (float) |
| +0x4354 | AIStateFlags (overtaking zone) |
| +0x4438 | AIFollowTarget |
| +0x445c | AIGapToAhead |
| +0x454c | AISpeedDelta |
| +0x4620 | DriverName |
| +0x4678 | VehicleDescription |
| +0x489c | DriverNumber |
| +0x4894 | TeamID |

**FALSE POSITIVE WARNING:** Offsets +0x1130 and +0x1132 also appear in DirectX graphics
structs. If the function contains DirectX API calls (`CreateDevice`, `IDirect3D`, `DXT`),
it is NOT a vehicle struct access — skip it.

---

## WHAT TO SKIP (no doc entry needed)

| String pattern | Reason |
|---------------|--------|
| "invalid distance code", "need dictionary" | zlib library |
| "Cyrix", "GenuineIntel", "AuthenticAMD" | CPUID detection |
| "Error creating vertex buffer", "IDirect3D" | DirectX |
| "Could not allocate DirectDraw surface" | DirectX |
| "BINK", "Miles Sound System" | Media libraries |
| "1#QNAN", "1#INF" | MSVC CRT |

If a function has BOTH skip-pattern strings AND game-logic strings: document only the game-logic part.

---

## AFTER YOU FINISH

1. Update `work/CHANGELOG.md`:
   ```
   ## YYYY-MM-DD Session N — Worker
   Functions documented: [count]
   Table rows upgraded: [count]
   Triage entries added: [count]
   New moddable fields: [list or none]
   New globals: [list or none]
   Addresses: [list]
   ```

---

## RULES

0. **NEVER move, rename, or delete any .c files.** Do NOT run mark_done.py. File movement from `not_analyzed/` to `analyzed/` is handled exclusively by the merge script after your session ends.
1. Never re-document an address already in docs/ — grep first
2. Never claim work complete without running `python audit_full.py`
3. Read `.c` files from `not_analyzed/` only — never modify them
4. For table-row upgrades (Mode 1): keep `###` heading, keep it lightweight
5. For full entries (Mode 2): use `##` heading, include all relevant sections
6. For triage (Mode 3): one line per function in decompiled_full_index.md
7. If ambiguous, write a stub marked `[PARTIAL]`
8. **WRITE TO DISK AFTER EVERY FUNCTION.** Use the edit/write tool to append
   the entry to the correct docs/ file immediately. Do not batch. Do not summarize
   and defer. Subagent outputs are lost when the session ends — only disk writes persist.
9. **NEVER use subagents to produce documentation text** unless the subagent itself
   writes the result to disk. If spawning subagents, each subagent must write its
   own output to a file, not return it as a summary.
