# DISCOVERY — Untapped External Sources (2026-07-16)

**Status:** MAJOR. Found three external data sources that were never exploited during the entire
project. Any of them retroactively upgrades all 6,870 documented functions. Read this before
doing any more static analysis — the highest-value work in the project is described here and it
is cheap.

**Read alongside:** `work/HANDOFF.md` (session state), `CLAUDE.md` (project overview).

---

## TL;DR

We reverse-engineered a stripped binary from the inside for months, inventing names like
`SessionTickUpdate` and `PhysicsDispatchChain`. Meanwhile:

1. **The game logs its own execution with the ORIGINAL class::method names and source
   file/line numbers.** The debug strings are already in the binary, already carry function
   address references, and the game will print a live execution narrative if launched with a
   higher trace level. This lets us replace invented names with real ones across the whole corpus.

2. **The game install folder contains prior community RE work** — a Lua DLL-injection mod
   framework (`inject.exe` + `Lua.dll` + `LuaScript/`), a Java live-telemetry plugin
   (`F1CLiveUIPlugin`) that reads game memory, and a steering-wheel DLL. Their config files
   encode independently-discovered memory offsets = free cross-validation of our globals.

3. **This is an ISI gMotor-family engine** (shared lineage: F1 2002 → F1 Challenge → rFactor →
   GTR2 → Automobilista). The file formats (.hdv/.tbc/.aiw/.gdb) are near-identical to rFactor's,
   which the modding community has publicly documented for 20 years. Our `docs/08-file-formats.md`
   was reconstructed from scratch when a community-validated spec for the same formats exists.

None of these require more decompilation. They are sitting on disk right now.

---

## SOURCE 1 — The game's own debug trace system

### What it is

