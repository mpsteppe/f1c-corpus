// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E540
// Canonical corpus name: PlaneEquationFromPointNormal
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlaneEquationFromPointNormal_0050e540.c

void UnknownObject::PlaneEquationFromPointNormal()
{
    // __stdcall helper that builds a plane equation from a point and a normal: copies the three normal components (a3[0..2]) into the output struct at a1+0/+4/+8, then stores the signed plane constant -(a2[0]*a3[0] + a2[1]*a3[1] + a2[2]*a3[2]) at a1+12, and returns a1. Equivalent to constructing the plane with the negated dot product of the point-on-plane vector a2 with the plane normal a3.
    // ASSIGNMENT: Copy normal component X: *(float *)a1 = *(float *)a3. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Copy normal component Y: *(_DWORD *)(a1 + 4) = *(_DWORD *)(a3 + 4). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Copy normal component Z: *(_DWORD *)(a1 + 8) = *(_DWORD *)(a3 + 8). [field:this:0x00000008, source:raw]
    // CALCULATION: Compute plane constant at a1 + 12: -(a2[1] * a3[1] + a2[2] * a3[2] + a2[0] * a3[0]), i.e. the negated dot product of the point vector a2 with the normal a3. [field:this:0x0000000C, source:raw]
    // RETURN: Return a1 (the output plane struct pointer), preserved in result before the writes. [abi:lead, function:0x0050E540, source:raw]

    // Conservative worker pseudocode:
    //   // out[0..2] = normal, out[3] = -(point . normal)
    //   float *plane = (float *)a1;
    //   float *point = a2;
    //   float *normal = (float *)a3;
    //   plane[0] = normal[0];
    //   plane[1] = normal[1];
    //   plane[2] = normal[2];
    //   plane[3] = -(point[0] * normal[0] + point[1] * normal[1] + point[2] * normal[2]);
    //   return a1;
    // UNRESOLVED: Roles of a2 (point on the plane) and a3 (plane normal) are inferred from the canonical name and the negated dot-product form; the packet evidence does not independently label either vector.
    // UNRESOLVED: Whether a2 is a normalized direction or an arbitrary point is not decidable from this function alone.
    // UNRESOLVED: The a1+12 value is interpreted as the signed plane distance constant in ax+by+cz+d=0 form (DERIVED from the dot-product structure, not stated by the evidence).
}
