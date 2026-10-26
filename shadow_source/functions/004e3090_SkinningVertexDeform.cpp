// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E3090
// Canonical corpus name: sub_4E3090
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4E3090_004e3090.c

void UnknownObject::SkinningVertexDeform()
{
    // Deforms a run of skinned vertices using a rotation frame derived from a2 (bone direction and origin fields), blending each vertex toward its transformed position by a per-vertex weight, writing results through per-vertex output pointers, then clearing the dirty flag on the output buffer (this+0x8F8). All work is gated by a three-level enable check on a2+112 (frame pointer), a2+176 (enable byte) and this[569] (this+0x8E4, output buffer). Frame-path helper called by VehicleStateUpdate_19d0 (0x004E19D0).
    // GUARD: Bone frame pointer check: the dword at a2+112 must be non-zero or the function returns early without deforming. [source:raw]
    // GUARD: Bone enable check: the byte at a2+176 must be non-zero or the function returns early. [source:raw]
    // GUARD: Output buffer check: this[569] (this+0x8E4) must be non-zero or the function returns early. [field:this:0x000008E4, source:raw]
    // ASSIGNMENT: Load the frame inputs into locals: direction component from a2+212, origin components from a2+116 and a2+120, and the z carry value from a2+292; a2+224 holds the second direction component. [source:raw]
    // GUARD: Degenerate tangent case: when both direction components (a2+212 and a2+224) are zero, use the unit frame (0.0, 0.0, 1.0) instead of normalizing. [source:raw]
    // CALCULATION: Normalize the tangent direction when non-zero: scale the two components by 1/sqrt(v16*v16 + v3*v3); the third frame term stays 0.0. [source:raw]
    // CALCULATION: Build the two remaining frame vectors from the normalized tangent via the embedded cross-product terms (v18, v20, v22), then normalize with 1/sqrt(v22*v22 + v20*v20 + v18*v18). [source:raw]
    // LOOP: Vertex run loop: for the count stored at a2+284, iterate stride-32 entries starting at the pointer a2+288. For each entry read the 3-float local offset at +12/+16/+20, the base position at +0/+4/+8, the blend weight at +24 and the output pointer at +28; compute the frame-rotated position, then write base + (transformed - base) * weight into the output pointer's three floats. [source:raw]
    // ASSIGNMENT: Clear the output-buffer dirty flag: dword at (this+0x8F8)+20 is masked with 0xFEFFFFDF. [field:this:0x000008F8, source:raw]
    // RETURN: Return the output buffer pointer this[569] (this+0x8E4). [field:this:0x000008E4, source:raw]

    // Conservative worker pseudocode:
    //   char SkinningVertexDeform(void *this, int a2) {
    //     if (!*(int*)(a2 + 112)) return 0;
    //     if (!*(byte*)(a2 + 176)) return 0;
    //     int *out = this[569];
    //     if (!out) return 0;
    //     float dx = *(float*)(a2 + 212), dy = *(float*)(a2 + 224);
    //     float ox = *(float*)(a2 + 116), oz = *(float*)(a2 + 292), oy = *(float*)(a2 + 120);
    //     float tx, ty;
    //     if (dx == 0.0f && dy == 0.0f) { tx = 0.0f; ty = 1.0f; }
    //     else { float inv = 1.0f / sqrtf(dy*dy + dx*dx); tx = inv * dx; ty = dy * inv; }
    //     // build and normalize the two remaining frame vectors (v18, v20, v22)
    //     for (int i = 0; i < *(int*)(a2 + 284); i++) {
    //       float *e = (float*)(*(int*)(a2 + 288) + i * 32);
    //       float *dst = *(float**)((char*)e + 28);
    //       float w = e[6];
    //       dst[0] = (rotX - e[0]) * w + e[0];
    //       dst[1] = (rotY - e[1]) * w + e[1];
    //       dst[2] = (rotZ - e[2]) * w + e[2];
    //     }
    //     *(int*)((char*)out + 20) &= 0xFEFFFFDF;
    //     return (char)out;
    //   }
    // UNRESOLVED: Packet lists globals flt_59E43C (0x0059E43C) and flt_59E440 (0x0059E440) as read, but the raw source contains no direct global references; the float literals (0.0, 1.0) are likely constant-folded from these globals, which is not directly evidenced.
    // UNRESOLVED: The bone/skin state layout at a2 (frame pointer a2+112, enable byte a2+176, direction/origin fields, vertex-run count a2+284 and base a2+288) is only evidenced through raw pointer arithmetic; the owning struct is unnamed.
    // UNRESOLVED: The meaning of the a2+292 value carried into the z output and the exact frame construction (tangent/binormal/normal) are interpreted from analysis prose; only the arithmetic is evidenced here.
    // UNRESOLVED: The object holding this+0x8E4 and this+0x8F8 is unidentified.
}
