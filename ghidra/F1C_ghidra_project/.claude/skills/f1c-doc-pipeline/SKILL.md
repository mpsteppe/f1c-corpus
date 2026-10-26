---
name: f1c-doc-pipeline
description: Operate the DS-worker batch documentation pipeline (bundle → queue → batch GUI → workers → merge → graph + SDK rebuild). Use when a task says "run the doc pipeline", "launch DS workers", "merge worker output", "document these functions in batch", or "run 2_merge". Do NOT use for auditing accuracy of existing docs — use f1c-doc-audit; for verifying a single claim — use f1c-verify-claim; for sibling-binary delta documentation, read f1c-port-sibling first (same batch GUI, different worker rules AND a different merge script — cross_binary/scripts/merge_xbin_delta.py; merge_to_docs.py drops ## sub_ entries).
---

# Run the DS-worker documentation pipeline

## When to use / when not

Use for any batch documentation run: triaging/documenting F1C functions with DeepSeek
workers and merging their output into `docs/`. Not for hand-writing a single doc entry
(follow REFERENCE.md §Doc Entry Formats directly) and not for doc QA (f1c-doc-audit).

## Iron rules (quoted verbatim from CLAUDE.md §Iron rules — do not paraphrase)

> 7. Never re-document an address already in `docs/` (check `## FUN_` header first).
>    Workers write to `analysis_pipeline/output/`, never directly to `docs/`.
>    Flag doc errors in `work/CHANGELOG.md` as `[CORRECTION]`.

And from `analysis_pipeline/_README.md` §Path warning (verbatim):

> `analyzed/` and `output/` are referenced by hardcoded paths in the pipeline
> scripts and CLAUDE.md — do not move them without updating references.

The `.bat` files hardcode their own Python interpreters (two different ones; both
resolve — see `_meta/toolfacts.md` §Python interpreters). Never "fix" those paths.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| Pipeline dir intact | `ls /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline` | `analyzed/`, `output/`, `prompts/`, the five `.bat` files |
| No unmerged leftovers | `ls /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline/output` | empty or only subdirs you expect; stray `worker_X.md` = a previous run was never merged — investigate before generating new prompts |

## Procedure

**Mid-run resume:** if `output/` already holds worker files, do NOT run Steps 1–3 —
the GUI's Generate overwrites the `prompts/worker_X_prompt.md` files that Step 4's
completion check depends on. Start at Step 4.

### Step 1: Bundle small files and build the queue
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && cmd //c 0_bundle.bat
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && cmd //c 0r_gen_queue.bat
```
Expected output: bundling / queue-generation progress, ending with `Press any key to
continue . . .` (press Enter — every pipeline `.bat` except the GUI ends with `pause`).
If instead you see a Python "not found" error → the hardcoded interpreter is broken on
this machine; STOP and report — do not edit the `.bat`.

### Step 2: Launch the batch GUI and generate prompts
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && cmd //c 1_batch_gui.bat
```
Expected output: a Tkinter window (no console pause). In the GUI: pick a mode. The
GUI's own mode list (= `batch_launcher.py`'s dispatch) is the ground truth — it has
grown well past the modes REFERENCE.md §Batch Launcher Modes documents; use that
section only for the semantics of the modes it covers, and flag the REFERENCE gap
for f1c-doc-audit. Set worker count (max 20, letters A–T), Generate. Prompts are
saved under `prompts/` (per-mode subdir for newer modes).
If instead no window appears → you are in a session without a display; STOP and ask
the user to run the GUI, or report which prompts are needed.

### Step 3: Run the workers
Per REFERENCE.md §Parallel Worker Workflow: for each worker letter, "Launch + Copy
Prompt" and paste into a DeepSeek instance. Workers write ONLY to
`analysis_pipeline/output/worker_<LETTER>.md` (or `output/<mode>/worker_<LETTER>.md`),
in the `=== TRIAGE LINES === / === FULL ENTRIES ===` format with `<!-- target: -->`
comments. Worker conduct rules: roles/WORKER.md §RULES.

