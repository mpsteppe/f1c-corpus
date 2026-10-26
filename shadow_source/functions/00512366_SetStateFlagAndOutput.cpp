// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512366
// Canonical corpus name: StateFlagSetter_2366
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateFlagSetter_2366_00512366.c

void UnknownObject::SetStateFlagAndOutput()
{
    // State-flags setter on an object pointed to by a1. Sets bit 7 of the byte at offset 0x61 and stores the byte parameter a2 as a WORD at offset 0x11E. Toggles bit 7 of the flags byte at offset 0x5C according to the boolean a3. Then derives an output state byte at offset 0x11B from two state bytes: when the state byte at 0x116 equals 2 the output becomes 4; when it equals 0 and the state byte at 0x117 is >= 8 the output becomes 2. Returns the object pointer a1.
    // ASSIGNMENT: Set bit 7 of the flags byte at offset 0x61 (a1 + 97) with an OR mask 0x80. [field:this:0x00000061, source:raw]
    // ASSIGNMENT: Store the unsigned byte parameter a2 as a WORD at offset 0x11E (a1 + 286). [field:this:0x0000011E, source:raw]
    // GUARD: Test whether parameter a3 equals 1 to select between setting and clearing bit 7 of the flags byte at offset 0x5C. [source:raw]
    // ASSIGNMENT: When a3 equals 1, set bit 7 of the flags byte at offset 0x5C (a1 + 92) with an OR mask 0x80. [field:this:0x0000005C, source:raw]
    // ASSIGNMENT: When a3 does not equal 1, clear bit 7 of the flags byte at offset 0x5C (a1 + 92) by ANDing with the complement of 0x80. [field:this:0x0000005C, source:raw]
    // GUARD: Read the state byte at offset 0x116 (a1 + 278) into v4; its value 0 or 2 selects the output state written at offset 0x11B. [field:this:0x00000116, source:raw]
    // STATE_TRANSITION: When the state byte at offset 0x116 equals 2, write the output state 4 to the byte at offset 0x11B (a1 + 283). [field:this:0x0000011B, source:raw]
    // GUARD: Guard that the state byte at offset 0x117 is >= 8, combined with the state byte at 0x116 being 0, selects the output state 2. [guard:0, field:this:0x00000117, source:raw]
    // STATE_TRANSITION: When the state byte at offset 0x116 equals 0 and the state byte at offset 0x117 is >= 8, write the output state 2 to the byte at offset 0x11B. [field:this:0x0000011B, source:raw]
    // RETURN: Return the original object pointer a1 as result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_512366(int self, unsigned char value, int enable) {
    //     ((unsigned char *)self)[97] |= 0x80;
    //     *(unsigned short *)(self + 286) = value;
    //     if (enable == 1)
    //       ((unsigned char *)self)[92] |= 0x80;
    //     else
    //       ((unsigned char *)self)[92] &= ~0x80;
    //     unsigned char state0 = ((unsigned char *)self)[278];
    //     if (state0 == 2)
    //       ((unsigned char *)self)[283] = 4;
    //     if (state0 == 0 && ((unsigned char *)self)[279] >= 8)
    //       ((unsigned char *)self)[283] = 2;
    //     return self;
    //   }
    // UNRESOLVED: Object type and field semantics of offsets 0x5C, 0x61, 0x116, 0x117, 0x11B and 0x11E are unknown; called by sub_50210E (0x0050210E).
}
