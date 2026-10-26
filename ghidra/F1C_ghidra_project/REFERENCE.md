# REFERENCE.md — Full Project Reference

Complete reference for the F1C reverse-engineering project. CLAUDE.md holds only
the iron rules and pointers; everything else lives here. Read sections on demand —
do not load this whole file into context speculatively.

## Project Overview

Reverse engineering documentation project for **F1 Challenge 99-02** (`F1 Challenge Online.exe`) — x86 PE32, MSVC ~2002, 3.14 MB, 6,772 functions decompiled with Ghidra + 495 IDA-only functions. Goal: complete public documentation of the game engine.

Your role is **ARCHITECT** (see `roles/ARCHITECT.md`). You audit, verify, assign work, and quality-gate. You do NOT write docs or run triage — delegate to Worker (DS V4 Flash) and Lead (GLM-5.2).

## LLM Role System

| File | Model | Task |
|------|-------|------|
| `roles/WORKER.md` | DS V4 Flash | Bulk triage + full `## FUN_` entries |
| `roles/LEAD.md` | GLM-5.2 | Human-readable docs from flagged functions |
| `roles/ARCHITECT.md` | Claude | Audit, verify, assign work |

Each role file is self-contained — point the model at it and it knows what to do.

## Directory Layout

```
F1C_ghidra_project/
  docs/                          — authoritative documentation output
    01–21: game systems + engine internals
    12-globals-reference.md      — ~8,048 named globals (2,356 + 5,685 from global_validate_2)
    13-struct-offsets.md         — 6,910 lines of synthesized struct definitions
    13-audit-report.md           — struct confidence audit: 281 sections, 375 new offsets, conflicts flagged
    30-impl-specs/               — 18 per-system reimplementation specs (NEW)
    31-call-chains/              — 237 end-to-end call chain traces (NEW)
    decompiled_full_index_final.md — master triage table (7,108 entries)
  decompiled_all/                — 656 string-anchored .c files
  decompiled_full/               — 6,116 anonymous .c files (all moved to analyzed/)
  analysis_pipeline/             — ALL pipeline tooling lives here
    batch_launcher.py            — GUI for generating + launching DS worker prompts (26 modes)
    merge_to_docs.py             — merges worker_X.md output into docs/
    2_merge.bat                  — merges standard + ida_gaps output, rebuilds graph
    analyzed/                    — all 6,116+ .c files (processing complete)
    not_analyzed/                — empty (all done)
    output/                      — worker_A.md … worker_T.md (active run)
    output/ida_gaps/             — IDA Gaps mode worker output
    output/orphan_resolve/       — Orphan Resolve mode worker output (378 classified)
    output/archive/              — archived outputs per merge run
    prompts/                     — saved worker prompts (worker_X_prompt.md)
  source_recovery/               — source recovery workspace (isolated, self-contained)
    ACTION_PLAN.md               — master task list (single source of truth)
    FINDINGS.md                  — append-only discovery log
    01_binary_forensics/         — PE analysis of F1C exe (Rich header, RTTI, debug dir)
    02_cross_binary/             — comparing other isiMotor1 binaries for debug symbols
    03_sdk_crossref/             — rFactor SDK header cross-referencing
    04_dll_framework/            — DLL proxy/injection modification framework
    05_automation/               — AHK + Frida automated trace pipeline
    06_community_sources/        — external knowledge (interviews, patches, download links)
    binaries/                    — downloaded exes/demos (gitignored)
  cross_binary/                  — isiMotor1 sibling cross-binary DELTA workspace (self-contained)
    _README.md                   — pipeline + methodology (read first)
    scripts/                     — xbin_match (byte+mask), xbin_srcmatch (TF-IDF source), xbin_feature_diff,
                                   build_delta, recover_missed, ida_export/decompile, merge_xbin_delta, merge_cleanup
    WORKER_DELTA.md              — DS worker role for sibling-delta docs
    _delta/                      — featdiff_<game>_not_f1c.csv (PORT bins) + classified/srcmatch/ledgers
    _fingerprints/ _decomp/ _logs/ — byte-sigs/strings, IDA hexrays corpora, run logs (gitignored)
  source_material/<game>/docs/40-43 — 2,357 sibling-exclusive functions (in game, NOT in F1C) with Port verdicts
  docs/32-sibling-exclusive-functions.md — F1C<->F1 2002 portability MATRIX (what each side has/lacks)
  knowledge_graph/               — extracted.json + 9 graph JSON files
  tools/knowledge_graph/         — Python scripts: extract.py, build_graph.py, query.py, explorer.py
  roles/                         — WORKER.md, LEAD.md, ARCHITECT.md system prompts
  work/
    PLAN_recreation.md           — active plan toward open-source recreation
    PLAN_hardening.md            — active plan for coverage + call graph hardening
    CHANGELOG.md                 — [CORRECTION] entries from audits
    merge_impl_spec.py           — merges impl_spec output → docs/30-impl-specs/
    merge_call_chain.py          — merges call_chain output → docs/31-call-chains/
    merge_struct_synth.py        — merges struct_synth output → docs/13
    merge_global_sweep.py        — merges global_sweep output → docs/12
    merge_global_validate.py     — merges global_validate/global_validate_2 output → docs/12 (use --subdir flag)
    merge_struct_audit.py        — merges struct_audit output → docs/13-audit-report.md
    merge_arch_narrative.py      — prepends arch narratives to docs/17–21
    merge_orphan_resolve.py      — parses orphan_resolve output → summary CSV + graph rebuild
    new_call_edges.csv           — 14,424 supplementary call edges (Phase 5 + IDA xrefs)
    orphan_resolve_summary.csv   — 378 orphan classifications from DS workers
    function_sizes.csv           — Ghidra function export (6,772 functions)
    binary_coverage_gaps.csv     — 990 binary gaps from PE gap audit
    new_function_candidates.csv  — 188 missed function candidates (45 HIGH confirmed)
  tools/
    binary_coverage_audit.py     — PE gap analysis → new_function_candidates.csv
    call_edge_completeness.py    — .c text scan → 6,208 supplementary edges
    ida_export_all.py            — IDA headless: exports functions/xrefs/strings/vtables + decompiles gaps
    ida_diff_and_import.py       — diffs IDA vs Ghidra, resolves vtable orphans
    run_ida_export.bat           — runs IDA headless export (idat.exe -A -B)
    ida_functions.csv            — 6,170 IDA-discovered functions
    ida_xrefs.csv                — 14,223 IDA call edges
    ida_vtables.csv              — vtable scan (empty — no RTTI in binary)
  scripts/
    ExportFunctionSizes.java     — Ghidra: export all functions to work/function_sizes.csv
    CreateMissedFunctions.java   — Ghidra: create+decompile HIGH-confidence missed functions
    CreateGapFunctions.java      — Ghidra: create gap functions (superseded by IDA approach)
```