### Step 4: Verify completion BEFORE merging
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && grep -c '^## FUN_' output/worker_A.md
```
Expected output: a count close to the number of functions assigned in
`prompts/worker_A_prompt.md`. Repeat per worker. This grep pattern is for
`## FUN_`-format modes ONLY — for other modes, count the entry-header pattern the
mode's prompt actually mandates.
If instead the count is far below assigned → stalled worker (context limit); build a
resume prompt per REFERENCE.md §Parallel Worker Workflow (snippet copied into
`reference.md` in this skill's directory). Also scan for the two known format drifts
(non-`FUN_` headers, `.md.md` targets) — fixes in `reference.md`.

### Step 5: Merge worker output into docs
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && cmd //c 2_merge.bat
```
Expected output: per-file merge log (entries routed via `<!-- target: -->`, addresses
already present as `## FUN_` skipped), worker files archived to `output/archive/`,
then a knowledge-graph rebuild, then `pause`.
If instead you see `No worker output files found` → workers wrote somewhere else;
locate their real output and move it to `output/` — never hand-paste entries into
`docs/`. IMPORTANT: `merge_to_docs.py` handles `## FUN_`-format modes only (subdir
flags in `_meta/toolfacts.md` §analysis_pipeline batch entry points). Special modes
have dedicated merge scripts: impl_spec, call_chain, global_validate(_2),
struct_audit, arch_narrative, orphan_resolve → the matching `work/merge_*.py`
(list + invocations: REFERENCE.md §Key Commands); xbin_delta (`## sub_` output) →
`cross_binary/scripts/merge_xbin_delta.py` ONLY (see f1c-port-sibling —
merge_to_docs.py silently drops `## sub_` entries).

### Step 6: Sync the analyzed corpus (redundant safety pass)
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && cmd //c 5_move_analyzed.bat
```
The Step 5 merge already runs `move_analyzed()`, so **zero moves here is the NORMAL
success outcome** — this step is a redundant safety sync. Expected output: usually
nothing to move, then `pause`. Verify merge success from Step 5's own log (entries
routed/skipped), never from whether this step moves files.

### Step 7: Rebuild the graph, then regenerate the SDK (always, in this order)
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/knowledge_graph/rebuild.py
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/gen_sdk.py
```
Expected output: rebuild progress ending `Done in <t>s`; then a one-line SDK count
summary. `gen_sdk.py` runs on bare invocation and overwrites `mods/sdk/f1c_sdk.h` +
`f1c_sdk.json` — that is the point: after EVERY docs merge the SDK must be
regenerated or poke/preflight run on stale data.
If instead rebuild errors on a docs file → a malformed merged entry; fix the doc,
log `[CORRECTION]` in `work/CHANGELOG.md`, re-run both commands.

## STOP — do not proceed if

- You (or a worker) are about to write to `docs/` directly → forbidden; output goes
  to `analysis_pipeline/output/`, the merge script owns `docs/`.
- An address already has a `## FUN_` header in `docs/` → never re-document it.
- You are about to move/rename `analysis_pipeline/analyzed/`, `output/`, or any
  pipeline dir → forbidden; hardcoded paths break silently.
- You are about to edit a `.bat` to "fix" its Python path → forbidden; both
  hardcoded interpreters resolve (`_meta/toolfacts.md` §Python interpreters).
- Step 4 found format drift or a stalled worker → fix/resume BEFORE Step 5; merging
  drifted output silently drops entries.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| Worker file has `## Unwind_…` / `## thunk_…` / named headers | worker drifted from `## FUN_` format | normalize headers before merge — recovery commands in REFERENCE.md §Known Pitfalls (copied in `reference.md`) |
| `<!-- target: docs/XX.md.md -->` | double `.md` extension drift | fix before merge (merge silently skips these) — see `reference.md` |
| Entry count ≪ assigned | stalled worker | resume prompt — REFERENCE.md §Parallel Worker Workflow |
| `No worker output files found in <dir>` | output written to wrong place | move to `output/`; never hand-edit docs |
| Console hangs after a `.bat` finishes | trailing `pause` | press any key; only `1_batch_gui.bat` has no pause |

## Deep reference

Read `reference.md` in this skill's directory for per-stage expected console output,
the stalled-worker resume snippet, the header/target fix commands, and merge-error
walkthroughs.

---
Canonical sources: CLAUDE.md §Iron rules; REFERENCE.md §Parallel Worker Workflow; REFERENCE.md §Batch Launcher Modes; REFERENCE.md §Known Pitfalls; REFERENCE.md §Doc Entry Formats; REFERENCE.md §Rules; analysis_pipeline/_README.md §Path warning; roles/WORKER.md §RULES; roles/LEAD.md §RULES; REFERENCE.md §Key Commands; _meta/toolfacts.md §analysis_pipeline batch entry points
Last validated: 2026-07-20 against 6bcccfe
