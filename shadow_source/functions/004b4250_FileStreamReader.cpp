// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4250
// Canonical corpus name: FileStreamReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileStreamReader_004b4250.c

void UnknownObject::FileStreamReader()
{
    // Writes a framed string record to a file stream: emits a 4-byte header, then a single length byte, then builds a zero-padded string buffer seeded from byte_5EA438, conditionally writes that buffer when the length byte is non-zero, null-terminates it and passes it to StringCopyWithBufferRealloc, then always returns 1. Called by ModelSceneFileLoader (004B6C90).
    // CALL: FileWriteWithBackendDispatch(this, 4) writes a 4-byte header to the stream [callee:0x00566C00, source:raw]
    // ASSIGNMENT: v4 = 0 initialises the length byte to zero [source:raw]
    // CALL: FileWriteWithBackendDispatch(&v4, 1) writes the single length byte [callee:0x00566C00, source:raw]
    // ASSIGNMENT: v5[0] = byte_5EA438[0] seeds the payload buffer's first byte from the read-only global buffer [global:0x005EA438, source:raw]
    // CALCULATION: memset(&v5[1], 0, 0xFC) zero-fills the remaining 252 bytes of the buffer [source:raw]
    // GUARD: If v4 is non-zero, FileWriteWithBackendDispatch(v5, v4) writes the payload and v2 is set to the length [callee:0x00566C00, source:raw]
    // ASSIGNMENT: v5[v2] = 0 null-terminates the payload at the carried length index [source:raw]
    // CALL: StringCopyWithBufferRealloc(v5) processes the assembled string buffer [callee:0x00566650, source:raw]
    // RETURN: Always returns 1 (success) regardless of the length byte [function:0x004B4250, source:raw]
    // CALL: Invoked by ModelSceneFileLoader (004B6C90) to emit the framed record during model scene loading [caller:0x004B6C90, source:raw]

    // Conservative worker pseudocode:
    //   FileWriteWithBackendDispatch(this, 4);
    //   v4 = 0;
    //   FileWriteWithBackendDispatch(&v4, 1);
    //   v5[0] = byte_5EA438[0];
    //   memset(&v5[1], 0, 0xFC);
    //   v2 = v4;
    //   if (v4) { FileWriteWithBackendDispatch(v5, v4); v2 = v4; }
    //   v5[v2] = 0;
    //   StringCopyWithBufferRealloc(v5);
    //   return 1;
    // UNRESOLVED: The 4-byte header write preceding the length byte is uninterpreted; its layout is not defined in this packet
    // UNRESOLVED: The result of StringCopyWithBufferRealloc is discarded and its purpose (buffer reallocation vs string copy) is unverifiable here
    // UNRESOLVED: byte_5EA438 is read-only here but never written in this function; its producer is unknown
    // UNRESOLVED: Local v6/v7 are zero-initialised but never otherwise used in the decompiled frame
}
