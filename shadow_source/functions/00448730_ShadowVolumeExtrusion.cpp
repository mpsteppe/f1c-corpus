// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448730
// Canonical corpus name: ShadowVolumeExtrusion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShadowVolumeExtrusion_00448730.c

void UnknownObject::ShadowVolumeExtrusion()
{
    // Computes a shadow-volume extrusion offset for collision geometry. Gated on the element count/type selector at *(this+0x18) being in 2..11, it walks the triangle array at *(this+0x1C), detects silhouette edges relative to the light (facing test with ratio 0.7), deduplicates them into a local edge table, then sums an angular extrusion contribution per edge. The accumulated factor is clamped and written to the offset field at *(this+0x10) relative to the base position fields *(this+0)/+4/+0xC.
    // GUARD: Enter only when the element count/type selector *(this+0x18) is within 2..11 (v1 > 1 and v1 <= 0xB). [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Zero the local v76 edge-accumulator buffer (44 iterations of 4 dwords). [source:raw]
    // LOOP: Iterate the v5 triangle entries in the array pointed to by *(this+0x1C), stepping 4 dwords per entry. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Read the triangle entry v6 fields: vertex pointers at +0x0/+0x8/+0x10, edge-partner references at +0x4/+0xC/+0x14, and the flags word at +0x18. [field:*(this+0x1C):0x00000000, field:*(this+0x1C):0x00000004, field:*(this+0x1C):0x00000008, field:*(this+0x1C):0x0000000C, field:*(this+0x1C):0x00000010, field:*(this+0x1C):0x00000014, field:*(this+0x1C):0x00000018, source:raw]
    // ASSIGNMENT: Load the three vertex records' coordinates through the vertex pointers: base components at +0/+4/+8 and the Z value at +12. [field:*(*(this+0x1C)+0x0):0x00000000, field:*(*(this+0x1C)+0x0):0x00000008, field:*(*(this+0x1C)+0x0):0x0000000C, source:raw]
    // CALCULATION: Compute the cross-product components v48/v53 from the three edge vectors and their magnitude v17 via sqrt. [source:raw]
    // GUARD: Silhouette test: accept the edge only when v17 > 0 and the ratio v53/v17 is at least 0.7 (facing the light source). [source:raw]
    // ASSIGNMENT: Resolve the edge identifier: read the per-face flag byte at +0x19; when it equals the 0xFF sentinel, use the 16-bit value at +0x1A instead. [field:*(this+0x1C):0x00000019, field:*(this+0x1C):0x0000001A, source:raw]
    // LOOP: Search the first six dwords v6[0..5] for the entry equal to the this pointer to locate which edge of the triangle is the silhouette edge. [source:raw]
    // STATE_TRANSITION: Dispatch on the found edge index through the jump table jpt_44890C and select the two silhouette-edge vertices from the edge-partner fields (+0x4/+0xC/+0x14) and the vertex pointers (+0x0/+0x8/+0x10). [global:0x00448D80, field:*(this+0x1C):0x00000004, field:*(this+0x1C):0x0000000C, field:*(this+0x1C):0x00000014, field:*(this+0x1C):0x00000000, field:*(this+0x1C):0x00000008, field:*(this+0x1C):0x00000010, source:raw]
    // LOOP: Deduplicate and accumulate the silhouette edge into the local v74/v76 tables, keyed by (edge id, edge vertex). [source:raw]
    // ASSIGNMENT: Read per-triangle auxiliary data at +0x1C (its exact role is not visible in the decompiled control flow). [field:*(this+0x1C):0x0000001C]
    // CALCULATION: For each accumulated silhouette edge, form vectors from the base position fields *(this+0)/+4/+0xC to the two edge vertices. [field:this:0x00000000, field:this:0x00000004, field:this:0x0000000C, source:raw]
    // CALCULATION: Compute cross products of the edge vectors, normalize both, derive the two angles with atan2, and accumulate the extrusion contribution v34 when the angle difference is at most 0.15. [source:raw]
    // ASSIGNMENT: Clamp and write the extrusion offset *(this+0x10): when the accumulation exceeds 0.025 store base Y + 0.025 and return; below -0.025 clamp to -0.025; otherwise store the accumulation added to base Y. [field:this:0x00000010, source:raw]
    // RETURN: Return after writing the clamped extrusion offset at *(this+0x10). [function:0x00448730, source:raw]

    // Conservative worker pseudocode:
    //   void ShadowVolumeExtrusion(ShadowVolume* sv) {
    //     if (sv->type <= 0xB && sv->type > 1) {
    //       // v76 local edge table zeroed (44 * 4 dwords)
    //       for each triangle t in sv->triangles {
    //         read vertex0 = t.v0, vertex1 = t.v1, vertex2 = t.v2;
    //         compute cross product magnitude v17 over edge vectors;
    //         if (v17 > 0 && ratio >= 0.7) {
    //           id = (t.flagByte(+0x19) == 0xFF) ? t.ushort(+0x1A) : t.flagByte;
    //           find which entry in t.dwords[0..5] equals sv;
    //           select silhouette edge pair by that index;
    //           deduplicate (id, edgeVertex) into the local edge table;
    //         }
    //       }
    //       float ext = 0;
    //       for each unique edge (A, B) {
    //         vectors from sv->pos(+0x0/+0x4/+0xC) to A and B;
    //         cross products, normalize, atan2 angles;
    //         if (|angleA - angleB| <= 0.15)
    //           ext += (interp * (v52 - v55) + v55) / invW * (1 - diff * 6.66666...) * 0.5;
    //       }
    //       if (ext > 0.025) { sv->offset(+0x10) = sv->posY + 0.025; return; }
    //       if (ext < -0.025) ext = -0.025;
    //       sv->offset(+0x10) = ext + sv->posY;
    //     }
    //   }
    // UNRESOLVED: The double globals dbl_59E420, dbl_59E430, dbl_59E830, dbl_59E880, dbl_59EC60, dbl_59EF18, dbl_59EF20 and dbl_59EF28 are read by this function but do not surface as named operands in the Hex-Rays text (materialized FP constants such as 0.7, 0.15, 0.025, 6.66666...); their exact values and per-step roles are not evidenced here.
    // UNRESOLVED: The triangle entry at +0x1C is read but its role is not visible in the decompiled control flow.
    // UNRESOLVED: The meaning of the element count/type selector at *(this+0x18) and of the edge-partner fields is inferred from the silhouette algorithm and remains DERIVED.
    // UNRESOLVED: Whether *(this+0x10) is written as a double (via the +0x10 long-double store) or paired with surrounding data is unresolved.
}
