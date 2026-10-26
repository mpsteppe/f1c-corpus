# Implementation Plan — Source-Level Knowledge Recovery

**Status:** NOT STARTED. **Owner:** Architect assigns tracks; Worker (DS V4 Flash) and Lead (GLM-5.2) execute.
**Goal:** Recover real names (functions, structs, fields, source files) for the ~3,700 still-anonymous
functions in `F1 Challenge Online.exe`, using external-but-legitimate sources. We cannot obtain the
actual source code; we can triangulate it from siblings, SDKs, symbols, and signatures.

---

## Track priority (do in this order)

| # | Track | Yield | Effort | Who |
|---|-------|-------|--------|-----|
| A | rFactor plugin SDK struct mapping | HIGH | LOW | Lead |
| B | Exe-wide assert/string source map | HIGH | LOW | Worker |
| D | Console port symbol harvest (PS2/Xbox F1 2001/2002) | VERY HIGH if symbols exist | MEDIUM | Architect gate, then Worker |
| C | Sibling exe binary diffing | HIGH | MEDIUM | Architect (tooling) + Worker (consume) |
| E | Library signature matching (FID/FLIRT) | MEDIUM | LOW | Architect (one-time run) |
| F | Community artifact mining | MEDIUM | MEDIUM | Lead |
| G | Second-decompiler cross-check | MEDIUM | MEDIUM | Architect (tooling) + Worker |
| H | Game data archive sweep (.MAS leftovers) | LOW-MEDIUM | LOW | Worker |
| J | Unique-string web/GitHub search | LOW-MEDIUM | LOW | Lead |
| I | Runtime validation (ongoing) | confirmatory | ongoing | already in progress |

---

## Track A — rFactor Plugin SDK Struct Mapping

**Why:** rFactor 1 is the direct successor of F1C, same ISI team, same gMotor lineage. Its *public*
plugin SDK (`InternalsPlugin.hpp`, `PluginObjects.hpp`) contains real C++ struct definitions with
field names: `TelemInfoV2` (per-wheel rotation, tire temps in 3 layers, brake temp, suspension
deflection, ride height, engine RPM / water / oil temps, fuel, DRS-era fields absent), `TelemWheelV2`,
`VehicleScoringInfoV2`, `ScoringInfoV2`, `GraphicsInfoV2`. Field ordering and grouping is largely
inherited from the F1C-era codebase.

**Steps:**
1. Obtain the rFactor 1 plugin SDK headers (freely distributed with rFactor; also mirrored in many
   open-source rFactor plugin repos on GitHub, e.g. telemetry plugins that vendored the headers).
   Save to `reference/rf1_sdk/`.
2. Build a field table: for each struct, list `field name | C type | size | cumulative offset`.
   Write to `reference/rf1_sdk/field_offsets.md`.
3. Cross-match against `docs/13-struct-offsets.md` (F1C vehicle struct, tire block stride 0xF8,
   vehicle struct size 0x48C0 — see memory note). Matching heuristics:
   - Same type + same relative order within a cluster (e.g. 3 consecutive doubles = tire temp layers).
   - Known anchors: wear floor 0.75 clamp, RPM fields, per-wheel stride.
4. For every confident match, update `docs/13` field names with `(rf1: <FieldName>)` annotation.
   Do NOT overwrite existing verified names; append the rf1 name as corroboration.
5. Log ambiguous matches in `work/CHANGELOG.md` with prefix `[RF1-UNCERTAIN]` for Architect review.

**Output:** annotated `docs/13`, `reference/rf1_sdk/field_offsets.md`.
**Acceptance:** every annotation cites both the rf1 header line and the F1C evidence (function address
+ offset). No annotation without a Ghidra-side anchor.

---

## Track B — Exe-Wide Assert/String Source Map

**Why:** Assert strings embed `D:\dev\F1_1999_2002\Source\<file>.cpp` plus line numbers. Each assert
pins the *referencing function* to a real source file, and line numbers order functions within that
file. Note: the existing `strings_raw.txt` in repo root is NOT an exe dump (zero `D:\dev` hits) — must
re-extract from the exe itself.

**Steps:**
1. Extract all strings from the exe with addresses. In Ghidra: Window → Defined Strings → export CSV.
   Or script: `strings -t x -a "F1 Challenge Online.exe"` (Sysinternals/GNU strings, hex offsets).
2. Filter rows matching `\.cpp|\.h` and rows matching the `D:\dev` path prefix.
3. For each source-path string: find cross-references (Ghidra XRefs) → referencing function address.
4. Emit `reference/source_file_map.csv`: `FUN_address, source_file.cpp, assert_line, assert_text`.
5. Sort per source file by assert line number → produces the original function order inside each .cpp.
6. Worker pass: for each `## FUN_` entry in docs/ whose address appears in the map, update the
   `Source:` line from "likely X.cpp" to "confirmed X.cpp (assert line N)".
