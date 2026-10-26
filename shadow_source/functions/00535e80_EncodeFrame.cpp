// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00535E80
// Canonical corpus name: sub_535E80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_535E80_00535e80.c

void UnknownObject::EncodeFrame()
{
    // Encodes one frame or data chunk through a codec pipeline state object v4 (a1+28). Validates the encoder object, operation type a2 (0..4), and buffer presence; writes big-endian audio header words for codec type 42 and sets codec type 113; copies compressed buffers via BufferCopyWithSizeTracking; dispatches to a codec handler selected from funcs_536014 by 3*(codec+122); completes frames with BitstreamEncoder / BitstreamWriteBits. Returns 0 on success and negative error codes -2/-5 on validation failure, storing an error pointer at a1+24.
    // GUARD: Reject a null encoder object a1, a missing codec state v4 (a1+28), or an operation type a2 greater than 4 by returning -2. [source:raw, function:0x00535E80]
    // GUARD: Reject when a1+12 (input buffer) is absent, when a1+0 (output) is absent while a1+4 is present, or when the codec type v5 (v4+4) already equals 666 (final state) for a2 != 4; on rejection store the error pointer off_5DA82C[0] at a1+24 and return -2. [global:0x005DA82C, source:raw]
    // GUARD: Reject when a1+16 (output size field) is absent: store the error pointer off_5DA838[0] at a1+24 and return -5. [global:0x005DA838, source:raw]
    // ASSIGNMENT: Bind the pipeline: save the prior operation type v14 = v4+30, store the caller object a1 at v4+0, and set the operation type v4+30 to a2. [source:raw]
    // CALL: For codec type 42, compose an audio header word from codec+122, codec+38 and codec+98 (with an optional 0x20 bit), align it to 0x1F, set codec type v4+4 to 113, write the word via BigEndianShortWriter, then when codec+98 is set also write the caller fields a1+50 and a1+48 as 16-bit big-endian words and set a1+48 to 1. [callee:0x00536130, source:raw]
    // CALL: When codec+20 is non-zero, copy the compressed buffer via BufferCopyWithSizeTracking(a1); if a1+16 becomes zero afterward, set the operation type v4+30 to -1 and return 0. [callee:0x00536160, source:raw]
    // GUARD: Else, when a1+4 is absent and a2 <= v14 and a2 != 4, store the error pointer off_5DA838[0] at a1+24 and return -5. [global:0x005DA838, source:raw]
    // GUARD: Reject when the codec type is 666 (final state) but a1+4 (input) is present: store the error pointer off_5DA838[0] at a1+24 and return -5. [global:0x005DA838, source:raw]
    // GUARD: Short-circuit finalize when codec+106 is zero and (a2 == 0 or codec type is 666): for a2 == 4 write the trailing 16-bit header words via BigEndianShortWriter, flush via BufferCopyWithSizeTracking(a1), store -1 at codec+24, and return (codec+20 == 0); for a2 != 4 return 0. [callee:0x00536130, callee:0x00536160, source:raw]
    // CALL: Dispatch to the codec handler selected from the function table funcs_536014 at index 3*(codec+122), called with (v4, a2); when the handler returns 2 or 3, mark the codec type v4+4 as 666 (final state). [global:0x005B77F0, source:raw]
    // CALL: When the handler returned 1 (frame complete): for a2 == 1 run BitstreamEncoder(v4); otherwise write end bits via BitstreamWriteBits(0, 0), and for a2 == 3 zero the bitstream buffer at codec+58 over 2*(codec+66)-2 bytes; then copy via BufferCopyWithSizeTracking(a1), and if a1+16 becomes zero set the operation type v4+30 to -1 and return 0. [callee:0x00537FE0, callee:0x00537F30, callee:0x00536160, source:raw]
    // RETURN: Fall through to the finalize path (LABEL_45); when a1+16 is zero set the operation type v4+30 to -1, then return 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (!a1) return -2;
    //   codec = a1[7];
    //   if (!codec || a2 > 4) return -2;
    //   if (!a1[3] || (!a1[0] && a1[1]) || (type = codec[1]) == 666 && a2 != 4) { a1[6] = off_5DA82C[0]; return -2; }
    //   if (!a1[4]) { a1[6] = off_5DA838[0]; return -5; }
    //   v14 = codec[7]; codec[0] = a1; codec[7] = a2;
    //   if (type == 42) {
    //     v8 = min(((codec[30] - 1) >> 1), 3);
    //     v9 = (v8 << 6) | ((codec[9] << 12) - 30720) | (codec[24] ? 0x20 : 0);
    //     codec[1] = 113;
    //     BigEndianShortWriter(codec, v9 - v9 % 0x1F + 31);
    //     if (codec[24]) { BigEndianShortWriter(codec, a1[12]); BigEndianShortWriter(codec, a1[12]); }
    //     a1[12] = 1;
    //   }
    //   if (codec[5]) { BufferCopyWithSizeTracking(a1); if (!a1[4]) { codec[7] = -1; return 0; } }
    //   else if (!a1[1] && (int)a2 <= v14 && a2 != 4) { a1[6] = off_5DA838[0]; return -5; }
    //   if (codec[1] == 666 ? a1[1] : 0) { a1[6] = off_5DA838[0]; return -5; }
    //   if (!codec[26] && (!a2 || codec[1] == 666)) {
    //     if (a2 != 4) return 0;
    //     if (codec[6]) return 1;
    //     BigEndianShortWriter(codec, a1[12]); BigEndianShortWriter(codec, a1[12]);
    //     BufferCopyWithSizeTracking(a1); codec[6] = -1; return codec[5] == 0;
    //   }
    //   rc = funcs_536014[3 * codec[30]](codec, a2);
    //   if (rc == 2 || rc == 3) codec[1] = 666;
    //   if (rc == 1) {
    //     if (a2 == 1) BitstreamEncoder(codec);
    //     else { BitstreamWriteBits(0, 0); if (a2 == 3) memset(codec[14], 0, 2 * codec[16] - 2); }
    //     BufferCopyWithSizeTracking(a1); if (!a1[4]) { codec[7] = -1; return 0; }
    //   }
    //   if (rc && rc != 2) return finalize(a2, a1, codec);
    //   if (!a1[4]) codec[7] = -1;
    //   return 0;
    // UNRESOLVED: Callee 0x00536300 (DecompressionBufferFlush) is recorded as a call target but does not appear as an explicit call in the decompiled body; it may be inlined or reachable through a path not shown.
    // UNRESOLVED: The function table funcs_536014 entry layout (3 slots per codec type) and the exact handler signatures are unknown; the dispatch contract is inferred from the triple-indexed call.
    // UNRESOLVED: Codec constants 42, 113 and 666 are treated as opaque magic values; their meanings (audio header, audio type, final state) are inferred from usage only.
    // UNRESOLVED: Offsets within a1 (12, 16, 24, 48, 50) and codec (4, 20, 24, 30, 38, 58, 66, 98, 106, 122) are named by role only; no owner or field evidence is available.
    // UNRESOLVED: Ownership is unknown: caller names (BufferFillWithTimeout, FileReadLoop) and the codec globals suggest a buffered codec pipeline, but no owner is evidenced.
}
