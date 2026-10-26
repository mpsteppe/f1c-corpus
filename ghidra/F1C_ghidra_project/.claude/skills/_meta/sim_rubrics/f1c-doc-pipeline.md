# Rubric: f1c-doc-pipeline

Task prompt: "Worker output from yesterday's deepdive batch is sitting in
analysis_pipeline/output/ (workers A–D). Worker C looks short. Get everything
merged into docs and make the downstream tooling consistent again."

Expected steps (in order):
1. Reads the skill; checks `analysis_pipeline/output/` contents (`ls`) instead of
   generating new prompts — recognizes this is a mid-run resume at Step 4.
2. Verifies completion per worker:
   `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && grep -c '^## FUN_' output/worker_C.md`
   (and A/B/D), compares against the counts assigned in `prompts/worker_C_prompt.md`.
3. For the short worker C: identifies it as a stalled worker; builds a resume
   prompt using the snippet from `reference.md` / REFERENCE.md §Parallel Worker
   Workflow (or reports that worker C must be resumed before merge) — does NOT
   merge a half-finished worker silently without flagging it.
4. Scans worker files for the two known drifts (non-`FUN_` headers, `.md.md`
   targets) and fixes them per REFERENCE.md §Known Pitfalls before merging.
5. Merges: `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline && cmd //c 2_merge.bat`.
6. Syncs corpus: `cmd //c 5_move_analyzed.bat` (same cwd).
7. Rebuilds graph then SDK, in that order:
   `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/knowledge_graph/rebuild.py`
   then `python tools/gen_sdk.py`.
8. Reports counts merged/skipped and worker C's resume status.

Forbidden actions:
- Writing or pasting any entry into `docs/` by hand.
- Re-documenting an address that already has a `## FUN_` header.
- Moving/renaming `analysis_pipeline/` directories, or editing the `.bat` files'
  hardcoded Python paths.
- Skipping `python tools/gen_sdk.py` after the merge.
- Running `0_bundle.bat` / `1_batch_gui.bat` to regenerate prompts when output
  already exists unmerged.

Pass criteria:
- Merge performed only via `2_merge.bat` (cwd `analysis_pipeline/`, `cmd //c`).
- Stalled worker C detected from entry-count vs prompt, and handled (resume or
  explicit flag) rather than ignored.
- Format-drift check happens BEFORE the merge, not after.
- Graph rebuild AND SDK regeneration both run after the merge, in that order.
- Does not interpret zero moves in Step 6 (`5_move_analyzed.bat`) as a failed
  merge — merge success is judged from Step 5's own log.
- Does not run Steps 1–3 (bundle/queue/Generate) on this mid-run resume —
  Generate would overwrite the prompts the completion check needs.
- Final report states what merged, what was skipped as duplicate, and what
  remains outstanding for worker C.
