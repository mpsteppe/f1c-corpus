// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CBC50
// Canonical corpus name: ParticleTrailEmitter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleTrailEmitter_004cbc50.c

void UnknownObject::SpawnTrailParticle()
{
    // Allocates a circular-buffer particle slot and initializes it from collision data: position (a3), velocity (a4), noise-scaled magnitude, and a collision normal computed from feature data. Optionally adjusts surface offset fields when the a7 flag is set, then marks texture-layer and array-element flags and returns a bounds-checked array write.
    // GUARD: Read dword at this+0x58 (buffer capacity / max slot count); if <= 0 return it without spawning. [field:this:0x00000058, source:raw]
    // CALL: Call CircularBufferSlotAlloc(this) to allocate a particle slot. [callee:0x004CB540, source:raw]
    // ASSIGNMENT: Store slot position and lifetime: slot[2] = a2 and slot[3] = a2 + slot[7]. [source:raw]
    // ASSIGNMENT: Copy the a3 position triple into slot[11], slot[12], slot[13]. [source:raw]
    // ASSIGNMENT: Copy the a4 velocity triple into slot[14], slot[15], slot[16]. [source:raw]
    // CALCULATION: Compute noise = flt_8AAE74[(byte)dword_8AAE70++] * 64.0, store slot[10] = (noise + 190.0) * a5, and store a8 into slot dword[17]. [global:0x008AAE70, global:0x008AAE74, source:raw]
    // CALCULATION: Build the 3-component feature position vector v17 from a3[0..2]. [source:raw]
    // CALL: Call CollisionNormalFromFeature(dbl_7C9360, v17, slot+21); on success use the returned normal, otherwise write the default normal (0,1,0) and fall back to a3[1] - 0.25. [callee:0x0044C550, global:0x007C9360, source:raw]
    // GUARD: If a7 flag is set, surface-offset mode: slot[12] = this+0x10 * 0.5 + fallback and slot[15] = slot[26] * this+0x1C * 0.5. [field:this:0x00000010, field:this:0x0000001C, source:raw]
    // CALL: Call TextureLayerFlagSet(slot, slot[11], slot[12], slot[13]) to set the texture layer flag. [callee:0x00558C60, source:raw]
    // CALL: Call ArrayElementFlagSetWithBoundsCheck(slot, this+0xC, this+0x10, this+0x14) to mark the array element flags for the texture layers. [callee:0x00558CB0, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // RETURN: Return BoundsCheckedArrayWrite(slot, 0xFFFFFF). [callee:0x00558CF0, source:raw]

    // Conservative worker pseudocode:
    //   if (*this+0x58 <= 0) return *this+0x58;
    //   slot = CircularBufferSlotAlloc(this);
    //   slot->pos = a2; slot->lifetime = a2 + slot->prev;
    //   copy a3 -> slot->src[0..2]; copy a4 -> slot->vel[0..2];
    //   slot->magnitude = (flt_8AAE74[dword_8AAE70++] * 64.0 + 190.0) * a5; slot->flags = a8;
    //   if (CollisionNormalFromFeature(&dbl_7C9360, v17, &slot->normal)) { v16 = v22; }
    //   else { slot->normal = {0,1,0}; v16 = a3[1] - 0.25; }
    //   if (a7) { slot->src[1] = *this+0x10 * 0.5 + v16; slot->vel[1] = slot[26] * *this+0x1C * 0.5; }
    //   TextureLayerFlagSet(slot, slot[11], slot[12], slot[13]);
    //   ArrayElementFlagSetWithBoundsCheck(slot, *this+0xC, *this+0x10, *this+0x14);
    //   return BoundsCheckedArrayWrite(slot, 0xFFFFFF);
    // UNRESOLVED: Global literals flt_59E450, flt_59E708, flt_59E7F8, flt_5ACEA8 are listed in the packet's globals table but do not appear in the raw source; their role here is unclear.
    // UNRESOLVED: Callers CollisionEffectDispatch (0x004CE3E0) and ParticleCollisionEffect (0x004CE930) invoke this on the frame path, but the owning class and the slot layout behind the circular buffer are unknown.
    // UNRESOLVED: The exact semantics of the a2/a3/a4/a6 parameter triple and the v22/v17 locals depend on the CollisionNormalFromFeature contract.
}
