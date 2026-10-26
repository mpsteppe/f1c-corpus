// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583790
// Canonical corpus name: PhysicsQueryGetterWithReadyFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsQueryGetterWithReadyFlag_00583790.c

void UnknownObject::PhysicsQueryGetterWithReadyFlag()
{
    // Consumes a producer-written physics/animation query state guarded by a ready flag. If the flag at this+12 is clear it returns 0 immediately; otherwise it clears the flag, computes a timestamp delta (a5 minus the previous timestamp at this+16), writes the output value (delta plus the base value at this+24) through a2, copies the attached data size from this+288 into a4, and returns 1. When the data size is non-positive it writes 0 into a3 instead of the data pointer.
    // GUARD: Return 0 immediately when the ready flag byte at this+12 is zero. [source:raw, field:this:0x0000000C]
    // CALCULATION: Compute the timestamp delta v5 = a5 - previous timestamp at this+16. [source:raw, field:this:0x00000010]
    // ASSIGNMENT: Clear the ready flag byte at this+12 to 0, marking the query state consumed. [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Write the output value *a2 = v5 + base value at this+24. [source:raw, field:this:0x00000018]
    // ASSIGNMENT: Copy the attached data size at this+288 into the output slot *a4. [source:raw, field:this:0x00000120]
    // GUARD: If the data size at this+288 <= 0, write *a3 = 0 (no data pointer) and return 1. [source:raw, field:this:0x00000120, guard:0]
    // ASSIGNMENT: Otherwise write *a3 = this + 32, the address of the attached data buffer, and return 1. [source:raw]
    // RETURN: Return 1 when the query state was produced; return 0 only when the ready flag was clear. [source:raw]

    // Conservative worker pseudocode:
    //   char PhysicsQueryGetterWithReadyFlag(int this, double* a2, int* a3, int* a4, double a5) {
    //     if (!*(char*)(this+12)) return 0;
    //     double v5 = a5 - *(double*)(this+16);
    //     *(char*)(this+12) = 0;
    //     *a2 = v5 + *(double*)(this+24);
    //     *a4 = *(int*)(this+288);
    //     if (*(int*)(this+288) <= 0) { *a3 = 0; return 1; }
    //     *a3 = this + 32;
    //     return 1;
    //   }
    // UNRESOLVED: Meaning of the timestamp parameter a5 and of the base value at this+24 depends on the producer/caller (AnimationValueFetchWithTiming).
    // UNRESOLVED: Layout and element type of the attached data buffer at this+32 are unknown.
    // UNRESOLVED: Whether the data pointer written to a3 aliases the value written to a2 is unresolved.
}
