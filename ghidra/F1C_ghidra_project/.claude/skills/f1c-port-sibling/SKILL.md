---
name: f1c-port-sibling
description: Port knowledge to/from sibling isiMotor1 binaries (NASCAR 03/04, F1 2002, F1 2002 demo, SCGT) via tools/port.py and the cross_binary delta pipeline. Use when a task says "what does NASCAR do here", "port this sibling function", "find the sibling version", "run the delta pipeline", or "document sibling-only functions". Do NOT use for locating code inside F1C itself — use f1c-locate; for running the F1C ## FUN_ worker batches — use f1c-doc-pipeline (but delta ## sub_ output merges ONLY via cross_binary/scripts/merge_xbin_delta.py, never merge_to_docs.py); for recovering F1C's own original names — use f1c-source-recovery.
---

# Port knowledge across isiMotor1 sibling binaries

## When to use / when not

Use when a question or mod needs a sibling game's implementation (features F1C lacks,
cleaner builds of shared engine code) or when extending the cross-binary delta.
Route out: F1C-internal lookups → f1c-locate; turning a ported finding into a mod →
f1c-mod-lifecycle (the ported claim is just one more fact to preflight).

## Trust rule (quoted verbatim from CLAUDE.md §Iron rules — do not paraphrase)

> 1. **Trust tiers.** Raw `.c` files (`analysis_pipeline/analyzed/`, `decompiled_all/`)
>    and the live process are FACT. `docs/` labels, offsets, call chains are GUESS —
>    LLM-generated, ~90% per-fact accuracy. Verify before building on any doc claim.

A cross-binary match is NOT a fact about F1C. Per INDEX.md §Trust tiers, verified ISI
identity (`tools/cross_binary_final.csv`) is CONFIRMED tier; everything ported from a
sibling (offsets, behavior, names) is a hypothesis until re-verified in F1C's own raw
`.c` or exe bytes. A ported match never upgrades a GUESS to FACT.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| port.py sees sibling corpora | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/port.py list` | known game keys + decompiled counts |
| Delta CSVs exist (for delta work) | `ls /c%USERPROFILE%/Desktop/F1C_ghidra_project/cross_binary/_delta` | `<stem>_classified.csv` / `<stem>_novel.csv` per sibling — the stem varies per game; use the "delta stem" printed by `port.py list` |

## Procedure

### Step 1: List the sibling corpora
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/port.py list
```
Expected output: the game keys `nascar03`, `nascar04`, `f1_2002`, `f1_2002_demo`,
`scgt` with decompiled counts and each game's "delta stem" (the filename stem used
by that game's `_delta/` CSVs — stems vary per game; always take them from here).
If instead a key you need shows zero decompiled files → that sibling's novels were
never decompiled; see cross_binary/_README.md §Pipeline before proceeding.

### Step 2: Pull the porting dossier for a sibling address
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/port.py nascar03 <sibling_addr>
```
Expected output: a stdout dossier (sibling source, match rows, source-file match).
Read-only; writes nothing.
If instead you see `unknown game '<k>' — one of: nascar03, nascar04, f1_2002,
f1_2002_demo, scgt` → use an exact key. If you see `no cross-binary match rows...`
or `no decompiled .c...` (still exit 0) → that address has no match/decomp data yet;
do not improvise — extend the delta per cross_binary/_README.md §Pipeline.

### Step 3: (Delta extension only) run the pipeline stages
The stages are: IDA export → fingerprint (byte_sigs + strings) → xbin_match →
delta → DS workers. All matching is offline byte-level Python; workers only ever
see the NOVEL delta (stage map: cross_binary/_README.md §Pipeline and §Files).
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python cross_binary/scripts/xbin_match.py nascar03
```
Expected output: `_delta/<stem>_classified.csv` + `_delta/<stem>_novel.csv` (stem
from `port.py list`; flags/defaults: `_meta/toolfacts.md` §cross_binary/scripts/xbin_match.py).
If instead match rates collapse → see the mask rule below before touching the matcher.

### Step 4: Interpret verdicts (cross_binary/_README.md §Matching signals (xbin_match.py))
| Verdict | Meaning | What you do |
|---|---|---|
| BYTE_EXACT | byte-identical duplicate | skip — F1C already has it |
| BYTE_MASK | identical after masking relocations — **primary signal** | duplicate; skip for delta, usable as identity lead |
| STRING | shared unique string | same-function lead (signal currently inert — see §TODO / known gaps) |
| NOVEL | no match | **the delta** — candidate for documentation/porting |