The engine has a built-in trace/logging system. Every subsystem method logs its own entry.
The game already produced `LOG/trace.txt` at TRACE LEVEL = 2 during normal play. Sample
(real output, verbatim from the install):

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
...
ai_db.cpp    2022: Entered AIDatabase::Init()
steward.cpp  2345: Entered Steward::Init()
setup.cpp     704: Could not find ENGINE.INI
```

This gives, for free:
- **Original class names**: Game, OSMan, VidMan, SpecialFX, DynMan, PlayerFile, Sound, HWInput,
  OnScreen, AIDatabase, Steward, CamMan, Render, Options, NetComm, Setup, ...
- **Original method names**: Enter/Setup/Init/Restart/Post/Exit lifecycle (confirms the
  "subsystem manager pattern" documented in docs/16 — now with real names)
- **Original source file + line numbers** for each log point

### Location on disk

`%USERPROFILE%\Desktop\F1 Challenge V10\LOG\trace.txt` (149 lines at level 2).
Also in the same LOG/ dir: `weather.txt`, `lua.txt`, `steeringwheel.txt` (per-subsystem logs).

### The trace strings are ALREADY in our data — with function addresses

`tools/ida_strings.csv` (5,434 strings) has columns: `addr,length,encoding,value,ref_funcs`.
The `ref_funcs` column is a `|`-separated list of function addresses that reference the string.

**60 "Entered Class::Method()" strings, each mapped to its function address.** Examples
(verbatim from ida_strings.csv):

```
0x005be6a8,27,ascii,Entered AIDatabase::Init(),0x004040a0
0x005be940,23,ascii,Entered CamMan::Init(),0x0040c920
0x005be980,26,ascii,Entered CamMan::Restart(),0x0040c9e0
0x005be99c,23,ascii,Entered CamMan::Post(),0x0040cce0
0x005c331c,24,ascii,Entered DynMan::Enter(),0x0042c130
0x005c335c,24,ascii,Entered DynMan::Setup(),0x0042c170
0x005c3374,23,ascii,Entered DynMan::Init(),0x0042c1a0
0x005c338c,26,ascii,Entered DynMan::Restart(),0x0042c3b0
```

**This is a direct rename table.** `Entered DynMan::Init()` references `0x0042c1a0`, and we
already independently labeled `FUN_0042c1a0` as "DynMan::Init" — so the method confirms our
guess. But most functions were NOT guessed correctly, and 60 of them can be confirmed instantly.

`inputs/raw_strings/strings_raw.txt` also contains all 60 "Entered X::Y()" strings and 75 total `::`-containing
strings (some are non-method, e.g. namespace-qualified types).

### The .cpp file strings map source files to function CLUSTERS

31 strings of the form `D:\dev\F1_1999_2002\Source\<file>.cpp`, each with a `|`-separated list
of every function that references it (i.e. every function whose asserts/logs live in that source
file). This is a **source-file → function-set map**, already extractable. Examples:

```
game.cpp    -> 0x0042cf10|0x0042d260|0x0042d370|0x0042d5d0|0x0042d6b0|0x0042d7a0|0x0042d8a0|0x0042da30|0x0042db20  (10 funcs)
dynman.cpp  -> 0x0042c130|0x0042c170|0x0042c1a0|0x0042c3b0|0x0042c9f0|0x0042ca70                                   (6 funcs)
NetComm.cpp -> 0x0045d890|0x0045eb50|0x0045fc50|...|0x00462c00                                                     (20 funcs)
hdvehicle.cpp -> 0x00439210|0x0043af50|0x0043b040|0x0043c250|0x0043da10                                            (5 funcs)
hwinput.cpp -> 0x00455bf0|0x00455c60|0x00455d50|0x00455da0|0x00455e70|0x00455f00                                   (6 funcs)
```

Note: these are only functions that *reference* the .cpp path string (usually via an assert
macro), so it's a lower bound per file — but combined with address adjacency (functions in a
.cpp are contiguous in .text) it lets us assign source files to whole address RANGES, not just
individual functions. Cross-check against `docs/00-source-tree.md` which inferred file layout;
this is ground truth to validate it.

### The trace-level control mechanism (how to turn it up)

Relevant strings and their referencing functions (from ida_strings.csv):

```
0x005d2870, "CurrentRace=%d\nTRACE LEVEL = %d", ref 0x004d7960
0x005d4a18, "%strace.txt",                      ref 0x004d7960
0x005d4a24, "trace=%d",                          ref (none captured — likely cmdline sscanf)
0x005d4a30, "notrace",                           ref 0x004d7a00
```

Interpretation:
- **FUN_004d7960** = trace system init. Reads a trace level, opens `<LOGDIR>trace.txt`, writes
  the `TRACE LEVEL = %d` header. This is where the max level and the level gate live — READ THIS
  FUNCTION FIRST to find what the maximum meaningful trace level is and what each level enables.
- **FUN_004d7a00** = parses `notrace` (and probably `trace=%d`) from the command line.
- **FUN_004d7a50 / FUN_004d7aa0** = the trace emit functions. We documented these as
  "assert/error logging" throughout docs/ — that label is INCOMPLETE. They are the general
  trace printf. Every call site passes a format string that often contains the real function or
  operation name. Mining all their call sites = mining the entire original naming scheme.

`trace=%d` and `notrace` are command-line params. `Config.ini` and the launch `.bat` files
(`F1CUILivePluginStart*.bat`, `noPlayerMode.bat`) are where a launch argument would be added.

### How to exploit — concrete steps (highest value work in the project)

1. **Static name recovery (no game run needed):**
   - Parse the 60 `Entered Class::Method()` → address pairs from ida_strings.csv into a rename
     table. Instant confirmed names for ~60 subsystem lifecycle functions.
   - Extract ALL strings referenced by FUN_004d7a50 / FUN_004d7aa0 call sites. Each format
     string names an operation in original terminology. Many will contain method names,
     variable names, or state descriptions.
   - Build source-file → address-range map from the 31 .cpp strings + adjacency. Validate/replace
     docs/00-source-tree.md.

2. **Find the max trace level:** decompile FUN_004d7960 (and its callers). Determine the level
   variable, its clamp, and what each level unlocks. Levels above 2 likely log per-frame subsystem
   calls, physics steps, AI decisions, network packets — i.e. a self-narrating execution trace
   with REAL names, far richer than our Frida hooks.

3. **Runtime trace capture:** launch with the highest useful `trace=N`, play a full session,
   capture `LOG/trace.txt`. This is the game telling us its own call order with original names —
   directly comparable to (and validating/correcting) the Frida traces in `tools/trace/output/`.

4. **Mass correction pass:** diff recovered real names against our invented names across docs/.
   Feeds directly into the cv2 correction backlog (docs/25) and upgrades the knowledge graph.

### Why this is a gamechanger

Every deliverable in the project (impl specs, call chains, recreation blueprint, knowledge graph)
is keyed on function identity. Right now identity = invented name + address. Replacing invented
names with the engine's own names:
- Makes the docs verifiable rather than speculative
- Reveals the true subsystem/class boundaries (confirms or corrects our 17-system split)
- Gives every function its home source file with line-level granularity
- Costs almost nothing — the data is already sitting in ida_strings.csv and on disk

---

## SOURCE 2 — Community RE work already present in the install

The `F1 Challenge V10` install is a heavily-modded distribution. Prior authors already did
runtime RE on this exact binary. Their artifacts are cross-validation goldmines.

### Inventory (in `%USERPROFILE%\Desktop\F1 Challenge V10\`)

| Artifact | What it is | Why it matters |
|----------|-----------|----------------|
| `inject.exe` | DLL injector | A runtime code-injection path into this exe already works |
| `Lua.dll` + `LuaScript/main.lua` | Embedded Lua scripting mod | Community built a live scripting layer; main.lua parses Config.ini, rewrites it, loads `moduletest.dll` |
| `F1CLiveUIPlugin` + `F1CUILive.jar` + `F1CUILivePlugin*.ini` | Java live telemetry/UI overlay | Reads game state from memory in real time. Its .ini files encode memory offsets someone else found — DIRECT cross-check of docs/12 globals |
| `SteeringWheel.dll` + `steeringwheel.ini` | Wheel/display plugin | Another memory-reading consumer; offsets to validate |
| `oph.ini` + `oph readme.txt` | "OnePageHud" or similar overlay config | More externally-discovered offsets |
| `Telemetry/` | Telemetry output dir | Format of exported telemetry = struct layout confirmation |
| `Config.ini` | Master config | Every key here is a config value the binary parses — maps to specific parser functions |
| `src/Lua.rar` | Source of the Lua mod | Community source code for the injection layer |

### Note from memory (already known, connect the dots)

Memory file `project_f1cui_crossvalidation.md` records: "Tire stride 0xF8, vehicle struct 0x48C0,
wear floor 0.75 confirmed vs Ghidra; vehicle array at 0x005F0DEC; AI offsets -1580/-1664 open."
That cross-validation came from F1CUI — i.e. we ALREADY started mining Source 2 once and it
produced confirmed offsets. It was never done systematically. The `F1CUILivePlugin_*.ini` files
and the Java plugin's memory-map deserve a full extraction pass.

### How to exploit

1. Extract every memory offset / address literal from `F1CUILivePlugin*.ini`, `oph.ini`,
   `steeringwheel.ini`. Diff against docs/12 (globals) and docs/13 (struct offsets). Matches =
   independent confirmation; mismatches = something to investigate.
2. Unpack `src/Lua.rar` and read the community mod source. It documents which addresses they
   hook and why — a second opinion on the memory map.
3. The Java plugin (`F1CUILive.jar`) can be decompiled (standard JVM bytecode, trivial vs x86).
   Its memory-read calls reveal the offsets it depends on.
4. `inject.exe` + `Lua.dll` prove a clean injection path — useful for the modding-framework
   deliverable and for future runtime tracing that's lighter than Frida.

---

## SOURCE 3 — ISI gMotor engine-family Rosetta stone

### The lineage

F1 Challenge 99-02 (2003, EA/ISI) runs Image Space Incorporated's gMotor 2 engine. The same
engine and its data formats flow through a long, publicly-documented family:

```
F1 2001 / F1 2002  ->  F1 Challenge 99-02  ->  rFactor (2005)  ->  GTR2 / GT Legends
                                            ->  ARCA Sim / Automobilista (Reiza)
