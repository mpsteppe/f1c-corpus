// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058895C
// Canonical corpus name: ScriptFrameProcessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScriptFrameProcessor_0058895c.c

void UnknownObject::ScriptFrameProcessor()
{
    // MSVC CRT SEH frame processor (__except_handler3/4 style). Examines a flags field in the exception record (a1+4): when bits 0x2 or 0x4 are set, it performs an unconditional full unwind to trylevel -1 and returns 1. Otherwise it walks the scope table (trylevel chain starting from TargetFrame[3] with the frame pointer in TargetFrame[2]), invoking each scope entry's filter function; a nonzero filter result triggers global unwind via GlobalUnwind2, local unwind of the scope table to the matched trylevel, then dispatches the matched catch handler through sub_58893A.
    // GUARD: Check exception-record flags field at a1+4: if (flags & 6) != 0, take the unconditional-unwind path without evaluating filters. [field:this:0x00000004, source:raw]
    // CALL: On the flag path, unwind the local SEH scope table to trylevel -1: MSVCRTSEHFrameUnwinder(TargetFrame, -1). [callee:0x005888A6, source:raw]
    // RETURN: Return 1 after the unconditional full unwind. [source:raw]
    // ASSIGNMENT: Seed the local frame context v11 with {a1, a3} and link it behind the caller frame: *(TargetFrame - 1) = v11. [source:raw]
    // ASSIGNMENT: Load scope-table cursor: v5 = TargetFrame[3] (current trylevel) and v6 = TargetFrame[2] (scope-table base pointer). [source:raw]
    // LOOP: Walk the scope table while v5 != -1 (no more enclosing try levels). [source:raw]
    // GUARD: If the scope entry at v6 + 12*v5 + 4 holds a nonzero filter/expression pointer, evaluate it. [source:raw]
    // CALL: Invoke the scope entry's filter/expression function at v6 + 12*v5 + 4 and capture its result in v7. [source:raw]
    // GUARD: If the filter result v7 is nonzero: a negative result (-1) means 'continue unwinding' and returns 0; a positive result means 'handle here'. [source:raw]
    // RETURN: Return 0 when the filter result is negative, propagating the keep-unwinding signal. [source:raw]
    // ASSIGNMENT: Capture the unwinder bookkeeping frame v4 (via v3[3]) and its scope-table base v8 = v4[2] for the matched trylevel. [source:raw]
    // CALL: Perform the global unwind of the frame chain: GlobalUnwind2(v3[3]). [callee:0x00588864, source:raw]
    // CALL: Unwind the local scope table to the matched trylevel: MSVCRTSEHFrameUnwinder(v4, v5). [callee:0x005888A6, source:raw]
    // CALL: Dispatch the matched catch: sub_58893A(handler at v8 + 12*v5 + 8, v4 + 4, 1), installing the handler context. [callee:0x0058893A, source:raw]
    // ASSIGNMENT: Update the current trylevel to the scope table's successor: v4[3] = *(v8 + 4*v9), then invoke the dispatch stub at v8 + 4*v9 + 8. [source:raw]
    // CALCULATION: Advance the walk: v6 = v4[2]; v5 = *(v6 + 12*v5), following the next trylevel in the scope table. [source:raw]
    // RETURN: Return 1 when the walk ends without a match (v5 == -1) on the normal path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_58895C(int a1, _DWORD *TargetFrame, int a3) {
    //     if ((*(_DWORD *)(a1 + 4) & 6) != 0) {
    //       MSVCRTSEHFrameUnwinder((int)TargetFrame, -1);
    //       return 1;
    //     }
    //     int v5 = TargetFrame[3];
    //     int v6 = TargetFrame[2];
    //     while (v5 != -1) {
    //       if (*(_DWORD *)(v6 + 12 * v5 + 4)) {
    //         int v7 = (*(int (**)(void))(v6 + 12 * v5 + 4))();
    //         if (v7 != 0) {
    //           if (v7 < 0) return 0;
    //           GlobalUnwind2((PVOID)TargetFrame);
    //           MSVCRTSEHFrameUnwinder((int)TargetFrame, v5);
    //           sub_58893A(*(_DWORD *)(v6 + 12 * v5 + 8), (int)(TargetFrame + 4), 1);
    //         }
    //       }
    //       v6 = TargetFrame[2];
    //       v5 = *(_DWORD *)(v6 + 12 * v5);
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: v9 (ecx) is used by the decompiler for v4[3] = *(v8 + 4*v9) and the dispatch call at v8 + 4*v9 + 8 but has no visible prior assignment; exact catch-handler dispatch indexing is not recovered.
    // UNRESOLVED: The meaning of sub_58893A's third argument (literal 1) is unknown.
    // UNRESOLVED: The purpose and type of a3, stored into the local frame context v11[1], are unknown from this function alone.
    // UNRESOLVED: The v3/v4 frame-register chain (savedregs-based unwinder pointer walk) is only partially understood; its exact relationship to the CRT registration node is not modeled.
}
