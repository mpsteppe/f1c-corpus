// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057D660
// Canonical corpus name: BufferUnpackWithSizeCheckByteWordCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferUnpackWithSizeCheckByteWordCopy_0057d660.c

void UnknownObject::unpackPacketWithSizeCheckAndCopy()
{
    // Unpacks a structured packet from buffer a1: the header WORD at a1[0] is a declared payload size compared against a computed byte count derived from the bitfield at a2+36 (value >> 3 plus a carry bit when the low 3 bits are non-zero); on match, qmemcpy copies the payload bytes (starting 4 bytes past a1) to the destination pointer at a2+20. Regardless of the match, MemcpyLikeWithRealloc copies the trailing data block whose size is a1[1] from after the declared payload. Always returns 1. Called by sub_57CB50 (0057CB50).
    // CALCULATION: Set v2 to the payload start, a1 advanced by 2 words (4 bytes) past the header WORDs [field:this:0x00000000, field:this:0x00000002, source:raw]
    // GUARD: Compare the declared payload size in the header WORD at a1[0] against the computed byte count from the bitfield at a2+36 (value >> 3 plus 1 when the low 3 bits are non-zero); the payload qmemcpy runs only on equality [field:this:0x00000000, source:raw]
    // CALL: When the size guard passes, qmemcpy the computed byte count from the payload pointer v2 to the destination pointer stored at a2+20 [source:raw]
    // CALL: Call MemcpyLikeWithRealloc to copy the trailing data block starting after the declared payload, sized by the header WORD at a1[1] [callee:0x00587510, field:this:0x00000002, source:raw]
    // RETURN: Return constant 1 unconditionally [source:raw]
    // CALL: Invoked by sub_57CB50 (0057CB50) as part of its packet-decoding path [caller:0x0057CB50]

    // Conservative worker pseudocode:
    //   v2 = (char *)a1 + 4;
    //   declared_size = *a1;
    //   computed_size = (*(int *)(a2 + 36) >> 3) + ((*(int *)(a2 + 36) & 7) != 0);
    //   if (declared_size == computed_size)
    //     qmemcpy(*(void **)(a2 + 20), v2, computed_size);
    //   MemcpyLikeWithRealloc(&v2[*a1], a1[1]);
    //   return 1;
    // UNRESOLVED: The semantics of the bitfield at a2+36 (bit-packed length with possible flag bits) and the destination pointer at a2+20 are not established
    // UNRESOLVED: The meaning of the trailing MemcpyLikeWithRealloc copy destination (v2[*a1]) is not verifiable from this function alone
}
