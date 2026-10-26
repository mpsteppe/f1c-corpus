// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D47A0
// Canonical corpus name: ThreadSafeReadWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadSafeReadWrapper_004d47a0.c

void UnknownObject::ThreadSafeReadWrapper()
{
    // Thin __fastcall wrapper that reorders its four arguments and forwards to ThreadSafeReadWrapper_803f (0x0058803F): the callee is called as ThreadSafeReadWrapper_803f(a2, 1, a3, a1), moving the first argument to the last position, injecting the constant 1 as the second argument, and returning the callee's result unchanged.
    // CALL: Invoke ThreadSafeReadWrapper_803f(0x0058803F) with arguments reordered to (a2, 1, a3, a1); original first argument a1 becomes the fourth, and the constant 1 is passed as the second argument. [callee:0x0058803F, abi:lead, source:raw]
    // RETURN: Return the result of ThreadSafeReadWrapper_803f unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int ThreadSafeReadWrapper(int a1, int a2, int a3, int a4) {
    //     return ThreadSafeReadWrapper_803f(a2, 1, a3, a1);
    //   }
    // UNRESOLVED: Purpose and signature of the target ThreadSafeReadWrapper_803f (0x0058803F) are unknown here; this function only reorders and forwards.
    // UNRESOLVED: Meaning of the injected constant 1 argument is unproven; it may be a mode/flag selecting a read flavor in the callee.
    // UNRESOLVED: Fourth parameter a4 is never referenced by the body; whether it is a dead parameter or consumed indirectly by the callee is unknown.
}
