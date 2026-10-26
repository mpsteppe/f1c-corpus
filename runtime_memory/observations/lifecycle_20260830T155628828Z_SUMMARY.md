# Passive lifecycle-boundary monitor — 2026-08-30

## Scope and controls

This is an additive, read-only runtime-evidence record for the running
`F1 Challenge Online.exe` session. The monitor used only
`python tools/f1c_mod.py` runtime and memory recipes through hidden elevated
PowerShell after normal process access was denied. No game input, memory write,
file or asset modification, restart, track change, or forced transition was
issued.

## Result

No natural session end/setup/restart/track reload or weather/grip-triggered AIW
rebuild was observed in this bounded window. This is negative evidence for this
specific interval, not proof that these transitions cannot occur.

The lap discriminator continued to identify normal race state but stopped
emitting lap increments after monitor time 469.359 seconds. A separate pit
trace reported a clustered `PitStatus 2 -> 4` behavior at approximately
1129--1198 seconds. That behavior is **compatible with post-running
return-to-pits**, but it is not treated as a session boundary: no lap reset,
AIW header change, reparse event, or memory-diff transition candidate was
observed.

## Read-only observations

| Monitor | Duration / sampling | Result |
|---|---:|---|
| Race discriminator (`lapNumber`) | 1800.296 s; 1799 samples at 1 Hz; 22 live slots | 321 natural monotonic `+1` changes; no reset and no increment in the 1129--1198 s pit-cluster interval. |
| AIW rebuild state | 1800.469 s; 3596 samples at 2 Hz | 0 events. Semantic header slot 0 remained `RebuildPhase=0`, `RebuildCursor=-1`, `LastGripBlend=1.0`. |
| AIW allocation pointers | 1800.172 s; 3595 samples at 2 Hz | 0 events. Semantic header slot 0 remained waypoint pointer `0x1784438C`, waypoint count `1204`, grid pointer `0x1330B528`. |
| Header pre/post reads | before and after the monitor window | Selected path, waypoint count/pointer, grid/pit/garage pointers, and garage count were identical (see sidecar). |
| Process snapshots/diff | one process-scoped snapshot before and after | Same process and module SHA-256; 22,146 changed pages, 520 added pages, 7 removed pages, and 0 transition candidates. |

The fixed selected path was
`SEASONDATA\\CIRCUITS\\Italy\\2002_Monza\\2002_Monza.AIW`. Pre/post values
were waypoint count `1204`, waypoint pointer `0x1784438C`, grid pointer
`0x1330B528`, pit pointer `0x04BA8008`, garage pointer `0x175906B0`, and
garage count `3`.

## Artifacts

- `runtime_memory/observations/lifecycle_20260830T155628828Z_rebuild/correlation.json`
- `runtime_memory/observations/lifecycle_20260830T155628828Z_pointers/correlation.json`
- `runtime_memory/observations/lifecycle_20260830T155628828Z_lap/{observation,report}.json`
- `runtime_memory/lifecycle_20260830T155628828Z_{pre,post}/manifest.json`
- This summary and `lifecycle_20260830T155628828Z_summary.json`

## Limitations and follow-up

No lifecycle or weather trigger occurred naturally during the bounded window.
The AIW custom-recipe reader is deliberately rebased to the global AIW header;
only slot 0 is semantically meaningful, while its other stride-derived rows are
adapter artifacts. Re-observe a naturally occurring session transition or
weather change before assigning causal semantics to the pit cluster.

## Wasted-effort check

One status-check command used an invalid inline PowerShell `if` expression and
was immediately corrected. The initial normal `OpenProcess` denial required the
already authorized elevated pattern. No broad build or repeated active test was
run; monitor waiting was necessary to observe a natural boundary.

## Verification

The JSON sidecar parsed successfully and every referenced primary artifact was
present. The workspace-structure validator was rerun after creating this
additive record; it still reports the same nine pre-existing workspace errors
(missing root game paths, one Randomizer production path, and four source-like
files under the Bug Report Site production tree). This observation task did not
alter any of those paths or their state.