**Python path on this machine:** `%USERPROFILE%\AppData\Local\Python\bin\python3.exe`

## Modding Toolchain — START HERE for mods

**STEP 0 — MANDATORY: read `mods/_README.md` FIRST.** It is the shipped-mod ledger:
what already works, reusable primitives (hotkey tick DLL, injector, vehicle-array
iteration, confirmed struct writes), and the strategy ladder. Many "new" mod
requests are one field-value change to an existing mod (e.g. F8→AI-DNF =
`mods/ai_pit_retire/`, already working). Then `tools/mod_pipeline/MODDING_PLAYBOOK.md`.
Never call game functions from injected code — pure memory writes or call-site
byte redirects only. **Before writing ANY mod code**: decompose the mod into facts
(addresses/types/values/stability) and verify each against the live game:
`python tools/preflight.py run mods/<name>/facts.json` (template: `preflight.py example`).
Never test "does the whole mod work" as the first test — test facts one at a time.

Six tools turn the docs into a programmable modding surface. The modding ladder:
data files → runtime pokes → byte patches → vtable swaps → DLL hooks.

```bash
# 1. SDK — compile the knowledge base into a C header + JSON (run after every docs merge)
python tools/gen_sdk.py                  # -> mods/sdk/f1c_sdk.h (+ .json)
#   g_SessionType, VEHICLE_TireWear(p), FN_<name>, VTBL_<addr> — names not raw offsets
#   8,039 global macros, 165 struct accessor groups, 6,342 func addrs, 181 vtables
#   ambiguous docs/13 offsets kept as `alt:` comments — never silently mislabelled

# 2. poke — named runtime memory console (needs game running; non-ASLR abs addrs)
python tools/poke.py list tire           # search known globals
python tools/poke.py read SessionType
python tools/poke.py write TireWearMultiplier 3.0
python tools/poke.py watch RacePhase SessionType --hz 4
python tools/poke.py veh TireWear         # player-vehicle struct field by name
python tools/poke.py snapshot before.json # capture ALL globals -> do thing in-game ->
python tools/poke.py diff before.json     #   diff shows what moved (find unknown globals by behavior)

# 3. patch — byte-patch manager, manifest at mods/patches/manifest.json
python tools/patch.py add <name> 0xVA "90 90" --desc "..."   # records ORIGINAL bytes
python tools/patch.py status              # applied / clean / FOREIGN + collision detection
python tools/patch.py apply <name>        # verifies originals first; .prepatch.bak once
python tools/patch.py apply <name> --out "F1C (mod).exe"     # patched COPY instead
python tools/patch.py revert <name>       # verified restore

# 4. gen_hook — scaffold a compilable DLL mod wired to the SDK (MinGW32)
python tools/gen_hook.py tick <name>              # per-frame polling thread (VSC, weather...)
python tools/gen_hook.py detour <name> 0xADDR     # inline 5-byte JMP hook + trampoline
#   emits mods/<name>/{<name>.c, build.bat, README.md} — fill in one C function body

# 5. port — sibling-function porting workbench (feature resurrection)
python tools/port.py nascar03 0x004c9650   # sibling source + doc + F1C byte/TF-IDF matches
python tools/port.py list                  # game keys: nascar03/04, f1_2002, scgt

# 6. param — data-file field -> parser function -> file format (tier-1 join)
python tools/investigate.py param FuelConsumption
```

