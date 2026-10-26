# Passive pit-transition observation — 2026-08-30

## Scope and safety

This is a read-only live-session record for `F1 Challenge Online.exe` (PID 4836).
No game input, memory write, asset edit, restart, forced pit action, or executable
change was performed. Normal process access was denied; the approved hidden,
elevated PowerShell observer was therefore used.

The custom approved recipe was
`aiw_navigation_20260830_live_vehicle_waypoint_recipes.json`.

## Completed 900-second records

| Record | Requested rate | Actual duration / samples | Events | Result |
| --- | ---: | ---: | ---: | --- |
| `pit_transition_20260830_1524_current_prev_900s` | 3 Hz | 900.062 s / 2,695 | 6,000 (configured cap) | all 22 active slots readable; waypoint history capture reached its event retention cap before the relevant pit routing transitions, so it cannot establish exact waypoint indices for the pit episode. |
| `pit_transition_20260830_1525_callbox_waypoint_900s` | 2 Hz | 900.438 s / 1,799 | 4 | natural pit-routing episode observed for slot 18. |
| `pit_transition_20260830_1525_lap_role_900s` | 1 Hz | 900.532 s / 900 | 195 | all 22 active slots readable; slot 18 remained controller role 1. |

All completed records reported zero unreadable reads and identified the game module
base as `0x00400000`, vehicle array base as `0x005EC6D8`, and vehicle stride as
`0x48C0`.

## Natural pit-routing episode (slot 18)

The episode began on lap 17 (slot 18 changed from lap 16 to 17 at t=179.094 s)
and preserved controller role 1 throughout. The correlator recorded:

| t (s) | Field transition | Current waypoint pointer |
| ---: | --- | --- |
| 188.172 | `CallToBox` 0 -> 1; `PathSelector` 0 | `0x1784D180` |
| 273.750 | `PathSelector` 0 -> 1; `CallToBox` 1 | `0x1788D208` |
| 285.766 | `CallToBox` 1 -> 0; `PathSelector` 1 | `0x17892108` |
| 310.281 | `PathSelector` 1 -> 0; `CallToBox` 0 | `0x17899510` |

The simultaneous AIW header monitor retained waypoint base `0x1784438C`, count
1204, and the active `2002_Monza` path throughout this episode. Applying the
already live-validated 316-byte stride gives exact aligned indices:

| Event | Pointer | Index | Active-asset branch |
| --- | --- | ---: | --- |
| CallToBox `0 -> 1` | `0x1784D180` | 115 | main branch 0 |
| PathSelector `0 -> 1` | `0x1788D208` | 945 | pit branch 1 |
| CallToBox `1 -> 0` | `0x17892108` | 1009 | pit branch 1 |
| PathSelector `1 -> 0` | `0x17899510` | 1103 | main branch 0 |

This directly validates a natural CallToBox/path-selector pit cycle and the
active asset's branch boundary interpretation. Static Monza event nodes 983
and 984 lie between the observed branch-1 indices 945 and 1009, but the capped
high-frequency pointer stream did not retain this later interval. Their actual
passage and visible `(1,18)` effect therefore remain strongly bracketed rather
than directly sampled.

## Negative / failed collection details

`pit_transition_20260830_1525_path_callbox_900s` created no correlation
artifact even though its elevated observer launched; it had exited by final
inspection. No partial data was recovered or inferred.

An earlier pre-adjustment 1,800-second lap/role observer (Python PID 17420,
started 2026-08-30T15:21:06Z) remained outside the revised 900-second weather
window. It was explicitly stopped through the same approved elevated session;
only that observer process was targeted, and the game process was not stopped.

## Follow-up

Use a bounded per-slot or higher-capacity read-only waypoint capture around a
subsequent natural CallToBox event to sample indices 983/984 directly and
separate their `(1,18)` effect from the broader pit-route cycle.
