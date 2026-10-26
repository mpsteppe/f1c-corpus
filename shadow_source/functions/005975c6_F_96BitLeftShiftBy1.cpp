// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005975C6
// Canonical corpus name: F_96BitLeftShiftBy1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_96BitLeftShiftBy1_005975c6.c

void UnknownObject::F_96BitLeftShiftBy1()
{
    // Left-shift a 96-bit value held in three consecutive dwords (this+0x0, this+0x4, this+0x8) by exactly one bit, propagating the carry of each word's bit 31 into the low bit of the next-higher word. Returns the input pointer. The canonical name F_96BitLeftShiftBy1 is carried from the packet. Invoked by sub_597621 (0x00597621), sub_5976E8 (0x005976E8) and sub_597AA0 (0x00597AA0).
    // CALCULATION: Double word 0 in place: this+0x0 *= 2. [field:this:0x00000000, source:raw]
    // CALCULATION: Shift word 1 to this+0x4 = (old word0 bit 31 carried) | (old word1 * 2). [field:this:0x00000004, source:raw]
    // CALCULATION: Shift word 2 to this+0x8 = (old word1 bit 31 carried) | (old word2 * 2). [field:this:0x00000008, source:raw]
    // RETURN: Return the input pointer a1. [source:raw]
    // CALL: Invoked by sub_597621 (0x00597621), sub_5976E8 (0x005976E8) and sub_597AA0 (0x00597AA0). [caller:0x00597621, caller:0x005976E8, caller:0x00597AA0, source:raw]

    // Conservative worker pseudocode:
    //   w0 = a1[0]; w1 = a1[1]; w2 = a1[2];
    //   a1[0] = w0 << 1;
    //   a1[1] = (w0 >> 31) | (w1 << 1);
    //   a1[2] = (w1 >> 31) | (w2 << 1);
    //   return a1;
    // UNRESOLVED: The consumer role of the three callers (arbitrary-precision arithmetic context) is not visible from this packet; the object owning the 96-bit value is unknown.
}
