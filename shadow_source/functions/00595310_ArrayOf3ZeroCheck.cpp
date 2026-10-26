// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595310
// Canonical corpus name: ArrayOf3ZeroCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayOf3ZeroCheck_00595310.c

void UnknownObject::ArrayOf3ZeroCheck()
{
    // Tests three consecutive dwords for all-zero state. Walks a1 element by element; while the current element is zero it advances the pointer and increments a counter, returning 1 as soon as the counter reaches 3 (all three consecutive elements were zero). Any non-zero element terminates the walk immediately with 0.
    // ASSIGNMENT: Initialize the element counter v2 to 0 before the walk. [source:raw]
    // LOOP: while-loop: while the current element at a1 is zero, increment v2 and advance a1 to the next element; the walk stops at the first non-zero element. [field:this:0x00000000, source:raw]
    // GUARD: Loop condition reads the dword at the current pointer (field 0x0 of the current element); a non-zero value exits the loop and selects the 0 return path. [field:this:0x00000000, source:raw]
    // RETURN: Return 1 when v2 reaches 3, i.e. all three consecutive elements starting at a1 were zero. [source:raw]
    // RETURN: Return 0 when a non-zero element is encountered before the counter reached 3. [source:raw]
    // CALL: Called by sub_5953B8 (0x005953B8) to check whether the 3-element array it owns is entirely zero. [caller:0x005953B8, source:raw]

    // Conservative worker pseudocode:
    //   int sub_595310(int* a1) {
    //     int v2 = 0;
    //     while (!*a1) {
    //       ++v2; ++a1;
    //       if (v2 >= 3) return 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The prelabel template action ('getter: returns field 0x0') does not match the raw source, which iterates three consecutive elements; the raw source outranks the template label and no single-field getter is claimed.
    // UNRESOLVED: The elements at a1+4 and a1+8 reached by pointer advancement have no distinct packet field evidence; only the base field 0x0 is evidenced.
}