7. Bonus: functions with NO assert but sandwiched (by address) between two functions of the same .cpp
   are *probably* from that .cpp (MSVC mostly preserves compilation-unit ordering). Mark those
   `Source: probable X.cpp (address-locality)`.

**Output:** `reference/source_file_map.csv`, updated `Source:` lines in docs/.
**Acceptance:** spot-check 10 random rows — assert string must actually appear in the corresponding
decompiled .c file.

---

## Track C — Sibling Exe Binary Diffing

**Why:** F1 2002, F1 2001, F1 2000 (all EA/ISI, same codebase generations) and rFactor 1 share large
code regions with F1C. Any function identified in one binary names its twin in the others. Official
*demos* of these games are freely distributed and sufficient.

**Steps:**
1. Acquire legitimately: F1 2002 demo, F1 2001 demo, rFactor demo (all were official public demo downloads).
   Also every official F1C patch exe.
2. Import each into the Ghidra project as separate programs; run auto-analysis.
3. Diff tool options (pick per availability):
   - **Ghidra Version Tracking** (built in, no extra install) — run Exact Function Match,
     then Duplicate Function Match, then Combined Reference correlator.
   - **Diaphora** (needs IDA) or **BinDiff** (free, works with Ghidra via BinExport) — better fuzzy
     matching for compiler-version drift.
4. Export match tables: `reference/diff_f1c_vs_<target>.csv` with columns
   `F1C_addr, target_addr, similarity, confidence`.
5. Value extraction:
   - Functions documented in F1C → transfer to sibling (not our goal, skip).
   - Sibling demo builds sometimes contain MORE asserts / debug strings (demos built earlier, less
     stripped). For each F1C-anonymous function whose sibling twin has an assert path → inherit the
     source file attribution. Feed into Track B map with tag `via-diff`.
6. rFactor diff special case: rF exports plugin entry points with names; walk inward from those to
   name callback dispatch layers shared with F1C.

**Output:** per-target diff CSVs, additional rows in `reference/source_file_map.csv` tagged `via-diff`.
**Acceptance:** any inherited attribution needs similarity ≥ 0.8 AND matching call-graph degree
(±2 callees), else log as `[DIFF-UNCERTAIN]`.

---

## Track D — Console Port Symbol Harvest (highest possible yield — gate first)

**Why:** PS2-era EA titles very often shipped **unstripped ELF executables** — full function-name
symbol tables in the SLES/SLUS ELF. F1 2001 and F1 2002 shipped on PS2 (and Xbox/GameCube). Same
ISI codebase core. If the PS2 ELF has a symtab, we get *thousands of real function names* mappable
to F1C via Track C-style diffing (cross-architecture: use Ghidra + BSim, or match via strings, call
graphs, and constants rather than bytes).

**Gate (Architect, 30 min):** user must own or legitimately obtain the disc. Dump the ELF
(`SLES_xxx.xx` / `SLUS_xxx.xx` from disc root), run `readelf -S` or load in Ghidra, check for
`.symtab` / non-empty symbol table. If stripped → close track, cheap exit.

**If symbols present (Worker/Architect):**
1. Load PS2 ELF in Ghidra (MIPS R5900; install ghidra-emotionengine extension for best results).
2. Export full symbol list: `reference/ps2_symbols.csv` = `name, address, size`.
3. Match to F1C x86 functions via: identical string references (strongest), identical float/double
   constants (physics coefficients are unique fingerprints), call-graph shape, function size ratio.
4. Every match ≥2 independent signals → rename in docs as `(ps2: RealName)` annotation.
5. C++ mangled names decode to full class::method signatures — harvest class names, build a class map
   in `docs/22-class-map.md` (new doc).

**Also check:** Xbox builds (XBE, x86! — byte-level diffing works directly, even better than PS2 if
symbols or debug sections present), GameCube DOL (symbols rarer).

**Output:** `reference/ps2_symbols.csv`, `docs/22-class-map.md`, annotated docs entries.
**Acceptance:** each name transfer lists its ≥2 matching signals.

---

## Track E — Library Signature Matching

**Why:** ~1,000 functions are CRT/system, plus statically linked middleware (zlib, Miles Sound
System, Bink, D3DX8). Naming them shrinks the `unknown` pile and de-noises call graphs.

**Steps (Architect, one-time):**
1. Ghidra FunctionID: apply shipped FID databases (VC6/VC7 CRT). MSVC ~2002 = VC7/VS.NET era.
2. zlib: version string is in the exe ("deflate ... Copyright"); grab that exact zlib release, compile
   with VC7 defaults or use known signature sets, match inflate/deflate family.
