# F1 Challenge 99-02 — Analysis & Documentation Completion Plan

**Goal:** Complete, verified, structured documentation of all 6,306 decompiled functions — sufficient for future open-source reimplementation.

**Workforce:** DeepSeek V4 Flash workers (1M context, parallel) via `analysis_pipeline/batch_launcher.py`.

**Current state (2026-07-15):**
- 6,306/6,306 functions documented (`## FUN_` entries)
- Knowledge graph built (8,026 call edges, 855 globals, 436 algorithm clusters)
- Zero triage-only remaining
- All 6,116 `.c` files in `analysis_pipeline/analyzed/`

**Known quality gaps:**
- No cross-validation audit done on deep dive entries (docs/17–21)
- docs/13 struct offsets: 38 lines, scattered observations not synthesized
- docs/12 globals: 51 lines vs 843 named in knowledge graph — not consolidated
- 94 table-row stubs in docs/01–10 without `### FUN_` entries (81 have .c source)
- docs/17–21 have no architecture narrative prose — just raw function entries
- 1,456 orphan functions in call graph (no callers/callees documented)

---

## Infrastructure — 5 New Batch Launcher Modes

| Mode ID | Label | Purpose |
|---------|-------|---------|
| `cross_validate` | Cross-Validation Audit | Verify documented claims against actual .c source |
| `struct_synth` | Struct Synthesis | Consolidate scattered offset observations into docs/13 |
| `global_sweep` | Global Consolidation | Compile all 843+ named globals into comprehensive docs/12 |
| `stub_upgrade` | Stub Upgrade | Upgrade 81 table-row stubs in docs/01–10 to `### FUN_` |
| `arch_narrative` | Architecture Narrative | Write prose system overviews for docs/17–21 |

Each mode: prompt template + item collector + `output/<mode_id>/worker_X.md` + `prompts/<mode_id>/worker_X_prompt.md`.

---

## Phase 1 — Cross-Validation Audit (MUST RUN FIRST)
**Workers: 10–20 | Est: 1 day**

Audit all deep dive entries in docs/17–21 against actual `.c` source files. These 4,121 entries were written by DS workers without human review — errors propagate if not caught now.

**What workers check per entry:**
- Globals: does `.c` actually reference claimed `DAT_` addresses?
- Direction: entry says "reads X" but `.c` only writes (or vice versa)
- Struct offsets: claimed type (float/int/double) matches `.c` dereference pattern
- Called functions: `.c` actually calls claimed `FUN_` addresses
- Constants: numeric values accurate
- Moddability: "configurable" requires config string literal in `.c`

**Output format:** Per-function PASS/FAIL with tagged error types. FAIL entries include corrected replacement text.

**Post-phase:** Apply corrections to docs/ files. Log all changes in `work/CHANGELOG.md` with `[CORRECTION]` prefix.

---

## Phase 2 — Struct Synthesis + Global Consolidation (parallel)
**Workers: 4+2 | Est: 1 day | Depends: Phase 1 complete**

### 2A · Struct Synthesis (`struct_synth` mode)
- Workers read all `## FUN_` entries in assigned doc files
- Extract every struct offset observation from offset tables
- Group by struct type (VehiclePhysics, AIDriver, TireModel, RaceSession, etc.)
- Deduplicate offsets, resolve type conflicts, name fields from usage context
- Output: unified field tables for `docs/13-struct-offsets.md`
- 4 workers: one per doc cluster (physics+collision, renderer, engine+session, math+audio)

### 2B · Global Consolidation (`global_sweep` mode)
- Knowledge graph already has 843/855 globals named from function entries
- Workers compile comprehensive reference: address, name, module, value range, access pattern
- For 12 truly unnamed globals: read `.c` files, propose names from context
- Output: complete `docs/12-globals-reference.md` table
- 2 workers (one for game globals 0x005–0x007, one for engine globals 0x008+)

---

## Phase 3 — Stub Upgrade
**Workers: 2 | Est: half day | Depends: Phase 2 (better globals/structs reference)**

94 functions in docs/01–10 exist only as table rows. 81 have `.c` source files.

Each worker reads the `.c` file and writes a lightweight entry:
```markdown
### FUN_00XXXXXX — Short Name

One-line summary.

**Key logic:**
- 2–4 bullets: main behavior, key constants, branches

**Calls:** FUN_AAAAAA (what it does)
```

