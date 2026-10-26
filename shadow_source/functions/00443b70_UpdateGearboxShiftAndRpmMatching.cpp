// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00443B70
// Canonical corpus name: Gearbox
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Gearbox_00443b70.c

void UnknownObject::UpdateGearboxShiftAndRpmMatching()
{
    // Per-frame gearbox/gearbox-control update invoked from VehicleMainPhysicsUpdate. Computes a rev-match wheel-speed target from drivetrain-mode wheel averages, selects the current gear ratio (internal per-gear table or external dword_5C7530), and produces a throttle-blend coefficient (this+0x8, clamped to [0,1]) used to smooth engine RPM across gear changes for auto and manual/override shift modes. Also handles rev-limit ratio clamping, speed-limiter engagement/decay with HUD and position/lap side-effects, RPM vibration disturbance scaling, and a final random-perturbation of the throttle output.
    // ASSIGNMENT: Load gearbox shift-state word from this+0x1EF8 into v4 and zero the shift-progress components this+0x18 and this+0x1C. [field:this:0x00001EF8, field:this:0x00000018, field:this:0x0000001C, function:0x00443B70]
    // GUARD: If this+0x1EF8 (shift state) is zero, skip the whole gear-change rev-match / throttle-blend block and jump to LABEL_21. [field:this:0x00001EF8, guard:0]
    // CALCULATION: Compute rev-match wheel-speed target v8 from drivetrain mode at this+0x1E14: mode 0 averages this+0x1074 and this+0xC10 times -0.5; mode 1 averages this+0x1074, this+0xC10, this+0x7AC and this+0x348 times -0.25; mode 2 averages this+0x7AC and this+0x348 times -0.5. [field:this:0x00001E14, field:this:0x00001074, field:this:0x00000C10, field:this:0x000007AC, field:this:0x00000348, source:raw]
    // CALCULATION: Select gear ratio by current gear (this+0x1EF4; -1 treated as 0). When the clamped gear index > 7 use external ratio table dword_5C7530 + 8*gear, otherwise use internal table this + 8*gear + 7856. v37 = v8 * ratio. [field:this:0x00001EF4, source:raw]
    // STATE_TRANSITION: Decrement this+0x1E7C by this+0x68 (time-step) and store the result. If the floating-subtract condition-code flags (C0/C3) indicate the boundary condition, record the current gear v9 into this+0x1EF0. [field:this:0x00001E7C, field:this:0x00000068, field:this:0x00001EF0, source:raw]
    // GUARD: If this+0x1C5C equals the computed rev-match target v40, skip all throttle-blend writes and take the clear-shift-state (LABEL_14/15) path. [field:this:0x00001C5C, source:raw]
    // CALCULATION: Automatic-gearbox blend (byte flag at this+0x1E78 set): on downshift (shift state <= 0 and this+0x1C5C < target) write 0 into this+0x8 and 1072693248 into this+0xC (sets the throttle double at this+0x8 to 1.0); upshift is mirrored with this+0xC = 0. When this+0x1E7C < 0, set this+0x18 = 1 - this+0x1E7C/this+0x1E9C (downshift) or /this+0x1E8C (upshift). [field:this:0x00001E78, field:this:0x00001C5C, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000018, field:this:0x00001E7C, field:this:0x00001E9C, field:this:0x00001E8C, source:raw]
    // STATE_TRANSITION: If this+0x1E38 equals the rev-match target, clear the shift state this+0x1EF8 to 0 (blend settled). [field:this:0x00001E38, field:this:0x00001EF8, source:raw]
    // CALCULATION: Manual/override blend (argument a3 set): shift direction comes from argument a2 (2/3 = down, 1/3 = up) or mode bits at this+0x80; downshift sets the throttle double to 1.0 (this+0x8 = 0, this+0xC = 1072693248), upshift sets it to 0. Blend factor v19 = 1 - this+0x1E7C/this+0x1E9C (or /this+0x1E8C); if v19 exceeds this+0x20, store v19 into this+0x20. [field:this:0x00000080, field:this:0x00000008, field:this:0x0000000C, field:this:0x00001E9C, field:this:0x00001E8C, field:this:0x00001E7C, field:this:0x00000020, source:raw]
    // STATE_TRANSITION: End of blend: when the target is reached, clear the shift state this+0x1EF8 = 0 (LABEL_14) or, on the equal-target path, record the current gear into this+0x1EF0 (LABEL_15). [field:this:0x00001EF8, field:this:0x00001EF0, source:raw]
    // GUARD: Telemetry-update guard: if this+0x1EF8 < 0 (mid-shift) and gear >= 1 and this+0x10 > 0 and this+0x19C > 0 and this+0x1CDC*0.5 < this+0x1C5C, call PositionUpdateWithTelemetryRecording with (this+0x1F00) + 12. [field:this:0x00001EF8, field:this:0x00000010, field:this:0x0000019C, field:this:0x00001CDC, field:this:0x00001C5C, field:this:0x00001F00, callee:0x004EF4F0]
    // CALCULATION: Rev-limit ratio clamp: v15 = (double)(this+0x1C5C > this+0x1CE4); when true, v16 = (this+0x1CEC - this+0x1C5C)/(this+0x1CEC - this+0x1CE4); if v16 < this+0x8 clamp to >= 0 and store into this+0x8. [field:this:0x00001C5C, field:this:0x00001CE4, field:this:0x00001CEC, field:this:0x00000008]
    // CALCULATION: Gearbox speed-average rev-match (byte flag this+0x1C58 set and gear this+0x1EF0 nonzero): v23 = mode-dependent average of this+0x11C4, this+0xD60, this+0x8FC, this+0x498; v38 = this+0x1C5C / ratio (this + 8*gear + 7856 or dword_5C7530 + 8*gear); v27 = 2*(flt_8ACFB4 - fabs(v38*v23)); if v27 < this+0x8 clamp to >= 0 and store into this+0x8. [field:this:0x00001C58, field:this:0x00001EF0, field:this:0x000011C4, field:this:0x00000D60, field:this:0x000008FC, field:this:0x00000498, field:this:0x00001C5C, global:0x008ACFB4, field:this:0x00000008, source:raw]
    // CALCULATION: Throttle rate limiter: v28 = (previous this+0x8 - current this+0x8) * 0.166; if v28 > this+0x170, store v28 into this+0x170. [field:this:0x00000008, field:this:0x00000170]
    // GUARD: Low-speed (speed-limiter) branch: if this+0x1C5C < this+0x1C8C compute v29 (either this+0x1C7C directly, or (this+0x1C8C - this+0x1C5C)*this+0x1C7C/(this+0x1C8C - this+0x1C84)); if v29 > this+0x8, store v29 into this+0x8. [field:this:0x00001C5C, field:this:0x00001C8C, field:this:0x00001C7C, field:this:0x00001C84, field:this:0x00000008]
    // CALL: Speed-limiter / position side-effects: if this+0x1C84*0.0078125 >= this+0x1C5C and this+0x1D10 <= 0 and dword_7C56A8 != 2 and byte_7CE254 == v5 and dword_7CC6E0 == v5 and dword_7CC6E4 == 89 and VehicleActive(this), call PositionLapStateUpdate(v5, 4) and SuspensionVibration(v5). [field:this:0x00001C84, field:this:0x00001C5C, field:this:0x00001D10, global:0x007C56A8, global:0x007CE254, global:0x007CC6E0, global:0x007CC6E4, callee:0x00447160, callee:0x00447E00, callee:0x004471F0]
    // STATE_TRANSITION: Speed-limiter timer decay: if this+0x1D10 > 0 subtract this+0x68 into it; crossing this+0x1D28 (while this+0x1C5C < this+0x1C84) calls HUDElementConfig(39, 2, 1.0, 1.0); when this+0x1D10 <= 0 and this+0x1C5C < this+0x1C84, copy this+0x1C84 into this+0x1C5C and this+0x1C88 into this+0x1C60. [field:this:0x00001D10, field:this:0x00000068, field:this:0x00001D28, field:this:0x00001C5C, field:this:0x00001C84, field:this:0x00001C88, field:this:0x00001C60, callee:0x004F87C0]
    // CALCULATION: RPM vibration disturbance: if this+0x1DAC > 0 compute v33 = 11.5 / this+0x1CDC * dbl_8AFEA0 * this+0x1C5C; call InterruptDispatch(v33); interpolate flt_8AAE74 at CRTFtol(fabs(v33)) into v36; scale this+0x8 by (1.0 - v36*this+0x1DAC*v36). [field:this:0x00001DAC, field:this:0x00001CDC, global:0x008AFEA0, field:this:0x00001C5C, callee:0x0058957A, global:0x008AAE74, callee:0x00587BDC, field:this:0x00000008]
    // ASSIGNMENT: Final throttle output: this+0x8 = RandomPhysicsParameterGenerator(this) * this+0x8. [field:this:0x00000008, callee:0x00447B10]

    // Conservative worker pseudocode:
    //   state = this[0x1EF8]; this[0x18] = 0; this[0x1C] = 0;
    //   if (state == 0) goto shift_progress;
    //   target = rev_match_target_by_mode(this, this[0x1E14]);
    //   ratio = (gear_index > 7) ? dword_5C7530[gear_index] : this[gear_index + 7856/8];
    //   target *= ratio;
    //   decay = this[0x1E7C] -= this[0x68];
    //   if (borrow_flags) this[0x1EF0] = gear;
    //   if (this[0x1C5C] != target) {
    //     if (this[0x1E78]) blend_auto(this, target, decay);
    //     else if (a3) blend_manual(this, a2, target, decay);
    //     if (this[0x1E38] == target) this[0x1EF8] = 0;
    //   } else {
    //     this[0x1EF0] = gear; this[0x1EF8] = 0;
    //   }
    //   if (telemetry_guard) PositionUpdateWithTelemetryRecording(this[0x1F00] + 12);
    //   shift_progress: clamp_rev_ratio(this); blend_rev_match(this); limit_throttle_rate(this);
    //   speed_limiter(this); vibration_disturbance(this);
    //   this[0x8] = RandomPhysicsParameterGenerator(this) * this[0x8];
    // UNRESOLVED: dword_5C7530: external gear-ratio lookup table used when gear index > 7; present in the raw source but absent from the packet globals, so no global evidence ref is available for it.
    // UNRESOLVED: this+7856 (offset 0x1EB0): internal per-gear ratio table base; not a listed packet field, so only source:raw evidence exists.
    // UNRESOLVED: Semantics of arguments a2 (shift-request direction values 1/2/3) and a3 (manual-override enable) are inferred from usage, not confirmed.
    // UNRESOLVED: The v13/v14 condition-code flags (C0/C3) that decide whether the current gear is written into this+0x1EF0 are not decoded in the decompilation; the precise arithmetic condition is unclear.
    // UNRESOLVED: Ten packet globals (dbl_59E420, dbl_59E430, dbl_59E880, dbl_59EB50, dbl_59EC10, dbl_59ED10, dbl_59ED98, dbl_59EDB0, dbl_59EDB8, dbl_59EDC0) are listed in the packet but never referenced in the raw source; their role in this function is unknown.
}
