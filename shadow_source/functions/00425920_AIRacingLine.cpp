// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00425920
// Canonical corpus name: AIRacingLine
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/AIRacingLine_00425920.c

void F1CVehicle::AIRacingLine()
{
    // Per-frame AI racing-line and speed-profile update: resolves the nearest waypoint node and a look-ahead chain, computes aerodynamic drag from the lead car's closing distance, builds a speed profile across the waypoint chain using a tire-force energy-decay model, determines overtaking threat via pass scores, and produces throttle/brake targets (with a thermal brake ramp) plus an overtaking-window flag. On loss of the racing line it resets waypoint state and delegates to sub_426430.
    // ASSIGNMENT: v52 = *(float*)(this + 0x4438): snapshot current pace/throttle output into a local used to clamp the grip-derived throttle later. [field:this:0x00004438]
    // CALL: v2 = SpatialTreeNearestNeighborSearch(dword_5EA2C0, vehicle position, CurrentWaypointPtr(0x4354), WaypointSetSelector(0x4550), 0): nearest waypoint node for the whole chain navigation. [callee:0x00403AA0, global:0x005EA2C0, field:this:0x00004354, field:this:0x00004550]
    // GUARD: Resolve the forward waypoint link: while the stored node id (0x454C) is valid but mismatches the primary link's id, fall back to the alternate link of the search node. [field:this:0x0000454C]
    // GUARD: Resolve the look-ahead waypoint v5 through the second link level the same way; v5 drives overtaking and pass scoring below. [field:this:0x0000454C]
    // GUARD: Drag-from-lead-car block: if the drag-active flag (0x443C) is set and the lead reference (0x4400) is valid, compute the closing-distance aero drag term. [field:this:0x0000443C, field:this:0x00004400]
    // CALL: F_3DTransformWithMatrixMultiplication(v53, v55): transform the current position into the lead-car frame. [callee:0x004EFB20]
    // CALCULATION: v48 = distance to the lead car: sqrt((v54 - lead.z)^2 + (v53[0] - lead.x)^2) using the lead-car position at deref(0x4400) offsets 0x0/0x8. [field:*(this+0x4400):0x00000000, field:*(this+0x4400):0x00000008]
    // CALL: AerodynamicForceCalc(Speed(0x4440), v48 * 0.4f, 0.75): compute the aero drag from the closing distance. [callee:0x004E8B80, field:this:0x00004440]
    // ASSIGNMENT: If v48 > 0: clear the drag-active flag (0x443C) and record the gap distance in 0x4524. [field:this:0x0000443C, field:this:0x00004524]
    // GUARD: If the pass-window field (0x4424) is 0.0, re-test the pass window against the lead waypoint's forward link: window size from deref(0x4400)+0x18, linked node through deref(0x4400)+0x114. [field:this:0x00004424, field:*(this+0x4400):0x00000018, field:*(this+0x4400):0x00000114]
    // CALCULATION: Distance v45 to the linked waypoint (link offsets 0x94/0x9C); build a clamped pass threshold from the waypoint size. When inside the window, clear 0x443C and set 0x4424 to half or full waypoint size. [field:*(*(this+0x4400)+0x114):0x00000094, field:*(*(this+0x4400)+0x114):0x0000009C, field:this:0x00004424, field:this:0x0000443C]
    // GUARD: Gap-maintenance block: if the stored gap (0x4524) is non-zero, re-run the pass-window test with a wider 1.2x threshold against the lead waypoint; when the car is inside, clear the overtake flags (0x4468, 0x443C) and update the pass window (0x4424) to half or full waypoint size. [field:this:0x00004524, field:this:0x00004468, field:this:0x0000443C, field:this:0x00004424, field:*(this+0x4400):0x00000018]
    // CALL: F_3DTransformWithMatrixMultiplication(v53, v55): transform the current position into the lead-car frame again for the gap test. [callee:0x004EFB20]
    // GUARD: When the pass-window re-test applies, a wider 1.2x distance threshold against the linked waypoint decides whether the car is still inside the overtaking window; clear the overtake flag 0x4468 and the drag flag 0x443C and set the pass window 0x4424 accordingly. [field:this:0x00004468, field:this:0x0000443C, field:this:0x00004424, field:*(this+0x4400):0x00000018]
    // CALCULATION: v23 = distance from the vehicle to the current waypoint (deref(0x4400) offsets 0x0/0x8); v24 = pass-direction dot product with the forward-link tangent (offsets 0xC/0x14), or a fallback comparison when no link is present. [field:*(this+0x4400):0x00000000, field:*(this+0x4400):0x00000008, field:*(*(this+0x4400)+0x114):0x0000000C, field:*(*(this+0x4400)+0x114):0x00000014]
    // GUARD: If the pass-direction dot product v24 is not positive, or the waypoint gap v23 is not greater than the stored gap (0x4524), branch to the racing-line reset path. [field:this:0x00004524]
    // STATE_TRANSITION: Reset path: zero the waypoint counters 0x34F8/0x34FC/0x3500, the target waypoint 0x43F8, the gap 0x4524, the brake target 0x4434 and the pass window 0x4424; clear the drag flag 0x443C and the byte 0x45F4; set throttle 0x4438 to 1.0f; clear the node id 0x454C and set WaypointSetSelector 0x4550 to 1; set driverStatus (0x4510) to 4 or 5 by dword_7C56A4; call AIClearStateFlags then sub_426430(this) and return. [callee:0x0042AE00, callee:0x00426430, global:0x007C56A4, field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, field:this:0x000043F8, field:this:0x00004524, field:this:0x00004434, field:this:0x00004424, field:this:0x0000443C, field:this:0x000045F4, field:this:0x00004438, field:this:0x0000454C, field:this:0x00004550, field:this:0x00004510]
    // GUARD: Mid-gap branch: if the waypoint gap v23 is greater than 0.5, store it in 0x4524 and call AerodynamicForceCalc(Speed(0x4440), v23*0.3f, 0.7f); then set throttle 0x4438 and brake 0x4434 (brake via BrakeThermalModel when the factor is non-positive, otherwise throttle 1.0f and brake 0) and return. [callee:0x004E8B80, callee:0x004E87E0, field:this:0x00004440, field:this:0x00004524, field:this:0x00004438, field:this:0x00004434]
    // CALCULATION: Else build the speed profile: v49 = Speed(0x4440) * 1.05; v26 = (AIComputePassScore(v2) < v49 || AIComputePassScore(alternate link) < v49): overtaking threat against this car's pace. [callee:0x0042A780, field:this:0x00004440]
    // CALCULATION: Target speed v50: when the look-ahead node's pass-score flag is set use its explicit score, otherwise AIComputePassScore(v5) * pace factor at 0x4554. [callee:0x0042A780, field:this:0x00004554]
    // LOOP: If the look-ahead node v5 differs from CurrentWaypointPtr (0x4354), walk the chain storing Speed(0x4440) into the speed-profile array at 0x43A4 (up to 20 entries). [field:this:0x00004354, field:this:0x000043A4]
    // ASSIGNMENT: Reset the target fields: 0x43F8 = 0 and 0x43FC = 9999.0f (default target speed). [field:this:0x000043F8, field:this:0x000043FC]
    // LOOP: While profile speed v46 < target: advance v5 through the waypoint-graph links keyed on the node id (0x454C); on the lap-start sector override the target to flt_8ACFB4; score the waypoint with AIComputePassScore; run TireForce(v46, node parameters); decay the speed by v46 -= node.speedFactor / v46 * pace(0x44CC) * score * 0.915; store v46 into the profile and stop when it reaches zero. [callee:0x004E9100, callee:0x0042A780, global:0x008ACFB4, field:this:0x0000454C, field:this:0x000044CC]
    // LOOP: Fill the remaining speed-profile tail (0x43A4 onward) by decaying each stored entry by 1.8. [field:this:0x000043A4]
    // ASSIGNMENT: byte_5C3160 = 0; store the chosen target waypoint v5 in 0x43F8 and the final target speed v50 in 0x43FC. [global:0x005C3160, field:this:0x000043F8, field:this:0x000043FC]
    // CALCULATION: Set the overtaking-window byte 0x445C from the track-bounds test: current-waypoint right/left boundary distances (deref(0x4354) offsets 0x50/0x54) must each exceed the lateral deviation window 0x4428. [field:this:0x0000445C, field:this:0x00004428, field:this:0x00004354, field:*(this+0x4354):0x00000050, field:*(this+0x4354):0x00000054]
    // GUARD: If profile speed is exhausted (v46 <= 0): throttle 0x4438 = 0; if overtaking is threatened (v26) brake via BrakeThermalModel, else target brake 0x4434 (1.0 in-window when 0x446C is set, otherwise 0.4/0.5 by Speed 0x4440) and blend toward it in 20% steps from the pace fields 0x44B8/0x44C4, the source selected by byte_5C3160. [callee:0x004E87E0, global:0x005C3160, field:this:0x00004438, field:this:0x00004434, field:this:0x0000445C, field:this:0x0000446C, field:this:0x000044B8, field:this:0x000044C4, field:this:0x00004440]
    // ASSIGNMENT: Else (v46 > 0): throttle 0x4438 = TireGripCoefficient(this + 12) clamped to v52 + 0.2; brake 0x4434 = 0. [callee:0x004E88B0, field:this:0x00004438, field:this:0x00004434]

    // Conservative worker pseudocode:
    //   void AIRacingLine(F1CVehicle* this) {
    //     pace_snapshot = this->throttle_0x4438;
    //     node = SpatialTreeNearestNeighborSearch(spatial_tree, this->position, this->current_waypoint_0x4354, this->selector_0x4550, 0);
    //     look = resolve_forward_link(node, this->node_id_0x454C);
    //     if (this->drag_active_0x443C && this->lead_ref_0x4400) {
    //       F_3DTransformWithMatrixMultiplication();
    //       gap = distance_to_lead_car();
    //       AerodynamicForceCalc(this->speed_0x4440, gap * 0.4f, 0.75f);
    //       if (gap > 0.0f) { this->drag_active_0x443C = 0; this->gap_0x4524 = gap; }
    //       if (this->pass_window_0x4424 == 0.0f) update_pass_window();
    //     }
    //     if (this->gap_0x4524 != 0.0f) {
    //       F_3DTransformWithMatrixMultiplication();
    //       if (within_wider_window()) clear_overtake_state();
    //       if (!pass_direction_ok() || waypoint_gap_small()) { reset_racing_line(); sub_426430(this); return; }
    //       if (waypoint_gap > 0.5f) {
    //         this->gap_0x4524 = waypoint_gap;
    //         AerodynamicForceCalc(this->speed_0x4440, waypoint_gap * 0.3f, 0.7f);
    //         set_throttle_brake();
    //         return;
    //       }
    //       reset_racing_line(); sub_426430(this); return;
    //     }
    //     build_speed_profile();
    //     update_overtake_window_flag();
    //     set_throttle_brake_targets();
    //   }
    // UNRESOLVED: The 17 float tuning constants in the 0x59E43C..0x59E8C8 range are read (fact table) but not visible in the raw body; presumed consumed by inlined callees (AerodynamicForceCalc, TireForce, AIComputePassScore).
    // UNRESOLVED: Waypoint-graph node fields not exposed by the packet (link pointers, node id, pass-score flag, tire-force parameters) are navigated by array index in the raw; their concrete layout stays unresolved.
    // UNRESOLVED: Offset 0x454C is named CallToBox (command_input) in the packet but is used here as the waypoint node-id key for chain link resolution; the dual role is not resolved.
    // UNRESOLVED: The speed-profile array (0x43A4) length constant 20 is not part of the packet field metadata.
}
