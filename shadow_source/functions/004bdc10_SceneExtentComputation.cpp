// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BDC10
// Canonical corpus name: SceneExtentComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneExtentComputation_004bdc10.c

void UnknownObject::SceneExtentComputation()
{
    // Computes the scene extent by walking the collision geometry node list once: it reads the node count via AudioNetworkNodeCount(dword_8AFE88), then for each active node (LinkedListFlagBitExtraction non-zero and the node's byte at offset 60 with bit 0x10 clear) calls BoundingBoxComputation to get a bounding box and folds its six outputs into running min (v6,v7,v8, initialized to +FLT_MAX) and max (v9,v10,v11, initialized to -FLT_MAX) accumulators. If no node produces a non-degenerate box (maxX<=minX or maxZ<=minZ on the two stored axes), it returns an error path that emits the CouldNotGetExt debug log. Otherwise it stores the normalized extents on `this`: this[585]=min0, this[587]=min2, this[586]=8.0/(max0-min0), this[588]=8.0/(max2-min2). Existing analysis labels the two stored axes X and Z (scene min extent / scale for rendering).
    // ASSIGNMENT: Initialize the three minimum accumulators v6, v7, v8 to 3.4028235e38 (FLT_MAX). [source:raw]
    // ASSIGNMENT: Initialize the three maximum accumulators v9, v10, v11 to -3.4028235e38 (-FLT_MAX). [source:raw]
    // CALL: v1 = AudioNetworkNodeCount(dword_8AFE88) to obtain the number of nodes in the collision geometry list. [callee:0x005452F0, global:0x008AFE88]
    // LOOP: Iterate v2 from 0 while v2 < v1; if v1 <= 0 the loop body is skipped entirely (jump to the post-loop degenerate-bounds check). [source:raw]
    // CALL: v3 = LinkedListNodeFinder(v2) to fetch the node at index v2. [callee:0x00545340]
    // GUARD: Process the node only when LinkedListFlagBitExtraction(v3) is non-zero and the node's byte at offset 60 does not have bit 0x10 set; otherwise skip to the next index. [callee:0x0054FB70, source:raw]
    // CALL: BoundingBoxComputation(&v15) computes the node's bounding box into the stack output buffer; its six float outputs v12..v17 are subsequently consumed by the min/max fold. [callee:0x004DD550, source:raw]
    // CALCULATION: Fold first three bounding-box outputs into the minima: if v6 > v12 then v6 = v12; if v7 > v13 then v7 = v13; if v8 > v14 then v8 = v14. [source:raw]
    // CALCULATION: Fold remaining three bounding-box outputs into the maxima: if v9 < v15 then v9 = v15; if v10 < v16 then v10 = v16; if v11 < v17 then v11 = v17. [source:raw]
    // LOOP: Increment v2 and repeat the node iteration while v2 < v1. [source:raw]
    // GUARD: After the loop, if v9 <= v6 || v10 <= v7 || v11 <= v8 the extent is degenerate (no valid bounding range); this triggers the error path. The same guard is reached when the node list was empty. [source:raw]
    // CALL: On the error path, result = StringSplitLoop(1, aDDevF119992002_23, 321) to obtain the source-path debug string. [callee:0x004D7A50, global:0x005D2604]
    // CALL: If the split result is non-null, return DebugLogWrite(&dword_8AD25C, aCouldNotGetExt) to emit the 'could not get extent' error log. [callee:0x004D7AA0, global:0x008AD25C, global:0x005D25D0]
    // ASSIGNMENT: On success, this[585] (offset 0x924) = v6, the stored minimum of the first tracked axis (labeled scene min X in existing analysis). [field:this:0x00000924]
    // ASSIGNMENT: On success, this[587] (offset 0x92C) = v8, the stored minimum of the third tracked axis (labeled scene min Z in existing analysis). [field:this:0x0000092C]
    // CALCULATION: On success, this[586] (offset 0x928) = 8.0 / (v9 - v6), the normalized X scale from the first axis range. [field:this:0x00000928, source:raw]
    // CALCULATION: On success, this[588] (offset 0x930) = 8.0 / (v11 - v8), the normalized Z scale from the third axis range. [field:this:0x00000930, source:raw]
    // RETURN: Return `this` on success; on the degenerate/empty path return the StringSplitLoop result, or DebugLogWrite's return value when the split succeeded. [source:raw]

    // Conservative worker pseudocode:
    //   float *SceneExtentComputation(float *this) {
    //     float min0 = 3.4028235e38f, min1 = 3.4028235e38f, min2 = 3.4028235e38f;
    //     float max0 = -3.4028235e38f, max1 = -3.4028235e38f, max2 = -3.4028235e38f;
    //     int nodeCount = AudioNetworkNodeCount(dword_8AFE88);
    //     for (int i = 0; i < nodeCount; i++) {
    //       void *node = LinkedListNodeFinder(i);
    //       if (LinkedListFlagBitExtraction(node) && (*(char *)node + 60 & 0x10) != 0x10) {
    //         float box[6];
    //         BoundingBoxComputation(&box[3]);
    //         if (min0 > box[0]) min0 = box[0];
    //         if (min1 > box[1]) min1 = box[1];
    //         if (min2 > box[2]) min2 = box[2];
    //         if (max0 < box[3]) max0 = box[3];
    //         if (max1 < box[4]) max1 = box[4];
    //         if (max2 < box[5]) max2 = box[5];
    //       }
    //     }
    //     if (max0 <= min0 || max1 <= min1 || max2 <= min2) {
    //       float *s = StringSplitLoop(1, aDDevF119992002_23, 321);
    //       if (s) return DebugLogWrite(&dword_8AD25C, aCouldNotGetExt);
    //     } else {
    //       this[585] = min0;
    //       this[587] = min2;
    //       this[586] = 8.0f / (max0 - min0);
    //       this[588] = 8.0f / (max2 - min2);
    //       return this;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The identity of the six bounding-box outputs v12..v17 (which decompiler-local corresponds to minX/maxX/minY/maxY/minZ/maxZ) is not determinable from this function alone; only two axes (v6/v9 and v8/v11) are stored, and existing analysis labels those X and Z but that labeling is DERIVED.
    // UNRESOLVED: The node byte at offset 60 masked with 0x10 belongs to the linked-list node object, but no packet field evidence identifies it; only source:raw supports that access.
    // UNRESOLVED: Global flt_59E4DC (0x0059E4DC) is listed in the packet globals but never referenced in the raw source text; its role here is unknown.
    // UNRESOLVED: The exact packing of the six box outputs written by BoundingBoxComputation(&v15) versus the stack slots read (v12..v17) is a decompiler artifact; the min fold reads v12/v13/v14 while the callee's pointer argument is &v15, leaving the mapping between the two ranges unverified.
}
