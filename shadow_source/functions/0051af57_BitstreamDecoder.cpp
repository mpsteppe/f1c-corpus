// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051AF57
// Canonical corpus name: BitstreamDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitstreamDecoder_0051af57.c

void UnknownObject::BitstreamDecoder()
{
    // Decodes one block of bitstream data. Conditionally resets counter state via CounterUpdateWithZero when the block-count flag (this->0xFC) is nonzero and the decode-state remaining-block count (this->0x1C8) is zero. Then, if the sub-block count this->0x13C is positive, iterates over that many sub-blocks: reads Huffman-coded symbols from a byte stream using sub_51A794 refills and HuffmanArithmeticBitstreamSymbolDecoder, applies extra-bit threshold/base-offset tables dword_5B0488 / dword_5B04C8, accumulates per-symbol counts shifted by this->0x174, and writes 16-bit output words through a2. On exit persists the saved read pointer (this->0x14), write state (this->0x18), flag (this->0x178), bit accumulator (this->0x1A4), bit count (this->0x1A8) and decrements the remaining-block count (this->0x1C8). Returns 1 on success, 0 on stream failure.
    // GUARD: Guard on block-count flag: when this->0xFC == 0 the reset call is skipped (v3 = a1[63] == 0). CounterUpdateWithZero is reached only when this->0xFC != 0 AND the decode-state remaining-block count this->0x1C8 == 0. [guard:0, field:this:0x000000FC, field:this:0x000001C8, source:raw]
    // CALL: CounterUpdateWithZero(a1): resets counter state before decoding; if it returns 0 the whole function aborts with that result. [callee:0x0051AEFC]
    // ASSIGNMENT: Load decode-state pointer v4 = this->0x194 and shift value v28 = this->0x174; the decode state is retained as v32 for reload after refills. [field:this:0x00000194, field:this:0x00000174]
    // ASSIGNMENT: Load read-state pointer v7 = this->0x14; capture v19 = *v7 (byte cursor) and v20 = *(v7 + 4) (write state at this->0x18). [field:this:0x00000014, field:this:0x00000018]
    // ASSIGNMENT: Snapshot decode state: bit accumulator v34 = v4[4] (this->0x1A4), bit count v9 = v4[5] (this->0x1A8), and copy 5 dwords from v4 + 8 into v26 as per-block symbol counts; flag this->0x178 is saved as v21. [field:this:0x000001A4, field:this:0x000001A8, field:this:0x00000178]
    // GUARD: Guard on sub-block count: when this->0x13C <= 0 the whole decode loop is skipped and control jumps straight to the epilogue. [guard:1, field:this:0x0000013C, source:raw]
    // LOOP: Iterate over this->0x13C sub-blocks (index v31, loop continues while v31 < this->0x13C). Each pass walks the sub-block descriptor array at this->0x140 (v30 = a1 + 80, ++v30 per pass), loads descriptor v29 = *v30 and output word pointer v27 = *(a2 + 4 * v31). [field:this:0x0000013C, field:this:0x00000140]
    // CALCULATION: Resolve the code-tree node for the sub-block: v10 = v4[*(*(this + (v29 + 73) * 4) + 20) + 14] — a runtime-indexed lookup through the decode state using the sub-block descriptor. [field:this:0x00000194, field:this:0x00000140]
    // GUARD: When bit count v9 < 8, refill the bitstream by calling sub_51A794(&v19, v34, v9, 0); a zero return aborts with 0. On success bit accumulator v34 and bit count v9 are reloaded from the out-params, and v4 is restored from v32. [callee:0x0051A794, field:this:0x000001A4, field:this:0x000001A8]
    // CALCULATION: Extract v12 = (unsigned byte)(v34 >> (v9 - 8)) as the code-table index and look up v13 = *(v10 + 4 * v12 + 212), a short-code length entry in the code tree. [field:this:0x000001A4, field:this:0x000001A8, field:this:0x00000194]
    // CALL: If short-code entry v13 is nonzero, take the symbol length v14 = *(v12 + v10 + 1236) and subtract v13 from the bit count; otherwise call HuffmanArithmeticBitstreamSymbolDecoder(&v19, v34, v9, v10, 9); a negative return aborts with 0. Bit state reloaded from out-params afterwards. [callee:0x0051A87E, field:this:0x000001A4, field:this:0x000001A8]
    // GUARD: When extra bits are needed (v14 nonzero) and bit count v9 < v14, refill again via sub_51A794(&v19, v34, v9, v14); zero return aborts with 0; then v9 -= v14. [callee:0x0051A794, field:this:0x000001A4]
    // CALCULATION: Apply the extra-bits tables: mask v33 = (1 << v14) - 1, v16 = (v34 >> v9) & v33; if v16 >= dword_5B0488[v14] the symbol is v16 itself, otherwise v14 = v16 + dword_5B04C8[v14]. [global:0x005B0488, global:0x005B04C8, field:this:0x000001A4]
    // ASSIGNMENT: Accumulate the symbol into v26[v29 + 1] += v14 and write the shifted output word *v27 = (v26[v29 + 1] << this->0x174). [field:this:0x00000140, field:this:0x00000174]
    // STATE_TRANSITION: Epilogue persists decode state back to the object: *this->0x14 = v19 (saved read pointer), *(this->0x14 + 4) = v20 (write state this->0x18), this->0x178 = v21, this->0x1C8 -= 1 (decrement remaining-block count), this->0x1A4 = v34 (bit accumulator), this->0x1A8 = v9 (bit count), copy v26 back into decode state; return 1. [field:this:0x00000014, field:this:0x00000018, field:this:0x00000178, field:this:0x000001C8, field:this:0x000001A4, field:this:0x000001A8, function:0x0051AF57]
    // RETURN: All stream-failure paths (refill or symbol-decoder failure) return 0; the success path returns 1. [source:raw]

    // Conservative worker pseudocode:
    //   char BitstreamDecoder(_DWORD *this, int a2) {
    //       decode_state = this->0x194;
    //       shift = this->0x174;
    //       if (this->0xFC != 0 && decode_state[13] == 0) {
    //           if (!CounterUpdateWithZero(this)) return 0;
    //           decode_state = this->0x194;
    //       }
    //       read_state = this->0x14;
    //       cursor = *read_state;
    //       write_state = *(read_state + 4);
    //       saved_flag = this->0x178;
    //       acc = decode_state[4];
    //       bits = decode_state[5];
    //       copy block_counts[5] from decode_state + 8;
    //       if (this->0x13C > 0) {
    //           desc_iter = this->0x140;
    //           for (i = 0; i < this->0x13C; i++) {
    //               out_word = *(a2 + 4 * i);
    //               desc = *desc_iter++;
    //               tree = decode_state[*(*(this + (desc + 73) * 4) + 20) + 14];
    //               if (bits < 8) {
    //                   if (!sub_51A794(&cursor, acc, bits, 0)) return 0;
    //                   reload acc, bits;
    //               }
    //               index = (byte)(acc >> (bits - 8));
    //               len = *(tree + 4 * index + 212);
    //               if (len) { sym_len = *(index + tree + 1236); bits -= len; }
    //               else { sym_len = HuffmanArithmeticBitstreamSymbolDecoder(&cursor, acc, bits, tree, 9); if (sym_len < 0) return 0; reload acc, bits; }
    //               if (sym_len) {
    //                   if (bits < sym_len) { if (!sub_51A794(&cursor, acc, bits, sym_len)) return 0; reload acc, bits; }
    //                   bits -= sym_len;
    //                   mask = (1 << sym_len) - 1;
    //                   value = (acc >> bits) & mask;
    //                   sym_len = (value >= dword_5B0488[sym_len]) ? value : value + dword_5B04C8[sym_len];
    //               }
    //               block_counts[desc + 1] += sym_len;
    //               *out_word = block_counts[desc + 1] << shift;
    //           }
    //       }
    //       *read_state = cursor;
    //       *(read_state + 4) = write_state;
    //       this->0x178 = saved_flag;
    //       decode_state[13]--;
    //       decode_state[4] = acc;
    //       decode_state[5] = bits;
    //       copy block_counts back to decode_state + 8;
    //       return 1;
    //   }
    // UNRESOLVED: The 5-dword block-count array v26 copied from decode_state + 8 (and copied back on exit) has no packet field evidence ref; its exact role as per-sub-block symbol accumulators is inferred from usage.
    // UNRESOLVED: The runtime-indexed this + (v29 + 73) * 4 table (a1[v29 + 73]) and its +20 dereference form a dynamic field not present in the packet field list.
    // UNRESOLVED: The purposes of saved decode_state slots v4[6] / v4[7] (captured as v25) are not exercised by this function.
    // UNRESOLVED: No static callers and no frame path; the owning object (UnknownObject) is unconfirmed. ABI name BitstreamDecoder is LEGACY trust only.
    // UNRESOLVED: The 16-bit output words written through a2 are not covered by a packet field; a2 is an external output array.
    // UNRESOLVED: Exact codec (Huffman arithmetic vs JPEG-style extra-bits) is not pinned by evidence; semantics are decoded-usage DERIVED.
}
