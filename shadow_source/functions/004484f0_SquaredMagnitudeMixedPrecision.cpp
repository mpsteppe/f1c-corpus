// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004484F0
// Canonical corpus name: EmptyFunction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EmptyFunction_004484f0.c

void UnknownObject::SquaredMagnitudeMixedPrecision()
{
    // Returns the squared magnitude (dot product with itself) of a three-component vector stored in mixed precision: float component at this+0x0, double component at this+0x4, and float component at this+0xC. Computed as the sum of each component multiplied by itself, promoted to double for the double term. Called by RecursiveTriangleEdgeSubdivisionForCollision (0044aae0), consistent with its use in collision-mesh edge length calculation.
    // CALCULATION: Reads the float component at this+0x0 and squares it [field:this:0x00000000, source:raw]
    // CALCULATION: Reads the double component at this+0x4 and squares it [field:this:0x00000004, source:raw]
    // CALCULATION: Reads the float component at this+0xC and squares it [field:this:0x0000000C, source:raw]
    // CALCULATION: Sums the three squared components [source:raw]
    // RETURN: Returns the sum as a double (the squared magnitude) [source:raw]
    // CALL: Invoked by RecursiveTriangleEdgeSubdivisionForCollision (0044aae0) to size collision-mesh edges [caller:0x0044AAE0, source:raw]

    // Conservative worker pseudocode:
    //   double SquaredMagnitudeMixedPrecision(void* this) {
    //     double c0 = (double)(*(float*)this);
    //     double c1 = *(double*)((char*)this + 4);
    //     double c2 = (double)(*((float*)this + 3));
    //     return c0*c0 + c1*c1 + c2*c2;
    //   }
    // UNRESOLVED: Field this+0x4 is read as a double while this+0x0 and this+0xC are floats; the struct layout producing this mixed precision is not defined here
}
