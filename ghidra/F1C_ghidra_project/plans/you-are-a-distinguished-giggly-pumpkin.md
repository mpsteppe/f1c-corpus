# Skill Library: `.claude/skills/` for post-retirement operation

## Context

Senior operator (ARCHITECT role) retiring. Junior/mid engineers and Sonnet-class models
must carry project forward: debug, extend, validate, advance. Expert knowledge exists
but scattered (REFERENCE.md ~33KB, MODDING_PLAYBOOK, roles/, mods ledger, 180KB
CHANGELOG mistake catalog) — cold cheap sessions historically fail (stale ledger,
call-game-internals reflex, trusting GUESS-tier docs). Fix: skill library encoding
each expert workflow as explicit, stepwise, STOP-guarded procedure. `.claude/skills/`
is greenfield (only hooks/ + settings exist). Token cost irrelevant; correctness is.

**Design stance:** skills are execution shells; canonical docs stay knowledge stores.
Exact commands, expected outputs, failure modes, STOP conditions inline (CLIs stable).
Volatile facts (addresses, offsets, mod statuses) NEVER inlined — always cited from
canonical file (`mods/_README.md`, `docs/12`, REFERENCE.md sections). Prevents skill/doc
drift while keeping cold Sonnet sessions self-sufficient.

## Skill catalog (15 skills, prefix `f1c-`)

| Skill | Purpose | Primary sources |
|-------|---------|-----------------|
| `f1c-start-here` | Router + orientation: trust tiers, iron-rules digest (verbatim-aligned with `.claude/hooks/mod_reminder.py`), task→skill decision tree, "what NOT to do cold" | CLAUDE.md, INDEX.md, roles/ |
| `f1c-locate` | Find code/data: investigate.py all modes w/ output samples, knowledge_graph/query.py, escalation to raw .c | REFERENCE.md §Bug Investigation, §Knowledge Graph |
| `f1c-verify-claim` | Verify one doc claim before relying: raw .c cross-read → preflight.py probe grammar → verdict → [CORRECTION] if wrong | REFERENCE.md §Verification Methodology, tools/preflight.py |
| `f1c-live-probe` | poke.py workflows (list/read/write/watch/veh/snapshot/diff), SDK regen prerequisite, "write logged ≠ game reacted" | tools/poke.py, gen_sdk.py, mods/_README.md |
| `f1c-mod-lifecycle` | Spine skill: ledger-first → decompose to facts.json → preflight gate → strategy ladder → Frida-first → bake to COPY → in-game confirm → ledger update. Routes to 3,4,6,7,8,9 | MODDING_PLAYBOOK.md, mods/_README.md |
| `f1c-byte-patch` | patch.py manifest flow, asm_tools.py resolve/redirect + stack-balance delta, FOREIGN-byte abort, redirect call SITE not function, thiscall/ret N gotchas | tools/patch.py, asm_tools.py, PLAYBOOK gotchas |
| `f1c-dll-mod` | gen_hook.py tick/detour scaffolds, MinGW32 build, race gate + vehicle iteration primitives (cited from ledger), state-writes-only rule | tools/gen_hook.py, mods/_README.md, mods/ai_pit_retire/ |
| `f1c-frida-trace` | watch_run.py, trace/f1c_trace.py + trace_comprehensive.py + analyze_trace.py, patch_trace.py clamp unlock, .js→baked graduation | tools/trace/, tools/mod_pipeline/watch_run.py |
| `f1c-debug-failed-mod` | Triage tree from historical failures: stale ledger, log-confirmed trap, GUESS offset (safety_car 0x453C case), thiscall/stack, race gate. Exit = ledger update + [CORRECTION] | mods/_README.md, work/CHANGELOG.md cases |
| `f1c-doc-pipeline` | DS worker batch system: 0_bundle → 0r_gen_queue → 1_batch_gui (modes, workers A–T) → 2_merge → 5_move → graph rebuild → gen_sdk. Never move dirs (hardcoded paths); workers never write docs/ | analysis_pipeline/, REFERENCE.md §Worker Workflow, §Batch Modes |
| `f1c-doc-audit` | ARCHITECT-style audit: sample→verify→tally, [CORRECTION] format w/ real examples, never delete—correct-and-log | roles/ARCHITECT.md, REFERENCE.md §Verification |
| `f1c-port-sibling` | port.py (nascar03/04, f1_2002, demo, scgt), cross_binary delta pipeline, match confidence never auto-FACT | tools/port.py, cross_binary/_README.md |
| `f1c-source-recovery` | Isolated workspace rules ([MERGE-READY] flow), trace mining: clamp unlock → capture → extract names/state machines → merge route | source_recovery/README.md, work/BREAKTHROUGH_trace_mining.md |
| `f1c-handoff` | Session exit checklist (ledger, corrections, QUEUE.md, HANDOFF format, commit discipline — never commit patched exes) + resume checklist | work/HANDOFF.md, work/_README.md |
| `f1c-skill-maintenance` | Keep library true: run validator, fact-citation rule, patch skill + re-sim | `_meta/CONVENTIONS.md` |

