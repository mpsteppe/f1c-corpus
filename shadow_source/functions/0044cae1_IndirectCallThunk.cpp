// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CAE1
// Canonical corpus name: nullsub_41
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/nullsub_41_0044cae1.c

void UnknownObject::IndirectCallThunk()
{
    // Forwarding thunk: reads a 16-bit selector and 32-bit offset from the stack return-address slot, assembles them into a segmented far pointer, calls through that pointer with all 17 integer arguments unchanged, and returns the callee's result. The MK_FP far-pointer reconstruction is a Hex-Rays artifact; the real mechanism (likely an indirect jump/call through a stored function pointer) is not directly evidenced in the packet.
    // CALL: Build a segmented far pointer from a WORD (selector) and DWORD (offset) both read at the return-address slot, then call through it passing all 17 integer arguments unchanged. [source:raw, function:0x0044CAE1]
    // RETURN: Return the integer result produced by the indirect call. [source:raw]

    // Conservative worker pseudocode:
    //   int IndirectCallThunk(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
    //                        int a8, int a9, int a10, int a11, int a12, int a13, int a14,
    //                        int a15, int a16, int a17) {
    //     /* read selector+offset at the return-address slot, form far pointer, call it * /
    //     return far_ptr_call(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17);
    //   }
    // UNRESOLVED: The actual target of the indirect call is unknown; no function-pointer source or callee record is present in the packet.
    // UNRESOLVED: The MK_FP segmented-pointer mechanics are a decompiler artifact; the underlying instruction pattern is not evidenced and may be an indirect jump rather than a true far call.
    // UNRESOLVED: Why 17 integer arguments are forwarded unchanged (thunk vs. tail-call contract) is unknown.
    // UNRESOLVED: Owning class and subsystem are not recorded in the packet.
}
