// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00460C30
// Canonical corpus name: LinearSearchIn104ElementArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinearSearchIn104ElementArray_00460c30.c

void UnknownObject::LinearSearchIn104ElementArray()
{
    // Linearly searches a 104-element dword array beginning at this+3974 (this+0x3E18) for a value equal to a2. Returns the 0-based index of the first matching element, or 63 when the scan exhausts 104 elements without a match.
    // ASSIGNMENT: result = 0; match index initialized before the loop. [source:raw]
    // LOOP: Iterate cursor i over dword array elements starting at this + 3974 (byte offset 0x3E18), comparing a2 against each element. [field:this:0x00003E18, source:raw]
    // GUARD: If the incremented match index reaches 104 without a match, return 63 (not found sentinel). [source:raw]
    // RETURN: Return result (the 0-based index) when the current array element equals a2. [source:raw]

    // Conservative worker pseudocode:
    //   int LinearSearchIn104ElementArray(DWORD *this, int a2) {
    //     int idx = 0;
    //     for (DWORD *p = this + 3974; a2 != *p; ++p)
    //       if (++idx >= 104) return 63;
    //     return idx;
    //   }
    // UNRESOLVED: Failure sentinel 63 is not 104 or -1; the meaning of 63 to the caller is unknown.
    // UNRESOLVED: Semantic identity of the 104-element array at this+0x3E18 is unknown.
}
