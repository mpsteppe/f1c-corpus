// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051593F
// Canonical corpus name: F_2DArrayBlockCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DArrayBlockCopy_0051593f.c

void UnknownObject::F_2DArrayBlockCopy()
{
    // Row-block copy helper: copies a5 rows, each a6 bytes wide, from a source array (a1 + 4*a2) into a destination array (a3 + 4*a4). The 4-byte start offsets index rows by a stride of one pointer/word per element. Returns a pointer just past the last copied source row. When a5 is zero or negative the loop is skipped and only the initial pointer is returned.
    // ASSIGNMENT: result = (const void **)(a1 + 4*a2): source row pointer computed as byte address plus a 4-byte-per-element row offset. [source:raw]
    // ASSIGNMENT: v7 = (void **)(a3 + 4*a4): destination row pointer computed as byte address plus a 4-byte-per-element row offset. [source:raw]
    // GUARD: Guard on a5 > 0; the row loop is skipped entirely when the row count is not positive. [source:raw]
    // LOOP: do-while loop over a5 iterations using a countdown counter seeded from a5. [source:raw]
    // CALL: qmemcpy(*v7++, *result++, a6): copy one a6-byte row from the current source element to the current destination element, advancing both row pointers by one element after each copy. [source:raw]
    // RETURN: Return result, the source pointer advanced past all copied rows (or the initial source pointer when the loop never ran). [function:0x0051593F, source:raw]

    // Conservative worker pseudocode:
    //   const void **sub_51593F(int a1, int a2, int a3, int a4, int a5, unsigned int a6) {
    //     const void **src = (const void **)(a1 + 4 * a2);
    //     void **dst = (void **)(a3 + 4 * a4);
    //     for (int n = a5; n > 0; --n) qmemcpy(*dst++, *src++, a6);
    //     return src;
    //   }
    // UNRESOLVED: The 4-byte start-offset stride (a2/a4) implies the caller indexes arrays of pointer-sized (4-byte) elements, but the element type and whether a1/a3 are two-dimensional arrays are caller-supplied and unknown here.
    // UNRESOLVED: The a6-byte rows are copied as flat memory blocks; the in-memory element layout of each row is unknown.
    // UNRESOLVED: Four callers use this helper (TrackMapPixelFill, BufferInterleaveCopy, F_2DCopyDelegation, AudioSampleStream); their varied uses are consistent with a generic row-block copy but none is proven here.
}
