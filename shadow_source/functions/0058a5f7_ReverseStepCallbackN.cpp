// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A5F7
// Canonical corpus name: NTimeCallbackLoopWithSEH
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NTimeCallbackLoopWithSEH_0058a5f7.c

void UnknownObject::ReverseStepCallbackN()
{
    // Invokes a caller-supplied callback a4 exactly a3 times while stepping a pointer backward through a memory range: the pointer starts at a1 + a3*a2 and is decremented by a2 each iteration; the last callback result is returned. If a3 is zero or negative the loop never executes and the initial value a3*a2 is returned.
    // CALCULATION: Initialize result as a3 * a2, which also anchors the starting stepping pointer for the loop. [function:0x0058A5F7, source:raw]
    // GUARD: The loop runs only while --a3 >= 0; a3 starting at zero or negative means the body never executes. [source:raw]
    // LOOP: Loop a3 times: start the stepping pointer i at a3*a2 + a1 and walk it backward by a2 each iteration. [source:raw]
    // CALL: Each iteration invokes the callback a4(i) with the current stepping pointer and stores its return value into result; the packet records sub_58A677 as the callback invocation helper. [callee:0x0058A677, source:raw]
    // CALCULATION: Step the pointer i backward by the element size a2. [source:raw]
    // RETURN: Return the last callback result. [source:raw]

    // Conservative worker pseudocode:
    //   int ReverseStepCallbackN(int a1, int a2, int a3, int (*a4)(int)) {
    //     int result = a3 * a2;
    //     int i;
    //     for (i = a3 * a2 + a1; --a3 >= 0; result = a4(i))
    //       i -= a2;
    //     return result;
    //   }
    // UNRESOLVED: The five listed globals (ScriptFrameProcessor, stru_5B8C98, and the three byte_FF... TEB/KUSER_SHARED_DATA bytes) are SEH registration/scope-table artifacts of the compiled function and do not appear in the raw C text; their role here is not established.
    // UNRESOLVED: sub_58A677 is recorded as the callback invocation helper, but the raw source calls the callback a4 directly; the exact relationship between the two is unclear.
}
