---
name: f1c-doc-audit
description: Audit the accuracy of docs/ content (or freshly merged worker output) by sampling claims, verifying each against raw source, tallying accuracy, and logging [CORRECTION] entries in work/CHANGELOG.md — ARCHITECT-style QA. Use when a task says "audit this doc", "spot-check the merge", "QA the worker output", "log a correction", or when f1c-verify-claim REFUTES a claim. Do NOT use to verify one claim inline mid-task — use f1c-verify-claim; to run or merge worker batches — use f1c-doc-pipeline; to fix a misfiring skill file — use f1c-skill-maintenance.
---

# Audit doc accuracy and log corrections

## When to use / when not

Doc-level QA: sample, verify, tally, decide, log. The method comes from
`roles/ARCHITECT.md` (§2. Quality-verify Lead output, §VERIFICATION METHODOLOGY) —
cite it for METHOD only. Its §AUDIT SCRIPT (`python audit_full.py`) is STALE: that
script has been deleted from the repo root. Do not run it; sample manually via
`f1c-verify-claim` as prescribed below.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| Target doc exists and has `## FUN_` entries | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && grep -c "^## FUN_" docs/<target-doc>.md` | A positive entry count (single-KNOWN-file check — this is not a locate fan-out) |

If instead you see `0` or `No such file` → wrong target file; confirm the doc name
against `docs/_README.md` §Trust map before auditing anything.

## Procedure

### Step 1: choose the sample

Pick 5–10 entries at random from the target doc or merge batch. Non-negotiable floor,
verbatim from REFERENCE.md §Rules: `Never accept "all physics" verdicts without
sampling at least 10 files` — any "all done / all X documented" claim requires a
≥10-entry sample. Prioritize (per roles/ARCHITECT.md §2. Quality-verify Lead output):
entries claiming new struct offsets, entries claiming `Moddability: configurable`, and
game-logic classifications of anonymous functions.

### Step 2: verify each sampled claim

For each entry, run the `f1c-verify-claim` procedure (static cross-read is mandatory;
the `LIVE:` probe is required only for claims about runtime values). Fast check first
(30 s): confirm the claimed globals appear in the entry's raw `.c`; full check (2 min):
match every claim — globals, offsets+types, strings, called functions — against the
`.c` (REFERENCE.md §Verification Methodology (Architect role)).

### Step 3: red-flag scan

Flag any entry showing (REFERENCE.md §Verification Methodology (Architect role)):
- "reads X" but the `.c` only writes;
- offset claimed as `double` but the `.c` shows `*(int *)(ptr + ...)`;
- `Moddability: configurable` with no field-name string literal in the `.c`;
- an address documented twice (duplicates) — CLAUDE.md §Iron rules rule 7, verbatim:
  "Never re-document an address already in `docs/` (check `## FUN_` header first)."

### Step 4: tally and decide

Compute sampled accuracy (correct claims / checked claims). Decide the trust action:
- ~90%+ and errors are isolated → accept the doc; log the individual corrections.
- Systematic error class (same mistake repeated) → log corrections AND flag the whole
  doc section in the CHANGELOG entry; queue re-documentation via `f1c-doc-pipeline`.
- "All done" claim + any missing entries in a ≥10 sample → reject the claim; record
  the discrepancy.

### Step 5: log every refuted claim as a [CORRECTION]

Append to `work/CHANGELOG.md` using the exact format in `correction-format.md` (this
skill's directory). During an audit, `work/CHANGELOG.md` is the ONLY file you write;
the doc text itself is fixed later via `f1c-doc-pipeline` or an explicitly
user-approved edit. Rules:
- **Never delete** doc content during an audit — correct and log. The correction line
  is the audit trail.
- Cite entries by verbatim text or `FUN_` address, never by CHANGELOG line number
  (the file is append-heavy; line numbers drift).
- One `[CORRECTION]` line per wrong fact, naming the doc file it lives in.

### Step 6: close the loop

If the audit was of worker output: report accuracy + error classes to whoever runs
`f1c-doc-pipeline`. If a correction invalidates SDK-visible facts (globals, offsets),
note that `tools/gen_sdk.py` must be re-run after the docs are corrected — but do not
run it casually (it overwrites the SDK files on bare invocation).

## STOP — do not proceed if

- You are about to run `python audit_full.py` → the script is deleted; roles/ARCHITECT.md
  §AUDIT SCRIPT is stale. Sample manually via `f1c-verify-claim` instead.
- You are about to edit `docs/` directly as a worker/author → forbidden; worker output
  goes to `analysis_pipeline/output/`, and audit findings go to `work/CHANGELOG.md` as
  `[CORRECTION]` (CLAUDE.md §Iron rules rule 7).
- You are about to accept an "all done"/"all physics" claim without sampling ≥10
  entries → forbidden (REFERENCE.md §Rules).
- You are about to delete a wrong doc entry → never delete; correct and log.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| Sampled entry's `.c` file not found in `analysis_pipeline/analyzed/` or `decompiled_all/` | address mis-typed in doc, or IDA-only function | check `tools/decompiled_ida/`; if truly absent, that itself is a finding — log it |
| Same address documented in two docs | duplicate (merge only dedups `## FUN_` headers per target) | `[CORRECTION]` naming both files; keep the better entry, flag the other |
| Claim is un-checkable (no address, no offset, pure prose) | vague worker output | flag the entry as unverifiable in the CHANGELOG; count it against accuracy |
| Doc's error rate far above ~10% | wrong mode/prompt in the producing batch | flag systematically; route re-run to `f1c-doc-pipeline` |

## Deep reference

Read `correction-format.md` in this skill's directory for the exact `[CORRECTION]`
entry format and real examples spanning the main error classes.

---
Canonical sources: roles/ARCHITECT.md §2. Quality-verify Lead output; roles/ARCHITECT.md §VERIFICATION METHODOLOGY; roles/ARCHITECT.md §RULES; REFERENCE.md §Verification Methodology (Architect role); REFERENCE.md §Rules; CLAUDE.md §Iron rules; work/CHANGELOG.md
Last validated: 2026-07-18 against 6bcccfe
