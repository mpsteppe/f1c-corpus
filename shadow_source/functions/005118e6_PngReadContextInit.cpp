// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005118E6
// Canonical corpus name: sub_5118E6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5118E6_005118e6.c

void UnknownObject::PngReadContextInit()
{
    // PNG/zlib decompression context initializer. Allocates and zero-initializes a 1-byte-minimum context block, installs a setjmp/longjmp error-recovery frame, stores three initialization parameters via TripleFieldSetter_184f, validates that the libpng version string starts with '1' (else raises the incompatible-version error), configures a 0x2000 window size, registers the read callback sub_513C80 and the safe-delete thunk at +132/+136/+140, initializes the zlib stream with version string "1.1.3" and window size 56, and routes zlib error codes (-6 version, -4/-2 memory, other unknown) to longjmp error handlers. Returns the context pointer.
    // CALL: AllocAndZeroInit(1) allocates and zero-initializes the context block; the result is kept in v8 [callee:0x00517E43, source:raw]
    // GUARD: If the allocation returned null, return 0 immediately without configuring anything [source:raw]
    // CALL: Setjmp3MSVCJmpBufSave(context, 0, v7) installs the longjmp error-recovery frame for the context [callee:0x0058A7EC, source:raw]
    // STATE_TRANSITION: On the longjmp path (non-zero setjmp return): ConditionalCall_7ec8(context, *(context+156)) runs the error hook and GuardedDelegate(context) tears the context down, then return 0 [callee:0x00517EC8, callee:0x00517E85, source:raw]
    // CALL: TripleFieldSetter_184f(context, a2, a3, a4) stores the three caller-supplied initialization parameters into the context [callee:0x0051184F, source:raw]
    // GUARD: If a1 is null or *a1 != '1' (0x31), GuardedCallWithLongjmp(context, "Incompatible libpng version in application and library") raises the version error [guard:0, field:this:0x00000000, callee:0x00511869, global:0x005AF2E0, source:raw]
    // ASSIGNMENT: Set the context window size at +160 to 0x2000 and +156 to the result of sub_517E92(context, 0x2000) [callee:0x00517E92, source:raw]
    // ASSIGNMENT: Register the read callback: +132 = sub_513C80, +136 = SafeDeleteGuardForThunkFUN00517ec8, +140 = context [global:0x00513C80, global:0x00513CD3, source:raw]
    // CALL: sub_517AC5(context+100, "1.1.3", 56) initializes the zlib stream against version string "1.1.3"; the result is kept in v6 [callee:0x00517AC5, global:0x005AF2D8, source:raw]
    // STATE_TRANSITION: Route the zlib init result: v6 == -6 raises "zlib version error", v6 == -4 or -2 raises "zlib memory error", any other non-zero value raises "Unknown zlib error", each via GuardedCallWithLongjmp [callee:0x00511869, global:0x005AF29C, global:0x005AF2B0, global:0x005AF2C4, source:raw]
    // ASSIGNMENT: Copy the stream setup into +112 (from +156) and +116 (from +160) [source:raw]
    // CALL: sub_513BF9(context, 0, 0) finalizes the decompression state after all setup is complete [callee:0x00513BF9, source:raw]
    // RETURN: Return the initialized context pointer v8; the caller sub_50210E (0050210e) receives the context [function:0x005118E6, caller:0x0050210E, source:raw]

    // Conservative worker pseudocode:
    //   ctx = AllocAndZeroInit(1);
    //   if (!ctx) return 0;
    //   if (Setjmp3MSVCJmpBufSave(ctx, 0, jmpBuf)) {
    //     ConditionalCall_7ec8(ctx, *(ctx+156));
    //     GuardedDelegate(ctx);
    //     return 0;
    //   }
    //   TripleFieldSetter_184f(ctx, a2, a3, a4);
    //   if (!a1 || *a1 != '1') GuardedCallWithLongjmp(ctx, "Incompatible libpng version...");
    //   *(ctx+160) = 0x2000;
    //   *(ctx+156) = sub_517E92(ctx, 0x2000);
    //   *(ctx+132) = sub_513C80;
    //   *(ctx+136) = SafeDeleteGuardForThunkFUN00517ec8;
    //   *(ctx+140) = ctx;
    //   v6 = sub_517AC5(ctx+100, "1.1.3", 56);
    //   if (v6 == -6) GuardedCallWithLongjmp(ctx, "zlib version error");
    //   else if (v6 == -4 || v6 == -2) GuardedCallWithLongjmp(ctx, "zlib memory error");
    //   else if (v6) GuardedCallWithLongjmp(ctx, "Unknown zlib error");
    //   *(ctx+112) = *(ctx+156);
    //   *(ctx+116) = *(ctx+160);
    //   sub_513BF9(ctx, 0, 0);
    //   return ctx;
    // UNRESOLVED: The context struct offsets +156/+160/+132/+136/+140/+112/+116/+100 are the primary state but are not exposed as packet field evidence; only field this+0x0 (the version-string byte) is recorded
    // UNRESOLVED: The exact contract of the longjmp path (what triggers ConditionalCall_7ec8) is not visible from this packet alone
}
