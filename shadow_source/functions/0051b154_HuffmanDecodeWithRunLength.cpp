// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051B154
// Canonical corpus name: sub_51B154
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51B154_0051b154.c

void UnknownObject::HuffmanDecodeWithRunLength()
{
    // Decodes a range of Huffman-coded symbols with run-length and distance encoding. Maintains a bit buffer inside a decode-state object (a1[101], this+0x194) carrying a bit accumulator, bit count, remaining-count and a Huffman tree pointer; refreshes a block counter via CounterUpdateWithZero when the block is exhausted, refills the buffer through sub_51A794, decodes symbols either through an embedded short-symbol table or HuffmanArithmeticBitstreamSymbolDecoder, and writes run-length/ distance-adjusted WORDs shifted by this+0x174 into the output array *a2, indexed via dword_5AF778. Persists all working state back to the object before returning 1, or 0 on any decoder/refill/counter failure.
    // GUARD: Block-counter refresh: when this+0xFC (a1[63]) is nonzero and the decode-state block counter v4[13] (this+0x1C8) is zero, calls CounterUpdateWithZero(a1) (callee 0x0051AEFC) and aborts with 0 if it reports failure. [callee:0x0051AEFC, field:this:0x000000FC, field:this:0x000001C8, function:0x0051B154, guard:0, source:raw]
    // ASSIGNMENT: Loads working state: decode-state pointer v4 = a1[101] (this+0x194), loop upper bound v26 = a1[91] (this+0x16C), output shift v25 = a1[93] (this+0x174), read/write pointer record at a1[5] (this+0x14 / this+0x18), and this+0x178 (a1[94]) into v19. [field:this:0x00000014, field:this:0x00000018, field:this:0x0000016C, field:this:0x00000174, field:this:0x00000178, field:this:0x00000194, source:raw]
    // GUARD: Short-circuit: if the remaining count v4[8] (this+0x1B4) is nonzero, v30 = v4[8] - 1 and control jumps to the epilogue, skipping the decode loop entirely. [field:this:0x000001B4, source:raw]
    // ASSIGNMENT: Initializes bit-buffer and loop registers: bit accumulator v8 = v4[4] (this+0x1A4), bit count v9 = v4[5] (this+0x1A8), Huffman tree pointer v27 = v4[18] (this+0x1DC), output base v24 = *a2, loop start v10 = a1[90] (this+0x168). [field:this:0x00000168, field:this:0x000001A4, field:this:0x000001A8, field:this:0x000001DC, source:raw]
    // LOOP: Decodes symbols for positions v31 in [this+0x168, this+0x16C]: each iteration refills the bit buffer via sub_51A794 when short, decodes a Huffman symbol (fast path through the short-symbol table embedded in the tree state, else HuffmanArithmeticBitstreamSymbolDecoder), then either extends a run, breaks with a remaining count, or writes a WORD to the output buffer. [callee:0x0051A794, callee:0x0051A87E, field:this:0x00000168, field:this:0x0000016C, field:this:0x000001DC, source:raw]
    // CALL: Refills the bit buffer through sub_51A794(&v17, v8, v9, nbits) when fewer than 8 bits remain; returns 0 immediately when the refill fails. [callee:0x0051A794, source:raw]
    // CALL: Decodes one Huffman symbol via HuffmanArithmeticBitstreamSymbolDecoder(&v17, v8, v9, v27, v11); a negative result aborts the whole decode with 0. [callee:0x0051A87E, field:this:0x000001DC, source:raw]
    // CALCULATION: Splits the decoded symbol v32 into a high length nibble v14 = v32 >> 4 and a low distance nibble v33 = v32 & 0xF. [source:raw]
    // STATE_TRANSITION: Run-length path (v33 == 0): a length nibble of 15 adds 15 to the position counter v31 and continues the loop; otherwise the remaining literal run v30 = (1 << v14) - 1 plus up to v14 extra bits, minus one, is computed and the loop breaks. [source:raw]
    // CALCULATION: Literal path (v33 != 0): advances v31 by v14, consumes v33 extra bits, forms v15 = (v8 >> v9) & ((1 << v33) - 1), combines it with dword_5B0488[v33] / dword_5B04C8[v33] into v16, and writes the shifted literal *(_WORD*)(v24 + 2*dword_5AF778[v31]) = v16 << v25 using the shift from this+0x174. [field:this:0x00000174, global:0x005AF778, global:0x005B0488, global:0x005B04C8, source:raw]
    // STATE_TRANSITION: Epilogue: persists decode state - read/write pointers stored back through the record at a1[5] (this+0x14 / this+0x18), this+0x178 restored to v19, bit count v9 saved to v4[5] (this+0x1A8), bit accumulator v8 saved to v4[4] (this+0x1A4). [field:this:0x00000014, field:this:0x00000018, field:this:0x00000178, field:this:0x000001A4, field:this:0x000001A8, source:raw]
    // STATE_TRANSITION: Final bookkeeping: decrements the block counter v4[13] (this+0x1C8), stores the remaining count v30 to v4[8] (this+0x1B4), and returns 1 on success. [field:this:0x000001C8, field:this:0x000001B4, source:raw]
    // RETURN: Aborts with 0 when CounterUpdateWithZero, the bit-buffer refill, or the symbol decoder reports failure. [callee:0x0051AEFC, callee:0x0051A794, callee:0x0051A87E, source:raw]

    // Conservative worker pseudocode:
    //   state = a1[101];                            // this+0x194
    //   if (a1[63] != 0 && state[13] == 0)          // this+0xFC, this+0x1C8
    //     if (!CounterUpdateWithZero(a1)) return 0;
    //   remaining = state[8];                       // this+0x1B4
    //   if (remaining) goto done;                   // decode already run this block
    //   read_ptr  = *(a1[5]);                       // this+0x14
    //   write_ptr = *(a1[5] + 4);                   // this+0x18
    //   saved = a1[94];                             // this+0x178
    //   bits  = state[4];                           // this+0x1A4
    //   nbits = state[5];                           // this+0x1A8
    //   tree  = state[18];                          // this+0x1DC
    //   out   = *a2;
    //   pos   = a1[90];                             // this+0x168
    //   end   = a1[91];                             // this+0x16C
    //   shift = a1[93];                             // this+0x174
    //   while (pos <= end) {
    //     if (nbits < 8 && !sub_51A794(&read_ptr, bits, nbits, 0)) return 0;
    //     sym = fast_table_or_HuffmanArithmeticBitstreamSymbolDecoder(&read_ptr, bits, nbits, tree);
    //     if (sym < 0) return 0;
    //     len = sym >> 4; dist_nib = sym & 0xF;
    //     if (dist_nib == 0) {
    //       if (len == 15) { pos += 15; continue; }      // run extension
    //       run = 1 << len;
    //       if (len) { refill_if_needed(len); run += ((1 << len) - 1) & (bits >> nbits); }
    //       remaining = run - 1; break;
    //     }
    //     pos += len;
    //     if (nbits < dist_nib) refill_if_needed(dist_nib);
    //     v = (bits >> nbits) & ((1 << dist_nib) - 1);
    //     literal = (v >= dword_5B0488[dist_nib]) ? v : v + dword_5B04C8[dist_nib];
    //     *(WORD*)(out + 2*dword_5AF778[pos]) = literal << shift;
    //     pos++;
    //   }
    //   *(a1[5]) = read_ptr;
    //   *(a1[5] + 4) = write_ptr;
    //   a1[94] = saved;
    //   state[5] = nbits;
    //   state[4] = bits;
    //   done:
    //   state[13]--;                                // this+0x1C8
    //   state[8] = remaining;                       // this+0x1B4
    //   return 1;
    // UNRESOLVED: The embedded short-symbol table inside the decode state (accessed through v27 with raw source offsets 212 and 1236) has no named packet field; those derived offsets are not promoted to field refs.
    // UNRESOLVED: The tables dword_5AF778, dword_5B0488, dword_5B04C8 are inferred to be output-offset/length/distance tables for the run-length coding; not independently proven.
    // UNRESOLVED: Semantic purpose of a1[94] (this+0x178), loaded into v19 and restored on exit, is unknown.
    // UNRESOLVED: Whether the pointer record at a1[5] aliases this+0x14/0x18 (self-referential) is not proven; only that a1[5] points at a two-dword read/write-pointer record.
    // UNRESOLVED: No owner or caller evidence exists; the owning object and invocation context are unknown.
    // UNRESOLVED: ABI lead name Huffman_Bitstream_Decoder is a legacy hint only; ownership trust stays UNKNOWN.
}
