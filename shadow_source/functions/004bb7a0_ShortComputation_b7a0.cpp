// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB7A0
// Canonical corpus name: ShortComputation_b7a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_b7a0_004bb7a0.c

void UnknownObject::ShortComputation_b7a0()
{
    // Constructor/initializer for a race-timing-related struct (prelabeled ctor_init). Zeroes an 8-dword block starting at this+0x40, zeroes scalar/pointer fields at this+0x0, this+0x30, this+0x8C, this+0x90, this+0x94, this+0xA4, sets sentinel fields this+0x4, this+0x24, this+0x2C to -1 and this+0x28 to -1082130432 (float -1.0), then runs StructResetReinitializer(this).
    // LOOP: Zero 8 consecutive dwords starting at this+0x40: 4 iterations of 2 dword writes (this[16], this[17], advancing 2 dwords per step). [field:this:0x00000040, field:this:0x00000044, source:raw]
    // ASSIGNMENT: Set this+0x0 to 0. [field:this:0x00000000]
    // ASSIGNMENT: Set this+0x30 to 0. [field:this:0x00000030]
    // ASSIGNMENT: Set this+0x8C, this+0x90, this+0x94 to 0. [field:this:0x0000008C, field:this:0x00000090, field:this:0x00000094]
    // ASSIGNMENT: Set this+0xA4 to 0. [field:this:0x000000A4]
    // ASSIGNMENT: Set sentinel this+0x4 to -1. [field:this:0x00000004]
    // ASSIGNMENT: Set sentinel this+0x24 to -1. [field:this:0x00000024]
    // ASSIGNMENT: Set this+0x28 to -1082130432, which is the raw bit pattern of float -1.0. [field:this:0x00000028]
    // ASSIGNMENT: Set sentinel this+0x2C to -1. [field:this:0x0000002C]
    // CALL: StructResetReinitializer(this) performs the deeper struct reset. [callee:0x004BB950]
    // RETURN: Return this (initialized struct pointer). [function:0x004BB7A0, source:raw]

    // Conservative worker pseudocode:
    //   for k in 0 .. 3: this[16+2k] = 0; this[17+2k] = 0
    //   this[0] = 0; this[12] = 0; this[35] = 0; this[36] = 0; this[37] = 0; this[41] = 0
    //   this[1] = -1; this[9] = -1; this[10] = -1082130432; this[11] = -1
    //   StructResetReinitializer(this)
    //   return this
    // UNRESOLVED: The -1 / float -1.0 sentinels at this+0x4, this+0x24, this+0x28, this+0x2C suggest 'invalid/not-set' markers, but their semantics are not confirmed.
}
