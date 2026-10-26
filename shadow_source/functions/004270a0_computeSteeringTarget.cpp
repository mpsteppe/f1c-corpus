// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004270A0
// Canonical corpus name: AISteering
// Owner: RacingLineSteeringController [DERIVED]
// Raw source: functions/AISteering_004270a0.c

void RacingLineSteeringController::computeSteeringTarget()
{
    // Per-frame AI steering target computation. Scans the 5-lane lateral-boundary table, computes a centre steering value clamped between left/right bounds, evaluates the nearest opponent in each lane via spatial nearest-neighbour queries, scores lanes and picks steering targets, and drives overtaking state transitions (mode codes 1/2/4/7/8/16) with session-time steering overrides.
    // GUARD: Guard: skip a lane candidate when its in-garage flag (track-position data +0x12C) equals 1. [guard:0, field:*(this+0x4354):0x0000012C]
    // GUARD: Guard: callToBox flag (this+0x454C) equals 1 enables pit-box steering override path. [guard:1, field:this:0x0000454C]
    // GUARD: Guard: pit-lane entry flag (this+0x4550) equals 1 enables pit-lane steering override path. [guard:2, field:this:0x00004550]
    // LOOP: Scan the 5 lane entries (lane table at this+0x4174, pointers also read through this+0x4354 / this+0x4358) and track the running left-boundary minimum (+0x50) and right-boundary maximum (+0x54) across lane track-position data. [field:this:0x00004354, field:this:0x00004358, field:*(this+0x4354):0x00000050, field:*(this+0x4354):0x00000054, field:*(this+0x4358):0x00000050, field:*(this+0x4358):0x00000054, field:this:0x00004174]
    // CALCULATION: Compute centre steering (this+0x4420), the boundary midpoint, and normalised left/right lateral ratios from the current lateral offset (this+0x441C), bounded by this+0x4414 and this+0x4418. [field:this:0x00004420, field:this:0x0000441C, field:this:0x0000440C, field:this:0x00004414, field:this:0x00004418]
    // STATE_TRANSITION: If the steering-latch byte (this+0x4579) is set, snap or step the steering target (this+0x440C) toward centre (this+0x4420) in 0.2 increments. [field:this:0x00004579, field:this:0x0000440C, field:this:0x00004420]
    // STATE_TRANSITION: Reset per-frame state: clear steering-latch byte (0x4579), overtake side indices (0x4570 / 0x4574), overtake counter (0x455C), reset override gain to 1.0 (0x4554) and clear the block flag byte (0x456C). [field:this:0x00004579, field:this:0x00004570, field:this:0x00004574, field:this:0x0000455C, field:this:0x00004554, field:this:0x0000456C]
    // CALCULATION: Session-time gates (global session time vs race-time offset): when dbl_8AFEA0 < flt_8ACF90 + 6.5 / + 2.5, override the steering target (this+0x440C) from the selected opponent car (indexed via this+0x4468 and this+0x44FC) and this+0x4428. [global:0x008AFEA0, global:0x008ACF90, field:this:0x000044FC, field:this:0x0000440C, field:this:0x00004428, field:this:0x00004468]
    // CALL: Primary spatial query: SpatialTreeNearestNeighborSearch(dword_5EA2C0, lane car +0x34E0, ..., this+0x4550, 0) to find the nearest opponent car for the current lane. [callee:0x00403AA0, global:0x005EA2C0, field:this:0x00004468, field:this:0x000034E0, field:this:0x00004440]
    // ASSIGNMENT: Store the nearest-neighbour result index into the lane entry slot (this+0x41AC). [field:this:0x000041AC]
    // GUARD: If the candidate car is not on track (lane-car status 0x32C8) while the own car is, or the candidate car is the own car, fall back to BVHNearestNeighborQuery; otherwise skip scoring. [field:*(this+0x4174):0x000032C8, field:*(this+0x4174):0x00004354, callee:0x004039C0, field:this:0x000041AC]
    // CALL: ShortComputation_3ca0 computes the lateral offset between this car and the opponent using RenderZ/forward/lateral components (this+0x34F8 / 0x34FC / 0x3500) and speed (this+0x4440). [callee:0x00423CA0, field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, field:this:0x00004440]
    // CALL: ShortComputation_3db0 computes forward distance and angle to the opponent using lane offsets (this+0x34E0 / 0x34E4 / 0x34E8) and stored lane-track values (this+0x448C / 0x4490 / 0x4494). [callee:0x00423DB0, field:this:0x0000448C, field:this:0x00004490, field:this:0x00004494, field:this:0x000034E0, field:this:0x000034E4, field:this:0x000034E8]
    // CALL: VehicleDynamics is run for the opponent (from the lane slot this+0x41AC) and for the current car (indexed via this+0x4468) to derive closing dynamics. [callee:0x00423B10, field:this:0x000041AC, field:this:0x00004468]
    // CALCULATION: Compute closing-rate/time-to-gap (from lane front distance this+0x4180 and gap this+0x41A4), look up the matching slot in the 20-entry table at this+17096 via lane slot index (this+0x41B4), defaulting the stored index to -1 when no slot matches. [field:this:0x000041B4, field:this:0x000041A4, field:this:0x00004440, field:this:0x00004468, field:this:0x00004180]
    // GUARD: If the lane car lacks a valid track flag (status 0x32C8 clear) or the car is nearly stationary, force the score sentinel (-10000) and reset the cached target slot. [field:*(this+0x4174):0x000032C8, field:this:0x000041A4]
    // CALCULATION: Insert the lane score into the sorted 5-best list, shifting the per-lane index assignments (scores and lane front distances from this+0x4180). [field:this:0x00004180]
    // LOOP: Evaluate each of the 5 best candidates: skip out-of-range lane distance (this+0x41A8), test yaw alignment (own track-data +0xB8 vs candidate), lateral offset (this+0x4450 with flt_5EA3FC width), speed-scaled penalty using this+0x4440 / this+0x4438 / this+0x44A4, and overtake aggression factors this+0x4414 / this+0x4418 / this+0x44F8. [field:this:0x00004450, global:0x005EA3FC, field:this:0x000044F8, field:this:0x00004440, field:this:0x000041A8, field:this:0x00004174, field:*(this+0x4354):0x000000B8, field:this:0x00004438, field:this:0x000044A4, field:this:0x00004414, field:this:0x00004418]
    // CALCULATION: Compare the own car's session/team identity (dereferenced via this+0x0) against the opponent car's identity and apply a -95 steering bias when the opponent is ahead. [field:this:0x00000000, field:this:0x00004174]
    // CALL: TrackParameterMinimumClamp enforces speed-target floors derived from speed (this+0x4440) and candidate lateral state. [callee:0x0042A740, field:this:0x00004440]
    // CALL: SignedIndexTableLookup selects the steering/lane index from the computed target (this+0x4428) and lane aggression (this+0x44F8). [callee:0x004FAE70, field:this:0x00004428, field:this:0x000044F8]
    // ASSIGNMENT: Update the per-lane overtake timer slot (this+17116 region) using lane lateral speed (this+0x41A4 context) and speed thresholds (this+0x4438 / this+0x4480), clamped to the timer ceiling. [field:this:0x00004174, field:this:0x000044F8, field:this:0x00004438, field:this:0x00004480]
    // STATE_TRANSITION: When a candidate triggers overtaking, increment the overtake counter (this+0x455C and this+0x4508), set the steering-latch byte (this+0x4579), and record the side index (this+0x4570 / this+0x4574) from the candidate car's stored counter values; reads overtaking-allowance fields (obj +0x48A4 / +0x48A8) and the callToBox guard (this+0x4544). [field:obj:0x000048A4, field:obj:0x000048A8, field:this:0x00004508, field:this:0x00004570, field:this:0x00004574, field:this:0x0000455C, field:this:0x00004544, field:this:0x000041A4]
    // CALCULATION: Steering-state reset when the lane entry is empty or speed (this+0x4440) exceeds the threshold (this+0x4480): re-seed the target slot (this+0x4488 byte and timer) before recomputing the candidate path. [field:this:0x00004480, field:this:0x00004488, field:this:0x00004440]
    // CALL: For overtaking modes (v86 == 1/2/7/8), call Overtaking(this, v86), increment this+0x4508, and refine the lateral target using this+0x4428 / this+0x4414 / this+0x4418. [callee:0x0042AF70, field:this:0x00004508, field:this:0x00004428, field:this:0x00004414, field:this:0x00004418, field:this:0x00004579]
    // ASSIGNMENT: Commit the final steering output: write this+0x4408 from this+0x440C, apply overrides from this+0x4420 and this+0x4424, honour the pit-steering byte (this+0x4548), set the boundary flag byte (this+0x4140) when the target exceeds the lateral bounds (this+0x4414 / this+0x4418 / this+0x4440), and clear the flag byte (this+0x4488). [field:this:0x00004408, field:this:0x0000440C, field:this:0x00004420, field:this:0x00004424, field:this:0x00004548, field:this:0x00004140, field:this:0x00004488, field:this:0x00004414, field:this:0x00004418, field:this:0x00004440]

    // Conservative worker pseudocode:
    //   scan 5 lane entries -> leftBound (min +0x50), rightBound (max +0x54)
    //   steeringTarget = clamp(centre, leftBound, rightBound); snap ±0.2 if latch set
    //   if sessionTime < raceTimeOffset + 6.5 or + 2.5: steeringTarget = opponent-derived value
    //   for each lane: nearest = SpatialTreeQuery(...); if on-track mismatch: nearest = BVHQuery(...)
    //   compute closing dynamics via ShortComputation_3ca0/3db0 + VehicleDynamics
    //   insert lane score into sorted 5-best; score each candidate for overtaking
    //   for best candidates: mode = f(lateral, yaw, speed, overtake counters); commit this+0x4408
    //   if target outside [leftBound, rightBound]: set boundary flag byte 0x4140
    // UNRESOLVED: The 61 flt/dbl_59E* float constants are read by the function but their exact roles are not visible in the decompiled body; treated as tuning constants.
    // UNRESOLVED: Field pairs obj+0x48A4 / obj+0x48A8 (overtaking-allowance counters) are read but the exact candidate they belong to is not confirmed in the pseudocode.
    // UNRESOLVED: The lane-table entries and their 68-byte layout are inferred from pointer arithmetic, not a named struct.
}
