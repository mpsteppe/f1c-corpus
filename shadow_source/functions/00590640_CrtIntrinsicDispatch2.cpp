// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00590640
// Canonical corpus name: Cintrindisp2
// Owner: MSVCRTInternal [DERIVED]
// Raw source: functions/Cintrindisp2_00590640.c

void MSVCRTInternal::CrtIntrinsicDispatch2()
{
    // Legacy MSVC CRT internal dispatch wrapper (ABI lead name 'cintrindisp2'). Forwards caller state (a1 in edx, FPU status word, and two x87-stack doubles) to sub_58DAD7 together with a local savedregs buffer, then returns the result of sub_59070A(). Part of the CRT intrinsic/FPU-exception dispatch machinery rather than game logic.
    // CALL: Invoke sub_58DAD7(a1, &savedregs, a2, a3, a4), forwarding the register-carried caller state (a1 in edx, a2 FPU status, a3/a4 on the x87 stack) and the address of the local savedregs buffer used to preserve the FPU context. [callee:0x0058DAD7, source:raw]
    // CALL: Invoke sub_59070A() and return whatever it produces. [callee:0x0059070A, source:raw]
    // RETURN: Return the value produced by sub_59070A. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_590640(int a1, __int16 fpcw, double a3, double a4) {
    //     int savedregs;
    //     sub_58DAD7(a1, (int)&savedregs, fpcw, a3, a4);
    //     return sub_59070A();
    //   }
    // UNRESOLVED: Role of sub_58DAD7 and sub_59070A inside the CRT intrinsic/FPE dispatch path; the __usercall register-carrying convention is legacy and the exact semantics of each callee are not established.
    // UNRESOLVED: The local savedregs buffer is only passed by address; its layout and how the callees use it are unknown.
    // UNRESOLVED: dword_5E9AD0 (named CrtFPEExceptionFlag [DERIVED]) is read by this dispatch path but does not appear directly in the raw source snippet.
}