```

rFactor in particular has 20 years of community documentation for formats that are near-identical
to F1 Challenge's, because they share the gMotor data pipeline.

### Shared/near-identical file formats

| Format | Purpose | Community documentation status |
|--------|---------|-------------------------------|
| `.hdv` | Vehicle physics/handling data | Fully documented (rFactor modding wikis) |
| `.tbc` | Tire brand/compound curves | Fully documented |
| `.aiw` | AI waypoints / racing line | Fully documented |
| `.gdb` | Track/circuit database | Fully documented |
| `.veh` | Vehicle definition | Fully documented |
| `.svm` | (F1C-specific vehicle/setup) | Ours; cross-checkable vs .veh |
| `.gmt`/`.mas` | Mesh / archive | Documented |
| `.cam` | Camera definitions | Documented |
| `.plr` / player files | Player config | Partially documented |

Our `docs/08-file-formats.md` is 6,884 lines built purely from the binary's parsers. The
rFactor community specs give human-readable field names, valid ranges, and semantics for the
same byte layouts — cross-referencing them names struct fields we only know by offset.

### Evidence in our own data

- Assert path `D:\dev\F1_1999_2002\Source\` confirms ISI's 1999-2002 codebase.
- Source files `hdvehicle.cpp`, `tire_manager`, `ai_db.cpp`, `steward.cpp`, `camera.cpp`,
  `garage.cpp` map 1:1 onto gMotor subsystem names.
- Trace log line `tire_manager 1080: Non-existent tire brand ""` ties directly to .tbc tire-brand
  parsing.
- docs already reference rFactor/gMotor 31 times across 10 files (some prior awareness, never
  systematized).

### How to exploit

1. For each format in docs/08, pull the corresponding rFactor community spec and align field
   names to our offsets. This is a naming/validation pass, not new RE.
2. Use rFactor's documented struct field names as candidate names for the equivalent in-memory
   structs in docs/13.
3. Where F1C diverges from rFactor (it's an earlier engine rev), the diffs are the genuinely
   novel findings worth documenting.

**Caveat:** community wikis are external content — treat field-name claims as hypotheses to
confirm against our binary, not as ground truth. Confirm, then document.

---

## Revised project assessment

The earlier "we've reached the last mile / static analysis is 90-95% exhausted" conclusion was
wrong in one specific way: it assumed the only data sources were the binary and our own runtime
traces. Three external sources were never systematically used. The binary-internal analysis IS
largely exhausted — but the project is not, because these sources make the existing analysis
*trustworthy and correctly named*, which is worth more than discovering the next 500 orphans.

### Revised priority order (supersedes HANDOFF "What To Do Next")

1. **Trace-name recovery (Source 1) — DO FIRST, cheapest + highest value:**
   - Parse 60 `Entered X::Y()` → address pairs into a confirmed rename table.
   - Decompile FUN_004d7960 to find max trace level + level semantics.
   - Extract all FUN_004d7a50/FUN_004d7aa0 call-site format strings for name mining.
   - Build source-file → address-range map from the 31 .cpp strings.
2. **Run game at max trace level, capture LOG/trace.txt** — self-narrated execution with real
   names; validate against Frida traces and against our call graph.
3. **Community offset extraction (Source 2):** mine F1CUILivePlugin*.ini, oph.ini,
   steeringwheel.ini, F1CUILive.jar, and src/Lua.rar for memory offsets; diff vs docs/12+13.
4. **Apply cv2 corrections (253 FAILs, docs/25)** — now informed by real names from step 1.
5. **rFactor format alignment (Source 3):** name struct fields in docs/08 and docs/13 using the
   engine-family specs, confirming each against the binary.
6. Only then return to binary-internal frontier work (vtable dispatch tracing for 502 orphans,
   852 .text gaps).

### Data pointers for whoever picks this up

- `tools/ida_strings.csv` — 5,434 strings, `ref_funcs` column has function addresses. The whole
  of Source 1's static half lives here. 2,666 strings have at least one function reference.
- `inputs/raw_strings/strings_raw.txt` — flat strings dump; 60 "Entered" method strings, 75 `::` strings.
- `LOG/trace.txt` in the game install — the level-2 sample; the template for what higher levels
  produce.
- Trace functions: FUN_004d7960 (init/level), FUN_004d7a00 (cmdline parse), FUN_004d7a50 +
  FUN_004d7aa0 (emit).
- Memory `project_f1cui_crossvalidation.md` — prior partial Source-2 mining with confirmed offsets.
- Game install root: `%USERPROFILE%\Desktop\F1 Challenge V10\` — all of Source 2.

---

## One-paragraph summary for a fresh model

You are documenting a stripped x86 binary of F1 Challenge 99-02 (ISI gMotor engine). ~6,870
functions are documented with INVENTED names. Three external sources were discovered on
2026-07-16 that were never systematically used: (1) the game's own debug trace system prints
ORIGINAL class::method names and source file/line numbers — 60 of these are already mapped to
function addresses in `tools/ida_strings.csv` (ref_funcs column), and the trace level can be
raised via a `trace=%d` command-line arg to get a live self-narrated execution log; (2) the game
install folder contains community RE artifacts (Lua injection mod, Java telemetry plugin, wheel
DLL) whose config files encode independently-found memory offsets; (3) the engine is in the
rFactor/gMotor family whose file formats are publicly documented. Priority: recover real names
from source 1 first (cheap, upgrades everything), then validate offsets from source 2, then align
formats with source 3. Start by parsing the 60 `Entered X::Y()` strings and decompiling
FUN_004d7960 to find the max trace level.
