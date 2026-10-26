# BREAKTHROUGH: Untapped External Sources — Trace Mining, Community Prior Art, Engine Family

**Date:** 2026-07-16
**Status:** DISCOVERED, NOT YET EXPLOITED
**Priority:** #1 — supersedes all other pending work. Read this before continuing any other phase.
**Companion:** `work/HANDOFF.md` (session log), `CLAUDE.md` (project overview)

---

## Executive Summary

The project spent all effort on binary-internal analysis (Ghidra, IDA, Frida) and considered
itself ~95% exhausted. Three external sources were never exploited, discovered 2026-07-16:

1. **The game has built-in trace logging** with ORIGINAL source file names, line numbers, and
   `Class::Method()` names, activated by a command-line parameter that was never tried.
   The game documents itself. This can recover real names for hundreds of functions.

2. **The game install folder contains community reverse-engineering prior art**: a DLL
   injection framework with Lua scripting, two memory-reading telemetry plugins with
   independently discovered memory offsets, and per-subsystem log files.

3. **The engine is ISI gMotor lineage** (F1 2002 → F1 Challenge → rFactor → GTR2 →
   Automobilista). rFactor's file formats (.hdv/.tbc/.aiw/.gdb/.svm) are near-identical
   and have 20 years of public community documentation — a Rosetta stone for naming
   struct fields and file format semantics that was never cross-referenced.

Any one of these could rename/validate large fractions of the 6,870 documented functions.
Combined, they retroactively upgrade the entire documentation corpus.

---

## Discovery 1: Built-In Trace Logging (THE BIG ONE)

### Evidence

**File:** `%USERPROFILE%\Desktop\F1 Challenge V10\LOG\trace.txt` (149 lines, from a past
game run, sitting there unnoticed the whole project). First lines:

```
TRACE LEVEL = 2
NetComm.cpp  6949: NetComm checking command line: ""
game.cpp      360: Entered Game::Enter()
osman.cpp     420: Entered OSMan::Enter()
vidman.cpp    928: Entered VidMan::Enter()
specialfx.cp 2798: Entered SpecialFX::Enter()
dynman.cpp    507: Entered DynMan::Enter()
plrfile.cpp  2463: Entered PlayerFile::Enter()
sound.cpp     661: Entered Sound::Enter()
hwinput.cpp  5205: Entered HWInput::Enter()
onscreen.cpp 2604: Entered OnScreen::Enter()
game.cpp      430: Entered Game::Setup()
options.cpp  1169: Entered Options::Setup()
tire_manager 1080: Non-existent tire brand ""
steward.cpp  2330: Entered Steward::Setup()
game.cpp      467: Entered Game::Init()
ai_db.cpp    2022: Entered AIDatabase::Init()
steward.cpp  2345: Entered Steward::Init()
setup.cpp     704: Could not find ENGINE.INI
camera.cpp   3633: Entered CamMan::Init()
render.cpp    199: Entered Render::Init()
game.cpp      509: Entered Game::Restart()
...
```

**This is the engine's own diagnostic output.** Original .cpp filename, original line number,
original class::method name, in execution order.

### Binary-side confirmation

`inputs/raw_strings/strings_raw.txt` contains:
```
TRACE LEVEL = %d
%strace.txt
trace=%d
notrace
```

`trace=%d` is a **command-line parameter**. The game was run at TRACE LEVEL = 2 by whatever
produced the existing log. Higher levels exist (find the clamp/max in the parser). The
rFactor-lineage convention is `+trace=N` or `trace=N` on the command line; F1C accepts
`trace=%d` per the format string. There is also a `notrace` switch.

### The logging machinery in our docs (misidentified)

Two functions were documented as generic "error logging" without realizing their significance:

- **FUN_004d7a50** — trace-level gate. Signature pattern from call sites:
  `FUN_004d7a50(level, source_file_string, line_number)` — returns nonzero if current
  trace level >= requested level. Example from FUN_0042cf10 (game.cpp):
  ```c
  cVar6 = FUN_004d7a50(2, s_D__dev_F1_1999_2002_Source_game__005c3590, 0xd7);
  if (cVar6 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c, s_Multiplayer_mode__setting_vehicl_005c355c);
  }
  ```
  Note: `0xd7` = 215 = the line number in game.cpp. The string at 0x005c3590 is
  `D:\dev\F1_1999_2002\Source\game.cpp`.

- **FUN_004d7aa0** — trace output/printf. First arg `&DAT_008ad25c` (debug buffer),
  second arg format string.

