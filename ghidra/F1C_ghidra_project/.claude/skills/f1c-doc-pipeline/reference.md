# f1c-doc-pipeline — deep reference

Companion to `SKILL.md`. Everything here is copied/derived from REFERENCE.md
(§Parallel Worker Workflow, §Batch Launcher Modes, §Known Pitfalls, §Doc Entry
Formats) and `_meta/toolfacts.md` §analysis_pipeline batch entry points. When this
file and those sources disagree, the sources win — flag the drift via
f1c-skill-maintenance.

## Per-stage expected console output

| Stage | Invokes | What success looks like |
|---|---|---|
| `0_bundle.bat` | `bundle_small.py` | packs small `.c` files from `not_analyzed/` into bundles; ends `Press any key to continue . . .` |
| `0r_gen_queue.bat` | `generate_review_queue.py` | writes `work/review_queue.jsonl` (full-entry queue); ends with `pause` |
| `1_batch_gui.bat` | `batch_launcher.py` | Tkinter window opens; console stays silent; NO `pause` |
| `2_merge.bat` | `merge_to_docs.py` | per-entry routing log; skip lines for existing `## FUN_`; archive message; then a `--subdir ida_gaps --archive` pass IF `output/ida_gaps/worker_A.md` exists; then knowledge-graph rebuild output; `pause` |
| `5_move_analyzed.bat` | `merge_to_docs.py --move-only` | list of files moved `not_analyzed/` → `analyzed/`; `pause` |

`merge_to_docs.py` flags (run only via the `.bat`s in normal operation; direct flags
documented in `_meta/toolfacts.md`):

- (no flags) — merge `output/worker_[A-U].md` (+`_batchN`) into `docs/` per
  `<!-- target: docs/xx.md -->`, skip existing `## FUN_` addrs, append triage lines
  to `decompiled_full_index_final.md`, run `move_analyzed()`, archive + reset workers.
- `--move-only` — only the `not_analyzed/` → `analyzed/` sync.
- `--subdir NAME` — merge from `output/<NAME>/`; by default prints
  `Subdir mode — files NOT archived or cleared.`
- `--archive` — with `--subdir`, archive after merging like standard mode.

## Worker output format (what a healthy worker file looks like)

From REFERENCE.md §Parallel Worker Workflow:

```
=== TRIAGE LINES ===
(blank for Full Entry / Deep Dive modes)

=== FULL ENTRIES ===
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Name
...
```

Merge behavior: triage lines append to `docs/decompiled_full_index_final.md`; full
entries route to the doc named in the nearest preceding `<!-- target: -->` comment;
addresses already present as `## FUN_` headers are skipped (duplicate detection
checks `## FUN_` headers ONLY — not mentions inside Calls/Globals sections, per
REFERENCE.md §Rules); worker files are archived to `output/archive/TIMESTAMP/`.

Entry body format: REFERENCE.md §Doc Entry Formats (full `## FUN_` template,
lightweight `### FUN_` template, triage-line format). Do not invent a variant.

## Known worker failure fixes (REFERENCE.md §Known Pitfalls, quoted commands)

1. **Non-FUN_ headers** — workers sometimes write `## Unwind_XXXXXX`,
   `## thunk_FUN_...`, or a library name as the header. `merge_to_docs.py` only
   splits on `## FUN_` — these break routing. Recovery (from §Known Pitfalls):

   ```bash
   cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && sed -i 's/Unwind_\([0-9a-f]*\)/FUN_\1/' output/worker_X.md
   ```

   Inspect the file after — headers that are neither `FUN_` nor `Unwind_` (e.g. a
   guessed name) must be rewritten by hand to `## FUN_<8-hex-address>` using the
   address from the source filename.

2. **Double `.md` extension** — `<!-- target: docs/20-math-utilities.md.md -->`.
   The merge silently skips these entries. Fix before merging (from §Known Pitfalls):

   ```bash
   cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && sed -i 's/\.md\.md/.md/g' output/worker_X.md
   ```

3. **Stalled worker** — entry count far below assigned means the worker hit its
   context limit. Resume snippet (from REFERENCE.md §Parallel Worker Workflow; run
   with cwd = `analysis_pipeline/`):

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

   Write a new prompt containing only `remaining`, launch a fresh DS instance,
   have it append to the SAME worker file.

## Common merge errors

| Merge log symptom | Meaning | Action |
|---|---|---|
| `No worker output files found in <dir>` | nothing matching `worker_[A-U].md` in `output/` | find where the worker actually wrote; move the file; re-run merge |
| Entry visibly missing from target doc after merge | its address already had a `## FUN_` header (intended skip) OR its target comment was malformed | grep the target doc for the address first; if absent, inspect the archived worker file's `<!-- target: -->` line |
| Graph rebuild (inside `2_merge.bat`) errors on a docs file | malformed merged entry | fix the doc entry, log `[CORRECTION]` in `work/CHANGELOG.md`, re-run `python tools/knowledge_graph/rebuild.py` from project root |

## Mode selection and per-mode merge routing

The GUI mode list changes as modes are added; counts quoted anywhere (11, 26, 31…)
go stale. **Ground truth is the GUI's own mode list — i.e. `batch_launcher.py`'s
`_generate()` dispatch dict** — read it at run time. REFERENCE.md §Batch Launcher
Modes documents only a subset; use it for the semantics of the modes it covers and
flag the gap for f1c-doc-audit. Newer modes write to per-mode dirs
`output/<mode_id>/worker_X.md` + `prompts/<mode_id>/worker_X_prompt.md`.

Merge routing is NOT one-size-fits-all:

- **`## FUN_`-format modes** (triage/review/deepdive/stub_upgrade/ida_gaps…) merge
  via `merge_to_docs.py` (`2_merge.bat` for standard + ida_gaps;
  `--subdir <mode_id> --archive` for other per-mode dirs).
- **Special-format modes** have dedicated merge scripts in `work/` — impl_spec →
  `work/merge_impl_spec.py`, call_chain → `work/merge_call_chain.py`,
  global_validate(_2) → `work/merge_global_validate.py --subdir global_validate_2`,
  struct_audit → `work/merge_struct_audit.py`, arch_narrative →
  `work/merge_arch_narrative.py`, orphan_resolve → `work/merge_orphan_resolve.py`.
  Invocation list: REFERENCE.md §Key Commands (and work/_README.md §Merge scripts).
- **xbin_delta / `## sub_` output** merges ONLY via
  `cross_binary/scripts/merge_xbin_delta.py` — `merge_to_docs.py` splits on
  `## FUN_`/`### FUN_` and silently drops every `## sub_` entry, then archives the
  worker files. Contract: `_meta/toolfacts.md` §cross_binary/scripts/merge_xbin_delta.py;
  workflow: f1c-port-sibling.

The `grep -c '^## FUN_'` completion check and the stalled-worker resume snippet
above are `## FUN_`-mode-only — for other modes substitute the entry-header pattern
the mode's prompt mandates (check `prompts/<mode_id>/worker_X_prompt.md`).

---
Canonical sources: REFERENCE.md §Parallel Worker Workflow; REFERENCE.md §Known Pitfalls; REFERENCE.md §Batch Launcher Modes; REFERENCE.md §Key Commands; REFERENCE.md §Doc Entry Formats; REFERENCE.md §Rules; _meta/toolfacts.md §analysis_pipeline batch entry points; _meta/toolfacts.md §cross_binary/scripts/merge_xbin_delta.py
Last validated: 2026-07-20 against 6bcccfe
