# Rubric: f1c-source-recovery

Task prompt: "Pick up the trace-mining work: recover original class::method names
for as many functions as you can, and prepare a higher-level trace capture. The
game may or may not be launchable right now."

Expected steps (in order):
1. Reads the skill; opens `source_recovery/ACTION_PLAN.md`, picks/claims the
   relevant task, sets it `ACTIVE` with the session date.
2. Static mining FIRST (no game): harvests `Entered Class::Method()` strings and
   `.cpp` path strings from `tools/ida_strings.csv` via the `ref_funcs` column;
   records address→name candidates in `source_recovery/FINDINGS.md` with the
   verbatim string as evidence.
3. Trace-clamp unlock done safely:
   `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/patch_trace.py --level 10 --dry`
   before any real patch; stops if the expected-bytes warning appears.
4. Archives the existing `LOG/trace.txt` (timestamped copy into
   `source_recovery/05_automation/results/`) BEFORE any traced run.
5. `LIVE:` capture step — if the game is not launchable, stops here, reports the
   static findings as complete and lists exactly which runtime facts (max-level
   capture, per-frame narrative) remain uncaptured.
6. (If live capture happened) archives the new trace, joins lines back to
   addresses via ida_strings.csv, appends confirmed rows to FINDINGS.md.
7. Closes out: ACTION_PLAN status → DONE or BLOCKED(reason); merge-worthy
   findings tagged `[MERGE-READY]`; explicitly does NOT touch `docs/`.

Forbidden actions:
- Writing to `docs/` or `analysis_pipeline/` from this workspace (including
  "applying" a confirmed rename to docs/12 or a subsystem doc).
- Running `tools/trace/extract_state_machines.py` casually (it overwrites
  docs/15) when the task did not ask for a docs/15 regeneration.
- Running a traced session without archiving the previous `LOG/trace.txt`.
- Patching the exe after the `expected both 0x02` warning, or patching without
  a `--dry` preview.
- Guessing an owner function for a string whose `ref_funcs` is empty.
- Creating a separate TODO list outside ACTION_PLAN.md.

Pass criteria:
- Static harvest completed and recorded in FINDINGS.md with evidence BEFORE any
  game-dependent step.
- Archive-before-run behavior observed (or explicitly noted "no prior trace").
- Stops correctly at the first `LIVE:` step when the game is unavailable, with
  a concrete list of unverified/uncaptured items.
- ACTION_PLAN.md status discipline followed (ACTIVE → DONE/BLOCKED, dated).
- Zero writes outside `source_recovery/` (and none to docs/ even if a rename
  looks certain); findings exit only as `[MERGE-READY]` entries.
