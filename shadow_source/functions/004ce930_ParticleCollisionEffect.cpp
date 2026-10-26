// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CE930
// Canonical corpus name: ParticleCollisionEffect
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleCollisionEffect_004ce930.c

void UnknownObject::ParticleCollisionEffect()
{
    // Spawns trail particles from three collision-effect slots (this[8], this[9], this[10], offsets 0x20/0x24/0x28) whenever the collision point has moved enough since the last frame. An emitter-mode argument a6 is derived from the smoke/renderer flags (byte_7CF9BC, byte_7CF9EC), and emission is gated per slot by the collision strength stored in the a2 state, the slot pointer, and the throttle counters (dword_7CF8A8, dword_8AB6E4, dword_7C5698). On significant movement (vertical delta beyond 0.15/0.06, or squared horizontal distance beyond 1.0/0.16) it updates the tracked position, builds a noise-jittered spawn position from flt_8AB274 indexed by the ring counter dword_8AAE70, scales the a5 velocity by 0.1, and calls ParticleTrailEmitter (0x004CBC50). The third slot additionally spawns a secondary offset trail at higher render-throttle detail. Called from tire-slip force calculation (0x004472B0) and 0x004EE2D0.
    // ASSIGNMENT: Derive the emitter-mode argument a6 from the smoke/renderer flags: when byte_7CF9BC is set and byte_7CF9EC is set use 104; when both flags are clear use -1; otherwise keep the incoming a6. [global:0x007CF9BC, global:0x007CF9EC, source:raw]
    // GUARD: Slot-8 emission gate: requires the collision strength at a2+0 to be non-zero, the slot pointer this[8] (offset 0x20) to be set, and the throttle condition dword_7CF8A8 > 2, dword_8AB6E4 == 2, or dword_7C5698 % 20 == 0. [field:this:0x00000020, global:0x007CF8A8, global:0x008AB6E4, global:0x007C5698, source:raw]
    // GUARD: Slot-8 movement test: emit only when the vertical delta from the last tracked collision height exceeds 0.15000001, or the squared horizontal distance from the tracked position exceeds 1.0. [source:raw]
    // ASSIGNMENT: Update the tracked collision state at a2 (position components, collision height a3, and velocity) to the current frame's values. [source:raw]
    // CALCULATION: Build the jittered spawn position for slot 8: offset the collision point by flt_8AB274[ring counter dword_8AAE70++] scaled by 0.25, and scale the a5 velocity components by 0.1. [global:0x008AB274, global:0x008AAE70, source:raw]
    // CALL: Emit the slot-8 trail particle via ParticleTrailEmitter (0x004CBC50) with the slot pointer this[8], the collision height, the jittered position, the scaled velocity and the emitter-mode a6. [callee:0x004CBC50, field:this:0x00000020, source:raw]
    // GUARD: Slot-9 emission gate: same throttle condition with the collision strength at a2+20 and the slot pointer this[9] (offset 0x24). [field:this:0x00000024, global:0x007CF8A8, global:0x008AB6E4, global:0x007C5698, source:raw]
    // GUARD: Slot-9 movement test: vertical delta beyond 0.15000001, or squared horizontal distance beyond 1.0. [source:raw]
    // ASSIGNMENT: Update the slot-9 tracked collision state at a2 (positions around a2+28, height a2+24, velocity a2+36). [source:raw]
    // CALCULATION: Build the jittered spawn position for slot 9 using flt_8AB274[ring counter dword_8AAE70++] and the 0.25/0.1 scalings. [global:0x008AB274, global:0x008AAE70, source:raw]
    // CALL: Emit the slot-9 trail particle via ParticleTrailEmitter (0x004CBC50) with the slot pointer this[9] (offset 0x24). [callee:0x004CBC50, field:this:0x00000024, source:raw]
    // GUARD: Slot-10 emission gate: requires the collision strength at a2+40 and the slot pointer this[10] (offset 0x28), with the slightly weaker throttle condition dword_7CF8A8 > 1, dword_8AB6E4 == 2, or dword_7C5698 % 20 == 0. [field:this:0x00000028, global:0x007CF8A8, global:0x008AB6E4, global:0x007C5698, source:raw]
    // GUARD: Slot-10 movement test: vertical delta beyond 0.059999999, or squared horizontal distance beyond 0.16000001. [source:raw]
    // ASSIGNMENT: Update the slot-10 tracked collision state at a2 (positions around a2+48, height a2+44, velocity a2+56). [source:raw]
    // CALCULATION: Build the jittered spawn position for slot 10 using flt_8AB274[ring counter dword_8AAE70++] with the finer 0.15000001 offset scaling and the 0.1 velocity scaling. [global:0x008AB274, global:0x008AAE70, source:raw]
    // CALL: Emit the slot-10 trail particle via ParticleTrailEmitter (0x004CBC50) with the slot pointer this[10] (offset 0x28). [callee:0x004CBC50, field:this:0x00000028, source:raw]
    // GUARD: When dword_7CF8A8 > 2 (high render-throttle detail), also spawn a secondary offset trail from slot this[10]: offset the spawn position backward by a5 scaled by 0.0125, jitter it again with flt_8AB274[ring counter dword_8AAE70++], and use the collision height a3 minus 0.0125. [global:0x007CF8A8, field:this:0x00000028, global:0x008AB274, global:0x008AAE70, callee:0x004CBC50, source:raw]

    // Conservative worker pseudocode:
    //   void ParticleCollisionEffect(void *this, void *a2, float height, float *pos, float *vel, int mode) {
    //     if (byte_7CF9BC) { if (byte_7CF9EC) mode = 104; }
    //     else if (!byte_7CF9EC) mode = -1;
    //     emitSlot(this[8],  a2, 0,   pos, vel, height, mode, 0.15000001, 1.0,  0.25);
    //     emitSlot(this[9],  a2, 20,  pos, vel, height, mode, 0.15000001, 1.0,  0.25);
    //     emitSlot(this[10], a2, 40,  pos, vel, height, mode, 0.059999999, 0.16000001, 0.15000001);
    //     if (dword_7CF8A8 > 2) {
    //       spawn secondary offset trail from slot this[10] with vel * 0.0125 and height - 0.0125;
    //     }
    //   }
    // UNRESOLVED: The emitter-mode magic values 104 and -1 (a6) are not explained by the packet.
    // UNRESOLVED: The slot thresholds (0.15000001/0.059999999/1.0/0.16000001) and scaling factors (0.25/0.1/0.0125) are inlined literals in the raw source; their binding to the packet's float globals (flt_59E43C, flt_59E440, flt_59E454, flt_59E7F8, flt_59E84C, flt_59E868, flt_5ACECC, flt_5ACED0) is not directly evidenced.
    // UNRESOLVED: The a2 state layout (per-slot tracked position/height/velocity fields) is used via raw pointer arithmetic; no field evidence pins it to a named struct.
    // UNRESOLVED: The exact meaning of the ParticleTrailEmitter throttle argument a6 is not evidenced here.
}
