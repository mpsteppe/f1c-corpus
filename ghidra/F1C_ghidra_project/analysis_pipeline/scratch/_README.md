# analysis_pipeline/scratch/ — One-Off Pipeline Artifacts (DEAD)

Throwaway files from pipeline runs. Not components — safe to ignore.

- `_launch_*.ps1` (20) — per-worker launch scripts from a specific batch run
- `debug_struct*.py` — struct-parsing debug throwaways
- `temp_*.txt` — temporary file lists
- `poc_*` — proof-of-concept prompt/launcher experiments
- `_check_results.py`, `usage_limit.md` — run helpers/notes

Kept for provenance, not deleted. The live pipeline entry points are one level up:
`1_batch_gui.bat`, `2_merge.bat`, `batch_launcher.py`, `merge_to_docs.py`.
