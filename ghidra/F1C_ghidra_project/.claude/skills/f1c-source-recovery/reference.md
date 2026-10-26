# f1c-source-recovery — deep reference

Companion to `SKILL.md`. Sources: source_recovery/README.md + ACTION_PLAN.md,
work/DISCOVERY_external_sources.md, work/BREAKTHROUGH_trace_mining.md,
`_meta/toolfacts.md`. When this file and those disagree, the sources win — flag
via f1c-skill-maintenance.

## Trace-line anatomy

A `LOG/trace.txt` capture starts with a `TRACE LEVEL = <N>` header, then lines of
the shape:

```
<sourcefile>.cpp <line>: <message>
```

Lifecycle messages look like `Entered Game::Enter()` — i.e. ORIGINAL class name +
method name, with the emitting source file and line. A level-2 sample exists in the
game install's `LOG/` dir (per work/DISCOVERY_external_sources.md §SOURCE 1 — The
game's own debug trace system, which quotes it verbatim). Higher levels are expected
to narrate per-frame subsystem calls — a self-narrating execution trace with real
names.

## The static half lives in ida_strings.csv

`tools/ida_strings.csv` columns: `addr,length,encoding,value,ref_funcs`, where
`ref_funcs` is a `|`-separated list of function addresses referencing the string.
Two string families matter (both enumerated with examples in DISCOVERY §SOURCE 1):

1. **`Entered Class::Method()` strings** — each is referenced by exactly the
   function it names. This is a direct rename table: parse string → owning
   function address → original name. Confirmed-by-string renames are the
   strongest name evidence in the project (see the `[CORRECTION]` examples in
   `_meta/doc-anchors.md` §Correction corpus where trace strings overturned
   invented labels and even an invented class).
2. **Source-path strings** (`...\Source\<file>.cpp`) — referenced by every
   function whose asserts/logs live in that file. This is a lower bound per file;
   functions from one `.cpp` are contiguous in `.text`, so combine with address
   adjacency to assign whole address RANGES to source files. Cross-check against
   the inferred source tree doc rather than replacing it blind.

The trace machinery itself (init/level function, cmdline parser, the two emit
functions) is identified with addresses and evidence in DISCOVERY §SOURCE 1 —
read the current identifications there; do not rely on a copy here. Mining ALL
call sites of the two emit functions harvests the original naming scheme far
beyond the lifecycle strings.

## Known launch-arg discrepancy (`trace=%d` vs `notrace`)

- DISCOVERY §SOURCE 1 documents `trace=%d` and `notrace` as the two command-line
  parameters, with `trace=%d` setting the level.
- `_meta/toolfacts.md` §tools/patch_trace.py (the validated tool contract) says:
  after patching, "launch the game with the `notrace` cmdline arg to ENABLE
  tracing, then read `LOG/trace.txt`."
- `tools/trace/trace_comprehensive.py --launch` starts the game with
  `-trace=2 -noplayer` (toolfacts §tools/trace/trace_comprehensive.py) — an
  automated alternative launch path.

Follow toolfacts first (it is the verified contract). If a run produces no trace,
try the `trace=<N>` form next, and record which invocation actually worked in
`FINDINGS.md` — then flag the toolfacts section for regeneration via
f1c-skill-maintenance. Do not silently pick one and report failure.

## FINDINGS.md evidence format

Per source_recovery/README.md §How Results Flow Out, a finding must be recorded
WITH evidence before it can be tagged. A good rename row carries:

```
[2026-07-18] <addr> -> Class::Method (<file>.cpp:<line>)
  Evidence: ida_strings.csv row "<verbatim string>" ref_funcs contains <addr>;
            trace line "<verbatim trace line>" (archived capture <filename>)
  Docs impact: current docs label is "<label>" in docs/<NN> -> rename candidate
  [MERGE-READY]
```

Only `[MERGE-READY]`-tagged findings are eligible for the separate merge session,
which applies them to `docs/` and logs them in `work/CHANGELOG.md` (as
`[CORRECTION]` where an existing doc claim was wrong). This session never edits
`docs/` itself.

## The three external sources (context for prioritization)

work/DISCOVERY_external_sources.md is the authoritative writeup; its §Revised
project assessment carries the priority order. In one line each:

1. **§SOURCE 1 — the game's own debug trace system**: original names + file/line,
   partly mineable statically (this skill's Steps 2–6). Highest value, cheapest.
2. **§SOURCE 2 — community RE work already present in the install**: injector,
   Lua mod, Java telemetry plugin, wheel DLL — their configs encode
   independently-discovered memory offsets = free cross-validation of docs/12+13.
   Maps to ACTION_PLAN task CS-01.
3. **§SOURCE 3 — ISI gMotor engine-family Rosetta stone**: rFactor-family file
   format specs as field-name hypotheses for docs/08 + docs/13. Community claims
   are hypotheses — confirm against the binary, then document.

Note: work/BREAKTHROUGH_trace_mining.md is a truncated near-duplicate of the
DISCOVERY file (it ends mid-Discovery-2). Cite BREAKTHROUGH only for its
§Runtime procedure (after static mining) archive warning; cite DISCOVERY for
Sources 2–3 and the priority order.

## Workspace subdir boundaries (source_recovery/README.md §Relationship to Other Directories)

Each numbered subdir has an explicit reads-from / never-writes-to contract —
e.g. `05_automation/` reads `tools/trace/` but never writes to it; forensics and
community-source dirs never write `docs/` or `work/`. Check the table before a
task touches anything outside `source_recovery/`.

---
Canonical sources: work/DISCOVERY_external_sources.md §SOURCE 1 — The game's own debug trace system; work/DISCOVERY_external_sources.md §SOURCE 2 — Community RE work already present in the install; work/DISCOVERY_external_sources.md §SOURCE 3 — ISI gMotor engine-family Rosetta stone; work/DISCOVERY_external_sources.md §Revised project assessment; work/BREAKTHROUGH_trace_mining.md §Runtime procedure (after static mining); source_recovery/README.md §Relationship to Other Directories; source_recovery/README.md §How Results Flow Out; _meta/toolfacts.md §tools/patch_trace.py
Last validated: 2026-07-18 against 6bcccfe
