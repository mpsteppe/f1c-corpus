// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00401000
// Canonical corpus name: sub_401000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_401000_00401000.c

void UnknownObject::CallbackLoopNTimes()
{
    // Generic iteration helper: calls a __thiscall callback a4 exactly a3 times, advancing the first argument a1 by stride a2 after each call. Returns the last callback result. If the requested count a3 is zero, the loop body never runs and the function returns a3 - 1.
    // ASSIGNMENT: Initialize result to a3 - 1 before the count check. [source:raw]
    // GUARD: Guard on (a3 - 1) >= 0; when a3 is zero the loop is skipped entirely. [source:raw]
    // LOOP: do-while loop over a3 iterations using a countdown counter seeded from a3. [source:raw]
    // CALL: Call the __thiscall callback a4(a1) each iteration and store its return value as result. [source:raw]
    // CALCULATION: Advance the element pointer by the stride: a1 += a2. [source:raw]
    // RETURN: Return the last callback result (or a3 - 1 when the loop never ran). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_401000(int p, int stride, int count, int (__thiscall *cb)(int)) {
    //     int result = count - 1;
    //     if (count - 1 >= 0) {
    //       int n = count;
    //       do { result = cb(p); p += stride; --n; } while (n);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identity and purpose of the callback a4 is caller-supplied and unknown here.
    // UNRESOLVED: Element type and meaning of stride a2 depend on the caller's array layout.
}
