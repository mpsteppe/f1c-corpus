# WORKER H — F1 Challenge 99-02 Reverse Engineering

You are documenting Ghidra-decompiled C code from a 2002 PC racing game.
This is Worker H of 10. You handle items 8–7.

**Two file types in your list:**
- `.c` files — one function each. Produce one triage line per file.
- `.bundle` files — multiple functions packed together. Each function is wrapped:
  `===== FILE: 0x00XXXXXX__FUN_00XXXXXX.c (N lines, NB) =====`
  `... decompiled code ...`
  `===== END: 0x00XXXXXX__FUN_00XXXXXX.c =====`
  Produce one triage line per FILE section. The address is in the filename inside the header.

## YOUR OUTPUT FILE

Write ALL output to a single file:
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_H.md

Use this exact structure inside that file:

```
=== TRIAGE LINES ===
| 0x00XXXXXX | <lines> | <category> | <description> | yes/no | -- |
...

=== FULL ENTRIES ===
<!-- target: docs/06-session-race-logic.md -->
## FUN_00XXXXXX — Name
...

<!-- target: docs/20-math-utilities.md -->
## FUN_00YYYYYY — Name
...
```

Write to disk after EVERY function. Do not batch. Do not summarize at the end.
One function = one write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_H.md.

---

## YOUR FILES (0 files)



---

## FOR EACH FILE

1. Read the .c file
2. Classify into one category:
   - `math_util`     — pure math/vector/matrix, no game globals
   - `physics_math`  — physics math (forces, tire slip), no game globals
   - `collision`     — collision detection, BVH, intersection
   - `dynamics`      — rigid body, vehicle dynamics
   - `renderer`      — D3D, vertex buffers, shaders
   - `audio`         — sound mixing, Miles Sound System
   - `network`       — TCP/UDP, packet handling
   - `game_logic`    — references known game globals (see list below)
   - `unknown`       — cannot determine

3. Write a TRIAGE LINE for every file regardless of category:
   `| 0x00XXXXXX | <line_count> | <category> | <one-line description> | yes/no | -- |`
   (yes/no = is it game_logic?)

4. FULL ENTRY rules — who gets one:

   ALWAYS write a full entry for:
     game_logic, physics_math, dynamics, collision, renderer, audio, network

   TRIAGE LINE ONLY (no full entry) for:
     math_util   — pure leaf math with no game context
     unknown     — genuinely unclassifiable

   If unsure between math_util and physics_math: write the full entry.

Full entry format:

```
<!-- target: docs/<correct doc file — see guide below> -->
## FUN_00XXXXXX — Descriptive Name

Source: likely_source.cpp (from assert strings if present). One-line summary.

**Key logic:**
- What it does step by step
- Thresholds, state transitions, branches
- Key constants or formulas used

**Struct offsets (if accessed):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xXXX | FieldName | type, purpose |

**Globals:** (only for game_logic)
- `DAT_007c56a4` — SessionType (value read/written)

**Calls:** FUN_00AAAAAA (brief what), FUN_00BBBBBB (brief what)

**Moddability:** configurable | hardcoded | hookable
```

Target doc file guide — route by category:
  game_logic   -> docs/01 through 10 (whichever system it belongs to)
  collision    -> docs/17-physics-collision.md
  dynamics     -> docs/18-physics-dynamics.md
  physics_math -> docs/18-physics-dynamics.md
  renderer     -> docs/19-renderer.md
  audio        -> docs/21-audio-network-internals.md
  network      -> docs/21-audio-network-internals.md

  docs/01-engine-architecture.md   — main loop, game state machine, module lifecycle
  docs/02-ai-system.md             — AI difficulty, overtaking, waypoints
  docs/03-engine-wear-damage.md    — damage model, RPM limits, thermal
  docs/04-tire-system.md           — tire compounds, slip, wear
  docs/05-weather-system.md        — weather modes, rain, track conditions
  docs/06-session-race-logic.md    — scoring, standings, penalties, race state
  docs/07-pit-system.md            — pit strategy, crew, repair
  docs/08-file-formats.md          — file parsers (.svm/.hdv/.veh/.scn)
  docs/09-track-system.md          — track DB, surface, cameras
  docs/10-vehicle-physics.md       — suspension, brakes, aero, body

---

## KNOWN GAME GLOBALS (any of these = game_logic)

| Address | Name |
|---------|------|
| DAT_007c56a4 | SessionType (7=race, 6=quali, 0-5=practice) |
| DAT_007c56a8 | RacePhase (0-7) |
| DAT_007d00ec | GameState (1-7) |
| DAT_007d0410 | RaceMode (3/4=championship) |
| DAT_005c329c | VehicleCount |
| DAT_007c54e8 | PlayerVehiclePtr |
| DAT_007c54f0 | VehiclePtrArray |
| DAT_007d01a0 | AIDifficultySlider (0-120) |
| DAT_007d2e48 | SeasonScoringDB |
| DAT_007d0c60 | TireWearMultiplier |
| DAT_007cea5c | EngineWearMode (0/2/3) |
| DAT_007cf080 | WeatherMode (0-5) |
| DAT_008acf9c | TotalRaceLaps |
| DAT_007d0b28 | MultiplayerFlag |
| DAT_007cef84 | PenaltiesEnabled |
| DAT_007cebc4 | FormationLap |
| DAT_007d0308 | RaceActiveFlag |
| DAT_007d0b64 | FuelMult |
| DAT_007cec30 | ReconPitOpen |
| DAT_007cec54 | ReconPitClosed |

## SKIP PATTERNS (write TRIAGE LINE with category=unknown, skip full entry)

- "invalid distance code" / "need dictionary"  -> zlib
- "GenuineIntel" / "AuthenticAMD"              -> CPUID
- "IDirect3D" / "CreateDevice"                 -> DirectX internals
- "BINK" / "Miles Sound System"                -> media libraries
- "1#QNAN" / "1#INF"                           -> MSVC CRT

Exception: if a skip-pattern file ALSO contains game globals, document the game-logic part.

---

## RULES

0. **NEVER move, rename, or delete .c files.** Do NOT run mark_done.py or any script that moves files. File movement is handled exclusively by the merge script after your session ends.
1. Never stop early. Document ALL 0 files.
2. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_H.md after each function — never accumulate in memory.
3. Never write to any file except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_H.md.
4. TRIAGE LINE for every file, even skipped ones (use category=unknown).
5. FULL ENTRY for: game_logic, physics_math, dynamics, collision, renderer, audio, network.
6. NO full entry for: math_util, unknown.