**Every call site of these two functions is a (file, line, message) triple** statically
embedded in the binary. The message often IS the original function name
(`"Entered Game::Enter()"`).

### What this unlocks

1. **Mass function renaming.** For every trace call site whose message says
   `Entered X::Y()`, the containing FUN_ address IS X::Y (or its inlined caller).
   The existing trace.txt at level 2 already proves ~30 mappings. Higher trace levels
   log far more functions.

2. **Line-number-accurate source reconstruction.** `steward.cpp 2330` (Setup) and
   `steward.cpp 2345` (Init) bound the source layout. Collecting all (file, line)
   pairs per file reconstructs the original file structure at line granularity —
   far better than the current docs/00-source-tree.md inference.

3. **Runtime execution narrative with real names.** Run the game with max trace level
   through a full race → get the engine's own account of what runs when, with original
   names — validates/corrects every invented name in docs (SessionTickUpdate,
   PhysicsDispatchChain, etc. all become checkable).

4. **Log-line ↔ address mapping.** Combine trace.txt output order with Frida timestamps
   from `tools/trace/` captures to bind log lines to addresses even for messages
   without obvious anchors.

### Exact mining procedure (static, no game launch needed for step 1)

1. **Mine `tools/ida_strings.csv`** (5,434 strings with referencing functions — this data
   is ALREADY EXPORTED). Extract:
   - All strings matching `Entered %s` / `Entered *::*` patterns
   - All strings that look like trace messages
   - Their referencing function addresses
2. **Enumerate all xrefs to FUN_004d7a50 and FUN_004d7aa0** (use `tools/ida_xrefs.csv`
   or knowledge_graph/callers.json — both already contain this). For each calling
   function: extract the file-string + line-number arguments from the decompiled .c
   (files in `analysis_pipeline/analyzed/`, pattern: `FUN_004d7a50(N, s_..., 0xLINE)`).
3. **Build table:** FUN_address → (source.cpp, line, message). Where message contains
   `Class::Method`, propose rename.
4. **Cross-check against existing docs entries** — flag naming conflicts as corrections
   in `work/CHANGELOG.md` with `[CORRECTION]` prefix.

### Runtime procedure (after static mining)

1. Find max trace level: read the `trace=%d` parser (search callers of the command-line
   parsing near `NetComm.cpp 6949: NetComm checking command line` string; NetComm.cpp
   is the command-line checker per trace.txt line 2).
2. Launch: `"F1 Challenge Online.exe" trace=99` (game likely clamps to max; also try
   `+trace=99` if bare form fails — rFactor lineage uses `+`).
3. Play a full session (menu → race → results → exit). LOG/trace.txt gets rewritten.
4. Optionally run the Frida state tracer (`tools/trace/f1c_trace.py -S`) simultaneously —
   correlate wall-clock timestamps.
5. Parse resulting trace.txt: every unique (file, line, message) is ground truth.

**WARNING:** LOG/trace.txt gets overwritten per run. The current 149-line file is from an
old run — **archive it first**: copy to `tools/trace/output/original_trace_level2.txt`.

---

## Discovery 2: Community Prior Art In The Install Folder

**Location:** `%USERPROFILE%\Desktop\F1 Challenge V10\` — this is the community "V10" mod
install, not vanilla F1C. It contains independent reverse-engineering artifacts:

| Item | What it is | Value |
|------|-----------|-------|
| `inject.exe` + `Lua.dll` + `LuaScript/main.lua` | DLL injection + Lua 5.x scripting layer injected into the game process | A working runtime modding framework for this exact exe already exists. Study inject.exe's technique; the Lua API surface reveals which memory the modders considered stable |
| `src/Lua.rar` | Source of the Lua injection layer | Unpack and read — shows exactly which addresses/functions the mod hooks |
| `F1CLiveUIPlugin/` + `F1CUILive.jar` + many `F1CUILivePlugin_*.ini` | Java-based live telemetry overlay reading game memory | The .ini files and jar encode independently discovered memory offsets — free cross-validation of docs/12 globals and docs/13 struct offsets. Prior session memory (`project_f1cui_crossvalidation.md`) already validated some: tire stride 0xF8, vehicle struct 0x48C0, vehicle array 0x005F0DEC |
| `SteeringWheel.dll` + `steeringwheel.ini` + `LOG/steeringwheel.txt` | Another memory-reading plugin | More independent offsets |
| `LOG/` (HAT, Results, lua.txt, trace.txt, weather.txt, steeringwheel.txt) | Per-subsystem log outputs | weather.txt = weather subsystem's own logging; Results = session