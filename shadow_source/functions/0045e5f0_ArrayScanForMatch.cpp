// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045E5F0
// Canonical corpus name: ArrayScanForMatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayScanForMatch_0045e5f0.c

void UnknownObject::ArrayScanForMatch()
{
    // Scans a 104-element dword array beginning at this+3974 (this+0x3E18) for a value equal to a2. Returns 1 when a matching element is found, 0 when the scan exhausts 104 elements without a match.
    // ASSIGNMENT: v2 = 0; scan index initialized before the loop. [source:raw]
    // LOOP: Iterate cursor i over dword array elements starting at this + 3974 (byte offset 0x3E18), comparing each element to a2. [field:this:0x00003E18, source:raw]
    // GUARD: If the incremented scan index reaches 104 without a match, return 0 (not found). [source:raw]
    // RETURN: Return 1 when the current array element equals a2 (match found). [source:raw]

    // Conservative worker pseudocode:
    //   char ArrayScanForMatch(DWORD *this, int a2) {
    //     int idx = 0;
    //     for (DWORD *p = this + 3974; *p != a2; ++p)
    //       if (++idx >= 104) return 0;
    //     return 1;
    //   }
    // UNRESOLVED: Boolean result (1/0) does not expose the matching index; how the caller uses the found/not-found signal is unknown.
    // UNRESOLVED: Semantic identity of the 104-element array at this+0x3E18 is unknown.
}
