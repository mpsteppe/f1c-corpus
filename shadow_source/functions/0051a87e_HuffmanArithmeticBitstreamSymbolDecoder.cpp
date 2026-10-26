// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051A87E
// Canonical corpus name: HuffmanArithmeticBitstreamSymbolDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HuffmanArithmeticBitstreamSymbolDecoder_0051a87e.c

void UnknownObject::HuffmanArithmeticBitstreamSymbolDecoder()
{
    // Decodes one Huffman-coded symbol from a bitstream object. Extracts a code word of a5 bits from the bit accumulator (this+0xC) and remaining-bit-count (this+0x18), optionally refilling via sub_51A794 when the requested bit range is not already buffered. When the code word exceeds the table threshold at a4 + 4*a5 + 68, walks the Huffman tree one bit at a time, refilling through sub_51A794 when the bit count drops below 1, until a table entry is reached. Persists the accumulator and bit count back into this+0xC/this+0x18. On success returns the decoded symbol byte from the lookup table (bases a4+208, a4 + 4*v12 + 140, a4 + 4*v12, plus v9 + 17) when v12 <= 16. On decode failure writes 114 into vtable slot +0x14 of the parent context (*(this+0x1C)) and dispatches the vtable slot +0x4 error handler with (parent_context, -1), returning 0; refill failure returns -1.
    // GUARD: Choose the input path: when a3 >= a5 the caller-supplied accumulator a2 is used directly; otherwise the bitstream must be refilled before decoding. [source:raw]
    // CALL: Refill the bitstream accumulator through sub_51A794(a1, a2, a3, a5); a zero return means the refill failed and the decoder returns -1. [callee:0x0051A794, source:raw]
    // ASSIGNMENT: After a refill, reload the bit accumulator from this+0xC and the remaining bit count from this+0x18. [field:this:0x0000000C, field:this:0x00000018, source:raw]
    // CALCULATION: Extract the code word: v8 = v5 - a5 then v9 = ((1 << a5) - 1) & (v7 >> v8), masking the a5 most significant buffered bits. [source:raw]
    // GUARD: When the extracted code word v9 exceeds the table threshold at a4 + 4*a5 + 68, the code is not a leaf and the Huffman tree walk begins. [source:raw]
    // LOOP: Huffman tree walk: per iteration double the code word (v11 = 2 * v9), consume the next bit (v9 = (v7 >> --v8) & 1 | v11) and advance the consumed-length counter v12, refilling through sub_51A794 when v8 < 1 (returning -1 on failure), until v9 <= the current table entry. [callee:0x0051A794, source:raw]
    // ASSIGNMENT: Persist the decoder state back to the bitstream object: write the remaining bit count to this+0x18 and the accumulator to this+0xC. [field:this:0x00000018, field:this:0x0000000C, source:raw]
    // GUARD: Fast-path guard: when the consumed length v12 <= 16, return the decoded symbol byte computed from the decode table (base pointer at a4+208, cumulative table at a4 + 4*v12 + 140, table start at a4 + 4*v12, offset v9 + 17). [source:raw]
    // ASSIGNMENT: Decode-error path: write the literal 114 into vtable slot +0x14 of the parent context object reached through the parent pointer at this+0x1C (field:this:0x0000001C; vtable base at *(*(this+0x1C)+0x0)). [field:this:0x0000001C, field:*(*(this+0x1C)+0x0):0x00000014, field:*(this+0x1C):0x00000000, source:raw]
    // CALL: Decode-error dispatch: invoke the parent context vtable method at slot +0x4 (field:*(*(this+0x1C)+0x0):0x00000004) with (parent_context, -1), passing the parent pointer stored at *(this+0x1C) as receiver and -1 as argument. [field:*(*(this+0x1C)+0x0):0x00000004, field:*(this+0x1C):0x00000000, source:raw]
    // RETURN: Return values: decoded symbol byte on success (v12 <= 16), 0 on the decode-error path after dispatching the error handler, or -1 when a refill through sub_51A794 fails. [function:0x0051A87E, source:raw]
    // CALL: Invoked from TextureDecompression (0x0051A9C6), BitstreamDecoder (0x0051AF57), sub_51B154 (0x0051B154) and sub_51B45F (0x0051B45F). [caller:0x0051A9C6, caller:0x0051AF57, caller:0x0051B154, caller:0x0051B45F]

    // Conservative worker pseudocode:
    //   int HuffmanArithmeticBitstreamSymbolDecoder(Bitstream* bs, int acc, int sel, HuffTable* tab, int bitlen) {
    //     int v7, v8, v12 = bitlen;
    //     if (sel < bitlen) {
    //       if (!sub_51A794(bs, acc, sel, bitlen)) return -1;
    //       v7 = *(int*)((char*)bs + 0xC);   /* accumulator * /
    //       v8 = *(int*)((char*)bs + 0x18);  /* bit count  * /
    //     } else { v7 = acc; v8 = sel; }
    //     v8 = v8 - bitlen;
    //     v9 = ((1 << bitlen) - 1) & (v7 >> v8);
    //     if (v9 > *(int*)((char*)tab + 4 * bitlen + 68)) {
    //       while (v9 > *table) {
    //         v9 = ((v7 >> --v8) & 1) | (2 * v9);
    //         if (v8 < 1) {
    //           if (!sub_51A794(bs, v7, v8, 1)) return -1;
    //           v7 = *(int*)((char*)bs + 0xC);
    //           v8 = *(int*)((char*)bs + 0x18);
    //         }
    //         v12++;
    //       }
    //     }
    //     *(int*)((char*)bs + 0x18) = v8;
    //     *(int*)((char*)bs + 0xC)  = v7;
    //     if (v12 <= 16)
    //       return *(unsigned char*)(*(int*)((char*)tab + 208) + *(int*)((char*)tab + 4 * v12 + 140) - *(int*)((char*)tab + 4 * v12) + v9 + 17);
    //     *(int*)(**(int**)((char*)bs + 0x1C) + 20) = 114;
    //     (*(void(__cdecl**)(int, int))(**(int**)((char*)bs + 0x1C) + 4))(*(int*)((char*)bs + 0x1C), -1);
    //     return 0;
    //   }
    // UNRESOLVED: The Huffman table object a4 (threshold at a4 + 4*a5 + 68, tables at a4 + 4*v12 + 140 and a4 + 4*v12, base at a4 + 208) is not part of the deterministic field list; only the bitstream object fields are enumerated in the packet.
    // UNRESOLVED: The parent-context vtable method at slot +0x4 dispatched with (parent_context, -1) is an error handler, but its identity and meaning of the -1 argument are unknown.
    // UNRESOLVED: The meaning of the literal 114 written to the parent vtable slot +0x14 (likely an error/status constant) is unknown.
    // UNRESOLVED: The bitstream refill helper sub_51A794 is shared with other decoders; its handling of escape sequences is not evidenced in this packet.
}
