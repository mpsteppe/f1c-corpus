// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561A86
// Canonical corpus name: NestedLoopArrayFillWithStride
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NestedLoopArrayFillWithStride_00561a86.c

void UnknownObject::fillArrayWithStride()
{
    // Strided dword array fill loop that writes a constant value and advances the write pointer per-iteration by a base byte stride, plus a conditional extra stride driven by an error accumulator. Nine __cdecl integer/pointer arguments; no callees, fields, globals, or guards beyond the local branch on the accumulator sign.
    // ASSIGNMENT: Computes the initial write pointer v9 as a9 plus four times a6 (treating a6 as a dword index into an array based at a9). [source:raw]
    // ASSIGNMENT: Precomputes byte strides v13 = 4 * a5 (extra conditional stride) and v14 = 4 * a8 (base per-iteration stride). [source:raw]
    // ASSIGNMENT: Stores the fill value a7 into result and into the current write pointer *v9. [source:raw]
    // CALCULATION: Advances the write pointer by the base stride v14 (4 * a8 bytes). [source:raw]
    // GUARD: Tests the sign of the error accumulator a1: when negative it is incremented by a3; otherwise it is incremented by a4 and the write pointer is advanced an extra v13 (4 * a5) bytes. [source:raw]
    // LOOP: Decrements the counter a2 each iteration and repeats until a2 reaches zero. [source:raw]
    // RETURN: Returns the stored fill value a7 (result). [source:raw]

    // Conservative worker pseudocode:
    //   int fillArrayWithStride(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
    //       int *p = (int *)(a9 + 4 * a6);
    //       int extra = 4 * a5;
    //       int base = 4 * a8;
    //       do {
    //           *p = a7;
    //           p = (int *)((char *)p + base);
    //           if (a1 < 0)
    //               a1 += a3;
    //           else {
    //               a1 += a4;
    //               p = (int *)((char *)p + extra);
    //           }
    //       } while (--a2);
    //       return a7;
    //   }
    // UNRESOLVED: The error-accumulator branch (a1 < 0 → a3, else a4 + extra stride) is a Bresenham-style line step, but the semantic meaning of the strides (pixel/row offsets vs. matrix strides) is undocumented by the packet.
    // UNRESOLVED: a6 and a8 are dword counts while a5 is also used as a stride count; the intended array/geometry layout is unknown.
    // UNRESOLVED: The function is called from no documented caller and the packet gives no class or module identity.
}
