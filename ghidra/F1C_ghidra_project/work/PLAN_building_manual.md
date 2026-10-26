# The Building Manual — Gap Analysis & Recreation Plan

**Date:** 2026-07-15
**Status:** Active plan

---

## Part 1: What We Have vs What We Need

### The Brick Catalog (DONE — static analysis ~95% exhausted)

| Asset | Count | Status |
|-------|-------|--------|
| Documented functions | 6,868 | Complete |
| Call edges | 16,475 | Complete |
| Named globals | ~8,048 | Complete |
| Struct offset lines | 6,910 | Complete |
| Reimplementation specs | 18 | Complete |
| Call chain traces | 237 | Complete |
| Architecture narratives | 5 (docs/17–21) | Complete |
| Audit report (structs) | 281 sections | Complete |

### The Building Manual (MISSING — requires runtime + synthesis)

| Gap | Why it matters | How to close it |
|-----|---------------|-----------------|
| **Frame loop sequence** | Don't know execution order within a tick | Runtime trace |
| **Object lifecycle** | Know struct layout, not create/init/update/destroy flow | Synthesis from call graph + runtime |
| **State machine graphs** | Know states exist (GameState 1-7, RacePhase 0-7), not transition edges | Runtime trace + manual mapping |
| **Data flow ownership** | 8,048 globals but no read/write ownership per subsystem | Automated script on call graph + global usage |
| **Virtual dispatch targets** | 479 orphans, no RTTI, static analysis ceiling | Runtime trace (hook vtable calls) |
| **Inlined functions** | Invisible to both Ghidra and IDA — compiler eliminated them | Pattern matching across .c files (speculative) |
| **Data tables** | Tire curves, aero coefficients, lookup tables — encode behavior but aren't code | Data section sweep + manual identification |
| **Thread model** | Which subsystems run on which threads, synchronization points | Runtime observation |
| **Initialization order** | What sets up what at startup, dependency chain | Trace from WinMain/entry down |

### Static Analysis Ceiling — What More Ghidra/IDA Passes Won't Give

1. **Indirect calls** — `call [eax+0x1C]` has no static resolution without RTTI
2. **22KB gap at 0x0047fc54** — likely data table in .text, needs runtime confirmation
3. **Compiler transforms** — loop unrolling, strength reduction, CSE distort original logic
4. **Inlined functions** — existed in source, flattened into callers by `/Ob2`
5. **Runtime-only paths** — code reached only via callbacks, timers, window messages

---

## Part 2: Recreation Plan — How To Build From Here

### Phase A: Runtime Trace (THE critical missing piece)

**Goal:** Capture one full frame of execution — every function called, in order, with caller info.

**Approach:**
1. Build a Python DLL injector using `ctypes` + `WriteProcessMemory`
2. Hook the frame loop entry point (find via breakpoint on known per-frame functions like physics update)
3. Instrument ~50 key functions with entry/exit logging (not all 6,868 — start with top-called from graph stats)
4. Run game through: menu → practice session → one timed lap → pit stop → session end
5. Capture: function address, caller address, timestamp, thread ID

**Output:** `traces/frame_sequence.log` — ordered function call list for one frame
**Derived:** Frame loop diagram, subsystem execution order, thread model

**Tools needed:**
- Python + ctypes (process attach)
- x86 debugger (x64dbg or WinDbg) for initial breakpoint discovery
- Frida (alternative: JavaScript-based hooking, lower friction than DLL injection)

**Key discovery targets:**
- Main loop function (calls everything per frame)
- Physics tick rate vs render tick rate (likely different)
- AI update frequency (every frame? every N frames?)
- Input polling point in the loop

### Phase B: Global Ownership Map (automated, no workers needed)

**Goal:** For every global, determine which functions write it and which read it.

**Approach:**
1. Parse all .c files for global references (already have `ida_data_xrefs.csv` with 17,037 refs)
2. Classify each ref as read or write (IDA data xrefs have this)
3. Group by subsystem (using existing docs/ system assignments)
4. Output: ownership table — "DAT_X: written by physics, read by renderer+AI"

**Output:** `docs/14-global-ownership.md` or knowledge graph extension
**Script:** ~100 lines Python, reads `ida_data_xrefs.csv` + `knowledge_graph/globals_usage.json`

