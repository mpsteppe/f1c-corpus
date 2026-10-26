// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CD6C0
// Canonical corpus name: WheelContactParticle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelContactParticle_004cd6c0.c

void UnknownObject::WheelContactParticleSpawn()
{
    // Spawns a wheel contact particle (tire spray / smoke / dust). Reads remaining capacity at this+0x58 and returns it if not positive; otherwise allocates a particle slot from a circular buffer, seeds slot element 2 from a scoring delegation or dbl_8AFEA0, and writes four quad vertices into the texture buffer. Surface type this+0x4 == 8 selects the wet/smoke variant: sets slot element 3 from lifetime plus this+0x30, computes a per-surface alpha clamped to [0,1] using this+0x40 and a scoring delta, stores it in slot element 25 and writes it back scaled by 63.5 at a3+24. Non-8 surfaces store a maximum-lifetime marker instead. Returns the last PixelWriteToTextureBuffer result.
    // GUARD: Read remaining capacity at this+0x58; if not positive, return it without spawning. [field:this:0x00000058, source:raw]
    // CALL: Allocate a particle slot from the emitter's circular buffer via CircularBufferSlotAlloc. [callee:0x004CB540, source:raw]
    // GUARD: If scoring gate dword_8AB6E4 == 2, delegate the lifetime query through Delegation(&dword_8AB6EC); otherwise take dbl_8AFEA0 as the seed. [global:0x008AB6E4, global:0x008AB6EC, global:0x008AFEA0, callee:0x004B9CE0, source:raw]
    // ASSIGNMENT: Store the seed lifetime into the allocated slot's element 2. [source:raw]
    // GUARD: Branch on surface type this+0x4 == 8 selecting the wet/smoke particle variant. [guard:0, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Type-8 variant: slot element 3 gets the lifetime plus the emitter duration field this+0x30. [field:this:0x00000030, source:raw]
    // CALCULATION: Type-8 variant: scale the byte values at a4+24 and a3+24 by 0.0039370079. [source:raw]
    // GUARD: When scoring gate dword_8AB6E4 == 2, query VehicleDataAccessor(&dword_8AB6EC); if it returns 5 use 0.0, otherwise use FloatDifference(&dword_8AB6EC); when not 2 use dbl_8AFE98. [global:0x008AB6E4, global:0x008AB6EC, global:0x008AFE98, callee:0x004B9E30, callee:0x004B9CF0, source:raw]
    // CALCULATION: Type-8 variant: v9 = scaled surface value - scoring delta * this+0x40, clamped to [0,1]; store v9 in slot element 25. [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Type-8 variant: scale v9 by 63.5 and write the integer result back to a3+24. [source:raw]
    // ASSIGNMENT: Non-8 surfaces: slot element 3 is set to the maximum float 3.4028235e38 (no contact modification). [source:raw]
    // CALCULATION: Build the first two quad vertices: vertex 0 from a3 plus its +12/+16/+20 offset, vertex 1 from a4 plus its +12/+16/+20 offset. [source:raw]
    // CALL: Write vertex 0 into the texture buffer via PixelWriteToTextureBuffer using the value at a3+24. [callee:0x00558E10, source:raw]
    // CALL: Write vertex 1 into the texture buffer via PixelWriteToTextureBuffer using the value at a4+24. [callee:0x00558E10, source:raw]
    // CALCULATION: Build the last two quad vertices: vertex 2 from a4 minus its +12/+16/+20 offset, vertex 3 from a3 minus its +12/+16/+20 offset. [source:raw]
    // CALL: Write vertex 2 into the texture buffer via PixelWriteToTextureBuffer using the value at a4+24. [callee:0x00558E10, source:raw]
    // RETURN: Write vertex 3 into the texture buffer via PixelWriteToTextureBuffer using the value at a3+24 and return its result. [callee:0x00558E10, source:raw]

    // Conservative worker pseudocode:
    //   int WheelContactParticleSpawn(this, seed, cornerA, cornerB) {
    //     if (this->capacity <= 0) return this->capacity;
    //     slot = CircularBufferSlotAlloc(this);
    //     if (ScoringGate == 2) Delegation(&ScoringData); else seed = dbl_8AFEA0;
    //     slot[2] = seed;
    //     if (this->surfaceType == 8) {
    //       slot[3] = seed + this->lifetimeDuration;
    //       slot[24] = cornerB->value * 0.0039370079;
    //       surface = cornerA->value * 0.0039370079;
    //       delta = (ScoringGate == 2)
    //           ? (VehicleDataAccessor(&ScoringData) == 5 ? 0.0 : FloatDifference(&ScoringData))
    //           : dbl_8AFE98;
    //       value = surface - delta * this->scale;
    //       value = clamp(value, 0.0, 1.0);
    //       slot[25] = value;
    //       cornerA->value = (int)(value * 63.5);
    //     } else {
    //       slot[3] = 3.4028235e38;
    //     }
    //     PixelWriteToTextureBuffer(slot[0], 0, cornerA.pos + cornerA.off, cornerA->value);
    //     PixelWriteToTextureBuffer(slot[0], 1, cornerB.pos + cornerB.off, cornerB->value);
    //     PixelWriteToTextureBuffer(slot[0], 2, cornerB.pos - cornerB.off, cornerB->value);
    //     return PixelWriteToTextureBuffer(slot[0], 3, cornerA.pos - cornerA.off, cornerA->value);
    //   }
    // UNRESOLVED: Globals flt_59E43C, flt_59E440, flt_5ACEBC, flt_5ACEC0 are listed as read but do not appear in the raw decompilation; their role here is unclear.
    // UNRESOLVED: Slot element indices (2 lifetime, 3, 24, 25) and the exact particle/vertex layout are DERIVED from the decompilation only.
    // UNRESOLVED: a3/a4 corner data layout (position at +0/+4/+8, offset at +12/+16/+20, value at +24) is inferred; no packet field table defines it.
}
