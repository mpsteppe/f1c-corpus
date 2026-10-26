# Archived F1C Shadow Source

> Preserved evidence. Access it through `python tools/f1c_mod.py search`,
> `inspect`, or `route`; do not restart reconstruction from this document.

For a self-contained project handoff and exact continuation commands, read
[`LLM_CONTINUATION_RUNBOOK.md`](LLM_CONTINUATION_RUNBOOK.md). Agents operating
inside this tree must also follow [`AGENTS.md`](AGENTS.md).

This tree contains a generated, evidence-linked semantic reconstruction of the
game executable. It is not claimed original source code and is not a production
mod tree.

Immutable evidence remains in `functions/`, `skeleton_facts_all.json`,
`callgraph.json`, `analysis/recovery_index.json`, and `tools/sdk/`. Worker output
is accepted only into `shadow_source/ir/functions/` and must pass deterministic
validation before C++ maps are generated under `shadow_source/functions/`.

## Mixed pilot

```powershell
python tools/shadow_source.py pilot --count 50
python tools/shadow_source.py launchers --workers 8 --chunk 5
powershell -File shadow_source/launchers/launch_all.ps1
python tools/shadow_source.py batch
```

reasoning variant. Passing a system agent does not change that model selection.

Validate and generate one completed function:

```powershell
python tools/shadow_source.py validate shadow_source/packets/0042a3d0.json shadow_source/ir/functions/0042a3d0.json
python tools/shadow_source.py generate shadow_source/packets/0042a3d0.json shadow_source/ir/functions/0042a3d0.json
```

Worker agreement never promotes trust by itself. Runtime and independently
reviewed static evidence remain required for `CONFIRMED` or `FACT` status.

## Breadth-first recovery waves

Expansion waves select direct callers/callees, typed field-sharing neighbors,
same-subsystem functions, lifecycle routines, and frame-path functions around a
validated seed manifest:

```powershell
python tools/shadow_source.py wave --wave 1 --count 280
python tools/shadow_source.py launchers `
  --manifest shadow_source/waves/wave_001/manifest.json `
  --workers 50 --chunk 4 --max-packet-bytes 100000
powershell -File shadow_source/waves/wave_001/launchers/launch_all.ps1
python tools/shadow_source.py batch `
  --manifest shadow_source/waves/wave_001/manifest.json --force
```

Wave launchers use a bounded scheduler. It never permits more than 50 global
hidden, non-interactive windows. A wrapper exits immediately after its worker
and a brief filesystem settle; missing outputs are left for deterministic retry
instead of occupying a scheduler slot. Per-task stdout and stderr are retained
under each launcher directory's `logs/` folder.

## Architecture recovery

Validated function IR can be grouped into evidence-linked subsystem, class,
field, state-machine, interface, and compatibility-contract proposals:

```powershell
python tools/shadow_architecture.py build
python tools/shadow_architecture.py launchers --workers 8
powershell -File shadow_source/architecture_launchers/stage1/launch_all.ps1
python tools/shadow_architecture.py batch
```

This second-stage pipeline is also pinned to
every input function and every material field/global/callee reference to be
accounted for or explicitly marked unresolved.

Architecture for a recovery wave uses distinct packet, IR, report, and document
directories:

```powershell
python tools/shadow_architecture.py build `
  --source-manifest shadow_source/waves/wave_001/manifest.json `
  --phase wave_001 --max-packet-bytes 75000
python tools/shadow_architecture.py launchers `
  --manifest shadow_source/architecture_manifest_wave_001.json --workers 16
powershell -File shadow_source/architecture_launchers/wave_001/launch_all.ps1
python tools/shadow_architecture.py batch `
  --manifest shadow_source/architecture_manifest_wave_001.json --force
```

Independent whole-engine reconciliation candidates are generated after stage 1:

```powershell
python tools/shadow_reconcile.py build --candidates 3
python tools/shadow_reconcile.py launchers
powershell -File shadow_source/architecture_launchers/reconciliation/launch_all.ps1
python tools/shadow_reconcile.py batch
```

Equal offsets on unrelated `this` pointers are explicitly forbidden as merge
evidence. Candidate agreement remains a review aid and never promotes trust.
Architecture and reconciliation launchers use the same 50-process ceiling and
hidden auto-closing wrapper policy.

An already-launched recovery wave can be carried through deterministic
function repair and architecture repair without an interactive LLM supervisor:

```powershell
python tools/shadow_wave_supervisor.py --wave 3 --workers 50 --repair-chunk 1
```

The supervisor records a durable audit log in `shadow_source/reports/` and
finishes only when both validation summaries are clean or the configured repair
limit is reached.
