# Doc Anchors — canonical section index for skill authors

Generated 2026-07-18. Anchors verbatim; re-harvest if canonical docs restructure.

Skill authors may cite canonical-doc sections ONLY from this file. Every anchor
below is an exact, existing heading (level shown by `#` count). Cite as
`path §Heading` in skill footers. Where a CATALOG shorthand differs from the
real heading (e.g. "§Primitives"), the real heading is what must resolve.

---

## Anchors

### CLAUDE.md

| Anchor | What's in it |
|---|---|
| `# CLAUDE.md` | Project one-paragraph identity: F1C exe, 6,868 functions, ARCHITECT role, Python path |
| `## Iron rules` | The 7 numbered iron rules (trust tiers, investigate.py-first, mods ledger-first, preflight facts, strategy ladder, read-back logging, never re-document) |
| `## Everyday commands` | 6 copy-paste commands: investigate find/dossier, poke read, preflight run, 2_merge.bat, graph rebuild |
| `## Key pointers` | Need→Where table (REFERENCE.md, INDEX.md, mods ledger, playbook, docs/12/13/35, HANDOFF) + key-globals cheat line |

### INDEX.md

| Anchor | What's in it |
|---|---|
| `# INDEX — Start Here` | Entry-point declaration: read this first, then CLAUDE.md |
| `## What this project is` | RE-complete/modding-frontier framing + cross-binary port map summary (2,357 sibling-exclusive funcs, docs/40-43, docs/32) |
| `## Trust tiers — READ THIS BEFORE TRUSTING ANY FILE` | THE trust-tier table (FACT/CONFIRMED/DERIVED/GUESS/LEAD/SCRATCH) — quoted verbatim below |
| `## Repo map (current layout)` | Path→Role→Trust table for every top-level dir |
| `## Common tasks → where to start` | "I want to…"→"Start here" routing table (mod, patch-point, source atlas, vtables, fp-constants, investigate) |
| `## Key facts a fresh LLM needs` | Exe path + ImageBase 0x400000 no-ASLR, Python path, IDA path, MSVC 6.0 `/GR-` thiscall/ret-N, sibling binaries |

#### Trust-tier definitions (INDEX.md §Trust tiers — quoted verbatim)

> | Tier | What | Where | Rule |
> |------|------|-------|------|
> | **FACT** | Raw decompiled `.c` source | `decompiled_all/`, `analysis_pipeline/analyzed/`, `tools/decompiled_ida/` | Ground truth. Trust over any doc. |
> | **FACT** | Bytes read from the exe | via `tools/mod_pipeline/` | Deterministic. The final arbiter. |
> | **CONFIRMED** | ISI class/function identity | `tools/cross_binary_final.csv` | Verified by NASCAR cross-match. |
> | **DERIVED** | IDA exports, graphs, CSVs | `tools/*.csv`, `knowledge_graph/` | Regenerable. Accurate but mechanical. |
> | **GUESS** | Global labels, struct offsets | `docs/12`, `docs/13*` | DS-worker inferred. Verify before relying. |
> | **LEAD** | Call chains, semantic names | `docs/31-call-chains/`, `docs/30-impl-specs/` | **May be hallucinated.** A chain (0008) mislabeled a network function as "track grip". Treat as a hint, confirm in source. |
> | **SCRATCH** | Chat logs, temp files | `ds.txt`, `opus_chat.txt`, `analysis_pipeline/_launch_*.ps1` | Historical. Do not treat as current. |
>
> **The one rule that prevents wasted work:** for anything precise (a mod, an offset,
> a value), confirm against FACT-tier raw source or an exe byte-read. Never act on a
> GUESS/LEAD label alone.

### MANIFEST.md

| Anchor | What's in it |
|---|---|
| `# MANIFEST — Every Top-Level Item` | Scope statement: complete root inventory, trust per INDEX.md |
| `## Directories` | Item/Files/Purpose/Trust/Regenerable table for every top-level dir |
| `## Loose root files (after Phase 1)` | The few files allowed at repo root |
| `## Phase 1 moves completed (nothing deleted)` | From→To table of the reorg moves (driver*.bin, strings_raw.txt, chat logs, scratch) |
| `## Notes` | "Nothing is deleted during reorganization"; Phase-3 deferral of path-referenced moves |

### REFERENCE.md (read sections on demand — do not load whole file)

