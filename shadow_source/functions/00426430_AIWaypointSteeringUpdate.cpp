// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00426430
// Canonical corpus name: sub_426430
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/sub_426430_00426430.c

void F1CVehicle::AIWaypointSteeringUpdate()
{
    // Per-frame AI waypoint-following and steering update: computes vehicle speed magnitude, keeps the current waypoint valid (re-querying the spatial tree when drifted), rebuilds the 20-node look-ahead chain on waypoint crossing, dispatches pit-lane entry commands, runs the tire-force solver for grip, classifies a 0..3 speed zone, and projects steering targets clamped to track boundaries. Returns 1 when the update completed or was skipped early.
    // CALCULATION: Speed(0x4440) = sqrt(0x34F8^2 + 0x34FC^2 + 0x3500^2) - vehicle speed magnitude from the render-space velocity vector. [field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, field:this:0x00004440]
    // GUARD: If CurrentWaypointPtr (0x4354) is null, resolve it with SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, position 0x34E0, WaypointSetSelector 0x4550); return 0 on failure. [callee:0x004038E0, global:0x005EA2C0, field:this:0x00004354, field:this:0x00004550, field:this:0x000034E0]
    // GUARD: If the current waypoint drifted more than 3200 units from position (0x34E0/0x34E8), re-query the nearest waypoint, store it in 0x4354 and set the chain-rebuild byte 0x4488. [callee:0x004038E0, field:this:0x00004354, field:this:0x00004488, field:this:0x000034E0, field:this:0x000034E8]
    // GUARD: Plane test against the waypoint tangent: if dot(v10[5]*(v10[39]-Z) + v10[3]*(v10[37]-X)) < 0 the car passed the waypoint plane - bump the waypoint counter 0x4458 when inside the node radius and set byte 0x4488. [field:*(this+0x4354):0x0000000C, field:*(this+0x4354):0x00000014, field:*(this+0x4354):0x00000094, field:*(this+0x4354):0x0000009C, field:this:0x00004458, field:this:0x00004488]
    // GUARD: If the chain-rebuild byte 0x4488 is set, rebuild the 20-node look-ahead waypoint chain. [field:this:0x00004488]
    // CALL: SpatialTreeNearestNeighborSearch(dword_5EA2C0, position, chain base 0x4358, WaypointSetSelector 0x4550, 1) - reselect the current waypoint and store it in 0x4354. [callee:0x00403AA0, global:0x005EA2C0, field:this:0x00004354, field:this:0x00004358, field:this:0x00004550]
    // LOOP: Fill the waypoint chain at 0x4358 with 19 forward links, each step advancing through the node graph keyed on the vehicle node id 0x454C and the chain-node id at *(this+0x4358)+0x12C. [field:this:0x00004358, field:*(this+0x4358):0x0000012C, field:this:0x0000454C]
    // GUARD: Pit-lane entry dispatch: if the set selector is 0 and the current chain node id equals 1, enqueue AICommandMessageQueueDispatcher(this, 14, WaypointSetSelector) and call sub_4A46F0(this,1,1); if the selector is 1 and the node id is 0, call sub_4A46F0(this,0,0). [field:this:0x00004550, field:*(this+0x4358):0x0000012C, callee:0x00424CD0, callee:0x004A46F0]
    // ASSIGNMENT: Store the current chain node id into WaypointSetSelector 0x4550. [field:this:0x00004550, field:*(this+0x4358):0x0000012C]
    // CALL: TireForceSolver(wp.grip at 0x70, wp+0x78, wp.traction at 0x74, 16.0) - per-waypoint tire-force reference for the speed/steering model. [callee:0x004E8CE0, field:*(this+0x4354):0x00000070, field:*(this+0x4354):0x00000074]
    // CALCULATION: Target pace: v18 = chain track distance (*(this+0x4358)+0x48) * 0x4504 + 0x4500, clamped to 75; if WaypointSetSelector(0x4550)==1, v18 = flt_8ACFB4. Write the clamped speed ratio Speed/v18 into 0x4444 (capped at 1.0). [field:*(this+0x4358):0x00000048, field:this:0x00004500, field:this:0x00004504, field:this:0x00004550, field:this:0x00004444, field:this:0x00004440, global:0x008ACFB4]
    // CALCULATION: 0x4450 = waypoint track distance read from *(this+0x4354)+0x48; then 0x4454 = (int)0x4458 * flt_5EA3FC + 0x4450 - recompute track position from pit exit as a waypoint-counter weighted blend. [field:*(this+0x4354):0x00000048, field:this:0x00004450, field:this:0x00004454, field:this:0x00004458, global:0x005EA3FC]
    // ASSIGNMENT: Speed-zone classification 0..3 into 0x4468 from Speed thresholds 15 / 30 / 65. [field:this:0x00004468, field:this:0x00004440]
    // CALCULATION: Store the waypoint offset: 0x4498 = pos X, 0x44A0 = pos Z, 0x43F4 = distance to waypoint = sqrt((wp.Z-Z)^2 + (wp.X-X)^2). [field:this:0x00004498, field:this:0x000044A0, field:this:0x000043F4, field:this:0x000034E0, field:this:0x000034E8, field:*(this+0x4354):0x00000094, field:*(this+0x4354):0x0000009C]
    // RETURN: Early exit: if no chain rebuild happened and the 0x4140 byte flag is clear, return 1. [field:this:0x00004140, function:0x00426430]
    // GUARD: Slot-liveness gate: the vehicle-slot id at obj+0x32C8 must not equal 1 before the steering update runs. [guard:1, field:obj:0x000032C8]
    // GUARD: Pit-lane waypoint gate: the chain-node pit-entry flag at *(this+0x4358)+0x12C must not equal 1 (the pit-entry command path is dispatched separately). [guard:0]
    // GUARD: Steering runs only if the waypoint-chain slot indexed by the speed zone 0x4468 (array base 0x4358) is non-null. [field:this:0x00004468, field:this:0x00004358]
    // CALCULATION: Lateral deviation 0x4428 = -(wp.up.Y * (wp.Z - Z) + wp.up.X * (wp.X - X)) using the waypoint up-vector at *(this+0x4354)+0x20/0x28 and positions 0x34E0/0x34E8. [field:this:0x00004428, field:this:0x000034E0, field:this:0x000034E8, field:*(this+0x4354):0x00000020, field:*(this+0x4354):0x00000028, field:*(this+0x4354):0x00000094, field:*(this+0x4354):0x0000009C]
    // CALCULATION: Blend the zone steering offset: v31 = (1 - speed ratio 0x4444) * 0.15 + chain[zone].heading offset; compute the steering window edges around the zone heading. [field:this:0x00004444, field:this:0x00004358]
    // GUARD: If carConditions(0x3D6C) != 2 or FuelLevel(0x3984) > 0.001, apply heading-window clamping: compute the heading difference between chain nodes (headings at *(this+0x4354)+0xB8, *(this+0x4358)+0xB8 and *(this+0x4364)+0xB8 via the pointer 0x4364), wrap to [-pi,pi], and set the steering sign fields 0x4528/0x452C. [field:this:0x00003D6C, field:this:0x00003984, field:*(this+0x4354):0x000000B8, field:*(this+0x4358):0x000000B8, field:*(this+0x4364):0x000000B8, field:this:0x00004364, field:this:0x00004528, field:this:0x0000452C]
    // GUARD: Abort steering if the vehicle owner state at deref(this+0)+13000 is not 1. [field:this:0x00000000]
    // CALCULATION: Compute the three steering targets 0x4414, 0x4418 and 0x441C as line/ray intersections of the waypoint up-vector with the heading rays for the zone-steering, lower-window and current-heading angles (sin/cos projections). [field:this:0x00004414, field:this:0x00004418, field:this:0x0000441C, field:this:0x000034F0, field:*(this+0x4354):0x00000020, field:*(this+0x4354):0x00000028, field:*(this+0x4354):0x00000094, field:*(this+0x4354):0x0000009C]
    // GUARD: If carConditions != 2 && FuelLevel > 0.001, clamp the steering targets to the track boundaries: scan the 5-node chain for the min/max boundary distances (0x50/0x54) and clamp 0x4414/0x4418 to the resulting interval. [field:this:0x00003D6C, field:this:0x00003984, field:*(this+0x4358):0x00000050, field:*(this+0x4358):0x00000054, field:*(this+0x4354):0x00000050, field:*(this+0x4354):0x00000054, field:this:0x00004414, field:this:0x00004418]
    // ASSIGNMENT: Clear the per-frame processed byte 0x4140. [field:this:0x00004140]
    // RETURN: return 1 - steering update complete. [function:0x00426430, source:raw]

    // Conservative worker pseudocode:
    //   int AIWaypointSteeringUpdate(F1CVehicle* this) {
    //     this->speed_0x4440 = sqrt(this->vel_0x34F8^2 + this->vel_0x34FC^2 + this->vel_0x3500^2);
    //     if (!this->wp_0x4354) {
    //       this->wp_0x4354 = SpatialNearestNeighborQueryWithPlaneTest(tree, pos, this->selector_0x4550);
    //       if (!this->wp_0x4354) return 0;
    //     }
    //     if (displacement_from_waypoint > 3200) {
    //       this->wp_0x4354 = SpatialNearestNeighborQueryWithPlaneTest(tree, pos, this->selector_0x4550);
    //       if (!this->wp_0x4354) return 0;
    //       this->rebuild_byte_0x4488 = 1;
    //     }
    //     if (passed_waypoint_plane(this->wp_0x4354)) { this->wp_counter_0x4458++; this->rebuild_byte_0x4488 = 1; }
    //     if (this->rebuild_byte_0x4488) {
    //       this->wp_0x4354 = SpatialTreeNearestNeighborSearch(tree, pos, chain_0x4358, this->selector_0x4550, 1);
    //       fill_lookahead_chain(this, 0x4358);
    //       if (this->selector_0x4550 == 0 && chain_node_id == 1) {
    //         AICommandMessageQueueDispatcher(this, 14, this->selector_0x4550);
    //         sub_4A46F0(this, 1, 1);
    //       } else if (this->selector_0x4550 == 1 && chain_node_id == 0) sub_4A46F0(this, 0, 0);
    //       TireForceSolver(wp.grip, wp.surface, wp.traction, 16.0);
    //       classify_speed_zone(this);
    //     }
    //     if (zone_slot_valid(this)) {
    //       compute_lateral_deviation_0x4428(this);
    //       compute_steering_targets_0x4414_0x4418_0x441C(this);
    //       clamp_to_track_boundaries(this);
    //     }
    //     this->processed_byte_0x4140 = 0;
    //     return 1;
    //   }
    // UNRESOLVED: The 13 float globals in the 0x59E43C..0x59E8E0 range and unk_7CE2F0 are read but absent from the raw body; presumed tuning constants consumed by inlined math and TireForceSolver.
    // UNRESOLVED: Exact semantics of sub_4A46F0 and of the AI command-queue message id 14.
    // UNRESOLVED: The two packet guards (*(this+0x4358)+0x12C != 1 and obj+0x32C8 != 1) gate the steering path, but their trigger conditions are extracted facts rather than directly readable statements in the decompiled body.
}
