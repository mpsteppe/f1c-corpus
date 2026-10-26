// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004649F0
// Canonical corpus name: BitFlagSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitFlagSetter_004649f0.c

void UnknownObject::BitFlagSetter()
{
    // Sets or clears bit 7 (0x80) of the byte pointed to by this, depending on argument a2: nonzero a2 stores 0x80, zero a2 ANDs out the 0x80 bit. Returns a2 unchanged. No callees.
    // ASSIGNMENT: Save the incoming a2 as the value to return. [source:raw]
    // GUARD: Branch on a2: if nonzero, set bit 7; if zero, clear bit 7. [source:raw]
    // ASSIGNMENT: When a2 is nonzero, store 0x80 into the byte at this (offset 0x0), setting bit 7. [source:raw, field:this:0x00000000]
    // ASSIGNMENT: When a2 is zero, clear bit 7 of the byte at this (offset 0x0) via AND with the bitwise complement of 0x80. [source:raw, field:this:0x00000000]
    // RETURN: Return the original a2. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4649F0(_BYTE *this, char a2) {
    //     char result = a2;
    //     if (a2)
    //       *this = 0x80;
    //     else
    //       *this &= ~0x80;
    //     return result;
    //   }
    // UNRESOLVED: Purpose of the bit-7 flag at this+0x0 is unknown; callers DispatchWrapper and FloatComputation do not reveal it here.
}