The mask zeroes E8/E9 rel32 call/jmp targets and in-image absolute addresses, so
shared engine code that differs only by relocation hashes identical. Verbatim from
§Validation (correctness gate — PASSED): "Masking is the reason the gate passes.
Do not remove it."

Exclusions (per §Current status): **SCGT** is excluded from the unified delta —
older compiler generation makes nearly everything a FALSE novel. **rFactor** is
excluded entirely — isiMotor2, wrong engine. Do not add either back.

### Step 5: Document delta functions (worker rules AND merge differ from F1C workers)
Delta documentation follows cross_binary/WORKER_DELTA.md §HARD RULES — violating any
of these breaks the merge. Read twice. — headline differences from F1C doc work:
headers are exactly `## sub_XXXXXXXX` (NOT `## FUN_`), source is IDA Hex-Rays (not
Ghidra — glossary in §SOURCE FORMAT — IDA Hex-Rays (not Ghidra)), entries route via
one `<!-- target: ... -->` per group, and every entry carries an honest **F1C
status** + **Port:** verdict (`yes` / `merge` / `data-driven` / `no`). Depth
benchmark: §GOLD-STANDARD EXAMPLE — copy this shape exactly. Workers launch via the
batch GUI "Sibling Delta" (`xbin_delta`) mode and write to
`analysis_pipeline/output/xbin_delta/`. The merge step is:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python cross_binary/scripts/merge_xbin_delta.py
```
Expected output: `merged: +<n> triage, +<n> full entries (...)`; entries land in
`source_material/<game>/docs/`, workers archive. If instead it prints
`SKIPPED <n> malformed addresses` → review those entries by hand before re-running.
**Do NOT merge `## sub_` output with f1c-doc-pipeline's `merge_to_docs.py` /
`2_merge.bat`** — that script splits only on `## FUN_`/`### FUN_` headers, silently
drops every `## sub_` entry, then archives the worker files (details:
`_meta/toolfacts.md` §cross_binary/scripts/merge_xbin_delta.py). Reference outputs
from prior runs: docs/27 and docs/32.

### Step 6: Re-verify anything ported before use in F1C
Before a ported offset/behavior drives a mod or doc claim: verify it in F1C's own
raw `.c` (f1c-locate → read source) and, for live values, f1c-verify-claim. LIVE:
any runtime confirmation of a ported offset requires the running game — stop at
this point if the game is not available and report the fact as unverified.

## STOP — do not proceed if

- You are about to state a sibling-derived offset/behavior as an F1C fact without
  re-verifying in F1C source or bytes → it is a hypothesis; verify first.
- You are about to remove or "simplify" the E8/E9 rel32 mask in the matcher →
  forbidden; the validation gate passes because of it (§Validation).
- You are about to include SCGT or rFactor rows in the unified delta → both are
  excluded for cause (§Current status).
- A delta worker is about to write `## FUN_` headers, multiple targets per group,
  or anything under `docs/` directly → forbidden per WORKER_DELTA §HARD RULES.
- You are about to merge `## sub_` output with `merge_to_docs.py` / `2_merge.bat`
  → forbidden; it drops every `## sub_` entry — use `merge_xbin_delta.py` (Step 5).
- `port.py` reports no match/decomp data for the address → do not hand-guess a
  correspondence; extend the pipeline or report the gap.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| `unknown game '<k>' — one of: ...` | mistyped game key | use a key from `port.py list` |
| `no cross-binary match rows...` / `no decompiled .c...` | address outside current delta/decomp coverage | extend per cross_binary/_README.md §Pipeline; do not improvise |
| Sibling match rate collapses vs prior runs | mask weakened or wrong-generation sibling added | restore the mask; check §Current status for which siblings belong |
| SCGT "novels" flooding the delta | compiler-generation gap, not real novelty | exclude SCGT rows (§Current status) |

## Deep reference

Read `reference.md` in this skill's directory for a worked `port.py` dossier
walkthrough, the delta CSV column layout, and the WORKER_DELTA output skeleton.

---
Canonical sources: CLAUDE.md §Iron rules; INDEX.md §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE; cross_binary/_README.md §Goal (corrected framing); cross_binary/_README.md §Pipeline; cross_binary/_README.md §Matching signals (xbin_match.py); cross_binary/_README.md §Validation (correctness gate — PASSED); cross_binary/_README.md §Current status; cross_binary/WORKER_DELTA.md §HARD RULES — violating any of these breaks the merge. Read twice.; _meta/toolfacts.md §tools/port.py; _meta/toolfacts.md §cross_binary/scripts/merge_xbin_delta.py; _meta/toolfacts.md §cross_binary/scripts/xbin_match.py
Last validated: 2026-07-20 against 6bcccfe
