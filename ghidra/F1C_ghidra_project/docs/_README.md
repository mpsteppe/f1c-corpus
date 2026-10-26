# docs/ — Documentation (mixed trust)

Authoritative documentation output. **Trust varies per file** — the biggest
clarity trap in the repo. Verify anything precise against raw `.c` source.

## Trust map

| Files | Content | Trust | Note |
|-------|---------|-------|------|
| `00-*` | Architecture manual, methodology, source tree | mixed | narrative synthesis |
| `01`–`10` | Game systems (engine, AI, tire, weather, race, pit, files, track, physics) | **FACT-leaning** | string-anchored to real functions |
| `11` | F1CLiveUI plugin | reference | community tool |
| `12-globals-reference.md` | ~8,048 DAT_ globals | **GUESS** | DS-worker labels — verify by exe byte-read |
| `13-struct-offsets.md`, `13-audit-report.md` | struct field offsets | **GUESS** | verify against `.c` |
| `14-*`, `15-*`, `16-*` | corrections, limits, moddable fields, lifecycles | mixed | |
| `17`–`21` | Engine internals (collision, dynamics, renderer, math, audio/net) | mixed | semantic names may be LEAD |
| `22`–`26` | frame loop, modding ref, gaps, enums, cv2 corrections, F1CUI offsets | mixed | |
| `27-cross-binary-reference.md` | NASCAR match, 17 ISI classes | **CONFIRMED** | cross-binary verified |
| `30-impl-specs/` | 18 reimplementation specs | **LEAD** | synthesized — treat as hints |
| `31-call-chains/` | 237 call chain traces | **LEAD** | ⚠️ some hallucinated (e.g. 0008 mislabeled a network func as "track grip") |
| `32-sibling-exclusive-functions.md` | F1C↔F1 2002 portability matrix | mixed | port verdicts |
| `33-capability-bible.md` | modding capability reference (audited) | mixed | see CHANGELOG 2026-07-17 corrections |
| `34-source-atlas.md` | real file/line/name coords from baked trace/assert literals | **FACT** (data) + heuristic (target_addr) | per-column tiers inside; data `work/source_atlas.csv`, `work/source_file_map_expanded.csv` |
| `35-mod-targets.md` | 155 ranked enforcement/validation patch-points | **FACT** (string↔func xref) + **HYPOTHESIS** ("patch X changes Y") | only 0x004bc0e0 DQ confirmed; rest candidates; data `work/mod_targets.csv` |
| `36-vtables.md` | 181 recovered C++ vtables (RTTI-less), 3202 method slots | **FACT** (raw .rdata bytes; 72% slots resolve to known funcs) + DERIVED ctor attribution | class NAMES mostly open; data `work/vtables.csv` |
| `37-fp-constants.md` | 845 FP constants (physics/math magic numbers) with values + readers | **FACT** (raw IEEE-754 bytes) + DERIVED file attribution | data `work/fp_constants.csv` |
| `decompiled_full_index_final.md` | master triage table (7,108 rows) | DERIVED | one-line-per-function index |

## Rule

For modding or any precise claim: a doc is a lead, the raw `.c` in
`analysis_pipeline/analyzed/` or `decompiled_all/` is the truth. When they
disagree, the source wins. Use `tools/mod_pipeline/asm_tools.py resolve <addr>`
to get confirmed identity fast.
