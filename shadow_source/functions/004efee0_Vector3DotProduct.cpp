// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EFEE0
// Canonical corpus name: sub_4EFEE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4EFEE0_004efee0.c

void UnknownObject::Vector3DotProduct()
{
    // __fastcall 3-component dot product over two float vectors a1 and a2: returns a1[0]*a2[0] + a1[1]*a2[1] + a1[2]*a2[2] as double. All three components of the first vector are read at offsets 0x0, 0x4, 0x8. No branches, globals, or callees. Structural twin of the cluster representative at 0045eb00 (prelabel cluster_copy). Single static caller: RayTriangleIntersectionWithBarycentricCoordinate (004EFBD0).
    // CALCULATION: Load the three components of a1 at offsets 0x0, 0x4, 0x8 (a1[0], a1[1], a1[2]). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Compute a1[0]*a2[0] + a1[1]*a2[1] + a1[2]*a2[2]; the second vector a2 is read at the same offsets 0x0, 0x4, 0x8 as a1. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // RETURN: Return the accumulated double result of the three pairwise products. [function:0x004EFEE0, source:raw]
    // CALL: Invoked by RayTriangleIntersectionWithBarycentricCoordinate (004EFBD0). [caller:0x004EFBD0]

    // Conservative worker pseudocode:
    //   double Vector3DotProduct(const float *a1, const float *a2) {
    //     return a1[0]*a2[0] + a1[1]*a2[1] + a1[2]*a2[2];
    //   }
    // UNRESOLVED: Field evidence covers only a1's three components; a2 is read at the same offsets but is not separately listed as field evidence.
    // UNRESOLVED: The prelabel names the cluster representative 0045eb00 Vector3ScalarMultiply; the packet source computes a dot product, and the caller (ray/triangle intersection) is consistent with a dot product, but the cluster name itself is not confirmed by this packet.
}
