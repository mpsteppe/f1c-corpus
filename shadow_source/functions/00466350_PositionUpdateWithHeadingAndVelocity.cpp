// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466350
// Canonical corpus name: sub_466350
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_466350_00466350.c

void UnknownObject::PositionUpdateWithHeadingAndVelocity()
{
    // Per-frame position/heading update guarded by a flag at this+0xEC. Reads saved-position components through FloatFieldAccessor/DualFieldRead, computes per-axis deltas, delegates through TwoCallDelegation_2420, then runs flag-based motion branches: a speed/brake reduction path (fields 0xF8/0xFC/0x100, with different clamping under the dword_7D0398 photo/free-camera mode) and a heading-angle branch (adjust + wrap to +/-2π or clamp to +/-π/2). Resolves velocity as sin/cos of the heading times the speed, writes velocity/heading back to fields 0x118/0x11C/0x120, stores the new position at 0x108, and finishes with a virtual call through vtable+44. Called by GameObjectUpdateFrame (004661B0) and StateInitializerWithFlagCheck (00466300).
    // GUARD: Guard on field 59 at this+0xEC: if zero the entire update is skipped and its value is returned immediately. [field:this:0x000000EC, source:raw]
    // CALL: FloatFieldAccessor on the sub-object pointer at field 16 (this+0x40) to begin reading saved state. [callee:0x00498730, field:this:0x00000040, source:raw]
    // CALL: DualFieldRead(&v27, &v26) reads the two saved-position components used for delta computation. [callee:0x00498880, source:raw]
    // CALCULATION: Compute per-axis deltas: v28 = v27 - field 65 (this+0x104) and v22 = v26 - field 66 (this+0x108). [field:this:0x00000104, field:this:0x00000108, source:raw]
    // CALL: TwoCallDelegation_2420 with six local out-parameters (v25, v20, v21, v19, v24, v23) performs an intermediate state transform. [callee:0x00542420, source:raw]
    // ASSIGNMENT: Load the current motion state: v5/v19 from field 72 (this+0x120), v20 from field 70 (this+0x118) and v21 from field 71 (this+0x11C); v20/v21 become the working velocity components. [field:this:0x00000118, field:this:0x0000011C, field:this:0x00000120, source:raw]
    // GUARD: Flag byte at this+0xF5 selects the speed/brake reduction branch versus the heading-angle computation branch. [field:this:0x000000F5, source:raw]
    // GUARD: Within the speed branch, the flag byte at this+0xF4 combined with global dword_7D0398 selects the direct OffsetDispatch path. [field:this:0x000000F4, global:0x007D0398, source:raw]
    // CALL: OffsetDispatch(v17, 0.0, v18) with the deltas scaled by 0.0074999998: v28 becomes the +X component and v22 becomes the -Y component. [callee:0x0054B3F0, source:raw]
    // CALCULATION: Decay the speed field: this[62] (0xF8) is reduced by v22 * 0.025. [field:this:0x000000F8, source:raw]
    // STATE_TRANSITION: When dword_7D0398 (photo/free-camera mode) is set, clamp this[62] to the range bounded below by 0.1 * this[64] (0x100) and above by this[63] + this[63] (0xFC). [global:0x007D0398, field:this:0x000000FC, field:this:0x00000100, field:this:0x000000F8, source:raw]
    // STATE_TRANSITION: Otherwise clamp this[62] to the range bounded by this[64] (0x100) below and this[63] (0xFC) above. [field:this:0x000000FC, field:this:0x00000100, field:this:0x000000F8, source:raw]
    // GUARD: Flag byte at this+0xF4: heading adjust v5 -= v22 * 0.0055, then wrap into +/-2*pi (6.2831855) when dword_7D0398 is set, otherwise clamp into +/-pi/2 (1.5707964). [field:this:0x000000F4, global:0x007D0398, source:raw]
    // CALCULATION: Resolve the velocity from the heading and speed: v20 = sin(v5) * this[62] and v21 = cos(v5) * this[62]. [field:this:0x000000F8, source:raw]
    // CALL: UtilityFunction_1cd0(v25, v20, v21, v19, v24, v23) applies the resolved velocity/heading values. [callee:0x00541CD0, source:raw]
    // ASSIGNMENT: Write results back: field 70 (0x118) gets velocity X, field 71 (0x11C) gets velocity Y, field 72 (0x120) gets the heading, and field 66 (0x108) stores the second saved-position component read this frame. [field:this:0x00000118, field:this:0x0000011C, field:this:0x00000120, field:this:0x00000108, source:raw]
    // RETURN: Virtual call through the vtable pointer at this+0x0 with the slot at offset +44, invoked as (this, 1); the return value propagates to the callers GameObjectUpdateFrame (004661B0) and StateInitializerWithFlagCheck (00466300). [field:this:0x00000000, caller:0x004661B0, caller:0x00466300, source:raw]

    // Conservative worker pseudocode:
    //   int sub_466350(this) {
    //     if (!this[59]) return this[59];
    //     FloatFieldAccessor(this[16]);
    //     DualFieldRead(&x_new, &y_new);
    //     dx = x_new - this[65];   // 0x104
    //     dy = y_new - this[66];   // 0x108
    //     TwoCallDelegation_2420(&a, &b, &c, &d, &e, &f);
    //     heading = this[72]; vx = this[70]; vy = this[71];
    //     if (flag at 0xF5) {
    //       if ((flag at 0xF4) && dword_7D0398) {
    //         OffsetDispatch(dx * 0.0074999998, 0.0, -dy * 0.0074999998);
    //       } else {
    //         this[62] -= dy * 0.025;
    //         if (dword_7D0398) this[62] = clamp(this[62], 0.1 * this[64], this[63] + this[63]);
    //         else              this[62] = clamp(this[62], this[64], this[63]);
    //       }
    //     } else if (flag at 0xF4) {
    //       heading -= dy * 0.0055;
    //       if (dword_7D0398) heading = wrap_2pi(heading);   // 6.2831855
    //       else              heading = clamp_pi_half(heading); // 1.5707964
    //     }
    //     vx = sin(heading) * this[62];
    //     vy = cos(heading) * this[62];
    //     UtilityFunction_1cd0(a, vx, vy, heading, e, f);
    //     this[70] = vx; this[71] = vy; this[72] = heading;
    //     this[66] = y_new;
    //     return vtable[+44](this, 1);
    //   }
    // UNRESOLVED: Eight read-only float globals (flt_59E84C, flt_59E87C, flt_59E888, flt_59F1F0, flt_59F1F4, flt_59F1F8, flt_59F1FC, flt_59F200) are flagged by packet facts but never appear in the raw decompiled source; their role (likely scaling/tuning constants) is unverifiable from this packet.
    // UNRESOLVED: The flag semantics at 0xF4/0xF5 and the exact owning class are not confirmed; the legacy ABI label names a camera yaw/zoom controller while the skeleton fill treats it as a generic position/heading update.
    // UNRESOLVED: The semantics of the two saved-position deltas (position vs. input-axis delta) and the OffsetDispatch 0.0074999998 scale factor are not established.
}
