# F1C shadow-source continuation runbook

> **Historical static-recovery runbook:** Waves 1 through 8 are complete. Do
> not launch another breadth-recovery wave. New orchestrators must start with
> `RECONSTRUCTION_ORCHESTRATOR_RUNBOOK.md`. Keep this file as the operational
> record for validating, reproducing, or repairing existing wave artifacts.

This document lets a new LLM continue the reconstruction without access to the
conversation that created it. Work from repository root:

`%USERPROFILE%\Desktop\f1c_ida_decompiled`

## Mission

Build an evidence-linked, human-reviewable semantic model of the F1 Challenge
engine, then use that model as the specification for a clean, isolated
replacement executable. The goal is source-like navigation and controlled
feature rewriting. This process does **not** recover the original source text,
and decompiler/LLM output must never be presented as original source.

The immutable static corpus currently contains 7,132 functions. At the start of
Wave 2, 330 function IR files were validated. Roughly 7,000 functions therefore
remain; process them in bounded waves rather than loading the corpus into one
LLM context.

## Hard safety and isolation rules

1. Never modify or deploy production mods, existing prototypes, or the original
   game executable. All reconstruction experiments stay in `shadow_source/`;
   clean-room executable work stays in `replacement_engine/`.
2. Preserve unrelated work in the dirty worktree. Never use destructive Git
   recovery commands.
   The generated launchers enforce this. Never change them to v4-pro.
5. Launch only through each phase's `launch_all.ps1`. It starts hidden,
   non-interactive, auto-closing task wrappers. Do not open one terminal per
   worker manually.
6. Worker JSON is untrusted until deterministic validation succeeds. Candidate
   agreement helps prioritize review but does not establish runtime truth.
7. Equal offsets on unrelated `this` pointers are not proof that fields or
   classes are identical.

## Authoritative inputs and generated outputs

Do not edit the evidence to fit a hypothesis:

- `functions/`: raw/decompiled function corpus.
- `skeleton_facts_all.json`: static function facts.
- `callgraph.json`: static calls.
- `analysis/recovery_index.json`: searchable recovery index.
- `tools/sdk/`: reviewed SDK evidence and runtime/static contracts.

Pipeline outputs:

- `shadow_source/packets/` and `shadow_source/waves/*/packets/`: bounded worker
  evidence packets.
- `shadow_source/ir/functions/`: worker function IR accepted only after
  validation.
- `shadow_source/functions/`: generated C++ semantic maps.
- `shadow_source/ir/architecture/`: architecture proposals.
- `shadow_source/ir/architecture/reconciliation/`: independent reconciliations.
- `shadow_source/reports/`: machine-readable validation/comparison reports.
- `shadow_source/architecture/`: human-readable subsystem maps.
- `*/launchers/logs/`: retained worker stdout/stderr.

## Current operation: infrastructure Wave 2

Wave 2 contains 480 infrastructure-biased functions:

`shadow_source/waves/wave_002/manifest.json`

It prioritizes startup, main-loop, configuration, archive/MAS, filesystem,
rendering, window/input, audio, session, and plugin paths, plus direct graph
neighbors. Its launchers contain 121 chunks of at most four functions. If a
scheduler is already running, do not launch a duplicate.

Inspect progress safely:

```powershell
$processes = Get-CimInstance Win32_Process |
"total=$($processes.Count)"
"wave2=$(@($processes | Where-Object CommandLine -match 'wave_002').Count)"
python tools\shadow_source.py batch `
  --manifest shadow_source\waves\wave_002\manifest.json `
  --force --allow-missing
```

The batch command writes `shadow_source/reports/wave_002_validation.json`.
`--allow-missing` is only for progress inspection. Completion requires exactly
480 valid, zero invalid, and zero missing.

If Wave 2 has not been launched, regenerate only the launchers and start the
bounded scheduler:

```powershell
python tools\shadow_source.py launchers `
  --manifest shadow_source\waves\wave_002\manifest.json `
  --workers 50 --chunk 4 --max-packet-bytes 100000
powershell.exe -NoLogo -NoProfile -NonInteractive `
  -ExecutionPolicy Bypass -WindowStyle Hidden `
  -File shadow_source\waves\wave_002\launchers\launch_all.ps1
```

without `--allow-missing`. On failure, regenerate launchers from the same
manifest. The generator includes only invalid/missing work. Use chunks of one
for final repairs to isolate failures:

```powershell
python tools\shadow_source.py launchers `
  --manifest shadow_source\waves\wave_002\manifest.json `
  --workers 50 --chunk 1 --max-packet-bytes 100000
powershell.exe -NoLogo -NoProfile -NonInteractive `
  -ExecutionPolicy Bypass -WindowStyle Hidden `
  -File shadow_source\waves\wave_002\launchers\launch_all.ps1
python tools\shadow_source.py batch `
  --manifest shadow_source\waves\wave_002\manifest.json --force
```

Repeat only for remaining invalid/missing items. Read each validation error; do
not weaken validation to accept hallucinated addresses, omitted functions, or
unsupported evidence.

## Current operation: hierarchical Wave-1 reconciliation

There are five scope manifests, each requesting three independent candidates:

- `reconciliation_manifest_wave1_generic_runtime_objects.json`
- `reconciliation_manifest_wave1_math_and_collision.json`
- `reconciliation_manifest_wave1_ui_platform_and_options.json`
- `reconciliation_manifest_wave1_vehicle_ai_and_pit.json`
- `reconciliation_manifest_wave1_vehicle_physics.json`

For every manifest, validate after active reconciliation workers finish:

```powershell
python tools\shadow_reconcile.py batch `
  --manifest shadow_source\reconciliation_manifest_wave1_vehicle_physics.json
```

Regenerate and start its launchers to repair only bad/missing candidates:

