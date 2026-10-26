// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053A7B0
// Canonical corpus name: sub_53A7B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53A7B0_0053a7b0.c

void UnknownObject::HuffmanLZ77Decode()
{
    // Bitstream decompression core: decodes a Huffman-style token stream (length/literal tree a3 plus a distance tree a4) into an output buffer, using an LZ77 window with back-references. State is threaded through caller-supplied structures: bit accumulator and cursor live in a5[7]/a5[8]/a5[13], output bounds in a5[10]/a5[11]/a5[12], and the input cursor/limit in a6[0]/a6[1]/a6[2]. Bit masking uses the shared 0x005DBB90 lookup table indexed by a1/a2 and by tree-entry flag bytes. Returns 1 on a valid terminal match, -3 on invalid literal/distance (writing the matching error string into a6[6]), and 0 when output space or input is exhausted.
    // ASSIGNMENT: Load input stream state from a6: v6 = *a6 (read cursor) and v45 = a6[1] (remaining input bytes). [source:raw]
    // ASSIGNMENT: Load output and bit state from a5: v7 = a5[13] (write cursor), v8 = a5[12] (capacity), v9 = a5[8] (bit accumulator), v10 = a5[7] (bit position). [source:raw]
    // CALCULATION: Compute remaining output space v47: if the cursor is at or past capacity use a5[11] - cursor, otherwise capacity - cursor - 1. [source:raw]
    // ASSIGNMENT: Load the two table bit-mask values v51 = dword_5DBB90[a2] and v50 = dword_5DBB90[a1] from the shared 0x005DBB90 lookup table. [source:raw, global:0x005DBB90]
    // LOOP: Outer decode loop: repeat while remaining output space v47 >= 0x102 and remaining input v45 >= 0xA. [source:raw]
    // LOOP: Refill the bit accumulator from input bytes until at least 0x14 bits are buffered, shifting in 8 bits per byte and decrementing v45. [source:raw]
    // CALCULATION: Look up the first (length/literal) tree entry: v12 = a3 + 8 * (v9 & v50) and read its flag byte v13. [source:raw]
    // LOOP: Walk the length/literal tree: shift the accumulator by the entry's bit count, follow sub-table offsets (v12 += 8 * [v12+4] + 8 * (v9 & dword_5DBB90[v13])) until a terminal flag is reached. [source:raw, global:0x005DBB90]
    // GUARD: Tree terminal flag 0x10: a match token was decoded; take the low nibble v16 = v13 & 0xF as the extra bit count and compute the length value v46 from the entry plus the mask table. [source:raw, global:0x005DBB90]
    // STATE_TRANSITION: Tree terminal flags 0x40|0x20: valid terminal match; save the bit/input/output state back to a5 and a6 and return 1. [source:raw]
    // STATE_TRANSITION: Tree terminal flag 0x40 without 0x20: invalid literal; store the error string aInvalidLiteral_0 into the a6[6] error-slot, save state, and return -3. [source:raw, global:0x005DA964]
    // CALCULATION: Decode the distance: look up v49 = a4 + 8 * (v9 & v51) in the distance tree and walk it the same way as the length tree. [source:raw]
    // STATE_TRANSITION: Distance-tree terminal flag 0x40: invalid distance; store the error string aInvalidDistanc_0 into the a6[6] error-slot, save state, and return -3. [source:raw, global:0x005DA980]
    // CALCULATION: Distance-tree terminal flag 0x10: compute the distance value v22 from the entry plus the mask table, consume the remaining extra bits, and reduce the remaining output space v47 by the length v46. [source:raw, global:0x005DBB90]
    // LOOP: LZ77 back-reference copy: copy v46 bytes from (v7 - v22) into the output at v7, wrapping through the window base a5[10] / boundary a5[11] when the distance crosses the window start; advance v7. [source:raw]
    // ASSIGNMENT: Literal path: when a tree entry is empty (flag byte 0), emit the stored literal byte v12[4], advance v7, and decrement the remaining output space v47. [source:raw]
    // RETURN: When the outer loop exits (v47 < 0x102 or v45 < 0xA), save the remaining bit and stream state back into a5[7]/a5[8]/a5[13] and a6[0]/a6[1]/a6[2], and return 0. [source:raw, function:0x0053A7B0]

    // Conservative worker pseudocode:
    //   int sub_53A7B0(int a1, int a2, byte *lenTree, byte *distTree, int *st, byte **in) {
    //     v6 = *in; v45 = in[1];
    //     v7 = st[13]; v8 = st[12]; v9 = st[8]; v10 = st[7];
    //     v47 = (v7 >= v8) ? st[11] - v7 : v8 - v7 - 1;
    //     v50 = dword_5DBB90[a1]; v51 = dword_5DBB90[a2];
    //     do {
    //       refill_bits_until(v10 >= 0x14);        // shift input bytes into v9, 8 bits each
    //       e = lenTree + 8 * (v9 & v50);         // walk to a terminal flag byte
    //       if (e[0] & 0x10) {                    // match token
    //         v16 = e[0] & 0xF; v46 = e[4] + (v9 & dword_5DBB90[v16]);
    //         v49 = distTree + 8 * (v9 & v51);    // distance tree walk
    //         v22 = e[4] + (v9 & dword_5DBB90[i & 0xF]);
    //         v47 -= v46;
    //         copy v46 bytes from (v7 - v22) to v7, wrapping via st[10]/st[11];
    //       } else if (e[0] & 0x40) {
    //         in[6] = (e[0] & 0x20) ? NULL : aInvalidLiteral_0;
    //         save_state(); return (e[0] & 0x20) ? 1 : -3;
    //       } else {                              // empty entry: literal
    //         *v7++ = e[4]; --v47;
    //       }
    //     } while (v47 >= 0x102 && v45 >= 0xA);
    //     save_state(); return 0;
    //   }
    // UNRESOLVED: Exact compression format (Deflate/zlib-like Huffman length tree + distance tree + LZ77 window) is inferred from control flow and the invalid-literal / invalid-distance error strings; no format identifier is named in the packet.
    // UNRESOLVED: Precise meaning of the 0x20 flag (valid-terminal marker) and the boundary roles of a5[10] (window base) and a5[11] are DERIVED-level interpretations.
    // UNRESOLVED: Meaning of a1/a2 as indices into the 0x005DBB90 mask table is unresolved.
    // UNRESOLVED: Caller sub_539870 (0x00539870) and the structure owners of a5/a6 are unknown.
    // UNRESOLVED: Return value 1 path only occurs from the length-tree 0x40|0x20 terminal; whether it also encodes a match-length 0 is not established.
}
