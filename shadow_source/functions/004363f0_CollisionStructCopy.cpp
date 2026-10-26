// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004363F0
// Canonical corpus name: CollisionStructCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStructCopy_004363f0.c

void UnknownObject::CollisionStructCopy()
{
    // Copies a small collision-result struct from a source buffer into a destination owned by this. Copies a one-byte type marker, then swaps two six-dword payload blocks (destination dword slots 1-6 receive source byte offsets 28-48, while slots 7-12 receive source byte offsets 4-24), copies two trailing dwords into slots 17-18, and zeroes slots 19-24. The copy is skipped entirely when the source type marker is zero. Called per-frame by sub_43BC20 on the collision response path.
    // ASSIGNMENT: Copy the one-byte type marker from source offset 0 into destination byte offset 0 and test it. [field:this:0x00000000, source:raw]
    // GUARD: Guard on the copied type marker being nonzero; the bulk copy block is skipped when it is zero. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Copy six dwords from source byte offsets 28-48 into destination dword slots 1-6 (byte offsets 4-24). [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Copy six dwords from source byte offsets 4-24 into destination dword slots 7-12 (byte offsets 28-48), swapping the two payload halves relative to the source. [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Copy source byte offsets 52 and 56 into destination dword slots 17-18 (byte offsets 68 and 72). [field:this:0x00000044, field:this:0x00000048, source:raw]
    // ASSIGNMENT: Zero destination dword slots 19-24 (byte offsets 76-96); these trailing fields are not sourced from the input. [field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, source:raw]
    // RETURN: Return the value stored into destination dword slot 18 (read from source offset 56) on the copy path, or the source pointer when the type marker caused the copy to be skipped. [function:0x004363F0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4363F0(int *dst, int src) {
    //     dst[0] = *(char *)src;
    //     if (*(char *)src) {
    //       dst[1]  = *(int *)(src + 28); dst[2]  = *(int *)(src + 32);
    //       dst[3]  = *(int *)(src + 36); dst[4]  = *(int *)(src + 40);
    //       dst[5]  = *(int *)(src + 44); dst[6]  = *(int *)(src + 48);
    //       dst[7]  = *(int *)(src + 4);  dst[8]  = *(int *)(src + 8);
    //       dst[9]  = *(int *)(src + 12); dst[10] = *(int *)(src + 16);
    //       dst[11] = *(int *)(src + 20); dst[12] = *(int *)(src + 24);
    //       dst[17] = *(int *)(src + 52);
    //       dst[18] = *(int *)(src + 56);
    //       dst[19] = 0; dst[20] = 0; dst[21] = 0;
    //       dst[22] = 0; dst[23] = 0; dst[24] = 0;
    //       return dst[18];
    //     }
    //     return src;
    //   }
    // UNRESOLVED: Meaning of the one-byte type marker at offset 0 and the identity of the source/destination struct types are not established.
    // UNRESOLVED: Why the two six-dword payload halves are swapped between source and destination is unexplained.
    // UNRESOLVED: The destination-only zeroed range (byte offsets 76-96) is written but never sourced; its purpose is unknown.
    // UNRESOLVED: The return value differs by path (source pointer when skipped, copied dword otherwise); the contract is caller-visible only.
}
