// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005888A6
// Canonical corpus name: MSVCRTSEHFrameUnwinder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MSVCRTSEHFrameUnwinder_005888a6.c

void UnknownObject::UnwindSEHScopeToTargetTryLevel()
{
    // CRT SEH scope-table unwinder (_local_unwind core). Walks the 3-DWORD scope table referenced at a1+0x8 while the current trylevel at a1+0xC is neither -1 nor the target level a2, advancing the stored trylevel each iteration and invoking each scope entry's registered unwind handler (guarded by a disposition word) before returning a1.
    // ASSIGNMENT: Load the scope-table pointer from a1+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Load the current trylevel from a1+0xC. [field:this:0x0000000C, source:raw]
    // LOOP: Iterate the scope table while the current trylevel is neither -1 nor the target level a2. [source:raw]
    // GUARD: Break the loop when trylevel equals -1 (no scope left) or equals the target level a2 (unwind target reached). [field:this:0x0000000C, source:raw]
    // CALCULATION: Index the 3-DWORD scope entry: entry = 3 * trylevel; the first DWORD of the entry holds the next trylevel. [source:raw]
    // ASSIGNMENT: Advance the stored trylevel at a1+0xC to the next scope entry. [field:this:0x0000000C, source:raw]
    // GUARD: When the scope entry's second DWORD (disposition) is zero, report via sub_58893A and invoke the registered unwind handler at the entry's third DWORD. [callee:0x0058893A, source:raw]
    // CALL: Call sub_58893A(257) to signal the unwind action for the current scope entry. [callee:0x0058893A, source:raw]
    // CALL: Invoke the unwind handler with the SEH ExceptionList and the FlagCheckHandler callback (0x00588884). [global:0x00588884, source:raw]
    // CALL: Called by ScriptFrameProcessor (0x0058895C), LocalUnwindWrapper (0x00588A19), LongjmpMSVCCRT (0x0058A770) and SEHWrapperAroundCRTFunctionCall (0x005938B4) as the shared unwind core. [caller:0x0058895C, caller:0x00588A19, caller:0x0058A770, caller:0x005938B4]
    // RETURN: Return a1. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5888A6(int a1, int a2) {
    //     int ExceptionList;             /* from NtCurrentTeb()->ExceptionList * /
    //     int (*FlagCheckHandler)(...);  /* global 0x00588884 * /
    //     while (1) {
    //       int scope = *(int *)(a1 + 8);
    //       int trylevel = *(int *)(a1 + 12);
    //       if (trylevel == -1 || trylevel == a2) break;
    //       int entry = 3 * trylevel;
    //       *(int *)(a1 + 12) = *(int *)(scope + 4 * entry);
    //       if (!*(int *)(scope + 4 * entry + 4)) {
    //         sub_58893A(257);
    //         ((void (__cdecl *)(int, int (*)(...)))*(int *)(scope + 4 * entry + 8))(
    //             ExceptionList, FlagCheckHandler);
    //       }
    //     }
    //     return a1;
    //   }
    // UNRESOLVED: Meaning of the 257 code passed to sub_58893A and of the disposition DWORD at scope+4*entry+4.
    // UNRESOLVED: Full scope-table layout as consumed by this CRT variant.
    // UNRESOLVED: Whether the near-equal scope structures across SEH frames are distinct classes or the same layout.
}