**What this reveals:**
- Shared mutable state between subsystems (coupling points)
- Globals that are written by many subsystems (coordination variables)
- Globals written by nobody in static code (set by runtime/config file loading)
- Natural subsystem boundaries for recreation modules

### Phase C: Architecture Synthesis (manual, architect + lead work)

**Goal:** Produce the actual wiring diagram — how subsystems connect.

**Approach:**
1. Start from frame trace (Phase A output)
2. Draw subsystem boxes: Physics, AI, Renderer, Audio, Network, UI, GameLogic, Input
3. For each box, list: entry functions (called by main loop), exit functions (calls to other subsystems), globals owned
4. Draw edges: data flow between subsystems via globals and function calls
5. Document the update contract: "Physics runs first, writes vehicle positions. Renderer runs second, reads them."

**Output:** `docs/00-architecture-manual.md` — the building manual itself
**Format:** Prose + diagrams (mermaid or SVG)

**This is the document that makes recreation possible.** Everything else is supporting material.

### Phase D: Object Lifecycle Documentation (synthesis from existing data)

**Goal:** For each major game object (Vehicle, Track, Session, Weather, AI Driver), document: allocation → initialization → per-frame update → state transitions → destruction.

**Approach:**
1. Pick object (e.g., Vehicle at `DAT_007c54e8` PlayerVehiclePtr)
2. Find all functions that write to early struct offsets (initialization)
3. Find all functions called per-frame that read/write the struct (update)
4. Find cleanup/destructor patterns (write NULL, free calls)
5. Order by call graph depth from main loop

**Output:** Per-object lifecycle docs in `docs/30-impl-specs/` (extend existing specs)

### Phase E: State Machine Extraction (depends on Phase A traces)

**Goal:** Map every state variable to its transition graph.

**Known state variables:**
- `DAT_007d00ec` GameState (1-7)
- `DAT_007c56a4` SessionType (0-7)
- `DAT_007c56a8` RacePhase (0-7)
- `DAT_007cf080` WeatherMode (0-5)
- `DAT_007d0410` RaceMode (3/4=championship)

**Approach:**
1. Find all functions that WRITE each state variable (from Phase B ownership map)
2. For each write, determine: what was the previous value? What triggered the write?
3. Build transition graph: state × input → new_state + side_effects
4. Validate against runtime traces

**Output:** `docs/15-state-machines.md` — transition tables + diagrams

### Phase F: Remaining DS Worker Tasks (polish, parallel with above)

Run the 5 approved tasks from HANDOFF.md (~36 worker runs):
- Batch 1: triage_upgrade (63 functions) + source_tree (reconstruct original .cpp layout)
- Batch 2: gap_analyze (852 .text gaps) + enum_catalog (magic numbers from switches)
- Batch 3: cross_validate_2 (audit physics/game_logic entries against updated docs/12+13)

These improve brick quality but don't build the manual. Run them in parallel with Phases A-E.

#### Phase F Progress (completed 2026-07-15, Sonnet)

**Phase B — DONE**
- `tools/global_ownership.py` — reads ida_data_xrefs.csv + systems.json
- `docs/14-global-ownership.md` — 124 KB; 7,990 globals; 80 cross-subsystem coupling points
- Key coupling: VehicleCount, CurrentPlayerIndex, RaceMode written by 3+ subsystems; 6,909 globals have no static writer

**Batch 1 — DONE**
- `triage_upgrade` — 62 entries merged across 10 docs; triage-only count → 0; knowledge graph rebuilt
  - Bug fixed: item getter defaulted all to docs/20; `work/reroute_triage_upgrade.py` re-routed 43/63 to correct docs
- `source_tree` — `docs/00-source-tree.md` (53 KB); 55 .cpp files mapped with address ranges
  - `work/merge_source_tree.py` written (handles 3 different worker Statistics formats)

**Batch 2 — DONE**
- `gap_analyze` — `docs/23-gap-analysis.md` (271 KB); 824 gaps classified
  - 421 missed_function | 165 jump_table | 130 mixed | 42 padding | 16 data_table
  - High-confidence missed functions: 0x00472cf5 (2,235B UI constructor), 0x0046aef9 (375B), 0x00488fa9 (1,047B)
  - 0x0047fc54 (23KB) confirmed data_table — not recoverable as functions
  - `work/merge_gap_analyze.py` written (dedup by start address — worker B ran full set)
