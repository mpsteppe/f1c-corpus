// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005123B3
// Canonical corpus name: sub_5123B3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5123B3_005123b3.c

void UnknownObject::SwapBytePairsByCount()
{
    // Conditional adjacent-byte-pair swap over the buffer a2. When the enable byte at this+0x9 equals 16 and the product of the dword count at this+0x0 and the stride byte at this+0xA is non-zero, swaps each adjacent byte pair of a2, iterating count*stride times and advancing the buffer pointer by two bytes per iteration.
    // GUARD: Proceed only when the byte at this+0x9 equals 16 (enable flag). [guard:0, field:this:0x00000009]
    // CALCULATION: Compute the iteration count as the dword at this+0x0 times the byte at this+0xA; the swap runs only while that product is non-zero. [field:this:0x00000000, field:this:0x0000000A]
    // LOOP: For each iteration, swap the adjacent byte pair at a2[0] and a2[1], then advance the buffer pointer by two bytes; repeat count*stride times. [source:raw, function:0x005123B3]

    // Conservative worker pseudocode:
    //   if (byte(this+0x9) == 16 && dword(this+0x0) * byte(this+0xA) != 0) {
    //       count = dword(this+0x0) * byte(this+0xA);
    //       while (count--) { swap(a2[0], a2[1]); a2 += 2; }
    //   }
    // UNRESOLVED: Object type behind this is unknown; the only recorded caller is sub_51389E (0x0051389E).
    // UNRESOLVED: The paired-byte swap is consistent with a 16-bit endianness conversion, but the buffer and value semantics are inferred, not packet-stated.
}
