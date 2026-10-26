// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598E9E
// Canonical corpus name: sub_598E9E
// Owner: CodecvtStreamBuffer [DERIVED]
// Raw source: functions/sub_598E9E_00598e9e.c

void CodecvtStreamBuffer::BufferedCharWriteWithCodecvtConversion()
{
    // Writes a single character into a buffered output stream that may carry a codecvt encoding-conversion facet. An end-of-stream sentinel (-1) returns 0 immediately. If the internal buffer still has room the byte is stored directly at the current write position. If the output device is absent it fails with -1; if no codecvt facet exists it falls back to a plain buffered write. Otherwise the character is converted through the facet vtable conversion entry point, and the converted bytes are flushed to the output device, returning the original character on success or -1 on any error.
    // GUARD: End-of-stream sentinel: when the character argument equals -1 the function returns 0 without writing. [source:raw]
    // CALL: Fast direct write: when the buffer-range check through the state pointers at this+0x20 and this+0x30 still has room, resolve the current write position with sub_599485 and store the character byte there, returning the character. [source:raw, field:this:0x00000020, field:this:0x00000030, field:*(this+0x20):0x00000000, field:*(this+0x30):0x00000000, callee:0x00599485]
    // GUARD: Missing output device: when the device pointer field at this+0x50 is null the write fails and returns -1. [source:raw, field:this:0x00000050]
    // CALL: Plain fallback: when the codecvt facet pointer at this+0x38 is null, delegate to BufferedCharacterWriteWithOverflowHandling with the output device, returning the character on success and -1 otherwise. [source:raw, field:this:0x00000038, callee:0x00589898, field:this:0x00000050]
    // CALL: Prepare conversion: stage the character in a local, then reset the temporary conversion buffer with BufferTruncationShrink(0, -1) and regrow it with BufferAppendWithMemset(8, 0). [source:raw, callee:0x00599348, callee:0x005992EF]
    // CALL: Snapshot stream buffer positions: refresh boundary markers on the buffer object reached through this+0x44 via BufferBoundaryMarkerCheckSet and read its next/end pointers at offsets 4 and 8. [source:raw, callee:0x00599534, field:this:0x00000044, field:*(this+0x44):0x00000004, field:*(this+0x44):0x00000008]
    // CALL: Invoke the codecvt conversion entry point (vtable slot index 5 of the facet object reached through this+0x38), passing the conversion state, the staged input character, output slot, and buffer position pointers; the result encodes ok/partial/error. [source:raw, field:this:0x00000038, field:*(this+0x38):0x00000000, field:*(*(this+0x38)+0x0):0x00000014]
    // STATE_TRANSITION: Interpret the conversion result: on the error case (2) fall back to a direct buffered write of the staged character; on partial with no input consumed fail with -1; otherwise continue to flush. [source:raw, callee:0x00589898]
    // RETURN: Flush the converted range: refresh boundary markers, compute the produced byte count as end minus begin, write that many bytes through FileReadWrapperWithLock to the output device, and return the character when the full count is written, otherwise -1. [source:raw, callee:0x00588678, callee:0x00599534, field:this:0x00000044, field:*(this+0x44):0x00000004]

    // Conservative worker pseudocode:
    //   int BufferedCharWriteWithCodecvtConversion(int this, int ch) {
    //     if (ch == -1) return 0;
    //     if (*(*(_DWORD**) (this + 32)) &&
    //         **(_DWORD**) (this + 32) < **(_DWORD**) (this + 32) + **(_DWORD**) (this + 48)) {
    //       *(_BYTE*) sub_599485(this) = (BYTE) ch;
    //       return ch;
    //     }
    //     if (!*(_DWORD*) (this + 80)) return -1;
    //     if (!*(_DWORD*) (this + 56))
    //       return BufferedCharacterWriteWithOverflowHandling((char) ch, *(_DWORD**) (this + 80)) != -1 ? ch : -1;
    //     /* codecvt path: stage ch, convert via facet vtable slot 5, then * /
    //     /* flush the converted bytes through FileReadWrapperWithLock * /
    //     return wrote_all ? ch : -1;
    //   }
    // UNRESOLVED: Global dword_5B9C38 (0x005B9C38) appears in the fact tables but is not referenced anywhere in the raw source; likely a stale attribution.
    // UNRESOLVED: The callee named FileReadWrapperWithLock is invoked to emit the converted bytes; its read-oriented name suggests a mis-named shared wrapper whose exact contract is unverified.
    // UNRESOLVED: The codecvt conversion state passed at this+0x40 is untyped in the raw source; its layout is unknown.
}
