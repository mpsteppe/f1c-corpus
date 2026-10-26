// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055E320
// Canonical corpus name: sub_55E320
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55E320_0055e320.c

void UnknownObject::TransformMeshVerticesWithLighting()
{
    // Per-vertex 3D mesh transform, lighting and color-pack pipeline. Reads the scene graph node pointer from this+0x18 and the source vertex buffer from this+0x0C, selects a 12- or 16-byte vertex stride based on a flags test against global unk_800000, invokes world/screen transform helpers through the transform vtable at global dword_8B8F24 (outputs v67/v66), optionally relocates dynamic vertices when this+0x0 render flag bit 0x100 is set and the node vertex count is positive, computes per-vertex distance-weighted contributions from the source-mesh vertex fields, then writes packed lighting colors (via MMX packuswb with qword_8B6C20) to this+0x20 output vertices at +24/+28 and specular channels at +40/+44. Specular components are scaled by TableLookupScale against the per-vertex object's lookup table at *(this+0x04)+180.
    // ASSIGNMENT: v3 = this[6] reads the scene graph node pointer; v50 = v3 + 256 derives a scene-space address used by the transform calls [field:this:0x00000018, source:raw]
    // GUARD: Stride selection: if (unk_800000 & *(v3 + 20)) == 0 the vertex source v6 = v5 + 12 with stride 12, otherwise v6 = v5 + 28 with stride 16; v5 is the source vertex buffer pointer this[3] [global:0x00800000, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: v7 = *(dword_8B8F28 + 288) and v44 = *(v3 + 312) + 340 load transform/lighting parameters; v8 = *(void**)dword_8B8F24 is the transform vtable base [global:0x008B8F24, global:0x008B8F28, field:this:0x00000018, source:raw]
    // CALL: Two initial transform calls through the vtable at dword_8B8F24 (entry v8 = *(dword_8B8F24), then vtable+0) fill v67 (position) and v66 (direction/normal) for the vertex [global:0x008B8F24, source:raw]
    // LOOP: Dynamic vertex relocation: guarded by (v13 & 0x100) != 0 on the flags at this+0 and node vertex count > 0; iterates v10 = *(float**)(v9 + 272) with count *(v9 + 268) and stride 14, calling vtable+24 and vtable+20 on dword_8B8F24 with this[1] and accumulating the offsets into the vertex list [field:this:0x00000000, field:this:0x00000004, field:this:0x00000018, global:0x008B8F24, source:raw]
    // ASSIGNMENT: Reads the source mesh vertex data: source mesh pointer at this+0x128, its vertex data pointer at *(*(this+0x128)) + 0, and transformed data words at +0x10/+0x14/+0x18/+0x1C; vertex position at +0x38/+0x3C/+0x40 and radius/flag word at +0x50 are consumed by the per-vertex distance loop [field:this:0x00000128, field:*(this+0x128):0x00000000, field:*(this+0x128):0x00000010, field:*(this+0x128):0x00000014, field:*(this+0x128):0x00000018, field:*(this+0x128):0x0000001C, field:*(*(this+0x128)+0x0):0x00000000, field:*(*(this+0x128)+0x0):0x00000038, field:*(*(this+0x128)+0x0):0x0000003C, field:*(*(this+0x128)+0x0):0x00000040, field:*(*(this+0x128)+0x0):0x00000050, source:raw]
    // CALCULATION: v13 = *(this[1] + 156) is the per-vertex flag word; v95 = v13 & 0x40 selects color scaling, and later v96 = v13 & 0x80 selects the specular path [field:this:0x00000004, source:raw]
    // ASSIGNMENT: When the 0x40 flag is set, the vertex color components at this[1]+100/+104/+108 are either read directly or scaled by *(v7 + 36); when the 0x4000 flag is set the alpha component *(this[1]+80) is scaled by *(v7 + 36) * 255.0, otherwise by 255.0 alone [field:this:0x00000004, source:raw]
    // CALL: Lighting-space calls: vtable+24 and vtable+20 on dword_8B8F24 receive dword_8B8F28, the float parameter and this[1], producing v70 (specular) and v69 (lighting direction) [global:0x008B8F24, global:0x008B8F28, field:this:0x00000004, source:raw]
    // CALCULATION: MMX color packing: _m_packuswb(v76, qword_8B6C20) packs the per-component colors (v70/v71/v72 and the truncated v52) into the base packed color v53 [global:0x008B6C20, source:raw]
    // LOOP: Per-vertex output loop bounded by the vertex count this[2]; output pointer advances by 64 bytes per vertex (v18 += 64) and the source advances by v98 = 4 * stride [field:this:0x00000008, source:raw]
    // CALCULATION: Per-vertex distance weighting: when dynamic relocation (v79) is active the vertex list is re-read from the node (count *(v19 + 268), list *(v19 + 272)); for each entry the distance to the target is accumulated from vertex positions and radius (+56/+60/+64 and +80 relative to the vertex object), attenuated as 1 - sqrt(distsq) * v20[4] unless flag 0x100 on the vertex object forces direct weighting, then weighted by v20[5..7] [field:this:0x00000018, source:raw]
    // CALCULATION: Backface/depth test: v31 = -(v67[0]*x + v67[1]*y + v67[2]*z) over the transformed vertex; if v31 <= 0 the precomputed color v53 is written to output+24, otherwise the lit color v69 * v31 + v70 is packed and written to output+24 [field:this:0x00000020, global:0x008B6C20, source:raw]
    // CALCULATION: Specular lighting: when flag 0x40 (v95) is set and the dot product v32 of v66 with the vertex direction is positive, TableLookupScale(*(int*)(this[1]+180), v47) scales the components v85/v81/v86, packed and written to output+28; otherwise output+28 is cleared [callee:0x0053AC40, field:this:0x00000004, field:this:0x00000020, source:raw]
    // CALCULATION: Specular reflection channels: when flag 0x80 (v96) is set the vertex is transformed through vtable+0 on dword_8B8F24 into v63, then a normalized reflection vector is computed from v60/v61/v62 plus a2[9..11] and written as 0.5-scaled channels to output+40 and output+44 [field:this:0x00000020, global:0x008B8F24, source:raw]
    // RETURN: Returns result = last processed vertex index (v77 + 1) after the per-vertex loop, or v51 when no vertices were processed [source:raw]
    // CALL: Shared helper reached from UIElementBitfieldStateSetter (0054bdc0), MeshBoundingBoxComputation (0054d9f0) and sub_55D720 (0055d720) [caller:0x0054BDC0, caller:0x0054D9F0, caller:0x0055D720, source:raw]

    // Conservative worker pseudocode:
    //   v3 = this[6]; v50 = v3 + 256;
    //   stride = (unk_800000 & *(v3 + 20)) == 0 ? (v6 = this[3] + 12, 12) : (v6 = this[3] + 28, 16);
    //   v7 = *(dword_8B8F28 + 288); v44 = *(v3 + 312) + 340; v8 = *(void**)dword_8B8F24;
    //   (*v8)(dword_8B8F24, v7 + 68, v67, v44); (vtable+0)(dword_8B8F24, v50, v66, v44);
    //   if ((this[0] & 0x100) && *(this[6] + 268) > 0) relocate_dynamic_vertices();
    //   v13 = *(this[1] + 156); v95 = v13 & 0x40; v96 = v13 & 0x80;
    //   (vtable+24)(dword_8B8F24, dword_8B8F28, v7, this[1], &v70); (vtable+20)(dword_8B8F24, v7, this[1], v69);
    //   v52 = (v13 & 0x4000) ? *(this[1] + 80) * *(v7 + 36) * 255.0 : *(this[1] + 80) * 255.0;
    //   v53 = packuswb(v76, qword_8B6C20);
    //   for each vertex (count this[2], output stride 64):
    //     if (v79) accumulate distance-weighted colors from vertex fields;
    //     v31 = -(dot(v67, vertex));
    //     output+24 = (v31 <= 0) ? v53 : packuswb(lit(v69 * v31 + v70), qword_8B6C20);
    //     if (v95 && dot(v66, vertex) > 0) output+28 = packuswb(TableLookupScale(*(this[1]+180), dot)); else output+28 = 0;
    //     if (v96) output+40/44 = reflection channels from v63 and a2[9..11];
    //   return last_vertex_index;
    // UNRESOLVED: The static-pipeline guard this+0x124 > 0 (guard:0) is not visible as an explicit branch in the raw decompilation; its role is unresolved.
    // UNRESOLVED: Fields this+0x2C/+0x54/+0x68/+0x6C/+0x70/+0xA0/+0xB8/+0x150 are listed in packet field evidence but do not appear as explicit operands in the raw text; purposes unresolved.
    // UNRESOLVED: Globals dbl_59E430, flt_59E43C, flt_59E450, flt_59FEC8 are referenced by extracted facts but not named in the raw source text; roles unresolved.
    // UNRESOLVED: The second 64-bit half of the MMX operand qword_8B6C20 used by packuswb is unknown.
    // UNRESOLVED: The destination meaning of the output +40/+44 specular channels (surface brightness vs. shininess) is not confirmed.
}
