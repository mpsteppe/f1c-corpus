// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00539200
// Canonical corpus name: HuffmanBitStreamDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HuffmanBitStreamDecoder_00539200.c

void UnknownObject::HuffmanSymbolBitPacker()
{
    // Encodes pending literal/length/distance symbols into a Huffman-coded bitstream. Iterates the pending symbol buffer (byte count at a1+5779, symbol bytes at *(a1+5771), pending word list at *(a1+5783)) from index 0. For each symbol it looks up the length-code class via byte_5B84F8, packs the Huffman code word and its extra length/distance bits from the code tables in a2 (code word/length pairs at a2+4*class+1028/1030) and a3 (length-code pairs at a3+4*class), shifting each value into the 16-bit accumulator at a1+5803 and flushing full bytes into the output buffer (base at *(a1+8), byte cursor at a1+20) whenever the bit position at a1+5805 crosses 16. Match length/distance base values come from byte_5B82F8/byte_5B83F8 and their extra-bit counts from dword_5B7CB0/dword_5B7D28 with base offsets dword_5B85F8/dword_5B8670. Finally the end-of-block code at a2+1024/a2+1026 is packed with a final flush; the bit position is stored at a1+5805, the end-of-block length at a1+5799, and the a1 pointer is returned. Called by HuffmanBitStreamEncoder (0x005381F0).
    // ASSIGNMENT: Initialize result = a1, v64 = a2, index v4 = 0, and read the pending-symbol count from *(a1+5779). [source:raw]
    // GUARD: Loop body runs only when *(a1+5779) (pending symbol count) is non-zero. [source:raw]
    // LOOP: do-while loop over each pending symbol index v4: reads symbol byte v7 from *(a1+5771)+v4, pending word v5 from *(*(a1+5783) + 2*v4), and current bit position from *(a1+5805). [source:raw]
    // CALCULATION: For a non-zero pending word v5, resolve the length-code class v15 = byte_5B84F8[v7] and read its Huffman code word/length from the a2 code table at a2+4*v15+1028/1030. [source:raw, global:0x005B84F8]
    // CALCULATION: Pack the code into the 16-bit accumulator at a1+5803 shifted by the current bit position; when bitpos + code length <= 16 keep it in the accumulator, otherwise flush a full byte into the output buffer (base *(a1+8), cursor a1+20, advancing by 2) and carry the remainder into the accumulator. [source:raw]
    // CALCULATION: Append the extra length bits: count from dword_5B7CB0[v15] and base offset from dword_5B85F8[v15]; packs v26 = v7 - base with the same shift-and-flush accumulator logic and updates the bit position at a1+5805. [source:raw, global:0x005B7CB0, global:0x005B85F8]
    // CALCULATION: Decode the match length: v34 = v5 - 1; base value from byte_5B82F8[v34] when v34 < 0x100, else byte_5B83F8[v34 >> 7]; then pack the length Huffman code from the a3 table at a3+4*v35 (word at +0, length at +2) with the same shift-and-flush logic. [source:raw, global:0x005B82F8, global:0x005B83F8]
    // CALCULATION: Append the extra distance bits: count from dword_5B7D28[v35] and base offset from dword_5B8670[v35], packing v46 = v34 - base via the shift-and-flush accumulator and updating the bit position at a1+5805. [source:raw, global:0x005B7D28, global:0x005B8670]
    // CALCULATION: After the symbol loop, pack the end-of-block Huffman code read from the a2 table at a2+1024 (code word) and a2+1026 (code length), i.e. the field pair at byte offsets 0x400/0x402, with a final flush; then store the final bit position at a1+5805 and the end-of-block length at a1+5799. [field:this:0x00000400, field:this:0x00000402, source:raw]
    // CALL: Called by HuffmanBitStreamEncoder (0x005381F0) to serialize pending symbols into the compressed bitstream. [caller:0x005381F0, function:0x00539200, source:raw]
    // RETURN: Return result = a1 (the stream/state object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   // Pack pending literal/length/distance symbols into a Huffman bitstream.
    //   int sub_539200(int a1, int a2, int a3) {
    //     if (*(int*)(a1+5779)) {
    //       for (i = 0; i < *(int*)(a1+5779); ++i) {
    //         u8 sym = *(u8*)(*(int*)(a1+5771) + i);
    //         u16 w = *(u16*)(*(int*)(a1+5783) + 2*i);
    //         if (w) {
    //           put_length_code(a2, sym, byte_5B84F8);       // + extra bits (dword_5B7CB0/dword_5B85F8)
    //           put_match_length(a3, w, byte_5B82F8, byte_5B83F8);
    //           put_extra_bits(dword_5B7D28, dword_5B8670);   // distance extra bits
    //         } else {
    //           put_plain_code(a2, sym);
    //         }
    //       }
    //     }
    //     put_end_of_block(a2+1024, a2+1026);  // offsets 0x400/0x402
    //     *(int*)(a1+5805) = bitpos;
    //     *(int*)(a1+5799) = *(u16*)(a2+1026);
    //     return a1;
    //   }
    // UNRESOLVED: The canonical name HuffmanBitStreamDecoder and the caller name HuffmanBitStreamEncoder disagree about encode vs. decode; the raw body clearly writes bits into the output buffer at *(a1+8)/a1+20, which is an encode/bit-pack direction.
    // UNRESOLVED: Offsets a1+5771/5779/5783 (pending symbol buffers), a1+5803/5804/5805 (bit accumulator) and a1+8/a1+20 (output buffer/cursor) are unnamed state slots; their object layout is not established.
    // UNRESOLVED: The byte_5B82F8/byte_5B83F8 tables are interpreted as short/long match-length base lookups by the v34 < 0x100 split, which is DERIVED from the code rather than externally confirmed.
}
