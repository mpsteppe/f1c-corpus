// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00529B2C
// Canonical corpus name: sub_529B2C
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_529B2C_00529b2c.c

void UnknownObject::InflateDecompressionStateMachine()
{
    // Core deflate inflate loop: decodes literal/length and distance Huffman codes from a bit-stream state machine (cases 0-9), copies length-distance matches from a circular output window with wraparound, emits literals, invokes a fast decode path (sub_52C334) when a full run is available, and flushes the window through sub_52A5D7 when full or at block end. Part of the zlib-style stream decompressor.
    // ASSIGNMENT: Snapshot stream state into locals on entry: bit count (this+0x1C), bit buffer accumulator (this+0x20), and the circular output-window bounds (this+0x28 start, this+0x2C end); the input read pointer and remaining input count are taken from the a2 stream object. [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // CALCULATION: Compute the available output-window space from the write pointer (this+0x34) relative to the window capacity (this+0x30). [field:this:0x00000034, field:this:0x00000030, source:raw]
    // LOOP: Infinite state-machine loop dispatching on the decoder state through the state jump table; the decoder-state structure is referenced through this+0x4. [global:0x0052A068, field:this:0x00000004, source:raw]
    // CALL: case 0 fast path: when the free window space is at least 0x102 bytes and at least 0xA bits are buffered, flush the bit/stream state back into the structure fields (this+0x1C, this+0x20) and call sub_52C334 to decode a run; on a nonzero result branch to the completion state, otherwise fall through to per-symbol decoding. [callee:0x0052C334, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALCULATION: Decode a Huffman symbol: index the code table (this+0x8) with the bit buffer masked by the dword_5DA520 table entry for the current bit count, then consume the code's bit length from the table entry; this+0xC carries the per-node bit count. [field:this:0x00000008, field:this:0x0000000C, global:0x005DA520, source:raw]
    // STATE_TRANSITION: When the decoded symbol marks a length code, store the extra-bits/length base into this+0x10 and transition to the length-extra-bits state. [field:this:0x00000010, field:this:0x00000008, source:raw]
    // STATE_TRANSITION: Consume the length extra bits using the saved table state carried in this+0x10 and the per-stream byte fields this+0x14 and this+0x15, then set the table pointer from this+0x18 for the next step. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000015, field:this:0x00000018, source:raw]
    // CALCULATION: case 3: decode the distance code through its table (this+0x8) using the bit count (this+0xC) and consume the distance extra bits. [field:this:0x00000008, field:this:0x0000000C, field:this:0x0000001C, source:raw]
    // GUARD: Report the invalid-distance-code error string and transition to the error state when the distance symbol is invalid. [global:0x005B0840, source:raw]
    // GUARD: Report the invalid-literal/length-code error string and transition to the error state when the length symbol is invalid. [global:0x005B0858, source:raw]
    // LOOP: case 4/5 match copy: copy the length-distance match from the circular window, wrapping the source pointer from the window end (this+0x2C) back to the window start (this+0x28); decrement the remaining-length counter and write through this+0x30/this+0x34; flush via sub_52A5D7 when the run or window is exhausted. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: Persist the write pointer (this+0x34) into the stream structure and call sub_52A5D7 to flush or refill the output window when it is full or a block completes. [callee:0x0052A5D7, field:this:0x00000034, source:raw]
    // RETURN: Write the bit count and bit buffer back to this+0x1C and this+0x20, then return 1 on block end (state 8), -3 on stream/data error (state 9), or -2 from the default invalid state. [field:this:0x00000004, field:this:0x0000001C, field:this:0x00000020, source:raw]

    // Conservative worker pseudocode:
    //   // Deflate inflate core. this = inflate stream object; a2 = input stream;
    //   // state machine runs cases 0-9 with a Huffman decode loop.
    //   int InflateDecompressionStateMachine(strm, in, flags) {
    //     bits = strm->bitCount;      // this+0x1C
    //     buf  = strm->bitBuffer;    // this+0x20
    //     start = strm->winStart;    // this+0x28
    //     end   = strm->winEnd;      // this+0x2C
    //     for (;;) {
    //       switch (state->mode) {
    //         case 0:
    //           if (free_space >= 0x102 && bits >= 0xA) {
    //             store state back;
    //             r = sub_52C334(decoder_table_fields, strm, in);
    //             if (r) { state->mode = 7; continue; }
    //           }
    //           setup length-code table; state->mode = 1;
    //         case 1:
    //           symbol = decode_code(table, buf, bits, dword_5DA520);
    //           if (symbol & 0x10) { set length state; state->mode = 2; continue; }
    //           if (symbol & 0x40) error("invalid literal/length code");
    //           emit literal; state->mode = 6;
    //         case 3:
    //           dist = decode_distance(table, buf, bits, dword_5DA520);
    //           if (dist & 0x40) error("invalid distance code");
    //         case 4: case 5:
    //           copy match with wraparound between winStart and winEnd;
    //           decrement remaining length;
    //           flush via sub_52A5D7 when window full;
    //         case 6: emit literal byte; state->mode = 0;
    //         case 7: flush via sub_52A5D7;
    //         case 8: return 1;
    //         case 9: return -3;
    //         default: return -2;
    //       }
    //     }
    //   }
    // UNRESOLVED: Base ambiguity: the packet field offsets mix the stream object (bit count this+0x1C, bit buffer this+0x20, window bounds this+0x28/this+0x2C) with the inner decoder-state structure (this+0x4 through this+0x18); raw-source immediate offsets on the v6 pointer do not align 1:1 with the fact-table offsets, so the exact struct base per field is not established.
    // UNRESOLVED: The precise layout of the Huffman tables indexed through this+0x8 and of the dword_5DA520 bit-mask table is not derivable from this packet alone.
    // UNRESOLVED: The exact semantics of sub_52C334 (fast-path decoder) and sub_52A5D7 (window flush/refill) arguments are not available in this packet.
}
