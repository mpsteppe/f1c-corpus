# Fresh-race high-frequency Monza pit-route capture — 2026-08-30

Fresh runtime header: PID 4836, module base 0x00400000, vehicle base 0x005EC6D8, vehicle stride 0x48C0, zero unreadable reads. All fresh live waypoint pointers aligned to base 0x1784438C and stride 316 before index arithmetic was used.

The read-only capture ran 600.016 seconds at requested 20 Hz, recorded 11,804 samples and 104,111 events for slots 0-21, with zero unreadable reads. Its 300,000-event cap was not reached. CurrentWaypointPointer was correlated with CallToBox and PathSelector.

Direct natural-route sampling of active Monza records occurred with PathSelector=1 and CallToBox=1. Exact formula: index = (pointer - 0x1784438C) / 316. Index 983 is 0x178900F0 and index 984 is 0x1789022C.

Slot 12: index 983 at t=42.438, index 984 at t=42.750. Slot 15: 983 at 43.703, 984 at 44.000. Slot 13: 983 at 44.797, 984 at 45.109. Slot 18: 983 at 47.656, 984 at 47.953. Slot 17: 983 at 48.375, 984 at 48.672. Slot 20: 983 at 49.891, 984 at 50.188. Slot 19: 983 at 149.375, 984 at 149.688. Each listed pointer had zero base/stride remainder.

The sampled sequences include contiguous indices 980 through 987 for these slots, with observed intervals generally 0.20 to 0.31 seconds between adjacent waypoint records. Sampling gaps therefore exist relative to the game tick, but no gap occurred between the recorded 983 and 984 transitions above. This observation proves read-only co-occurrence of the route flags and direct pointer passage; it does not by itself prove causal semantics for the static (1,18) event annotation.
