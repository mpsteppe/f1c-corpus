// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D5AF0
// Canonical corpus name: FileReadWithXORDecode
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileReadWithXORDecode_004d5af0.c

void UnknownObject::FileReadXORDecodeTripleKey()
{
    // Opens the file path a1 in binary read mode, counts its byte size, writes a 4-byte size header to the output sink sub_4D5BE0, rewinds, then re-reads every byte decoding each one by XOR with a cycling 3-key scheme (keys 0x5C, 0xB4, 0x12) and writes the decoded bytes to the sink. Closes the file and returns the close result. When the open fails, writes four zero bytes to the sink and returns immediately.
    // CALL: Open the file path a1 in binary read mode via sub_587DB0, using the aRb ("rb") mode string; the handle is kept in v1. [callee:0x00587DB0, global:0x005BE828, source:raw]
    // GUARD: If the file failed to open (v1 null), write four zero bytes to the output sink via sub_4D5BE0 and return its result. [callee:0x004D5BE0, source:raw]
    // LOOP: Count the file size by repeatedly reading bytes via StreamGetcWithUnderflowHandler until EOF (-1), incrementing the size counter v6. [callee:0x00589FCC, source:raw]
    // CALL: Write the counted size v6 to the output sink as 4 bytes via sub_4D5BE0. [callee:0x004D5BE0, source:raw]
    // CALL: Rewind the file handle to offset 0 via sub_587F64(v1, 0, 0). [callee:0x00587F64, source:raw]
    // LOOP: Re-read the file; for each group of up to 3 bytes, XOR the first byte with 0x5C, the second with 0xB4 and the third with 0x12, writing each decoded byte to the sink via sub_4D5BE0, stopping when EOF (-1) is hit. [callee:0x00589FCC, callee:0x004D5BE0, source:raw]
    // CALL: Close the file handle with synchronization via FileCloseWithLock. [callee:0x00587D02, source:raw]
    // RETURN: Return the result of FileCloseWithLock. [callee:0x00587D02, function:0x004D5AF0, source:raw]

    // Conservative worker pseudocode:
    //   int read_xor_decoded(const char* path) {
    //     FILE* f = sub_587DB0(path, aRb);
    //     int size = 0;
    //     if (!f) return sub_4D5BE0(&size, 4);
    //     while (StreamGetcWithUnderflowHandler(f) != -1) ++size;
    //     sub_4D5BE0(&size, 4);
    //     sub_587F64(f, 0, 0);
    //     for (;;) {
    //       int c0 = StreamGetcWithUnderflowHandler(f); if (c0 == -1) break;
    //       char b0 = (char)(c0 ^ 0x5C); sub_4D5BE0(&b0, 1);
    //       int c1 = StreamGetcWithUnderflowHandler(f); if (c1 == -1) break;
    //       char b1 = (char)(c1 ^ 0xB4); sub_4D5BE0(&b1, 1);
    //       int c2 = StreamGetcWithUnderflowHandler(f); if (c2 == -1) break;
    //       char b2 = (char)(c2 ^ 0x12); sub_4D5BE0(&b2, 1);
    //     }
    //     return FileCloseWithLock(f);
    //   }
    // UNRESOLVED: The consumer of the output sink (sub_4D5BE0) and the exact meaning of the decoded stream are not visible here; the existing analysis ties it to telemetry data loading.
    // UNRESOLVED: Whether the byte count and the decoded payload share the same sink stream or are separate is not confirmed.
}
