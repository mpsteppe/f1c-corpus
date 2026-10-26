// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00511869
// Canonical corpus name: GuardedCallWithLongjmp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedCallWithLongjmp_00511869.c

void UnknownObject::GuardedCallWithLongjmp()
{
    // Guarded callback dispatch with longjmp recovery: loads the callback pointer stored at a1+0x40 (offset 0x40); when non-null, invokes it with (a1, a2). Then unwinds through LongjmpMSVCCRT(a1, 1) (0x0058A770) before dispatching (a1, a2) to CallbackDispatch as the return value. Shared recovery/dispatch trampoline reused by 15 callers across stream and buffer code; structural twin of GuardedFunctionDispatch (00486aa0) per prelabel.
    // ASSIGNMENT: Load callback v2 from the function pointer stored at a1+0x40 (offset 0x40). [field:this:0x00000040, source:raw]
    // GUARD: If v2 is non-null, the stored callback is invoked. [field:this:0x00000040, source:raw]
    // CALL: Invoke the stored callback v2(a1, a2). [source:raw]
    // CALL: Unwind through LongjmpMSVCCRT(a1, 1) (0x0058A770). [callee:0x0058A770, source:raw]
    // RETURN: Dispatch (a1, a2) to CallbackDispatch as the final return value. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_511869(int a1, int a2) {
    //     void (__cdecl *v2)(int, int) = *(void (__cdecl **)(int, int))(a1 + 64);
    //     if (v2)
    //       v2(a1, a2);
    //     LongjmpMSVCCRT(a1, 1);
    //     return CallbackDispatch(a1, a2);
    //   }
    // UNRESOLVED: CallbackDispatch is named in the raw source but has no callee evidence ref; its target address is absent from the packet callee list.
    // UNRESOLVED: LongjmpMSVCCRT unwinds to a saved setjmp frame; the recovery context and the meaning of the value 1 are unknown.
    // UNRESOLVED: The context type behind a1 (holding the callback slot at offset 0x40) is unknown; the trampoline is shared by 15 callers.
}
