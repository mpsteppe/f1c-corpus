// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059379B
// Canonical corpus name: SEHAwareVirtualCallDispatchLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SEHAwareVirtualCallDispatchLoop_0059379b.c

void UnknownObject::SEHAwareVirtualCallDispatchLoop()
{
    // Scope-table iteration loop. Walks scope-table entries starting from the current try level stored at a1+8 (this+0x8) until reaching target index a4, bounds-checking each index against the table size *(a3+4) and invoking SEHGuardedFunctionPointerCall on out-of-range indices. For each valid level it loads the entry's cleanup function pointer at *( *(a3+8) + 8*i + 4 ) and, when non-null, calls sub_593C50(fn, a1, 259). After the loop the final index is written back to a1+8. Existing analysis interprets this as a C++ exception scope-table unwind loop.
    // ASSIGNMENT: Initialize loop index i from the current try level stored at a1+8 (this+0x8). [field:this:0x00000008, source:raw]
    // LOOP: Iterate i from the current try level while i != a4 (target index), advancing i = *( *(a3+8) + 8*i ) — the next scope-table entry pointer. [source:raw]
    // GUARD: Bounds-check the scope-table index: when i <= -1 or i >= table_size (*(a3+4)), route through SEHGuardedFunctionPointerCall. [callee:0x00593CFD, source:raw]
    // CALL: SEHGuardedFunctionPointerCall() handles the out-of-range scope-table index. [callee:0x00593CFD, source:raw]
    // CALCULATION: Load v5 = *( *(a3+8) + 8*i + 4 ) — the cleanup/destructor function pointer of the current scope entry. [source:raw]
    // GUARD: When v5 is non-zero the cleanup handler is invoked. [source:raw]
    // CALL: sub_593C50(v5, a1, 259) invokes the cleanup/destructor with context a1 and flag 259. [callee:0x00593C50, source:raw]
    // ASSIGNMENT: After the loop terminates, store the final index i back to a1+8 (this+0x8). [field:this:0x00000008, source:raw]
    // CALL: Invoked from sub_593446 (0x00593446) and MultiArgRenderingDispatchWithLayout (0x00593839) as part of scope-table unwinding. [caller:0x00593446, caller:0x00593839]

    // Conservative worker pseudocode:
    //   void sub_59379B(int ctx, int a2, int table, int target) {
    //     int i = *(int*)(ctx + 8);
    //     for (; i != target; i = *(int*)(*(int*)(table + 8) + 8 * i)) {
    //       if (i <= -1 || i >= *(int*)(table + 4))
    //         SEHGuardedFunctionPointerCall();
    //       int fn = *(int*)(*(int*)(table + 8) + 8 * i + 4);
    //       if (fn)
    //         sub_593C50(fn, ctx, 259);
    //     }
    //     *(int*)(ctx + 8) = i;
    //   }
    // UNRESOLVED: The interpretation as a C++ exception scope-table unwind (levels a1+8 to a4) follows the existing analysis (DERIVED); the packet only proves the loop mechanics.
    // UNRESOLVED: SEHGuardedFunctionPointerCall (0x00593CFD) and StreamMagicNumberCheck (0x0058A6D5) bodies are outside this packet; StreamMagicNumberCheck likely participates in scope-entry validation.
    // UNRESOLVED: The TEB/compiler SEH globals (0xFF00000000001692/1695/1699/169A/169B) and globals 0x0058895C / 0x005B9940 are touched by the compiled SEH machinery and cannot be tied to an explicit operation from the raw source.
    // UNRESOLVED: Semantics of the flag literal 259 passed to sub_593C50 are not stated by the packet.
}
