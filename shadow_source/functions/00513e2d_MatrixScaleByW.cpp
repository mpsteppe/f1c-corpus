// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513E2D
// Canonical corpus name: MatrixScaleByW
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MatrixScaleByW_00513e2d.c

void UnknownObject::MatrixScaleByW()
{
    // Batch homogeneous-weight scaling: processes exactly 16 consecutive float4 (X,Y,Z,W) vectors, reading each from the source pointer and writing to the destination pointer. For each vector it multiplies X, Y and Z by that vector's own W and passes W through unchanged. A pre-transform vertex/point weighting step.
    // LOOP: Iterate exactly 16 times (v2 initialized to 16, decremented each pass), advancing both the source and destination pointers by 4 floats per iteration until the counter reaches zero [source:raw]
    // CALCULATION: Compute v3 = a1[3] * a1[0], i.e. multiply the W component (this+0xC) by the X component (this+0x0) of the current source vector [field:this:0x0000000C, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the product v3 into the destination X slot (*a2 = v3), then advance both pointers by 4 floats [source:raw, field:this:0x00000000]
    // ASSIGNMENT: Write the remaining components of the current vector: destination Y = source Y * source W, destination Z = source Z * source W, destination W = source W (unchanged pass-through) [field:this:0x0000000C, source:raw]
    // RETURN: Return 0 once all 16 vectors have been scaled; reached from DelegationWithErrorCheck (005158AF) and InitProcessWrapper (005158E3) [function:0x00513E2D, caller:0x005158AF, caller:0x005158E3, source:raw]

    // Conservative worker pseudocode:
    //   src = a1; dst = a2;
    //   for (i = 0; i < 16; ++i) {
    //     x = src[0]; y = src[1]; z = src[2]; w = src[3];
    //     dst[0] = x * w;
    //     dst[1] = y * w;
    //     dst[2] = z * w;
    //     dst[3] = w;
    //     src += 4; dst += 4;
    //   }
    //   return 0;
    // UNRESOLVED: The __usercall float* prototypes for a1 (eax) and a2 (ecx) are compiler-register facts; the caller-side layout contract for the 16-vector buffer is not evidenced beyond the float4 stride
    // UNRESOLVED: Whether the source and destination buffers may alias is not evidenced by the raw source
}
