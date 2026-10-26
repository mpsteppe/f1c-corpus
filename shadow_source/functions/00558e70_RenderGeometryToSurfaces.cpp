// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00558E70
// Canonical corpus name: sub_558E70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_558E70_00558e70.c

void UnknownObject::RenderGeometryToSurfaces()
{
    // Renders a linked list of geometry mesh blocks onto one or more locked texture surfaces. Builds an Euler rotation matrix from an object transform (selecting pitch-only or full 3-axis based on flag bits in this+0x20), clears per-surface vertex/index allocation counters, walks each mesh block's child nodes copying transform/color state, packs per-vertex color words, then unlocks each surface and submits it with its accumulated vertex and index counts.
    // GUARD: If signed byte flag at this+0x20 is negative, the render-to-texture pass is disabled (surface invalidated/locked): skip geometry generation. [field:this:0x00000020, guard:0]
    // CALL: In the disabled branch, when *(this+0x30) (texture block pointer) is non-null, unlock/release the surface via TextureSurfaceUnlockRelease(this, 0) and submit sub_55CF50(a2, *(this+0x50) descriptor array, stride_x = *(this+0x30)**(this+0x24), stride_y = *(this+0x30)**(this+0x28)). [callee:0x00558D80, callee:0x0055CF50, field:this:0x00000030, field:this:0x00000050, field:this:0x00000024, field:this:0x00000028]
    // GUARD: Active geometry path is taken when this+0x20 >= 0 and *(this+0x30) is non-null. [field:this:0x00000020, field:this:0x00000030]
    // CALL: Initialize the 3x3 rotation matrix scratch v43 with F_10FloatStructInitializer. [callee:0x0053B130]
    // GUARD: If dword at this+0x20 has bit 0x20 set, use pitch-only rotation: F_3FieldGetter(a3, &v32, &v27, &v31), negate v27, then EulerAngleToRotationMatrix(v43, 0.0, -v27, 0.0). [field:this:0x00000020, callee:0x00542490, callee:0x0053B240]
    // GUARD: Else if dword at this+0x20 has bit 0x10 set, use full 3-axis rotation: F_3FieldGetter(a3, &v32, &v27, &v31), negate all three components, then EulerAngleToRotationMatrix(v43, -v32, -v27, -v31). [field:this:0x00000020, callee:0x00542490, callee:0x0053B240]
    // LOOP: For each of the *(this+0x4C) surfaces: reset the vertex count at *(this+0x44)+4*i and index count at *(this+0x48)+4*i to 0, then call TextureAllocationWithFormatSizeFlags(this, i). [guard:1, field:this:0x0000004C, field:this:0x00000044, field:this:0x00000048, callee:0x00558D10]
    // CALL: Set v33/v6 to the first mesh block *(this+0x38), traverse with LinkedListTraversal(a2, 0), and read a per-vertex scalar factor via FieldGetterByIndex(2, &v36). [field:this:0x00000038, callee:0x005457C0, callee:0x0055D560]
    // LOOP: Walk the mesh block linked list: v6 follows the next pointer *(v6+0x7C); the walk ends when the next pointer is null. [field:*(this+0x38):0x0000007C]
    // GUARD: If this[32] AND 0x30 is non-zero, copy the 48-byte v44 block into v6+0x38 (v6+14 floats), then copy three fields out of and back into v6+0x10 via ThreeFieldAccessor and MultiFieldSetter. [field:this:0x00000020, callee:0x0053B170, callee:0x0053B200]
    // GUARD: If *(v6+0x0) has bit 0x4000 set, read three fields from v6+0x10 via TripleFieldGetter_b1d0 and pass them to sub_53B330(v6+0x10, ...). [field:*(this+0x38):0x00000000, callee:0x0053B1D0, callee:0x0053B330]
    // CALL: Apply conditional scaling to v6+0x10 with ConditionalScaleApply(v6+4). [callee:0x0053B350]
    // LOOP: For each surface descriptor at *(this+0x50) (64-byte stride), iterate its vertex stream: for each vertex call the D3D wrapper function pointer at (*(dword_8B8F24)+4), storing packed color at v13+32 and lighting/packed words at v13+36 and v13+24 (v13-40); the loop bound is the surface vertex count at descriptor+8. [field:this:0x00000050, global:0x008B8F24, field:*(this+0x38):0x0000000C]
    // CALCULATION: Build the packed per-vertex color word v17 from v34 (color word at *(v6+0xC)) and v15 (vertex color byte): v37 = (double)HIBYTE(v34) * v36, truncate to __int16 v41, and combine ((v41<<8) + byte products) into a 32-bit color. [field:*(this+0x38):0x0000000C]
    // ASSIGNMENT: After each surface's vertex loop, accumulate its vertex count (descriptor+8) into *(this+0x44)+4*i and its index count (descriptor+16) into *(this+0x48)+4*i. [field:this:0x00000044, field:this:0x00000048, field:this:0x00000050]
    // ASSIGNMENT: Advance to the next mesh block: v33 = *(v6+0x7C); break out of the list walk when it is null. [field:*(this+0x38):0x0000007C]
    // LOOP: For each of the *(this+0x4C) surfaces: unlock/release with TextureSurfaceUnlockRelease(this, i), then submit sub_55CF50(a2, descriptor = *(this+0x50)+64*i, accumulated vertex count at *(this+0x44)+4*i, accumulated index count at *(this+0x48)+4*i). [callee:0x00558D80, callee:0x0055CF50, field:this:0x00000050, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C]
    // CALL: Finish the pass with EmptyStub_b160(). [callee:0x0053B160]

    // Conservative worker pseudocode:
    //   if (this[0x20] < 0) {
    //       if (*(this+0x30)) { TextureSurfaceUnlockRelease(this, 0); sub_55CF50(a2, *(this+0x50), *(this+0x30)**(this+0x24), *(this+0x30)**(this+0x28)); }
    //   } else if (*(this+0x30)) {
    //       F_10FloatStructInitializer(v43);
    //       if (*(this+0x20) & 0x20) { F_3FieldGetter(a3,&v32,&v27,&v31); EulerAngleToRotationMatrix(v43, 0.0, -v27, 0.0); }
    //       else if (*(this+0x20) & 0x10) { F_3FieldGetter(a3,&v32,&v27,&v31); EulerAngleToRotationMatrix(v43, -v32, -v27, -v31); }
    //       for (i = 0; i < *(this+0x4C); ++i) { *(this+0x44)+4*i = 0; *(this+0x48)+4*i = 0; TextureAllocationWithFormatSizeFlags(this, i); }
    //       v6 = *(this+0x38); LinkedListTraversal(a2, 0); FieldGetterByIndex(2, &v36);
    //       while (v6) {
    //           if ((this[0x20] & 0x30) != 0) { qmemcpy(v6+14, v44, 0x30); ThreeFieldAccessor(v6+4,&v29,&v30,&v28); MultiFieldSetter(v6+4,v29,v30,v28); }
    //           if ((*(v6) & 0x4000) != 0) { TripleFieldGetter_b1d0(v6+4,&v29,&v30,&v28); sub_53B330(v6+4,v29,v30,v28); }
    //           ConditionalScaleApply(v6+4);
    //           for (s = 0; s < *(this+0x4C); ++s) {
    //               desc = *(this+0x50) + 64*s;
    //               if (*(desc+8) > 0)
    //                   for (n = 0; n < *(desc+8); ++n) {
    //                       (*(*(dword_8B8F24)+4))(dword_8B8F24, v11, v13, v40);
    //                       *(v13+32) = v11[7]; *(v13+36) = v11[8];
    //                       v13 += 64; v11 += 9;
    //                   }
    //               *(this+0x44)+4*s += *(desc+8); *(this+0x48)+4*s += *(desc+16);
    //           }
    //           v6 = *(v6+0x7C);
    //       }
    //       for (s = 0; s < *(this+0x4C); ++s) { TextureSurfaceUnlockRelease(this, s); sub_55CF50(a2, *(this+0x50)+64*s, *(this+0x44)+4*s, *(this+0x48)+4*s); }
    //       EmptyStub_b160();
    //   }
    // UNRESOLVED: dword_8B78A0 is listed as read evidence but does not appear in the raw decompiled text; its role is unknown.
    // UNRESOLVED: The exact packing formula for the per-vertex color word and the semantic meaning of v36 are only partially recovered.
    // UNRESOLVED: The source and role of the 48-byte v44 block copied into each mesh node is not established from this function alone.
}
