// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B41B0
// Canonical corpus name: ShortComputation_41b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_41b0_004b41b0.c

void UnknownObject::ResetComparisonGlobalBlock()
{
    // Linear initializer for a small contiguous global block. Calls ArithmeticComparison_9780 with the address of the adjacent global dword_8AB6EC, zeroes the two neighboring globals dword_8AB6E4 and unk_8AB6E8, then returns a pointer to dword_8AB6E4. No branches and no other calls appear in the raw source.
    // CALL: Call ArithmeticComparison_9780(&dword_8AB6EC); the callee receives the address of the global immediately following the two zeroed fields. Its side effect on dword_8AB6EC is not visible in this function. [source:raw]
    // ASSIGNMENT: dword_8AB6E4 = 0; zero the first global of the block. [global:0x008AB6E4, source:raw]
    // ASSIGNMENT: unk_8AB6E8 = 0; zero the second (adjacent) field of the block. [source:raw]
    // RETURN: return &dword_8AB6E4; yield the base pointer of the zeroed portion of the block. [global:0x008AB6E4, source:raw]

    // Conservative worker pseudocode:
    //   int *sub_4B41B0() {
    //     ArithmeticComparison_9780(&dword_8AB6EC);
    //     dword_8AB6E4 = 0;
    //     unk_8AB6E8 = 0;
    //     return &dword_8AB6E4;
    //   }
    // UNRESOLVED: dword_8AB6EC is passed to ArithmeticComparison_9780 and sits directly after the two zeroed globals, but it has no global entry in this packet and is not otherwise touched here.
    // UNRESOLVED: The packet lists dword_8AB6E4 with rw=R although the raw source writes it to 0; the rw classification and the write conflict.
    // UNRESOLVED: The identity and side effects of ArithmeticComparison_9780 on dword_8AB6EC are outside this packet.
}
