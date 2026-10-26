// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448480
// Canonical corpus name: WeightedAverageInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WeightedAverageInterpolation_00448480.c

void UnknownObject::WeightedAverageInterpolation()
{
    // Unconditional element-wise midpoint: averages each of the three typed fields of the input structures a2 and a3 (float at offset 0x0, double at offset 0x4, float at offset 0xC) into the corresponding fields of the output structure this, each scaled by 0.5. Returns the a2 pointer (result = a2). No guard; every call overwrites all three output fields. Called by TriangleMeshAdjacencyBuilder, CollisionContactResponse and RecursiveTriangleEdgeSubdivisionForCollision.
    // ASSIGNMENT: Initialize result = a2; the source input pointer is carried through and returned. [source:raw]
    // CALCULATION: Write the float average into this + 0x0: *(float*)this = (*(float*)a2 + *(float*)a3) * 0.5, using the 0.5 constant global flt_59E450. [field:this:0x00000000, global:0x0059E450]
    // CALCULATION: Write the double average into this + 0x4: *(double*)(this + 4) = (*(double*)(a2 + 4) + *(double*)(a3 + 4)) * 0.5, using the 0.5 constant global dbl_59E880. [field:this:0x00000004, global:0x0059E880]
    // CALCULATION: Write the float average into this + 0xC: *((float*)this + 3) = (*(float*)(a2 + 12) + *(float*)(a3 + 12)) * 0.5, using the 0.5 constant global flt_59E450. [field:this:0x0000000C, global:0x0059E450]
    // RETURN: Return result (the a2 pointer). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_448480(char* this, int a2, int a3) {
    //     int result = a2;
    //     *(float*)this = (*(float*)a2 + *(float*)a3) * 0.5;
    //     *(double*)(this + 4) = (*(double*)(a2 + 4) + *(double*)(a3 + 4)) * 0.5;
    //     *((float*)this + 3) = (*(float*)(a2 + 12) + *(float*)(a3 + 12)) * 0.5;
    //     return result;
    //   }
    // UNRESOLVED: Both globals flt_59E450 (0x0059E450) and dbl_59E880 (0x0059E880) carry the 0.5 scale constant; the float/double split between them is inferred from their storage type and is DERIVED.
    // UNRESOLVED: The output layout (float, double, float at offsets 0x0, 0x4, 0xC) and the caller's record type are not otherwise identified.
    // UNRESOLVED: Despite the name, no weighting factor other than the fixed 0.5 midpoint is present in the body.
}
