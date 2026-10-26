// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054E120
// Canonical corpus name: PackedArrayIndexLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PackedArrayIndexLookup_0054e120.c

void UnknownObject::PackedArrayIndexLookup()
{
    // Given a global packed-array index a2, walks the packed array entries (64-byte stride) accumulating each entry's element-size field to find which entry contains a2, then returns a pointer to the sub-element at offset a2 - entryStart within that entry. Returns 0 if the element count at this+0x118 is non-positive or if a2 falls outside every entry's cumulative range.
    // GUARD: If the element count this[70] (this+0x118) is not greater than 0, skip the search loop and return the default result 0. [field:this:0x00000118, source:raw]
    // LOOP: Iterate entries v5 = 0, 1, ... while the requested index a2 is outside the current entry's range, i.e. while a2 < v3 or a2 >= v3 + entrySize; advance the byte cursor i by 64 (entry stride) each step. [source:raw]
    // CALCULATION: Accumulate the entry sizes: v3 += the size field at this[71] + i + 8, extending the cumulative range by the current entry. [field:this:0x0000011C, source:raw]
    // GUARD: If the entry counter v5 reaches the element count v2 without containing a2, abandon the search and return 0. [field:this:0x00000118, source:raw]
    // CALCULATION: Compute the sub-element address: entry base this[71] + (v5 << 6) + 12, then add 48 * (a2 - v3) to index the requested sub-element within the entry. [field:this:0x0000011C, source:raw]
    // RETURN: Return the resolved sub-element pointer; return the default 0 when the count guard or the not-found guard fired. [function:0x0054E120, source:raw]
    // CALL: Invoked on frame paths by GlobalVectorOffsetUpdate (0x0040E1F0), ParticleCollisionSpawn (0x004C9FB0), CameraViewportRenderSetup (0x004FBD70) and eleven other callers to resolve packed-array sub-elements by global index. [caller:0x0040E1F0, caller:0x004C9FB0, caller:0x004FBD70, source:raw]

    // Conservative worker pseudocode:
    //   int *sub_54E120(DWORD *this, int a2) {
    //     int count = this[70];
    //     int v3 = 0;
    //     int v5 = 0;
    //     if (count > 0) {
    //       for (int i = 0; a2 < v3 || a2 >= v3 + *(DWORD *)(this[71] + i + 8); i += 64) {
    //         v3 += *(DWORD *)(this[71] + i + 8);
    //         if (++v5 >= count) return 0;
    //       }
    //       return (int *)(this[71] + (v5 << 6) + 12 + 48 * (a2 - v3));
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The byte meaning of the 64-byte entry layout (size field at +8, payload header at +12, 48-byte sub-element stride) is derived from the decompiled arithmetic and not independently confirmed.
    // UNRESOLVED: Semantic roles of the returned sub-element (vertex, AABB, color, etc.) differ per caller and are not established here.
}
