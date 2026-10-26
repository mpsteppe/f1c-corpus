# Archived shadow-source agent instructions

The shadow-source pipeline is preserved evidence, not an active objective. Do
not resume its workers or replacement-engine work. Use only
`python tools/f1c_mod.py search`, `inspect`, or `route` to access this tree. The
rules below are retained as historical provenance and do not supersede the root
`AGENTS.md` or `tools/sdk/LLM_OPERATING_CONTRACT.md`.

Read `RECONSTRUCTION_ORCHESTRATOR_RUNBOOK.md` completely before starting new
work. Read `LLM_CONTINUATION_RUNBOOK.md` when auditing the completed static
recovery pipeline or its historical wave machinery.

Non-negotiable rules:

- Treat this tree as an evidence-linked semantic reconstruction, not recovered
  original source code.
- Never edit or deploy a production mod, the original game executable, or an
  existing prototype from this work. Experimental output belongs only under
  `shadow_source/` and `replacement_engine/`.
  `xhigh` variant. Do not substitute `deepseek-v4-pro`.
  schedulers; do not launch task scripts in an unbounded loop.
- Workers and PowerShell wrappers must be hidden, non-interactive, and
  auto-closing. Preserve their stdout/stderr logs.
- A worker-written JSON file is not accepted until the deterministic validator
  reports it `VALID`. Never hand-promote worker confidence to `CONFIRMED` or
  `FACT` without independent static or runtime evidence.
- Preserve immutable evidence and unrelated user work. Do not rewrite files in
  `functions/`, `skeleton_facts_all.json`, `callgraph.json`,
  `analysis/recovery_index.json`, or `tools/sdk/` merely to make a proposal pass.
- Static breadth recovery ended at Wave 8 with 7,132/7,132 function IR files.
  Do not create Wave 9. The next phase recovers reviewed contracts and builds
  dependency-closed vertical slices in `replacement_engine/`.
