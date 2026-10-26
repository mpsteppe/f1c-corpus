// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059067E
// Canonical corpus name: Cintrindisp1
// Owner: MSVCRTInternal [DERIVED]
// Raw source: functions/Cintrindisp1_0059067e.c

void MSVCRTInternal::CrtIntrinsicDispatch1()
{
    // Legacy MSVC CRT internal dispatch wrapper (ABI lead name 'cintrindisp1'). Forwards caller state (a1 in edx, a2 in cx, FPU status word, and x87-stack double a4) to Trandisp1 together with a local savedregs buffer, then calls sub_59070A with the saved FPU state and a4. Part of the CRT intrinsic/FPU-exception dispatch machinery rather than game logic.
    // CALL: Invoke Trandisp1(a1, a2, &savedregs, a3, a4), forwarding the register-carried caller state (a1 in edx, a2 in cx, a3 FPU status, a4 on the x87 stack) and the address of the local savedregs buffer used to preserve the FPU context. [callee:0x0058DA70, source:raw]
    // CALL: Invoke sub_59070A((double*)&savedregs, a4), passing the saved FPU-state buffer and the x87-stack value a4. [callee:0x0059070A, source:raw]

    // Conservative worker pseudocode:
    //   void sub_59067E(int a1, __int16 a2, __int16 fpcw, double a4) {
    //     int savedregs;
    //     Trandisp1(a1, a2, (int)&savedregs, fpcw, a4);
    //     sub_59070A((double*)&savedregs, a4);
    //   }
    // UNRESOLVED: Role of Trandisp1 and sub_59070A inside the CRT intrinsic/FPE dispatch path; the __usercall register-carrying convention is legacy and the exact semantics of each callee are not established.
    // UNRESOLVED: sub_59070A is invoked with arguments here, while the sibling Cintrindisp2 wrapper invokes it with no visible arguments; the register-carrying contract differs between wrappers.
    // UNRESOLVED: The local savedregs buffer is only passed by address; its layout and how the callees use it are unknown.
    // UNRESOLVED: dword_5E9AD0 (named CrtFPEExceptionFlag [DERIVED]) is read by this dispatch path but does not appear directly in the raw source snippet.
}
