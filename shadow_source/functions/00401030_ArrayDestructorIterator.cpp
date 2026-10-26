// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00401030
// Canonical corpus name: ArrayDestructorIterator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayDestructorIterator_00401030.c

void UnknownObject::ArrayDestructorIterator()
{
    // Generic reverse teardown helper (stdcall): given base pointer a1, element stride a2 and element count a3, iterates the array in reverse, calling the __thiscall destructor a4 on each element, and returns the last destructor result (or a3 - 1 when the count is zero). Used by resource/list teardown paths.
    // ASSIGNMENT: Initialize the one-past-last pointer v4 = a3 * a2 + a1 and the default result = a3 - 1 before the count check. [source:raw]
    // GUARD: Guard on (a3 - 1) >= 0; when a3 is zero the loop body never runs. [source:raw]
    // LOOP: do-while countdown over a3 iterations using a counter seeded from a3. [source:raw]
    // CALCULATION: Step the element pointer backward by the stride: v4 -= a2. [source:raw]
    // CALL: Invoke the __thiscall destructor a4(v4) on the current element and store its return value as result. [source:raw]
    // RETURN: Return the last destructor result, or a3 - 1 when the loop never ran. [source:raw]
    // CALL: Called by GraphicsResourceDestructor (0x0040FB30), GlobalListTripleCleanupWithTimerRemoval (0x00414210), DrawableResourceCleanup (0x004150C0), NamedEntryLookupInFormatList (0x00415230) and StaticInitBulk (0x004A8B80) to run reverse element teardown over their element arrays. [caller:0x0040FB30, caller:0x00414210, caller:0x004150C0, caller:0x00415230, caller:0x004A8B80, source:raw]

    // Conservative worker pseudocode:
    //   int sub_401030(int base, int stride, int count, int (__thiscall *dtor)(int)) {
    //     int p = count * stride + base;
    //     int result = count - 1;
    //     if (count - 1 >= 0) {
    //       int n = count;
    //       do { p -= stride; result = dtor(p); --n; } while (n);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identity of the callback a4 is caller-supplied and unknown here.
    // UNRESOLVED: Element type and meaning of the stride a2 depend on each caller's array layout; a4 is __thiscall per the raw source.
}
