// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044A4B0
// Canonical corpus name: sub_44A4B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_44A4B0_0044a4b0.c

void UnknownObject::BspLeafMaterialSelectionAndSubdivision()
{
    // Recursive collision-material selection for a vertex region. Walks a singly linked list of vertices (head encoded in float argument a2, next pointer at byte offset 28) to count nodes. With fewer than 3 nodes the region is degenerate and classified with flag -1 or -2, the output pointer is reserved in an arena and spatial hash keys are generated per node. Otherwise a sampling stride derived from the node count selects material indices across 14 material types, sub_44A2D0 scores each candidate, and the lowest-coverage material wins. The chosen material is written as a classification word at this+8 (0 for indices <= 7, 1 otherwise) and a dispatch index word at this+10 (14 - index when extended, else the index), dispatch hooks are invoked on both, two float slots are reserved in the output arena pointed to by this+12, the coverage coordinates are stored, and the function recurses twice on the two child half-regions, returning 0 on success and -1 on recursion failure.
    // CALL: ConditionalDispatch_6bd0 invoked on this and this+4 with argument 4 to reset the dispatch state before processing. [callee:0x00566BD0, source:raw]
    // ASSIGNMENT: Initialize the vertex list walk: v5 takes the list head (float argument a2 re-read as a pointer) and the node counter v6 starts at 0. [source:raw]
    // GUARD: If the list head a2 is null the list is empty and control jumps to the degenerate output path. [source:raw]
    // LOOP: Walk the singly linked list via the next pointer at byte offset 28 until the null terminator, counting the nodes into v6. [source:raw]
    // GUARD: If the node count is below 3, classify the region as degenerate: flag -1 written as a word at field this+8 when there is exactly 1 node, -2 when there are exactly 2. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Degenerate path: dispatch the classification byte from field this+8, write -1 as the dispatch index word at field this+10, reserve the output pointer from the arena record (base v3[9] plus 92 times slot counter v3[7]) into field this+12, and advance the arena slot counter. [field:this:0x0000000A, field:this:0x0000000C]
    // LOOP: Degenerate path: if the list head is non-null, iterate the node list again and call SpatialHashKeyGeneration for every node placed in the reserved output area. [callee:0x00449ED0, source:raw]
    // STATE_TRANSITION: For a non-degenerate region choose the material sampling stride v11 from the node count: 15 for at most 10 nodes, 6 for at most 100 nodes, otherwise 3; the loop step is 14 divided by v11, clamped to at least 1. [source:raw]
    // LOOP: Sample material indices starting at (count modulo step) and advancing by step while below 14 material types. [source:raw]
    // CALL: CollisionMaterialLookup(i, out-values) resolves material data for the sampled index i. [callee:0x0044A450, source:raw]
    // CALL: sub_44A2D0 computes the coverage score for the current candidate material against the vertex list. [callee:0x0044A2D0, source:raw]
    // CALCULATION: Track the best (lowest) coverage score: keep the best material index v20 initialized to -1 and the best score v21 initialized to the largest float. [source:raw]
    // CALL: Resolve the winning material with CollisionMaterialLookup and run a final sub_44A2D0 scoring pass with the persist flag for the selected material. [callee:0x0044A450, callee:0x0044A2D0, source:raw]
    // ASSIGNMENT: Write the material classification word at field this+8: 1 for a winning index above 7, 0 otherwise. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the dispatch material index word at field this+10: 14 minus the index for extended materials (index above 7), else the raw index. [field:this:0x0000000A, source:raw]
    // CALL: ConditionalDispatch_6bd0 invoked with argument 1 on the classification byte (field this+8) and on the dispatch index byte (field this+10). [callee:0x00566BD0, source:raw]
    // CALCULATION: Reserve two float slots in the output arena: field this+12 becomes the arena base v3[12] plus 16 times the slot counter v3[10], and the slot counter advances by 2. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store the coverage coordinate from v22[1] into the first output slot at buffer offset 0. [field:*(this+0xC):0x00000000, source:raw]
    // ASSIGNMENT: Store the coverage extent from v22[2] into the output buffer at byte offset 4. [field:*(this+0xC):0x00000004, source:raw]
    // CALL: Recurse into the first child half-region with sub_44A4B0(v22[0], arena); a non-zero result makes the function return -1. [callee:0x0044A4B0, function:0x0044A4B0, source:raw]
    // ASSIGNMENT: Store the recursion result coordinates v22[4] into the output buffer at byte offset 16 and v22[5] at byte offset 20. [field:*(this+0xC):0x00000010, field:*(this+0xC):0x00000014, source:raw]
    // CALL: Recurse into the second child half-region with sub_44A4B0(v22[3], arena); the final return is 0 on success and -1 on recursion failure. [callee:0x0044A4B0, function:0x0044A4B0, source:raw]
    // RETURN: Return 0 on the degenerate path and either 0 or -1 (propagating a failed recursion) on the normal path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_44A4B0(int this, float a2, int a3) {
    //     _DWORD* v3 = (_DWORD*)a3;
    //     ConditionalDispatch_6bd0(this, 4);
    //     ConditionalDispatch_6bd0(this + 4, 4);
    //     int v5 = (int)a2; int v6 = 0;
    //     if (a2 == 0.0) goto degenerate;
    //     do { a2 = *(float*)((int)a2 + 28); ++v6; } while (a2 != 0.0);
    //     if (v6 < 3) {
    //       if (v6 == 1) *(short*)(this + 8) = -1;
    //       else if (v6 == 2) *(short*)(this + 8) = -2;
    //       goto degenerate;
    //     }
    //     int v11 = v6 <= 10 ? 15 : (v6 <= 100 ? 6 : 3);
    //     int step = (14 / v11) >= 1 ? (14 / v11) : 1;
    //     int v20 = -1; float v21 = 3.4028235e38;
    //     for (int i = v6 % step; i < 14; i += step) {
    //       CollisionMaterialLookup(i, &v19, &a2);
    //       sub_44A2D0(v22, v5, v3[13], v19, a2, 0);
    //       if (v23 < v21) { v21 = v23; v20 = i; }
    //     }
    //     CollisionMaterialLookup(v20, &v19, &a2);
    //     sub_44A2D0(v22, v5, v3[13], v19, a2, 1);
    //     *(short*)(this + 8) = v20 > 7 ? 1 : 0;
    //     *(short*)(this + 10) = v20 > 7 ? (14 - v20) : v20;
    //     ConditionalDispatch_6bd0((int)&this + 8, 1);
    //     ConditionalDispatch_6bd0((int)&this + 10, 1);
    //     *(int*)(this + 12) = v3[12] + 16 * v3[10]; v3[10] += 2;
    //     **(float**)(this + 12) = v22[1];
    //     *(float*)(*(int*)(this + 12) + 4) = v22[2];
    //     if (sub_44A4B0(v22[0], (int)v3)) return -1;
    //     *(float*)(*(int*)(this + 12) + 16) = v22[4];
    //     *(float*)(*(int*)(this + 12) + 20) = v22[5];
    //     return -(sub_44A4B0(v22[3], (int)v3) != 0);
    //   degenerate:
    //     LOBYTE(a3) = *(char*)(this + 8);
    //     ConditionalDispatch_6bd0((int)&a3, 1);
    //     *(short*)(this + 10) = -1;
    //     *(int*)(this + 12) = v3[9] + 92 * v3[7];
    //     v3[7] += v6;
    //     if (v5) {
    //       int v8 = 0;
    //       do { SpatialHashKeyGeneration((_DWORD*)(v8 + *(int*)(this + 12)), v5, (int)v3); v8 += 92; v5 = *(int*)(v5 + 28); } while (v5);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Layout of the arena record v3 (fields indexed 7, 9, 10, 12, 13) is unknown; offsets 92 and 16 strides and the slot counters are only partially interpreted.
    // UNRESOLVED: Meaning of the sub_44A2D0 coverage score (v23) and its arguments v22 and v19 is unknown.
    // UNRESOLVED: First argument a2 is a vertex-list head pointer re-interpreted as a float; the float-encoded pointer conversion is a Hex-Rays artifact.
    // UNRESOLVED: Fields this+8 and this+10 are written as 16-bit words but dispatched byte-wise; their exact dispatch-consumer contract is unknown.
    // UNRESOLVED: Recursion passes v22[0] and v22[3] as the child this pointer; the correspondence to spatial half-splits is inferred, not proven.
}
