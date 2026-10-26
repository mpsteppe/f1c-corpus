# analysis_pipeline/ — DS-Worker Documentation Pipeline

The batch system that produced `docs/`. Uses DeepSeek V4 Flash workers driven by
`roles/WORKER.md` to triage and document functions.

## What matters here

| Path | Purpose | Trust |
|------|---------|-------|
| `analyzed/` | **6,116+ raw decompiled `.c`** — the main FACT-tier source corpus | FACT |
| `batch_launcher.py` | GUI generating/launching worker prompts (26 modes) | tooling |
| `merge_to_docs.py` | Merge worker output → `docs/` | tooling |
| `1_batch_gui.bat`, `2_merge.bat` | Main entry points | tooling |
| `output/` | Active worker output (worker_A.md …) | intermediate |
| `prompts/` | Saved worker prompts | intermediate |

## Scratch / historical (safe to ignore — being archived per PLAN_reorg)

`_launch_*.ps1` (20 files), `debug_struct*.py`, `temp_*.txt`, `poc_*`,
`_check_results.py`, `_extract_*`, `usage_limit.md`. These are one-off run
artifacts, not components.

## Path warning

`analyzed/` and `output/` are referenced by hardcoded paths in the pipeline
scripts and CLAUDE.md — do not move them without updating references.

Full pipeline docs: see `CLAUDE.md` → "Parallel Worker Workflow".
