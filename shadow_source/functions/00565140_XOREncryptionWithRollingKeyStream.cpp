// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565140
// Canonical corpus name: XOREncryptionWithRollingKeyStream
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/XOREncryptionWithRollingKeyStream_00565140.c

void UnknownObject::XOREncryptionWithRollingKeyStream()
{
    // Stream cipher primed from an object-held rolling key pointer: XORs len bytes of the destination buffer a2 with a rolling key stream. The key stream lives at a1 + 309 (dword index 325 of the object) and is refilled on demand by sub_564F10 in blocks of 16 dwords. Refill triggers when the pointer is null or the consumed offset since refill reaches 0x3F (63) bytes.
    // LOOP: Loop over the destination buffer for i in [0, a3), consuming one key byte and XORing one byte per iteration, and advancing a1[325] on every iteration. [source:raw]
    // GUARD: Before XORing, check whether the key pointer a1[325] is exhausted: refill when it is null or when its consumed offset (v6 - a1 - 1236) is at least 0x3F. [source:raw]
    // ASSIGNMENT: Reset the key pointer a1[325] to a1 + 309 (dword index 309) when a refill is needed. [source:raw]
    // CALL: Call sub_564F10(a1, a1 + 309, 16) to regenerate a 16-dword block of keystream into the a1 + 309 buffer. [callee:0x00564F10, source:raw]
    // ASSIGNMENT: XOR one output byte with the current keystream byte: *(_BYTE *)(i + a2) ^= *(_BYTE *)a1[325]. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_565140(_DWORD* a1, int dest, int len) {
    //     for (int i = 0; i < len; ++a1[325]) {
    //       unsigned int* key = a1[325];
    //       if (!key || (unsigned int)(key - a1 - 1236) >= 0x3F) {
    //         a1[325] = a1 + 309;
    //         sub_564F10(a1, a1 + 309, 16);
    //       }
    //       *(_BYTE*)(i + dest) ^= *(_BYTE*)a1[325];
    //       ++i;
    //     }
    //   }
    // UNRESOLVED: The keystream block is 16 dwords (64 bytes) at a1 + 309, but the refill check triggers at a consumed offset of 0x3F (63) bytes; the one-byte margin is unexplained.
    // UNRESOLVED: The owning object that holds the key pointer (dword index 325) and the generator state used by sub_564F10 is unknown.
    // UNRESOLVED: The caller 0x00563410 is not described in the packet beyond its address.
}
