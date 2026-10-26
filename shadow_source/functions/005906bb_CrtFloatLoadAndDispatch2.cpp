// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005906BB
// Canonical corpus name: sub_5906BB
// Owner: MSVCRTInternal [DERIVED]
// Raw source: functions/sub_5906BB_005906bb.c

void MSVCRTInternal::CrtFloatLoadAndDispatch2()
{
    // Legacy MSVC CRT float-display wrapper (ABI lead name 'CRT___ctrandisp2'). Loads two doubles a2 and a3 onto the x87 stack via CRTFload, forwards register-carried state (v4 in edx, FPU status v5, and x87-stack doubles a1/v3) to sub_58DAD7 together with a local savedregs buffer, then calls sub_590703 on that buffer and returns its result. Part of the CRT float-formatting/intrinsic dispatch machinery rather than game logic.
    // CALL: Load the first double argument a2 onto the x87 stack via CRTFload (0x0059086E). [callee:0x0059086E, source:raw]
    // CALL: Load the second double argument a3 onto the x87 stack via CRTFload (0x0059086E), keeping the result as v3 (st7). [callee:0x0059086E, source:raw]
    // CALL: Invoke sub_58DAD7(v4, (int)&savedregs, v5, a1, v3), forwarding the register-carried caller state (v4 in edx, FPU status v5) plus the x87-stack doubles a1 (st1) and v3 (st0), and the address of the local savedregs buffer used to preserve the FPU context. [callee:0x0058DAD7, source:raw]
    // CALL: Invoke sub_590703((int)&savedregs), passing the saved FPU-state buffer. [callee:0x00590703, source:raw]
    // RETURN: Return the result produced by sub_590703. [source:raw]

    // Conservative worker pseudocode:
    //   int CrtFloatLoadAndDispatch2(double a1, double a2, double a3) {
    //     int savedregs;
    //     CRTFload(a2);
    //     double v3 = CRTFload(a3);
    //     sub_58DAD7(v4, (int)&savedregs, v5, a1, v3);
    //     return sub_590703((int)&savedregs);
    //   }
    // UNRESOLVED: The register v4 (edx) is uninitialized in the decompiler view; its meaning as the object pointer forwarded to sub_58DAD7 is unknown.
    // UNRESOLVED: Role of sub_58DAD7 and sub_590703 in the CRT float-display/FPE path; the exact semantics of the savedregs FPU-context buffer are not established.
    // UNRESOLVED: v5 (FPU status) is passed without visible initialization in the raw source snippet.
    // UNRESOLVED: ABI lead name 'CRT___ctrandisp2' identifies this as the CRT variant of the trandisp2 family, consistent with the sibling Cintrindisp2 wrapper.
}