| Anchor | What's in it |
|---|---|
| `# REFERENCE.md — Full Project Reference` | Charter: CLAUDE.md = iron rules, everything else here |
| `## Project Overview` | Binary stats, ARCHITECT role definition |
| `## LLM Role System` | Worker (DS V4 Flash) / Lead (GLM-5.2) / Architect (Claude) table → roles/*.md |
| `## Directory Layout` | Full annotated tree: docs/, analysis_pipeline/, source_recovery/, cross_binary/, work/ merge scripts, tools/, scripts/ |
| `## Modding Toolchain — START HERE for mods` | STEP 0 = mods/_README.md; the 6 tools (gen_sdk, poke, patch, gen_hook, port, param) with command examples |
| `## Bug Investigation — START HERE` | investigate.py doctrine: system/mod → find/global/uses → dossier; offset-table auto-decode; "build the offset table ONCE" rule |
| `## Key Commands` | Batch GUI, merge variants, graph rebuild, query.py, worker completion check, sed fixes, merge_*.py |
| `## Parallel Worker Workflow` | Worker output format (`=== TRIAGE LINES ===` / `=== FULL ENTRIES ===`, `<!-- target: -->`), launch steps, stalled-worker recovery snippet |
| `## Knowledge Graph` | The 9 graph JSON files, rebuild command, current graph stats |
| `## Source Data` | decompiled_all vs decompiled_full; filename convention `0x00XXXXXX__FUN_00XXXXXX.c`; assert path `D:\dev\F1_1999_2002\Source\` |
| `## Documentation Output (docs/)` | Per-doc content map incl. docs/34-37; current state metrics; remaining quality gaps |
| `## Doc Entry Formats` | Full `## FUN_` entry template, lightweight `### FUN_` template, triage-line format + categories |
| `## Ghidra Pseudocode Patterns` | Pattern→meaning table (idx×4, DAT_, unaff_EBX, thunk_, goto chains) + DirectX +0x1130/0x1132 false positive |
| `## Skip Patterns (no doc entry needed)` | zlib/CPUID/DirectX/BINK/CRT/NetComm/UI string signatures |
| `## Key Globals (subset — full list in docs/12-globals-reference.md)` | 14-row address→name cheat table |
| `## Verification Methodology (Architect role)` | 30s fast check, 2min full check, red-flag list, `[CORRECTION]` rule |
| `## Batch Launcher Modes` | Mode table (triage/review/deepdive/cross_validate/…/ida_gaps) + "Adding a new mode" recipe |
| `## Work Assignment` | Completed/remaining phases across PLAN_recreation + PLAN_hardening; IDA workflow |
| `## IDA Pro Integration` | idat.exe headless invocation (PowerShell-only), DB paths, no-RTTI note, byte-scanned vtables, ida_*.csv inventory, physics state block |
| `## Known Pitfalls (learned 2026-07-15)` | Non-FUN_ headers, double `.md.md`, stalled-worker symptoms + fixes |
| `## Rules` | Never re-document; QUEUE.md is source of truth; never accept "all physics" without sampling ≥10 files |

Note: CATALOG shorthand "REFERENCE.md §Knowledge Graph / §Key Commands / §Batch
Launcher Modes / §Parallel Worker Workflow / §Known Pitfalls / §Verification
Methodology / §Rules" all resolve to the exact headings above. There is no
section literally named "§Bug Investigation" — the real heading is
`## Bug Investigation — START HERE`. There is no "§gotchas" in REFERENCE.md —
that is MODDING_PLAYBOOK's `## Gotchas learned the hard way`.

### tools/mod_pipeline/MODDING_PLAYBOOK.md

| Anchor | What's in it |
|---|---|
| `# F1C Modding Playbook` | "Read this before attempting any behavioral mod"; Python + exe paths |
| `## Iron rules (violate these and you break the game)` | 5 rules: trust FACT only, never modify original exe, verify original bytes, check stack balance, Frida first / bake second |
| `## The process` | 7-step process container (h3 steps below) |
| `### 1. Name the behavior, find the anchor` | Config-word / penalty-string / physics-global anchor hunting |
| `### 2. Map who touches it` | `mod_pipeline.py map seeds/<name>.json` — player-path vs AI-path split |
| `### 3. Resolve the exact functions (replaces reading 5 .c files by hand)` | `asm_tools.py resolve` — ISI identity, strings, callers, `ret imm` |
| `### 4. Plan the change` | Three mod archetypes: redirect a call, flip a constant, force a branch |
| `### 5. Redirect a call (the common case — replaces all hand-disassembly)` | `asm_tools.py redirect` — E8 sites, retarget bytes, stack delta, `--at` scoping |
| `### 6. Verify + apply to a copy` | apply_*.py pattern: `(VA, expected_original_hex, new_hex, note)` edits, abort on mismatch, write COPY, emit Frida twin |
| `### 7. Test in-game` | Predict the exact observable; failed prediction = doc oversimplification, go back to raw source |
| `## Worked example (fully reproducible with the tools)` | cut_track_dq end-to-end: the two asm_tools commands + resulting 3 byte edits + "In-game confirmed" |
| `## Gotchas learned the hard way` | thiscall ECX, shared handlers → redirect the CALL SITE, MSVC `ret N` cleanup, copy-protection → Frida memory patch, severity threshold `_DAT_005acb30` |

### mods/_README.md

| Anchor | What's in it |
|---|---|
| `# mods/ — Shipped Game Mods` | "READ THIS FILE BEFORE STARTING ANY MOD"; nearest existing mod is the fastest start |
| `## Current contents` | **THE MOD LEDGER TABLE** (Mod / What / Status): ai_pit_retire LOG-CONFIRMED ONLY, red-flag-dll, replay-ai-fix NO WORKING PATCH YET, safety_car v3 UNTESTED |
| `## Related (not yet consolidated here)` | cut_track_dq (in-game confirmed, lives in tools/mod_pipeline/mods/) + ai_drying (WATCH-validated) |
| `## Reusable primitives (copy these, don't re-derive)` | **THE PRIMITIVES SECTION** — hotkey tick DLL skeleton, vehicle iteration (array/count/player-skip/stride), race gate, confirmed vehicle-struct writes, non-ASLR note. CATALOG's "§Primitives" resolves HERE. |
| `## The strategy ladder (why mods fail)` | **THE STRATEGY LADDER** — 5 rungs (data file → memory write → byte redirect → vtable swap → detour); "no working mod calls a game function from injected code"; poke-prove before any C |
| `## How mods are made` | Pointer to MODDING_PLAYBOOK; every mod ships apply_*.py + Frida .js |

### roles/ARCHITECT.md

| Anchor | What's in it |
|---|---|
| `# ARCHITECT — Claude` | Role charter: quality gate, does NOT write docs or triage |
| `## RESPONSIBILITIES` | Container for the 5 numbered duties |
| `### 1. Audit coverage` | audit_full.py before/after every Lead session — **STALE: audit_full.py was deleted from repo root 2026-07** |
| `### 2. Quality-verify Lead output` | Sample 5–10 entries, cross-check .c, flag `[CORRECTION]`; spot-check targets |
| `### 3. Audit Worker triage output` | Sample 10 `needs_deep_analysis: false` entries, read the .c |
| `### 4. Maintain work/QUEUE.md` | Queue update duties after audit |
| `### 5. Catch stale claims` | Patterns: "all X documented", evidence-free "verified as physics", typeless offsets, duplicates |
| `## AUDIT SCRIPT` | audit_full.py invocation + expected output (**stale, script deleted**) |
| `## VERIFICATION METHODOLOGY` | Fast/full check + red-flags (same doctrine as REFERENCE.md §Verification Methodology) |
| `## KNOWN PROJECT STATE (2026-07-14, verified)` | Historical counts (superseded by REFERENCE.md current state) |
| `## ASSIGNING WORK` | How to brief Worker vs Lead; priority Python snippet |
| `## RULES` | 6 rules incl. always `[CORRECTION]`, QUEUE.md single source of truth, delegate doc-writing |

### roles/LEAD.md

| Anchor | What's in it |
|---|---|
| `# LEAD — GLM-5.2` | Doc-writer role; authorized to act as Architect if Claude unavailable |
| `## YOUR TASK` | Two phases: `### Phase 1: Undocumented decompiled_all functions`, `### Phase 2: Flagged decompiled_full functions` |
| `## DOCS FILE MAPPING` | docs/01–16 routing table |
| `## DOCUMENTATION FORMAT` | The mandatory `## FUN_` entry template |
| `## CROSS-REFERENCING — MANDATORY` | "Calls FUN_… (per docs/NN)" linking idioms |
| `## WHAT TO SKIP (no doc entry needed)` | Library-string skip table |
| `## READING GHIDRA PSEUDOCODE` | Pattern glossary + DirectX false-positive warning |
| `## KNOWN CONTEXT (reference — do not re-document)` | Pre-read list docs/02–16 |
| `## RULES` | 7 rules incl. never re-document, CHANGELOG line per function, speculation goes in "Notes" |

### roles/WORKER.md

| Anchor | What's in it |
|---|---|
| `# WORKER — DeepSeek V4` | Bulk doc agent + CRITICAL "WRITE TO DISK IMMEDIATELY" rule (one function = one disk write) |
| `## CONTEXT` | Corpus layout; "Never read from `analyzed/`"; no file moves |
| `## YOUR THREE WORK MODES` | `### Mode 1: Upgrade table-row entries (decompiled_all)`, `### Mode 2: Full documentation (decompiled_all gaps)`, `### Mode 3: Triage decompiled_full (6,116 anonymous functions)` |
| `## DOCS MAPPING — which file gets what` | docs/01–21 + master index routing table |
| `## CROSS-REFERENCING — REQUIRED` | Linking idioms |
| `## STEP 0 — GET YOUR WORK LIST` | Queue-file assignment |
| `## GHIDRA PSEUDOCODE PATTERNS` | Pattern glossary |
| `## GLOBALS TABLE — flag any of these when seen` | ~50-row known-globals table (GUESS-era snapshot; docs/12 is current) |
| `## STRUCT OFFSETS TABLE — vehicle/AI struct` | ~35-row vehicle-struct offset table + DirectX false-positive warning |
| `## WHAT TO SKIP (no doc entry needed)` | Skip-string table |
| `## AFTER YOU FINISH` | CHANGELOG session-entry template |
| `## RULES` | 10 rules incl. rule 0 never move files, rule 8 write-per-function, rule 9 no subagent summaries |

### analysis_pipeline/_README.md

| Anchor | What's in it |
|---|---|
| `# analysis_pipeline/ — DS-Worker Documentation Pipeline` | What the batch system is |
| `## What matters here` | Path/Purpose/Trust table (analyzed/ = FACT corpus; batch_launcher; merge; output/; prompts/) |
| `## Scratch / historical (safe to ignore — being archived per PLAN_reorg)` | One-off run artifacts list |
| `## Path warning` | analyzed/ and output/ are hardcoded paths — do not move |

### tools/_README.md

| Anchor | What's in it |
|---|---|
| `# tools/ — Scripts + Derived Data` | Code + DERIVED CSVs coexist; CSV paths hardcoded |
| `## Subdirectories` | mod_pipeline / trace / knowledge_graph / decompiled_ida (FACT) |
| `## Key data files (DERIVED — regenerable via ida_export_all.py)` | ida_*.csv + cross_binary_final.csv (CONFIRMED) inventory |
| `## Key scripts` | ida_export_all, cross_binary_match, parse_struct_dump |

### tools/mod_pipeline/README.md

| Anchor | What's in it |
|---|---|
| `# F1C Mod Investigation Pipeline` | 4-stage "understand X then change it" flow |
| `## Start here` | Playbook-first rule + asm_tools resolve/redirect one-liners |
| `## Stages` | SEED / MAP / WATCH / PATCH command + output table |
| `## Seed spec format` | seeds/<name>.json schema (globals, seeds, ranges, struct_watches, watch_hz) |
| `## Trust tiers (baked into every dossier)` | FACT/GUESS/LEAD/CONFIRMED as they appear in dossiers; the `0059e450` = 0.5 mislabel catch |
| `## Data sources (pre-existing)` | ida_data_xrefs, cross_binary_final, callers.json, analyzed/*.c |
| `## Workflow` | 5-step observable→anchor→map→watch→patch loop |
| `## Validated case: ai_drying` | `AI_grip = 1.0 - mean(OnPathWetness, OffPathWetness)`; FUN_00404460; dossier pointer |

### cross_binary/_README.md

| Anchor | What's in it |
|---|---|
| `# cross_binary — isiMotor1 family DELTA finder` | Self-contained workspace; workers only ever see the NOVEL delta |
| `## Goal (corrected framing)` | dedup / novel / gap-fill definitions — NOT "read every sibling" |
| `## Pipeline` | export → fingerprint → xbin_match → delta → DS workers (tokens only at the end) |
| `## Matching signals (xbin_match.py)` | Verdict table BYTE_EXACT / BYTE_MASK / STRING / NOVEL + the E8/E9 rel32 mask explanation |
| `## Validation (correctness gate — PASSED)` | 3,614 matched with masking vs 1,351 without — "Masking is the reason the gate passes. Do not remove it." |
| `## Current status` | Per-sibling match table; SCGT excluded (compiler gap); rFactor excluded (isiMotor2); unified delta 206 triple-confirmed |
| `## TODO / known gaps` | STRING signal inert; gap-fill pass unbuilt; 3DConfig debug-residue pass |
| `## Files` | scripts/_fingerprints/_delta/_decomp layout |

### cross_binary/WORKER_DELTA.md

| Anchor | What's in it |
|---|---|
| `# WORKER — Cross-Binary Delta Documentation (DeepSeek V4)` | Role: document sibling-only functions ("bricks F1C is missing") |
| `## HARD RULES — violating any of these breaks the merge. Read twice.` | 7 rules: write only to worker file, one-function-one-write, no subagents, header exactly `## sub_XXXXXXXX`, target comment exactly one `.md` |
| `## SOURCE FORMAT — IDA Hex-Rays (not Ghidra)` | sub_/dword_/a2-v5/`operator new(0xNN)` glossary |
| `## OUTPUT FILE STRUCTURE` | TRIAGE LINES / FULL ENTRIES layout with docs/40-43 routing + triage categories + Port enum |
| `## GOLD-STANDARD EXAMPLE — copy this shape exactly` | Full NASCAR caution-state-machine entry (sub_004c9a50) as the depth benchmark |

### source_recovery/README.md

| Anchor | What's in it |
|---|---|
| `# Source Recovery — F1 Challenge 99-02` | Isolation charter: "nothing in this directory writes to `docs/` or `analysis_pipeline/`" |
| `## Directory Map` | 01_binary_forensics … 06_community_sources + binaries/ layout |
| `## Relationship to Other Directories` | Reads-from / never-writes-to table |
| `## How Results Flow Out` | FINDINGS.md → `[MERGE-READY]` tag → separate merge session → work/CHANGELOG.md |

### source_recovery/ACTION_PLAN.md

| Anchor | What's in it |
|---|---|
| `# Source Recovery — Action Plan` | Master task list; statuses TODO/ACTIVE/DONE/BLOCKED |
| `## Phase 1: Binary Forensics (F1C exe only, no downloads needed)` | BF-01…BF-05 (all DONE 2026-07-16): Rich header, RTTI scan, PDB path, string forensics, import/export |
| `## Phase 2: Cross-Binary Analysis (requires downloads)` | CB-01…CB-07 inventory + per-binary analyses (rFactor + Poochihead still TODO) |
| `## Phase 3: rFactor SDK Cross-Reference` | SDK-01…SDK-04 (headers indexed; struct alignment / HW-control grep / phase-enum validation TODO) |
| `## Phase 4: DLL Modification Framework` | DLL-01…DLL-03 proxy-DLL plan (TODO) |
| `## Phase 5: Automated Trace Pipeline` | AT-01…AT-03 AHK + Frida orchestration (TODO) |
| `## Phase 6: Community Source Recovery` | CS-01…CS-03 F1CUI offsets, Wayback trawl, download catalog |
| `## Priority Order` | do-first/second/third/fourth/last ordering |
| `## Session Handoff Rules` | Status discipline; "No task modifies `docs/` directly. All doc changes go through `FINDINGS.md` -> `work/CHANGELOG.md` -> merge." |

### work/_README.md

| Anchor | What's in it |
|---|---|
| `# work/ — Planning, Merge Scripts, Working Data` | Three kinds of content, pending PLAN_reorg split |
| `## Plans & process (meta)` | PLAN_*.md, HANDOFF.md, QUEUE.md ("single source of what's next"), CHANGELOG.md, DISCOVERY/BREAKTHROUGH |
| `## Merge scripts (tooling — belong with pipeline)` | merge_*.py (15 files), absolute-path caveat |
| `## Working data (DERIVED)` | The 5 working CSVs |
| `## For an LLM` | Read QUEUE.md + CHANGELOG.md for status; PLAN_*.md for strategy |

### work/HANDOFF.md (top-level sections = handoff template basis)

Current instance is titled `# Session Handoff — 2026-07-16 (F1CUI Extraction + Binary Analysis Plan)`.
Its top-level `##` sections — the de-facto handoff template a new HANDOFF entry should mirror:

| Anchor | Template role |
|---|---|
| `## What Was Done This Session` | Completed work, per-workstream, with counts and output paths |
| `## Current State` | Metric table (functions, edges, globals, docs coverage) |
| `## What To Do Next: Binary Analysis` | Prioritized next steps (Priority 1…7) — the "Next" part of the title varies per session |
| `## Key Commands` | Copy-paste commands the next session will need |
| `## IDA Pro Reference` | Tool paths + invocation (session-specific reference block) |
| `## Data Files Reference` | File → records → purpose table |
| `## Frida Trace Technical Notes` | Session-specific technical gotchas |
| `## Globals Tracked by State Agent` | Session-specific data appendix |
| `## Binary Comparison Targets` | Session-specific data appendix |

Generic template skeleton: **state → completed → metrics → prioritized next steps →
commands/reference appendices**. Newer per-topic handoffs (e.g.
`work/HANDOFF_2026-07-17_data-retrieval.md`) follow the same shape.

### work/BREAKTHROUGH_trace_mining.md

(Truncated sibling of DISCOVERY_external_sources.md — file ends inside Discovery 2; Discovery 3 and later sections exist only in the DISCOVERY file.)

| Anchor | What's in it |
|---|---|
| `# BREAKTHROUGH: Untapped External Sources — Trace Mining, Community Prior Art, Engine Family` | Status header: "Priority: #1 — supersedes all other pending work" |
| `## Executive Summary` | The 3 untapped sources in one screen |
| `## Discovery 1: Built-In Trace Logging (THE BIG ONE)` | Container for the trace-system evidence |
| `### Evidence` | Verbatim LOG/trace.txt sample (original .cpp/line/Class::Method) |
| `### Binary-side confirmation` | `trace=%d` / `notrace` command-line params in strings_raw.txt |
| `### The logging machinery in our docs (misidentified)` | FUN_004d7a50 (level gate) + FUN_004d7aa0 (trace printf); every call site = (file, line, message) triple |
| `### What this unlocks` | Mass renaming, line-accurate source reconstruction, real-name runtime narrative, log↔address mapping |
| `### Exact mining procedure (static, no game launch needed for step 1)` | 4-step ida_strings.csv mining recipe |
| `### Runtime procedure (after static mining)` | Find max level → launch `trace=99` → capture; **WARNING: LOG/trace.txt overwritten per run — archive first** |
| `## Discovery 2: Community Prior Art In The Install Folder` | inject.exe/Lua, F1CUILive.jar, SteeringWheel.dll, LOG/ inventory (file truncates inside this section) |

### work/DISCOVERY_external_sources.md

| Anchor | What's in it |
|---|---|
| `# DISCOVERY — Untapped External Sources (2026-07-16)` | Status MAJOR; read before any more static analysis |
| `## TL;DR` | Three sources in three bullets |
| `## SOURCE 1 — The game's own debug trace system` | (h3s: `### What it is`, `### Location on disk`, `### The trace strings are ALREADY in our data — with function addresses`, `### The .cpp file strings map source files to function CLUSTERS`, `### The trace-level control mechanism (how to turn it up)`, `### How to exploit — concrete steps (highest value work in the project)`, `### Why this is a gamechanger`) — 60 `Entered X::Y()` → address pairs; FUN_004d7960 init, FUN_004d7a00 cmdline parse, FUN_004d7a50/FUN_004d7aa0 emit |
| `## SOURCE 2 — Community RE work already present in the install` | (h3s: `### Inventory (in \`%USERPROFILE%\Desktop\F1 Challenge V10\`)`, `### Note from memory (already known, connect the dots)`, `### How to exploit`) — offset cross-validation from community plugins |
| `## SOURCE 3 — ISI gMotor engine-family Rosetta stone` | (h3s: `### The lineage`, `### Shared/near-identical file formats`, `### Evidence in our own data`, `### How to exploit`) — rFactor format specs as field-name hypotheses, "Confirm, then document" caveat |
| `## Revised project assessment` | (h3s: `### Revised priority order (supersedes HANDOFF "What To Do Next")`, `### Data pointers for whoever picks this up`) |
| `## One-paragraph summary for a fresh model` | Self-contained briefing paragraph |

### docs/_README.md

| Anchor | What's in it |
|---|---|
| `# docs/ — Documentation (mixed trust)` | "Trust varies per file — the biggest clarity trap in the repo" |
| `## Trust map` | Per-doc-file trust table (docs/12+13 = GUESS; docs/30+31 = LEAD w/ hallucination warning; docs/27 = CONFIRMED; docs/34-37 = FACT-data + DERIVED-attribution) |
| `## Rule` | "a doc is a lead, the raw `.c` … is the truth. When they disagree, the source wins." + asm_tools resolve pointer |

---

## Correction corpus

10 representative `[CORRECTION]` entries from `work/CHANGELOG.md`, verbatim, with
line number (as of 2026-07-18) and error class. Historical snapshot — cite the
class and pattern, not the line number, in skills.

1. **Float-vs-int type error** (line 298):
   > [CORRECTION] docs/12 TotalRaceLaps (DAT_008acf9c): stored as **IEEE 754 float**, not int32. Raw value 1093926912 = float(12.0). Previous docs treated as integer.

2. **Enum misread — wrong phase name** (line 299):
   > [CORRECTION] docs/15 RacePhase sequence: noplayer race goes 0(IDLE)->2(GRID)->4(PACE)->5(GREEN)->8(FINISHED). Phases 1(FORMATION), 3, 6, 7 skipped in noplayer. Phase 5 = GREEN FLAG (not RED_FLAG as previously guessed).

3. **Wrong name, corrected by trace string** (line 322):
   > [CORRECTION] docs/01 Game::Setup: FUN_004d36d0 was labeled "sound" — actually Steward::Setup (confirmed by "Entered Steward::Setup()" string at that address)

4. **Wrong name, corrected by trace string — invented class** (line 323):
   > [CORRECTION] docs/01 Game::Restart: FUN_004d3cf0 was labeled "Session" — actually Steward::Restart (confirmed by trace string). No "Session" class exists.

5. **Formula sign error** (line 343):
   > - `[CORRECTION] FUN_004E513E: formula sign error — source negates input before subtraction (docs/06)`

6. **Struct offset error** (line 344):
   > - `[CORRECTION] FUN_0052DE60: frame size reads +0x24cc not +0x2494 (docs/06)`

7. **Clamp value error** (line 347):
   > - `[CORRECTION] FUN_00442060: clamp value wrong — source writes ±1.549 rad not ±0.22 rad (docs/10)`

8. **Miscategorization — wrong subsystem entirely** (line 349):
   > - `[CORRECTION] FUN_0044F5F0: miscategorized as collision — actually CursorCleanup (DestroyCursor loop) (docs/17)`

9. **Semantic field misread** (line 402):
   > - `[CORRECTION] FUN_00454DA0: "clutch" at 0x1c54 should be "handbrake" (docs/02)`

10. **Int-index vs byte-offset confusion** (line 2085):
    > - `[CORRECTION] FUN_004E3AA0: struct offset table uses float* indices (0x06, 0x0e) instead of correct byte offsets (0x0c, 0x18) — already flagged in docs/13-audit-report (docs/18)`

Additional patterns worth knowing (not part of the 10): bulk audit shorthand
tags exist en masse (`WRONG_MODDABILITY`, `MISSING_GLOBAL`, `WRONG_CONST`,
`MISSING_ENTRY` — CHANGELOG ~lines 1486–1663 and 2133–2210), and one
**stale-ledger correction** at lines 2500–2503 (quoted in full in the
postmortems section below) documents a mod's status being overstated in
`mods/_README.md` itself.

---

## Failed-mod postmortems (historical snapshot 2026-07)

Verbatim quotes with sources, for `f1c-debug-failed-mod` case studies. These are
frozen pedagogy — the live status lives ONLY in the `mods/_README.md` ledger.

### Case 1 — safety_car v3: GUESS offset in the chain, never live-probed

`mods/_README.md` §Current contents (ledger row, verbatim):

> | `safety_car/` | **Safety car deployment via oph.dll** — two-layer speed governor (SafetyCarFollow flag + liveLapRatio clamp), AI cmd 0xe queue injection, auto-deploy on DNF, manual hotkeys (NUM8/2/5) | **v3 UNTESTED** — built on v2 prototype (`analysis_pipeline/work/oph/`). Speed offset 0x453C is GUESS tier; run NUM5 probe to verify. Plan: `plans/investigate-and-figure-out-imperative-llama.md` |

`mods/safety_car/README.md` — status header:

> ## Status: TESTING REQUIRED
>
> v3 adds speed governor and probe diagnostics but key offsets are GUESS tier.
> Run the probe (NUM5 in-game) and check `LOG\safety_car.txt` before trusting
> speed control.

`mods/safety_car/README.md` §Known Limitations (first bullet):

> - Speed governor offset (0x453C) is GUESS tier — may need adjustment

`mods/safety_car/README.md` — the falsification criterion (end of §Phase 1 Verification Checklist):

> If `live_lap_ratio` shows garbage (very large/small numbers, NaN), the
> byte offset 0x453C is wrong — consult the probe raw bytes dump to find
> the actual location.

Lesson tag: a whole DLL was built on top of an unverified GUESS-tier offset.
Preflight-per-fact (CLAUDE.md rule 4) would have gated this before any C.

### Case 2 — replay-ai-fix: three failed attempts + a stale-ledger correction

`mods/replay-ai-fix/apply_replay_ai_fix.py` module docstring (verbatim):

> Bugfix: AI simplified driving after instant replay.
>
> STATUS: NO WORKING PATCH YET — see docs/28-known-bugs.md for full analysis.
>
> Root cause: FUN_004ef5a0 (Vehicle State Setter) has an InternalState != 5 gate
> at VA 0x004ef623 that returns early, preventing AI_ENABLE from firing during
> replay exit when InternalState hasn't reached RACING (5). Mid-race replays work
> fine; early replays (during formation/lights) leave AI in simplified mode.
>
> Three patch attempts failed:
>   1. Save offset change → grid bunching
>   2. Phase 5→3 comparison → timer delay too long for short tracks
>   3. NOP jne in backup enable → timer delay still present
>
> Proposed fix (not yet validated): NOP the InternalState gate in FUN_004ef5a0
> at VA 0x004ef62a (75 46 → 90 90). Risk: may break formation driving during
> normal game startup since 0→1 transition also passes through this path.

`mods/_README.md` §Current contents (ledger row, verbatim):

> | `replay-ai-fix/` | Bugfix attempt: AI simplified driving after instant replay | **NO WORKING PATCH YET** — 3 attempts failed; proposed fix unvalidated. See `docs/28-known-bugs.md` BUG-001 + `apply_replay_ai_fix.py` header |

`work/CHANGELOG.md` lines 2500–2503 — the stale-ledger correction (verbatim):

> [CORRECTION] mods/_README.md claimed replay-ai-fix = shipped "1-byte patch (GREEN_FLAG
> instead of FINISHING)". FALSE: apply_replay_ai_fix.py header says "NO WORKING PATCH YET";
> docs/28 BUG-001 records 3 failed attempts (grid bunching / timer delay / gate still blocks).
> mods/_README.md and docs/33 exec summary + byte-patch row corrected.

Lesson tag: the ledger itself once overstated a mod as shipped — "read the
ledger" means read it critically; the mod's own artifacts (apply script header,
bug doc) carry the ground truth.

### Case 3 — ai_pit_retire: "writes stick ≠ game reacts" (the log-confirmed-only trap)

`mods/_README.md` §Current contents (ledger row, verbatim):

> | `ai_pit_retire/` | **Press F8 in a race → every AI car pits + DNFs** (player untouched) | **LOG-CONFIRMED ONLY** — v3 log shows writes land (`retired 21 AI cars (count=22)`) but desired in-game outcome NOT confirmed by user. Writes stick ≠ game reacts. Run `tools/preflight.py` stability check on `veh+0x4064` next; suspect game logic never reads it, or reads a different field. |

`mods/ai_pit_retire/README.md` §Notes / limits (verbatim):

> - Hybrid design: cars are marked pitting + DNF in one shot; they do **not**
>   drive a full in-lap first. Scoring/standings show them as retired.
> - Non-ASLR binary (base 0x00400000) so absolute VAs are used directly.
> - Physics/AI may keep the car object alive visually until the game's own
>   retirement cleanup runs off FinishState. Verify in-game.

Lesson tag: a mod can log perfect read-backs and still not produce the
observable. Only an in-game observation upgrades a mod to confirmed. (Note:
one memory file calls this mod "already works"; the ledger's LOG-CONFIRMED
ONLY is the authoritative status.)

---

## cut_track_dq walkthrough

The one in-game-confirmed mod: cutting the track = instant DQ. The reference
implementation for `f1c-mod-lifecycle` and `f1c-byte-patch`. Sources:
`tools/mod_pipeline/MODDING_PLAYBOOK.md` §Worked example (fully reproducible with the tools)
and `tools/mod_pipeline/mods/cut_track_dq/` (apply_cut_track_dq.py + cut_track_dq.js).

### The worked-example steps (PLAYBOOK, verbatim commands)

```
# identify the DQ handler by its string
python asm_tools.py resolve 0x004bc0e0        # -> "Disqualified:", ret imm 4

# redirect the two cut-track penalty calls in the steward routine
python asm_tools.py redirect 0x004bccc0 0x004bbc60 0x004bc0e0 --at 0x004bd0c1  # warning->DQ, delta 0
python asm_tools.py redirect 0x004bccc0 0x004bbd60 0x004bc0e0 --at 0x004bd0b3  # stopgo->DQ, delta 4 -> NOP push at 0x004bd0aa
```

Resulting edits (PLAYBOOK, verbatim):

```
0x004bd0aa  6a0a       -> 9090        NOP the stopgo `push 0xA`
0x004bd0b3  e8a8ecffff -> e828f0ffff  stopgo -> DQ
0x004bd0c1  e89aebffff -> e81af0ffff  warning -> DQ
```

Followed by: "In-game confirmed: any registered cut now disqualifies."

Process shape (maps 1:1 onto PLAYBOOK `## The process` steps 1–7):
1. Anchor by player-facing string ("Disqualified:") → handler FUN_004bc0e0.
2. `asm_tools.py resolve` gives identity + `ret imm 4` (arg count / stack cleanup).
3. `asm_tools.py redirect` per CALL SITE (`--at`), not per function — the
   warning/stopgo handlers are shared by many penalty types.
4. Non-zero stack delta (4) → tool pinpoints the exact `push` to NOP (0x004bd0aa).
5. Edits baked into an apply script (COPY) + a Frida twin (reversible, tested first).
6. Predicted observable: "cut a corner → instant DQ". User tests in-game.

### apply_cut_track_dq.py — EDITS anatomy

Header docstring states scope and safety: "Only these two call sites (the
cut-track branch) are touched; pit-speeding, blue-flag and wrong-way penalties
are unaffected." and "Writes a MODDED COPY; never modifies the original.
Verifies original bytes first."

The EDITS table (verbatim):

```python
# (VA, expected_original_hex, new_hex, note)
EDITS = [
    (0x004bd0aa, "6a0a",       "9090",       "NOP push 0xA (stopgo seconds)"),
    (0x004bd0b3, "e8a8ecffff", "e828f0ffff", "stopgo call -> DQ"),
    (0x004bd0c1, "e89aebffff", "e81af0ffff", "warning call -> DQ"),
]
```

Script structure (the pattern every apply_*.py must copy):
1. `SRC` = absolute path to the original exe; `IMAGE_BASE = 0x00400000`.
2. `sections(data)` — parse PE section table from raw bytes (no deps).
3. `va_to_fo(secs, va)` — VA → file offset via section mapping; error if unmapped.
4. **Verify + stage loop**: for every edit, read the bytes at the file offset and
   compare to `expected_original_hex`. On mismatch: print expected vs found,
   "Aborting — wrong exe version or already patched.", `sys.exit(1)`. No partial
   application — all edits verified before any write.
5. **Apply to copy**: patch the in-memory buffer, write to
   `F1 Challenge Online (CutTrackDQ).exe` beside the original. Original untouched.
   Rollback = delete the copy.

### cut_track_dq.js — the Frida twin

Same `EDITS` list (`{ va, orig, patch }`), applied to the running process:
`apply()` first verifies ALL original bytes via `readByteArray` (aborts on any
mismatch with "wrong version or already patched"), then `Memory.protect(p, n,
'rwx')` + `writeByteArray` per edit. Exposes `globalThis.restore()` writing the
original bytes back — in-session undo. Run: `frida -p <F1C pid> -l cut_track_dq.js`.
This is the "Frida first, bake second" rung of PLAYBOOK iron rule 5 made concrete.

---

## Harvest notes (for skill authors and re-harvesters)

- **All requested files exist.** `analysis_pipeline/_README.md` exists.
- **Anchor mismatches to watch:** CATALOG's "mods/_README.md §Primitives" →
  real heading is `## Reusable primitives (copy these, don't re-derive)`.
  CATALOG's "REFERENCE.md §Bug Investigation" → real heading is
  `## Bug Investigation — START HERE`. "MODDING_PLAYBOOK §gotchas" → real
  heading is `## Gotchas learned the hard way`.
- **roles/ARCHITECT.md is partially stale**: it mandates `python audit_full.py`
  but `audit_full.py` has been deleted from the repo root. Its §KNOWN PROJECT
  STATE is a 2026-07-14 snapshot superseded by REFERENCE.md. Cite it for
  method (verification, red flags, `[CORRECTION]` discipline), not for numbers
  or the audit script.
- **work/BREAKTHROUGH_trace_mining.md is a truncated near-duplicate** of
  work/DISCOVERY_external_sources.md (ends mid-sentence inside Discovery 2).
  Prefer DISCOVERY_external_sources.md for Sources 2–3 and the priority order;
  either file works for Discovery/Source 1 (trace mining).
- **work/HANDOFF.md heading titles are session-specific** (e.g. "What To Do
  Next: Binary Analysis"). Treat the section ROLES (state / completed / metrics
  / next steps / commands) as the template, not the literal titles.
- **CHANGELOG line numbers drift** — the file is append-heavy. Cite correction
  entries by their verbatim text or FUN_ address, never by line number.
