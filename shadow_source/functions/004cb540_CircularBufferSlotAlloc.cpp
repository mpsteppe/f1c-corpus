// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CB540
// Canonical corpus name: CircularBufferSlotAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CircularBufferSlotAlloc_004cb540.c

void UnknownObject::CircularBufferSlotAlloc()
{
    // Circular particle-buffer slot allocation. Advances a circular write index (this[24], offset 0x60) with wraparound at capacity (this[22], offset 0x58), computes the slot address from the buffer base (this[23], offset 0x5C) using a 108-byte slot stride, and returns it. When the slot's state/link word is negative (slot free), links the slot into the active-slot list, appends its address to the tracking array (this[26], offset 0x68) while incrementing the allocation count (this[25], offset 0x64), and resets the slot via sub_558A30. The index always advances; the caller is responsible for capacity.
    // ASSIGNMENT: Read the circular write index v1 = this[24] and the buffer capacity v2 = this[22]; advance the index (this[24] = v1 + 1) and wrap it to 0 when it reaches capacity [field:this:0x00000060, field:this:0x00000058, source:raw]
    // CALCULATION: v3 = this[23] loads the slot buffer base; v5 = v3 + 108 * v1 addresses the chosen slot (108-byte slot stride) [field:this:0x0000005C, source:raw]
    // GUARD: Read the slot's state/link word v4 = *(v5 + 4); the free-slot bookkeeping runs only while v4 < 0 (slot unclaimed) [field:this:0x0000005C, source:raw]
    // ASSIGNMENT: *(v5 + 4) = this[25] links the now-claimed slot to the allocation-count value [field:this:0x00000064, source:raw]
    // ASSIGNMENT: *(this[26] + 4 * this[25]++) = v5 stores the slot address in the tracking array at this[26] and increments the allocation count this[25] [field:this:0x00000068, field:this:0x00000064, source:raw]
    // CALL: sub_558A30(v1) initializes / ages the claimed slot at index v1 (age reset for a recycled slot) [callee:0x00558A30, source:raw]
    // RETURN: Return v5, the claimed slot pointer; the circular index advances unconditionally and the caller must honor capacity [source:raw]
    // CALL: Invoked by the particle emitters ParticleCollisionSpark, ParticleTrailEmitter, ParticleSpawnFunction, WheelContactParticle and sub_4CC970 [caller:0x004CB620, caller:0x004CBC50, caller:0x004CC970, caller:0x004CCE90, caller:0x004CD6C0, source:raw]

    // Conservative worker pseudocode:
    //   v1 = this[24]; v2 = this[22];
    //   this[24] = v1 + 1;
    //   if (this[24] >= v2) this[24] = 0;
    //   v3 = this[23];
    //   v5 = v3 + 108 * v1;
    //   if (*(v5 + 4) < 0) {
    //     *(v5 + 4) = this[25];
    //     *(this[26] + 4 * this[25]++) = v5;
    //     sub_558A30(v1);
    //   }
    //   return v5;
    // UNRESOLVED: Whether this[25] is a plain counter or a link token is inferred from its use both as the value written into the slot link word and as the tracking-array index
    // UNRESOLVED: sub_558A30's exact slot-initialization work is unverified; treated as slot age reset from call context
}
