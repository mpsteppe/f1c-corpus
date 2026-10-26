// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EB430
// Canonical corpus name: ParticleEffectUpdateDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleEffectUpdateDispatch_004eb430.c

void UnknownObject::ParticleEffectUpdateDispatch()
{
    // Per-frame vehicle surface-effect dispatcher invoked from MainGameTickUpdate (0042C690). Resets per-frame accumulators (0xA4/0xA8/0xAC/0xB0/0xB4 and the 0x3B75 byte), then, gated on the mode counter 0x32BC being at most 1 and the external-object flag bit 0 at 0x48BC being set, clears and repopulates the active-effect slot list (0x1070/0x1074), computes the slip-velocity norm, iterates the grid, performs wheel-contact distance computation, sprite rendering, a 3x3 matrix transform with translation, and collision detection. Contact data accumulated in the 8AD400/8AD404/8AD428/8AD42C arrays is normalized, dispatched by contact type through ModeDispatchWithSwitch and UICameraModeDispatchWithVehicleDataRead, scaled back into the effect intensity via ConditionedFloatRead/PerIndexStructFieldSetter, tracked through VehicleTelemetryPositionAccumulator/PositionChangeMonitor, and finally used to set the 0x3FF0 surface flag when the body-to-contact dot product exceeds a threshold.
    // ASSIGNMENT: Per-frame reset invoked from MainGameTickUpdate (0042C690): zero the byte at 0x3B75 and the accumulators at 0xA4, 0xAC, 0xB0 and 0xB4, and reset the scale factor at 0xA8 to 1.0f. [caller:0x0042C690, field:this:0x00003B75, field:this:0x000000A4, field:this:0x000000AC, field:this:0x000000B0, field:this:0x000000B4, field:this:0x000000A8, source:raw]
    // GUARD: Gate: the mode counter at this+0x32BC must be at most 1 AND the flag bit 0 of the external object at this+0x48BC (reached through the this+0x0 object pointer) must be set; otherwise the whole dispatch body is skipped. [guard:0, field:this:0x000032BC, field:obj:0x000048BC, field:this:0x00000000, source:raw]
    // GUARD: If the active-effects flag at this+0x1070 is set, clear it and zero the 17 effect slots at this+0x1074 (28-byte stride each). [field:this:0x00001070, field:this:0x00001074, source:raw]
    // LOOP: Four pending-effect slots at this+0x3B78 (28-byte stride) are drained: reading the byte pair at 0x3B79/0x3B78 and the three dwords at 0x3B88/0x3B8C/0x3B90, staging them into the lower buffer, marking 0x1070 active, and clearing the source slot. [field:this:0x00003B78, field:this:0x00003B79, field:this:0x00003B88, field:this:0x00003B8C, field:this:0x00003B90, field:this:0x00001070, source:raw]
    // ASSIGNMENT: Reset the contact count dword_8ADAF8 to 0 before the new frame's collision pass. [global:0x008ADAF8, source:raw]
    // CALL: ComputeSlipVelocityNorm(this) computes the slip-velocity norm feeding the grid iteration. [callee:0x004E9980, source:raw]
    // CALL: GridCellIterate(grid 0x8AB710, this, position at this+0x34D4, slip norm) iterates the spatial grid around the body. [callee:0x004BE340, global:0x008AB710, field:this:0x000034D4, source:raw]
    // CALL: sub_4E96C0(this) determines whether wheel contact processing should run this frame. [callee:0x004E96C0, source:raw]
    // CALL: VehicleBodyToWheelContactDistanceComputation(this, 0) computes the body-to-wheel contact distance used by the sprite renderer. [callee:0x004E9A40, source:raw]
    // CALL: SpriteGridRender(grid 0x8AB710, sprite object at this+0x6E8, position at this+0x34D4, contact distance) renders the sprite grid for this frame. [callee:0x004BE4E0, global:0x008AB710, field:this:0x000006E8, field:this:0x000034D4, source:raw]
    // CALL: F_3x3MatrixTransformWithTranslation(this) transforms by the body's 3x3 rotation plus translation. [callee:0x004E9BD0, source:raw]
    // CALL: CollisionDetectionSystem runs the collision detection pass over the grid contacts. [callee:0x004EA970, source:raw]
    // LOOP: When the contact count dword_8ADAF8 exceeds 1, iterate the contact array at unk_8AD400 (14-float stride) accumulating the per-component max and sum of the contact force components. [global:0x008ADAF8, global:0x008AD400, source:raw]
    // CALCULATION: Normalize the accumulated contact forces: per-component ratio = max / sum, defaulting to 1.0 for a zero sum, then rescale every stored contact component by its ratio. [global:0x008ADAF8, global:0x008AD400, source:raw]
    // LOOP: First contact pass over unk_8AD42C: for each contact call VehicleContactForceAccumulation(contact, 1), take the absolute value of a force component, negate it, and switch on the contact type dword. [global:0x008AD42C, global:0x008ADAF8, callee:0x004EBC60, source:raw]
    // CALL: For contact types 0 through 6, ModeDispatchWithSwitch dispatches on the mode pointer and contact with the vehicle speed/state at this+0x34AC. [callee:0x0040F4B0, field:this:0x000034AC, source:raw]
    // CALCULATION: Compute the effect intensity v53 from the raw force magnitude: (magnitude - 5.0) * 0.01 for types 0-5, (magnitude - 1000.0) * 0.00025 for types 6 and 9. Clamp the resulting slot index (0..3), then bump it by the flt_8AB274 lookup indexed by the rolling dword_8AAE70 counter when positive, gated on byte_7CF728. [global:0x008AB274, global:0x008AAE70, global:0x007CF728, source:raw]
    // STATE_TRANSITION: For contact type 9, when the referenced object is present and its contact-plane check is zero, set the byte at this+0x3B75 to 1. [field:this:0x00003B75, source:raw]
    // ASSIGNMENT: For the active surface case, derive half-extents from this+0x34EC/0x34F0/0x34F4 scaled by 0.5 plus the contact normal components, write the composite position into the selected effect slot at this+0x1074 (28 * slot index), and set the active flag at this+0x1070. [field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, field:this:0x00001074, field:this:0x00001070, source:raw]
    // GUARD: Effect trigger guard: when v53 exceeds 0.01, clamp it to at most 1.0 and only fire when ConditionedFloatRead(slot) is below the computed intensity. [callee:0x004F8AB0, source:raw]
    // CALCULATION: Compute the body-space contact offset by transforming the contact-to-body difference through the 3x3 rotation matrix at this+0x34B0..0x34D0 using the body position at this+0x34D4/0x34D8/0x34DC, then PerIndexStructFieldSetter applies the scaled intensity to the indexed field with the offset vector. [callee:0x004F8850, field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // LOOP: Second contact pass over unk_8AD404: for each non-9/non-10 contact read a type-dependent damping reference (a double at +384 on the referenced object for types 0-5, a float at this+0x3514 for type 6), then reduce the contact force by ratio v60 = stored_force * (this+0x3514) / (reference + this+0x3514). [global:0x008AD404, global:0x008ADAF8, field:this:0x00003514, source:raw]
    // CALL: VehicleTelemetryPositionAccumulator(contact) accumulates the telemetry position for camera tracking for each contact. [callee:0x004EC080, source:raw]
    // CALL: UICameraModeDispatchWithVehicleDataRead(contact object, contact) feeds the camera mode dispatch for non-9/non-10 contact types, after re-negating the force. [callee:0x0040F550, source:raw]
    // CALL: When the reference-position pointer at this+0x3A9C is null, PositionChangeMonitor(this) re-establishes the tracking position. [callee:0x004E9630, field:this:0x00003A9C, source:raw]
    // CALCULATION: Compute the delta between the reference position (components 0/4/8 of the vector at this+0x3A9C) and the body position at this+0x34D4/0x34D8/0x34DC, then normalize the delta by its inverse length (1/sqrt(x^2+y^2+z^2)) unless it is a zero vector. [field:*(this+0x3A9C):0x00000000, field:*(this+0x3A9C):0x00000004, field:*(this+0x3A9C):0x00000008, field:this:0x000034D4, field:this:0x000034D8, field:this:0x000034DC, source:raw]
    // LOOP: Final contact pass over unk_8AD428: dot the normalized delta with each contact direction; when the contact type is 9 and the dot product is below -0.707, set the byte at this+0x3FF0 to 1. [global:0x008AD428, global:0x008ADAF8, field:this:0x00003FF0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4EB430(this) {
    //     this[0x3B75] = 0;
    //     this[0xAC/4] = 0; this[0xB0/4] = 0;
    //     this[0xA4/4] = 0; this[0xA8/4] = 1.0f; this[0xB4/4] = 0;
    //     if (this[0x32BC/4] > 1) return;
    //     if ((*(byte *)(*(this) + 0x48BC) & 1) == 0) return;
    //     if (this[0x1070]) { this[0x1070] = 0; for (i=0;i<17;i++) ((byte*)&this[0x1074])[i*28] = 0; }
    //     for (k=0;k<4;k++) { slot = &this[0x3B78] + k*28; if (slot[0]) { stage slot pair + 3 dwords; this[0x1070] = 1; slot[0] = 0; } }
    //     dword_8ADAF8 = 0;
    //     slip = ComputeSlipVelocityNorm(this);
    //     GridCellIterate(dword_8AB710, this, &this[0x34D4], slip);
    //     if (sub_4E96C0(this)) { dist = VehicleBodyToWheelContactDistanceComputation(this, 0); SpriteGridRender(dword_8AB710, this[0x6E8], &this[0x34D4], dist); }
    //     F_3x3MatrixTransformWithTranslation(this);
    //     CollisionDetectionSystem(...);
    //     if (dword_8ADAF8 > 1) { sum/max accumulate over unk_8AD400 entries; per-component ratio scale; }
    //     for each contact at unk_8AD42C {
    //       VehicleContactForceAccumulation(c, 1);
    //       switch (type) {
    //         case 0..5: ModeDispatchWithSwitch(mode, c, this[0x34AC/4]); v53 = (mag-5.0)*0.01;
    //         case 6: ModeDispatchWithSwitch(mode, c, this[0x34AC/4]); v53 = (mag-1000.0)*0.00025; idx = clamp((int)(v53*3.0),0,3) + (flt_8AB274[dword_8AAE70++] > 0.0 ? 1 : 0); if (byte_7CF728==0 && ...) { write half-extent effect slot at this[0x1074]+28*slot; this[0x1070]=1; }
    //         case 9: if (obj) { if (obj.plane == 0.0) this[0x3B75] = 1; } v53 = (mag-1000.0)*0.00025; idx clamp; ...
    //         default: continue;
    //       }
    //       if (v53 > 0.01) { if (v53 > 1.0) v53 = 1.0; if (ConditionedFloatRead(idx) < v53) { offset = R(contact-body); PerIndexStructFieldSetter(idx, 2, v53, 1.0, offset); } }
    //     }
    //     for each contact at unk_8AD404 {
    //       ref = (type<=5) ? *(double*)(obj+384) : this[0x3514];
    //       v60 = *force * this[0x3514/4] / (ref + this[0x3514/4]);
    //       *force -= v60;
    //       VehicleTelemetryPositionAccumulator(c);
    //       if (type != 9 && type != 10) { *force = -v60; UICameraModeDispatchWithVehicleDataRead(obj, c); }
    //     }
    //     if (!this[0x3A9C]) PositionChangeMonitor(this);
    //     delta = refPos(this[0x3A9C]) - bodyPos(this[0x34D4..0x34DC]); if (delta != 0) normalize(delta);
    //     for each contact at unk_8AD428 { if (type == 9 && dot(delta, dir) < -0.707) this[0x3FF0] = 1; }
    //   }
    // UNRESOLVED: Three jump-table data globals (jpt_4EB6B1 004EBC20, byte_4EBC30 004EBC30, jpt_4EB96D 004EBC3C) are flagged by packet facts but are address-data only and never appear in the raw source text; their exact branch structure is not visible here.
    // UNRESOLVED: Eleven float globals flagged by packet facts (flt_59E43C, flt_59E440, flt_59E444, flt_59E450, flt_59E478, flt_59E7EC, flt_59E800, flt_59E874, flt_5AD1E0, flt_5AD1E4, flt_5AD1E8) appear nowhere in the raw source text, so their roles cannot be asserted from this packet.
    // UNRESOLVED: The contact type enum (0-6, 9, 10) and the 14-float contact entry layout are raw-offset conventions without a named struct.
    // UNRESOLVED: The reference position is read from the pointer at this+0x3A9C and is dereferenced unconditionally after the null-guarded PositionChangeMonitor call; the ordering implies the monitor guarantees a non-null pointer, which is not provable from this packet.
}