Output routes to same doc file via `<!-- target: docs/XX-name.md -->`.
After merge: every function with source in docs/01–10 has human-readable documentation.

**Distribution:**
- Worker A: docs/01 (45 stubs) + docs/10 (25 stubs) = 70 items
- Worker B: docs/09 (13 stubs) + docs/08 (6) + docs/06 (5) = 24 items

---

## Phase 4 — Architecture Narratives
**Workers: 5–7 | Est: 1 day | Depends: Phases 1–3 complete**

Each worker reads all documented functions for one system and writes prose architecture overview prepended to the doc file.

| Worker | Doc | Entries | Topic |
|--------|-----|---------|-------|
| A | docs/17-physics-collision.md | 364 | BVH, intersection tests, collision response |
| B | docs/18-physics-dynamics.md | 285 | Forces, integration, suspension, aero |
| C | docs/19-renderer.md | 435 | D3D draw pipeline, state machine, vertex format |
| D | docs/20-math-utilities.md (part 1) | ~1,400 | Vector/matrix math, algorithm families |
| E | docs/20-math-utilities.md (part 2) | ~1,448 | CRT wrappers, data structures, misc |
| F | docs/21-audio-network-internals.md | 189 | Audio mixing, network protocol |

**Narrative format per doc:**
```markdown
## System Overview
[2–3 paragraphs: what it does, where it runs in game loop, what data it owns]

## Subsystem Structure
[Major function clusters and how they interact]

## Data Flow
[How data enters, transforms, exits]

## Key Entry Points
[Top-level functions that drive this system]

## Call Graph Summary
[Major call chains in plain English]
```

---

## Orphan Analysis (standalone script, runs anytime)

1,456 functions have no callers/callees in knowledge graph. Not a worker mode — query `knowledge_graph/callers.json` + `call_graph.json` for zero-edge nodes.

Script outputs:
- List of orphan addresses with their doc entries
- Likely causes: vtable slots, registered callbacks, export entry points, missed call links
- Suggested `**Calls:**` / `**Used by:**` additions for docs

Can feed identified gaps into targeted worker re-analysis.

---

## Timeline

| Phase | Workers | Duration | Status |
|-------|---------|----------|--------|
| Infrastructure (5 launcher modes) | — | 1 day (code) | ✅ DONE |
| 1 · Cross-Validation | 20 | 1 day | ✅ DONE — 255 FAILs, 127 corrected |
| — · Apply corrections | manual | half day | ✅ DONE |
| 2A · Struct Synthesis | 18 | 1 day | ✅ DONE — docs/13: 38→6,910 lines |
| 2B · Global Consolidation | 20 | 1 day | ✅ DONE — docs/12: 51→2,004 lines, 859 rows |
| 3 · Stub Upgrade | 5 | half day | ✅ DONE — 50 `### FUN_` entries added |
| 4 · Architecture Narratives | 6 | 1 day | ✅ DONE — ~10k words across docs/17–21 |
| 5 · Impl Specs | 19 | 1 day | ✅ DONE — 18 specs in docs/30-impl-specs/ |
| 6 · Call Chain Traces | 19 | 1 day | ✅ DONE — 237 chains in docs/31-call-chains/ |

---

## Recreation Validation (next phase — not yet started)

With impl specs and call chains complete, the remaining work is validation and gap-filling:

- **Recreation Validation** — Per-spec completeness audit: for each spec in docs/30-impl-specs/, verify all claimed APIs, structs, constants against actual .c source files
- **Gap-Filling** — Identify systems where call chains are shallow (depth < 3) or seed functions have undocumented callees; targeted re-analysis
- **Orphan Resolution** — 1,399 functions with no callers/callees in call graph; infer vtable slots, callbacks, export entry points

Requires 1 new launcher mode (`recreation_validate`) or manual audit workflow.

### Redundant spec pairs in docs/30 (optional cleanup)
- `01-engine-architecture-spec.md` + `03-session-state-machine-...-part-2-spec.md` — both cover Engine Architecture
- `02-math-utilities-spec.md` + `04-math-utilities-part-2-...-spec.md` — both cover Math Utilities
- `10-session-and-race-logic-part-1-spec.md` + `11-session-and-race-logic-spec.md` — both cover Session/Race Logic
- Can be manually merged; combined coverage is richer than either alone
