// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586D70
// Canonical corpus name: TestBitmapBitsInTextureRegion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TestBitmapBitsInTextureRegion_00586d70.c

void UnknownObject::TestBitmapBitsInTextureRegion()
{
    // Reads a range descriptor from a descriptor table: index this[14] at +0x38 selects an entry (start WORD at table + 4*index, count WORD at table + 4*index + 2) whose base pointer is this[7] at +0x1C. When the count WORD is non-zero it walks bits from end = start + count - 1 down to start, testing the bitmap pointed to by this[5] at +0x14 (byte offset (end-k) >> 3, mask 1 << ((end-k) & 7)) and accumulating result |= (1 << k); otherwise it returns 0. The returned value is the occupancy bitmask for the region.
    // ASSIGNMENT: Read the descriptor-table index this[14] at offset 0x38. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Read the descriptor-table base pointer this[7] at offset 0x1C (entries are 4 bytes: start WORD then count WORD). [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Fetch the start WORD at table + 4*index and the count WORD at table + 4*index + 2 for the selected range descriptor. [field:this:0x0000001C, field:this:0x00000038, source:raw]
    // CALCULATION: Compute the end bit index as start + count - 1. [source:raw]
    // GUARD: If the count WORD is zero, skip the loop and return 0 immediately. [source:raw]
    // LOOP: For k from 0 to count-1, test bitmap bit at index (end - k): read byte at ((end - k) >> 3) from the bitmap base this[5] at offset 0x14 and mask with (1 << ((end - k) & 7)); when set, accumulate result |= (1 << k). [field:this:0x00000014, source:raw]
    // RETURN: Return the accumulated result bitmask, or 0 when the count WORD was zero. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_586D70(_DWORD *this) {
    //     int idx = this[14];
    //     unsigned short *table = this[7];
    //     unsigned short start = table[2 * idx];
    //     unsigned short count = table[2 * idx + 1];
    //     int end = start + count - 1;
    //     int result = 0;
    //     if (!count) return 0;
    //     for (unsigned int k = 0; k < count; ++k) {
    //       unsigned int bit = end - k;
    //       if (*(unsigned char *)((bit >> 3) + this[5]) & (1 << (bit & 7)))
    //         result |= (1 << k);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The bit ordering of the result (result bit k corresponds to bitmap bit end-k, i.e. reversed) is inferred from the loop structure and not confirmed by any caller.
    // UNRESOLVED: No callers were listed in the packet, so the meaning of the range descriptor (start/count) and the role of the bitmap region are not grounded.
    // UNRESOLVED: The descriptor-table entries and the bitmap pointer share this-object fields, but no class owner was identified for them.
}
