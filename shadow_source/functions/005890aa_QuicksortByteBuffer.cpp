// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005890AA
// Canonical corpus name: sub_5890AA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5890AA_005890aa.c

void UnknownObject::QuicksortByteBuffer()
{
    // Iterative quicksort over an array of a2 elements, each a3 bytes, at base address a1, ordered by the caller-supplied comparator a4 (a4 returns <= 0 or >= 0 relative to the pivot). Small subarrays (8 or fewer elements) are handed to sub_5891FE. Partitioning: the middle element is swapped to the front with ByteBufferSwap as the pivot, a Hoare-style scan advances from both ends (left while a4 <= 0, right while a4 >= 0) swapping crossing pairs, and the pivot is placed at the meeting point. Subarray bounds are kept on an explicit stack over the local buffers v14/v15 with depth counter v17; the larger partition is processed in place while the smaller is pushed, bounding stack depth.
    // GUARD: If the element count a2 is less than 2 or the element size a3 is zero, return immediately (nothing sortable). [source:raw]
    // ASSIGNMENT: Initialize the sort: v5 = a1 + a3 * (a2 - 1) (address of the last element); set up the explicit subarray-bound stacks v19/v18 over the local buffers v14/v15 and the depth counter v17. [source:raw]
    // CALCULATION: Compute the current subarray's element count v6 = (v5 - a1) / a3 + 1. [source:raw]
    // GUARD: If v6 <= 8, hand the small range to sub_5891FE(a1, v5, a3, a4) and continue with the next subarray taken from the stack. [callee:0x005891FE, source:raw]
    // CALL: Swap the middle element (a1 + a3 * (v6 >> 1)) to the front with ByteBufferSwap, making it the pivot. [callee:0x0058924C, source:raw]
    // LOOP: Hoare partition: advance v16 from the left while a4(element) <= 0, advance i from the right while a4(element) >= 0, and swap each crossing pair with ByteBufferSwap(v16, i, a3), repeating until the scans meet. [callee:0x0058924C, source:raw]
    // CALL: Swap the pivot back into its final position with ByteBufferSwap(a1, i, a3) at the scan meeting point. [callee:0x0058924C, source:raw]
    // CALCULATION: Record v9 = v16 (start of the right partition) and compare the partition sizes (int)(i - a1 - 1) and (int)(v5 - v16) to choose which side is processed next and which is pushed. [source:raw]
    // STATE_TRANSITION: Push the deferred subarray bounds onto the explicit stack (v19/v18 with depth counter v17) and select the next subarray to process: the left partition ending at i - a3 or the right partition starting at v9. [source:raw]
    // RETURN: Pop a subarray from the stack; when the depth counter v17 goes below zero the stack is empty and the function returns. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 < 2 || a3 == 0) return;
    //   lo = a1; hi = a1 + a3 * (a2 - 1);
    //   init explicit stack of (lo, hi) bounds;
    //   loop {
    //       n = (hi - lo) / a3 + 1;
    //       if (n <= 8) { sub_5891FE(lo, hi, a3, a4); continue; }
    //       ByteBufferSwap(lo + a3 * (n >> 1), lo, a3);
    //       scan left while a4 <= 0; scan right while a4 >= 0; swap crossings;
    //       ByteBufferSwap(lo, meeting, a3);
    //       push the smaller partition bounds; process the larger partition;
    //   }
    // UNRESOLVED: sub_5891FE (the small-range handler) is assumed to be the terminal insertion-style sorter, but its body is outside this function.
    // UNRESOLVED: The comparator convention (a4's sign relative to the pivot on both scan sides) is inferred from the conditions a4(v8) <= 0 and a4(i) >= 0; the caller contract is unverified.
    // UNRESOLVED: The explicit-stack local buffers v14/v15 have no evident size in this decompilation.
}
