// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040AD60
// Canonical corpus name: LinearSearchWithStride0xA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinearSearchWithStride0xA0_0040ad60.c

void UnknownObject::LinearSearchPointerStride160()
{
    // Linear search for the value a2 in an array of stride-160 elements rooted at this[3] (offset 0xC) with this[4] (offset 0x10) entries. Returns the zero-based matching index, or -1 when the element is absent or the array is empty. Each step compares the current element pointer (advanced by 160 bytes) against a2.
    // ASSIGNMENT: Read the entry count this[4] (offset 0x10) into v2 and initialize the search index v4 to 0 and the default result to -1. [field:this:0x00000010, source:raw]
    // GUARD: Guard on this[4] > 0; when the array is empty or has a negative count, skip the loop and return -1. [field:this:0x00000010, source:raw]
    // LOOP: Iterate a pointer i starting at this[3] (offset 0xC) and advancing by 160 bytes each step, comparing i against a2. [field:this:0x0000000C, source:raw]
    // GUARD: Before each comparison, increment v4 and return -1 when v4 reaches the entry count v2, i.e. the element was not found. [field:this:0x00000010, source:raw]
    // RETURN: Return the matching index v4 when the search pointer equals a2. [field:this:0x0000000C, source:raw]
    // RETURN: Return -1 when the array is empty or the element is absent. [field:this:0x00000010, source:raw]
    // CALL: Invoked by LookupWithOptionalCallback (0x0040B450) to resolve an element index by pointer. [caller:0x0040B450]

    // Conservative worker pseudocode:
    //   int sub_40AD60(int* this, int a2) {
    //     int count = this[4];
    //     int index = 0;
    //     if (count > 0) {
    //       for (int* p = (int*)this[3]; p != a2; p += 40) {
    //         if (++index >= count) return -1;
    //       }
    //       return index;
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: The stride-160 element layout and the type of a2 (pointer vs. value) are not recoverable from this function alone.
    // UNRESOLVED: The identity of the owning object and the meaning of the returned index depend on the caller at 0x0040B450.
}
