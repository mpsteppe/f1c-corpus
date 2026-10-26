// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041AD80
// Canonical corpus name: sub_41AD80
// Owner: CollisionDetectionSystem [DERIVED]
// Raw source: functions/sub_41AD80_0041ad80.c

void CollisionDetectionSystem::OvertakingEventTracker()
{
    // Per-frame overtaking/passing event tracker invoked from the collision detection system. After race-active and track-condition guards, an overtake is accepted when the current session time (dbl_8AFEA0) is more than 2.0 seconds past the last recorded event for both drivers (per-driver element index 319, indexed by driver id read at a2+18580 / a3+18580) and the passed distance a4 exceeds 1250.0. On acceptance it records time, distance, and opponent references for both drivers, builds a local event record (v11) and emits event 114/115 when the player's driver (dword_7C54E8 + 18580) is one of the two participants, otherwise event 225/226 gated by a weather-noise table lookup (flt_8AB274 indexed by rotating byte counter dword_8AAE70). The filled record is appended via InsertDriverTableEntry(flt_5EA618, v11).
    // GUARD: Return early unless race-active flag dword_7D0308 is nonzero. [global:0x007D0308, source:raw]
    // GUARD: Continue only when flt_7CF3C8 is nonzero and dword_7C56A8 does not equal 8 (post-race phase excluded). [global:0x007CF3C8, global:0x007C56A8, source:raw]
    // GUARD: Accept overtake when session time dbl_8AFEA0 minus 2.0 exceeds the recorded last-event time for both drivers (element index 319 of the per-driver table selected by the driver id read at a2+18580 and a3+18580) and the passing distance a4 exceeds 1250.0. [global:0x008AFEA0, source:raw]
    // ASSIGNMENT: Record the overtake: set last-event timestamp (element index 319) to dbl_8AFEA0 for both drivers. [global:0x008AFEA0, source:raw]
    // ASSIGNMENT: Store the passing distance a4 at element index 423 and the opponent driver pointer (a3 for driver a2, a2 for driver a3) at element index 527 for both drivers. [source:raw]
    // CALCULATION: Compute the distance projection of both vehicles via DistanceProjectionCalc(a2 + 12) and DistanceProjectionCalc(a3 + 12); the two results are compared to determine overtake direction and which driver id is reported as overtaker. [callee:0x004F0050, source:raw]
    // CALL: Initialize the local event record v11 with sentinel values via StructInitWithSentinelValues. [callee:0x004144D0, source:raw]
    // GUARD: Read the player driver id v6 from dword_7C54E8 + 18580 and branch on whether it equals the driver id at a2+18580 or a3+18580 to detect player-involved overtakes. [global:0x007C54E8, source:raw]
    // CALL: For a player-involved overtake, fill v11 via DriverDataTableLookupAndTimeConversion with event code 114 or 115 (selected by the distance-projection comparison), passing the opponent driver id at +18588 and the sentinels -1, -1, -1, -2.0, -2.0. [callee:0x004144F0, source:raw]
    // CALL: For an AI-vs-AI overtake, draw weather-noise value flt_8AB274[(unsigned char)dword_8AAE70++] (incrementing the rotating byte counter) and fill v11 via DriverDataTableLookupAndTimeConversion with event code 225 when the noise is positive, otherwise 226, passing the overtaker/opponent driver ids at +18588 and sentinels -1, -1, -2.0, -2.0. [callee:0x004144F0, global:0x008AB274, global:0x008AAE70, source:raw]
    // CALL: Append the filled event record to the session event table via InsertDriverTableEntry(flt_5EA618, v11) and return. [callee:0x00418560, global:0x005EA618, source:raw]

    // Conservative worker pseudocode:
    //   if dword_7D0308 and flt_7CF3C8 != 0.0 and dword_7C56A8 != 8:
    //       if dbl_8AFEA0 - 2.0 > last_time[a2] and dbl_8AFEA0 - 2.0 > last_time[a3] and a4 > 1250.0:
    //           record overtake for both drivers (time = dbl_8AFEA0, distance = a4, opponent ref at index 527)
    //           v11 = StructInitWithSentinelValues();
    //           if player_driver == driver a2 or driver a3: emit event 114 or 115 (by distance comparison)
    //           else: emit event 225 or 226 gated by flt_8AB274[(unsigned char)dword_8AAE70++]
    //           InsertDriverTableEntry(flt_5EA618, v11)
    // UNRESOLVED: Semantic name of the per-driver element index 319 last-event time field is not given by any evidence; only its usage (cooldown against dbl_8AFEA0 - 2.0) is grounded.
    // UNRESOLVED: Exact event-code semantics (114/115 vs 225/226) and which +18588 driver id is the overtaker versus the overtaken are inferred from the branch structure and distance comparison, not confirmed by a label.
    // UNRESOLVED: Globals flt_59E440, flt_59E800, flt_59E820 are listed in the packet globals and referenced by existing analysis prose but do not appear in the raw decompilation; no operation could be grounded on them.
    // UNRESOLVED: abi:lead legacy symbol 'Overtake_Position_Swap' is LEGACY trust and was not promoted; proposed name 'OvertakingEventTracker' comes from the existing analysis fill and stays DERIVED.
}
