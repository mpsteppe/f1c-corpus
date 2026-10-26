# [CORRECTION] entry format — work/CHANGELOG.md

Companion to `f1c-doc-audit` SKILL.md. Every refuted doc fact gets exactly one line
(or short block) appended to `work/CHANGELOG.md`, prefixed `[CORRECTION]`.

## Format

```
[CORRECTION] <doc-file or FUN_address>: <what was claimed> — <what the FACT-tier evidence shows> (<which doc file holds the wrong entry>)
```

Rules:
- Name the wrong claim AND the correct fact with its evidence (raw `.c` cast, trace
  string, exe byte-read, live probe result). A correction without evidence is just a
  second guess.
- Identify the entry by verbatim text or `FUN_` address — never by CHANGELOG line
  number (the file is append-heavy; numbers drift).
- One line per wrong fact. A systematic error class additionally gets a summary line
  naming the doc section and the class.
- Never delete the wrong doc content as part of the audit — the correction line is the
  audit trail; doc rewrites go through the normal pipeline (`f1c-doc-pipeline`) or an
  explicitly approved edit.

## Real examples (verbatim from work/CHANGELOG.md), spanning the main error classes

**1. Type error — float stored, int documented:**

> [CORRECTION] docs/12 TotalRaceLaps (DAT_008acf9c): stored as **IEEE 754 float**, not int32. Raw value 1093926912 = float(12.0). Previous docs treated as integer.

**2. Enum misread — wrong phase name:**

> [CORRECTION] docs/15 RacePhase sequence: noplayer race goes 0(IDLE)->2(GRID)->4(PACE)->5(GREEN)->8(FINISHED). Phases 1(FORMATION), 3, 6, 7 skipped in noplayer. Phase 5 = GREEN FLAG (not RED_FLAG as previously guessed).

**3. Wrong name — corrected by the game's own trace string:**

> [CORRECTION] docs/01 Game::Setup: FUN_004d36d0 was labeled "sound" — actually Steward::Setup (confirmed by "Entered Steward::Setup()" string at that address)

**4. Struct offset error — wrong byte offset in a frame-size read:**

> - `[CORRECTION] FUN_0052DE60: frame size reads +0x24cc not +0x2494 (docs/06)`

(Related recurring class: docs/13 rows using float* INDICES where byte offsets belong —
an index looks like a small offset and reads garbage when dereferenced as bytes. When
you hit a suspicious small offset on a float field, check for this before probing.)

## Bulk-audit shorthand

Mass audits in the CHANGELOG also use shorthand tags on individual rows:
`WRONG_MODDABILITY`, `MISSING_GLOBAL`, `WRONG_CONST`, `MISSING_ENTRY`. Use these only
inside a bulk-audit block that defines its scope; standalone findings use the full
`[CORRECTION]` line format above.

## What comes after logging

- Doc correction itself: via the pipeline or an approved edit — never silently.
- If globals/offsets changed: flag that `tools/gen_sdk.py` needs a deliberate re-run.
- If a mod ledger row was wrong (it has happened — the ledger once overstated a mod as
  shipped): correct `mods/_README.md` too and log that correction the same way.

---
Canonical sources: work/CHANGELOG.md; roles/ARCHITECT.md §VERIFICATION METHODOLOGY; REFERENCE.md §Verification Methodology (Architect role)
Last validated: 2026-07-18 against 6bcccfe
