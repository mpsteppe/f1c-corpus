---
name: f1c-start-here
description: Orientation and router for the F1 Challenge 99-02 RE repo — the single entry point a brand-new session reads first. Use when starting any cold session, when asked "where do I begin", or when unsure which workflow (locate, verify, mod, trace, docs, handoff) a task belongs to. Do NOT use to execute a workflow — this skill only routes; open the skill it names (e.g. f1c-mod-lifecycle for building a mod) and follow that.
---

# Orient a cold session and route to the right skill

## When to use / when not

Read this before doing ANYTHING else in this repo if you have zero project memory.
It defines the trust vocabulary, quotes the iron rules, and routes every task to one
of the other 14 skills. It does not execute work: route, open the target skill, follow it.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| Repo present, tools runnable | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py` | Module docstring / usage help printed (read-only, safe) |

If instead you see `command not found` or a traceback → wrong shell or machine; stop and report.

## Read order for a cold session

1. This file. 2. `INDEX.md` (repo map, trust tiers). 3. `CLAUDE.md` (iron rules).
4. The task-specific skill from the tree below. Current priorities: `work/QUEUE.md`
and the newest `work/HANDOFF*.md` (resume via `f1c-handoff`). Full inventory: `MANIFEST.md`.

## Trust tiers — quoted verbatim from INDEX.md §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE

> | Tier | What | Where | Rule |
> |------|------|-------|------|
> | **FACT** | Raw decompiled `.c` source | `decompiled_all/`, `analysis_pipeline/analyzed/`, `tools/decompiled_ida/` | Ground truth. Trust over any doc. |
> | **FACT** | Bytes read from the exe | via `tools/mod_pipeline/` | Deterministic. The final arbiter. |
> | **CONFIRMED** | ISI class/function identity | `tools/cross_binary_final.csv` | Verified by NASCAR cross-match. |
> | **DERIVED** | IDA exports, graphs, CSVs | `tools/*.csv`, `knowledge_graph/` | Regenerable. Accurate but mechanical. |
> | **GUESS** | Global labels, struct offsets | `docs/12`, `docs/13*` | DS-worker inferred. Verify before relying. |
> | **LEAD** | Call chains, semantic names | `docs/31-call-chains/`, `docs/30-impl-specs/` | **May be hallucinated.** A chain (0008) mislabeled a network function as "track grip". Treat as a hint, confirm in source. |
> | **SCRATCH** | Chat logs, temp files | `ds.txt`, `opus_chat.txt`, `analysis_pipeline/_launch_*.ps1` | Historical. Do not treat as current. |
>
> **The one rule that prevents wasted work:** for anything precise (a mod, an offset,
> a value), confirm against FACT-tier raw source or an exe byte-read. Never act on a
> GUESS/LEAD label alone.

Every other skill uses FACT / CONFIRMED / DERIVED / GUESS / LEAD / SCRATCH with exactly
these meanings and cites `INDEX.md`. This is the only skill that defines them.

## Iron rules

`.claude/hooks/mod_reminder.py` injects this text every turn (verbatim):

> F1C iron rules (every turn): LOCATE code with tools/investigate.py (find/system/mod/dossier),
> never raw grep fan-out. MODS: read mods/_README.md ledger first; verify every fact with
> tools/preflight.py against the live game BEFORE writing code; memory write > byte redirect >
> detour; NEVER call game internals from injected code. Docs are GUESS tier - trust raw .c
> and the live process, not doc labels.

Lead sentences of the 7 numbered rules, verbatim from `CLAUDE.md` §Iron rules
(read the full section before any non-trivial task; quote it, never paraphrase it):

> 1. **Trust tiers.** Raw `.c` files (`analysis_pipeline/analyzed/`, `decompiled_all/`) and the live process are FACT.
> 2. **LOCATE with `tools/investigate.py`** (`find` / `system` / `mod` / `global` / `uses` / address dossier) — never fan out raw greps or hand-read `.c` files to find code.
> 3. **Mods: read `mods/_README.md` (ledger) FIRST**, then `tools/mod_pipeline/MODDING_PLAYBOOK.md`.
> 4. **Mods: verify facts before code.**
> 5. **Mod strategy ladder:** data file > memory write (poke-proven, then tick DLL) > call-site byte redirect > vtable swap > detour. **Never call game internals from injected code**
> 6. **Mods must log read-back values** (write, re-read, log both + gate states)
> 7. Never re-document an address already in `docs/` (check `## FUN_` header first).

## Decision tree — route the task

- **Find something** — "where is X handled", "what does this function do", "who touches
  this global", "map the tire subsystem", "find a patch-point candidate" → `f1c-locate`.
- **Trust something** — one specific doc claim (offset, global label, enum, behavior) you
  are about to build on → `f1c-verify-claim`. Whole-doc accuracy sweep, or logging
  `[CORRECTION]` entries → `f1c-doc-audit`.
- **Touch the live game** — read/watch/write memory, snapshot→diff hunting → `f1c-live-probe`.
  Reversible function/state tracing (Frida) → `f1c-frida-trace`.
- **Change game behavior** — ANY mod, feature restoration, or bugfix starts at
  `f1c-mod-lifecycle` (the spine — it gates and routes to `f1c-byte-patch` for static
  bytes/call redirects, `f1c-dll-mod` for injected tick/hotkey DLLs, `f1c-live-probe`
  to poke-prove, `f1c-frida-trace` to test reversibly). Enter the spine even when the
  task names a specific rung ("just apply the patch").
- **A mod misbehaves** — compiles/injects/logs but the game doesn't react, or crashes
  → `f1c-debug-failed-mod`.
- **Documentation work** — run DS-worker batches, merge worker output → `f1c-doc-pipeline`.
  Audit/QA the result → `f1c-doc-audit`.
- **Cross-binary** — port knowledge to/from NASCAR 03/04, F1 2002, SCGT siblings
  → `f1c-port-sibling`.
- **Source recovery** — original file/class names, trace mining, binary forensics
  → `f1c-source-recovery`.
- **Session mechanics** — end, checkpoint, or resume a session → `f1c-handoff`.
- **The library itself** — a skill misfired, a tool CLI changed, validator upkeep
  → `f1c-skill-maintenance`.

If no branch fits, read `routing-table.md` in this skill's directory (18 example task
phrasings → skill). Still no fit → ask the user; do not improvise a workflow.

## What NOT to do cold

- Do NOT edit `docs/` directly. Worker/author output goes to `analysis_pipeline/output/`;
  errors are flagged in `work/CHANGELOG.md` as `[CORRECTION]` (CLAUDE.md §Iron rules, rule 7).
- Do NOT call game internals from injected code — state writes only (rule 5, quoted above).
- Do NOT patch the original exe. Patch a COPY; verify original bytes first (rule 5).
- Do NOT trust `docs/12`, `docs/13*` (GUESS) or `docs/30`/`docs/31` (LEAD) labels without
  verification — `f1c-verify-claim` first (INDEX.md §Trust tiers, quoted above).
- Do NOT fan out raw greps or hand-read `.c` files to find code (rule 2) — `f1c-locate`.
- Do NOT start any mod without reading the `mods/_README.md` ledger (rule 3).
- Do NOT run `python tools/gen_sdk.py` casually — it regenerates and overwrites the SDK
  files on bare invocation, no flags, no prompt.

## STOP — do not proceed if

- The task needs the running game and it is not running → plan statically, stop at the
  first `LIVE:` step of the routed skill, report which facts remain unverified.
- You are about to act on a GUESS/LEAD doc label alone → route to `f1c-verify-claim`.
- You cannot map the task to a skill → read `routing-table.md`; if still unmapped, ask
  the user instead of inventing a procedure.
- Any instruction here conflicts with `CLAUDE.md` → `CLAUDE.md` wins; flag the conflict
  via `f1c-skill-maintenance`.

## Deep reference

Read `routing-table.md` in this skill's directory when the decision tree is ambiguous.

---
Canonical sources: INDEX.md §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE; INDEX.md §Repo map (current layout); INDEX.md §Common tasks → where to start; CLAUDE.md §Iron rules; CLAUDE.md §Key pointers; MANIFEST.md §Directories; roles/ARCHITECT.md §RULES; work/_README.md §Plans & process (meta); work/QUEUE.md
Last validated: 2026-07-18 against 6bcccfe
