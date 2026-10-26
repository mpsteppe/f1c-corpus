// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517FD0
// Canonical corpus name: sub_517FD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_517FD0_00517fd0.c

void UnknownObject::ValidateChunkType()
{
    // Validates a four-byte chunk-type header pointed to by a2. Each byte must satisfy 0x29 <= v <= 0x7A and must not fall in the gap 0x5A < v < 0x61. On the first invalid byte the function calls DoubleBufferInit(a1, "invalid chunk type") and returns its result. When all four bytes are valid it returns the fourth byte a2[3].
    // GUARD: Validate a2[0]: fail unless 0x29 <= v <= 0x7A and v is not in the gap 0x5A < v < 0x61. [source:raw]
    // GUARD: Validate a2[1] with the same chunk-type range test; on failure fall through to the error report. [source:raw]
    // GUARD: Validate a2[2] with the same chunk-type range test; on failure fall through to the error report. [source:raw]
    // GUARD: Validate a2[3] with the same chunk-type range test; on failure fall through to the error report. [source:raw]
    // CALL: Report an invalid chunk: call DoubleBufferInit(a1, "invalid chunk type"), the message string being the read-only global aInvalidChunkTy at 0x005AFB18, and return its result. [callee:0x0051189C, global:0x005AFB18]
    // RETURN: Return a2[3] (the fourth chunk-type byte) once all four bytes have passed validation. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned __int8 ValidateChunkType(int a1, unsigned __int8 *a2) {
    //     unsigned __int8 c;
    //     for (int i = 0; i < 4; ++i) {
    //       c = a2[i];
    //       if (c < 0x29u || c > 0x7Au || (c > 0x5Au && c < 0x61u))
    //         return DoubleBufferInit(a1, "invalid chunk type");
    //     }
    //     return a2[3];
    //   }
    // UNRESOLVED: Meaning of the four-byte chunk type and how a2 is laid out in the caller sub_518FCF is unknown; the header appears archive/chunk related.
    // UNRESOLVED: DoubleBufferInit semantics and why the error is routed through it are not established from this function alone.
}
