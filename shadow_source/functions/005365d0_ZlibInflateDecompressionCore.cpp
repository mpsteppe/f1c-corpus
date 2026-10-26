// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005365D0
// Canonical corpus name: ZlibInflateDecompressionCore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZlibInflateDecompressionCore_005365d0.c

void UnknownObject::ZlibInflateDecompressionCore()
{
    // Core deflate compression loop over a zlib-style state object. Refills input via TextBufferDecompressor when the available byte count drops below 262, inserts each byte into a hash chain, finds the longest LZ77 match via ZlibDeflateLongestMatch, and emits either a literal byte or a length/distance pair while updating frequency tables. HuffmanBitStreamEncoder flushes buffered symbols and BufferCopyWithSizeTracking drains the output stream whenever the pending buffer reaches its limit.
    // LOOP: Outer while(1) loop consumes one input symbol (literal or length/distance match) per iteration until input is exhausted or a flush/buffer-full exit fires. [function:0x005365D0, source:raw]
    // GUARD: When the available byte count at a1+106 drops below 262, call TextBufferDecompressor(a1) to refill the input buffer. [callee:0x00536440, source:raw]
    // GUARD: After a refill, if the count is still below 262 and the flush flag a2 is zero, return 0 (need more input); if the count reaches zero, break the loop. [source:raw, function:0x005365D0]
    // CALCULATION: When the count is at least 3, compute the hash key v7 = state at a1+74 AND (input byte at a1+46 + pos + 2 XOR (previous hash at a1+62 shifted left by a1+78)) for hash-chain insertion. [source:raw, function:0x005365D0]
    // ASSIGNMENT: Store the hash-chain entry: write the previous chain value at a1+54 + 2*(pos AND a1+42), store the current position word at a1+58 + 2*new_hash, and update the hash state at a1+62. [source:raw, function:0x005365D0]
    // GUARD: If a chain entry v3 exists, the position is within the window (pos - v3 <= a1+34 - 262), and the mode at a1+126 is not 2, call ZlibDeflateLongestMatch(a1, v3) to extend the match. [callee:0x00536900, source:raw]
    // GUARD: If the match length at a1+86 is below 3, take the literal path: read one input byte, emit it to the output byte stream, and bump its literal-frequency counter. [source:raw, function:0x005365D0]
    // CALCULATION: Match path: compute distance = pos at a1+98 minus previous offset at a1+102, emit a length byte of match_len - 3, and update the length/distance frequency tables using the lookup tables byte_5B84F8, byte_5B83F8 and byte_5B82F8. [global:0x005B84F8, global:0x005B83F8, global:0x005B82F8, source:raw]
    // LOOP: Inner do-while loop continues hash-chain insertion per consumed byte while the match length counter at a1+86 is decremented toward zero. [source:raw, function:0x005365D0]
    // CALL: When the pending output buffer is full (pending count at a1+5779 equals the limit at a1+5775 minus 1), flush via HuffmanBitStreamEncoder(count, 0) and drain the output stream object with BufferCopyWithSizeTracking; return 0 if the stream reports full. [callee:0x005381F0, callee:0x00536160, source:raw]
    // CALL: On loop exit, perform the final flush: HuffmanBitStreamEncoder(pending count, a2 == 4) followed by BufferCopyWithSizeTracking(v29) on the output stream. [callee:0x005381F0, callee:0x00536160, source:raw]
    // RETURN: Return code from the set 0, 1, 2, 3 encoding flush status: 0 when more input is needed or the output stream is full, otherwise 1 + 2*(a2 == 4) when the stream is still writable. [function:0x005365D0, source:raw]

    // Conservative worker pseudocode:
    //   int ZlibInflateDecompressionCore(void* state, int flush) {
    //       int chain = 0;
    //       for (;;) {
    //           unsigned avail = read_avail(state);            // state+106
    //           if (avail < 262) {
    //               TextBufferDecompressor(state);
    //               avail = read_avail(state);
    //               if (avail < 262 && !flush) return 0;       // need more input
    //               if (avail == 0) break;
    //           }
    //           if (avail >= 3) {
    //               hash = mask(state) & (in[state + pos + 2] ^ (prev_hash << shift(state)));
    //               chain = lookup(hash);
    //               store_chain(state, pos & chain_mask(state), chain);
    //               store_pos(state, hash);
    //           }
    //           int match = ZlibDeflateLongestMatch(state, chain);  // if chain && in-window && mode != 2
    //           if (match < 3) {
    //               emit_literal(state, in[state + pos]);
    //               --avail;
    //           } else {
    //               emit_length_distance(state, match);  // uses byte_5B82F8/5B83F8/5B84F8
    //               advance_hash_chain(state, match);
    //           }
    //           ++pos;
    //           if (buffer_full(state)) {
    //               HuffmanBitStreamEncoder(pending, 0);
    //               BufferCopyWithSizeTracking(state->stream);
    //               if (stream_full(state)) return 0;
    //           }
    //       }
    //       HuffmanBitStreamEncoder(pending, flush == 4);
    //       BufferCopyWithSizeTracking(state->stream);
    //       return stream_full(state) ? (flush == 4 ? 2 : 0) : 1 + 2*(flush == 4);
    //   }
    // UNRESOLVED: Canonical/ABI names describe this as inflate/decompression, but the raw code performs deflate COMPRESSION: hash-chain insertion, longest-match search, and length/distance emission. Naming discrepancy is unresolved.
    // UNRESOLVED: The many state offsets (106, 98, 62, 74, 78, 46, 34, 118, 126, 82, 86, 102, 138, 1166, 2430, 5771, 5775, 5779, 5783) are treated as opaque; the packet provides no field evidence refs for them.
    // UNRESOLVED: The exact semantics of the lookup tables byte_5B82F8, byte_5B83F8 and byte_5B84F8 (distance base, extra bits, length base) are DERIVED in the existing analysis, not confirmed by the raw source.
}
