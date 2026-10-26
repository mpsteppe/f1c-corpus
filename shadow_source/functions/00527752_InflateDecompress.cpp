// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00527752
// Canonical corpus name: sub_527752
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_527752_00527752.c

void UnknownObject::InflateDecompress()
{
    // Outer DEFLATE inflate state machine (zlib-style): parses block headers (stored / fixed-Huffman / dynamic-Huffman), reads the dynamic-block code-length tables, builds the Huffman decode tables, drives the literal/length decode loop, and flushes the circular output window. Operates on an inflate-context object a1 (state field this+0x0, remaining-length this+0x4, loop counter this+0x8, work/table buffer this+0xC, decode bit count this+0x10, decode table this+0x14, bfinal flag this+0x18, bit count this+0x1C, bit accumulator this+0x20, max code length this+0x24, window bounds this+0x28/0x2C, window capacity this+0x30, output cursor this+0x34) and a stream object a2 (input pointer a2[0], input remaining a2[1], consumed counter a2[2], error-string slot a2[6], allocator/deallocator fn ptrs a2[8]/a2[9], owner a2[10]). Returns 1 on stream end, the sub_52A5D7 flush result when more input is needed, -2 on an invalid state, -3 on data/bitstream errors, -4 on table allocation failure. Called by sub_517ADC (InflateBlockProcessor).
    // GUARD: Entry/loop guard: if the state field (this+0x0) exceeds 9 the state is invalid; set return code -2 and jump to the state-persist/return path (LABEL_5). [field:this:0x00000000, guard:0, source:raw]
    // ASSIGNMENT: Snapshot stream state into locals on entry: input read pointer v7 = *a2, remaining input v82 = a2[1], bit accumulator v83 = this+0x20, bit count v84 = this+0x1C, output cursor v81 = this+0x34; compute available output-window space v80 from the window-end this+0x2C, window capacity this+0x30 and cursor. [field:this:0x0000001C, field:this:0x00000020, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // LOOP: Infinite state-machine loop: dispatch on the state selector (this+0x0) through the jump table jpt_5277CE (0x00527EC5); after each case, reload the state from this+0x0, restore the stream/pointer locals and continue until a return. [global:0x00527EC5, field:this:0x00000000, source:raw]
    // STATE_TRANSITION: case 0 (block header): top up the bit buffer to 3 bits from the input, then read bfinal = this+0x18 = v83 & 1 and block type = (v83 & 7) >> 1. Type 0 (stored): align bits and set state 1. Type 1 (fixed): consume 3 bits and build the fixed-Huffman tables. Type 2 (dynamic): consume 3 bits and set state 3. Type 3: invalid. [field:this:0x00000018, source:raw]
    // CALL: case 0 fixed-Huffman path: call ArithmeticComparison_a5a8 with four by-ref stack outputs to derive the fixed literal/length and distance table parameters, then call FieldSetterWithVTableAlloc to allocate the fixed decode tables; store the resulting table into this+0x4 and transition to state 6 (decode). If the allocation returns null, jump to the -4 memory-failure path. [callee:0x0052A5A8, callee:0x00529AF8, field:this:0x00000004, source:raw]
    // ASSIGNMENT: case 0 invalid block type: set the state to 9 (error), write the invalid-block-type error string (aInvalidBlockTy) into the stream error slot a2[6], persist bit state and go to the error return path (return -3). [global:0x005B0794, field:this:0x00000000, source:raw]
    // CALCULATION: case 1 (stored block header): top up to 16 bits and read LEN = this+0x4 = (u16)v83; guard `~v83 >> 16 != (u16)v83` (NLEN complement check); on mismatch set state 9, write the invalid-stored-block-lengths error string (aInvalidStoredB) into a2[6] and return -3. On match clear the bit state. [global:0x005B0774, field:this:0x00000004, source:raw]
    // STATE_TRANSITION: case 1 end-of-header transition: if the stored length (this+0x4) is zero (guard:1) finish the block immediately, selecting the next state from bfinal: state 7 when this+0x18 != 0 (guard:3, final block) or state 0 when this+0x18 == 0 (guard:4, more blocks); otherwise enter state 2 (stored copy). [field:this:0x00000004, field:this:0x00000018, guard:1, guard:3, guard:4, source:raw]
    // CALCULATION: case 2 (stored copy): copy up to min(this+0x4 remaining length, remaining input, available window space v80) bytes from the input pointer to the output window via qmemcpy; advance the read pointer, cursor, input counter and v80; decrement this+0x4. When the length reaches zero (guard:1) end the block (bfinal ? state 7 : state 0). [field:this:0x00000004, field:this:0x00000018, guard:1, guard:3, guard:4, source:raw]
    // CALL: case 2 window-full flush: when v80 (window space) reaches zero, persist the output cursor into this+0x34 and call sub_52A5D7 to flush/refill the output window; on refill recompute the window bounds from this+0x28/0x2C/0x30 and re-derive v80; if the window cannot be refilled, persist bit state, input counters and cursor, then return the sub_52A5D7 result. [callee:0x0052A5D7, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALCULATION: case 3 (dynamic block header): top up to 14 bits and read HLIT = v83 & 0x1F, HDIST = (v83 >> 5) & 0x1F and HCLEN = v83 >> 10 into this+0x4 (14-bit combined field). Guard: if HLIT or HDIST exceeds 0x1D, set state 9 and write the too-many-length-or-distance-symbols error string (aTooManyLengthO) into a2[6] (return -3). [field:this:0x00000004, global:0x005B0750, field:this:0x00000000, source:raw]
    // CALL: case 3 table allocation: allocate the code-length work table by calling the stream allocator a2[8](a2[10], HDIST + HLIT + 258, 4); store the pointer into this+0xC; if null, jump to the -4 memory-failure path. Consume the 14 header bits, clear this+0x8 and set state 4. [field:this:0x0000000C, field:this:0x00000008, source:raw]
    // LOOP: case 4 (read code-length code lengths): loop while this+0x8 < (HCLEN + 4) and while this+0x8 < 0x13 (guard:2): read a 3-bit code length into this+0xC + 4 * dword_5B06E8[this+0x8], where dword_5B06E8 is the fixed HCLEN order permutation table; increment this+0x8; afterwards zero-fill the remaining entries up to 0x13. Topping up the bit buffer may hit the need-more-input path. [field:this:0x00000008, field:this:0x0000000C, global:0x005B06E8, guard:2, source:raw]
    // CALL: case 4 build code-length tree: set this+0x10 (bit count) to 7, then call sub_52A426(this+0xC, &this+0x10, &this+0x14, this+0x24, a2) to build the code-length Huffman decode table at this+0x14 using the max-code-length parameter this+0x24; on a nonzero return free this+0xC via the deallocator a2[9] and jump to the error path (state 9 / -3). [callee:0x0052A426, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000024, source:raw]
    // LOOP: case 5 (read literal/length and distance code lengths): loop this+0x8 up to (HDIST + HLIT + 258). Decode each symbol from this+0x14 by indexing `this+0x14 + 8 * (v83 & dword_5DA520[this+0x10])` with the bit mask table dword_5DA520, reading the code bit length from table+1 and the symbol value from table+4. Values below 0x10 are stored directly into this+0xC; repeat codes 16/17/18 consume their extra bits and replicate the previous length or a run of zeros. Guard: if the run overruns the (HDIST + HLIT + 258) budget, free this+0xC and write the invalid-bit-length-repeat error string (aInvalidBitLeng) into a2[6], then return -3. [global:0x005DA520, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000008, global:0x005B0734, source:raw]
    // CALL: case 5 build tables: call sub_52A4A5((HLIT & 0x1F) + 257, (HDIST >> 5) + 1, this+0xC, bit counts 9/6 via stack vars, this+0x24, a2) to build the literal/length and distance Huffman trees; free the code-length buffer this+0xC via the deallocator a2[9]; on a nonzero result set state 9 when the result is -3 and return -3. On success call FieldSetterWithVTableAlloc with the computed table parameters and store the tree into this+0x4; a null allocation jumps to the -4 path; then set state 6. [callee:0x0052A4A5, callee:0x00529AF8, field:this:0x0000000C, field:this:0x00000004, source:raw]
    // CALL: case 6 (decode literals/lengths): persist the bit state (this+0x1C/0x20), input counters and cursor, then call sub_529B2C (the inner literal/length+distance decode state machine); if its result is not 1, return sub_52A5D7(a1, a2, a3). Otherwise call IndirectCallDispatch(this+0x4, a2) to run the decode trees, reload the stream state from a2, recompute the window space, and select the next state: 0 when bfinal (this+0x18) is 0 (guard:4) or 7 when it is set (guard:3). [callee:0x00529B2C, callee:0x0052A090, callee:0x0052A5D7, field:this:0x00000004, field:this:0x00000018, guard:3, guard:4, source:raw]
    // CALL: case 7 (end of block): persist the cursor to this+0x34 and call sub_52A5D7 to flush the window; if the window capacity (this+0x30) is consumed, set state 8 and return 1; otherwise persist bit state, counters and cursor and return the sub_52A5D7 result. [callee:0x0052A5D7, field:this:0x00000030, field:this:0x00000034, source:raw]
    // STATE_TRANSITION: case 8 (done): return 1 to signal complete decompression of the input stream. [source:raw]
    // RETURN: case 9 / error return path (LABEL_110/LABEL_6): persist the bit accumulator into this+0x20, the bit count into this+0x1C, and the remaining input count into a2[1], then return -3 for data errors or -4 for the allocation-failure path (LABEL_120). [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALL: need-more-input path (LABEL_114): persist the bit accumulator into this+0x20, the bit count into this+0x1C, the zeroed input count into a2[1], the consumed-byte counter into a2[2], the input read pointer into a2[0] and the output cursor into this+0x34, then call sub_52A5D7(a1, a2, a3) to request/await more input. [callee:0x0052A5D7, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000034, source:raw]

    // Conservative worker pseudocode:
    //   // Outer DEFLATE inflate state machine. a1 = inflate context (14 dwords),
    //   // a2 = stream object. States: 0=block header, 1=stored len, 2=stored copy,
    //   // 3=dynamic header, 4=code-lengths, 5=lit/len+dist lengths, 6=decode,
    //   // 7=post-block, 8=done, 9=error.
    //   int InflateDecompress(int *ctx, int *strm, int flush) {
    //     bits = ctx[7];         // this+0x1C bit count
    //     hold = ctx[8];         // this+0x20 bit accumulator
    //     in   = strm[0]; in_left = strm[1]; consumed = strm[2];
    //     out  = ctx[13];        // this+0x34 output cursor
    //     win_space = available(ctx[12], ctx[11], out);
    //     for (;;) {
    //       if (ctx[0] > 9) return -2;            // guard:0 invalid state
    //       switch (ctx[0]) {
    //         case 0: // block header: read 3 bits
    //           ctx[6] = hold & 1;                 // bfinal
    //           switch ((hold & 7) >> 1) {
    //             case 0: align(3); ctx[0] = 1; break;         // stored
    //             case 1:
    //               ArithmeticComparison_a5a8(&t0,&t1,&t2,&t3);
    //               if (!(ctx[1] = FieldSetterWithVTableAlloc(t0,t1,t2,t3,strm)))
    //                 goto memfail;
    //               consume(3); ctx[0] = 6; break;
    //             case 2: consume(3); ctx[0] = 3; break;       // dynamic
    //             default:
    //               ctx[0] = 9; strm[6] = "invalid block type"; goto dataerr;
    //           }
    //           break;
    //         case 1: // stored block: read LEN/NLEN
    //           fill_to(16);
    //           if (~hold >> 16 != (u16)hold) {
    //             ctx[0] = 9; strm[6] = "invalid stored block lengths"; goto dataerr;
    //           }
    //           ctx[1] = (u16)hold; hold = bits = 0;
    //           ctx[0] = ctx[1] ? 2 : (ctx[6] ? 7 : 0);   // guard:1, 3, 4
    //           break;
    //         case 2: // stored copy
    //           if (!win_space) {
    //             persist; r = sub_52A5D7(ctx, strm, flush);
    //             if (!recomputed_space) return r;
    //           }
    //           n = min(ctx[1], in_left, win_space);
    //           qmemcpy(out, in, n); in += n; out += n;
    //           ctx[1] -= n;
    //           if (!ctx[1]) ctx[0] = ctx[6] ? 7 : 0;   // guard:1
    //           break;
    //         case 3: // dynamic block header: 14 bits
    //           fill_to(14); ctx[1] = hold & 0x3FFF;
    //           if ((hold & 0x1F) > 0x1D || ((hold >> 5) & 0x1F) > 0x1D) {
    //             ctx[0] = 9; strm[6] = "too many length or distance symbols"; goto dataerr;
    //           }
    //           if (!(ctx[3] = alloc(strm[10], ((hold>>5)&0x1F)+(hold&0x1F)+258, 4)))
    //             goto memfail;
    //           consume(14); ctx[2] = 0; ctx[0] = 4;
    //         case 4: // read HCLEN code lengths
    //           while (ctx[2] < (ctx[1] >> 10) + 4) {
    //             fill_to(3);
    //             ctx[3][dword_5B06E8[ctx[2]]] = hold & 7; consume(3); ctx[2]++;
    //           }
    //           while (ctx[2] < 0x13) ctx[3][dword_5B06E8[ctx[2]++]] = 0;  // guard:2
    //           ctx[4] = 7;
    //           if (sub_52A426(ctx[3], &ctx[4], &ctx[5], ctx[9], strm)) {
    //             free(strm[10], ctx[3]); goto dataerr;
    //           }
    //           ctx[2] = 0; ctx[0] = 5;
    //         case 5: // read literal/length + distance code lengths
    //           while (ctx[2] < ((ctx[1]>>5)&0x1F) + (ctx[1]&0x1F) + 258) {
    //             fill_to(ctx[4]);
    //             e = &ctx[5][8 * (hold & dword_5DA520[ctx[4]])];
    //             nb = e[1]; val = e[4];
    //             if (val >= 0x10) { // repeat codes 16/17/18
    //               extra = (val == 18) ? 7 : 3;
    //               fill_to(nb + extra); hold >>= nb;
    //               run = extra + (hold & dword_5DA520[val - (val==18 ? 4 : 14)]);
    //               hold >>= ...; bits -= nb + extra;
    //               if (ctx[2] + run > ((ctx[1]>>5)&0x1F) + (ctx[1]&0x1F) + 258) {
    //                 free(strm[10], ctx[3]); ctx[0] = 9;
    //                 strm[6] = "invalid bit length repeat"; return -3;
    //               }
    //               prev = (val == 16 && ctx[2]) ? ctx[3][ctx[2]-1] : 0;
    //               do ctx[3][ctx[2]++] = prev; while (--run);
    //             } else {
    //               hold >>= nb; bits -= nb; ctx[3][ctx[2]++] = val;
    //             }
    //           }
    //           r = sub_52A4A5((ctx[1]&0x1F)+257, ((ctx[1]>>5)&0x1F)+1, ctx[3],
    //                         &ctx[4], &ctx[5], &v71, &v72, ctx[9], strm);
    //           free(strm[10], ctx[3]);
    //           if (r) { ctx[0] = (r == -3) ? 9 : ctx[0]; return -3; }
    //           if (!(ctx[1] = FieldSetterWithVTableAlloc(ctx[4], ctx[5], v71, v72, strm)))
    //             goto memfail;
    //           ctx[0] = 6;
    //         case 6: // decode literals/lengths via inner state machine
    //           persist(ctx, strm);
    //           if ((r = sub_529B2C(ctx, strm, flush)) != 1)
    //             return sub_52A5D7(ctx, strm, r);
    //           IndirectCallDispatch(ctx[1], strm);   // run decode trees
    //           reload stream/bit state; recompute win_space;
    //           ctx[0] = ctx[6] ? 7 : 0;             // guard:3 / guard:4
    //           break;
    //         case 7: // post-block flush
    //           persist(ctx, strm);
    //           r = sub_52A5D7(ctx, strm, flush);
    //           if (ctx[12] == ctx[13]) { ctx[0] = 8; return 1; }
    //           persist(ctx, strm); return sub_52A5D7(ctx, strm, r);
    //         case 8: return 1;
    //         case 9:
    //         default: return -3;
    //       }
    //     }
    //   memfail: return -4;
    //   dataerr: persist(ctx, strm); return -3;
    //   }
    // UNRESOLVED: The inflate-context base is a 14-dword object with two overlapping views: the persistent state fields (this+0x0..0x20) and the per-block table/bit fields (this+0x4..0x24). The raw-source dword indexing of a1 and the fact-table hex offsets agree arithmetically but the struct layout (union/overlay) is not proven by the packet.
    // UNRESOLVED: The error-string globals are matched to their literal text by IDA prefix names (aInvalidBlockTy, aInvalidStoredB, aTooManyLengthO, aInvalidBitLeng) plus the inlined string literals in the raw source; the exact global-address to string-text pairing was not independently cross-checked here.
    // UNRESOLVED: a3 (the flush-style third argument) is threaded unchanged into sub_52A5D7 and the need-more-input path; its exact semantic (flush vs finish) is not derivable from this packet.
    // UNRESOLVED: The decode-table entry layout (8 bytes: bit length at +1, symbol value at +4) is inferred from raw-source byte indexing of the table pointer and is not backed by a packet struct.
    // UNRESOLVED: The exact contracts of the callees (sub_52A5D7 window flush, sub_529B2C inner decode machine, sub_52A426 code-length tree builder, IndirectCallDispatch, FieldSetterWithVTableAlloc vtable layout) are caller-side and unverified here.
    // UNRESOLVED: The caller relation to sub_517ADC (InflateBlockProcessor) only establishes the driving context; the parent object's field mapping for a1 is not in this packet.
    // UNRESOLVED: dword_5DA520 is treated as a bit-mask table indexed by bit count; its full contents and dword_5B06E8's exact 19-entry order permutation are not dumped in the packet.
}
