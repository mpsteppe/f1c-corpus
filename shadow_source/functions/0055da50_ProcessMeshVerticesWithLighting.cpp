// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055DA50
// Canonical corpus name: sub_55DA50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55DA50_0055da50.c

void UnknownObject::ProcessMeshVerticesWithLighting()
{
    // Per-triangle mesh vertex processing for rendering. Uses the device-wrapper vtable (dword_8B8F24) to obtain transform/light vectors and per-vertex world positions. When the render flag bit 0x100 is set and the mesh vertex count is positive, accumulates per-bone influence weights from the weight block at this+0x128 into each vertex. Computes brightness from a material float at offset 80 (scaled by a context factor when material flag 0x4000 is set), packs vertex normals and the summed diffuse/specular result into RGBA color with MMX pack helpers, and writes the color (and optional reflection texcoords) into the output vertex buffer at this[8]+24/+28/+40/+44 for each of the triangle's three 16-bit indices. A deterministic signed guard on this+0xA0 selects the full blended-lighting path over a simple flat-color pack.
    // CALL: Setup calls through the device-wrapper vtable at dword_8B8F24: read the context pointer dword_8B8F28, then produce world-transform vectors v79 and v80 into local buffers using the mesh block pointer this[6] (this+0x18) and the output offset 0x154 (the +340 constant added to *(this[6]+312)). [global:0x008B8F24, global:0x008B8F28, field:this:0x00000154, source:raw]
    // GUARD: Guard selecting the per-vertex influence path: when the render control flag bit 0x100 of *this (offset 0x00) is clear, or the mesh vertex count read from this[6] (offset 0x18) is zero, the influence flag v93 is cleared. [field:this:0x00000000, field:this:0x00000018, source:raw]
    // CALL: Vertex-buffer accumulation loop: for each mesh vertex, call the vtable+20 and vtable+24 methods of dword_8B8F24 and write the summed result into the output vertex buffer entries (stride 14). [global:0x008B8F24, source:raw]
    // GUARD: Material color-vector selection using flags at this[1]+156 (offset 0x04 base): when bit 0x40 is set, either take the color vector fields at offsets 0x68/0x6C (material+104/+108) directly, or scale them by the context factor *(v61+36) when bit 0x4000000 is clear. [field:this:0x00000004, field:this:0x00000068, field:this:0x0000006C, source:raw]
    // CALL: Transform calls through the dword_8B8F24 vtable (vtable+20 and vtable+24) produce the world-space normal data v87 and the diffuse light vector v78 for the material at this[1]. [global:0x008B8F24, source:raw]
    // CALCULATION: Compute the brightness factor: read the material float at offset 80 via this[1]; when material flag 0x4000 is set it is scaled by *(v61+36)*255, otherwise by 255 alone, then truncated to 16 bits for packing. [field:this:0x00000004, source:raw]
    // CALCULATION: Compute the triangle count as the integer division of this[4] (offset 0x10) by 3 using a magic-number multiply/shift sequence. [field:this:0x00000010, source:raw]
    // LOOP: Per-triangle do-while loop that runs this[4]/3 times, advancing 36 bytes per iteration and counting down. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Read three 16-bit vertex indices from the index buffer this[5] (offset 0x14) and form the index base from the mesh block field at offset 0x124 (this[6]+292) plus the running byte offset. [field:this:0x00000014, field:this:0x00000124, source:raw]
    // CALL: When the influence flag v93 is set, call the vtable+4 method of dword_8B8F24 to fetch the current vertex world position into v81/v82/v83 using the mesh output base + 276. [global:0x008B8F24, source:raw]
    // LOOP: Per-bone influence loop over the vertex block behind this+0x128: read the vertex position (offsets 0x38/0x3C/0x40) and influence radius (0x50) of the vertex data block at *(this+0x128), compare the radius-squared against the squared distance, and accumulate blend weights from the weight block fields 0x10/0x14/0x18/0x1C, applying the falloff (1.0 - sqrt(distance) * inverse-distance factor) unless the vertex flag bit 0x100 (offset 0x00) is set. [field:this:0x00000128, field:*(this+0x128):0x00000000, field:*(this+0x128):0x00000010, field:*(this+0x128):0x00000014, field:*(this+0x128):0x00000018, field:*(this+0x128):0x0000001C, field:*(*(this+0x128)+0x0):0x00000000, field:*(*(this+0x128)+0x0):0x00000038, field:*(*(this+0x128)+0x0):0x0000003C, field:*(*(this+0x128)+0x0):0x00000040, field:*(*(this+0x128)+0x0):0x00000050, source:raw]
    // GUARD: Format select: when the mesh block flag at offset 0x13C (this[6]+316) is nonzero, vertex data uses a 64-byte stride from the output buffer this[8] (offset 0x20); otherwise it uses a 48-byte stride from this[3] (offset 0x0C). [field:this:0x0000013C, field:this:0x00000020, field:this:0x0000000C, source:raw]
    // CALCULATION: Pack the world normal v87 into the three 16-bit RGB lanes of the MMX color accumulator v92 and load the brightness-derived alpha lane. [source:raw]
    // GUARD: Deterministic guard on this+0xA0 (value less than 0): when it passes, the blended per-vertex lighting path runs (accumulated influences + MMX pack of diffuse/specular); when it fails, the base color is packed directly. [guard:0, field:this:0x000000A0, source:raw]
    // CALCULATION: Diffuse lighting: compute the negated dot product of the light direction v79 with the vertex normal; when positive, scale the diffuse vector v78 and add it into the RGB lanes of the color accumulator v92. [source:raw]
    // CALL: Specular path: when the material flag byte at this[1]+156 has bit 0x40 set and the view dot product is positive, scale the precomputed color vector by TableLookupScale on the material lookup table at this[1]+180. [field:this:0x00000004, callee:0x0053AC40, source:raw]
    // ASSIGNMENT: Write the specular color dword into the color slot (index<<6 + this[8] + 28) for all three triangle vertices. [field:this:0x00000020, source:raw]
    // CALCULATION: MMX pack: add the color accumulator v92 to the influence weights v94 (paddsw) and saturate-pack to a final RGBA dword using the qword_8B6C20 constant. [global:0x008B6C20, source:raw]
    // ASSIGNMENT: Write the packed final color dword into (index<<6 + this[8] + 24) for all three triangle vertices. [field:this:0x00000020, source:raw]
    // CALL: Reflection texcoord path: when the signed byte at this[1]+156 is negative, call the vtable+4 method (with the mesh output base + 416 when influence is inactive) and the vtable+0 method of dword_8B8F24 to fetch reflection data v84. [field:this:0x00000004, global:0x008B8F24, source:raw]
    // CALCULATION: Reflection vector math: add the a2 light-offset components a2[9]/a2[10]/a2[11] to the fetched position, normalize with 1/sqrt of the squared length, and derive the reflection-mapped texcoord pair from the view and reflection vectors. [source:raw]
    // ASSIGNMENT: Write the two reflection texcoords into (index<<6 + this[8] + 40) and (index<<6 + this[8] + 44) for all three triangle vertices. [field:this:0x00000020, source:raw]
    // CALCULATION: Advance the per-triangle loop by 36 bytes, decrement the triangle countdown, and continue while triangles remain. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int ProcessMeshVerticesWithLighting(_DWORD *this, float *lightOff) {
    //     int mesh = this[6];
    //     int v61 = *(int *)(dword_8B8F28 + 288);
    //     setup(wrapper(dword_8B8F24), v61 + 68, v79, *(int *)(mesh + 312) + 340);
    //     setup(wrapper(dword_8B8F24), mesh + 256, v80, *(int *)(mesh + 312) + 340);
    //     int infl = ((*this & 0x100) && *(int *)(mesh + 268) > 0) ? 1 : 0;
    //     if (infl) {
    //       float *w = *(float **)(mesh + 272);
    //       for (int i = 0; i < *(int *)(mesh + 268); i++) {
    //         vtable_24(dword_8B8F24, 0, *(int *)w, this[1], &v97);
    //         vtable_20(dword_8B8F24, *(int *)w, this[1], v108);
    //         w += 14;
    //         w[-9] = v108[0] + v97; w[-8] = v108[1] + v98; w[-7] = v109 + v99;
    //       }
    //     }
    //     pickMaterialColor(this[1], v61);
    //     vtable_24(dword_8B8F24, dword_8B8F28, v61, this[1], v87);
    //     vtable_20(dword_8B8F24, v61, this[1], v78);
    //     int alpha = (int)(matBright(this[1], v61));
    //     int triCount = this[4] / 3;
    //     int out = 0, byteOff = 0;
    //     do {
    //       int idxBase = *(int *)(this[6] + 292) + byteOff + 16;
    //       int i0 = *(unsigned short *)(this[5] + byteOff);
    //       int i1 = *(unsigned short *)(this[5] + byteOff + 2);
    //       int i2 = *(unsigned short *)(this[5] + byteOff + 4);
    //       byteOff += 6;
    //       if (infl) {
    //         vtable_04(dword_8B8F24, idxBase, &v81, *(int *)(this[6] + 312) + 276);
    //         for (int b = 0; b < *(int *)(this[6] + 268); b++) {
    //           accumulate influence from weight block;
    //         }
    //         packWeights(v94);
    //       }
    //       float *v = (*(int *)(this[6] + 316)) ? (float *)((i0 << 6) + this[8] + 12)
    //                                             : (float *)(48 * i0 + this[3] + 12);
    //       packNormal(v92, v87);
    //       if (infl) {
    //         float d = -(v79[0]*v[0] + v79[1]*v[1] + v79[2]*v[2]);
    //         if (d > 0) addDiffuse(v92, v78, d);
    //         if (matSpecular(this[1])) writeSpecular(v42);
    //         color = packuswb(paddsw(v92, v94), qword_8B6C20);
    //       } else {
    //         color = packuswb(v92, qword_8B6C20);
    //       }
    //       writeColor(this[8], i0 << 6, color, 24);
    //       writeColor(this[8], i1 << 6, color, 24);
    //       writeColor(this[8], i2 << 6, color, 24);
    //       _m_empty();
    //       if ((signed char)(*(char *)(this[1] + 156)) < 0) {
    //         if (!infl) vtable_04(dword_8B8F24, idxBase, &v81, *(int *)(this[6] + 312) + 416);
    //         vtable_00(dword_8B8F24, v, &v84, *(int *)(this[6] + 312) + 276);
    //         float2 refl = reflectTexcoord(v81, v82, v83, lightOff, v84, v85, v86);
    //         writeTexcoord(this[8], i0 << 6, refl, 40, 44);
    //         writeTexcoord(this[8], i1 << 6, refl, 40, 44);
    //         writeTexcoord(this[8], i2 << 6, refl, 40, 44);
    //       }
    //       out += 36;
    //     } while (--triCount);
    //     return triCount;
    //   }
    // UNRESOLVED: The precise semantic roles of this-struct offsets 0x54, 0x70, 0xB8 and 0x150 (listed as accessed) are not visible in the decompiled body; they are likely part of the mesh/render descriptor state.
    // UNRESOLVED: Globals dbl_59E430, flt_59E43C, flt_59E450 and flt_59FEC8 are listed as read but do not appear in the visible body; they are likely float constants folded into the numeric code, role unestablished.
    // UNRESOLVED: The deterministic guard on this+0xA0 (value less than 0) is interpreted here as the selector between the blended per-vertex lighting path and the simple flat pack; this interpretation is derived from the skeleton analysis, not proven.
    // UNRESOLVED: The two vtable method groups (vtable+0/+4 vs vtable+20/+24) and the exact meaning of the output buffer +24/+28/+40/+44 slot layout are inferred from use, not from a known struct contract.
}
