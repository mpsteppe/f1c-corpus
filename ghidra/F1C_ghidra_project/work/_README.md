# work/ — Planning, Merge Scripts, Working Data

Mixed bag (being split by `PLAN_reorg.md` into `meta/` + `tools/pipeline_merges/`).
Until then, three kinds of thing live here:

## Plans & process (meta)

| File | Purpose |
|------|---------|
| `PLAN_reorg.md` | **Repo reorganization plan (active)** |
| `PLAN_recreation.md`, `PLAN_hardening.md`, `PLAN_building_manual.md` | strategy plans |
| `PLAN_source_recovery.md`, `PLAN_launcher_modes.md` | older plans |
| `HANDOFF.md` | Session handoff (prior state) |
| `QUEUE.md` | Task queue (single source of "what's next") |
| `CHANGELOG.md` | `[CORRECTION]` log from audits |
| `CORRECTIONS_phase1.md`, `DISCOVERY_*.md`, `BREAKTHROUGH_*.md` | findings |

## Merge scripts (tooling — belong with pipeline)

`merge_*.py` (15 files) — merge specific DS-worker mode outputs into `docs/`.
Each is documented in CLAUDE.md → "Key Commands". Referenced by absolute paths,
so moving needs a CLAUDE.md update.

## Working data (DERIVED)

`function_sizes.csv`, `new_call_edges.csv`, `new_function_candidates.csv`,
`binary_coverage_gaps.csv`, `orphan_resolve_summary.csv`.

## For an LLM

Current status/next-steps: read `QUEUE.md` and `CHANGELOG.md`. Strategy context:
the `PLAN_*.md` files. Everything else here is tooling/data.
