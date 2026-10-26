// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A770
// Canonical corpus name: LongjmpMSVCCRT
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LongjmpMSVCCRT_0058a770.c

void UnknownObject::crtLongjmp()
{
    // MSVC CRT longjmp implementation over the jmp_buf at a1. Reads the saved target (a1[0]) and saved frame pointer (a1[6]); when the saved frame differs from the current thread FS:0, calls GlobalUnwind2 to unwind global frames. When the saved frame is non-null, either runs the cleanup handler stored at a1[9] (after validating the jmp_buf cookie: EmptyStub_3d53(a1+8) and a1[8] == 1447244336) or unwinds the local SEH scope table to the saved trylevel via MSVCRTSEHFrameUnwinder(v3, a1[7]). Finally calls sub_58893A(a1[5], a1[0], 0) and jumps through a1[5], returning its result.
    // ASSIGNMENT: Capture saved state: v2 = *a1 (saved longjmp target) and v3 = a1[6] (saved frame pointer / exception registration frame). [field:this:0x00000000, field:this:0x00000018]
    // GUARD: Guard: v3 != __readfsdword(0) — saved frame differs from the current thread's FS:0 TEB frame, meaning global frames must be unwound. [field:this:0x00000018, source:raw]
    // CALL: GlobalUnwind2((PVOID)a1[6]) unwinds the global stack frames when the saved frame no longer matches the current one. [callee:0x00588864, field:this:0x00000018]
    // GUARD: Guard: v3 (saved frame) non-null selects the SEH-local unwind/cleanup path. [field:this:0x00000018, source:raw]
    // GUARD: Cookie validation: EmptyStub_3d53(a1 + 8) non-zero AND a1[8] == 1447244336 must both hold for the stored cleanup handler path to be taken. [guard:0, callee:0x00593D53, field:this:0x00000020]
    // ASSIGNMENT: v4 = a1[9] loads the optional cleanup function pointer stored in the jmp_buf. [field:this:0x00000024]
    // GUARD: Guard: v4 non-null before invoking the cleanup handler. [source:raw]
    // CALL: v4(a1) invokes the validated cleanup handler with the whole jmp_buf pointer as its argument. [field:this:0x00000024, source:raw]
    // CALL: MSVCRTSEHFrameUnwinder(v3, a1[7]) unwinds the local SEH scope table to the saved trylevel when the cookie path was not taken. [callee:0x005888A6, field:this:0x0000001C, field:this:0x00000018]
    // CALL: sub_58893A(a1[5], v2, 0) restores the saved return context using the saved target a1[0] and the final jump slot a1[5]. [callee:0x0058893A, field:this:0x00000014, field:this:0x00000000]
    // RETURN: Transfer to the saved target: indirect call through a1[5]; its return value becomes this function's result. [field:this:0x00000014, source:raw]
    // CALL: Invoked by VTableDispatchWithLongjmp (005016E0), AssertFailHandler (00502102) and GuardedCallWithLongjmp (00511869) to restore the saved jump context after an error path. [caller:0x005016E0, caller:0x00502102, caller:0x00511869, source:raw]

    // Conservative worker pseudocode:
    //   int sub_58A770(int *buf, int a2) {
    //     int target = buf[0];
    //     int frame = buf[6];
    //     if (frame != __readfsdword(0))
    //       GlobalUnwind2((PVOID)buf[6]);
    //     if (frame) {
    //       if (EmptyStub_3d53(buf + 8) && buf[8] == 1447244336) {
    //         void (__stdcall *cleanup)(int *) = (void (__stdcall *)(int *))buf[9];
    //         if (cleanup) cleanup(buf);
    //       } else {
    //         MSVCRTSEHFrameUnwinder(frame, buf[7]);
    //       }
    //     }
    //     sub_58893A(buf[5], target, 0);
    //     return ((int (*)(void))buf[5])();
    //   }
    // UNRESOLVED: The a2 parameter appears nowhere in the body of the raw source; its role is unaccounted for.
    // UNRESOLVED: The literal 1447244336 at a1[8] is the deterministic cookie guard value; its textual meaning is not decoded here and was preserved as decimal per the packet.
}
