// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C9A9
// Canonical corpus name: BilinearInterp4Component
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BilinearInterp4Component_0050c9a9.c

void UnknownObject::BilinearInterp4Component()
{
    // Bilinear interpolation of a 4-component float vector. Writes out[i] = (cornerB[i] - cornerA[i]) * t1 + (cornerC[i] - cornerA[i]) * t2 + cornerA[i] for i in 0..3 using a2 as the base corner and a3/a4 as the two edge corners, weighted by scalar factors a5 and a6. Returns the out pointer (a1).
    // ASSIGNMENT: result = a1; cache the destination (out) pointer in eax for the eventual return value. [function:0x0050C9A9, source:raw]
    // CALCULATION: out[0] = (edgeA[0] - base[0]) * weightA + (edgeB[0] - base[0]) * weightB + base[0]; bilinear interpolation of component 0. [source:raw, field:this:0x00000000]
    // CALCULATION: out[1] = (edgeA[1] - base[1]) * weightA + (edgeB[1] - base[1]) * weightB + base[1]; bilinear interpolation of component 1. [source:raw, field:this:0x00000004]
    // CALCULATION: out[2] = (edgeA[2] - base[2]) * weightA + (edgeB[2] - base[2]) * weightB + base[2]; bilinear interpolation of component 2. [source:raw, field:this:0x00000008]
    // CALCULATION: out[3] = (edgeA[3] - base[3]) * weightA + (edgeB[3] - base[3]) * weightB + base[3]; bilinear interpolation of component 3. [source:raw, field:this:0x0000000C]
    // RETURN: return result; __stdcall function returns the out pointer (a1) in eax. [function:0x0050C9A9, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   float *BilinearInterp4Component(float *out, float *base, float *edgeA, float *edgeB, float weightA, float weightB)
    //   {
    //       out[0] = (edgeA[0] - base[0]) * weightA + (edgeB[0] - base[0]) * weightB + base[0];
    //       out[1] = (edgeA[1] - base[1]) * weightA + (edgeB[1] - base[1]) * weightB + base[1];
    //       out[2] = (edgeA[2] - base[2]) * weightA + (edgeB[2] - base[2]) * weightB + base[2];
    //       out[3] = (edgeA[3] - base[3]) * weightA + (edgeB[3] - base[3]) * weightB + base[3];
    //       return out;
    //   }
    // UNRESOLVED: Which objects the four float pointers (out, base, edgeA, edgeB) belong to; ownership is UNKNOWN because callers are absent from the packet.
    // UNRESOLVED: Which weight (a5 vs a6) pairs with which edge corner (a3 vs a4); the mapping is inferred from the formula's symmetry, not independently evidenced.
    // UNRESOLVED: Whether this is used for texture-coordinate, position, or colour interpolation; no call-site evidence is available.
}
