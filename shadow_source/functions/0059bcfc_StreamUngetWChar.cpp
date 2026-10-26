// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BCFC
// Canonical corpus name: sub_59BCFC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59BCFC_0059bcfc.c

void UnknownObject::StreamUngetWChar()
{
    // Pushes a WCHAR character back into an input stream buffer (analogous to ungetwc). Rejects WEOF and invalid stream state, lazily initializes the buffer via MemoryAllocatorInit, then either stores the character directly (wide mode) or converts it to a multibyte sequence via sub_596030 and pushes the bytes (narrow mode). The mode is selected by a stream flag bit (0x40) or by a per-encoding descriptor byte; the descriptor comes from a global default or the dword_8D4920 descriptor array keyed by stream[4]. On conversion failure it stores error 42 in the TLS slot returned by TLSOffsetGetter and returns -1. Only caller found statically is StreamReadWrapperWithLockUnlock (0059bcd2).
    // ASSIGNMENT: Save the WCHAR argument a1 into v2 for later stores. [source:raw]
    // GUARD: If a1 == 0xFFFF (WEOF sentinel) the character cannot be pushed back; return -1 immediately. [source:raw]
    // ASSIGNMENT: Read the stream state flags a2[3] into v4. [source:raw]
    // GUARD: Reject the call when the stream state is invalid: if bit0 is clear and (bit7 is clear or bit1 is set), return -1. [source:raw]
    // CALL: If the stream has no buffer yet (a2[2] == 0), call MemoryAllocatorInit(a2) to allocate and initialize it. [source:raw, callee:0x005957BD]
    // ASSIGNMENT: Re-read the stream state flags into v5 after the potential initialization. [source:raw]
    // CALCULATION: Resolve the mode descriptor v6: the default descriptor unk_5E7898 when stream[4] == -1, otherwise an entry of the dword_8D4920 descriptor array at row stream[4] >> 5 plus 36 * (stream[4] & 0x1F). [source:raw, global:0x005E7898, global:0x008D4920]
    // GUARD: Dispatch on stream mode: take the wide (direct WCHAR) path when flag bit6 (0x40) is set or the descriptor byte v6[4] >= 0; otherwise take the narrow (multibyte) path. [source:raw]
    // GUARD: Wide branch: if the buffer pointer equals the end pointer (stream[0] == stream[2]) and the count stream[1] is nonzero there is no room; return -1. [source:raw]
    // CALCULATION: Wide branch: extend the buffer by 2 (stream[0] += 2), increment the count stream[1] by 2, update the low flags byte to v5 & 0xEE | 1 (set bit0, clear bit1/bit4), step the pointer back 2 and write the flags back to stream[3]. [source:raw]
    // ASSIGNMENT: Wide branch: store the WCHAR as a 16-bit word at the current buffer position and return the stored word. [source:raw]
    // CALL: Narrow branch: call sub_596030(&a1, a1) to convert the WCHAR into a multibyte byte sequence; v7 is the resulting byte length (-1 signals conversion failure). [source:raw, callee:0x00596030]
    // GUARD: Narrow branch: on conversion error (v7 == -1) write error code 42 into the TLS slot returned by TLSOffsetGetter() and return -1. [source:raw, callee:0x0058AFCF]
    // CALCULATION: Narrow branch: if the buffer is at its end and the count is nonzero return -1; otherwise grow the buffer by v7, push the high byte (when v7 != 1) then the low byte of a1 as single bytes at the buffer, advance the count by v7 and set flag bit0. [source:raw]
    // RETURN: Narrow branch returns the original WCHAR v2 on success. [source:raw]

    // Conservative worker pseudocode:
    //   __int16 StreamUngetWChar(WCHAR ch, _DWORD *stream) {
    //     if (ch == 0xFFFF) return -1;
    //     int flags = stream[3];
    //     if ((flags & 1) == 0 && ((flags & 0x80) == 0 || (flags & 2) != 0)) return -1;
    //     if (stream[2] == 0) MemoryAllocatorInit(stream);
    //     flags = stream[3];
    //     char *desc = (stream[4] == -1) ? (char *)&unk_5E7898
    //                                   : (char *)(dword_8D4920[stream[4] >> 5] + 36 * (stream[4] & 0x1F));
    //     if ((flags & 0x40) != 0 || desc[4] >= 0) {
    //       if (stream[0] == stream[2]) { if (stream[1]) return -1; stream[0] += 2; }
    //       stream[1] += 2;
    //       stream[3] = (flags & 0xEE) | 1;
    //       stream[0] -= 2;
    //       *(_WORD *)stream[0] = ch;
    //       return *(_WORD *)stream[0];
    //     } else {
    //       int len = sub_596030((LPSTR)&ch, ch);
    //       if (len == -1) { *(_DWORD *)TLSOffsetGetter() = 42; return -1; }
    //       if (stream[0] == stream[2]) { if (stream[1]) return -1; stream[0] += len; }
    //       if (len != 1) *(_BYTE *)--stream[0] = HIBYTE(ch);
    //       *(_BYTE *)--stream[0] = (BYTE)ch;
    //       stream[1] += len;
    //       stream[3] = (stream[3] & 0xEE) | 1;
    //       return ch;
    //     }
    //   }
    // UNRESOLVED: Exact meaning of the stream flag bits in stream[3] (bit0 validity, bit1 reserve, bit6 wide flag, bit7) is only partially recovered from the guard structure.
    // UNRESOLVED: unk_5E7898 (default descriptor) and the dword_8D4920 descriptor array layout (row stride and 36-byte entries) are DERIVED from usage; the per-entry byte-4 mode field is inferred.
    // UNRESOLVED: sub_596030 conversion details and the TLS error-code slot semantics are defined in the callees, not here.
}
