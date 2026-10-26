// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005389B0
// Canonical corpus name: RunLengthAnalyzer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RunLengthAnalyzer_005389b0.c

void UnknownObject::RunLengthFrequencyAnalyzer()
{
    // Analyzes run-lengths of a Huffman code-length sequence for deflate tree encoding. Walks a2's code-length array from element 1 onward with a sentinel -1 written at a2 + 4*a3 + 6, tracking consecutive identical values. Thresholds switch between zero-run mode (max run v5=138, min run v6=3) and non-zero mode (v5=6/v6=3 or v5=7/v6=4). Finished runs accumulate frequency counts: short runs (v4 < v6) add v4 to a1[2*v9+1337]; non-zero runs of at least v6 increment a1[2*v9+1337] (only when the value differs from the previous run) plus a1[1369]; zero runs of at least v6 increment a1[1371] when v4 <= 10, else a1[1373]. Returns the remaining loop counter. The single static caller is PerformanceSectorTimeAccumulator (00538940).
    // CALCULATION: Load the first code length value v3 from a2 at offset 0x2. [field:this:0x00000002, source:raw]
    // GUARD: When the first code length v3 is zero, select zero-run thresholds (v5=138, v6=3). [source:raw]
    // ASSIGNMENT: Write the sentinel -1 into the code-length array at a2 + 4*a3 + 6 to terminate the scan. [source:raw]
    // GUARD: Enter the scan loop only when a3 >= 0. [source:raw]
    // LOOP: Iterate over code-length elements from a2 + 6 onward, tracking run length v4 and comparing the previous value v9 against the next value v3. [field:this:0x00000006, source:raw]
    // GUARD: End a run when the run length reaches the max threshold (++v4 >= v5) or the value changes (v9 != v3). [source:raw]
    // STATE_TRANSITION: Accumulate the finished run: short runs (v4 < v6) add v4 to a1[2*v9+1337]; longer runs of a non-zero value increment the per-value bucket a1[2*v9+1337] (only when v9 differs from the previous run) plus a1[1369]; zero runs of length 11+ increment a1[1373], else a1[1371]. [source:raw]
    // ASSIGNMENT: Reset the run counter v4 to 0, record v9 as the previous run value v10, and reselect thresholds from the next value v3 (zero -> 138/3, same non-zero -> 6/3, differing non-zero -> 7/4). [source:raw]
    // RETURN: Return the remaining loop counter. [function:0x005389B0, source:raw]
    // CALL: Invoked by PerformanceSectorTimeAccumulator (00538940), the sole static caller. [caller:0x00538940]

    // Conservative worker pseudocode:
    //   prev_len = a2[1];
    //   run = 0; prev_val = -1;
    //   max_run = (prev_len == 0) ? 138 : 7;
    //   min_run = (prev_len == 0) ? 3 : 4;
    //   a2[a3 + 3] = -1;  /* sentinel * /
    //   for (i = 0; i <= a3; ++i) {
    //       cur = a2[i + 1];
    //       if (++run < max_run && prev_len == cur) continue;
    //       if (run < min_run) hist[cur] += run;
    //       else if (cur != 0) { if (cur != prev_val) hist[cur]++; hist[1369]++; }
    //       else if (run > 10) hist[1373]++;
    //       else hist[1371]++;
    //       run = 0; prev_val = cur;
    //       if (cur == 0) { max_run = 138; min_run = 3; }
    //       else if (prev_len == cur) { max_run = 6; min_run = 3; }
    //       else { max_run = 7; min_run = 4; }
    //   }
    //   return a3 + 1 - i;
    // UNRESOLVED: Owner is UNKNOWN; the ABI lead FAIL_5389b0 indicates an unresolved symbol, not a recoverable class.
    // UNRESOLVED: The bucket layout a1[2*v9+1337], a1[1369], a1[1371], a1[1373] is taken verbatim from the raw source, but the structural meaning (a1[1337] acting as a per-length frequency base) is DERIVED.
    // UNRESOLVED: The caller's name PerformanceSectorTimeAccumulator (00538940) suggests a sector-timing context, which does not obviously match deflate code-length frequency analysis; the caller relationship is static only.
    // UNRESOLVED: The semantics of the loop return value (remaining counter) are not meaningful to callers according to the raw source; no contract is stated.
}
