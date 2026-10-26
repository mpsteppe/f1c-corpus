// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B208
// Canonical corpus name: SingleByteWriteViaStream
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleByteWriteViaStream_0059b208.c

void UnknownObject::SingleByteWriteViaStream()
{
    // cdecl helper that performs a single-byte stream operation. Returns -1 immediately when the byte value a1 is the -1 sentinel. Otherwise it zeroes a local byte buffer v3, materializes the byte value into the byte at &a1 + 3, calls sub_59B092(&v4, &a1 + 3, 1, v3, 0) to transfer one byte and report a WCHAR into v4, and returns v4 when the call succeeds, or -1 when the call returned a negative value.
    // GUARD: Guard on a1 == -1: when a1 is the -1 sentinel, return -1 immediately. [source:raw]
    // ASSIGNMENT: HIBYTE(a1) = a1: materialize the byte value into the byte at &a1 + 3, which is the 1-byte source for the transfer. [source:raw]
    // ASSIGNMENT: Zero the local byte buffer: *(_DWORD *)v3 = 0. [source:raw]
    // CALL: v2 = sub_59B092(&v4, &a1 + 3, 1, v3, 0) < 0: perform the single-byte stream operation, reading one byte from the source and reporting the resulting WCHAR into v4; the local buffer v3 and flag 0 are passed through. [callee:0x0059B092, source:raw]
    // GUARD: Guard on !v2 (call did not return negative): when it holds, return v4; otherwise fall through to the default result -1. [source:raw]
    // RETURN: Return the WCHAR v4 produced by the stream on success, or -1 on failure/sentinel. [source:raw]
    // CALL: Invoked by StreamCreationWithFlagInit (0x0059A3A9) during stream-state initialization. [caller:0x0059A3A9, source:raw]

    // Conservative worker pseudocode:
    //   WCHAR sub_59B208(int byteValue) {
    //     if (byteValue == -1) return -1;
    //     HIBYTE(byteValue) = byteValue;
    //     CHAR local[6]; *(DWORD*)local = 0;
    //     WCHAR out;
    //     if (sub_59B092(&out, &byteValue + 3, 1, local, 0) < 0) return -1;
    //     return out;
    //   }
    // UNRESOLVED: The exact contract of sub_59B092 (stream object identity, direction read vs write, meaning of the flag 0) is not established by this packet.
    // UNRESOLVED: The local buffer v3 (6 bytes) is passed but its role in the transfer is unknown.
    // UNRESOLVED: The WCHAR v4 semantics depend on sub_59B092's return/out behavior.
}
