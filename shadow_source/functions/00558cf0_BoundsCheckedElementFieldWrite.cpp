// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00558CF0
// Canonical corpus name: BoundsCheckedArrayWrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundsCheckedArrayWrite_00558cf0.c

void UnknownObject::BoundsCheckedElementFieldWrite()
{
    // Bounds-checked single-field write into an element array: reads the element count from this[11] (offset 0x2C) and, when the caller index a2 is within bounds, shifts it left by 7 to form a byte stride and writes a3 to element+12 using the array base pointer this[13] (offset 0x34). Returns the index when out of bounds, or the shifted index when written. Called by particle and wheel render update paths.
    // ASSIGNMENT: Initialize the result to the caller index a2. [source:raw]
    // GUARD: Guard on a2 < this[11] (element count limit at byte offset 0x2C); out-of-range indexes skip the write. [field:this:0x0000002C, source:raw]
    // CALCULATION: Compute the element byte offset as a2 << 7 (a shift of 7), the stride encoded in the raw source. [source:raw]
    // ASSIGNMENT: Write a3 into the dword at (a2 << 7) + this[13] + 12, where this[13] (byte offset 0x34) is the element array base pointer and 12 is the field displacement inside the element. [field:this:0x00000034, source:raw]
    // RETURN: Return a2 when the index was out of bounds, or the shifted index a2 << 7 when the write occurred. [source:raw]

    // Conservative worker pseudocode:
    //   int BoundsCheckedElementFieldWrite(int* this, int a2, int a3) {
    //     int result = a2;
    //     if (a2 < this[11]) {
    //       result = a2 << 7;
    //       *(int*)((a2 << 7) + (char*)this[13] + 12) = a3;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner class and the element type of the array at offset 0x34 are unknown.
    // UNRESOLVED: Meaning of the written field at element+12 and of the shift-by-7 stride are unknown.
    // UNRESOLVED: Why callers span both particle and wheel update paths is unresolved.
}
