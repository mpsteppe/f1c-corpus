// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005381F0
// Canonical corpus name: HuffmanBitStreamEncoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HuffmanBitStreamEncoder_005381f0.c

void UnknownObject::HuffmanBitStreamEncoder()
{
    // Deflate-style Huffman bitstream encoder. If the block counter at a1+122 is non-positive, the tree-rebuild stage is skipped; otherwise, when the block type at a1+28 is 2 the checksum is validated via BufferChecksumValidator, two Huffman trees are built via sub_5383D0 over the arrays at a1+2830 and a1+2842, and PerformanceSectorTimeAccumulator computes the bit-cost used during flushing. Byte budgets v7/v8 are derived from the bit counters at a1+5787 and a1+5791 ((value + 10) >> 3). When a2 is set and a3+4 fits the budget, the symbol is written raw via BitstreamWriteBits; otherwise the symbol (a4+2 or a4+4 extra bits, depending on which budget branch) is packed into the 16-bit accumulator at a1+5803 under the bit cursor a1+5805, flushing full bytes to the output cursor (a1+8 + a1+20) when the cursor exceeds 13 bits, rebuilding the fixed code table via HuffmanBitStreamDecoder(&unk_5B8280) on the literal path or the dynamic table at a1+2430 on the distance path, and flushing the buffered stream via BitBufferWriter. ScorecardZero resets the frequency/cost accumulators for the next block, and a non-zero a4 triggers a final UnicodeBufferFlusher.
    // GUARD: Block gate: when the dword block counter at a1+122 is <= 0, the tree rebuild and checksum stage is skipped and the budget falls back to a3+5; otherwise the full encoder path runs. [source:raw]
    // GUARD: Block-type check: when the byte at a1+28 is 2 (compressed), the buffer checksum is validated via BufferChecksumValidator(a1) before the trees are rebuilt. [callee:0x00539600, source:raw]
    // CALL: Build the two Huffman trees: sub_5383D0(a1, a1+2830) and sub_5383D0(a1, a1+2842) construct the literal/length and distance trees from their frequency arrays. [callee:0x005383D0, source:raw]
    // CALL: Accumulate the encoding bit-cost: PerformanceSectorTimeAccumulator(a1) returns v5, later passed to BitBufferWriter for the flush. [callee:0x00538940, source:raw]
    // CALCULATION: Bit-budget arithmetic: v7 = (dword at a1+5787 + 10) >> 3 and v8 = (dword at a1+5791 + 10) >> 3; when v8 <= v7 the smaller budget v8 is used. [source:raw]
    // GUARD: Raw-write branch: when a2 is set and a3+4 <= v7, the symbol is written directly with BitstreamWriteBits(a1, a3, a4) instead of being packed. [callee:0x00537F30, source:raw]
    // CALCULATION: Symbol packing: with the bit cursor v11 read from a1+5805, the value a4+2 (v8 == v7 literal path) or a4+4 (distance path) is shifted left by v11 and OR-ed into the 16-bit accumulator at a1+5803; when v11 <= 13 the cursor is advanced by 3. [source:raw]
    // CALCULATION: Byte flush when the cursor v11 exceeds 13: the low byte of a1+5803 is stored at the output cursor (a1+8 + a1+20), then the high byte at a1+5804 is stored at cursor +1, a1+20 advances by 2, the cursor at a1+5805 is reduced by 13, and the remaining shifted bits stay in a1+5803. [source:raw]
    // CALL: Rebuild the fixed/global code table: HuffmanBitStreamDecoder(&unk_5B8280) assigns the reverse codes for the shared static tree used on the literal path. [callee:0x00539200, global:0x005B8280, source:raw]
    // CALL: Flush the buffered bitstream: BitBufferWriter(a1+2846 + 1, v5 + 1) writes the pending output bytes on the distance path. [callee:0x00538A90, source:raw]
    // CALL: Rebuild the dynamic length tree code table: HuffmanBitStreamDecoder(a1 + 2430) assigns the reverse codes for the tree stored at a1+2430. [callee:0x00539200, source:raw]
    // CALL: Reset per-block accumulators: ScorecardZero(a1) zeroes the frequency/cost state and its return value becomes the function result when a4 is zero. [callee:0x00537EC0, source:raw]
    // GUARD: Final flush: when a4 (retained as v9) is non-zero the function returns UnicodeBufferFlusher() instead of the ScorecardZero result. [callee:0x00539720, source:raw]

    // Conservative worker pseudocode:
    //   if (a1[122] <= 0) { v7 = v8 = a3 + 5; }
    //   else {
    //     if (a1[28] == 2) BufferChecksumValidator(a1);
    //     sub_5383D0(a1, a1 + 2830);
    //     sub_5383D0(a1, a1 + 2842);
    //     v5 = PerformanceSectorTimeAccumulator(a1);
    //     v7 = (a1[5787] + 10) >> 3;
    //     v8 = (a1[5791] + 10) >> 3;
    //     if (v8 <= v7) v7 = v8;
    //   }
    //   if (a2 && a3 + 4 <= v7) {
    //     BitstreamWriteBits(a1, a3, a4);
    //   } else {
    //     v11 = a1[5805];
    //     value = (v8 == v7) ? (a4 + 2) : (a4 + 4);
    //     if (v11 <= 13) { a1[5803] |= value << v11; a1[5805] = v11 + 3; }
    //     else { flush a1[5803] bytes at a1[8] + a1[20]; a1[20] += 2; a1[5805] = v11 - 13; }
    //     if (v8 == v7) HuffmanBitStreamDecoder(&unk_5B8280);
    //     else { BitBufferWriter(a1[2846] + 1, v5 + 1); HuffmanBitStreamDecoder(a1 + 2430); }
    //   }
    //   result = ScorecardZero(a1);
    //   return (a4 != 0) ? UnicodeBufferFlusher() : result;
    // UNRESOLVED: The packet lists a read of the global unk_5B7E00, but the raw source text does not render an explicit reference to it; it likely feeds an inlined constant or a sub-call and is not mapped to a specific operation.
    // UNRESOLVED: The mapping of the tree arrays at a1+2830 (literal/length) and a1+2842 (distance) is an interpretation from the existing analysis fill, not independently evidenced; the same applies to the roles of a1+5803/a1+5805 as a bit accumulator/cursor.
    // UNRESOLVED: The meaning of the a2 parameter (raw-write gate) and of the a1+28 block-type encoding (2 = compressed) is inferred from deflate semantics and the fill, not proven.
    // UNRESOLVED: The distinction between the v8 == v7 literal branch (calls HuffmanBitStreamDecoder on the global table) and the distance branch (calls BitBufferWriter and rebuilds the a1+2430 table) follows the raw control flow but the exact symbol tables involved are DERIVED.
}
