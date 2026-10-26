// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561A15
// Canonical corpus name: ShortArrayFillWithStride
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortArrayFillWithStride_00561a15.c

void UnknownObject::ShortArrayFillWithStride()
{
    // Fills a2 elements of a 16-bit array starting at byte offset (a5 + 2*a1) with the value a3, advancing the write pointer by 2*a4 bytes (a4 words) after each element. Uses a do-while loop, so one element is written even when a2 is zero. Returns a3 unchanged. Called by sub_553D00.
    // ASSIGNMENT: Compute the word pointer start: v5 = (unsigned short *)(a1 + a1 + a5), i.e. byte offset a5 + 2*a1. [source:raw]
    // CALCULATION: Precompute the byte stride: v8 = 2 * a4 (a4 is a word stride). [source:raw]
    // ASSIGNMENT: Seed the return value: result = a3. [source:raw]
    // LOOP: do-while loop that runs a2 iterations, decrementing a2 and exiting when it reaches zero (at least one iteration always executes). [source:raw]
    // ASSIGNMENT: Write the 16-bit fill value at the current position: *v5 = a3. [source:raw]
    // CALCULATION: Advance the write pointer by the byte stride: v5 = (unsigned short *)((char *)v5 + v8). [source:raw]
    // RETURN: Return result, the original fill value a3. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_561A15(int wordIndex, int count, int value, int wordStride, int base) {
    //     unsigned short *p = (unsigned short *)(base + 2 * wordIndex);
    //     int byteStride = 2 * wordStride;
    //     do {
    //       *p = (unsigned short)value;
    //       p = (unsigned short *)((char *)p + byteStride);
    //     } while (--count);
    //     return value;
    //   }
    // UNRESOLVED: The strided fill pattern (skip a4 words between writes) belongs to caller sub_553D00; the target data layout is not established here.
    // UNRESOLVED: The do-while guarantees one write even for a2 == 0; whether callers rely on that is unknown.
}