- `enum_catalog` — `docs/24-enum-catalog.md` (492 KB); named enums + magic numbers + raw batch dumps
  - Workers K/R/T hit context limits → batch files handled by `work/merge_enum_catalog.py`

**Batch 3 — IN PROGRESS**
- `cross_validate_2` — running; worker I stalled (~10/351 functions done, needs re-run)
- 1,359 PASS / 33 FAIL so far across completed workers
- `work/merge_cross_validate_2.py` written — extracts FAILs to `docs/25-cv2-corrections.md` + CHANGELOG
- Does NOT auto-patch docs/ — corrections need architect review

**New scripts written (Phase F):**
- `tools/global_ownership.py`
- `work/reroute_triage_upgrade.py`
- `work/merge_source_tree.py`
- `work/merge_gap_analyze.py`
- `work/merge_enum_catalog.py`
- `work/merge_cross_validate_2.py`

#### Phase A Progress (2026-07-15, Opus)

**Runtime trace framework — DONE**
- `tools/trace/agent.js` — Frida 17 agent, 68 hooks across 10 subsystems
- `tools/trace/f1c_trace.py` — Python controller with interactive CLI
- `tools/trace/analyze_trace.py` — Post-processing: frame detection, subsystem counts, thread analysis

**Traces captured:**
1. Pre-start (98 frames, practice, 22 vehicles) — confirmed static analysis predictions
2. Racing (3,000 frames, 26.6s, 22 vehicles) — full physics + AI data

**Key runtime findings:**
- Single-threaded confirmed (TID 32488 across all 3,098 frames)
- Physics: fixed timestep ~1.16ms (~864 Hz), variable 3-36 sub-steps/frame (avg 9.7)
- AI: does NOT run every frame — ~31.7 Hz per vehicle (28% of frames), always 22 calls
- AI called FROM PhysicsDispatchChain, not from main loop directly
- Two-pass physics confirmed: 1st pass = 1 sub-step, 2nd pass = N sub-steps (accumulator)
- Racing FPS: ~113 (vs ~200 at pre-start)
- Per-frame call count: ~1,800 during racing (vs ~560 at pre-start)
- All static analysis predictions confirmed; 2 corrections (ForceFeedback/AudioDSP call chains)

**Side outputs:**
- `docs/15-state-machines.md` — state machine analysis from static scan (282 references)
- `docs/22-frame-loop.md` — fully updated with runtime data

**Remaining Phase A work:**
- Traces in other game states (qualifying, formation lap, pit stop)
- Vtable dispatch tracing (479 orphan resolution)
- Startup/initialization trace (WinMain → first frame)

---

## Sequencing

```
WEEK 1: ✅ DONE
  Phase B — Global ownership map → docs/14-global-ownership.md
  Phase F Batch 1 — triage_upgrade (62 entries) + source_tree (docs/00)

WEEK 2: ✅ DONE
  Phase F Batch 2 — gap_analyze (824 gaps → docs/23) + enum_catalog (docs/24)

WEEK 3 (current): ✅ MOSTLY DONE
  Phase F Batch 3 — cross_validate_2 (running; worker I needs re-run)
  Phase A — Runtime trace framework DONE (Frida-based, 68 hooks, interactive CLI)
  Phase A — Pre-start trace captured (98 frames) — confirmed static analysis
  Phase A — Racing trace captured (3,000 frames, 26.6s) — physics + AI rates measured
  Phase A — docs/22-frame-loop.md updated with runtime-confirmed data

WEEK 4:
  Phase A — Additional traces: qualifying, formation lap, pit stop ← NEEDS OPUS
  Phase C — Begin architecture synthesis from trace data ← NEEDS OPUS

WEEK 5:
  Phase D — Object lifecycle docs (Vehicle, Track, Session first) ← NEEDS OPUS
  Phase E — State machine extraction ← NEEDS OPUS

WEEK 6+:
  Phase C — Finalize architecture manual ← NEEDS OPUS
  Recreation begins — subsystem by subsystem, guided by the manual
```

