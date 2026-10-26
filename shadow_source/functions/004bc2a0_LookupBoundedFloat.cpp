// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC2A0
// Canonical corpus name: ArithmeticComparison_c2a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_c2a0_004bc2a0.c

void UnknownObject::LookupBoundedFloat()
{
    // Bounds-checked float array lookup: returns -1.0 when index a2 is negative or >= either capacity bound (this+0x8 or this+0x88); otherwise returns the float at this+0x90 + 4 * a2, widened to double.
    // GUARD: Bounds check a2: reject a2 < 0, a2 >= this+0x8 (this[2]), or a2 >= this+0x88 (this[34]); failure path returns -1.0. [source:raw, field:this:0x00000008, field:this:0x00000088]
    // CALCULATION: Compute element address this+0x90 (this[36]) + 4 * a2. [source:raw, field:this:0x00000090]
    // RETURN: Return the float at the computed element address as a double. [source:raw, field:this:0x00000090]
    // RETURN: Return the -1.0 sentinel when the bounds check fails. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_4BC2A0(int a2) {
    //     if (a2 < 0 || a2 >= this[2] || a2 >= this[34])
    //       return -1.0;
    //     return (double)(*(float *)(this[36] + 4 * a2));
    //   }
    // UNRESOLVED: Global flt_59E670 (0x0059E670) is listed as a read global in the packet but does not appear in the raw source text; it may hold the -1.0 return constant, but the linkage is not asserted.
    // UNRESOLVED: Relationship between the two capacity bounds (this+0x8 and this+0x88) and the array pointer field this+0x90 is unknown.
}
