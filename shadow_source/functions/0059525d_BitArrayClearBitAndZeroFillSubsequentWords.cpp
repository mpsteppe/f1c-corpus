// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059525D
// Canonical corpus name: BitArrayClearBitAndZeroFillSubsequentWords
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitArrayClearBitAndZeroFillSubsequentWords_0059525d.c

void UnknownObject::BitArrayClearBitAndZeroFillSubsequentWords()
{
    // Clears one bit in an arbitrary-size bit array and zero-fills the words after the target word. Given the array base a1 and a bit index a2, the bit at (a2 mod 32) within word (a2 / 32) is cleared. If that bit was set and the remainder of the range (from bit a2+1 onward) is not already clear, a failure handler is invoked and its result becomes the return value. If the cleared word is before the third word (the layout is capped at 96 bits per the overview), the trailing words are memset to zero. Returns 0 on the normal path.
    // ASSIGNMENT: Initialize the default return value v9 = 0 and compute the bit-location decomposition: word index v8 = a2 / 32, bit-within-word v4 = a2 % 32, shift v6 = 31 - v4, and a2 - 1 held in v2. [source:raw]
    // ASSIGNMENT: Compute the pointer to the target word v5 = a1 + 4 * (a2 / 32) and keep a saved copy v10 = v5. [source:raw]
    // GUARD: Guard on whether the target bit is already set: if (1 << (31 - v4)) & *v5 is non-zero the bit was set and must be cleared; otherwise the clear is a no-op. [source:raw]
    // CALL: When the target bit was set, check whether the remaining bit range starting at a2 + 1 is already clear via CheckIfBitRangeIsClearAcrossDwords(a1, a2 + 1). [callee:0x005951BE, source:raw]
    // CALL: If the remainder of the range is not clear, invoke the failure handler FAILOverviewSays96BitBitmapButSourceIsArbitraryS(a1, a2 - 1) and store its result as the return value v9. [callee:0x00595207, source:raw]
    // ASSIGNMENT: Restore the target word pointer v5 = v10, then clear the bit: *v5 &= (-1 << v6), keeping all other bits of the word intact. [source:raw]
    // GUARD: Guard on the word index being before the third word: if v8 + 1 < 3, zero-fill the remaining words with memset(a1 + 4 * (v8 + 1), 0, 4 * (3 - (v8 + 1))). [source:raw]
    // RETURN: Return v9, the failure-handler result if the range was not clear, otherwise 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_59525D(int bits, int bit_index) {
    //     int word_index = bit_index / 32;
    //     int bit_in_word = bit_index % 32;
    //     int *word = (int *)(bits + 4 * word_index);
    //     int result = 0;
    //     if ((1 << (31 - bit_in_word)) & *word) {
    //       if (!CheckIfBitRangeIsClearAcrossDwords(bits, bit_index + 1))
    //         result = FAILOverviewSays96BitBitmapButSourceIsArbitraryS(bits, bit_index - 1);
    //       word = (int *)(bits + 4 * word_index);
    //     }
    //     *word &= ~(1 << (31 - bit_in_word));
    //     if (word_index + 1 < 3)
    //       memset((char *)(bits + 4 * (word_index + 1)), 0, 4 * (3 - (word_index + 1)));
    //     return result;
    //   }
    // UNRESOLVED: The exact size of the bit array (apparently capped at 3 words / 96 bits by the zero-fill guard) and whether the FAILOverviewSays96BitBitmapButSourceIsArbitraryS handler returns an error code or a sentinel are not recoverable from this function alone.
}
