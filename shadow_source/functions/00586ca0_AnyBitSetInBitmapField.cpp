// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586CA0
// Canonical corpus name: sub_586CA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_586CA0_00586ca0.c

void UnknownObject::AnyBitSetInBitmapField()
{
    // Tests whether any bit is set in a bitmap field selected by index this[15] from a metadata table this[7]. Each metadata entry is 4 bytes: a start bit position and a bit count. Iterates the count bits, testing the corresponding bit in the byte array at this[5], and returns true if any tested bit is set.
    // ASSIGNMENT: Compute metadata entry pointer: v1 = this[7] + 4 * this[15] (table base 0x1C, element index 0x3C). [source:raw, field:this:0x0000001C, field:this:0x0000003C]
    // ASSIGNMENT: Load bit count from the metadata entry: v2 = v1[1]. [source:raw]
    // ASSIGNMENT: Initialize bit index v3 = 0 and result accumulator v6 = 0. [source:raw]
    // GUARD: Guard on (WORD)v2 != 0; a zero bit count returns false immediately. [source:raw]
    // LOOP: do-while loop over v3 from 0 while v3 < v2, testing each bit in range. [source:raw]
    // CALCULATION: Compute bit position base: v4 = *v1 + v2 - 1 (start position plus count minus one). [source:raw]
    // CALCULATION: Bit test: read byte at ((v4 - v3) >> 3) + this[5] (field 0x14, the bitmap byte array) and AND it with 1 << ((v4 - v3) & 7). [source:raw, field:this:0x00000014]
    // ASSIGNMENT: When the tested bit is set, accumulate it: v6 |= 1 << v3. [source:raw]
    // RETURN: Return (v6 != 0), i.e. true when any tested bit was set. [source:raw]

    // Conservative worker pseudocode:
    //   bool AnyBitSetInBitmapField(unsigned int* this) {
    //     unsigned short* entry = (unsigned short*)(this[7] + 4 * this[15]);
    //     unsigned int count = entry[1];
    //     unsigned int acc = 0;
    //     unsigned int i = 0;
    //     if ((unsigned short)count) {
    //       do {
    //         int base = *entry + (unsigned short)count - 1;
    //         if (((unsigned char)(1 << ((base - i) & 7)) & *(unsigned char*)(((base - i) >> 3) + this[5])) != 0)
    //           acc |= 1 << i;
    //         ++i;
    //       } while (i < count);
    //     }
    //     return acc != 0;
    //   }
    // UNRESOLVED: Meaning of the metadata table this[7] and the bitmap byte array this[5] is not established from this packet.
    // UNRESOLVED: Which state the selected bitmap encodes and the significance of the result for callers 0057e860 and 00585270 is unknown.
}