Shared: `.claude/skills/_meta/` — CONVENTIONS.md, TEMPLATE.md, CATALOG.md,
toolfacts.md, doc-anchors.md, validate_skills.py, sim_rubrics/.

## Authoring conventions (enforced by review + validator)

1. Frontmatter description with concrete "Use when…" triggers + route-outs.
2. SKILL.md ≤ ~150 lines; depth in bundled `reference.md` per skill.
3. Every command: cwd-explicit, copy-pasteable, "Expected output" + "If instead → recovery/STOP".
4. No inlined volatile facts (addresses/offsets/statuses) — citations only. Validator greps `0x00[0-9A-F]{6}`.
5. Mandatory `## STOP — do not proceed if` section per skill.
6. Windows/Git-Bash rules: `.bat` via `cmd //c` from own dir, `python` not `py`, forward slashes.
7. Live-game steps marked `LIVE:` (review-only during authoring; game not running).
8. Footer: `Canonical sources:` + `Last validated: <date> against <commit>`.

## Orchestration (all via Agent tool, ~19 runs)

- **Phase 0 — Conventions** (1 agent): write `_meta/` CONVENTIONS + TEMPLATE + CATALOG.
  I (main session) review before proceeding — highest-leverage checkpoint.
- **Phase 1 — Ground truth** (2 parallel read-only agents):
  - Agent T: `--help` / argparse-read every CLI → `_meta/toolfacts.md` (sole permitted source for flags). Record game-running/pip prerequisites per tool.
  - Agent D: harvest citable section anchors of all canonical docs + 10 representative [CORRECTION] entries + failed-mod postmortems → `_meta/doc-anchors.md`.
- **Phase 2 — Authoring** (4 parallel authors):
  A1: start-here, locate, verify-claim, doc-audit, handoff.
  A2: live-probe, mod-lifecycle, byte-patch.
  A3: dll-mod, frida-trace, debug-failed-mod.
  A4: doc-pipeline, port-sibling, source-recovery, skill-maintenance.
  Each author: reads cited sources in full; commands only from toolfacts; also writes
  `_meta/sim_rubrics/<skill>.md` (task, expected steps, forbidden actions, pass criteria).
- **Phase 3 — Static review** (5 fresh-context reviewers): R1–R4 per batch — Glob-verify
  every path, Grep-verify every flag vs argparse, verify doc anchors, frontmatter, no
  volatile facts, STOP present, Windows rules. R5 — cross-skill consistency: no conflict
  with mod_reminder.py hook text or CLAUDE.md iron rules; route-outs resolve; router
  covers all skills. Findings → owning author fixes → re-review diffs until zero findings.
- **Phase 4 — Simulation** (7 Sonnet-model task agents + 1 judge): fresh agents, realistic
  task, read-only; game not running so tasks end at correct `LIVE:` STOP (reaching STOP
  correctly = pass criterion). Tasks: cold orientation; mod planning (must ledger-first,
  no code); safety_car triage (must find GUESS offset, prescribe preflight); byte-patch
  dry-run (status/show only); doc-pipeline staging; correction logging; handoff.
  Judge grades vs rubrics; failures classified skill-defect vs model-lapse; skill defects
  → fix → re-sim (max 3 cycles, then escalate to human). Transcripts archived
  `work/skill_authoring/sim_transcripts/`.
- **Phase 5 — Integration** (1 agent + main): write `_meta/validate_skills.py`
  (mechanizes static checks, exit code = failures); run clean; update CLAUDE.md (one
  pointer line: start with `f1c-start-here`), INDEX.md repo map, MANIFEST.md; commit on
  branch per project checkpoint convention (no binaries/backups).

## Verification / acceptance

1. `python .claude/skills/_meta/validate_skills.py` exits 0.
2. All 7 simulation transcripts PASS, archived.
3. Router covers all skills; all route-outs resolve (R5 sign-off).
4. No conflict with hook text / iron rules.
5. CLAUDE.md/INDEX.md/MANIFEST.md updated; clean intended `git status`; committed.
6. Deferred (post-approval, first live session): smoke-test `f1c-mod-lifecycle` by
   re-confirming cut_track_dq in-game — only step needing live game.

## Risks

- **Drift**: mitigated structurally (no volatile facts), mechanically (validator),
  procedurally (skill-maintenance + Last-validated footers).
- **Live steps unexecuted during authoring**: `LIVE:` markers + deferred smoke test.
- **Sonnet overreach** (historical: ledger skip, game-internal calls): hard STOPs
  front-loaded; hook already re-injects rules; skills reinforce, never paraphrase-diverge.
- **Vague descriptions → skills never trigger**: convention 1 + sim task 1 tests discovery.
- **Hardcoded paths**: "never move dirs" encoded in doc-pipeline skill.
- **CHANGELOG case studies stale over time**: marked "historical snapshot 2026-07".

## Files touched

New: `.claude/skills/` (15 skill dirs + `_meta/`), `work/skill_authoring/`.
Edited: `CLAUDE.md` (1 pointer line), `INDEX.md`, `MANIFEST.md`.
Nothing else modified; no game binaries touched.
