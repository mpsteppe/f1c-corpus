// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BBD9
// Canonical corpus name: sub_59BBD9
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59BBD9_0059bbd9.c

void UnknownObject::StreamWriteWChar()
{
    // Stream output writer for a single wide character (__cdecl, WCHAR a1 into a stream buffer descriptor at a2). In wide mode (stream mode byte at a2+12 has bit 0x40 set, or the associated file state is considered valid) the WCHAR is stored directly into the buffer and the cursor advanced by 2 bytes, flushing via sub_59C1E7 when the remaining-space counter at a2+4 underflows. In narrow mode the character is converted to a multibyte sequence by sub_596030 (1 or 2 bytes, or -1 on conversion error which sets TLS error 42 and returns -1), each byte is written through the cursor while decrementing the per-buffer byte counter at v2[1], flushing via sub_58CF35 on underflow. Returns a1 on success or -1 on any failure.
    // GUARD: Select write mode: wide when the stream mode byte at a2+12 has bit 0x40 set, or when the file-state entry (default descriptor unk_5E7898 when the file index at a2+16 is -1, otherwise dword_8D4920[...]) reports a valid state (v3[4] >= 0); otherwise narrow (multibyte) mode. [source:raw, global:0x005E7898, global:0x008D4920, function:0x0059BBD9]
    // ASSIGNMENT: Wide path: decrement the remaining-space counter at a2+4 by 2 and detect underflow (becomes negative). [source:raw, function:0x0059BBD9]
    // CALL: Wide path flush: when the space counter underflows, call sub_59C1E7(a1, v2) to flush the buffer; its result is returned. [callee:0x0059C1E7, source:raw]
    // ASSIGNMENT: Wide path: write the 16-bit WCHAR a1 at the buffer cursor and advance the cursor by 2 bytes. [source:raw, function:0x0059BBD9]
    // CALL: Narrow path: call sub_596030 to convert the WCHAR a1 into a multibyte byte sequence, returning the byte count (1 or 2) or -1 on conversion error. [callee:0x00596030, source:raw]
    // GUARD: Narrow path: if the conversion returned -1, store error code 42 through TLSOffsetGetter and return -1. [callee:0x0058AFCF, source:raw]
    // ASSIGNMENT: Narrow path: decrement the per-buffer byte counter at v2[1] for each emitted byte (low byte of a1 for a 1-byte sequence; low byte then high byte BYTE1(a1) for a 2-byte sequence), writing each byte at the cursor and advancing it. [source:raw, function:0x0059BBD9]
    // CALL: Narrow path flush: when a byte counter underflows, call sub_58CF35(a2, v2) to flush the buffer and resume the byte write; a -1 result from any flush propagates as a -1 return. [callee:0x0058CF35, source:raw]
    // RETURN: Return a1 (the written WCHAR) on success, or -1 when the conversion failed or a flush helper returned -1. [source:raw, function:0x0059BBD9]
    // CALL: Called by ThreeStepStreamQuery (0x0059BBAF) as part of the stream character-output path. [caller:0x0059BBAF, source:raw]

    // Conservative worker pseudocode:
    //   short StreamWriteWChar(WCHAR c, StreamBuffer *buf) {
    //     bool wide = (buf->mode & 0x40) != 0
    //         || fileStateValid(buf->fileIndex == -1 ? &unk_5E7898
    //                                             : &dword_8D4920[fileIndex]);
    //     if (wide) {
    //       if (--buf->space < 0) return sub_59C1E7(c, buf);
    //       *(WORD*)buf->cursor = c; buf->cursor += 2;
    //       return c;
    //     }
    //     int n = sub_596030(&tmp, c);
    //     if (n == -1) { *TLSOffsetGetter() = 42; return -1; }
    //     if (n == 1) {
    //       if (--buf->count < 0) { if (sub_58CF35(buf) == -1) return -1; }
    //       else { *(BYTE*)buf->cursor = LOBYTE(c); }
    //     } else {
    //       if (--buf->count < 0) { if (sub_58CF35(buf) == -1) return -1; }
    //       else { *(BYTE*)buf->cursor++ = LOBYTE(c); }
    //       if (--buf->count < 0) { if (sub_58CF35(buf) == -1) return -1; }
    //       else { *(BYTE*)buf->cursor = HIBYTE(c); }
    //     }
    //     buf->cursor++;
    //     return c;
    //   }
    // UNRESOLVED: The exact contract of sub_596030 (return codes beyond -1/1/2 and how the multibyte sequence is produced) is not established from this packet alone.
    // UNRESOLVED: The file-state validity check at v3[4] >= 0 and the layout of the dword_8D4920 entries (stride 0x24) are not described by this packet.
    // UNRESOLVED: The structure of the buffer descriptor (v2) and the meaning of the cursor/counter split (v2[0], v2[1]) are inferred from usage, not confirmed.
}
