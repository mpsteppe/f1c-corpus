---
name: f1c-frida-trace
description: Trace live F1 Challenge execution REVERSIBLY with Frida — watch what WRITES a function/global, capture frame order and timing, and apply memory patches that survive integrity checks. Use when a task says "trace what runs each frame", "watch what writes this global live", "test a memory patch without touching the exe", or "capture a race trace". Do NOT use to author or gate a mod plan (use f1c-mod-lifecycle), to bake a confirmed patch to a copy of the exe (use f1c-byte-patch), to read/write single values without an agent (use f1c-live-probe), or to raise the trace level and mine original Class::Method names (use f1c-source-recovery).
---

# Trace live execution reversibly with Frida

## When to use / when not

- Use for: reversible runtime observation and testing — Frida hooks functions, watches
  globals, streams CSV rows, and applies memory patches that vanish when you detach. This
  is the "test first" half of the mod loop and the way to capture behavior safely.
- Frida-first doctrine: a Frida memory patch is reversible AND survives the on-disk
  integrity checks a patched exe trips. ALWAYS confirm behavior with a Frida `.js` before
  baking anything to disk. Bake to a copy only after live confirmation (→ `f1c-byte-patch`).
- Route out: design/gate a mod → `f1c-mod-lifecycle`. Bake a confirmed patch → `f1c-byte-patch`.
  Named single-value reads/writes without an agent → `f1c-live-probe`.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| frida installed | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python -c "import frida; print(frida.__version__)"` | prints a version (e.g. `17.x`); if `ModuleNotFoundError` → `pip install frida frida-tools` |
| game running | (visual) game window in a session | required for every `LIVE:` step below |
| admin (comprehensive) | run terminal as Administrator | `trace_comprehensive.py` and some attaches need it |

Use plain `python` (PATH, 3.12) — it has frida. Both interpreters have frida; `python` is the safe default.

## Procedure

### Step 1: Choose the tracer for the job

- Function-call / state trace, interactive or N frames → `tools/trace/f1c_trace.py`.
- 10-minute full-race capture (installs hooks after RUNNING) → `tools/trace/trace_comprehensive.py`.
- Seed-driven CSV watcher for specific globals/struct fields → `tools/mod_pipeline/watch_run.py`
  with an agent from `mod_pipeline.py watch`.
- Recover ORIGINAL names by raising the game's own trace level → NOT this skill; that
  name-mining workflow is owned by `f1c-source-recovery` (see Step 5 route-out).

### Step 2: LIVE — capture a function/state trace

`LIVE:`
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/trace/f1c_trace.py --frames 3000 -o race_trace.log
```
Expected output: per-frame lines to console, log saved under `tools/trace/output/`.
Flags: `--state` (read state vars and exit), `--state-only` / `-S` (watch state writes only,
tiny output), `--quiet` / `-q` (suppress console, still writes), `--list-threads`.
If instead you see `ERROR: '...exe' not running.` → start the game first (this is a `LIVE:` step).
If you see `ERROR: Permission denied. Run as Administrator.` → relaunch the terminal as admin.

### Step 3: LIVE — comprehensive race capture (optional)

`LIVE:` Run the terminal as Administrator.
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/trace/trace_comprehensive.py --duration 600
```
Expected output: waits for RUNNING, installs hooks, writes a `comprehensive_<TS>_<dur>s.log`
into `tools/trace/output/`.
`--launch` starts the game itself (spawns the process) with trace args; omit it if the game is already up.
If instead you see `ERROR: '...' not found after 60s.` → the game did not reach RUNNING; start a session.

### Step 4: Analyze the trace offline (no game)

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/trace/analyze_trace.py tools/trace/output/<file>.log --summary
```
Expected output: parsed summary to stdout. `--frame N`, `--threads`, `--doc PATH` (writes a
generated markdown doc). If instead you see `No trace entries found.` → wrong/empty log file.

### Step 5: Raising the trace level → route out to f1c-source-recovery

Raising the game's trace clamp to recover ORIGINAL `Class::Method` names is a name-mining
workflow OWNED by `f1c-source-recovery` — it drives `patch_trace.py --level`/`--restore`,
launches the game with tracing, and mines `LOG/trace.txt`. Hand that whole workflow there.
Only the essentials a frida-trace user must know if they touch the exe patch at all:

1. Archive `LOG/trace.txt` FIRST — it is overwritten every run. Use a TIMESTAMPED copy so
   reruns do not self-clobber, e.g. copy it into `tools/trace/output/` as
   `trace_YYYYMMDD_HHMMSS.txt` (never a fixed name).
2. `patch_trace.py --level N` edits two immediate bytes IN the exe (backs up to `<exe>.bak`
   once). If it warns `expected both 0x02; already patched or wrong exe/offsets` → STOP;
   wrong exe or already patched.
3. `LIVE:` the game must be launched with the `notrace` cmdline arg to ENABLE tracing. When
   done, revert the exe with `python tools/patch_trace.py --restore`.

For anything beyond these three notes (the mining recipe, name→address mapping, renames),
STOP and use `f1c-source-recovery` — it carries the canonical procedure.

### Step 6: Graduate a confirmed Frida patch to a baked copy

Once a Frida memory patch produces the confirmed in-game observable, and only then, bake it
to a COPY of the exe via `f1c-byte-patch` (same edits, `apply_*.py` verifies originals).
Keep the `.js` — it stays the reversible reference and in-session undo.

## STOP — do not proceed if

- About to rerun with the SAME `-o` output name, or raise the trace level without first
  archiving `LOG/trace.txt` → stop; archive only the file that would be overwritten (a distinct
  `-o` name for each `f1c_trace.py` run does not clobber; `LOG/trace.txt` always does).
- About to bake a patch to disk before Frida-confirming it live → stop; Frida-first is the doctrine.
- `patch_trace.py` warns the bytes are not the expected originals → stop; wrong exe or already patched.
- Game not running but the step is `LIVE:` → stop; report what remains uncaptured.
- About to run `patch_trace.py` (or any exe patch) on the ORIGINAL with no `.bak` route → confirm the backup exists first.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| `ModuleNotFoundError: No module named 'frida'` | frida not installed | `pip install frida frida-tools` |
| `ERROR: '...exe' not running.` | game not started | launch the game into a session (`LIVE:`) |
| `ERROR: Permission denied. Run as Administrator.` | attach needs elevation | relaunch terminal as admin |
| `no .bak found next to exe` (on `--restore`) | never applied, or `.bak` deleted | nothing to restore; verify the exe path |
| trace.txt unchanged after raising level | game launched without `notrace` arg | relaunch with the `notrace` cmdline switch (it ENABLES tracing) |

## Deep reference

Read `reference.md` in this skill's directory for the `agent.js` anatomy (hook-map shape,
CSV emit), how to read a sample trace, the `watch_run.py` interactive command set, and the
patch_trace clamp mechanics.

---
Canonical sources: _meta/toolfacts.md §tools/trace/f1c_trace.py, §tools/trace/trace_comprehensive.py, §tools/trace/analyze_trace.py, §tools/mod_pipeline/watch_run.py, §tools/patch_trace.py; work/BREAKTHROUGH_trace_mining.md §Discovery 1: Built-In Trace Logging (THE BIG ONE), §Runtime procedure (after static mining); work/DISCOVERY_external_sources.md §SOURCE 1 — The game's own debug trace system
Last validated: 2026-07-18 against 6bcccfe
