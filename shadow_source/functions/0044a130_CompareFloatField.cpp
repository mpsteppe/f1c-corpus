// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044A130
// Canonical corpus name: sub_44A130
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_44A130_0044a130.c

void UnknownObject::CompareFloatField()
{
    // Three-way comparator over the float at offset +0xC of two arguments: returns 1 when a1's field is greater than a2's, 0 when they are equal, and -1 when a1's field is smaller. Consistent with a sort or ordering callback.
    // CALCULATION: Promote both float fields at offset +0xC of a1 and a2 to double for comparison. [source:raw, field:this:0x0000000C]
    // GUARD: Guard on *(float*)(a1+0xC) > *(float*)(a2+0xC): when strictly greater, return 1. [source:raw, field:this:0x0000000C]
    // RETURN: Return 1 when a1's field is strictly greater than a2's. [source:raw]
    // GUARD: Guard on *(float*)(a1+0xC) >= *(float*)(a2+0xC): equality (not strictly greater) yields 0. [source:raw, field:this:0x0000000C]
    // RETURN: Return 0 when the two fields compare equal. [source:raw]
    // RETURN: Return -1 when a1's field is strictly smaller than a2's (the fall-through case). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_44A130(int a1, int a2) {
    //     if (*(float*)(a1 + 12) > *(float*)(a2 + 12)) return 1;
    //     if (*(float*)(a1 + 12) >= *(float*)(a2 + 12)) return 0;
    //     return -1;
    //   }
    // UNRESOLVED: The semantic meaning of the compared float at offset +0xC (what ordering quantity it represents) is unknown.
    // UNRESOLVED: Only a1's field has an evidence reference; the equal read of a2's +0xC field is only covered by source:raw.
    // UNRESOLVED: What object type a1/a2 point to is unknown, so the field has no named meaning.
}
