// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054D080
// Canonical corpus name: sub_54D080
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54D080_0054d080.c

void UnknownObject::ComputeTriangleMeshBounds()
{
    // For each triangle in a mesh, computes the triangle centroid, the bounding sphere radius (the square root of the maximum squared distance from the centroid to any of the triangle's three vertices), and a dominant normal axis code (0-5 selecting axis and sign) derived from a per-vertex normal lookup. Handles both 64-byte and 48-byte vertex strides selected by the MMX flag. Writes the centroid to triangle-entry +16/+20/+24, the radius to +28, and the axis code to +6. Returns the number of triangles processed.
    // ASSIGNMENT: Initialize result and the triangle counter to 0 before the count guard. [source:raw]
    // GUARD: Guard: the triangle count at this+0x120 must be greater than 0; otherwise return 0 immediately with no triangles processed. [guard:0, field:this:0x00000120, source:raw]
    // LOOP: Iterate over triangle entries in the array at this+0x124; each entry is 36 bytes and holds three uint16 vertex indices and a pointer to per-triangle data. [field:this:0x00000124, source:raw]
    // CALCULATION: Read the three vertex indices (uint16 at entry +0/+2/+4) and resolve the vertex-position array base through the per-triangle data pointer (+12). [source:raw]
    // CALCULATION: Branch on the MMX flag: bit 0x800000 of this+0x14 (tested via global 0x00800000) selects 64-byte vertex stride, otherwise 48-byte stride. [field:this:0x00000014, global:0x00800000, source:raw]
    // CALCULATION: Compute the triangle centroid as the sum of the three vertex positions scaled by 0.33333334 and store it at triangle-entry +16/+20/+24. [source:raw]
    // CALCULATION: Compute the bounding sphere radius as the square root of the maximum squared distance from the centroid to the three vertices; store it at triangle-entry +28. [source:raw]
    // CALCULATION: Look up a per-vertex normal in the array at this+0x12C using a 16-byte stride indexed through the triangle's data field, and compute a dot product of that normal against the vertex position. [field:this:0x0000012C, source:raw]
    // CALCULATION: Select the dominant normal axis by comparing absolute component magnitudes; encode axis and sign into a code in range 0-5. [source:raw]
    // ASSIGNMENT: Store the dominant-axis code as a uint16 at triangle-entry +6. [source:raw]
    // RETURN: Return the number of triangles processed (counter advanced per triangle, bounded by the count at this+0x120). [field:this:0x00000120, source:raw]

    // Conservative worker pseudocode:
    //   int sub_54D080(void *self) {
    //     int processed = 0;
    //     if (triangleCount(self) > 0) {
    //       for (off = 0; off < triangleCount(self); off += 36) {
    //         entry = triangleArray(self) + off;
    //         i0 = entry.word[0]; i1 = entry.word[1]; i2 = entry.word[2];
    //         verts = resolveVertexBase(entry);
    //         stride = (flags(self) & 0x800000) ? 64 : 48;
    //         // Centroid.
    //         cx = (v0.x + v1.x + v2.x) * 0.33333334;
    //         cy = (v0.y + v1.y + v2.y) * 0.33333334;
    //         cz = (v0.z + v1.z + v2.z) * 0.33333334;
    //         entry.float[4] = cx; entry.float[5] = cy; entry.float[6] = cz;
    //         // Bounding sphere radius = max distance from centroid.
    //         r2 = max(|v_i - c|^2 for i in 0..2);
    //         entry.float[7] = sqrt(r2);
    //         // Dominant normal axis from the per-vertex normal array (16-byte stride).
    //         n = normalArray(self) + 16 * entry.dword[3];
    //         code = dominantAxisCode(n);
    //         entry.word[3] = code;
    //         processed++;
    //       }
    //     }
    //     return processed;
    //   }
    // UNRESOLVED: Purpose of the unused second parameter a2 (not referenced in the decompiled body).
    // UNRESOLVED: Exact semantics of the normal dot product against the vertex position (the decompiled text shows the accumulation but not its classification meaning).
    // UNRESOLVED: Use of globals 0x0059E440 and 0x0059E98C is not visible in the raw decompiled text; they likely feed folded float literals in the per-triangle comparisons.
}
