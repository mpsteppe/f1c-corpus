// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8F10
// Canonical corpus name: ParticleEmitterInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleEmitterInit_004c8f10.c

void UnknownObject::ParticleEmitterInit()
{
    // Initializes a particle-emitter object at `this`: stores the vtable/interface pointer off_5ACE2C at +0x0, clears state floats at +0x4 and +0x8..+0x10, and sets the emitter duration at +0x14 to the caller-supplied a2, defaulting to 1.0 when a2 <= 0.0. Computes a randomized end boundary as v2 = flt_8AAE74[(byte)dword_8AAE70++] * 1.5 and stores duration + v2 at +0x18. Returns `this`. Called from MemoryAllocation_9a50 (0x004C9A50).
    // ASSIGNMENT: Store pointer to off_5ACE2C (vtable/interface pointer) at this+0x0. [field:this:0x00000000, global:0x005ACE2C, source:raw]
    // ASSIGNMENT: Clear float field at this+0x4 to 0.0. [field:this:0x00000004, source:raw]
    // GUARD: Guard on a2 <= 0.0: when true, the duration field this+0x14 is set to 1.0. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Otherwise (a2 > 0.0) set the duration field this+0x14 to a2. [field:this:0x00000014, source:raw]
    // CALCULATION: Advance the byte counter dword_8AAE70 (post-increment), index the table flt_8AAE74 with its low byte, and compute v2 = entry * 1.5. [global:0x008AAE70, global:0x008AAE74, source:raw]
    // ASSIGNMENT: Store the end boundary v2 + duration at this+0x18. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Clear float field at this+0x8 to 0.0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Clear float field at this+0xC to 0.0. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clear float field at this+0x10 to 0.0. [field:this:0x00000010, source:raw]
    // RETURN: Return the emitter pointer `this`. [source:raw]

    // Conservative worker pseudocode:
    //   float* ParticleEmitterInit(this, a2) {
    //     *(dword*)this = &off_5ACE2C;
    //     this[1] = 0.0;
    //     this[5] = (a2 <= 0.0) ? 1.0 : a2;
    //     v2 = flt_8AAE74[(byte)dword_8AAE70++] * 1.5;
    //     this[6] = v2 + this[5];
    //     this[2] = 0.0; this[3] = 0.0; this[4] = 0.0;
    //     return this;
    //   }
    // UNRESOLVED: flt_59E440 (0x0059E440) and flt_59E8A4 (0x0059E8A4) are listed as read globals by packet facts but do not appear in the raw decompiled source; their influence here is unknown.
    // UNRESOLVED: off_5ACE2C is treated as a vtable/interface pointer, but no virtual dispatch is visible inside this function.
    // UNRESOLVED: Semantics of the randomized value (flt_8AAE74 table entry * 1.5) and how the +0x18 end boundary is consumed downstream are unknown.
}
