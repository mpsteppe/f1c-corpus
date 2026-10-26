// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448300
// Canonical corpus name: RandomScaledValue
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomScaledValue_00448300.c

void UnknownObject::RandomScaledValue()
{
    // Produces a scaled value by indexing a lookup table with a monotonically incrementing global counter, multiplying the table entry by a scale factor stored at this+0x8, and storing the product at this+0x14. Returns the new counter value.
    // CALCULATION: Index flt_8AAE74 (lookup table at 0x008AAE74) with the low byte of dword_8AAE70 (counter at 0x008AAE70) to read a table entry. [global:0x008AAE70, global:0x008AAE74, source:raw]
    // ASSIGNMENT: Write the product of the table entry and the scale factor at this+0x8 into this+0x14 (output slot). [field:this:0x00000008, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Increment dword_8AAE70 (ring-buffer counter) and capture its new value as the return value. [global:0x008AAE70, source:raw]
    // RETURN: Return the incremented counter value as the result. [source:raw]

    // Conservative worker pseudocode:
    //   double entry = flt_8AAE74[(unsigned char)dword_8AAE70];
    //   result = ++dword_8AAE70;
    //   this[5] = entry * this[2];
    //   return result;
    // UNRESOLVED: Semantic meaning of the lookup table at 0x008AAE74 and counter at 0x008AAE70 (trig/weather noise) is DERIVED from existing analysis, not independently proven.
    // UNRESOLVED: Class owning this object and the role of this+0x14 output slot are unknown.
}
