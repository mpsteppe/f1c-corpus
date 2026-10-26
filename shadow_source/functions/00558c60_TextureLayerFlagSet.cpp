// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00558C60
// Canonical corpus name: TextureLayerFlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureLayerFlagSet_00558c60.c

void UnknownObject::TextureLayerFlagSet()
{
    // Bounds-checked texture-layer entry updater (thiscall). Writes a multi-field payload into the entry at index a2 (stride (a2 << 7) within the this+0x34 array), sets the 0x1000 update/dirty bit on that entry, and clears the 0x10000 dirty-tracking bit on the parent at this+0x20. Returns the entry pointer, or the raw index when out of bounds.
    // GUARD: Bounds guard: only when index a2 < this[11] (element count at this+0x2C) is the entry update performed. [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Seed the default result with the raw index: result = a2 (returned unchanged when the guard fails). [source:raw]
    // CALL: MultiFieldSetter(this[13] + (a2 << 7) + 16, a3, a4, a5) writes the multi-field payload into the texture-layer entry (this[13] is the array pointer at this+0x34; entry stride (a2 << 7) bytes, payload at +0x10). [field:this:0x00000034, callee:0x0053B200, source:raw]
    // ASSIGNMENT: Point result at the entry base: result = this[13] + (a2 << 7). [field:this:0x00000034, source:raw]
    // ASSIGNMENT: Set the 0x1000 update/dirty bit on the entry: *result |= 0x1000. [source:raw]
    // ASSIGNMENT: Clear the parent dirty-tracking bit 0x10000 at this+0x20: this[8] &= ~0x10000. [field:this:0x00000020, source:raw]
    // RETURN: Return the entry pointer (the raw index a2 when out of bounds). [source:raw]
    // CALL: Called by ParticleCollisionSpark (0x004CB620), WheelRenderObjectPerFrameUpdate (0x004CB860), ParticleTrailEmitter (0x004CBC50) and ParticleInstanceUpdate (0x004CC1D0) to flag texture-layer entries dirty per frame. [caller:0x004CB620, caller:0x004CB860, caller:0x004CBC50, caller:0x004CC1D0, source:raw]

    // Conservative worker pseudocode:
    //   int *TextureLayerFlagSet(int *this, int index, int a3, int a4, int a5) {
    //     int *result = (int *)index;
    //     if (index < this[11]) {
    //       MultiFieldSetter((int *)(this[13] + (index << 7) + 16), a3, a4, a5);
    //       result = (int *)(this[13] + (index << 7));
    //       *result |= 0x1000;
    //       this[8] &= ~0x10000;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identity of the texture-layer object (`this`) and the exact meaning of the 0x1000 entry flag and the 0x10000 parent flag (likely render/update dirty tracking).
    // UNRESOLVED: Meaning of the three payload fields a3/a4/a5 copied by MultiFieldSetter (entry element type unknown).
}