## Bug Investigation — START HERE

Before hand-grepping to LOCATE code, or hand-reading `.c` files, use investigate.py.
It kills the three biggest token sinks: guessing which grep to run, serial file reads,
and hand-computed offset math.

```bash
# STEP 0 — MODDING? Start with the subsystem map, not a grep.
python tools/investigate.py system tire     # functions + moddability + impl spec + call chains
                                            # + shared globals + patch-points + vtable hooks
python tools/investigate.py mod penalty     # patch surface: mod_targets tiers + docs/16
                                            # data-file params + runtime-pokeable globals

# STEP 1 — LOCATE: concept/term -> ranked addresses (strings + names + globals + docs).
# `find` also full-text scans ALL doc bodies (impl-specs/call-chains often ARE the answer).
# Do this FIRST. Never fan out raw greps to find a function again.
python tools/investigate.py find "commentary"
python tools/investigate.py find "tire wear"
python tools/investigate.py global DAT_007c56a4   # who touches a global (graph MERGED with raw .c scan)
python tools/investigate.py uses 0x113e           # raw scan for ANY token: hex/struct-offset/DAT_/identifier
                                                  # tags each hit [W]=writes / [R]=reads + shows the line

# NOTE: the knowledge graph under-reports (globals_usage.json had 10 users for SessionType; the
# real count is ~98). `global` and `uses` scan the actual .c files, so trust them over `query.py`.

# STEP 2 — DOSSIER: feed the address(es) in. Source + auto-decoded offsets + globals + edges.
# Pass EVERY function your hypothesis touches in ONE call.
python tools/investigate.py 0x004ef5a0 0x004b8940 0x004b87c0

# Tables only (no source dump) — fast triage of many functions
python tools/investigate.py 0x004ef5a0 --no-source

# Decisive lines only (globals/offsets/calls/constants ±1 ctx) — 5-10x cheaper sweeps
python tools/investigate.py 0x004ef5a0 --snippet

# Also pull the source of everything this function calls
python tools/investigate.py 0x004ef5a0 --callees
```

The offset table auto-converts `param_1[0xcaf]` → `+0x32bc`, decimal `13000` → `+0x32c8`,
and looks each byte offset up in docs/13 for the field name. Lookup is SCOPED per struct
section: ambiguous offsets show ALL candidate structs (`Field [Struct]; Field2 [Struct2] ?`)
— pick by context, never trust a `?`-marked label blindly. Never recompute idx×4 by hand.
Pointer-chain bases (`*param_1 + N`) are flagged `↳` — offset is into a SUB-object, the
exact class of confusion that stalled the replay-AI bug hunt.

Rule: build the offset table ONCE from the dossier, reason ONCE. Do not re-derive.

## Key Commands

