# Reorganization & Sanitization Plan — F1C Ghidra Root

Goal: make the whole repo **immediately legible to a fresh LLM** (and human) —
without deleting anything. Every move preserves history (`git mv`); inert clutter
is archived, not removed.

Status: PLAN ONLY. Nothing executed yet. Phased so the zero-risk clarity wins can
land first and the path-sensitive moves happen deliberately.

---

## 1. Diagnosis — why the repo is currently hard to read

| Problem | Evidence | Impact on an LLM |
|---------|----------|------------------|
| **Two contradictory entry points** | Root `README.md` (dated 2026-07-14, "2,413 entries", references "Isolated Workspace/" which no longer exists) vs `CLAUDE.md` (current, 6,868 funcs) | A fresh LLM reading README gets STALE, WRONG facts |
| **~20 loose files at root** | driver0/1/2.bin/.CEM, *_annotated.txt, *_gaps.csv, ds.txt, opus_chat.txt, strings_raw.txt, inventory.csv, search_docs.* | Root looks like a scratch folder; no signal of what matters |
| **Mods split across two locations** | root `mods/` (red-flag-dll) + `tools/mod_pipeline/mods/` (cut_track_dq) | Can't find "the mods" in one place |
| **`work/` is a dumping ground** | 12 PLAN/HANDOFF/QUEUE md + 15 merge_*.py + 6 CSVs + prompts | Planning, tooling, and data mixed with no boundary |
| **`tools/` mixes data and code** | 27 CSVs (IDA exports) + 18 .py + 4 subdirs | "tools" implies code, but half is derived data |
| **Scratch mixed with pipeline** | analysis_pipeline/: 20× `_launch_*.ps1`, debug_struct1/2/3.py, temp_*.txt, poc_* | Throwaway files look like real components |
| **No trust-tier signal** | docs/12,13,31 are DS-worker GUESS/LEAD but sit beside FACT-tier docs | LLM trusts hallucinated labels (already bit us: chain 0008) |
| **No repo-wide manifest** | — | LLM must infer structure by crawling 7,500+ files |

---

## 2. Design principles (optimized for LLM comprehension)

1. **One canonical entry point.** A single `INDEX.md` (or fixed README) an LLM
   reads first, that never contradicts CLAUDE.md. Everything else is reachable
   from it in one hop.
2. **Top level sorts by ROLE, not by history.** Six clear buckets: inputs,
   derived data, docs, tooling, mods, meta. A directory's name should tell an LLM
   whether it's ground truth, derived, or scratch.
3. **Trust tier is explicit and physical.** FACT vs GUESS/LEAD is stated in every
   directory README and, where possible, encoded in folder placement.
4. **Every directory has a `_README.md`** (sorts first alphabetically) with:
   purpose, trust tier, "what an LLM should read first here", and what NOT to trust.
5. **Nothing is deleted.** Scratch/superseded material moves to `archive/`
   (gitignored or kept, but clearly labelled dead).
6. **Don't break working tooling.** Path-referenced files (tools/*.csv,
   pipeline scripts) move only with a grep-and-update pass. Prefer ADD (indexes,
   READMEs) over MOVE where a move has dependents.

---

## 3. Target top-level taxonomy

```
F1C_ghidra_project/
  INDEX.md                  <- NEW. THE entry point. Read first. Points everywhere.
  CLAUDE.md                 (kept — operational instructions; INDEX links to it)
  README.md                 (REWRITTEN — public-facing, matches current state)
  MANIFEST.md               <- NEW. Every top-level item -> purpose + trust tier.

  inputs/                   <- IMMUTABLE ground truth (never regenerated)
    binary/                   the exe reference, PE facts (pointer only; exe stays in game dir)
    memory_dumps/             driver0/1/2.bin/.CEM  (F1CUI runtime struct dumps)
    raw_strings/              strings_raw.txt
    _README.md

  decompiled/               <- FACT tier: raw decompiled source (ground truth)
    string_anchored/          (was decompiled_all/) 666 identifiable funcs
    ida_hexrays/              (was tools/decompiled_ida/) 495 IDA-only
    _README.md                "This is FACT. Trust over any doc label."
    (analysis_pipeline/analyzed/ stays put — path-critical — but linked here)

  docs/                     <- Documentation. Mixed trust — labelled per file.
    _README.md                trust map: which docs are FACT/GUESS/LEAD
    (existing 00-31 unchanged)

  data/                     <- DERIVED datasets (regenerable from binary/docs)
    ida_exports/              the 27 tools/*.csv (functions/xrefs/strings/...)
    cross_binary/             cross_binary_*.csv, nascar0*/3dconfig CSVs
    knowledge_graph/          (was knowledge_graph/) graph JSONs
    inventory/                inventory.csv, function_sizes.csv, *_gaps.csv
    _README.md                "DERIVED. Regenerate via tools/. Not ground truth."

  tools/                    <- CODE ONLY (scripts). Data moved to data/.
    knowledge_graph/          extract/build/query
    trace/                    Frida runtime tracing
    mod_pipeline/             SEED/MAP/WATCH/PATCH + asm_tools + PLAYBOOK
    ida_scripts/              ida_export_all.py, ida_*.py
    _README.md

  pipeline/                 <- (was analysis_pipeline/) DS-worker doc pipeline
    analyzed/                 6,116+ .c (path-critical — stays)
    output/ prompts/ ...
    scratch/                  _launch_*.ps1, debug_struct*, temp_*, poc_* (archived)
    _README.md

  mods/                     <- ALL mods in one place (consolidated)
    red-flag-dll/             (existing)
    cut_track_dq/             (moved from tools/mod_pipeline/mods/)
    _README.md                index of shipped mods + status

  source_recovery/          (unchanged — already self-contained w/ its own ACTION_PLAN)
  roles/                    (unchanged — WORKER/LEAD/ARCHITECT prompts)
  scripts/                  (unchanged — Ghidra Java)

  meta/                     <- planning, process, history
    plans/                    PLAN_*.md (from work/)
    handoffs/                 HANDOFF.md, QUEUE.md
    changelog/                CHANGELOG.md, CORRECTIONS_*.md
    _README.md

  archive/                  <- superseded/scratch. NOT deleted. Clearly dead.
    chat_logs/                ds.txt, opus_chat.txt
    old_prompts/              worker_*_prompt.md, gen_*.py
    _README.md                "Historical. Do not treat as current."
```