---

## Success Criteria

The project is "fully mapped" when you can answer these without reading .c files:

1. "What happens every frame?" → Frame loop doc with ordered function list
2. "How does a Vehicle get created and destroyed?" → Lifecycle doc
3. "What triggers a transition from qualifying to race?" → State machine doc
4. "Which subsystems share mutable state?" → Global ownership map
5. "In what order should I reimplement subsystems?" → Architecture manual with dependency graph

Until all 5 are answerable, you have bricks without the manual.

---

## Model Routing

**Before starting any phase, ask the user:** "Which model am I running as? (Opus / Sonnet / other)"

This matters because phases have different complexity ceilings:

| Phase | Opus 4.6+ | Sonnet 4.6 | DS / other |
|-------|-----------|------------|------------|
| A — Runtime trace | Yes | NO — requires debugging improvisation | No |
| B — Global ownership | Yes | Yes — procedural instructions below | No |
| C — Architecture manual | Yes | NO — requires whole-codebase synthesis | No |
| D — Object lifecycles | Yes | MAYBE — with tight scoping | No |
| E — State machines | Yes | MAYBE — narrow scope helps | No |
| F — DS worker tasks | Yes | Yes — procedural instructions below | Prompt generation only |

**If you are Sonnet:** only execute phases marked "Yes" above. For phases marked "NO", tell the user: "This phase requires Opus. I can prepare inputs but should not execute the synthesis." For "MAYBE" phases, attempt only if the user explicitly asks and provides the specific object/variable to target.

---

## Sonnet-Ready Instructions: Phase B — Global Ownership Map

**You are building a Python script. Follow these steps exactly.**

### Step 1: Understand the input files

Read these files to understand their format (first 10 lines each):
- `tools/ida_data_xrefs.csv` — columns: `func_addr,global_addr,access_type` (access_type is `r` or `w`)
- `knowledge_graph/globals_usage.json` — JSON dict mapping global addresses to function lists
- `knowledge_graph/systems.json` — JSON dict mapping doc file paths to function address lists

### Step 2: Write the script

Create `tools/global_ownership.py` that:

1. Reads `tools/ida_data_xrefs.csv` with Python `csv` module
2. For each unique `global_addr`, collects:
   - `writers`: set of `func_addr` where `access_type == 'w'`
   - `readers`: set of `func_addr` where `access_type == 'r'`
3. Reads `knowledge_graph/systems.json` to map each function address to its subsystem (doc file)
4. Reads `docs/12-globals-reference.md` to get human-readable names for globals (parse table rows: `| 0xXXXXXXXX | name | ... |`)
5. Outputs `docs/14-global-ownership.md` with this format:

```markdown
# Global Ownership Map

Generated from IDA data xrefs (17,037 references).

## Summary Statistics

- Total globals with xrefs: NNNN
- Write-only globals: NNNN
- Read-only globals: NNNN  
- Shared (multi-subsystem write): NNNN — THESE ARE THE COUPLING POINTS

## Shared Mutable State (written by 2+ subsystems)

| Global | Name | Writers (subsystem) | Readers (subsystem) |
|--------|------|--------------------|--------------------|
| 0xXXXX | DAT_name | physics, AI | renderer, audio |

## Per-Subsystem Ownership

### docs/04-tire-system.md
**Owns (sole writer):**
- `DAT_XXXXXXXX` — TireWearMultiplier

**Reads from other subsystems:**
- `DAT_XXXXXXXX` — VehicleSpeed (owned by physics)

(repeat for each doc file in systems.json)

## Orphan Globals (no writers found in static analysis)

| Global | Name | Readers | Likely source |
|--------|------|---------|--------------|
| 0xXXXX | name | physics, renderer | config file / runtime init |
```

### Step 3: Verify

Run the script:
```bash
"%USERPROFILE%\AppData\Local\Python\bin\python3.exe" tools/global_ownership.py
```

Check output:
- `docs/14-global-ownership.md` should exist and have >100 lines
- "Shared Mutable State" table should have entries (if empty, the access_type parsing is wrong)
- Cross-check 3 globals manually against a .c file to confirm read/write classification