```bash
# Open batch launcher GUI — all pipeline modes available here
analysis_pipeline/1_batch_gui.bat

# Merge ALL worker outputs into docs/ + rebuild graph (standard + ida_gaps)
analysis_pipeline/2_merge.bat

# Merge only standard worker output (no ida_gaps, no graph rebuild)
cd analysis_pipeline && python merge_to_docs.py

# Merge ida_gaps subdir output + archive
cd analysis_pipeline && python merge_to_docs.py --subdir ida_gaps --archive

# Rebuild knowledge graph after any docs/ change
python tools/knowledge_graph/rebuild.py

# Query knowledge graph (CLI)
python tools/knowledge_graph/query.py stats
python tools/knowledge_graph/query.py func 0x00XXXXXX
python tools/knowledge_graph/query.py context 0x00XXXXXX
python tools/knowledge_graph/query.py global DAT_007c56a4
python tools/knowledge_graph/query.py system docs/04-tire-system.md

# Launch knowledge graph GUI explorer
tools/knowledge_graph/explorer.bat

# Check worker completion status
for f in A B C D E F G H I J K L M N O P Q R S T; do
  echo "worker_$f: $(grep -c '^## FUN_' analysis_pipeline/output/worker_$f.md 2>/dev/null || echo 0) entries"
done

# Fix non-FUN_ headers in worker output before merging (if workers wrote Unwind_/thunk_ headings)
# Run from analysis_pipeline/output/
sed -i 's/^## Unwind_\([0-9a-fA-F]*\)/## FUN_\1/' worker_X.md

# Fix double .md.md target extension
sed -i 's/\.md\.md/.md/g' worker_X.md

# Merge impl_spec worker output → docs/30-impl-specs/
python work/merge_impl_spec.py

# Merge call_chain worker output → docs/31-call-chains/
# Note: accepts both '# Chain:' and '# Chain N:' header formats
python work/merge_call_chain.py

# Merge global_validate or global_validate_2 output → docs/12
python work/merge_global_validate.py --subdir global_validate_2

# Merge struct_audit output → docs/13-audit-report.md
python work/merge_struct_audit.py
```

## Parallel Worker Workflow


Workers write to `analysis_pipeline/output/worker_X.md`. Never write directly to `docs/`.

Output format:
```
=== TRIAGE LINES ===
(blank for Full Entry / Deep Dive modes)

=== FULL ENTRIES ===
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Name
...
```

After all workers finish: run `analysis_pipeline/2_merge.bat`. Merge script:
- Appends triage lines to `docs/decompiled_full_index_final.md`
- Routes full entries to target doc via `<!-- target: -->` comment
- Skips addresses already present as `## FUN_` headers (duplicate detection)
- Archives worker files to `output/archive/TIMESTAMP/`

**Launching a worker:**
1. Open `1_batch_gui.bat` → select mode → set worker count → Generate
2. Click worker letter → "Launch + Copy Prompt" → paste into DS instance
3. DS reads the prompt file path and follows all instructions autonomously

**Stalled worker recovery:**
```python
# Find remaining functions for a stalled worker and generate resume prompt
import re, os
prompt = open('prompts/worker_X_prompt.md').read()
done = set(re.findall(r'^## FUN_([0-9a-fA-F]+)', open('output/worker_X.md').read(), re.M))
assigned = re.findall(r'\d+\. (C:[^\n]+\.c)', prompt)
remaining = [p for p in assigned if re.search(r'0x([0-9A-Fa-f]{8})__', p) and
             re.search(r'0x([0-9A-Fa-f]{8})__', p).group(1).lower() not in done]
print(f'{len(remaining)} functions remaining')
```

## Knowledge Graph

Built from `docs/` content. Rebuild after any merge: `python tools/knowledge_graph/rebuild.py`

**Graph files in `knowledge_graph/`:**
- `functions.json` — all 6,306 functions with metadata
- `call_graph.json` — forward call edges (caller → callees)
- `callers.json` — inverse edges (callee → callers)
- `structs.json` — synthesized struct definitions
- `globals_usage.json` — every global → functions that touch it
- `modules.json` — source file groupings
- `systems.json` — doc file → function lists
- `algorithms.json` — algorithm family clusters
- `stats.json` — top-called functions, most-used globals

**Current graph stats (2026-07-15 final, post global_validate_2 + struct_audit):**
- 6,868 known functions; 6,805 documented, 63 triage-only
- 16,475 call edges (8,299 Ghidra baseline + 6,208 Phase 5 text-scan + 8,216 IDA xrefs + 61 IDA-only function edges)
- 8,843 unique globals tracked (~8,048 named in docs/12 after global_validate_2 merge)
- 433 algorithm families
- 1,075 source modules inferred
- 479 orphan functions (271 structural floor + 208 IDA-only with no static callers)

