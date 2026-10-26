// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051D57F
// Canonical corpus name: sub_51D57F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51D57F_0051d57f.c

void UnknownObject::BuildMedianSplitOccupancyTree()
{
    // Iterative median-split tree builder over an array of 6-coordinate axis-aligned boxes (stride 8 dwords). For each output node it scans the input box array, selects the box whose split-key value is greatest (two scan variants differ in start offset and in a positivity filter on the preceding coordinate), copies the 6 box coordinates into the node, picks the widest axis by comparing scaled extents, bisects that axis at the midpoint (writing midpoint+1 as a split marker), and hands both resulting halves to GridOccupancyBoundingBoxScan. The loop advances two tree positions per node until the count reaches a4.
    // ASSIGNMENT: Alias result = a3 and v5 = a2 before any processing. [source:raw]
    // GUARD: Guard on a3 < a4: the tree-building loop only runs while there is at least one box to process. [source:raw]
    // CALCULATION: Initialize the node index v19 = 2*a3 and the output node pointer v6 = a2 + 32*a3 + 12, i.e. the (a3)-th stride-32 element offset by 12 bytes. [source:raw]
    // LOOP: Outer while(1) node loop; each iteration resets the selected box v7 and best key v8 to 0. [source:raw]
    // GUARD: Branch on v19 > a4: the upper-range scan variant starts at a2+24 and steps 8 dwords, while the a4-reachable variant starts at a2+28 and additionally requires the preceding coordinate *(v9-1) > 0. [source:raw]
    // LOOP: do-while scan over result (= a3) candidates; picks v7 as the box whose scanned key *v9 is greater than v8. [source:raw]
    // GUARD: if (!v7) break: when no box beats the initial zero key the outer loop terminates. [source:raw]
    // ASSIGNMENT: Copy the selected box's six coordinates into the output node: node[-2]=src[1], node[0]=src[3], node[2]=src[5], node[-3]=src[0], node[-1]=src[2], node[1]=src[4]. [source:raw]
    // CALCULATION: Axis selection by scaled extent: v11 = 12*(src[3]-src[2]) for y; if 16*(src[1]-src[0]) > v11 choose x (v12=0); if 8*(src[5]-src[4]) > v11 choose z (v12=2); otherwise keep y (v12=1). [source:raw]
    // STATE_TRANSITION: Bisect the chosen axis at its midpoint: x -> src[1]=mid, node[-3]=mid+1; y -> src[3]=mid, node[-1]=mid+1; z -> src[5]=mid, node[1]=mid+1. The midpoint+1 values act as split markers in the node. [source:raw]
    // CALL: GridOccupancyBoundingBoxScan(a1, v7) on the first half of the split box. [callee:0x0051D247, source:raw]
    // CALL: GridOccupancyBoundingBoxScan(a1, v6 - 3) on the second half of the split box (the copied node). [callee:0x0051D247, source:raw]
    // CALCULATION: Advance the walk: v19 += 2, result = a3 + 1, v6 += 8, and ++a3. [source:raw]
    // GUARD: Terminate the outer loop once ++a3 >= a4; v5 is reset to a2 each iteration. [source:raw]
    // RETURN: Return the final index (a3+1 of the last processed node, or a3 when nothing was processed); invoked from RenderBufferSetup. [caller:0x0051D80A, function:0x0051D57F, source:raw]

    // Conservative worker pseudocode:
    //   int BuildMedianSplitOccupancyTree(int grid, int* boxes, int first, int end) {
    //     if (first >= end) return first;
    //     int index = 2*first;
    //     int* node = (int*)((char*)boxes + 32*first + 12);
    //     while (1) {
    //       int* src = 0; int best = 0;
    //       if (index > end) {
    //         if (index > 0) { int* p = (int*)((char*)boxes + 24); int n = first;
    //           do { if (*p > best) { src = p - 6; best = *p; } p += 8; } while (--n); }
    //       } else if (index > 0) { int* p = (int*)((char*)boxes + 28); int n = first;
    //         do { if (*p > best && *(p-1) > 0) { src = p - 7; best = *p; } p += 8; } while (--n); }
    //       if (!src) break;
    //       node[-2]=src[1]; node[0]=src[3]; node[2]=src[5];
    //       node[-3]=src[0]; node[-1]=src[2]; node[1]=src[4];
    //       int extent = 12*(src[3]-src[2]); int axis = 1;
    //       if (16*(src[1]-src[0]) > extent) { extent = 16*(src[1]-src[0]); axis = 0; }
    //       if (8*(src[5]-src[4]) > extent) axis = 2;
    //       if (axis == 2) { int m = (src[4]+src[5])/2; src[5]=m; node[1]=m+1; }
    //       else if (axis == 1) { int m = (src[2]+src[3])/2; src[3]=m; node[-1]=m+1; }
    //       else { int m = (src[0]+src[1])/2; src[1]=m; node[-3]=m+1; }
    //       GridOccupancyBoundingBoxScan(grid, src);
    //       GridOccupancyBoundingBoxScan(grid, node - 3);
    //       index += 2; node += 8;
    //       if (++first >= end) break;
    //     }
    //     return first;
    //   }
    // UNRESOLVED: The two scan variants (v19 > a4 starting at +24 with no extra filter, vs the a4-reachable variant starting at +28 with the *(v9-1) > 0 filter) are not otherwise explained; the positivity filter's meaning is unknown.
    // UNRESOLVED: The exact layout semantics of a1 and its role in GridOccupancyBoundingBoxScan are supplied by the callee, not this function.
    // UNRESOLVED: The midpoint+1 split markers written into the node are presumed to be consumed by GridOccupancyBoundingBoxScan; this is unverified here.
    // UNRESOLVED: The 12/16/8 scaling factors on the axis extents are literal weights whose geometric intent (aspect compensation) is not proven.
}
