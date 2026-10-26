// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005619F1
// Canonical corpus name: F_16BitShortArrayFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_16BitShortArrayFill_005619f1.c

void UnknownObject::F_16BitShortArrayFill()
{
    // Fills a run of a2 consecutive 16-bit words starting at byte offset (a4 + 2*a1) with the value a3. a1 is a word-index offset into the buffer at a4. Returns the fill value a3 unchanged. Called by ClampedPixelSpanFill (0x00553CD0).
    // ASSIGNMENT: Compute the word pointer start: v4 = (unsigned short *)(a1 + a1 + a4), i.e. byte offset a4 + 2*a1. [source:raw]
    // ASSIGNMENT: Seed the return value: result = a3. [source:raw]
    // LOOP: while loop that writes a2 elements, decrementing a2 and terminating when it reaches zero. [source:raw]
    // ASSIGNMENT: Write the 16-bit fill value and advance: *v4++ = a3. [source:raw]
    // RETURN: Return result, the original fill value a3. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5619F1(int wordIndex, int count, int value, int base) {
    //     unsigned short *p = (unsigned short *)(base + 2 * wordIndex);
    //     while (count) { *p++ = (unsigned short)value; --count; }
    //     return value;
    //   }
    // UNRESOLVED: a1 is interpreted as a word index because the pointer is a1 + a1 + a4; the target buffer semantics belong to caller ClampedPixelSpanFill (0x00553CD0).
    // UNRESOLVED: Why the fill value a3 is returned unchanged (caller convention) is not established here.
}
