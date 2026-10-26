// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CC700
// Canonical corpus name: F_3DBoundingBoxRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DBoundingBoxRender_004cc700.c

void UnknownObject::RenderBoundingBoxCorners()
{
    // Render context helper (stdcall): reads a box center from this+0x2C/0x30/0x34 and combines it with the two 3-vector arguments a2/a3 to form four corner points, writing each to a texture buffer via PixelWriteToTextureBuffer (0x00558E10) with corner ids 0..3 and returning the last call's result. Debug/visualization rendering path.
    // CALCULATION: Read the box center from this+0x2C/0x30/0x34 (a1[11..13]) and add the a3 vector to form corner A (v11,v13,v15). [field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: Write corner A to the texture buffer via PixelWriteToTextureBuffer with corner id 1, using the this+0x0 texture/render handle and the this+0x60 render parameter. [callee:0x00558E10, field:this:0x00000000, field:this:0x00000060, source:raw]
    // CALCULATION: Subtract the a2 vector from corner A to form corner B (v5,v7,v9). [source:raw]
    // CALL: Write corner B to the texture buffer with corner id 2. [callee:0x00558E10, field:this:0x00000000, field:this:0x00000060, source:raw]
    // CALCULATION: Subtract the a3 vector from the center to form corner C (v12,v14,v16). [field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: Write corner C to the texture buffer with corner id 0. [callee:0x00558E10, field:this:0x00000000, field:this:0x00000060, source:raw]
    // CALCULATION: Subtract the a2 vector from corner C to form corner D (v6,v8,v10). [source:raw]
    // CALL: Write corner D to the texture buffer with corner id 3, returning its value. [callee:0x00558E10, field:this:0x00000000, field:this:0x00000060, source:raw]
    // RETURN: Return the value returned by the final PixelWriteToTextureBuffer call. [source:raw]
    // CALL: Invoked by sub_4CC970 (0x004CC970) and ParticleEffectPhysics (0x004CCB30) to emit debug/particle bounding-box corners. [caller:0x004CC970, caller:0x004CCB30, source:raw]

    // Conservative worker pseudocode:
    //   int RenderBoundingBoxCorners(float *a1, float *a2, float *a3) {
    //     float ax = a3[0] + a1[11], ay = a3[1] + a1[12], az = a3[2] + a1[13];
    //     PixelWriteToTextureBuffer(*((DWORD*)a1), 1, ax, ay, az, *((DWORD*)a1 + 24));
    //     float bx = ax - a2[0], by = ay - a2[1], bz = az - a2[2];
    //     PixelWriteToTextureBuffer(*((DWORD*)a1), 2, bx, by, bz, *((DWORD*)a1 + 24));
    //     float cx = a1[11] - a3[0], cy = a1[12] - a3[1], cz = a1[13] - a3[2];
    //     PixelWriteToTextureBuffer(*((DWORD*)a1), 0, cx, cy, cz, *((DWORD*)a1 + 24));
    //     return PixelWriteToTextureBuffer(*((DWORD*)a1), 3, cx - a2[0], cy - a2[1], cz - a2[2], *((DWORD*)a1 + 24));
    //   }
    // UNRESOLVED: Meaning of the a2/a3 vectors (box half-extents vs. independent offsets) and of the per-corner ids 0..3 is not established from this function alone.
    // UNRESOLVED: Semantics of the this+0x60 render parameter (colour/alpha/etc.) is not established.
}
