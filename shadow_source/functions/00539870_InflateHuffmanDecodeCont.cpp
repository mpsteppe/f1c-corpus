// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00539870
// Canonical corpus name: sub_539870
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_539870_00539870.c

void UnknownObject::InflateHuffmanDecodeCont()
{
    // Huffman symbol decode continuation of an inflate decompression state machine. Dispatches on the decode state stored at this+0x0 via the jump table jpt_5398B8 (0x00539F30), consuming a bitstream through a bit accumulator (this+0x8) with bit count (this+0x18), decoding literal/length and distance symbols via the dword_5DBB90 lookup table, copying matches from output history through sub_53A7B0 and output via AudioRingBufferCopy, and tracking the remaining match length in this+0x4. Invalid literal and distance codes reference the aInvalidLiteral_0 and aInvalidDistanc_0 error strings. Called from sub_537110 (0x00537110).
    // GUARD: Dispatch on the decode state stored at this+0x0 using the jump table jpt_5398B8 (state 0=copy/literal, 1=length code, 2=extra bits, 3=dist code, 4=dist extra, 5=copy match, 6=single literal, 7/8=flush, 9=error per existing analysis). [global:0x00539F30, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Load the input bitstream current read pointer (obj+0x0, v6 = *a2) and decode-state object members a1[1], a1[7], a1[12] used to feed the accumulator. [field:obj:0x00000000, source:raw]
    // CALCULATION: Maintain the bit accumulator register at this+0x8 and the bit count at this+0x18 as bits are shifted in from the input stream. [field:this:0x00000008, field:this:0x00000018, source:raw]
    // CALCULATION: Decode literal/length and distance Huffman symbols by indexing the dword_5DBB90 lookup table with accumulator bits. [global:0x005DBB90, source:raw]
    // ASSIGNMENT: Track the repeat count / remaining match length at this+0x4 (initialized to 0) as matches are copied. [field:this:0x00000004, source:raw]
    // GUARD: On an invalid literal code, take the error path referencing the aInvalidLiteral_0 error string. [global:0x005DA964, source:raw]
    // GUARD: On an invalid distance code, take the error path referencing the aInvalidDistanc_0 error string. [global:0x005DA980, source:raw]
    // CALL: Call sub_53A7B0 to bulk-copy match data from the output history into the output buffer. [callee:0x0053A7B0, source:raw]
    // CALL: Call AudioRingBufferCopy to copy decompressed output data to the ring buffer. [callee:0x0053A660, source:raw]
    // STATE_TRANSITION: Advance the decode state at this+0x0 between literal/length/extra/dist/copy phases and loop back to the jump-table dispatch. [field:this:0x00000000, source:raw]
    // UNRESOLVED: The raw source text in the packet is truncated mid-function, so the full switch body (exact per-state bit orders and copy loops) is not fully evidenced.
    // UNRESOLVED: The exact Huffman table encoding behind dword_5DBB90 is not evidenced in this packet.
    // UNRESOLVED: The precise meaning and allocation owner of the this/obj decode-state object are unknown; fields are treated as DERIVED from existing analysis.
    // UNRESOLVED: The caller sub_537110 contract and where this decode state fits in the wider inflate pipeline are not in the packet.
}
