// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F062
// Canonical corpus name: ByteCounterIncrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteCounterIncrement_0044f062.c

void UnknownObject::ByteCounterIncrement()
{
    // Adds the byte value a1 into the byte stored 94 bytes past the buffer pointer a2 (a2+94) and always returns -1. Only arguments a1 and a2 are used; a3, a4 and a5 are declared but never consumed. The leading source comment flags a detected positive stack adjustment, so the reconstructed ABI may be unreliable.
    // ASSIGNMENT: Byte increment: *(BYTE*)(a2 + 94) += a1, accumulating the byte argument a1 into the counter byte at offset 94 of the buffer referenced by a2. [source:raw]
    // RETURN: Always returns -1, independent of the byte accumulation. [source:raw]

    // Conservative worker pseudocode:
    //   int ByteCounterIncrement(char a1, int a2 /*, int a3, int a4, int a5 unused* /) {
    //       *(BYTE*)(a2 + 94) += a1;
    //       return -1;
    //   }
    // UNRESOLVED: The object behind pointer a2 and the meaning of the counter byte at offset 94 are not documented by the packet.
    // UNRESOLVED: The legacy prototype name Byte_Counter_Increment (abi:lead) is marked LEGACY; no caller or callee context exists to confirm its ABI or calling convention.
    // UNRESOLVED: The flagged positive stack adjustment means the userpurge parameter layout for a1/a2/a3/a4/a5 may be wrong.
}
