// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044B910
// Canonical corpus name: BoundingBoxComputationFromTriangles
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundingBoxComputationFromTriangles_0044b910.c

void UnknownObject::ComputeBoundingBoxFromTriangles()
{
    // Scans triangle strip vertex arrays from a2 to accumulate the X and Z (horizontal-plane) extents, then stores the axis center as the midpoint of each range and an inverse half-extent scale factor as doubles into this. When an axis range is degenerate (zero width) the corresponding scale double is written as zero instead of a reciprocal.
    // GUARD: Only scan when the count a2[0] is positive. [source:raw]
    // LOOP: Outer loop over the strip count from a2[0], with an inner loop of 3 vertices per strip advancing two pointer slots per vertex. [source:raw]
    // CALCULATION: Tighten the running X range using each vertex X value at data[0]. [source:raw]
    // CALCULATION: Tighten the running Z range using each vertex Z value at data[3]. [source:raw]
    // CALCULATION: Write the X center (midpoint of the X range) as a double at this+0x8 and the X scale as a double at this+0x10, zeroing the scale via its two dwords at this+0x10/this+0x14 when the X range is zero. [field:this:0x00000008, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALCULATION: Write the Z center (midpoint of the Z range) as a double at this+0x18 and the Z scale as a double at this+0x20, zeroing the scale via its two dwords at this+0x20/this+0x24 when the Z range is zero. [field:this:0x00000018, field:this:0x00000020, field:this:0x00000024, source:raw]

    // Conservative worker pseudocode:
    //   void ComputeBoundingBoxFromTriangles(this, int* a2) {
    //     float minX = +FLT_MAX, maxX = -FLT_MAX;
    //     float minZ = +FLT_MAX, maxZ = -FLT_MAX;
    //     if (a2[0] > 0) {
    //       for (int strip = a2[0]; strip; --strip) {
    //         for (int v = 3; v; --v, verts += 2) {
    //           float* p = *verts;
    //           minX = min(minX, p[0]); maxX = max(maxX, p[0]);
    //           minZ = min(minZ, p[3]); maxZ = max(maxZ, p[3]);
    //         }
    //       }
    //     }
    //     double spanX = (maxX - minX) * 0.03125;
    //     double spanZ = (maxZ - minZ) * 0.03125;
    //     *(double*)(this + 0x8)  = 0.5 * spanX + minX;
    //     *(double*)(this + 0x18) = spanZ * 0.5 + minZ;
    //     if (spanX == 0.0) { *(int*)(this + 0x10) = *(int*)(this + 0x14) = 0; }
    //     else               { *(double*)(this + 0x10) = 1.0 / spanX; }
    //     if (spanZ == 0.0) { *(int*)(this + 0x20) = *(int*)(this + 0x24) = 0; }
    //     else               { *(double*)(this + 0x20) = 1.0 / spanZ; }
    //   }
    // UNRESOLVED: The five floating-point constant globals (0x0059E420, 0x0059E430, 0x0059E880, 0x0059EF30, 0x0059EF48) are read by this function; their exact values and mapping to the sentinel and scale constants in the decompiled body are not present in the packet.
    // UNRESOLVED: The exact layout of a2 (strip count, vertex pointer table, per-vertex stride) is decompiler-interpreted.
}
