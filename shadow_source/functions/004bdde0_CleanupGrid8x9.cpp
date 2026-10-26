// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BDDE0
// Canonical corpus name: F_65xNestedCallLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_65xNestedCallLoop_004bdde0.c

void UnknownObject::CleanupGrid8x9()
{
    // Runs StructCleanup (0x004BD800) over an 8x8 grid of element pointers whose stride is 9 pointer-sized slots, then performs one final StructCleanup on the base pointer advanced by 576 slots. The caller (Game_Post, 0x0042DA30) supplies the grid base. Both loop counters are hardcoded to 8 and the pointer advance is exactly 9 slots per iteration.
    // ASSIGNMENT: Initialize the outer loop counter v3 to 8. [source:raw]
    // LOOP: Outer countdown loop driven by v3; body runs 8 times while v3 is nonzero. [source:raw]
    // ASSIGNMENT: Initialize the inner loop counter v4 to 8. [source:raw]
    // LOOP: Inner countdown loop driven by v4; body runs 8 times while v4 is nonzero. [source:raw]
    // CALL: Call StructCleanup(0x004BD800) on the current element pointer v2. [callee:0x004BD800, source:raw]
    // CALCULATION: Advance the element pointer by 9 slots: v2 += 9 (element stride of 9 LPVOID-sized entries). [source:raw]
    // CALCULATION: Decrement the inner counter v4 each inner iteration. [source:raw]
    // CALCULATION: Decrement the outer counter v3 each outer iteration. [source:raw]
    // CALL: Final StructCleanup(0x004BD800) call on this + 576 (9 slots x 64 = 576), covering the remainder of the grid. [callee:0x004BD800, source:raw]
    // RETURN: Return the result of the final StructCleanup call (raw decompiler keeps this as the function return). [source:raw]

    // Conservative worker pseudocode:
    //   void *__thiscall sub_4BDDE0(LPVOID *this) {
    //     LPVOID *cur = this;
    //     int outer = 8;
    //     do {
    //       int inner = 8;
    //       do {
    //         StructCleanup(cur);
    //         cur += 9;
    //       } while (--inner);
    //     } while (--outer);
    //     return StructCleanup(this + 576);
    //   }
    // UNRESOLVED: Element semantics and class of the 64 grid slots plus the trailing slot at this + 576 are unknown; StructCleanup takes the element pointer directly.
    // UNRESOLVED: Whether the grid is an array of structs or an array of pointers is not resolvable from this function alone (advance is a compile-time pointer arithmetic constant of 9 LPVOID slots).
    // UNRESOLVED: Purpose of the overall grid (why Game_Post triggers an 8x8 + trailing cleanup) is unknown.
}