---

## 4. Per-item disposition (nothing deleted)

| Current | Action | Destination | Risk |
|---------|--------|-------------|------|
| `README.md` (stale) | REWRITE to current state | root | none |
| `ds.txt`, `opus_chat.txt` | move (no refs) | `archive/chat_logs/` | none |
| `driver0_annotated.txt`, `*_gaps.csv` (no refs) | move | `data/inventory/` | none |
| `driver0/1/2.bin/.CEM` | move + update `tools/parse_struct_dump.py` | `inputs/memory_dumps/` | low |
| `strings_raw.txt` | move + update 3 doc refs | `inputs/raw_strings/` | low |
| `inventory.csv` | move + update docs/00 ref | `data/inventory/` | low |
| `search_docs.py/.bat` | move | `tools/` | low |
| `tools/*.csv` (27) | move + grep-update all `tools/xxx.csv` refs | `data/ida_exports/`, `data/cross_binary/` | **HIGH** |
| `work/PLAN_*.md` | move | `meta/plans/` | none (docs) |
| `work/merge_*.py` (15) | move + update CLAUDE.md refs | `tools/pipeline_merges/` | med |
| `work/*.csv` | move | `data/inventory/` | low |
| `analysis_pipeline/_launch_*.ps1` etc | move | `pipeline/scratch/` | low |
| root `mods/` + `tools/mod_pipeline/mods/` | consolidate | `mods/` | med (update PLAYBOOK paths) |
| `decompiled_all/` | rename | `decompiled/string_anchored/` | **HIGH** (many refs) |

---

## 5. The highest-value, ZERO-RISK layer: the index + README skeleton

Do this first. No file moves, pure addition. Delivers 80% of the LLM-clarity gain:

1. **`INDEX.md`** — the single entry point. Sections:
   - "If you are an LLM, read this first" — the trust-tier rules, the FACT-source
     locations, the one-line pointers to CLAUDE.md / MANIFEST / MODDING_PLAYBOOK.
   - A one-screen map of the repo with one sentence per directory.
   - "Common tasks -> where to start" table (mod a behavior / find a function /
     understand a system / regenerate data).
2. **`MANIFEST.md`** — every top-level dir + loose file, one row: purpose,
   trust tier (FACT/DERIVED/GUESS/LEAD/SCRATCH), regenerable? y/n.
3. **`_README.md` in each major dir** — purpose, trust tier, read-first pointer.
4. **Rewrite root `README.md`** to match current state (kill the 2026-07-14 stale
   facts and the "Isolated Workspace/" references).

These four additions mean a fresh LLM reads `INDEX.md` and instantly knows: what's
ground truth, what's derived, what's hallucination-prone, and where to start for
any task — before touching a single one of the 7,500 files.

---

## 6. Phased execution (recommended order)

- **Phase 0 (zero risk, do now):** INDEX.md, MANIFEST.md, per-dir `_README.md`,
  rewrite README.md. No moves. Immediate clarity.
- **Phase 1 (low risk):** archive inert scratch (ds.txt, opus_chat.txt,
  _launch_*.ps1, debug_struct*, temp_*, poc_*, old prompts) into `archive/` and
  `pipeline/scratch/`. Move loose data files with their ≤3 ref updates.
- **Phase 2 (med risk):** consolidate `mods/`; move `work/` into `meta/` +
  `tools/pipeline_merges/`, updating CLAUDE.md references.
- **Phase 3 (high risk, deliberate):** relocate `tools/*.csv` -> `data/`, and
  `decompiled_all/` -> `decompiled/string_anchored/`, with a full grep-and-update
  of every hardcoded path. Update CLAUDE.md paths. Run the pipeline + mod tools
  after to confirm nothing broke.

Each phase ends with: `git status` review + a smoke test (run `asm_tools.py
resolve`, `mod_pipeline.py map`, one merge script) to confirm nothing broke.

---

## 7. LLM entry contract (the outcome we're buying)

After Phase 0, a fresh LLM's first three reads are fixed and sufficient:
1. `INDEX.md` — where everything is, what to trust, where to start.
2. `CLAUDE.md` — operational rules + current state.
3. Task-specific: `MODDING_PLAYBOOK.md` (to mod) or a `docs/` file (to understand).

No crawling. No trusting a stale README. No falling for a GUESS-tier label.
That is the definition of "clear for any LLM" for this repo.
```
