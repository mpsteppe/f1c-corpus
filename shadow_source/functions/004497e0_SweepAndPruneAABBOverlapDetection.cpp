// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004497E0
// Canonical corpus name: SweepAndPruneAABBOverlapDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SweepAndPruneAABBOverlapDetection_004497e0.c

void UnknownObject::SweepAndPruneAABBOverlapDetection()
{
    // Broad-phase AABB overlap detection over a batch of triangles described by this[0] (count) and this[2] (triangle array, 32-byte stride). Allocates a temporary projection buffer (20 bytes per entry) with OperatorNewNhMallocWrapper, builds axis-aligned min/max projections for each triangle from its three vertex float pointers, sorts the entries by left bound via sub_5890AA with the sub_448440 comparator, then sweeps overlapping windows and validates each candidate pair with SATEdgeSeparationTest, marking overlapping triangle pairs with a 1 byte at triangle+24. Frees the buffer with FreeWrapper_7bcf and returns the triangle count. Invoked by CollisionGeometryOperationSelector as the broad phase before narrow-phase processing.
    // CALL: Allocate the projection buffer: v2 = OperatorNewNhMallocWrapper(20 * *this), sizing 20 bytes per triangle entry from the batch count at this+0x0 [callee:0x00587C03, field:this:0x00000000, source:raw]
    // GUARD: Guard on the batch count: when *this <= 0 skip the AABB-build loop, sort and sweep entirely (buffer remains NULL-allocated and only the count is returned) [guard:0, field:this:0x00000000, source:raw]
    // LOOP: Build projection entries for each triangle (v3 stepping by 32 through the triangle array at this+0x8): read the three vertex float pointers at triangle+0, +8 and +16, clear the overlap flag byte at triangle+24 to 0, store the triangle pointer, then compute the min and max of the axis floats (*v6, *v7, *v8) and of the second coordinate floats (v6[3], v7[3], v8[3]) into the 5-float entry [field:this:0x00000008, source:raw]
    // CALL: Sort the projection array: sub_5890AA(v2, *v1, 20, sub_448440) orders entries by their left bound using the sub_448440 comparator callback [callee:0x005890AA, global:0x00448440, field:this:0x00000000, source:raw]
    // LOOP: Sweep for overlaps: for each pivot entry, scan forward while the candidate left bound stays within the pivot right bound (breaking once *(v18-2) > v23); on x-overlap (v17[2] > *v18 && v17[1] < v18[1]) run SATEdgeSeparationTest on the two triangles and, when it returns non-zero, set the overlap flag byte at both triangle+24 to 1 [callee:0x004491C0, source:raw]
    // CALL: Free the temporary projection buffer with FreeWrapper_7bcf(v2) when it is non-null; the return value of the free becomes the function result [callee:0x00587BCF, source:raw]
    // RETURN: Return the triangle count (result = *this) when the buffer was never allocated, otherwise the FreeWrapper_7bcf result [function:0x004497E0, field:this:0x00000000, source:raw]
    // CALL: Invoked by CollisionGeometryOperationSelector (0044BB60) to find overlapping triangle pairs before narrow-phase collision resolution [caller:0x0044BB60, source:raw]

    // Conservative worker pseudocode:
    //   v2 = OperatorNewNhMallocWrapper(20 * *this);
    //   if (*this > 0) {
    //     for each triangle t (stride 32):
    //       t[24] = 0;
    //       p0 = *(float**)(t+0); p1 = *(float**)(t+8); p2 = *(float**)(t+16);
    //       entry.tri = t;
    //       entry.minX = min(*p0, *p1, *p2); entry.maxX = max(*p0, *p1, *p2);
    //       entry.minY = min(p0[3], p1[3], p2[3]); entry.maxY = max(p0[3], p1[3], p2[3]);
    //   }
    //   sub_5890AA(v2, *this, 20, sub_448440);
    //   for each pivot entry:
    //     for each candidate while candidate.left <= pivot.right:
    //       if (pivot.maxX > candidate.minX && pivot.minY < candidate.maxY)
    //         if (SATEdgeSeparationTest(pivot.tri, candidate.tri)) {
    //           pivot.tri[24] = 1; candidate.tri[24] = 1;
    //         }
    //   if (v2) return FreeWrapper_7bcf(v2);
    //   return *this;
    // UNRESOLVED: The axes of the two projections (offsets 0 and 3 of each vertex float pointer) are inferred as X and one orthogonal axis from the SAT test context; exact axis identity is not independently evidenced
    // UNRESOLVED: The triangle entry layout (three vertex pointers at +0/+8/+16, flag byte at +24) is read from the raw source, but the owning collision structure is not identified
    // UNRESOLVED: The meaningfulness of returning the free wrapper result versus the count on the allocated path is unclear from the evidence
    // UNRESOLVED: The existing analysis fill names the second projection axis by convention; that naming is not adopted beyond DERIVED
}