3. Miles Sound System: public `mss.h` names every `AIL_*` API. Match by string refs ("Miles Sound
   System" strings already flagged as skip-pattern) and export table of binkw32/mss32 if dynamically
   linked — check imports first, static parts second.
4. Bink: same approach with public Bink SDK headers.
5. D3DX8 static libs: match against DX8 SDK d3dx8.lib (public SDK).
6. Update triage index: reclassify matched rows from `unknown` to proper category with library name
   in the purpose column. These need NO full doc entries (skip-pattern rule stands).

**Output:** updated `docs/decompiled_full_index_final.md` rows; count report in `work/CHANGELOG.md`.
**Acceptance:** report how many `unknown` rows were consumed.

---

## Track F — Community Artifact Mining

**Why:** 20 years of F1C modding left tools whose authors already reverse engineered parts of the
memory layout: telemetry/MoTeC exporters, CSM (Championship Season Manager), F1C trainers/overlays,
MAS/GMT extractors. Their offsets independently confirm (or contradict) docs/12 and docs/13.

**Steps (Lead):**
1. Inventory known tools: search RaceDepartment, MediaFire-era F1C forums (via web search), GitHub
   for `F1 Challenge` `F1C` telemetry / MAS / GMT repos.
2. For open-source tools: extract every hardcoded address/offset; tabulate
   `tool, address/offset, claimed meaning`.
3. For closed tools with docs: harvest documented addresses from readmes/forum posts.
4. Cross-check table against docs/12 (globals) and docs/13 (offsets):
   - Agreement → add `(confirmed by <tool>)` note.
   - Conflict → `[CORRECTION]` candidate in `work/CHANGELOG.md` for Architect.
   - New address not in docs → new-global candidate, Worker verifies in decompile before adding.
5. File-format knowledge: MAS/GMT extractor source reveals loader struct layouts → map to the loader
   functions in docs (search index for file-I/O game_logic entries).

**Output:** `reference/community_offsets.md`, confirmations/corrections in docs.
**Acceptance:** no community claim enters docs/ without a decompile-side verification.

---

## Track G — Second-Decompiler Cross-Check

**Why:** Different decompilers recover different idioms. Targets: the worst Ghidra outputs (goto
spaghetti, failed switch recovery, register-allocated `this`).

**Steps:**
1. Candidates: Binary Ninja (commercial, best HLIL), IDA Free 8.x with Hex-Rays cloud decompiler
   (limited), RetDec (free, weaker), angr decompiler (free). Realistic free pick: RetDec batch +
   selective manual IDA Free.
2. Worker flags "unreadable" functions during normal passes with `[NEEDS-ALT-DECOMPILE]` in
   `work/CHANGELOG.md` (address list).
3. Architect batch-runs alternative decompiler on flagged addresses only, drops outputs in
   `Isolated Workspace/alt_decomp/0xADDR.c`.
4. Worker re-documents from the better output; entry notes `decompiled-with: <tool>`.

**Output:** `Isolated Workspace/alt_decomp/`, improved entries.
**Acceptance:** only run on flagged addresses; no blanket re-decompilation.

---

## Track H — Game Data Archive Sweep

**Why:** Shipped .MAS archives occasionally contain accidental dev leftovers: commented shader files,
.h fragments, tool-generated text with field names, default .ini with parameter names matching the
exe's config parser (feeds docs/16 moddable parameters).

**Steps (Worker):**
1. Extract all .MAS archives from the game install (community MAS extractor).
2. Sweep extracted tree for: `*.h`, `*.cpp`, `*.txt`, `*.ini`, `*.sp`, shader files with comments.
3. Grep every extracted text file for tokens that also appear as string literals in the exe —
   parameter-name overlaps confirm the config-parser field names in docs/16.
4. Log finds in `reference/data_archive_finds.md`.

**Output:** `reference/data_archive_finds.md`, docs/16 additions.
**Acceptance:** each docs/16 addition cites both the data-file token and the exe string literal.

---

## Track J — Unique-String Web/GitHub Search

**Why:** Highly unique exe strings (error messages, format strings, class-ish tokens) sometimes
appear in public derived code, forum RE threads, or sibling-engine open projects — free context.

**Steps (Lead):**
1. From Track B's string dump, select ~50 most distinctive strings (long, weird, low-google-noise).
2. Web + GitHub code search each. Record hits in `reference/web_string_hits.md`.

**Output:** `reference/web_string_hits.md`.
**Acceptance:** every used hit has URL + date + license/nature noted.

---

## Track I — Runtime Validation (already running, fold in)

Continue current Cheat Engine / monitor work (see memory: F1CUI cross-validation — tire stride 0xF8,
struct 0x48C0, wear floor 0.75 confirmed). New rule: every Track A/D/F name transfer that is
runtime-observable (temps, RPM, wear) gets a runtime spot-check before the annotation is marked
`confirmed` rather than `corroborated`.

---

## Bookkeeping

- New directory: `reference/` at repo root for all recovered external knowledge.
- Every track logs progress in `work/CHANGELOG.md`; corrections use existing `[CORRECTION]` prefix.
- Architect verifies per existing methodology (CLAUDE.md "Verification Methodology") before any
  annotation lands in docs/.
- QUEUE.md gains a pointer to this plan; track order above is the queue order.
