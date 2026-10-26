// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040AD90
// Canonical corpus name: BoundedIndexSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundedIndexSetter_0040ad90.c

void UnknownObject::SetIndexWithinBounds()
{
    // Bounded index setter: writes a2 into this[5] (offset 0x14) only when 0 <= a2 < this[4] (offset 0x10, the upper bound). Always returns a2 unchanged, whether or not the write took place.
    // ASSIGNMENT: Initialize result to a2 so the original value is returned in every path. [source:raw]
    // GUARD: Guard on 0 <= a2 < this[4] (offset 0x10); the write is skipped when a2 is negative or at/above the bound. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write a2 into this[5] (offset 0x14) as the stored index when the bound check passes. [field:this:0x00000014, source:raw]
    // RETURN: Return result, i.e. a2 unchanged. [source:raw]
    // CALL: Invoked by LookupWithOptionalCallback (0x0040B450) to store a resolved array index on the object. [caller:0x0040B450]

    // Conservative worker pseudocode:
    //   int sub_40AD90(int* this, int a2) {
    //     int result = a2;
    //     if (a2 >= 0 && a2 < this[4]) this[5] = a2;
    //     return result;
    //   }
    // UNRESOLVED: The array whose bound is stored at this[4] (offset 0x10) is not identified here; index 0x14 is validated against it without resolving that array.
    // UNRESOLVED: The identity of the owning object and the role of the stored index depend on the caller at 0x0040B450.
}
