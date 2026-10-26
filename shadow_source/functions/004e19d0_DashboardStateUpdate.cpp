// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E19D0
// Canonical corpus name: VehicleStateUpdate_19d0
// Owner: VehicleDashboardHUD [DERIVED]
// Raw source: functions/VehicleStateUpdate_19d0_004e19d0.c

void VehicleDashboardHUD::DashboardStateUpdate()
{
    // Per-frame vehicle dashboard/HUD update. Propagates the vehicle transform to four wheel sub-objects and each active dashboard component, updates wheel color/alpha via ColorAlphaUpdateFlagSet, reads component flags and dispatches sound/visual cues (sub_5506A0). Detects player-identity and state changes to conditionally refresh component poses via sub_4E3090, builds a scaled rotation transform for the speedometer when active, dispatches per-entry updates via ConditionalDispatchByFlag, then fires state-change cues for low-grip warning, gear change and byte flags, and updates a gauge value from a bounded delta with Delegation/flt_7CF740 scaling.
    // CALL: Propagate the vehicle world transform to the dashboard object: dispatch position this+0x8/0xC/0x10 and rotation this+0x14/0x18/0x1C through sub_54B4D0. [callee:0x0054B4D0, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // LOOP: Iterate 4 wheel sub-objects (stride 296, base this+0x1C8): for each active pair dispatch its pose through sub_54B4D0 and update color/alpha via ColorAlphaUpdateFlagSet using per-wheel values at this+0x1E0/0x1E4/0x1E8. [callee:0x0054B4D0, callee:0x004E21D0, field:this:0x000001C8, field:this:0x000001E0, field:this:0x000001E4, field:this:0x000001E8]
    // GUARD: Enter the active-component loop only when the component count at this+0x2BD0 is greater than 0. [guard:0, field:this:0x00002BD0]
    // LOOP: For each active component (component pointer array at this+0x2BD4): compute its transformed position and dispatch through sub_54B4D0, read flags via BitFlagReader and manipulate them via FlagFieldBitManipulation, dispatch a cue from this+0xB6C, and emit sub_5506A0 cues for every non-null entry in the dword_8AD3EC..unk_8AD3F8 range. [field:this:0x00002BD4, field:this:0x00000B6C, callee:0x0054B4D0, callee:0x0054C0B0, callee:0x0054C030, callee:0x005506A0, global:0x008AD3EC, global:0x008AD3F8]
    // CALCULATION: Compute condition v16 from session globals: not dword_7CFCEC, dword_5EA518 equal to dword_5EA528, and the dword at dword_5EA528+52 equal to 1. [global:0x007CFCEC, global:0x005EA518, global:0x005EA528]
    // CALCULATION: Compute condition v17: the external object (this+0) identity field at +0x4894 equals the identity at (dword_7C54F0[dword_7C54DC] + 0x4894), and dword_7CF7F4 is greater than 0. [field:obj:0x00004894, field:this:0x00000000, global:0x007C54F0, global:0x007C54DC, global:0x007CF7F4]
    // GUARD: When not v16 and (v17 or dword_8AB6E4 == 2) and VirtualDispatchHelper(&dword_5EA510) returns truthy and the resulting bit flags are set: refresh component poses via sub_4E3090, branching on the mode counter at this+0x964 (0 = all four wheels from this+0x1C8, 1 = all four, else two), and honoring dword_7CFCC8. [callee:0x0040C870, global:0x005EA510, global:0x008AB6E4, field:this:0x00000964, field:this:0x000001C8, callee:0x004E3090, global:0x007CFCC8]
    // CALCULATION: When the speedometer slot this+0x8A0 is active: scale rotation components from this+0x950/0x958/0x95C/0x960 by 2.0943952, build an identity basis in a 12-float buffer, then call sub_567120 with the scaled vector and matrix, and sub_54B450 with the matrix rows. [field:this:0x000008A0, field:this:0x00000950, field:this:0x00000958, field:this:0x0000095C, field:this:0x00000960, callee:0x00567120, callee:0x0054B450]
    // GUARD: Proceed with per-entry dispatch only when the cue slot this+0x898 is active and the byte flag at this+0x96D is set. [field:this:0x00000898, field:this:0x0000096D]
    // CALL: On player identity match, set flags via FlagFieldBitManipulation(1,1,0,0) and, for count this+0x8B4 entries, dispatch each pair from arrays this+0x8B8 / this+0x8C4 with a time value derived from this+0x950 through ConditionalDispatchByFlag; otherwise clear flags with FlagFieldBitManipulation(0,0,0,0). [callee:0x0054C030, callee:0x00551810, field:this:0x000008B4, field:this:0x000008B8, field:this:0x000008C4, field:this:0x00000950]
    // CALCULATION: Low-grip warning detection: if the byte flag at this+0x979 is set, or the average of flt_8AFEE8 and flt_8AFEEC exceeds the value at this+0x94C, use dbl_8AFEA0 as baseline, invoke InterruptDispatch(dbl_8AFEA0), and mark low_grip_state when the baseline is below 0.335. [field:this:0x00000979, field:this:0x0000094C, global:0x008AFEE8, global:0x008AFEEC, global:0x008AFEA0, callee:0x0058957A]
    // ASSIGNMENT: When low-grip state differs from the stored byte at this+0x974, store it and, if cue slot this+0x8A4 is active, dispatch a sub_5506A0 cue with the state. [field:this:0x00000974, field:this:0x000008A4, callee:0x005506A0]
    // ASSIGNMENT: Gear-change cue: when cue slot this+0x8A8 is active and the byte at this+0x975 differs from the stored byte at this+0x976, store the new value and dispatch a sub_5506A0 cue. [field:this:0x000008A8, field:this:0x00000975, field:this:0x00000976, callee:0x005506A0]
    // ASSIGNMENT: Byte-flag cue: when cue slot this+0x8AC is active and the byte at this+0x977 differs from the stored byte at this+0x978, store the new value and dispatch a sub_5506A0 cue. [field:this:0x000008AC, field:this:0x00000977, field:this:0x00000978, callee:0x005506A0]
    // CALL: Gauge update: when cue slot this+0x8B0 is active, call Delegation(&dword_8AB6EC) when dword_8AB6E4 == 2, otherwise take dbl_8AFEA0 as baseline; compute gauge_delta vs this+0x984, clamp it to the positive window this+0x988, derive gauge_value via flt_7CF740 scaling plus 0.5, and when it differs from the stored value at this+0x980 store it and dispatch two sub_5506A0 cues. [field:this:0x000008B0, field:this:0x00000984, field:this:0x00000988, field:this:0x00000980, global:0x008AB6EC, global:0x008AB6E4, global:0x008AFEA0, global:0x007CF740, callee:0x004B9CE0, callee:0x005506A0]

    // Conservative worker pseudocode:
    //   propagate_transform(this+0x8..0x1C);
    //   for each of 4 wheels (base this+0x1C8, stride 296):
    //     if active: propagate_pose(sub_54B4D0); ColorAlphaUpdateFlagSet(wheel, alpha);
    //   if count(this+0x2BD0) > 0:
    //     for each component i in array(this+0x2BD4):
    //       sub_54B4D0(computed pose); BitFlagReader; FlagFieldBitManipulation;
    //       sub_5506A0(component_cue); for p in dword_8AD3EC..unk_8AD3F8: sub_5506A0(this+0xB6C, *p, 0);
    //   if state_changed and VirtualDispatchHelper(&dword_5EA510):
    //     refresh_component_poses(sub_4E3090, mode this+0x964);
    //   if speedometer(this+0x8A0): build scaled transform; sub_567120; sub_54B450;
    //   if cue_slot(this+0x898) and byte(this+0x96D):
    //     if player_matched: FlagFieldBitManipulation(1,1,0,0);
    //       for i < count(this+0x8B4): ConditionalDispatchByFlag(array(this+0x8B8)[i], array(this+0x8C4)[i], time);
    //     else: FlagFieldBitManipulation(0,0,0,0);
    //   if low_grip: InterruptDispatch(dbl_8AFEA0); set state if baseline < 0.335;
    //   emit cues when states at 0x974/0x976/0x978 change;
    //   update gauge from clamped delta via flt_7CF740; emit cues on change;
    // UNRESOLVED: Seven read-only float globals (0x59E43C, 0x59E440, 0x59E450, 0x59E87C, 0x59F110, 0x5AD154, 0x5AD158) do not appear as explicit operands in the decompiled text; they likely hold float constants folded into arithmetic (rotation scale, thresholds). Exact mapping unverified.
    // UNRESOLVED: Semantics and side effects of VirtualDispatchHelper and InterruptDispatch on global session state are not resolved from this packet.
    // UNRESOLVED: Meaning of the bit flags produced by the VirtualDispatchHelper call (v19/v20) is unclear.
    // UNRESOLVED: The external-object identity chain (this+0 -> +0x4894 vs dword_7C54F0 grid slot) is only partially understood.
    // UNRESOLVED: Gauge value semantics (lap segment versus speed readout) are not determinable from this packet alone.
}
