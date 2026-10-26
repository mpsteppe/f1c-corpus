---
name: f1c-handoff
description: End or checkpoint a session cleanly (ledger, corrections, queue, handoff entry, commit) or resume someone else's session from their handoff. Use when a task says "wrap up", "checkpoint", "write a handoff", "commit the session", or "resume from last session". Do NOT use for cold orientation with no prior handoff — use f1c-start-here; for logging individual doc corrections — use f1c-doc-audit (this skill only checks they were logged); for skill-library upkeep — use f1c-skill-maintenance.
---

# End, checkpoint, or resume a session

## When to use / when not

Two procedures: EXIT (ending/checkpointing) and RESUME (picking up someone else's
work). Exit discipline is what makes cold resumption possible — a session that ends
without it strands its findings. Statuses written here must carry bits, not vibes:
record exactly what was observed, at which trust tier (`INDEX.md` §Trust tiers).

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| Repo is a working git checkout | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && git status --short` | Change list (possibly long) — no fatal error |

## Procedure — EXIT (end or checkpoint a session)

### Step 1: bring the mod ledger current

If ANY mod work happened: update the mod's status row in `mods/_README.md`
(§Current contents — the ledger table). Statuses must be honest per the ledger's own
vocabulary: "log-confirmed" ≠ confirmed; only an observed in-game outcome upgrades a
mod. Do not invent new status words.

### Step 2: confirm corrections are logged

Every doc fact refuted this session must already be a `[CORRECTION]` in
`work/CHANGELOG.md` (format: `f1c-doc-audit` → `correction-format.md`). If any are
missing, log them now — a handoff that silently absorbs a refuted fact poisons the
next session.

### Step 3: update the queue

`work/QUEUE.md` — verbatim from REFERENCE.md §Rules: "`work/QUEUE.md` is the single
source of truth for what's next". Add finished items to its completed section, add
newly discovered work as prioritized entries.

### Step 4: write the handoff entry

Create/refresh `work/HANDOFF.md` (or a dated `work/HANDOFF_<YYYY-MM-DD>_<topic>.md`
for a per-topic handoff) using `handoff-template.md` in this skill's directory.
Section ROLES to fill (titles may vary per session; roles may not): what was done /
current state metrics / prioritized next steps / key commands + reference appendices.
Never overwrite an existing handoff with a less informative one — date a new file.

### Step 5: rebuild derived artifacts ONLY if docs changed

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/knowledge_graph/rebuild.py
```
Expected output: progress lines then `Done in <t>s`; rewrites `knowledge_graph/*.json`.
If instead it errors on a docs parse → fix the offending doc entry first; do not hand
off a broken graph. Then, if globals/structs/functions changed, deliberately run
`python tools/gen_sdk.py` (same cwd) — WARNING: it executes on bare invocation and
overwrites `mods/sdk/f1c_sdk.h` + `.json`; run it on purpose, never to "check".

### Step 6: commit the checkpoint

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && cmd //c commit.bat
```
Interactive: shows `git status --short`, prompts for a message (Enter → default
`docs: session checkpoint` — the checkpoint convention). Expected output: commit
created, then `git log --oneline -5`.
CRITICAL: commit.bat stages ONLY a fixed list — `docs/ roles/ scripts/
work/CHANGELOG.md work/QUEUE.md README.md CLAUDE.md commit.bat .gitignore`. It does
NOT stage `tools/`, `mods/`, `analysis_pipeline/`, or new `work/HANDOFF*.md` files.
Stage those explicitly BEFORE running it:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && git add work/HANDOFF.md mods/_README.md
```
(adjust paths to what you actually changed). Expected: silent success; the files then
appear staged in commit.bat's status listing. If instead a path errors → typo; fix it.
Never stage ANY binary artifact — `.dll` (including self-built mod DLLs), `.exe`
(patched or otherwise), `.bak`, or game binaries. No conditionals, no "ships with the
mod" exception: commit the source + `build.bat` and rebuild binaries from source.

## Procedure — RESUME (pick up a prior session)

1. Read the NEWEST handoff: check `work/HANDOFF.md` AND any dated
   `work/HANDOFF_*.md` — the most recent date wins; older ones are historical.
2. Read `work/QUEUE.md` — the authoritative "what's next".
3. Read `mods/_README.md` (§Current contents) CRITICALLY — the ledger itself has been
   wrong before (a mod was once overstated as shipped; the `[CORRECTION]` lives in
   `work/CHANGELOG.md`). Where a status matters, the mod's own artifacts (apply-script
   headers, READMEs) are the ground truth.
4. `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && git log --oneline -10` —
   Expected: recent `docs: session checkpoint` commits matching the handoff's story.
   If instead the log post-dates the handoff → the handoff is stale; trust the newer
   commits + `work/CHANGELOG.md` and say so.
5. Route the first task through `f1c-start-here`'s decision tree.

## STOP — do not proceed if

- You are about to commit ANY binary (`.dll`/`.exe`/`.bak` — self-built mod DLLs
  included) → never, unconditionally; unstage it and commit its source instead.
- You are about to upgrade a mod status without an observed in-game outcome →
  forbidden; "writes stick ≠ game reacts" — keep the honest status.
- A `LIVE:` verification was skipped this session → the handoff MUST list those facts
  as unverified; do not hand them off as confirmed.
- You are about to overwrite a handoff/QUEUE entry you don't understand → append,
  don't destroy; ask the user if unsure.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| commit.bat status listing missing your files | outside its fixed stage list | `git add <paths>` explicitly, re-run |
| Two handoff files disagree | stale older handoff | newest date wins; note the conflict in the new handoff |
| Ledger status contradicts the mod's own README | stale ledger | trust the mod artifacts; log a `[CORRECTION]` via `f1c-doc-audit` |
| Uncommitted merge/pipeline output at exit | session ended mid-pipeline | note it in the handoff's next-steps; do not force-merge at exit |

## Deep reference

Read `handoff-template.md` in this skill's directory for the handoff skeleton.

---
Canonical sources: work/_README.md §Plans & process (meta); work/HANDOFF.md §What Was Done This Session; work/HANDOFF.md §Current State; work/HANDOFF.md §Key Commands; REFERENCE.md §Rules; CLAUDE.md §Iron rules; mods/_README.md §Current contents; work/QUEUE.md; work/CHANGELOG.md
Last validated: 2026-07-18 against 6bcccfe
