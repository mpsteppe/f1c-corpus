// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586DE0
// Canonical corpus name: BitmaskGenerationFromBitArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmaskGenerationFromBitArray_00586de0.c

void UnknownObject::BitmaskGenerationFromBitArray()
{
    // Builds an occupancy bitmask from a bitmap range: reads a range index from this+0x44, indexes a 4-byte descriptor entry (start WORD + count WORD) in the table at this+0x1C, then iterates count positions reading bits from the bitmap at this+0x14 and packs them into a bitmask result. Returns 0 when the count is zero.
    // CALCULATION: Read v1 = this[17] (this+0x44) as the range index and v2 = this[7] (this+0x1C) as the descriptor table base; read the start WORD v3 and count WORD v5 from the 4-byte entry at v2 + 4*v1. [field:this:0x00000044, field:this:0x0000001C, source:raw]
    // CALCULATION: Compute v6 = start + count - 1, the highest bit position of the range, and initialize result = 0 and loop counter v7 = 0. [source:raw]
    // GUARD: Guard on the descriptor count (_WORD)v5 being non-zero; when zero return result (0) immediately. [field:this:0x0000001C, source:raw]
    // LOOP: Loop v7 from 0 while v7 < count: test bit (v6 - v7) in the bitmap at this[5] (this+0x14) using byte index ((v6-v7) >> 3) and bit index ((v6-v7) & 7); when set, set result bit v7 (v8 |= 1 << v7). [field:this:0x00000014, source:raw]
    // RETURN: Return the accumulated bitmask v8, or 0 when the count guard failed. [source:raw]
    // CALL: Called by sub_587730 (0x00587730) to build an occupancy bitmask from a bitmap range. [caller:0x00587730, source:raw]

    // Conservative worker pseudocode:
    //   int sub_586DE0(int *this) {
    //     int idx = this[17];
    //     unsigned short *desc = (unsigned short *)this[7] + 2 * idx;
    //     unsigned int start = desc[0];
    //     unsigned int count = desc[1];
    //     int top = start + count - 1;
    //     int mask = 0;
    //     if (count) {
    //       for (unsigned int i = 0; i < count; i++) {
    //         int pos = top - i;
    //         if (((unsigned char)(1 << (pos & 7)) & ((unsigned char *)this[5])[pos >> 3]) != 0)
    //           mask |= 1 << i;
    //       }
    //       return mask;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the descriptor table entries (start/count pairs at 4-byte stride) and the meaning of the resulting bitmask depend on the caller's usage in sub_587730.
    // UNRESOLVED: Relationship of this range-index scheme (field 0x44) to any alternative range fields is unknown.
}
