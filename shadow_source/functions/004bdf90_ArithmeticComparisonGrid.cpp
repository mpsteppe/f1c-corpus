// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BDF90
// Canonical corpus name: ArithmeticComparison_df90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_df90_004bdf90.c

void UnknownObject::ArithmeticComparisonGrid()
{
    // Iterates an 8x8 grid of 9-dword records starting at 'this', calling ArithmeticComparison_d8c0 on every element with a2, then performs one final ArithmeticComparison_d8c0 on the element at 'this + 576' and returns its result. Each inner iteration advances the element pointer by 9 dwords. Called by ConditionalCleanupChain (0x0040F100) and StateDependentUpdateDispatch (0x0040F130).
    // LOOP: Outer do-while loop with counter v3 seeded at 8, running the inner grid pass 8 times. [source:raw]
    // LOOP: Inner do-while loop with counter v4 seeded at 8, visiting 8 consecutive records each pass. [source:raw]
    // CALL: Call ArithmeticComparison_d8c0(v2, a2) on each element pointer as the pointer advances through the grid. [callee:0x004BD8C0]
    // CALCULATION: Advance the element pointer by 9 dwords per inner iteration: v2 += 9. [source:raw]
    // CALL: After the nested loops, call ArithmeticComparison_d8c0(this + 576, a2) on the final element. [callee:0x004BD8C0]
    // RETURN: Return the result of the final ArithmeticComparison_d8c0(this + 576, a2) call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4BDF90(_DWORD *this, int a2) {
    //     _DWORD *p = this;
    //     int outer = 8;
    //     do {
    //       int inner = 8;
    //       do {
    //         ArithmeticComparison_d8c0(p, a2);
    //         p += 9;
    //         --inner;
    //       } while (inner);
    //       --outer;
    //     } while (outer);
    //     return ArithmeticComparison_d8c0(this + 576, a2);
    //   }
    // UNRESOLVED: Record layout of the 9-dword elements and the meaning of a2 depend on ArithmeticComparison_d8c0 and the two callers.
    // UNRESOLVED: The final element at 'this + 576' sits just past the 64-element grid (64 * 9 = 576 dwords); its special handling is unexplained by this function alone.
}
