# Post-restart AIW header comparison — 2026-08-30

## Result

This additive, read-only comparison captured the AIW header immediately after
the owner-reported fresh race restart and compared it with the prior race's
final header. The visible header is identical: selected path
`SEASONDATA\\CIRCUITS\\Italy\\2002_Monza\\2002_Monza.AIW`; waypoint count/pointer
`1204` / `0x1784438C`; grid/pit/garage pointers `0x1330B528` / `0x04BA8008` /
`0x175906B0`; capacities `1` / `104` / `52` / `3`; and rebuild phase/cursor/blend
`0` / `-1` / `1.0`.

The fresh baseline therefore reused the same observable allocation addresses and
header values. It does not prove that no parser or rebuild executed during the
unobserved gap: allocator reuse can produce the same addresses, and the boundary
was not continuously captured.

## Bounded evidence

- The fresh header was monitored for 120.172 seconds at 5 Hz (599 samples):
  zero rebuild/cursor events, with phase `0`, cursor `-1`, and blend `1.0`.
- The prior-final and fresh process snapshots have the same process and module
  SHA-256. Their map-aware diff found 14,789 changed, 1,181 added, and 5,894
  removed pages, but zero transition candidates. The fresh capture had 19
  unreadable pages, so this is not a byte-for-byte assertion.
- No game input, memory write, restart, track change, file/asset change, or
  forced transition was issued. Elevated PowerShell was used only to meet the
  game's integrity level.

## Artifacts

- `runtime_memory/lifecycle_20260830T155628828Z_post/manifest.json`
- `runtime_memory/restart_compare_20260830T163941449Z_current/manifest.json`
- `runtime_memory/observations/restart_compare_20260830T163941449Z_rebuild/correlation.json`
- This summary and `restart_compare_20260830T163941449Z_summary.json`

## Limitation and wasted-effort check

This is a post-restart comparison, not a direct transition trace. Only slot 0
of the rebased AIW header reader is semantic. One read-only status-check command
had an invalid inline PowerShell `if` expression and was corrected; no broad
build or active test was run.

## Verification

The JSON sidecar parsed successfully and all primary artifacts were present.
The workspace-structure validator still reports its nine pre-existing errors
and zero warnings; this read-only evidence task did not alter any affected
workspace path.
