# High-capacity passive pit-route capture — 2026-08-30

Capture tag: pit_transition_20260830_1546_highcap_waypoint_route_1200s. The approved hidden elevated observer ran against F1 Challenge Online.exe (PID 4836) from 2026-08-30T15:55:39.903Z to 2026-08-30T16:15:41.244Z. No game input, memory write, asset change, restart, or forced transition occurred.

CurrentWaypointPointer was sampled at 1 Hz with CallToBox context and PathSelector as an additional trigger. The record contains 1,200 samples over 1,200.844 seconds across slots 0-21, 23,064 retained events under a 35,000-event cap, and zero unreadable reads.

PathSelector changed 0 -> 1 while CallToBox was 1 for: slot 1 at t=404.281 (0x1788DD24); slot 5 at t=407.281 (0x1788D208); slot 16 at t=474.344 (0x1788D6F8); slot 12 at t=488.360 (0x1788D5BC); slot 14 at t=503.375 (0x1788CF90); slot 6 at t=533.391 (0x1788D6F8); slot 7 at t=582.422 (0x1788D6F8); slot 11 at t=582.422 (0x17887220); slot 2 at t=592.438 (0x1788D890); and slot 19 at t=611.438 (0x17887220).

The repeated pointers are 0x13C aligned. Under the supplied Monza branch-1 hypothesis, 0x1788CF90 aligns to index 983 and 0x1788D0CC to index 984; that is an alignment inference, not a validated pointer-to-index fact. Slot 5 moved from 0x1788691C (candidate index 900) at t=406.281 to 0x1788D208 (candidate index 985) at t=407.281 while PathSelector changed 0 -> 1 and CallToBox was 1. The one-second cadence did not directly sample candidate indices 983 or 984, so the capture cannot prove execution of (1,18) at those nodes. A future passive per-slot or targeted burst capture must retain each intermediate pointer change.