```powershell
python tools\shadow_reconcile.py launchers `
  --manifest shadow_source\reconciliation_manifest_wave1_vehicle_physics.json `
  --workers 50
powershell.exe -NoLogo -NoProfile -NonInteractive `
  -ExecutionPolicy Bypass -WindowStyle Hidden `
  -File shadow_source\architecture_launchers\reconciliation\wave1_vehicle_physics\launch_all.ps1
```

Do the equivalent for all five phase names. Once one scope reaches 3 valid, 0
invalid, 0 missing, generate its agreement/dispute report:

```powershell
python tools\shadow_reconcile.py compare `
  --manifest shadow_source\reconciliation_manifest_wave1_vehicle_physics.json
```

Do not overwrite an output whose worker is still running. Some large physics
packets legitimately take much longer than small UI packets.

## Subsequent recovery waves

Once Wave 2 is fully valid, build Wave-2 architecture:

```powershell
python tools\shadow_architecture.py build `
  --source-manifest shadow_source\waves\wave_002\manifest.json `
  --phase wave_002 --max-packet-bytes 75000
python tools\shadow_architecture.py launchers `
  --manifest shadow_source\architecture_manifest_wave_002.json --workers 50
powershell.exe -NoLogo -NoProfile -NonInteractive `
  -ExecutionPolicy Bypass -WindowStyle Hidden `
  -File shadow_source\architecture_launchers\wave_002\launch_all.ps1
python tools\shadow_architecture.py batch `
  --manifest shadow_source\architecture_manifest_wave_002.json --force
```

For Wave 3 and later, use a new wave number and the prior manifest as the seed.
Default `frontier` selection grows through calls, typed-field overlap,
subsystems, lifecycle, and frame paths. Never use `--force` on `wave` unless the
intent is to replace an unlaunched manifest after reviewing the consequences.

```powershell
python tools\shadow_source.py wave `
  --wave 3 --count 480 --focus frontier `
  --seed-manifest shadow_source\waves\wave_002\manifest.json
python tools\shadow_source.py launchers `
  --manifest shadow_source\waves\wave_003\manifest.json `
  --workers 50 --chunk 4 --max-packet-bytes 100000
powershell.exe -NoLogo -NoProfile -NonInteractive `
  -ExecutionPolicy Bypass -WindowStyle Hidden `
  -File shadow_source\waves\wave_003\launchers\launch_all.ps1
```

Repeat the function validation/repair loop, then the architecture loop. Prefer
meaningful subsystem/frontier coverage over merely choosing the next addresses
numerically. Keep manifests immutable after workers begin so every result stays
reproducible.

## Autonomous wave supervision

After a wave's initial function scheduler has been launched, the deterministic
supervisor can finish its validation/repair loop and architecture stage without
keeping an LLM conversation open:

```powershell
python tools\shadow_wave_supervisor.py `
  --wave 3 --workers 50 --repair-chunk 1 `
  --poll-seconds 20 --max-repairs 8
```

It waits for the existing bounded queue, validates the report, launches only
invalid/missing function repairs, builds architecture, and repeats the same
process for architecture packets. It does not interpret results, relax
validation, create later recovery waves, or touch production paths. Its durable
status log is `shadow_source/reports/wave_NNN_supervisor.log`; completion is the
explicit line `COMPLETE: function and architecture reports are clean`.

## Process and failure handling

  progress there. The JSON validator is authoritative.
- Task wrappers release their scheduler slot just after the worker exits. A
  worker may write output before it exits, so wait for the corresponding process
  before repairing that item. Missing outputs are handled by validation/retry,
  never by keeping a dead wrapper open.
  removed, resolve its full command line and target only the exact wave/task.
  `CommandLine`.
- Keep the user informed during long batches; unchanged runtime state is normal.


Do not rotate credentials because a task is slow or one worker fails. First
confirm a quota/authentication error in the worker logs and allow affected
workers to exit so all partial outputs remain available. Then run exactly once:

```powershell
  --source %USERPROFILE%\Desktop\api.txt --smoke-test
```

performs one isolated DeepSeek Flash/xhigh request, and restores the backup when
that request fails. Never print, quote, hash, copy into a report, or otherwise
expose either credential. `ALREADY_CURRENT`, `ROLLED_BACK`, or `ERROR` is a hard
stop requiring user attention; do not loop rotations. After `ROTATED` and
`SMOKE_OK`, resume/repair the same immutable wave before considering a later
wave.

## Deterministic verification

Run after tool changes and before handing off a completed milestone:

```powershell
python -m py_compile `
  tools\shadow_source.py tools\shadow_architecture.py tools\shadow_reconcile.py
python tools\sdk\tests\test_shadow_source.py
python tools\sdk\tests\test_shadow_architecture.py
python tools\sdk\tests\test_shadow_reconcile.py
& 'C:\Program Files\CMake\bin\ctest.exe' `
  --test-dir replacement_engine\build --output-on-failure
```

Also confirm there are no visible worker windows (`MainWindowHandle` must be 0),
all required validation reports are clean, and no production path changed.

## Milestone bookkeeping

After a wave is genuinely complete:

1. Record exact valid/invalid/missing totals in
   `shadow_source/architecture/CURRENT_SCOPE.md`.
2. Add a concise `WAVE_NNN_SUMMARY.md` with selection rationale, coverage,
   validation totals, architecture totals, and unresolved disputes.
3. Keep claims calibrated: `PROPOSED` is not `LIKELY`; `LIKELY` is not
   `CONFIRMED`; static agreement is not runtime validation.
4. Continue implementing the replacement engine only from reviewed contracts.
   Never deploy `replacement_engine/build/F1ChallengeReplacement.exe` over the
   original executable during reconstruction.
