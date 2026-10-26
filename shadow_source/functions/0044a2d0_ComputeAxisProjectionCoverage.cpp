// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044A2D0
// Canonical corpus name: sub_44A2D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_44A2D0_0044a2d0.c

void UnknownObject::ComputeAxisProjectionCoverage()
{
    // Walks a singly linked list of vertex-data nodes (a2 head, next pointer at node+28, zero count v7), projecting each node's three vertex pairs onto a weighted axis (a4/a5 blend factors) and tracking per-node min/max projection into 16-byte records (node pointer, min, max, midpoint) written to a3+8. The record array is then sorted by sub_5890AA (0x005890AA, 16-byte stride, comparator sub_44A130 at 0x0044A130). Coverage is evaluated via VisibilityFrustumTest (0x0044A170) on the sorted records, split by the count midpoint v16 = (v7+1)/2, and the better-scoring half's result is selected into this (copied via qmemcpy of 0x1C bytes or recomputed with flag 1 depending on a6).
    // GUARD: If a2 (linked-list head) is null, skip all processing (void function). [source:raw]
    // ASSIGNMENT: Initialize per-node projection min seed v10 to -3.4028235e38 (the MinusFLT_MAX constant associated with flt_59EF30) and max seed v20 to 3.4028235e38. [global:0x0059EF30, source:raw]
    // LOOP: For each node, loop i from 0 to 2 (three vertex pairs): compute v12 = a5 * *(*(v6 + 8*i) + 12) + a4 * **(v6 + 8*i), a weighted blend of two coordinates per vertex. [source:raw]
    // ASSIGNMENT: On an unordered compare flag (v14 | v15, i.e. NaN/orderedness), assign v20 = v12, capturing the value as the per-node minimum. [source:raw]
    // CALCULATION: Track the running maximum v10 = max(v10, v12) via the v21 temporary. [source:raw]
    // ASSIGNMENT: Write the per-node 16-byte record at the running output pointer v9 (starting at a3+8): node pointer v6 at offset 0, min v20 at offset 4, max v10 at offset 8, and midpoint (v10 + v20) * 0.5 at offset 12 after advancing v9 by 4 floats. [source:raw]
    // LOOP: Advance to the next node via the next pointer at node+28; repeat while the node pointer is non-null, incrementing the count v7. [source:raw]
    // CALL: Sort the record array with sub_5890AA(a3, v7, 16, sub_44A130) using a 16-byte stride and the comparator sub_44A130 (0x0044A130). [callee:0x005890AA, global:0x0044A130, source:raw]
    // CALCULATION: Compute the split index v16 = (v7 + 1) / 2 and branch on whether v7 / 2 == v16, i.e. whether the node count is even. [source:raw]
    // CALL: Even count: single VisibilityFrustumTest(this, a3, v7/2, v7, a6) (0x0044A170) over the whole record range. [callee:0x0044A170, source:raw]
    // CALL: Odd count: evaluate both halves with VisibilityFrustumTest(v18, a3, v7/2, v7, 0) and VisibilityFrustumTest(v19, a3, v16, v7, 0) (0x0044A170). [callee:0x0044A170, source:raw]
    // GUARD: Compare the two half results: if v18[6] >= v19[6] select the v19 half, else select the v18 half. [source:raw]
    // ASSIGNMENT: Selected half: when a6 is set, recompute into this via VisibilityFrustumTest(this, a3, index, v7, 1) (0x0044A170); otherwise copy the selected 0x1C-byte result into this with qmemcpy. [callee:0x0044A170, source:raw]

    // Conservative worker pseudocode:
    //   void ComputeAxisProjectionCoverage(float* this, int head, int out, float a4, float a5, char a6) {
    //     int node = head;
    //     int count = 0;
    //     float* outPtr = (float*)(out + 8);
    //     while (node) {
    //       float v20 = 3.4028235e38;
    //       float v10 = -3.4028235e38;
    //       for (int i = 0; i < 3; ++i) {
    //         float v12 = a5 * *(float*)(*(int*)(node + 8*i) + 12) + a4 * **(float**)(node + 8*i);
    //         if (unordered_compare) v20 = v12;
    //         if (v12 > v10) v10 = v12;
    //       }
    //       *outPtr = v10;
    //       *(int*)(outPtr - 2) = node;
    //       *(outPtr - 1) = v20;
    //       ++count;
    //       outPtr += 4;
    //       *(outPtr - 3) = (v10 + v20) * 0.5;
    //       node = *(int*)(node + 28);
    //     }
    //     if (!head) return;
    //     sub_5890AA(out, count, 16, sub_44A130);
    //     int v16 = (count + 1) / 2;
    //     if (count / 2 == v16) {
    //       VisibilityFrustumTest(this, out, count / 2, count, a6);
    //     } else {
    //       float v18[7], v19[7];
    //       VisibilityFrustumTest(v18, out, count / 2, count, 0);
    //       VisibilityFrustumTest(v19, out, v16, count, 0);
    //       if (v18[6] >= v19[6]) {
    //         if (a6) VisibilityFrustumTest(this, out, v16, count, 1);
    //         else qmemcpy(this, v19, 0x1C);
    //       } else if (a6) {
    //         VisibilityFrustumTest(this, out, count / 2, count, 1);
    //       } else {
    //         qmemcpy(this, v18, 0x1C);
    //       }
    //     }
    //   }
    // UNRESOLVED: flt_59E450 (DegreesToRadians) is recorded as a read global but has no visible reference in the raw source text; it may be constant-folded or optimized out of the decompilation.
    // UNRESOLVED: The semantics of the a4/a5 projection weights and the vertex-pair layout at node+0/+8/+12 are unverified; the 'axis-projection' reading follows the existing skeleton analysis.
    // UNRESOLVED: The meaning of the VisibilityFrustumTest coverage result and its use of flag 1 vs 0 is DERIVED from the skeleton, not proven by raw source.
    // UNRESOLVED: Whether a6 means 'in-place recompute' vs 'copy' is inferred from the qmemcpy-vs-recompute branching and is not independently grounded.
    // UNRESOLVED: The linkage between the -3.4028235e38 literal and the global flt_59EF30 is inferred (constant folding), not explicit in the raw text.
}
