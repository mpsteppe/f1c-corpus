// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054D520
// Canonical corpus name: F_3DBoundingBoxExtentsComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DBoundingBoxExtentsComputation_0054d520.c

void UnknownObject::F_3DBoundingBoxExtentsComputation()
{
    // Computes the 3D axis-aligned bounding box for an object's vertex buffers. Iterates the buffer-entry list at this+0x11C (entry count this+0x118), and for each entry scans its vertices accumulating per-axis min/max extents (X, Y, Z), choosing a 12- or 16-byte vertex stride from a flag at this+0x14. Writes the 24 box-corner coordinates (this+0x1C .. this+0x78), sets the has-3D-extents bit (0x10) of the flag word at this+0x14 (clearing it on any degenerate axis), optionally writes the box center (this+0xDC/0xE0/0xE4) when a2 bit 0 is set, and stores the bounding-sphere radius at this+0x18. Returns the updated flag word.
    // CALL: Invoked on frame paths by GlobalVectorOffsetUpdate (0x0040E1F0), PhysicsAudioVectorUpdate (0x004E2AD0), and VertexBufferTransform (0x0054C6C0) to refresh object bounding boxes. [caller:0x0040E1F0, caller:0x004E2AD0, caller:0x0054C6C0, function:0x0054D520, source:raw]
    // ASSIGNMENT: Initialize the six extent accumulators to the sentinel extrema: max values (v11, v13, v2) from -1.0e12 and min values (v12, v14, v15) from +1.0e12, reading the sentinel float globals flt_59E450 (0x0059E450) and flt_5B8984 (0x005B8984). [global:0x0059E450, global:0x005B8984, source:raw]
    // GUARD: Guard the whole scan on the vertex-buffer entry count at this+0x118 being greater than 0; when zero or negative, all extents stay at their sentinels. [field:this:0x00000118, guard:1, source:raw]
    // LOOP: Outer loop over vertex-buffer entries: walk the entry list at *(this+0x11C) with 16-byte entry descriptors until the entry count at this+0x118 is exhausted. [field:this:0x0000011C, source:raw]
    // ASSIGNMENT: Read the current entry descriptor: vertex count at *(entry+0x8) and the vertex position pointer at *(entry+0xC) (entry base = *(this+0x11C)). [field:*(this+0x11C):0x00000008, field:*(this+0x11C):0x0000000C, source:raw]
    // GUARD: Skip the entry when its vertex count at *(entry+0x8) is not greater than 0. [field:*(this+0x11C):0x00000008, guard:0, source:raw]
    // LOOP: Inner loop over the entry's vertices, advancing one vertex per iteration until the entry vertex count is exhausted. [source:raw]
    // GUARD: Select the vertex stride from the flag at this+0x14: when (flag & unk_800000 (0x00800000)) is zero, read packed 12-byte vertices (v4 base); otherwise read 16-byte-strided vertices (v5). [field:this:0x00000014, global:0x00800000, source:raw]
    // CALCULATION: Accumulate per-axis extents over the scanned vertices: min/max X (v12/v11), min/max Y (v14/v13), and min/max Z (v15/v2). [source:raw]
    // ASSIGNMENT: Write the 8 box corners from the extent values: min-X (v12) to this+0x34, +0x40, +0x64, +0x70. [field:this:0x00000034, field:this:0x00000040, field:this:0x00000064, field:this:0x00000070, source:raw]
    // ASSIGNMENT: Write max-X (v11) to this+0x1C, +0x28, +0x4C, +0x58. [field:this:0x0000001C, field:this:0x00000028, field:this:0x0000004C, field:this:0x00000058, source:raw]
    // ASSIGNMENT: Write min-Y (v14) to this+0x20, +0x2C, +0x38, +0x44. [field:this:0x00000020, field:this:0x0000002C, field:this:0x00000038, field:this:0x00000044, source:raw]
    // ASSIGNMENT: Write max-Y (v13) to this+0x50, +0x5C, +0x68, +0x74. [field:this:0x00000050, field:this:0x0000005C, field:this:0x00000068, field:this:0x00000074, source:raw]
    // ASSIGNMENT: Write min-Z (v15) to this+0x24, +0x48, +0x54, +0x78. [field:this:0x00000024, field:this:0x00000048, field:this:0x00000054, field:this:0x00000078, source:raw]
    // ASSIGNMENT: Write max-Z (v2) to this+0x30, +0x3C, +0x60, +0x6C. [field:this:0x00000030, field:this:0x0000003C, field:this:0x00000060, field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Update the flag word at this+0x14: clear bit 0x10 (&= 0xFFFFFFEF) when any axis is degenerate (min == max: v12 == v11, v14 == v13, or v15 == v2); otherwise set it (|= 0x10) to mark the box as having valid 3D extents. [field:this:0x00000014, source:raw]
    // GUARD: When the low bit of a2 is set, compute the box center from the min/max extents and write it to this+0xDC, +0xE0, +0xE4. [field:this:0x000000DC, field:this:0x000000E0, field:this:0x000000E4, source:raw]
    // CALCULATION: Compute the bounding-sphere radius from the half extents sqrt((maxZ - minZ)*0.5)^2 + halfY^2 + halfX^2) and store it at this+0x18. [field:this:0x00000018, source:raw]
    // RETURN: Return the updated flag word at this+0x14 as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_54D520(int this, float a2) {
    //     float maxX = -1.0e12f, maxY = -1.0e12f, maxZ = -1.0e12f;
    //     float minX = 1.0e12f, minY = 1.0e12f, minZ = 1.0e12f;
    //     if (*(int *)(this + 0x118) > 0) {
    //       int *entry = (int *)(*(int *)(this + 0x11C) + 8);
    //       int entryCount = *(int *)(this + 0x118);
    //       do {
    //         if (*entry > 0) {
    //           float *base12 = (float *)entry[1];
    //           float *base16 = base12;
    //           int count = *entry;
    //           do {
    //             float *v = (*(unsigned int *)(this + 0x14) & 0x800000) ? base16 : base12;
    //             if (v[0] < minX) minX = v[0]; if (v[0] > maxX) maxX = v[0];
    //             if (v[1] < minY) minY = v[1]; if (v[1] > maxY) maxY = v[1];
    //             if (v[2] < minZ) minZ = v[2]; if (v[2] > maxZ) maxZ = v[2];
    //             base16 += 4;
    //             base12 += 3;
    //           } while (--count);
    //         }
    //         entry += 4;
    //       } while (--entryCount);
    //     }
    //     *(float *)(this + 0x30) = maxZ; *(float *)(this + 0x3C) = maxZ;
    //     *(float *)(this + 0x60) = maxZ; *(float *)(this + 0x6C) = maxZ;
    //     *(float *)(this + 0x28) = maxX; *(float *)(this + 0x1C) = maxX;
    //     *(float *)(this + 0x58) = maxX; *(float *)(this + 0x4C) = maxX;
    //     *(float *)(this + 0x20) = minY; *(float *)(this + 0x2C) = minY;
    //     *(float *)(this + 0x38) = minY; *(float *)(this + 0x44) = minY;
    //     *(float *)(this + 0x34) = minX; *(float *)(this + 0x40) = minX;
    //     *(float *)(this + 0x64) = minX; *(float *)(this + 0x70) = minX;
    //     *(float *)(this + 0x50) = maxY; *(float *)(this + 0x5C) = maxY;
    //     *(float *)(this + 0x68) = maxY; *(float *)(this + 0x74) = maxY;
    //     *(float *)(this + 0x48) = minZ; *(float *)(this + 0x24) = minZ;
    //     *(float *)(this + 0x78) = minZ; *(float *)(this + 0x54) = minZ;
    //     int flags = *(int *)(this + 0x14);
    //     if (minX == maxX || minY == maxY || minZ == maxZ)
    //       flags &= 0xFFFFFFEF;
    //     else
    //       flags |= 0x10;
    //     *(int *)(this + 0x14) = flags;
    //     if (((int)a2 & 1) != 0) {
    //       *(float *)(this + 0xDC) = (maxX + minX) * 0.5f;
    //       *(float *)(this + 0xE0) = (maxY + minY) * 0.5f;
    //       *(float *)(this + 0xE4) = (maxZ + minZ) * 0.5f;
    //     }
    //     float halfX = (maxX - minX) * 0.5f;
    //     float halfY = (maxY - minY) * 0.5f;
    //     float halfZ = (maxZ - minZ) * 0.5f;
    //     *(float *)(this + 0x18) = sqrtf(halfX * halfX + halfY * halfY + halfZ * halfZ);
    //     return flags;
    //   }
    // UNRESOLVED: Fields *(this+0x11C):0x10 and *(this+0x11C):0x14 are listed in the packet but are not directly accessed by this function; their role is unknown.
    // UNRESOLVED: The exact corner-vertex mapping (which corner each this+0x1C..0x78 offset represents) is not asserted; only the extent value written to each offset is grounded.
    // UNRESOLVED: The meaning of the 0x800000 flag bit at this+0x14 (stride select) beyond the stride choice, and of the sentinel globals flt_59E450/flt_5B8984 beyond providing +/-1e12, is not grounded.
    // UNRESOLVED: The low bit of a2 selects the optional center computation; the caller's intent for that argument is not documented here.
}
