# toolfacts.md — canonical CLI reference for F1C skills

Generated 2026-07-18 against git 6bcccfe; regenerate the affected section when a tool changes.

**This file is the SOLE permitted source of command syntax for skill authors.** Skills copy
commands from here verbatim — never from memory or docs prose.

Legend: **LIVE** = requires the running game (`F1 Challenge Online.exe`).
Flags/args verified against each tool's source. All commands assume Git Bash on Windows 11.

---

## Python interpreters (READ FIRST — there are two, they differ)

| Invocation | Real exe | frida | pymem |
|---|---|---|---|
| `python` (on PATH) | `...\Programs\Python\Python312\python.exe` (3.12) | YES 17.15.5 | **YES** |
| `%USERPROFILE%\AppData\Local\Python\bin\python3.exe` (CLAUDE.md "canonical") | `...\Python\pythoncore-3.14-64\python.exe` (3.14) | YES 17.15.5 | **NO** |

- `python --version` works in Git Bash → `Python 3.12.10`. `python` is fine for every tool here.
- **pymem lives ONLY in Python312.** `tools/race_monitor.py` (its only pymem consumer) MUST be run
  with `python` (PATH), NOT the canonical 3.14 `python3.exe` — 3.14 raises
  `ModuleNotFoundError: No module named 'pymem'`.
- frida is in both, so all frida tools work with either interpreter.
- `.bat` files in `analysis_pipeline/` hardcode `...\Programs\Python\Python312\python.exe`
  EXCEPT `2_merge.bat`, which uses the canonical `...\Python\bin\python3.exe`. Both resolve.
- Recommendation for skills: use plain `python` for everything; it has the superset of packages.

---

## tools/investigate.py

Concept/address → ranked locations + auto-decoded dossier. Read-only, no game needed.

**Invocation** (cwd = project root): `python tools/investigate.py <subcommand-or-address...> [flags]`

Bare invocation (`python tools/investigate.py` with no args) → prints the module docstring (usage help). Safe.

| Subcommand | Syntax | Notes |
|---|---|---|
| find | `find <term...>` | multi-word term joined; searches strings, func names/summaries, globals(docs/12), doc headings + full-text doc bodies. Missing term → `usage: ...` |
| global | `global <DAT_addr\|addr>` | graph + raw .c scan merged; accepts `DAT_007c56a4` or bare `007c56a4` |
| uses | `uses <token...>` | raw ground-truth .c scan for ANY literal (hex/offset/identifier); tags each hit R/W |
| system | `system <term...>` | whole-subsystem map: functions, shared globals, impl specs, call chains, mod targets, vtables |
| mod | `mod <term...>` | ranked patch surface: docs/16 data-file params, mod_targets patch-points, writable globals |
| param | `param <field-name...>` | data-file field → parser function → file format (docs/16 join) |
| (address) | `<addr> [addr2 ...]` | dossier. Accepts `0x004ef5a0`, `004ef5a0`, `FUN_004ef5a0`. Batch ALL addrs in ONE call (iron rule 2) |

**Dossier flags** (address mode only): `--no-source` (tables only), `--snippet` (only decisive lines,
5-10× cheaper), `--callees` (also dump each callee). Default = full source dump.

**Reads (all optional, degrade gracefully if absent):** `knowledge_graph/*.json`,
`docs/12-globals-reference.md`, `docs/13-struct-offsets.md`, `docs/13-audit-report.md`, `docs/*.md`,
`tools/ida_strings.csv`, `work/source_atlas.csv`, `work/vtables.csv`, `work/mod_targets.csv`,
`work/fp_constants.csv`, decompiled dirs (`analysis_pipeline/analyzed/`, `decompiled_all/`,
`decompiled_full/`, `tools/decompiled_ida/`). Uses `rg` if on PATH, else pure-Python fallback.

**Output:** stdout only, never writes files. Dossier header `FUN_XXXXXXXX — name`, then identity /
graph edges / struct-offset table / globals / calls / source. `find` prints ranked FUNCTIONS/GLOBALS/
DOC sections/DOC content. **No non-zero exit on "not found"** — prints `nothing found` and exits 0.
Side effects: none.

---

## tools/poke.py — LIVE

Named runtime memory console. **LIVE** for every subcommand except `list`.

