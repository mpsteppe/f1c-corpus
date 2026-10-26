// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A55A
// Canonical corpus name: BinaryIntervalSearchForMatchingRange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinaryIntervalSearchForMatchingRange_0058a55a.c

void UnknownObject::BinaryIntervalSearchForMatchingRange()
{
    // Walks a sorted interval table backwards to locate the entry whose range contains value a3. Table base is at a1+0x10, entry count at a1+0xC, each 20-byte entry carrying lower bound at +4 and upper bound at +8. Writes the found entry index and the previous index through a4/a5 and returns a pointer to the matching entry; calls SEHGuardedFunctionPointerCall on the sentinel and bounds-failure paths.
    // ASSIGNMENT: Load table state: v6 = *(a1 + 12) (entry count, field 0xC) and v7 = *(a1 + 16) (table pointer, field 0x10). [source:raw, field:this:0x0000000C, field:this:0x00000010]
    // ASSIGNMENT: Seed locals v8, v12 and v11 all to the entry count v6. [source:raw]
    // GUARD: Guard on a2 >= 0; when a2 starts negative the search is skipped entirely. [source:raw]
    // LOOP: do-while loop that walks entries backward, decrementing a2 each time a range matches, while a2 >= 0. [source:raw]
    // GUARD: When v6 equals the sentinel -1, call SEHGuardedFunctionPointerCall as the error path. [source:raw, callee:0x00593CFD]
    // CALCULATION: Decrement the entry index v6. [source:raw]
    // GUARD: Range match test: *(v7 + 20*v6 + 4) < a3 && a3 <= *(v7 + 20*v6 + 8), or v6 reaches the sentinel -1. [source:raw]
    // STATE_TRANSITION: On a range match, decrement a2 and track the previous two indices: v11 = v12, v12 = v6. [source:raw]
    // ASSIGNMENT: After the loop, v8 = v11 (the earlier of the two tracked indices). [source:raw]
    // CALCULATION: Compute the output index: v9 = v6 + 1. [source:raw]
    // ASSIGNMENT: Write output indices: *a4 = v9 and *a5 = v8. [source:raw]
    // GUARD: Bounds validation: when v8 > entry count or v9 > v8, call SEHGuardedFunctionPointerCall. [source:raw, callee:0x00593CFD]
    // RETURN: Return the pointer to the matched entry: v7 + 20 * v9. [source:raw]

    // Conservative worker pseudocode:
    //   int BinaryIntervalSearchForMatchingRange(int a1, int a2, int a3, unsigned int* a4, unsigned int* a5) {
    //     unsigned int count = *(unsigned int*)(a1 + 12);
    //     int table = *(int*)(a1 + 16);
    //     unsigned int v6 = count, v8 = count, v12 = count, v11 = count;
    //     if (a2 >= 0) {
    //       do {
    //         if (v6 == -1) SEHGuardedFunctionPointerCall();
    //         --v6;
    //         if (*(int*)(table + 20 * v6 + 4) < a3 && a3 <= *(int*)(table + 20 * v6 + 8) || v6 == -1) {
    //           --a2; v11 = v12; v12 = v6;
    //         }
    //       } while (a2 >= 0);
    //       v8 = v11;
    //     }
    //     v6 = v6 + 1;
    //     *a4 = v6;
    //     *a5 = v8;
    //     if (v8 > *(unsigned int*)(a1 + 12) || v6 > v8) SEHGuardedFunctionPointerCall();
    //     return table + 20 * v6;
    //   }
    // UNRESOLVED: Semantics of parameters a2 and a3 and of the two output indices written through a4/a5 are not established from this packet.
    // UNRESOLVED: Meaning of the 20-byte interval entries beyond the lower/upper bounds at +4 and +8 is unknown.
    // UNRESOLVED: Whether the table is sorted ascending by lower bound is implied by the backward walk but not proven here.
}
