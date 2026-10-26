// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595207
// Canonical corpus name: FAILOverviewSays96BitBitmapButSourceIsArbitraryS
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FAILOverviewSays96BitBitmapButSourceIsArbitraryS_00595207.c

void UnknownObject::BitArrayIncrementCarryPropagate()
{
    // Increment-style operation over an array of 32-bit words treated as a big bit string of arbitrary length. It adds a single-bit mask at bit position (31 - a2 % 32) into the word at index a2 / 32 via OverflowCheckedUnsignedAddition, then, while the previous add reports overflow, propagates a carry by adding 1 to each preceding word in turn. Returns the last overflow indicator from the propagation chain.
    // CALCULATION: Compute the target word index a2 / 32 and the bit mask 1 << (31 - a2 % 32) for the addressed bit position. [source:raw]
    // CALL: OverflowCheckedUnsignedAddition adds the bit mask to the word at a1 + 4 * (a2 / 32), storing the result back at that word; its return value reports overflow. [callee:0x00597547, source:raw]
    // GUARD: Guard on v3 = a2 / 32 - 1 >= 0; carry propagation only runs while there are lower words to carry into. [source:raw]
    // LOOP: do-while loop over preceding words (a2 / 32 - 1 down to 0) that stops early once an add stops overflowing. [source:raw]
    // CALL: For each preceding word, OverflowCheckedUnsignedAddition adds 1 to that word and stores it back; result keeps the overflow indicator. [callee:0x00597547, source:raw]
    // RETURN: Return the final overflow indicator result from the last addition performed. [source:raw]
    // CALL: Called by BitArrayClearBitAndZeroFillSubsequentWords (0x0059525D) as the bit-array word-update helper. [caller:0x0059525D, abi:lead, function:0x00595207, source:raw]

    // Conservative worker pseudocode:
    //   int sub_595207(int a1, int a2) {
    //     int result = OverflowCheckedUnsignedAddition(*(_DWORD *)(a1 + 4 * (a2 / 32)),
    //                                                 1 << (31 - a2 % 32), a1 + 4 * (a2 / 32));
    //     int v3 = a2 / 32 - 1;
    //     if (v3 >= 0) {
    //       _DWORD *v4 = (_DWORD *)(a1 + 4 * v3);
    //       do {
    //         if (!result) break;
    //         result = OverflowCheckedUnsignedAddition(*v4, 1, v4);
    //         --v3; --v4;
    //       } while (v3 >= 0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Direction of the carry semantics depends on whether OverflowCheckedUnsignedAddition returns nonzero on overflow or on success; the loop break condition implies nonzero means continue propagating.
    // UNRESOLVED: Whether the caller treats the array as a big bit string or as packed numeric words is not established by this function alone.
}
