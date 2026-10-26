// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055EE20
// Canonical corpus name: sub_55EE20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55EE20_0055ee20.c

void UnknownObject::MatrixTransformVertices()
{
    // Transforms an array of 3D position vectors through a 4x4 transform matrix. Stores the vertex count from this+0x8 into global dword_5DC470, then loops count times: each source vertex (pointer at this+0xC, 12-float stride) is multiplied by the matrix in a2 and the three transformed components are written to the output array (pointer at this+0x3C, 6-float stride). Called by ThinWrapperDropsA1 (0053ACF0).
    // ASSIGNMENT: Stores the vertex count from this+0x8 (a1[2]) into global dword_5DC470 [field:this:0x00000008, global:0x005DC470, source:raw]
    // ASSIGNMENT: Loads the source vertex array pointer from this+0xC (a1[3]) [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Loads the output vertex array pointer from this+0x3C (a1[15]) [field:this:0x0000003C, source:raw]
    // LOOP: Iterates once per vertex (count from this+0x8, post-decrement counter in a do/while), advancing the source pointer by 12 floats and the output pointer by 6 floats per vertex [field:this:0x00000008, field:this:0x0000000C, field:this:0x0000003C, source:raw]
    // CALCULATION: Per vertex, computes the matrix-vector product against a2: X = a2[0]*v.x + a2[4]*v.y + a2[8]*v.z + a2[12], Y = a2[1]*v.x + a2[5]*v.y + a2[9]*v.z + a2[13], Z = a2[2]*v.x + a2[6]*v.y + a2[10]*v.z + a2[14] [source:raw]
    // ASSIGNMENT: Stores the three transformed components into the output slots at this+0x3C (output stride 6 floats) [field:this:0x0000003C, source:raw]
    // CALL: Invoked by ThinWrapperDropsA1 (0053ACF0) [caller:0x0053ACF0, source:raw]

    // Conservative worker pseudocode:
    //   dword_5DC470 = count = this[2];
    //   src = this[3]; dst = this[15];
    //   do {
    //     dst[0] = a2[0]*src[0] + a2[4]*src[1] + a2[8]*src[2] + a2[12];
    //     dst[1] = a2[1]*src[0] + a2[5]*src[1] + a2[9]*src[2] + a2[13];
    //     dst[2] = a2[2]*src[0] + a2[6]*src[1] + a2[10]*src[2] + a2[14];
    //     src += 12; dst += 6;
    //   } while (count-- > 1);
    // UNRESOLVED: Fields this+0x10, this+0x14, this+0x40 and this+0x44 are packet-flagged but never referenced in the decompiled source; their roles are unknown
    // UNRESOLVED: The transform matrix a2 is indexed by row stride (a2[0]/a2[4]/a2[8]/a2[12] etc.); a2's 4x4 layout is assumed and the 6-float output stride (two interleaved spare floats per vertex) is not defined
}
