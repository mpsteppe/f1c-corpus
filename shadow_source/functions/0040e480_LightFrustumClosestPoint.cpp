// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E480
// Canonical corpus name: LightFrustumClosestPoint
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LightFrustumClosestPoint_0040e480.c

void UnknownObject::LightFrustumClosestPoint()
{
    // Computes the bounding box of some scene data via BoundingBoxComputation, derives its center and half-diagonal radius, then performs a 5x5x5 grid search across the box volume. Each grid sample point keeps the maximum squared distance to any element of a packed array (fetched by index 0); if that maximum is below the running radius the sample becomes the new closest point. Writes the resulting closest point to the output vector a2 and the minimized radius to *a3.
    // CALL: Compute the bounding box into six consecutive locals (v23..v28 = min/max X/Y/Z) via BoundingBoxComputation. [callee:0x004DD550, source:raw]
    // CALCULATION: Compute signed extent vectors from the box corners: X = min.x - max.x, Y = min.y - max.y, Z = min.z - max.z. [source:raw]
    // CALL: Fetch the packed-array handle for index 0 via LinkedListIndexedAccessor_c230. [callee:0x0054C230, source:raw]
    // CALL: Query the packed-array element count via PackedArrayTotalSize. [callee:0x0054E100, source:raw]
    // CALCULATION: Compute the box center as (min + max) * 0.5 on each axis and write it to the output closest-point vector a2 (X/Y/Z). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Compute the initial search radius as half the box diagonal (0.5 * sqrt(sum of squared extents)) and store it in *a3. [source:raw]
    // LOOP: Nested 5x5x5 grid search: sample points are placed at the center plus (index - 2) * 0.02 times the box extent on each axis. [source:raw]
    // GUARD: Skip the per-element loop entirely when the packed-array element count is zero. [source:raw]
    // CALL: Fetch element i of the packed array via PackedArrayIndexLookup and read its three consecutive float components. [callee:0x0054E120, source:raw]
    // CALCULATION: For each element compute the squared distance from the current grid sample point and keep the maximum over all elements. [source:raw]
    // STATE_TRANSITION: If the maximum element distance at the sample point is below the current radius, adopt the sample as the new closest point (a2 X/Y/Z) and shrink the radius in *a3. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // RETURN: Return the final loop counter after the grid search completes. [source:raw]

    // Conservative worker pseudocode:
    //   int LightFrustumClosestPoint(int a1, float* outCenter, float* outRadius) {
    //     float bmin[3], bmax[3];
    //     BoundingBoxComputation(&bmin);
    //     int list = LinkedListIndexedAccessor_c230(0);
    //     int count = PackedArrayTotalSize(list);
    //     outCenter[0] = (bmin[0] + bmax[0]) * 0.5f;
    //     outCenter[1] = (bmin[1] + bmax[1]) * 0.5f;
    //     outCenter[2] = (bmin[2] + bmax[2]) * 0.5f;
    //     float dx = bmin[0] - bmax[0];
    //     float dy = bmin[1] - bmax[1];
    //     float dz = bmin[2] - bmax[2];
    //     *outRadius = sqrtf(dx*dx + dy*dy + dz*dz) * 0.5f;
    //     int i, j, k;
    //     for (i = 0; i < 5; ++i)
    //       for (j = 0; j < 5; ++j)
    //         for (k = 0; k < 5; ++k) {
    //           float p[3];
    //           p[0] = (float)(i - 2) * 0.02f * (bmin[0] - bmax[0]) + outCenter[0];
    //           p[1] = (float)(j - 2) * 0.02f * (bmin[1] - bmax[1]) + outCenter[1];
    //           p[2] = (float)(k - 2) * 0.02f * (bmin[2] - bmax[2]) + outCenter[2];
    //           float best = 0.0f;
    //           if (count > 0)
    //             for (int n = 0; n < count; ++n) {
    //               const float* e = PackedArrayIndexLookup(n);
    //               float d2 = (e[0]-p[0])*(e[0]-p[0]) + (e[1]-p[1])*(e[1]-p[1]) + (e[2]-p[2])*(e[2]-p[2]);
    //               if (d2 > best) best = d2;
    //             }
    //           float r = sqrtf(best);
    //           if (r < *outRadius) { outCenter[0]=p[0]; outCenter[1]=p[1]; outCenter[2]=p[2]; *outRadius = r; }
    //         }
    //     return 5;
    //   }
    // UNRESOLVED: Globals flt_59E450 and flt_59E6EC are recorded as read in this function but do not appear in the decompiled body; they are plausibly the inline FP scale constants (0.5, 0.02) or shared data, exact role unverified.
    // UNRESOLVED: Owner and element layout of the packed array (three consecutive floats per element) are unknown; the caller at 0x0040E8B0 supplies the context.
    // UNRESOLVED: First argument a1 is unused in the decompiled body.
}