### Step 4: If something fails

- If `ida_data_xrefs.csv` has different columns than expected: print the header row, report to user, stop
- If `systems.json` is missing: run `"%USERPROFILE%\AppData\Local\Python\bin\python3.exe" tools/knowledge_graph/rebuild.py` first, then retry
- If `docs/12-globals-reference.md` table format doesn't match: skip name lookup, use raw `DAT_` addresses, note the issue in output header
- If script produces 0 shared globals: likely bug in access_type parsing. Print first 5 rows of CSV and stop

---

## Sonnet-Ready Instructions: Phase F — DS Worker Tasks

**You are generating prompts and running merges. Follow these steps exactly.**

### Pre-check

Verify batch launcher exists:
```bash
ls analysis_pipeline/batch_launcher.py
```

If missing, stop and report.

### Batch 1: triage_upgrade + source_tree

**triage_upgrade:**
1. Open `analysis_pipeline/1_batch_gui.bat`
2. Select mode: `triage_upgrade`
3. Set worker count: 4
4. Click "Generate" — creates `prompts/triage_upgrade/worker_A_prompt.md` through `worker_D_prompt.md`
5. Report to user: "4 prompts generated. Launch each in a DS V4 Flash instance."

If `triage_upgrade` mode doesn't exist in the GUI:
- Check if it's listed in `batch_launcher.py` — grep for `triage_upgrade`
- If not, tell user: "triage_upgrade mode not built yet. Need Opus to add it to batch_launcher.py."

**source_tree:**
1. Same process, mode: `source_tree`, workers: 2-4
2. If mode doesn't exist, same fallback as above

**After workers finish (user will tell you):**
```bash
cd analysis_pipeline && "%USERPROFILE%\AppData\Local\Python\bin\python3.exe" merge_to_docs.py --subdir triage_upgrade --archive
```

Verify merge:
```bash
grep -c "## FUN_" docs/decompiled_full_index_final.md
```
Count should increase by ~63 compared to before.

### Batch 2: gap_analyze + enum_catalog

Same pattern. Modes: `gap_analyze` (10 workers), `enum_catalog` (10 workers).

**gap_analyze output is a classification table, not doc entries.** Merge script may need to be different. Check if `work/merge_gap_analyze.py` exists. If not, tell user a merge script is needed.

**enum_catalog output goes to a new doc file.** Check if target doc exists. If not, output should create `docs/15-enums.md` or similar.

### Batch 3: cross_validate_2

Mode: `cross_validate_2`, 8 workers.

Output is correction logs. Merge using:
```bash
cd analysis_pipeline && "%USERPROFILE%\AppData\Local\Python\bin\python3.exe" merge_to_docs.py --subdir cross_validate_2 --archive
```

After merge, rebuild graph:
```bash
"%USERPROFILE%\AppData\Local\Python\bin\python3.exe" tools/knowledge_graph/rebuild.py
```

### If a mode doesn't exist in batch_launcher.py

Several of these modes (triage_upgrade, source_tree, gap_analyze, enum_catalog, cross_validate_2) may not be built yet. The GUI currently has 12 modes. For any missing mode:

1. Report to user: "Mode `X` not in batch_launcher.py. Needs Opus to build it."
2. Do NOT attempt to add launcher modes yourself — the mode system requires: a prompt template, an item generator function, a prompt builder function, and GUI dispatch wiring. This is Opus-level work.
3. Move to the next task that does have a working mode.

### If workers stall or produce bad output

Check entry count:
```bash
grep -c "^## FUN_" analysis_pipeline/output/<mode>/worker_X.md
```

If count is far below expected (e.g., 3 entries when 16 assigned):
- Worker hit context limit. Generate resume prompt using the recovery script in CLAUDE.md.
- Report to user with count and ask whether to generate resume prompt.

If headers are wrong (not `## FUN_` format):
```bash
# Fix non-FUN_ headers
sed -i 's/^## Unwind_\([0-9a-fA-F]*\)/## FUN_\1/' analysis_pipeline/output/<mode>/worker_X.md
# Fix double .md extension  
sed -i 's/\.md\.md/.md/g' analysis_pipeline/output/<mode>/worker_X.md
```
