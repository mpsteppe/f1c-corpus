// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405E60
// Canonical corpus name: PhysicsCollisionResponseComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsCollisionResponseComputation_00405e60.c

void UnknownObject::ComputeCollisionAudioFeedback()
{
    // Computes the collision-response intensity used for audio feedback. Stores the collision parameter and the position/velocity pair into this, then asks the collision object (held at this+0x54) whether the contact type is valid; when it is, the intensity multiplier from the collision object is scaled by a2 and clamped to [0,1]. When intensity is zero the response is cleaned up via this's own vtable and 1 is returned; otherwise the position delta between the collision point and the collision object's reference position is computed into a7 with its magnitude into a6, and 0 is returned. Called by MilesAudioSamplePlaybackSetup.
    // ASSIGNMENT: Store the collision parameter a3 (as int) into this+0x48. [field:this:0x00000048]
    // ASSIGNMENT: Store the collision position a4 (X/Y/Z) into this[10..12] (offsets 0x28-0x30). [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030]
    // ASSIGNMENT: Store the collision velocity/force vector a5 (X/Y/Z) into this[13..15] (offsets 0x34-0x3C). [field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C]
    // GUARD: Threshold guard: when a2 is below 0.001953125 it is zeroed, so sub-threshold contacts produce no intensity. [source:raw]
    // CALL: Read the collision object's vtable pointer at *(this+0x54) and call vtable entry at offset 0x58; the returned value selects the contact-type branch (valid when it equals 1). [field:*(this+0x54):0x00000000, field:*(*(this+0x54)+0x0):0x00000058]
    // CALCULATION: On a valid contact type, call the collision object's vtable entry at offset 0x30 (intensity multiplier getter) and multiply it by a2, clamping the product to at most 1.0; on an invalid type the intensity is 0.0. [field:*(this+0x54):0x00000000, field:*(*(this+0x54)+0x0):0x00000030]
    // ASSIGNMENT: Store the clamped collision intensity into this[16] (offset 0x40). [field:this:0x00000040]
    // GUARD: When the intensity is exactly 0.0, invoke this's own vtable entry at offset 8 (cleanup/reset) and return 1 (no collision feedback). [field:this:0x00000000, field:obj:0x00000008]
    // GUARD: Collision-type flag check: when bit 3 (value 8) of the flag byte at this+0x18 is set, the magnitude output a6 is forced to 0.0 without computing a delta. [field:this:0x00000018]
    // CALCULATION: Otherwise compute the position delta into a7 as a4 minus the collision object's reference position (offsets 0x58/0x5C/0x60 of the object pointed to by this+0x54), then set a6 to sqrt of the sum of squared delta components. [field:*(this+0x54):0x00000058, field:*(this+0x54):0x0000005C, field:*(this+0x54):0x00000060, field:this:0x00000054]
    // RETURN: Return 1 on the no-collision cleanup path and 0 on the active collision path. [source:raw]
    // CALL: Invoked by MilesAudioSamplePlaybackSetup (00405900) to prepare collision audio feedback parameters. [caller:0x00405900]

    // Conservative worker pseudocode:
    //   // this is a collision audio-feedback response struct
    //   *(this+0x48) = a3;
    //   this[10..12] = a4 (collision position);
    //   this[13..15] = a5 (collision velocity/force);
    //   if (a2 < 0.001953125) a2 = 0.0;
    //   if (collisionObj.vtable[0x58]() == 1)
    //       intensity = clamp01(collisionObj.vtable[0x30]() * a2);
    //   else intensity = 0.0;
    //   this[16] = intensity;
    //   if (intensity == 0.0) { this.vtable[8](this); return 1; }
    //   if (this[6] & 8) *a6 = 0.0;
    //   else { *a7 = a4 - refPos; *a6 = sqrt(dot(*a7, *a7)); }
    //   return 0;
    // UNRESOLVED: Three read-only float globals (flt_59E43C, flt_59E440, flt_59E4D8) are flagged by the packet facts but appear nowhere in the raw decompiled source; they are likely compiler-inlined threshold/clamp constants and cannot be verified from this function alone.
    // UNRESOLVED: The exact semantics of the collision object's vtable entries at offsets 0x30 and 0x58 (intensity multiplier and contact-type check) are inferred from the call shape only.
}
