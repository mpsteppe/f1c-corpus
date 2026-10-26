// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005383D0
// Canonical corpus name: sub_5383D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5383D0_005383d0.c

void UnknownObject::HuffmanTreeConstructor()
{
    // Builds an optimal Huffman prefix-code tree from a symbol frequency table. Collects the non-zero-frequency symbols into a node-index array, synthesizes dummy symbols when fewer than 2 remain, builds a min-heap over the node indices, repeatedly combines the two smallest nodes into a new parent (summing frequencies and taking max code length + 1), then finalizes the root, calls RankRedistribution to enforce a maximum code-length constraint, and returns the result of FrequencyTableConstruction which generates the canonical codes. Deflate-style encoder tree construction.
    // ASSIGNMENT: Initialize: v2 = a2[2] (tree-state block pointer, packet field this+0x8), v3 = *v2, v4 = *a2 (frequency-table base, packet field this+0x0), v6 = v2[3] (symbol count, packet field this+0x14); zero the symbol-count dword at a1+5190 and seed the node-capacity dword at a1+5194 with 573; v7 starts at -1. [field:this:0x00000008, field:this:0x00000000, field:this:0x00000014, source:raw]
    // LOOP: Collect non-zero-frequency symbols: for v8 in [0, v6), when the frequency word at v4+4*v8 is non-zero, append v8 to the node-index array (a1 + 4*count + 2898), increment the count at a1+5190, record v7 = v8, and zero the code-length byte at a1+v8+5198; otherwise zero the code-length word at v4+4*v8+2. [source:raw]
    // LOOP: Minimum-symbol synthesis: while the count at a1+5190 is below 2, add a synthetic symbol (v11 = ++v7, or 0 when v7 >= 2), store it into the node-index array, set its frequency word to 1, zero its code-length byte at a1+v11+5198, decrement the bit-budget dword at a1+5787, and when v3 is set subtract the frequency word v3+4*v11+2 from the dword at a1+5791. [source:raw]
    // ASSIGNMENT: Write back the maximum symbol index: a2[1] = v7 (packet field this+0x4). [field:this:0x00000004, source:raw]
    // LOOP: Heapify: for j = count(a1+5190) / 2 down to 1, call HeapSiftDown(j) to establish the min-heap property over the node-index array at a1+2898. [callee:0x005385E0, source:raw]
    // LOOP: Combine loop: while the count at a1+5190 is at least 2, pop the two smallest nodes (v15 from the a1+2902 heap-root slot after swapping, then v16 from the new root), decrement the count and the capacity dword at a1+5194, create the internal node v22 with frequency word v4+4*v22 = freq(v15) + freq(v16), code-length byte a1+v22+5198 = max(len(v15), len(v16)) + 1, link the parent words v4+4*v16+2 = v22 and v4+4*v15+2 = v22, push v22 back through a1+2902, and restore the heap with HeapSiftDown(1). [callee:0x005385E0, source:raw]
    // ASSIGNMENT: Finalize the root: decrement the capacity dword at a1+5194 and store the root node index (from a1+2902) at a1 + 4*newCount + 2898. [source:raw]
    // CALL: Call RankRedistribution(a1, a2) to enforce the maximum code-length constraint by redistributing the rank code lengths. [callee:0x005386C0, source:raw]
    // RETURN: Return the result of FrequencyTableConstruction(a1 + 2866), which generates the canonical Huffman codes from the computed code lengths. [callee:0x005388D0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a2[2]; v3 = *v2; v4 = *a2; v6 = v2[3]; v7 = -1; v22 = v6;
    //   a1[5190] = 0;
    //   for (a1[5194] = 573; v8 < v6; ++v8) {
    //     if (word(v4 + 4*v8)) { a1[5190]++; v7 = v8; a1[4*(a1[5190]) + 2898] = v8; byte(a1+v8+5198) = 0; }
    //     else word(v4 + 4*v8 + 2) = 0;
    //   }
    //   for (i = a1[5190]; i < 2; i = a1[5190]) {
    //     v11 = (v7 >= 2) ? 0 : ++v7;
    //     a1[5190] = i + 1; a1[4*(i+1) + 2898] = v11; word(v4 + 4*v11) = 1; byte(a1+v11+5198) = 0;
    //     --a1[5787]; if (v3) a1[5791] -= word(v3 + 4*v11 + 2);
    //   }
    //   a2[1] = v7;
    //   for (j = a1[5190] / 2; j >= 1; --j) HeapSiftDown(j);
    //   do { pop two smallest nodes v15, v16; a1[5190] -= 1; a1[5194] -= 2;
    //     word(v4 + 4*v22) = word(v4 + 4*v15) + word(v4 + 4*v16);
    //     byte(a1+v22+5198) = max(byte(a1+v15+5198), byte(a1+v16+5198)) + 1;
    //     word(v4 + 4*v16 + 2) = v22; word(v4 + 4*v15 + 2) = v22; a1[2902] = v22++; HeapSiftDown(1);
    //   } while (a1[5190] >= 2);
    //   a1[5194]--; a1[4*a1[5194] + 2898] = a1[2902];
    //   RankRedistribution(a1, a2);
    //   return FrequencyTableConstruction(a1 + 2866);
    // UNRESOLVED: The identity of the a1 state object is unknown; the roles of the a1+5190 (symbol count), a1+5194 (node capacity seeded 573), a1+5198 region (code lengths), a1+2898 region (node-index heap, with a1+2902 as the heap-root slot), a1+5787/a1+5791 (bit-budget dwords) and a1+2866 (canonical table target) are interpretations from the existing analysis fill, DERIVED and not independently proven.
    // UNRESOLVED: The packet maps the symbol count to field this+0x14 (a2[5]), but the raw source reads the count from the tree-state block via v2[3] where v2 = a2[2]; the exact field location is therefore ambiguous.
    // UNRESOLVED: The deflate/Huffman interpretation (tree construction, min-heap, rank redistribution, canonical codes) is DERIVED from the fill and the callee names HeapSiftDown/RankRedistribution/FrequencyTableConstruction, not independently evidenced.
    // UNRESOLVED: The meaning of the v3-conditional adjustment of the dword at a1+5791 during dummy-symbol synthesis is not fully resolved.
}
