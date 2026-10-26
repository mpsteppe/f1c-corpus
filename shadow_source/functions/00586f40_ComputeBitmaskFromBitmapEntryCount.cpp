// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586F40
// Canonical corpus name: ComputeBitmaskFromBitmapEntryCount
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ComputeBitmaskFromBitmapEntryCount_00586f40.c

void UnknownObject::ComputeBitmaskFromBitmapEntryCount()
{
    // Thiscall helper that ANDs a caller-supplied mask with a bitmask built from a bitmap entry count. Reads the 16-bit count from entry a2 of a 4-byte-strided table anchored at this[2] (offset 0x8), sets that many low bits (v4 = (1<<count)-1), then applies *a3 &= v4 and returns a3. Callers: sub_586800 (0x00586800) and sub_586AA0 (0x00586AA0).
    // CALCULATION: Read the 16-bit entry count: v3 = *(unsigned __int16*)(this[2] + 4*a2 + 2), i.e. the upper word of 4-byte table element a2 of the table at this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Initialize the mask v4 = 0 and the bit counter v5 = 0 before the count check. [source:raw]
    // GUARD: Guard on (_WORD)v3 != 0; when the entry count is zero the mask stays 0. [source:raw]
    // LOOP: do-while loop over v3 iterations: v4 |= 1 << v5++ until v5 >= v3, producing a mask of the lowest v3 bits. [source:raw]
    // ASSIGNMENT: Apply the mask to the caller-supplied value: *a3 &= v4. [source:raw]
    // RETURN: Return a3 (the modified caller pointer), preserving the address rather than the masked value. [function:0x00586F40, source:raw]
    // CALL: Invoked by sub_586800 (0x00586800) and sub_586AA0 (0x00586AA0) to clip a mask against a bitmap's entry count. [caller:0x00586800, caller:0x00586AA0]

    // Conservative worker pseudocode:
    //   _DWORD *ComputeBitmaskFromBitmapEntryCount(_DWORD *this, int a2, _DWORD *a3) {
    //     unsigned int v3 = *(unsigned __int16 *)(this[2] + 4 * a2 + 2);
    //     int v4 = 0;
    //     unsigned int v5 = 0;
    //     if ((_WORD)v3) {
    //       do { v4 |= 1 << v5++; } while (v5 < v3);
    //     }
    //     *a3 &= v4;
    //     return a3;
    //   }
    // UNRESOLVED: Layout of the 4-byte-strided table at this+0x8 (bitmap entries with a 16-bit count in the upper word) is inferred from the access pattern only.
    // UNRESOLVED: Semantic role of the resulting mask depends on the two callers (0x00586800, 0x00586AA0).
}
