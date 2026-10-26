// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CB620
// Canonical corpus name: ParticleCollisionSpark
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleCollisionSpark_004cb620.c

void UnknownObject::ParticleCollisionSpark()
{
    // Spawns a spark particle at a collision contact point. Computes the contact magnitude and point from the incoming normal and position vectors, allocates a slot from the circular buffer owned by this, sizes the spark from a 256-entry trig table indexed by a rotating byte counter, computes a collision normal (with a fallback when the feature query fails), writes position, velocity and magnitude into the slot, then publishes the slot through three array/flag-flagging helpers. Runs when the contact magnitude is at least 1.0 and the slot counter at this + 88 is positive. Called by the collision effect dispatch (004ce3e0).
    // CALCULATION: Compute the contact magnitude v39 as the square root of the sum of the three squared components of the direction vector a4. [source:raw]
    // GUARD: Emit a particle only when the magnitude is at least 1.0 and the slot counter at this + 88 (field 0x58) is positive. [guard:0, field:this:0x00000058, source:raw]
    // CALL: Allocate a particle slot from the circular buffer owned by this. [callee:0x004CB540, source:raw]
    // ASSIGNMENT: Initialize the slot position: slot[2] = a2 and slot[3] = a2 + the slot's prior value at slot[7]. [source:raw]
    // CALCULATION: Compute the spark size v13 as (trig-table value indexed by the post-incrementing byte counter times 64.0 plus 190.0) times a5, store it in slot[10], and rescale it by v39 divided by the threshold at this + 72 (field 0x48) when v39 is below that threshold. [global:0x008AAE70, global:0x008AAE74, field:this:0x00000048, source:raw]
    // ASSIGNMENT: Store the caller-supplied integer a7 into the slot's dword 17. [source:raw]
    // CALCULATION: Compute the contact point as a3 plus a4 scaled by the value at this + 76 (field 0x4C) divided by the magnitude v39. [field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Store the contact point vector components into slot[11..13] after the normal computation completes. [source:raw]
    // ASSIGNMENT: Store the velocity vector as a4 scaled by 0.1 into slot[14..16] and the magnitude v39 into slot[26]. [source:raw]
    // CALL: Compute the collision normal from the feature data at dbl_7C9360 and the contact point vector; on failure write a fallback normal into slot[21..23] and adjust the stored slot[12] component. [callee:0x0044C550, global:0x007C9360, source:raw]
    // CALL: Set the texture layer flag on the slot's backing array using the stored slot[11..13] values as parameters. [callee:0x00558C60, source:raw]
    // CALL: Set an array element flag with bounds checking using the values at this + 12 (field 0xC), this + 16 (field 0x10) and this + 20 (field 0x14) as parameters. [callee:0x00558CB0, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALL: Write the sentinel value 0xFFFFFF into the bounds-checked array entry for the slot. [callee:0x00558CF0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4CB620(int this, float a2, float *a3, float *a4, float a5, int a6, int a7) {
    //     float mag = sqrt(a4[0]*a4[0] + a4[1]*a4[1] + a4[2]*a4[2]);
    //     if (mag < 1.0 || *(int *)(this + 88) <= 0) return;
    //     float *slot = CircularBufferSlotAlloc(this);
    //     slot[2] = a2; slot[3] = a2 + slot[7];
    //     float size = (flt_8AAE74[(unsigned char)dword_8AAE70++] * 64.0 + 190.0) * a5;
    //     slot[10] = size;
    //     if (mag < *(float *)(this + 72)) slot[10] = mag / *(float *)(this + 72) * size;
    //     ((int *)slot)[17] = a7;
    //     float k = *(float *)(this + 76) / mag;
    //     float px = a3[0] + a4[0] * k;
    //     float py = a3[1] + a4[1] * k;
    //     float pz = a3[2] + a4[2] * k;
    //     float nrm[3] = { px, py, pz };
    //     if (CollisionNormalFromFeature(dbl_7C9360, nrm, slot + 21)) {
    //       /* normal written into slot[21..23]; slot[12] keeps py * /
    //     } else {
    //       slot[21] = 0.0; slot[22] = 1.0; slot[23] = 0.0;
    //       py = py - 0.25;
    //     }
    //     slot[11] = px; slot[12] = py; slot[13] = pz;
    //     slot[14] = a4[0] * 0.1; slot[15] = a4[1] * 0.1; slot[16] = a4[2] * 0.1;
    //     slot[26] = mag;
    //     TextureLayerFlagSet(slot[0], slot[11], slot[12], slot[13]);
    //     ArrayElementFlagSetWithBoundsCheck(slot[0], *(int *)(this + 12), *(int *)(this + 16), *(int *)(this + 20));
    //     BoundsCheckedArrayWrite(slot[0], 0xFFFFFF);
    //   }
    // UNRESOLVED: Five packet-annotated global reads (flt_59E43C, flt_59E708, flt_59E7F8, flt_59E84C, flt_5ACEA8) appear as evidence but do not surface as named identifiers in the raw source; their roles here are unknown.
    // UNRESOLVED: Meaning of slot[7]'s prior value in the position accumulation is unknown.
    // UNRESOLVED: Constants 64.0, 190.0, 0.25 and 0.1, and the four packed dwords (0, 1070596096, 0x40000000, 1201543096) passed through the stack, are unexplained.
    // UNRESOLVED: The slot[12] fallback value (py - 0.25) and the identity of the fallback normal are not grounded.
    // UNRESOLVED: Owner class for this particle-emitter / collision-effect object is unknown.
}
