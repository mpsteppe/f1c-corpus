// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058924C
// Canonical corpus name: ByteBufferSwap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteBufferSwap_0058924c.c

void UnknownObject::byteBufferSwap()
{
    // Swaps a3 bytes between the buffers a1 and a2 in-place, element by element, advancing both pointers. No-op when the pointers are equal or a3 is zero. Returns the advanced a1 pointer (result starts at a1 and is incremented a3 times, so on the no-op path it equals a1). Used by sub_5890AA and sub_5891FE to exchange equal-sized byte blocks.
    // ASSIGNMENT: Initialize result = a1 and v4 = a2; result doubles as the advancing source pointer and return value. [source:raw]
    // GUARD: Only perform the swap when a1 != a2 and a3 is non-zero. [source:raw]
    // ASSIGNMENT: Initialize swap counter v5 = a3. [source:raw]
    // LOOP: Repeat a3 times: swap one byte (v6 = *result, *result++ = *v4, *v4++ = v6), decrementing v5 until zero. [source:raw]
    // RETURN: Return result, the a1 pointer advanced by a3 bytes. [source:raw]

    // Conservative worker pseudocode:
    //   result = a1; v4 = a2;
    //   if (a1 != a2 && a3) {
    //     v5 = a3;
    //     do {
    //       v6 = *result;
    //       *result++ = *v4;
    //       *v4++ = v6;
    //     } while (--v5);
    //   }
    //   return result;
    // UNRESOLVED: The packet field this+0x0 (read) has no correspondence in the raw source, which operates only on the a1/a2 pointer arguments; not used in any operation.
    // UNRESOLVED: No class is evidenced; owner is left UNKNOWN.
    // UNRESOLVED: Whether the buffers are byte strings or element arrays is not established.
}
