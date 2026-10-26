// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448440
// Canonical corpus name: sub_448440
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_448440_00448440.c

void UnknownObject::CompareFloatAtOffset4()
{
    // Three-way float comparator over the float value at offset 4 of two objects a1 and a2: returns 1 when a1[4] is greater than a2[4], 0 when they are equal, and -1 otherwise (a1[4] less than a2[4]). A classic qsort-style ordering predicate.
    // GUARD: When the float at a1+4 is strictly greater than the float at a2+4, take the early return path yielding 1 [field:this:0x00000004, source:raw]
    // GUARD: When the greater-than comparison fails but the values are still >= (i.e. equal), return 0 [field:this:0x00000004, source:raw]
    // CALCULATION: Compare the two float values at offset 4 of a1 and a2 to establish ordering (greater/equal/less) [field:this:0x00000004, source:raw]
    // RETURN: Return -1 when a1[4] is less than a2[4], completing the three-way comparator contract (1 / 0 / -1) [source:raw]

    // Conservative worker pseudocode:
    //   if (*(float *)(a1 + 4) > *(float *)(a2 + 4))
    //     return 1;
    //   if (*(float *)(a1 + 4) >= *(float *)(a2 + 4))
    //     return 0;
    //   return -1;
    // UNRESOLVED: The objects compared (class of a1/a2) and the meaning of the float at offset 4 are not established by this packet
    // UNRESOLVED: No static callers are recorded, so the sorting context (if any) is unknown
    // UNRESOLVED: The prelabel template categorized this as a getter, but the raw source shows a three-way comparator returning -1/0/1
}
