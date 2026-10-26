# MANIFEST — Every Top-Level Item

Complete inventory of the repo root. Trust tiers per `INDEX.md`.
Regenerable = can be rebuilt from the binary/docs without manual work.

## Directories

| Item | Files | Purpose | Trust | Regenerable |
|------|-------|---------|-------|-------------|
| `.claude/skills/` | 15+_meta | `f1c-*` workflow skills (router = `f1c-start-here`); `_meta/` = CONVENTIONS, TEMPLATE, CATALOG, toolfacts, doc-anchors, sim_rubrics, `validate_skills.py` | authoritative | no |
| `docs/` | 296 | Authoritative documentation, 00–37 by system + specs/chains (32 port matrix, 33 capability bible, 34 source atlas, 35 mod targets, 36 vtables, 37 fp-constants) | mixed (see docs/_README.md) | partial |
| `decompiled_all/` | 666 | String-anchored raw `.c` — identifiable functions | FACT | yes (Ghidra) |
| `analysis_pipeline/` | 7,512 | DS-worker doc pipeline; `analyzed/` = 6,116+ raw `.c`; `output/`, `prompts/` | FACT source + tooling | analyzed=yes |
| `tools/` | 586 | Scripts + 27 IDA/cross-binary CSVs + subtools | code + DERIVED | csv=yes |
| `tools/mod_pipeline/` | — | Modding pipeline: SEED/MAP/WATCH/PATCH, asm_tools, PLAYBOOK, mods | tooling | no |
| `tools/trace/` | — | Frida runtime tracing agents | tooling | no |
| `tools/knowledge_graph/` | — | Graph extract/build/query scripts | tooling | no |
| `tools/decompiled_ida/` | 495 | IDA Hex-Rays raw `.c` (IDA-only functions) | FACT | yes (IDA) |
| `knowledge_graph/` | 12 | Call graph / callers / globals / structs as JSON | DERIVED | yes |
| `mods/` | 7 | Shipped mods (red-flag-dll) | output | no |
| `cross_binary/` | — | isiMotor1 sibling cross-binary delta: byte/source/string matchers, feature-diff, 2,357 sibling-exclusive functions with port verdicts; own `_README.md` | tooling + DERIVED | yes |
| `source_material/` | — | isiMotor1 sibling game installs + decompiled corpora + per-game `docs/40-43` (only docs/ tracked; binaries/DBs gitignored) | FACT source + docs | decompiles=yes |
| `source_recovery/` | 35 | Binary-forensics workspace; own `ACTION_PLAN.md` + `FINDINGS.md` | mixed | no |
| `roles/` | 3 | WORKER / LEAD / ARCHITECT LLM system prompts | reference | no |
| `scripts/` | 13 | Ghidra Java extraction scripts | tooling | no |
| `work/` | 37 | Plans (PLAN_*.md), merge scripts (merge_*.py), working CSVs | meta + tooling | no |
| `reference/` | 1 | constants.md | reference | no |
| `monitor_output/` | 56 | Runtime struct-dump snapshots (F1CUI/Frida) | DERIVED | yes |
| `F1C_Analysis.rep/` | 9 | Ghidra project database | tool artifact | no (the analysis) |

## Loose root files (after Phase 1)

| Item | Purpose | Trust |
|------|---------|-------|
| `INDEX.md` | Entry point | authoritative |
| `MANIFEST.md` | This file | authoritative |
| `CLAUDE.md` | Operational instructions + state | authoritative |
| `README.md` | Public-facing overview | authoritative |
| `.gitignore`, `.gitattributes` | Git config | — |
| `F1C_Analysis.gpr` | Ghidra project file | tool artifact |
| `commit.bat` | Commit helper | tooling |

Root is now clean — only index files, git config, the Ghidra project, and the
commit helper remain.

## Phase 1 moves completed (nothing deleted)

| From (root) | To |
|-------------|----|
| `driver0/1/2.bin`, `driver0.CEM` | `inputs/memory_dumps/` |
| `strings_raw.txt` | `inputs/raw_strings/` |
| `driver0/1_annotated.txt`, `driver0/1_gaps.csv` | `data/inventory/` |
| `inventory.csv` | `data/inventory/` |
| `search_docs.py`, `.bat` | `tools/` |
| `ds.txt`, `opus_chat.txt` | `archive/chat_logs/` |
| `inventory_run.log` | `archive/` |
| `analysis_pipeline/_launch_*.ps1`, `debug_struct*`, `temp_*`, `poc_*`, `_check_results.py`, `usage_limit.md` | `analysis_pipeline/scratch/` |

References updated: `tools/parse_struct_dump.py` (usage), `docs/00-methodology.md`
(inventory path), `work/BREAKTHROUGH_trace_mining.md`, `work/DISCOVERY_external_sources.md`,
`source_recovery/ACTION_PLAN.md` (strings_raw path).

## Notes

- **Nothing in this repo is deleted during reorganization.** Scratch is archived.
- Moves that touch path-referenced files (`tools/*.csv`, `decompiled_all/`) are
  deferred to Phase 3 of `work/PLAN_reorg.md` with a grep-and-update pass.
- This manifest reflects the CURRENT layout. It is updated as reorg phases land.
