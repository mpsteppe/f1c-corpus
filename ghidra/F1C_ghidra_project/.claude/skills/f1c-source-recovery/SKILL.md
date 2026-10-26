---
name: f1c-source-recovery
description: Recover original source structure and class/method names for F1C — trace-string mining, binary forensics, SDK cross-reference — inside the isolated source_recovery/ workspace. Use when a task says "recover original names", "mine the trace log", "raise the trace level", "map source files to functions", or names a source_recovery/ task ID (BF/CB/SDK/DLL/AT/CS). Do NOT use for general runtime tracing or Frida agents — use f1c-frida-trace; for logging corrections to existing docs — use f1c-doc-audit; for sibling-binary comparison — use f1c-port-sibling.
---

# Recover original source structure and names

## When to use / when not

Use for any work under `source_recovery/` and for trace-string name mining (the
game's own debug trace carries ORIGINAL class::method names + file/line). Route out:
building/watching Frida agents → f1c-frida-trace; applying a confirmed rename to
docs/ → that happens in a separate merge session, never here.

## Workspace isolation (quoted verbatim — do not paraphrase)

From `source_recovery/README.md`:

> **Rule: nothing in this directory writes to `docs/` or `analysis_pipeline/`.**

From `source_recovery/ACTION_PLAN.md` §Session Handoff Rules:

> **No task modifies `docs/` directly.** All doc changes go through `FINDINGS.md` -> `work/CHANGELOG.md` -> merge.

Findings exit ONLY via: record in `FINDINGS.md` with evidence → add a `[MERGE-READY]`
tag → a separate session applies it to `docs/` via `work/CHANGELOG.md`
(source_recovery/README.md §How Results Flow Out). Validated names become renames via that merge —
never by editing docs from this workspace.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| Workspace + master plan present | `ls /c%USERPROFILE%/Desktop/F1C_ghidra_project/source_recovery` | `ACTION_PLAN.md`, `FINDINGS.md`, dirs `01_binary_forensics/` … `06_community_sources/` |
| Static mining input present | `ls /c%USERPROFILE%/Desktop/F1C_ghidra_project/tools/ida_strings.csv` | file exists (strings with `ref_funcs` column) |

## Procedure

### Step 1: Claim a task in the master plan
Read `source_recovery/ACTION_PLAN.md`, pick a `TODO` task, set its status to
`ACTIVE` with the session date (§Session Handoff Rules; statuses: TODO / ACTIVE /
DONE / BLOCKED(reason)). The plan is the single source of truth — no side TODO lists.
Workspace layout and per-subdir read/write boundaries: source_recovery/README.md §Directory Map and
§Relationship to Other Directories.

### Step 2: Static trace mining first (no game needed)
Mine `tools/ida_strings.csv` — its `ref_funcs` column maps each string to the
functions referencing it. Two harvests, per work/DISCOVERY_external_sources.md
§SOURCE 1 — The game's own debug trace system:
- `Entered Class::Method()` strings → a direct address→original-name rename table.
- `.cpp` path strings → a source-file→function-set map; combined with address
  adjacency this assigns source files to whole address ranges.
Expected output: rename candidates recorded in `FINDINGS.md` with the string
evidence. If instead `ref_funcs` is empty for a string → that string has no
captured xref; do not guess an owner.

### Step 3: (Optional) unlock the trace-level clamp
The in-game trace level is clamped; to raise it, patch the clamp:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/patch_trace.py --level 10 --dry
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/patch_trace.py --level 10
```
Expected output: `--dry` shows the two byte edits without writing; the real run
patches the exe IN PLACE, backing up to `<exe>.bak` once. Level must be 1..255.
If instead you see `WARNING: expected both 0x02; already patched or wrong
exe/offsets` → STOP; the exe is already patched or is the wrong build — do not
force it. Revert any time with:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/patch_trace.py --restore
```
If `--restore` prints `no .bak found next to exe` → there is nothing to revert from;
report before touching the exe further.

### Step 4: Archive the previous trace BEFORE any traced run
`LOG/trace.txt` in the game install is OVERWRITTEN on every run
(work/BREAKTHROUGH_trace_mining.md §Runtime procedure (after static mining)):
```bash
mkdir -p /c%USERPROFILE%/Desktop/F1C_ghidra_project/source_recovery/05_automation/results && cp "/c%USERPROFILE%/Desktop/F1 Challenge V10/LOG/trace.txt" /c%USERPROFILE%/Desktop/F1C_ghidra_project/source_recovery/05_automation/results/trace_$(date +%Y%m%d_%H%M%S).txt
```
Expected output: silent copy; the timestamped file exists in `results/`.
If instead the source file is missing → no prior trace exists; note it and continue.

### Step 5: LIVE: capture a trace run
Requires launching the game. Per `_meta/toolfacts.md` §tools/patch_trace.py: after
patching, launch the game with the `notrace` cmdline arg to ENABLE tracing, then
read `LOG/trace.txt`. Expected output: a fresh `LOG/trace.txt` beginning
`TRACE LEVEL = <N>` followed by `<file>.cpp <line>: <message>` lines with original
class::method names. If the game cannot be run now → STOP here; Steps 1–4 already
produced verifiable static findings — record them and report which runtime facts
remain uncaptured.

### Step 6: Mine the captured trace
Archive the new trace (repeat Step 4's copy). Join trace lines back to addresses
via the same `ida_strings.csv` `ref_funcs` mapping (each logged format string is
referenced by the function that emits it). Record confirmed `address → Class::Method
(file:line)` rows in `FINDINGS.md` with the trace line as evidence.

### Step 7: (Deliberate, outside isolation) regenerate the state-machine doc
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/trace/extract_state_machines.py
```
Expected output: scan progress; **writes/overwrites `docs/15-state-machines.md`
directly** — this tool is a doc-generator, an explicit exception to workspace
isolation. Run it ONLY when the task is to regenerate docs/15, never as a casual
side effect of recovery work. If that is not your task → skip this step.

### Step 8: Close out
Set the ACTION_PLAN task to `DONE` (or `BLOCKED(reason)` — never silently
incomplete), ensure every finding is in `FINDINGS.md` with evidence, and tag
merge-worthy ones `[MERGE-READY]`. Do not apply them to `docs/` yourself.

## STOP — do not proceed if

- You are about to write to `docs/` or `analysis_pipeline/` from this workspace →
  forbidden (isolation rule above); the only exception is the deliberate Step 7 tool.
- The game is not running/launchable but the next step is `LIVE:` → stop, report
  which facts remain unverified; static findings still count.
- `patch_trace.py` warns the clamp bytes are not as expected → wrong exe or already
  patched; investigate, do not force.
- You are about to run a traced session without archiving `LOG/trace.txt` → archive
  first; the run destroys the previous capture.
- A rename seems confirmed and you want to edit docs/ "while you're here" →
  forbidden; `[MERGE-READY]` in `FINDINGS.md`, separate merge session.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| `WARNING: expected both 0x02; already patched or wrong exe/offsets` | exe already patched or wrong build | check for `<exe>.bak`; `--restore` if present; else report |
| `no .bak found next to exe` on `--restore` | never patched from this tool | nothing to revert; verify exe state before further patching |
| `LOG/trace.txt` missing after a run | tracing not enabled at launch | re-check the launch arg per toolfacts §tools/patch_trace.py |
| Trace shows a level lower than patched | launch arg overrode/reset the level | re-read toolfacts; capture the exact command line used and report |
| String has empty `ref_funcs` | xref not captured in the IDA export | leave unmapped; note in FINDINGS.md; do not guess |

## Deep reference

Read `reference.md` in this skill's directory for the trace-line anatomy, the
FINDINGS.md evidence format, the full source-inventory of the three external
sources, and the known `trace=%d` vs `notrace` launch-arg discrepancy.

---
Canonical sources: source_recovery/README.md §How Results Flow Out; source_recovery/README.md §Directory Map; source_recovery/ACTION_PLAN.md §Session Handoff Rules; work/DISCOVERY_external_sources.md §SOURCE 1 — The game's own debug trace system; work/BREAKTHROUGH_trace_mining.md §Runtime procedure (after static mining); _meta/toolfacts.md §tools/patch_trace.py; _meta/toolfacts.md §tools/trace/extract_state_machines.py
Last validated: 2026-07-18 against 6bcccfe
