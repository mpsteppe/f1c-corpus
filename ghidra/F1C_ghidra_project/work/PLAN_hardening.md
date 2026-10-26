# F1 Challenge 99-02 — Confidence & Coverage Hardening Plan

**Goal:** Identify missed code, validate documentation accuracy, and upgrade inferred claims to confirmed facts.

**Context:** 6,306 functions documented, 18 impl specs, 237 call chains complete. This plan addresses two risks: (1) code that was never decompiled, (2) low-confidence claims in existing documentation.

**Workforce:** DeepSeek V4 Flash workers (1M context, parallel) via `analysis_pipeline/batch_launcher.py` for worker phases. Python scripts for automated analysis phases.

---

## Phase 0 — Binary Coverage Audit (manual + script)
**Goal:** Find code Ghidra missed entirely.
**Type:** One-shot script, no workers.
**Duration:** 1 day.
**Dependencies:** None — can run immediately.

**Method:**
1. Export PE section table from Ghidra (`.text` start, end, size)
2. Export all known function address ranges (start address + size from Ghidra function list)
3. Script: walk `.text` section byte-by-byte, mark regions NOT covered by any known function
4. Output: gap list with addresses, sizes, and hex dump of first 32 bytes per gap
5. For each gap > 16 bytes: attempt Ghidra "Disassemble" + "Create Function" manually
6. Classify results: real missed functions vs padding/alignment vs data-in-text

**Expected yield:** 50–200 small functions (vtable targets, compiler-generated thunks, exception handlers). Most gaps will be alignment padding (0xCC bytes).

**Tooling needed:** Python script reading Ghidra XML/CSV export. No launcher mode.

**Output:** `work/binary_coverage_gaps.csv` — address, size, classification, notes.

---

## Phase 1 — Struct Confidence Scoring (new launcher mode: `struct_audit`)
**Goal:** Grade every struct field definition in docs/13 by evidence strength.
**Type:** DS worker mode.
**Duration:** 1 day.
**Dependencies:** None — can run immediately, parallel with Phase 0.

**Method per field:**
1. Count how many `.c` files reference this offset on this struct type
2. Check type consistency: do all references agree on type (double/float/int)?
3. Check naming consistency: do all doc entries that mention this offset use same field name?
4. Assign confidence: **HIGH** (3+ sources, type agreement), **MEDIUM** (1–2 sources, type agreement), **LOW** (single source or type conflict)

**Output:** Annotated docs/13 with confidence column. LOW entries get flagged for manual review.

**Workers:** Read docs/13 fields + grep `.c` files for each offset pattern.

---

## Phase 2 — Global Name Validation (new launcher mode: `global_validate`)
**Goal:** Verify that named globals actually behave as documented.
**Type:** DS worker mode.
**Duration:** 1 day.
**Dependencies:** None — can run immediately, parallel with Phases 0–1.

**Method per global:**
1. Collect ALL functions that reference this `DAT_` address (from knowledge graph)
2. Categorize access patterns: read-only, write-only, read-write
3. Check: does documented name match observed behavior across ALL usages?
4. Flag mismatches: e.g., "RacePhase" but some functions use it as a bitfield, or write values outside documented range 0–7

**Output:** Validated globals table with access pattern summary. Misnamed globals get correction proposals.

**Priority targets:** Top-20 most-used globals from `knowledge_graph/stats.json` — several still named "Unknown" despite 500+ callers. Specifically:
- `0x00587bcf` — 507 callers, unnamed
- `0x00587b3e` — 155 callers, unnamed
- `0x00566650` — 134 callers, unnamed

---

## Phase 3 — Orphan Function Resolution (new launcher mode: `orphan_resolve`)
**Goal:** Reduce 1,399 orphan functions (no call edges) by identifying HOW they get called.
**Type:** DS worker mode.
**Duration:** 1 day.
**Dependencies:** Best run after Phase 0 (if new functions found, add them to orphan analysis).

**Method:**
1. For each orphan, check if its address appears in any data section (vtable slot)
2. Check if address appears in function pointer assignments in other `.c` files
3. Check if function matches callback signatures (specific parameter patterns)
4. Check if function is an export, DLL entry, or exception handler
5. For remaining true orphans: does function reference any game globals? If not, likely CRT/library dead code.

**Categories after analysis:**
- **vtable member** → document which class
- **callback** → document registration site
- **dead code** → mark as such, deprioritize
- **unknown entry point** → flag for runtime verification

**Output:** Orphan classification table. Updated call graph edges for vtable/callback discoveries.

---

## Phase 4 — Runtime Validation Framework (infrastructure)
**Goal:** Build tooling to verify static analysis claims against live game.
**Type:** Python tooling, no workers.
**Duration:** 2–3 days.
**Dependencies:** Needs game installed and runnable. Highest value AFTER Phases 1–3 identify which claims to test.

