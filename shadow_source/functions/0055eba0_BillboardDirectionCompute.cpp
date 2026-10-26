// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055EBA0
// Canonical corpus name: sub_55EBA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55EBA0_0055eba0.c

void UnknownObject::BillboardDirectionCompute()
{
    // Per-vertex billboard reflection setup: selects a 12- or 16-byte vertex stride from a flag bit at this[6]+20 against 0x00800000, then for each vertex runs two D3D device vtable transforms (entries 0 and 1 on dword_8B8F24) over the source/destination vertex pointers, adds an offset vector from a2[9..11], normalizes it, applies a half-vector reflection mapped into [0,1], and stores two floats per vertex at this[8]+i*64+40 and this[8]+i*64+44.
    // GUARD: Early return when the offset argument a2 is null. [source:raw]
    // ASSIGNMENT: Read the source vertex base pointer from this[3] and the flag word from this[6]+20; when flag bit 0x00800000 is set select source stride 16 and destination base this[3]+28, otherwise stride 12 and base this[3]+12. [field:this:0x0000000C, field:this:0x00000018, global:0x00800000, source:raw]
    // GUARD: Loop guard: proceed only when vertex count this[2] is greater than 0. [guard:0, field:this:0x00000008]
    // LOOP: Iterate this[2] vertices, advancing the source/destination vertex pointers by the selected stride (4 * 12 or 4 * 16 bytes) and the output index by 64 bytes per iteration. [field:this:0x00000008, source:raw]
    // CALL: Call the second vtable entry (+4) of the D3D device wrapper dword_8B8F24 to transform the source vertex into v23, using scene node data at this[6]+312 plus 416. [global:0x008B8F24, field:this:0x00000018, source:raw]
    // CALL: Call the first vtable entry of the D3D device wrapper dword_8B8F24 to transform the destination vertex into v20, using scene node data at this[6]+312 plus 276. [global:0x008B8F24, field:this:0x00000018, source:raw]
    // CALCULATION: Add the offset components a2[9], a2[10], a2[11] to the transformed source vector v23 and normalize it with a reciprocal square root. [source:raw]
    // CALCULATION: Compute the reflection half-vector dot v13 as twice the dot product of v20/v21/v22 with the normalized vector, then map each output component to [0,1] via (component * v13 - normalized_component) * 0.5 + 0.5. [source:raw]
    // ASSIGNMENT: Store the two mapped reflection components at this[8] plus the running byte index plus 40 and plus 44. [field:this:0x00000020, source:raw]

    // Conservative worker pseudocode:
    //   void BillboardDirectionCompute(_DWORD *this, float *a2) {
    //     if (!a2) return;
    //     int src = this[3];
    //     int stride = (0x00800000 & *(int*)(this[6] + 20)) ? 16 : 12;
    //     int dst = (stride == 16) ? this[3] + 28 : this[3] + 12;
    //     for (int i = 0; i < this[2]; ++i) {
    //       vtable1(g_device, src, v23, scene + 416);
    //       vtable0(g_device, dst, &v20, scene + 276);
    //       float x = v23[0] + a2[9], y = v23[1] + a2[10], z = v23[2] + a2[11];
    //       float inv = 1.0f / sqrtf(x*x + y*y + z*z);
    //       float nx = inv*x, ny = inv*y, nz = inv*z;
    //       float h = 2.0f * (v20*nx + v21*ny + v22*nz);
    //       *(float*)(this[8] + i*64 + 40) = (v20*h - nx) * 0.5f + 0.5f;
    //       *(float*)(this[8] + i*64 + 44) = (v21*h - ny) * 0.5f + 0.5f;
    //       src += 4*stride; dst += 4*stride;
    //     }
    //   }
    // UNRESOLVED: Fields this[11] (0x2C) and this[84] (0x150) are listed as read by the fact table but do not appear in the raw body; their purpose is unknown.
    // UNRESOLVED: Globals flt_59E43C and flt_59E450 are listed as read but are absent from the raw body; they are likely consumed inside the D3D vtable transforms.
    // UNRESOLVED: The exact semantics of the reflection inputs v20/v21/v22 depend on the destination transform output layout, which is not visible here.
}
