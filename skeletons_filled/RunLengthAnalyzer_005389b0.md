## RunLengthAnalyzer_005389b0 — Code length RLE frequency analyzer

**Summary:** Analyzes run-lengths of Huffman code length sequence for deflate tree encoding. Walks through code length array tracking consecutive identical values, accumulates frequency counts for short/long runs of zeros and non-zero code lengths. Feeds frequency data into Huffman tree builder for code length encoding.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PerformanceSectorTimeAccumulator (00538940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2 | R | — | first code length value (a2[1], v3) — used for run detection |
| this | 0x6 | R | — | next code length value (a2[3]) — compared for run continuation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** When first code length (v3) == 0, sets max run length (v5) to 138 and min run threshold (v6) to 3. When all runs complete and no non-zero code lengths, run detection shifts to next value. Run ends when v4 >= v5 (max run) or v9 != v3 (value changed). Thresholds switch between zero-run mode (v5=138, v6=3) and non-zero mode (v5=6, v6=3; v5=7, v6=4) based on current run value.