**Method:**
1. Build memory scanner that attaches to running `F1 Challenge Online.exe`
2. Read known global addresses at runtime, log actual values during gameplay
3. Compare observed values against documented ranges/meanings
4. Monitor struct field access patterns: set hardware breakpoints on documented offsets, verify which functions actually touch them

**Components:**
- `tools/runtime_monitor.py` — attach to process, read globals, log to CSV (extends existing `tools/race_monitor.py`)
- `tools/struct_validator.py` — set read/write breakpoints on struct offsets, record which functions trigger
- `tools/behavior_recorder.py` — record global state transitions during specific game events (race start, pit stop, tire change)

**Output:** Runtime evidence log. Each verified claim upgraded from "inferred" to "confirmed" in docs.

---

## Phase 5 — Cross-Reference Completeness (script + targeted workers)
**Goal:** Ensure call graph edges are complete — biggest source of orphans.
**Type:** Primarily script-driven, targeted worker passes for gap-filling.
**Duration:** Half day.
**Dependencies:** None — can run immediately, parallel with Phases 0–2.

**Method:**
1. Script: for each documented `## FUN_` entry, extract `**Calls:**` section
2. For each called function: verify reverse edge exists (callee knows about caller)
3. For each `.c` file: extract ALL `FUN_XXXXXXXX` references via regex
4. Compare against documented calls — find undocumented call edges
5. Feed missing edges into knowledge graph rebuild

**Expected yield:** 500–2,000 new call edges. Orphan count should drop from 1,399 to ~500.

**Output:** Updated `knowledge_graph/call_graph.json` and `knowledge_graph/callers.json`.

---

## Phase 6 — Inlined Function Recovery (research phase)
**Goal:** Identify functions that existed in source but were inlined by compiler.
**Type:** Analysis/research, no workers.
**Duration:** 1 day.
**Priority:** Low — enriches understanding but not blocking for recreation.

**Method:**
1. Scan assert strings for source filenames: `D:\dev\F1_1999_2002\Source\*.cpp`
2. Build source file list from asserts — partial original source tree structure
3. For each source file: count how many decompiled functions map to it
4. Files with suspiciously few functions likely had many inlined helpers
5. Look for repeated code patterns across multiple functions — same 5–10 instructions appearing in 20+ places = likely inlined helper
6. Document inferred inline functions as "phantom entries" — no address, but known behavior

**Output:** `docs/22-inlined-functions.md` — catalog of inferred inline functions with pattern signatures.

---

## Priority & Sequencing

```
IMMEDIATE (parallel, no dependencies):
  Phase 0 — Binary Coverage Audit        [1 day, script]
  Phase 1 — Struct Confidence Scoring     [1 day, workers]
  Phase 2 — Global Name Validation        [1 day, workers]
  Phase 5 — Cross-Reference Completeness  [half day, script]

AFTER IMMEDIATE:
  Phase 3 — Orphan Resolution            [1 day, workers]

INFRASTRUCTURE (anytime, highest value after 1–3):
  Phase 4 — Runtime Validation Framework  [2–3 days, code]

RESEARCH (low priority):
  Phase 6 — Inlined Function Recovery     [1 day, analysis]
```

### Confidence impact summary

| Phase | What it validates | Confidence upgrade |
|-------|------------------|--------------------|
| 0 | Code completeness | "we have everything" → verified |
| 1 | Struct field types/names | inferred → evidence-graded |
| 2 | Global variable names | behavioral guess → access-pattern-validated |
| 3 | Orphan function purposes | unknown caller → classified |
| 4 | All documented claims | inferred → runtime-confirmed |
| 5 | Call graph completeness | partial edges → comprehensive |
| 6 | Source-level completeness | binary-only → source-aware |

### New launcher modes needed

| Mode ID | Phase | Items | Workers |
|---------|-------|-------|---------|
| `struct_audit` | 1 | docs/13 field definitions | 4–6 |
| `global_validate` | 2 | 859 named globals + unnamed top-20 | 4–6 |
| `orphan_resolve` | 3 | 1,399 orphan functions | 10–15 |

### New scripts needed

| Script | Phase | Purpose |
|--------|-------|---------|
| `tools/binary_coverage_audit.py` | 0 | Find unmapped .text regions |
| `tools/call_edge_completeness.py` | 5 | Extract + reconcile all call edges |
| `tools/inline_pattern_finder.py` | 6 | Detect repeated code patterns |
| `tools/runtime_monitor.py` | 4 | Attach to game, read globals live |
| `tools/struct_validator.py` | 4 | Hardware breakpoints on struct offsets |
| `tools/behavior_recorder.py` | 4 | Record state transitions during gameplay |
