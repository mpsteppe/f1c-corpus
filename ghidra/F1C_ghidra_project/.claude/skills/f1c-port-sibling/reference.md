# f1c-port-sibling — deep reference

Companion to `SKILL.md`. Sources: `_meta/toolfacts.md` §tools/port.py,
cross_binary/_README.md, cross_binary/WORKER_DELTA.md. When this file and those
disagree, the sources win — flag via f1c-skill-maintenance.

## port.py — behavior details (toolfacts §tools/port.py)

- `python tools/port.py <game> <sibling_addr>` — dossier for porting.
  `python tools/port.py list` — known game keys + decompiled counts.
  Bare invocation prints the docstring. All read-only; stdout only; no writes.
- Reads: `source_material/<GameDir>/decompiled/*.c`,
  `source_material/<GameDir>/docs/4*.md`,
  `cross_binary/_delta/<stem>_classified.csv` + `<stem>_srcmatch.csv`.
- Missing data is NOT an error: it prints `no cross-binary match rows...` /
  `no decompiled .c...` and still exits 0. Treat those lines as "coverage gap",
  not "function does not exist".
- Argument errors: unknown game → `unknown game '<k>' — one of: nascar03,
  nascar04, f1_2002, f1_2002_demo, scgt`; fewer than 2 args →
  `usage: python tools/port.py <game> <sibling_addr>`.

## Reading a dossier

A dossier answers three questions; check them in order:

1. **Identity** — does the sibling function match a known F1C function
   (classified CSV rows), a known ISI class, or nothing (NOVEL)?
2. **Source context** — which sibling source file / doc entry describes it
   (`docs/4*.md` under the sibling's `source_material/` dir)?
3. **Portability** — does the entry (or your reading of the `.c`) support a
   `Port:` verdict of `yes` (drop-in), `merge` (adapt to F1C layout),
   `data-driven` (F1C has the mechanism, needs data), or `no`?

Every offset/global named in a sibling entry belongs to the SIBLING's memory
layout. Re-map to F1C explicitly; never copy a sibling offset into an F1C doc,
mod, or `facts.json` unverified.

## Why the exclusions exist (cross_binary/_README.md §Current status)

- **SCGT** — 1999-era compiler generation. Byte fingerprints of even shared code
  differ, so nearly everything classifies as a FALSE novel. Excluded from the
  unified delta; only same-compiler-generation siblings are fed to dedup.
- **rFactor** — isiMotor2, a different engine generation. Excluded entirely.
- Packed siblings (SafeDisc) have no fingerprints until runtime-dumped; the
  per-sibling table in §Current status is the live status — read it, don't
  restate it.

## Why the byte mask exists (§Matching signals / §Validation)

`mask()` zeroes E8/E9 rel32 call/jmp operands and in-image absolute addresses
before hashing, so two builds of the same function that differ only by
relocation produce identical (size, masked-head) signatures — BinDiff-lite.
The correctness gate compared against a known ground-truth matching: raw
(size, head) matching FAILED the gate; masked matching PASSED and exceeded the
prior full pipeline. Verbatim: "Masking is the reason the gate passes. Do not
remove it." Any "cleanup" of the matcher must re-run that validation before
its output is trusted.

Known inert signal: STRING verdicts are inert in the matcher (per §TODO / known
gaps — the string-join path yields no matches). Note that `tools/ida_strings.csv`
`ref_funcs` IS populated nowadays (f1c-source-recovery's static mining depends on
it), so the _README's stated reason ("empty referencing_functions") looks stale —
flag that section for f1c-doc-audit rather than re-deriving the cause here. Either
way: do not interpret "no STRING verdicts" as "no shared strings".

## WORKER_DELTA output skeleton (cross_binary/WORKER_DELTA.md §OUTPUT FILE STRUCTURE)

```
=== TRIAGE LINES ===
| 0x00xxxxxx | <lines> | <category> | <one-line purpose> | <port?> | docs/4X-<name>.md |

=== FULL ENTRIES ===
<!-- target: docs/40-gameplay.md -->
## sub_00xxxxxx — Name
...entry...
```

Routing by category: game modes / race control / career / penalties →
`docs/40-gameplay.md`; physics / collision / math → `docs/41-engine.md`;
renderer / audio / UI / HUD → `docs/42-presentation.md`; network / replay /
file I/O → `docs/43-io.md`.

Merge note: `merge_xbin_delta.py` routes game-qualified targets
(`<!-- target: <game>/<doc>.md -->`) directly; bare `docs/XX.md` targets (the
WORKER_DELTA form above) are salvaged by inferring the worker's single game —
prefer game-qualified targets when prompts allow. Full contract:
`_meta/toolfacts.md` §cross_binary/scripts/merge_xbin_delta.py. Never
merge_to_docs.py — it drops `## sub_` entries.

Triage categories: `game_mode` `race_control` `career` `penalty` `physics_math`
`collision` `renderer` `audio` `ui` `network` `replay` `file_parser`
`math_util` `unknown`. Port enum: `yes` / `merge` / `data-driven` / `no`.

Hard-rule reminders that differ from F1C doc workers (§HARD RULES):
header exactly `## sub_XXXXXXXX` (lowercase `sub_`, 8 hex digits from the `.c`
filename); one `.md` in the target comment (never `.md.md`); write only to the
worker output file; one function = one write; no subagents; never read
`analyzed/`; process the whole assigned list.

Entry depth benchmark: §GOLD-STANDARD EXAMPLE — copy this shape exactly —
key-logic bullets with real (sibling) offsets and globals, a struct-offset
table when object fields are touched, called subs, an honest **F1C status**
line, and a **Port:** verdict. Tiny anchorless helpers may get a 2-line entry
plus triage line — still `## sub_`, still in the worker file.

## Where prior outputs live

Cross-binary matching results and delta documentation from prior sessions are
in docs/27 and docs/32 (reference outputs), with the machine-readable identity
map at `tools/cross_binary_final.csv` (CONFIRMED tier per INDEX.md §Trust
tiers — READ THIS BEFORE TRUSTING ANY FILE).

---
Canonical sources: _meta/toolfacts.md §tools/port.py; cross_binary/_README.md §Matching signals (xbin_match.py); cross_binary/_README.md §Validation (correctness gate — PASSED); cross_binary/_README.md §Current status; cross_binary/_README.md §TODO / known gaps; cross_binary/WORKER_DELTA.md §OUTPUT FILE STRUCTURE; cross_binary/WORKER_DELTA.md §GOLD-STANDARD EXAMPLE — copy this shape exactly; _meta/toolfacts.md §cross_binary/scripts/merge_xbin_delta.py
Last validated: 2026-07-20 against 6bcccfe