**Invocation** (cwd = root): `python tools/poke.py <cmd> [args]`. Bare (`poke.py` no args) → prints docstring.

**Precondition:** `mods/sdk/f1c_sdk.json` must exist (all commands `load_sdk()` at startup).
Missing → exits: `mods/sdk/f1c_sdk.json missing — run: python tools/gen_sdk.py`.
Game must be running for read/write/watch/veh/snapshot/diff (opens process with
VM_READ|VM_WRITE|VM_OPERATION|QUERY; may need admin).

| Subcommand | Syntax | LIVE | Notes |
|---|---|---|---|
| list | `list [term]` | no | search known globals by name/desc; SDK only, no attach |
| read | `read <tok> [tok2 ...]` | YES | one or many tokens |
| write | `write <tok> <value>` | YES | writes straight into the running game |
| watch | `watch <tok> [tok2 ...] [--hz N]` | YES | default 2.0 Hz; prints on change; Ctrl+C to stop |
| veh | `veh <field\|offset>` | YES | player-vehicle struct field by name search or raw offset |
| snapshot | `snapshot [path]` | YES | capture ALL known globals → JSON (default `snapshot.json`) |
| diff | `diff <path> [--thresh F]` | YES | changed globals since capture; default thresh 0.0 |

**Token grammar:** `SessionType` (SDK name, case-insensitive, unique-substring ok) | `DAT_007c56a4` |
`0x007c56a4` | `0x7c56a4:int32` (per-token type override via `:type`).
**Types:** `float double int32 uint32 int int16 uint16 int8 uint8 byte ptr`.
`veh` raw offset defaults to `float`; `veh` field uses SDK type.

**Failure messages worth pattern-matching (quote exactly):**
- `'F1 Challenge Online.exe' is not running — start the game first` (no game)
- `OpenProcess failed (run as admin?) — pid <N>` (permission)
- `unknown global '<tok>' — try: poke.py list <tok>`
- `ambiguous '<tok>' — matches:` (then a list; exits 1)
- `write failed at 0x<addr>`
- `player vehicle pointer is NULL (not in session?)` (veh, not in a session)
- read of unreadable addr prints value `<unreadable>` (does not exit)

**Side effects / danger:** `write` mutates live game memory — save replays/setups first. `snapshot`
writes a JSON file. Iron rule 6: always re-read after write and log both (`write` already prints
before→after).

---

## tools/preflight.py — LIVE (run, probe)

Verify a mod's factual claims vs the live game before writing code. Imports `poke.Game`.

**Invocation** (cwd = root): argparse with required subcommand.
- `python tools/preflight.py run <facts.json> [--stable-secs F] [--stable-hz F]` — **LIVE**
- `python tools/preflight.py probe <expr> [expr2 ...] [--type T] [--secs F] [--hz F]` — **LIVE**
- `python tools/preflight.py example` — prints template facts.json to stdout, **not LIVE**

Defaults: `--stable-secs 2.0`, `--stable-hz 30.0` (run); `--type int32`, `--secs 2.0`, `--hz 30.0` (probe).
No subcommand → argparse error (subcommand is `required=True`).