**Supplementary edge file:** `work/new_call_edges.csv` — loaded by `build_graph.py` on every rebuild.
**IDA database:** `%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe.id0/.id1/.nam/.til`
**IDA install:** `C:\Program Files\IDA Professional 9.1\idat.exe`

## Source Data

| Directory | Files | Nature |
|-----------|-------|--------|
| `decompiled_all/` | 656 | String-anchored — identifiable purpose |
| `decompiled_full/` | 6,116 | Anonymous — physics/math/renderer/audio/network |

Filenames: `0x00XXXXXX__FUN_00XXXXXX.c`. Address is always the hex in the filename.

Source path in assert strings: `D:\dev\F1_1999_2002\Source\` — gives real .cpp filenames.

## Documentation Output (`docs/`)

The `docs/` files are the authoritative output — protect their quality.

- `docs/01–10`: Game systems (string-anchored functions)
- `docs/12`: All known `DAT_` globals — check here before claiming a global is new
- `docs/13`: All known struct field offsets — check here before claiming an offset is new
- `docs/16`: All moddable/writable game parameters
- `docs/17–21`: Engine internals (anonymous functions from `decompiled_full/`)
- `docs/34-source-atlas.md`: real file/line/`Class::Method` coords from baked trace/assert literals (FACT data; heuristic `target_addr`) — `work/source_atlas.csv`, `work/source_file_map_expanded.csv`
- `docs/35-mod-targets.md`: 155 ranked enforcement/validation patch-points (string↔func xref = FACT; "patch X changes Y" = HYPOTHESIS; only `0x004bc0e0` DQ confirmed) — `work/mod_targets.csv`
- `docs/36-vtables.md`: 181 recovered C++ vtables (RTTI-less, byte-scanned from `.rdata`), 3,202 method slots — `work/vtables.csv`; enables vtable-swap mods; class names mostly open
- `docs/37-fp-constants.md`: 845 FP physics/math constants with values + readers — `work/fp_constants.csv`

**investigate.py dossier now shows an identity block** (from `work/*.csv`): real source file/line/`Class::Method` (atlas), vtable role (constructs/method-slot), mod-target flag, and FP constants read. Regenerate the four CSVs with `tools/harvest_source_atlas.py`, `tools/expand_source_files.py`, `tools/extract_vtables.py`, `tools/build_mod_targets.py`, `tools/extract_fp_constants.py`.
- `docs/decompiled_full_index_final.md`: Master triage table (7,108 entries)

**Current state** (as of 2026-07-15 final, after global_validate_2 + struct_audit):
- `decompiled_all`: 655/656 documented
- `decompiled_full`: all 6,116 files triaged; **6,306+/6,306 full `## FUN_` entries** written — 100% complete
- **+45 functions** created via Ghidra headless (HIGH-confidence binary gaps) — all documented
- **+4 functions** created via IDA Hex-Rays (giant gaps Ghidra couldn't find) — all documented
- **+451 functions** from IDA v2 comprehensive export — all documented via DS workers
- All .c files in `analysis_pipeline/analyzed/` (including 451 IDA-only decompilations)
- Knowledge graph: **6,868 known functions**, **16,475 call edges**, 8,843 globals tracked, 433 algorithm clusters, 1,075 source modules
- `docs/12`: ~8,048 table rows (2,356 baseline + 5,685 from global_validate_2)
- `docs/13`: 6,910 lines struct definitions
- `docs/13-audit-report.md`: 7,124 lines — 281 sections audited, 375 new offsets, key conflicts flagged
- `docs/17–21`: architecture narratives prepended
- `docs/18-physics-dynamics.md`: 4 new giant-gap entries (LDL^T factorization, dynamics solver, identity init, zero-init)
- `docs/30-impl-specs/`: 18 reimplementation specs
- `docs/31-call-chains/`: 237 call chain traces

**Remaining quality gaps:**
- **Phase 0 (partial)**: 143 MEDIUM-confidence binary gap candidates not yet re-evaluated with updated Ghidra DB
- **global_validate_2**: DONE — 5,685 new globals named; docs/12 now ~8,048 rows
- **struct_audit**: DONE — 281 sections audited; key conflicts in AnimationNode (systematic +4/+8 error), UI Control struct (int-index vs byte-offset), RotationMatrix range; 375 new offsets → `docs/13-audit-report.md`
- **triage_upgrade**: 63 triage-only functions need full `## FUN_` entries (4 workers)
- **gap_analyze**: 852 .text gaps need classification (10 workers)
- **Phase 4**: runtime validation — Python process-attach framework — not started
- **479 orphan functions**: 271 structural floor + 208 IDA-only with no static callers
- **0x0047fc54 gap (22KB)**: neither Ghidra nor IDA found functions — likely data table in .text
- **docs/30 redundant pairs**: Arch+Part2, Math Utils+Part2, Session+Part1 — can be manually merged
- **Second/Third wave DS tasks**: switch_map, exception_map, import_map, string_map, orphan_resolve_2, enum_catalog, sig_refine, source_tree, data_map, inline_detect — all pending (see `work/HANDOFF.md`)
- **cross_validate_2**: DONE — 3,408 PASS, 253 FAIL, corrections in `docs/25-cv2-corrections.md`

## Doc Entry Formats

**Full entry** (`## FUN_`, h2) — for game logic and significant functions:
```markdown
## FUN_00XXXXXX — Descriptive Name

Source: likely_source.cpp. One-line summary.

**Key logic:**
- Step-by-step behavior, thresholds, state transitions
- Branches on globals (e.g. "if SessionType == 7 → race branch")

**Struct offsets (param_1):**
| Offset | Field | Notes |

**Globals:**
- `DAT_XXXXXXXX` — meaning

**Calls:** FUN_00AAAAAA (what, per docs/NN)

**Moddability:** `configurable` | `hardcoded` | `hookable`
```

**Lightweight entry** (`### FUN_`, h3) — for table-row upgrades in `decompiled_all`:
```markdown
### FUN_00XXXXXX — Short Name

One-line summary.

**Key logic:**
- 2–4 bullets

**Calls:** FUN_00AAAAAA (what)
```

**Triage line** — for `decompiled_full_index_final.md`:
```
| 0x00XXXXXX | LineCount | category | algorithm/purpose | yes/no | docs/NN or — |
```
Categories: `math_util` | `physics_math` | `collision` | `dynamics` | `renderer` | `audio` | `network` | `game_logic` | `unknown`

## Ghidra Pseudocode Patterns

| Pattern | Meaning |
|---------|---------|
| `*(double *)(ptr + 0x1330)` | 8-byte double at struct offset 0x1330 |
| `param_1[0x4a]` | Int-indexed: real byte offset = 0x4a × 4 |
| `DAT_007c56a4` | Global variable |
| `unaff_EBX/ESI/EBP` | Register-allocated `this` pointer |
| `thunk_FUN_XXXXXX` | Trampoline — skip |
| `goto` chains | MSVC loop artifact — ignore |

**False positive:** Offsets `+0x1130`/`+0x1132` also appear in DirectX device structs. Only document as vehicle struct offsets if function has NO DirectX API calls (`CreateDevice`, `IDirect3D`, `DrawPrimitive`, etc.).

## Skip Patterns (no doc entry needed)

`"invalid distance code"` / `"need dictionary"` → zlib  
`"Cyrix"` / `"GenuineIntel"` / `"AuthenticAMD"` → CPUID  
`"IDirect3D"` / `"CreateDevice"` / `"vertex buffer"` → DirectX  
`"BINK"` / `"Miles Sound System"` → media libraries  
`"1#QNAN"` / `"1#INF"` → MSVC CRT  
`"TCPDeny"` / `"TCPInfo"` / `"Ping Request"` → NetComm  
`"OSC Read Error"` / `"Prelinked Gizmo"` → UI framework internals  

If a function has both skip-pattern strings AND game-logic globals: document only the game-logic part.

## Key Globals (subset — full list in `docs/12-globals-reference.md`)

| Address | Name |
|---------|------|
| DAT_007c56a4 | SessionType (7=race, 6=quali, 0–5=practice) |
| DAT_007c56a8 | RacePhase (0–7) |
| DAT_007cea5c | EngineWearMode (0/2/3) |
| DAT_007cf080 | WeatherMode (0–5) |
| DAT_007d00ec | GameState (1–7) |
| DAT_007d01a0 | AIDifficultySlider (0–120) |
| DAT_007d0410 | RaceMode (3/4=championship) |
| DAT_005c329c | VehicleCount |
| DAT_007c54e8 | PlayerVehiclePtr |
| DAT_007c54f0 | VehiclePtrArray |
| DAT_007d0c60 | TireWearMultiplier |
| DAT_008acf9c | TotalRaceLaps |
| DAT_007d0308 | RaceActiveFlag |
| DAT_007cebc4 | FormationLap |

## Verification Methodology (Architect role)

Fast check (30s): grep claimed globals in the actual .c file — if they appear, likely correct.  
Full check (2min): match every claim in the doc entry against the .c file: globals, struct offsets, string literals, called functions.

Red flags to catch:
- "reads X" but .c only writes
- Struct offset claimed as `double` but .c shows `*(int *)(ptr + 0xXXX)`
- `Moddability: configurable` but no field-name string literal in .c file
- Functions already in `docs/` re-documented (duplicates)

Flag errors in `work/CHANGELOG.md` with prefix `[CORRECTION]`.

## Batch Launcher Modes

`analysis_pipeline/batch_launcher.py` GUI supports 11 modes:

| Mode | What it does | Items | Output |
|------|-------------|-------|--------|
| `triage` | Classifies new .c files into triage index | not_analyzed/ files | `output/worker_X.md` |
| `review` | Writes full `## FUN_` entries for pre-classified | review_queue.jsonl | `output/worker_X.md` |
| `deepdive` | Full entries for all triage-only functions | analyzed/ files | `output/worker_X.md` |
| `cross_validate` | Audit docs/17–21 entries vs .c source | 4,121 entries | `output/cross_validate/` |
| `struct_synth` | Consolidate struct offsets into docs/13 | 18 doc files | `output/struct_synth/` |
| `global_sweep` | Compile 855 globals into comprehensive docs/12 | 855 globals | `output/global_sweep/` |
| `stub_upgrade` | Upgrade table-row stubs to `### FUN_` entries | stubs w/ .c source | `output/stub_upgrade/` |
| `arch_narrative` | Prose architecture overviews for docs/17–21 | 5 doc files | `output/arch_narrative/` |
| `impl_spec` | Per-system reimplementation specs | 18 items (docs/01–10, 17–21; large docs auto-split) | `output/impl_spec/` |
| `call_chain` | End-to-end call chain traces from seed functions | 236 seeds (callee≥3, caller≤5) | `output/call_chain/` |
| `orphan_resolve` | Classify 271 orphan functions (vtable/callback/etc.) | orphan functions | `output/orphan_resolve/` |
| `ida_gaps` | Document IDA-only functions with Hex-Rays .c files | IDA-only ≥32B with .c in analyzed/ | `output/ida_gaps/` |

New modes use per-mode output directories: `output/<mode_id>/worker_X.md` and `prompts/<mode_id>/worker_X_prompt.md`.

**Adding a new mode:**
1. Write `PROMPT_<MODE>` template string
2. Write `get_<mode>_items()` → list of item dicts
3. Write `build_prompt_<mode>(letter, bucket, n, start)` → str
4. Add to `_generate()` dispatch dict and `_refresh_stats()` in GUI class

## Work Assignment

Two active plans: `work/PLAN_recreation.md` and `work/PLAN_hardening.md`.

**Completed phases (recreation):** cross_validate → struct_synth + global_sweep → stub_upgrade → arch_narrative → impl_spec → call_chain.

**Completed phases (hardening):**
- Phase 0 (partial): binary gap audit → 45 new functions found+documented
- Phase 3: orphan_resolve → 378 classified, 14 new entries, 83 duplicates  
- Phase 5: call edge completeness → +6,208 edges from .c text scan
- IDA integration: +8,216 IDA xrefs, 4 giant-gap functions decompiled+documented
- Total edges: 8,299 → 16,408; orphans: 1,399 → 271

**Remaining hardening work (from PLAN_hardening.md):**
- Phase 0 remainder: 143 MEDIUM candidates need re-evaluation
- Phase 1: struct_audit launcher mode — not built
- Phase 2: global_validate launcher mode — not built  
- Phase 4: runtime validation (process-attach) — not started
- Phase 6: inlined function recovery — research phase

**IDA workflow (for adding more functions):**
1. Run `tools/run_ida_export.bat` — rewrites all ida_*.csv + decompiles any new gap addresses in `tools/ida_export_all.py`
2. Run `python tools/ida_diff_and_import.py` — diffs vs Ghidra, appends new edges
3. Run batch GUI → IDA Gaps mode → DS workers → `2_merge.bat`

**Run any phase** using DS workers via `analysis_pipeline/1_batch_gui.bat`.

## IDA Pro Integration

**Install:** `C:\Program Files\IDA Professional 9.1` — `idat.exe` for 32-bit headless.
**Database:** Split format at `%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe.id0/.id1/.nam/.til`
**No RTTI** in binary (`/GR-`) — IDA/Ghidra vtable scan yields 0 results. **BUT vtables recovered by byte-scan of `.rdata`:** `tools/extract_vtables.py` → `work/vtables.csv` (181 vtables, 3,202 method slots, 72% resolve to known funcs). See `docs/36-vtables.md`. Class names mostly still open; slot mapping via `call [reg+N]` sites remains manual.
**FLIRT matches (only 4):** `_AIL_shutdown` (Miles), `__alloca_probe`, `___CxxFrameHandler`, `__WSAFDIsSet`.

**Headless run (reuse existing DB):**
```powershell
& "C:\Program Files\IDA Professional 9.1\idat.exe" -A -B "-SC:\path\to\script.py" "%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
```
Note: use `-c` flag only for first run (creates DB). Omit `-c` for subsequent runs (reuses existing DB, much faster).
Note: run from PowerShell with `&` prefix, NOT from bash/cmd (async subprocess issue swallows output).

**IDA vs Ghidra function counts:**
- Ghidra: 6,772 (including 45 manually created)
- IDA: 6,170 (fewer — IDA more conservative about splitting)
- IDA-only (in game range, ≥8B): 491 unique addresses, 451 documented via DS workers
- Gap at `0x0047fc54` (22KB): neither found — likely data table embedded in .text

**IDA v2 comprehensive export** (`tools/ida_export_all.py`):
- `ida_functions.csv` — 6,170 functions with flags, calling convention, type signatures
- `ida_xrefs.csv` — 14,223 code call edges
- `ida_data_xrefs.csv` — **17,037 global references** (7,990 unique addresses, 3,150 functions)
- `ida_switches.csv` — 286 jump/switch tables with targets
- `ida_exceptions.csv` — 98 exception-handling functions (SEH/C++)
- `ida_gaps.csv` — 3,778 .text gaps (852 possible code/data regions)
- `ida_strings.csv` — 5,434 strings with referencing functions
- `ida_imports.csv` — 246 DLL imports with caller lists
- `ida_segments.csv` — 8 PE segments with permissions
- `tools/decompiled_ida/` — 495 Hex-Rays decompiled .c files (IDA-only functions)
- `tools/ida_undocumented_globals.csv` — 7,195 globals not in docs/12 (ranked by ref count)
- `tools/ida_global_validation.csv` — 795 globals cross-validated (IDA + docs/12)

**Physics state block (discovered via IDA gap functions):**
- `0x8D0000–0x8D9000` = dynamics constraint solver matrix workspace
- `FUN_00579ccf` zeroes it (memset pattern)
- `FUN_00575bbd` factorizes it (LDL^T/Cholesky, 13KB)
- `FUN_0056fa96` does block sparse LDL^T on index arrays (17KB)
- `FUN_00578f76` initializes individual blocks to identity (34 cases, vehicle skeleton nodes)

## Known Pitfalls (learned 2026-07-15)

- **Non-FUN_ headers**: DS workers sometimes write `## Unwind_XXXXXX`, `## thunk_FUN_...`,
  `## AVIFileRelease` etc. instead of `## FUN_XXXXXXXX`. merge_to_docs.py only splits on
  `## FUN_` — these break routing. Fix: `PROMPT_DEEPDIVE` rule 11 enforces `## FUN_` always.
  Recovery script: sed `s/Unwind_\([0-9a-f]*\)/FUN_\1/` or use the Python normalizer written
  in the 2026-07-15 session.

- **Double .md extension**: Workers occasionally write `<!-- target: docs/20-math-utilities.md.md -->`.
  merge_to_docs.py skips these. Fix before merging: `sed 's/\.md\.md/.md/g' worker_X.md`.

- **Stalled workers**: Check entry count vs expected. If <<193, worker hit context limit.
  Generate resume prompt: extract assigned paths from `prompts/worker_X_prompt.md`,
  diff against written `## FUN_` headers, write new prompt for remaining functions only.

## Rules

- Never re-document an address already in `docs/` — check for `## FUN_XXXXXX` header first
- `work/QUEUE.md` is the single source of truth for what's next
- Never accept "all physics" verdicts without sampling at least 10 files
- Duplicate detection in merge_to_docs.py checks `## FUN_` headers only — not mentions in Calls/Globals sections
