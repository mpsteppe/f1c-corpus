# Skill Authoring Conventions — F1C `.claude/skills/`

Audience for every skill: a **cold session** — a junior/mid engineer or a Sonnet-class
model with zero project memory. Assume they have read nothing. Assume they will follow
instructions literally. Every ambiguity you leave is a future failed mod or corrupted doc.

## Design stance (the one rule that shapes everything)

**Skills are execution shells. Canonical docs are knowledge stores.**

- INLINE in the skill: procedures, exact commands, expected outputs, failure modes,
  recovery steps, STOP conditions. These are stable (CLIs rarely change).
- NEVER inline: addresses, struct offsets, global names+values, mod statuses, function
  labels, enum values. These are volatile and live in exactly one canonical place.
  A skill references them: "read the current list from `mods/_README.md` §Primitives".
- Litmus test: if the fact could be invalidated by a doc merge, a new mod result, or a
  `[CORRECTION]` entry, it does not belong in a skill.
- The ONLY exception: `f1c-debug-failed-mod` case studies, which are explicitly framed
  as "historical snapshot 2026-07" pedagogy, not current state.

## Hard conventions (validator-enforced where marked ✓)

1. **Frontmatter** — `name` (kebab-case, `f1c-` prefix) and `description`. ✓
   Description must contain: one sentence of what, concrete "Use when …" trigger
   phrases, and "Do NOT use for X — use `f1c-<other>`" route-outs. The description is
   all a model sees before invoking; vague description = skill never fires.
2. **Length** — SKILL.md ≤ ~150 lines. ✓ Depth goes to bundled files in the same skill
   directory (`reference.md`, `triage-tree.md`, etc.) with an explicit pointer:
   "Read `reference.md` in this skill's directory if <condition>."
3. **Commands** — every command copy-pasteable and cwd-explicit:
   `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/...`
   Each command carries an "Expected output:" snippet and an "If instead you see … →
   <recovery or STOP>" row. Commands come ONLY from `_meta/toolfacts.md` — never from
   memory, never from docs prose. ✓ (flags checked against argparse)
4. **No volatile facts** — no inlined exe-image addresses (`0x004…`–`0x007…`), struct
   offsets, or mod statuses. ✓ (validator greps `0x00[0-9a-fA-F]{6}` and offset
   patterns; any hit must be inside a citation sentence naming its canonical file, or
   in a file exempted as historical snapshot)
5. **STOP section** — every skill has `## STOP — do not proceed if` with hard
   conditions and what-to-do-instead. ✓ Non-negotiable entries where relevant:
   - any `preflight.py` fact FAILs → fix the fact, not the code
   - `patch.py` reports FOREIGN bytes → wrong exe or stale manifest; investigate
   - about to call a game-internal function from injected code → forbidden, re-read ladder
   - about to write to `docs/` as a worker/author → forbidden, output goes to
     `analysis_pipeline/output/`
   - game not running but step is `LIVE:` → stop, report which facts remain unverified
6. **Windows / Git-Bash rules** — shell is Git Bash on Windows 11:
   - `.bat` files: `cd` to their directory, run via `cmd //c name.bat`
   - `python` (on PATH: `%USERPROFILE%\AppData\Local\Python\bin\python3.exe`); never `py`
   - forward slashes in bash paths (`/c%USERPROFILE%`); backslashes only inside quoted
     Windows-program arguments
   - PowerShell launchers: `powershell -ExecutionPolicy Bypass -File <script>.ps1`
7. **`LIVE:` markers** — any step requiring the running game is prefixed `LIVE:`.
   During authoring/review these are validated by inspection only. A skill must remain
   useful up to its first `LIVE:` step (plan, verify statically, prepare artifacts).
8. **Footer** — every SKILL.md ends with:
   `Canonical sources:` list of `path §Section` entries, and
   `Last validated: <YYYY-MM-DD> against <git short-hash>`. ✓
9. **Trust-tier vocabulary** — FACT / CONFIRMED / DERIVED / GUESS / LEAD / SCRATCH used
   exactly as defined in `INDEX.md`. Only `f1c-start-here` defines them; all other
   skills use them and cite `INDEX.md`.
10. **Tone** — imperative, stepwise, no hedging. Number every step. One action per
    step. State the observable result of each step so the executor can self-check.

## Skill directory layout

```
.claude/skills/
  _meta/                      # this file, TEMPLATE.md, CATALOG.md, toolfacts.md,
                              # doc-anchors.md, validate_skills.py, sim_rubrics/
  f1c-<name>/
    SKILL.md                  # ≤150 lines, the executable procedure
    reference.md              # optional depth (transcripts, worked examples)
    <other bundles>           # e.g. triage-tree.md, checklist.md, handoff-template.md
```

## Simulation rubrics

Each skill's author also writes `_meta/sim_rubrics/<skill>.md`:

```
# Rubric: f1c-<name>
Task prompt: <realistic task a cold session would receive>
Expected steps (in order): <numbered, with the commands they should run>
Forbidden actions: <e.g. editing docs/, running apply, writing code before preflight>
Pass criteria: <including "stops correctly at first LIVE: step">
```

## Relationship to the every-turn hook

`.claude/hooks/mod_reminder.py` injects the iron rules each prompt. Skills must
REINFORCE its exact wording, never paraphrase into something subtly different.
If a skill needs to state an iron rule, quote the hook text or CLAUDE.md verbatim.