**Expression grammar** (`expr := atom (('+'|'-') hex)*`, `atom := '[' expr ']' | name | hexaddr`):
- `SessionType` — SDK global name | `0x007C56A4` — raw addr | `[0x007C54E8]` — deref (read u32 ptr)
- `[0x007C54F0]+0x4064` — deref then offset | `[[..]+0x10]+0x8` — nests arbitrarily
- `<expr>:float` — per-expr type override (probe only; run uses each fact's `"type"`)

**facts.json schema:**
```json
{ "name": "mod_name",
  "facts": [
    {"id":"vehicle_count","expr":"0x005C329C","type":"int32","expect":{"range":[1,26]}},
    {"id":"player_ptr","expr":"[0x007C54E8]","type":"ptr","expect":{"nonzero":true}},
    {"id":"finish_state","expr":"[0x007C54F0]+0x4064","type":"int32","expect":{"in":[0,1,2,3]},"stable":true},
    {"id":"in_race","expr":"SessionType","type":"int32","expect":{"eq":7},"gate":true} ] }
```
- `expect` kinds: `{"eq":v}` | `{"in":[..]}` | `{"range":[lo,hi]}` | `{"nonzero":true}` (omit = readable-only)
- `stable:true` — sample for `--stable-secs`; FAIL if the game rewrites it (your write would be clobbered)
- `gate:true` — precondition (e.g. must be in a race); reported as **GATE** not FAIL

**Output:** stdout per-fact lines tagged `PASS` / `FAIL` / `GATE`, then `<N> hard failure(s).`
**Exit code = number of FAILed facts, gates excluded.** 0 = compose the mod. `probe`/`example` return 0.

**Precondition:** SDK json (via `load_sdk`); game running (via `poke.Game`). Same attach failures as poke.py.

---

## tools/patch.py — byte-patch manager (does NOT need game running)

Manifest-based byte patcher. Operates on the exe FILE, not the process.

**Invocation** (cwd = root): `python tools/patch.py <cmd> [args] [--exe PATH] [--out NAME] [--desc TEXT]`.
Bare → prints docstring.

**Default exe:** `%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe`.
**Manifest:** `mods/patches/manifest.json` (checked in; exists).

| Subcommand | Syntax | Effect |
|---|---|---|
| add | `add <name> <va-hex> "<new bytes>" [--desc TEXT]` | reads+records ORIGINAL bytes at VA, appends a site to patch `<name>` |
| status | `status` | every patch: `applied` / `clean` / `FOREIGN` / `MIXED(...)`; flags overlaps |
| show | `show <name>` | per-site VA, orig→new, current on-disk state |
| apply | `apply <name> [--out "COPY.exe"]` | verify originals, write new bytes |
| revert | `revert <name>` | verify patched, restore originals |
| remove | `remove <name>` | drop from manifest (exe untouched) |

- VA is hex (e.g. `0x004bc4e0`). New bytes: hex string, spaces/commas/`0x` tolerated (`"e8 fb fb ff ff"`).
- One mod = many sites: `add` repeatedly with the same `<name>`.
- `--out` writes a patched COPY (relative names resolve next to the exe); original untouched.
- In-place `apply` creates `<exe>.prepatch.bak` once (first ever apply).

**FOREIGN semantics:** a site whose current bytes match NEITHER recorded original NOR new = another mod
or wrong exe version. `apply`/`revert` **ABORT, writing nothing**:
`  ABORT: bytes at 0x<va> match neither original nor patch (other mod / wrong exe version). Nothing written.`
Already-in-target-state sites are skipped, not re-written.

**Other messages:** `no patch '<name>'` (bad name; exits) · `bad hex byte string: '<s>'` ·
`site 0x<va> already in patch '<name>' — remove first` · `!! COLLISION: 'A' and 'B' overlap at 0x<va>`.

**Danger:** modifies the exe on disk unless `--out` used. Patched on-disk exe may trip integrity checks →
prefer Frida version first (MODDING_PLAYBOOK). Always verify original bytes (add records them) and patch a COPY.

---

## tools/patch_trace.py — unlock the in-game trace-level clamp

Patches two immediate bytes in the exe so the trace-level clamp (hard max 2) rises to N.

**Invocation** (cwd = root):
- `python tools/patch_trace.py --level N` — patch in place (backs up to `<exe>.bak` once)
- `python tools/patch_trace.py --restore` — revert from `.bak`
- `python tools/patch_trace.py --level N --dry` — show, don't write
- `--exe PATH` overrides default exe (default = same V10 path as patch.py)

`--level` type int, default 10, **must be 1..255** (single-byte immediate) else exits `level must be 1..255`.
File offsets patched: `0xd7971` (cmp imm) and `0xd7976` (mov imm). Expected original both `0x02`;
prints `WARNING: expected both 0x02; already patched or wrong exe/offsets` if not.
`--restore` with no `.bak` → exits `no .bak found next to exe`.

**Danger:** modifies the exe in place (`.bak` is the only safety net). After patching, launch the game
with the `notrace` cmdline arg to ENABLE tracing, then read `LOG/trace.txt`.

---

## tools/gen_sdk.py — compile knowledge base → SDK (NO ARGS; runs on bare invocation)

**⚠ EXECUTES ON BARE INVOCATION — do not run casually.** `python tools/gen_sdk.py` immediately
regenerates the SDK. No argparse, no `--help`. It reads docs and overwrites the two SDK files.

**Reads:** `docs/12-globals-reference.md`, `docs/13-struct-offsets.md`,
`knowledge_graph/functions.json`, `work/vtables.csv` (each degrades gracefully if missing).
**Writes:** `mods/sdk/f1c_sdk.h` (C accessor macros) and `mods/sdk/f1c_sdk.json` (machine-readable,
consumed by poke.py / preflight.py / gen_hook.py / Frida). Prints a one-line count summary.
**When to regenerate:** after EVERY docs merge (globals/structs/functions changed).
Side effect: overwrites both SDK files. Otherwise harmless (no game, no network).

---

## tools/gen_hook.py — scaffold a DLL mod

Generates a `mods/<name>/` project (DLL source + build.bat + README). No game needed.

**Invocation** (cwd = root): `python tools/gen_hook.py <template> <name> [target] [--desc "text..."]`.
`< 2` args → prints docstring.

| Template | Syntax | Produces |
|---|---|---|
| tick | `tick <name>` | per-frame polling thread DLL (no binary mod, pure external logic) |
| detour | `detour <name> <addr\|funcname>` | inline 5-byte JMP hook + trampoline of a game function |

- `detour` with no target → exits `detour needs a target: gen_hook.py detour <name> <addr|funcname>`.
- Target resolves via `mods/sdk/f1c_sdk.json` `functions` map: `0x004bc0e0` or a name / unique substring.
  Ambiguous substring → prints matches, exits 1. Unknown → `unknown function '<token>'`.
- Unknown template → `unknown template '<template>' (use: tick | detour)`.
- Missing SDK json → `mods/sdk/f1c_sdk.json missing — run: python tools/gen_sdk.py`.

**Outputs** (into `mods/<name>/`): `<name>.c`, `build.bat`, `README.md`. Build needs MinGW32 at
`C:\msys64\mingw32\bin` (hardcoded in build.bat as `MINGW`). Detour scaffold defaults `PROLOGUE_LEN 5`
with a loud TODO — must be set to a whole-instruction boundary ≥5 or it crashes.
**Danger:** detour = calling-convention/prologue hazard; STATE-WRITES-ONLY doctrine still applies (never
call game internals from injected code). Overwrites files in `mods/<name>/` if it exists.

---

## tools/port.py — sibling-function porting workbench (read-only)

**Invocation** (cwd = root):
- `python tools/port.py <game> <sibling_addr>` — dossier for porting
- `python tools/port.py list` — known game keys + decompiled counts
- bare (no args) → prints docstring

**Games:** `nascar03`, `nascar04`, `f1_2002`, `f1_2002_demo`, `scgt`. Unknown game →
`unknown game '<k>' — one of: nascar03, nascar04, f1_2002, f1_2002_demo, scgt`.
Only game + addr with `<2` total non-list args → `usage: python tools/port.py <game> <sibling_addr>`.

**Reads:** `source_material/<GameDir>/decompiled/*.c`, `source_material/<GameDir>/docs/4*.md`,
`cross_binary/_delta/<stem>_classified.csv` + `<stem>_srcmatch.csv`. Missing data → prints
`no cross-binary match rows...` / `no decompiled .c...` (still exits 0). Output: stdout dossier. No writes.

---

## tools/race_monitor.py — LIVE (pymem)

Live vehicle-struct monitor, all drivers, CSV dump. **LIVE.** **Requires pymem → run with PATH `python`
(Python312), not the 3.14 canonical.** Missing pymem prints `Missing dependency. Run: pip install pymem`
then exits 1.

**Invocation** (cwd = root): `python tools/race_monitor.py [--interval F] [--drivers N] [--docs PATH]`.
Defaults: `--interval 5.0`, `--drivers 22`, `--docs docs/10-vehicle-physics.md`.

Attaches to `F1 Challenge Online.exe` (pymem). Fail → `Failed to attach: <e>` + `Make sure the game is
running.` then exits 1. Runs until Ctrl+C. **Writes** `monitor_output/snapshot_<TS>.csv`,
`monitor_output/changes.csv`, `monitor_output/summary.txt`. Struct constants baked in
(STRUCT_SIZE 0x48C0, DRIVER0_BASE 0x005F0DEC). Read-only vs game (never writes memory).

---

## tools/parse_struct_dump.py — offline dump parser (no game)

**Invocation** (cwd = root): `python tools/parse_struct_dump.py <dump.bin> [docs/10-vehicle-physics.md]`.
`< 1` arg → prints usage, exits 1.
Input: a raw 0x48C0-byte vehicle-struct dump. Too small → `[!] File too small: <n> bytes, expected 18624`.
**Writes** next to input: `<dump>_annotated.txt` and `<dump>_gaps.csv`. Stdout: `Written: ...` lines.
No game, no network.

---

## tools/mod_pipeline/mod_pipeline.py — SEED→MAP→WATCH→PATCH

**Invocation** (cwd = `tools/mod_pipeline/`, or use full path from root). argparse, subcommand `required=True`.
- `python mod_pipeline.py map <seed.json>` — static dossier (no game)
- `python mod_pipeline.py watch <seed.json>` — generate Frida watch agent .js (no game; running it is LIVE)
- `python mod_pipeline.py patch --addr <hex> --type <T> --value <V> [--name NAME]` — patch record + Frida override (no game)

`--type` choices: `float`, `double`, `int`, `bytes` (bytes = hex string). Unknown type in map path
prints `unknown type <t>`.

**seed JSON format** (`tools/mod_pipeline/seeds/*.json`, e.g. `ai_drying.json`):
```json
{ "name": "ai_drying",
  "description": "...",
  "globals": [ {"addr":"0x008afee8","label":"OnPathWetness","type":"float"} ],
  "seeds":   [ "0x00404250", "0x00404460" ],
  "struct_watches": [],
  "watch_hz": 10 }
```
Optional keys: `player_ranges`, `ai_ranges` (lists of `[start,end]` VA), `struct_watches`
(each `{base_global,index,stride,offset,type,label}` for the watch agent).

**Reads:** `tools/ida_data_xrefs.csv`, `tools/cross_binary_final.csv`, `knowledge_graph/callers.json`,
`analysis_pipeline/analyzed/*.c`, `tools/mod_pipeline/subsystems.py`. Hardcoded EXE path (V10) for `patch`.
**Writes:** `map` → `investigations/<name>/consumers.csv` + `dossier.md`;
`watch` → `investigations/<name>/<name>_watch.js`; `patch` → `patches/<name>.json` + `<name>.js`
(all under `tools/mod_pipeline/`). `patch` prints `original: UNKNOWN (exe not found)` if exe absent.

---

## tools/mod_pipeline/asm_tools.py — deterministic disasm helpers (no game)

Reads the exe FILE + repo CSVs so a weak LLM never hand-does rel32 math.

**Invocation** (cwd = `tools/mod_pipeline/`). argparse, subcommand `required=True`.
- `python asm_tools.py resolve <addr> [--source]` — one-shot dossier: identity, ret-imm (calling
  convention/arg count), callers, string anchors, source path. `--source` dumps full raw .c.
- `python asm_tools.py redirect <caller> <from> <to> [--at <call_va>]` — find E8 calls to `<from>`
  inside `<caller>`, emit retarget bytes, and CHECK thiscall stack balance (ret-imm delta).

All addresses hex. `redirect` without `--at` and multiple sites → redirects ALL, prints
`NOTE: <n> call sites ... To target one, pass --at <call_va>.`. `--at` with no matching site →
`No call to <from> at <va>.`. No sites → `No E8 calls to <to> found in <caller> (size <n>).`.
Non-zero stack delta prints `!! STACK MISMATCH` + how many pushes to NOP.
**Reads:** exe (default V10 path), `tools/cross_binary_final.csv`, `knowledge_graph/callers.json`,
`tools/ida_functions.csv`, `analysis_pipeline/analyzed/` (+ `decompiled_all/`). Stdout only, no writes.
`redirect` only EMITS patch bytes — it does not modify anything.

---

## tools/mod_pipeline/watch_run.py — LIVE (frida)

Attach Frida to the running game, load a watch agent .js, stream its CSV rows.

**Invocation** (cwd = `tools/mod_pipeline/`):
`python watch_run.py <agent.js> [--seconds F] [--out FILE] [--interactive]`.
Defaults: `--seconds 0` (run until Ctrl+C), `--out None` (interactive mode forces `watch_capture.csv`).

**Precondition:** `pip install frida`; game running. Not running →
`ERROR: '<PROCESS>' not running. Start a race first.` exit 1. Agent .js must exist (opened directly).
**Interactive commands** (agent must export matching rpc): `row` (latest values), `header`,
`poke <off> <val>` (write S32 to every AI car, skips player), `dump <idx> <start> <end> <step>`,
`q`/`quit`/`exit`, `help`/`?`. In interactive mode the stream goes to the `--out` file, console is the prompt.
**Writes:** the `--out` CSV if given. **Danger:** `poke` writes live game memory.

---

## tools/trace/f1c_trace.py — LIVE (frida)

Frida trace controller (function-call + state traces). **Requires `pip install frida frida-tools`; game running.**

**Invocation** (cwd = root or `tools/trace/`): `python tools/trace/f1c_trace.py [flags]`.
| Flag | Type/default | Effect |
|---|---|---|
| `--frames N` | int 0 | capture N frames then stop; 0 = interactive |
| `--output` / `-o` | str | filename saved in `tools/trace/output/` |
| `--state` | flag | read current state vars and exit |
| `--list-threads` | flag | list game threads and exit |
| `--quiet` / `-q` | flag | suppress per-line console (still writes file) |
| `--state-only` / `-S` | flag | no function hooks, only watch state-var writes (tiny output) |

Not running → `ERROR: '<PROCESS>' not running.` exit 1. Permission denied →
`ERROR: Permission denied. Run as Administrator.` exit 1. Interactive verbs: `start [N] stop state
status threads global <addr> quit help`. **Writes** trace logs under `tools/trace/output/`.

## tools/trace/trace_comprehensive.py — LIVE (frida, admin)

10-minute comprehensive capture; installs hooks only after game reaches RUNNING.

**Invocation:** `python tools/trace/trace_comprehensive.py [--duration N] [--launch] [--wait N] [--quiet]`.
Defaults: `--duration 600` (s), `--wait 20`. `--launch` starts the game itself with `-trace=2 -noplayer`
(hardcoded GAME_DIR = `%USERPROFILE%\Desktop\F1 Challenge V10`) before attaching.
Run as Administrator. **Writes** `tools/trace/output/comprehensive_<TS>_<dur>s.log`.
Not found after 60s → `ERROR: '<PROCESS>' not found after 60s.` exit 1.
Danger: `--launch` spawns the game process.

## tools/trace/analyze_trace.py — offline trace analyzer (no game)

**Invocation:** `python tools/trace/analyze_trace.py <trace_file> [--summary] [--frame N] [--threads] [--doc PATH]`.
Parses a trace log. No matching entries → `No trace entries found.` exit 1. `--doc PATH` writes a
generated markdown doc; otherwise stdout only. No game, no writes unless `--doc`.

## tools/trace/extract_state_machines.py — offline .c scanner (no game; WRITES a doc)

**Invocation:** `python tools/trace/extract_state_machines.py` (no args). Scans
`analysis_pipeline/analyzed/*.c` + `decompiled_all/*.c` for 8 hardcoded state-var globals,
reads `knowledge_graph/functions.json`. **Writes/overwrites `docs/15-state-machines.md`.**
Note: this outputs directly to `docs/` — a doc-generator, distinct from worker output rules.

---

## tools/physics_id/map_channels.py — LIVE (frida)

Frida channel-discovery: poll vehicle-struct byte range as f64/f32, rank offsets by variance.
**Requires `pip install frida frida-tools`; game in an active on-track session (DRIVE the car).**

**Invocation:** `python tools/physics_id/map_channels.py [--lo H] [--hi H] [--hz N] [--secs F] [--out PATH]`.
Defaults: `--lo 0x1100`, `--hi 0x1600` (exclusive), `--hz 100`, `--secs 20`, `--out channels.csv`
(next to the script). `--lo/--hi` accept `0x` hex. Not running →
`process not found — is the game running? (F1 Challenge Online.exe)`. No samples →
`no samples captured — was the game in an on-track session?`. **Writes** the CSV. Read-only vs game.
`PLAYER_VEHICLE_PTR = 0x007c54e8` is GUESS-tier (verify).

---

## tools/knowledge_graph/rebuild.py — rebuild the graph (no game; WRITES graph JSONs)

**Invocation** (cwd = root): `python tools/knowledge_graph/rebuild.py` (no args). Runs `extract.run()`
then `build_graph.run()`. Reads `docs/`, writes `knowledge_graph/*.json`. Prints progress + `Done in <t>s`.
Run after any docs/ change (and before/after gen_sdk in the merge flow).

## tools/knowledge_graph/query.py — graph query (read-only)

**Invocation** (cwd = root): `python tools/knowledge_graph/query.py <command> [args]`. Bare → docstring.
Reads `knowledge_graph/*.json`.

| Command | Syntax | Notes |
|---|---|---|
| func | `func <addr>` | everything known about a function |
| calls | `calls <addr>` | direct callees (= `trace <addr> 1`) |
| callers | `callers <addr>` | direct callers (= `traceback <addr> 1`) |
| trace | `trace <addr> [depth]` | forward call tree, default depth 3 |
| traceback | `traceback <addr> [depth]` | inverse caller tree, default depth 3 (caps 15/node) |
| path | `path <addr1> <addr2>` | shortest path via call edges (BFS, both directions, cap 5000) |
| global | `global <DAT_addr>` | all functions touching a global |
| system | `system <doc_file>` | functions in a game system (fuzzy match; lists all if no match) |
| search | `search <text...>` | search names + summaries + algorithm family |
| stats | `stats` | graph-wide statistics |
| context | `context <addr\|system>` | focused LLM context window (prints char/token estimate) |

Note: docstring lists `struct`, `module`, `top` but these are NOT wired in `main()` — do NOT use them
(unknown command → `Unknown command: <cmd>` + available list). Unknown addr → `Unknown function: <addr>`.
Missing args → `Missing arguments for '<cmd>'.`. Stdout only, no writes.

---

## tools/search_docs.py — search docs/*.md with related-token harvest (no game)

**⚠ Path caveat:** this script resolves `DOCS_DIR = <script_dir>/docs`, i.e. `tools/docs/` — which does
NOT exist in this repo (docs live at project-root `docs/`). As shipped it finds no `.md` files from the
default location. Prefer `investigate.py find` / `investigate.py uses` for doc search. If used, run from a
cwd where `./docs` resolves, or treat output as empty.

**Invocation:** `python tools/search_docs.py <query> [-C N] [-l] [--all] [--offset|--global|--fun|--keyword]`.
Auto-detects query type (hex offset / DAT_ global / FUN_ / keyword). `-C` context lines (default 3),
`-l` file:line only, `--all` include the 7k-row index. Force-mode flags override auto-detect. Stdout only.

---

## analysis_pipeline batch entry points

All are `.bat` — run from Git Bash as `cd <dir> && cmd //c <name>.bat`. Each starts with
`cd /d "%~dp0"` so it self-locates, but the CONVENTIONS rule is: cwd = `analysis_pipeline/`.
`0_bundle.bat`, `0r_gen_queue.bat`, `1_batch_gui.bat`, `5_move_analyzed.bat` invoke Python312
(`...\Programs\Python\Python312\python.exe`); `2_merge.bat` invokes canonical (`...\Python\bin\python3.exe`).

| .bat | Invokes | Purpose |
|---|---|---|
| `0_bundle.bat` | `bundle_small.py` | pack small .c files from `not_analyzed/` into bundles |
| `0r_gen_queue.bat` | `generate_review_queue.py` | build `work/review_queue.jsonl` (full-entry queue) |
| `1_batch_gui.bat` | `batch_launcher.py` | Tkinter GUI: split work across ≤20 workers A–T, pick a mode, save prompts. No `pause` (GUI) |
| `2_merge.bat` | `merge_to_docs.py`, then `--subdir ida_gaps --archive` if `output/ida_gaps/worker_A.md`, then `../tools/knowledge_graph/rebuild.py` | merge worker output → docs, rebuild graph |
| `5_move_analyzed.bat` | `merge_to_docs.py --move-only` | sync `not_analyzed/`→`analyzed/` from current docs state |

(All except `1_batch_gui.bat` end with `pause`.)

**merge_to_docs.py flags** (`analysis_pipeline/merge_to_docs.py`; cwd = `analysis_pipeline/`):
- (no flags) — merge `output/worker_[A-U].md` (+`_batchN`) into `docs/` per `<!-- target: docs/xx.md -->`
  comments, skip existing `## FUN_` addrs, append triage lines to `decompiled_full_index_final.md`, then
  `move_analyzed()`, then archive+reset workers. No worker files → `No worker output files found in <dir>`.
- `--move-only` — skip merge, only run `move_analyzed()` (`not_analyzed/`→`analyzed/` for documented addrs).
- `--subdir NAME` — merge from `output/<NAME>/` instead of `output/`; by default does NOT archive/clear
  (prints `Subdir mode — files NOT archived or cleared.`).
- `--archive` — with `--subdir`, archive files after merging (like standard mode).

Iron rules for this pipeline: workers NEVER write `docs/` directly (output → `analysis_pipeline/output/`);
never re-document an existing `## FUN_`; never move `analysis_pipeline/` dirs (hardcoded paths).

---

## cross_binary/scripts/merge_xbin_delta.py — merge Sibling Delta worker output (no game)

**The ONLY merge path for `## sub_` delta entries.** `analysis_pipeline/merge_to_docs.py`
(and therefore `2_merge.bat`) splits only on `## FUN_`/`### FUN_` headers — it silently
drops 100% of `## sub_` entries and then archives/clears the worker files. Never run it
on xbin_delta output.

**Invocation** (cwd = project root): `python cross_binary/scripts/merge_xbin_delta.py` (no args).

**Reads:** `analysis_pipeline/output/xbin_delta/worker_*.md` (output of the batch GUI
"Sibling Delta" / `xbin_delta` mode). Game keys: `f1_2002`, `nascar03`, `nascar04`, `scgt`
(note: no `f1_2002_demo` key in this script).
**Routing:** full entries route by game-qualified target comment
`<!-- target: <game>/<doc>.md -->` → `source_material/<GameDir>/docs/<doc>.md`; bare
`docs/NN.md` targets are salvaged by inferring the worker's single game (plurality vote
over its addresses vs each game's decompiled corpus). Triage lines append to that game's
`docs/decompiled_index.md`. Dedup is by existing `## sub_`/`### sub_` headers in the
target doc. Processed `.c` files move `pipeline/not_analyzed/` → `pipeline/analyzed/`
under that game's `source_material/` dir; worker files archive to
`output/xbin_delta/archive/<TS>/`.
**Output:** `merged: +<n> triage, +<n> full entries (<n> salvaged from bare docs/ targets)`;
malformed addresses print `SKIPPED <n> malformed addresses (manual review): [...]` and are
NOT merged. Side effects: appends to sibling docs, moves .c files, archives worker files.

## cross_binary/scripts/xbin_match.py — sibling delta classifier (no game)

**Invocation** (cwd = project root): `python cross_binary/scripts/xbin_match.py <sibling>`
(e.g. `nascar03`). Optional flags (argparse): `--f1c-sigs`, `--f1c-strings`,
`--f1c-dataxrefs`, `--sib-sigs`, `--sib-strings` (defaults resolve under `tools/`),
`--out` (default `cross_binary/_delta`).
**Reads:** per-binary fingerprint CSVs (`<name>_byte_sigs.csv`, `<name>_strings.csv`).
**Writes:** `_delta/<sibling>_classified.csv` (every sibling func + verdict) and
`_delta/<sibling>_novel.csv` (NOVEL only). Pure stdlib, offline, no game.
Note: the script's docstring/CSV verdict for the (size, masked-head) match is
`BYTE_NORM`; `cross_binary/_README.md` calls the same signal `BYTE_MASK`. Same thing.
The `mask()` relocation-zeroing (E8/E9 rel32 + in-image absolutes) lives here — do not
remove it (see _README §Validation).

## commit.bat (project root)

**Invocation** (from root): `cmd //c commit.bat`. Interactive (prompts for a message via `set /p`).
`cd /d` to project root, then `git add docs/ roles/ scripts/ work/CHANGELOG.md work/QUEUE.md README.md
CLAUDE.md commit.bat .gitignore`, shows `git status --short`, prompts for a commit message (Enter →
default `docs: session checkpoint`), commits, prints `git log --oneline -5`, `pause`.
**Note:** it stages only that fixed file list — NOT `tools/`, `mods/`, `analysis_pipeline/`, etc. It never
stages patched exes / .bak / game binaries (consistent with handoff rules). Danger: creates a real commit.
