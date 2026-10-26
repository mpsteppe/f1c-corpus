// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564890
// Canonical corpus name: IndirectCallViaFunctionPointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndirectCallViaFunctionPointer_00564890.c

void UnknownObject::DispatchViaFunctionPointer()
{
    // Indirect dispatch helper (fastcall, two args). Loads the dword function pointer stored at a1+0x10; when it is non-zero, computes v4 = LinearInterpolation(a1, a2) and invokes the pointer as a __thiscall with v4 as its single argument, returning that call's result. When the pointer is null it returns the null value directly. Referenced by BatchLoopWithMemoryCleanup (0x00564860) and CallChainWrapper (0x005649D0) as the tail of their per-item processing.
    // ASSIGNMENT: Load the dword at a1+0x10 into result as the dispatch function pointer [source:raw]
    // GUARD: Proceed to the dispatch path only when the loaded pointer at a1+0x10 is non-zero; otherwise return it (null) unchanged [source:raw]
    // CALL: Call LinearInterpolation(a1, a2) and keep the return value as v4 [callee:0x005648B0, source:raw]
    // CALL: Invoke the function pointer at a1+0x10 as a __thiscall passing v4 as its argument [source:raw]
    // RETURN: Return the indirect call's result, or the null pointer when the dispatch slot is empty [source:raw]
    // CALL: Referenced by BatchLoopWithMemoryCleanup (0x00564860) and CallChainWrapper (0x005649D0) as a tail dispatch step [caller:0x00564860, caller:0x005649D0, source:raw]

    // Conservative worker pseudocode:
    //   int DispatchViaFunctionPointer(int a1, int a2) {
    //     int (*fn)(int) = *(int **)(a1 + 16);
    //     if (fn) {
    //       int v4 = LinearInterpolation(a1, a2);
    //       return fn(v4);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: What LinearInterpolation computes and what the dispatched pointer targets are unknown from this packet
    // UNRESOLVED: Identity of the receiver object a1 and the meaning of its +0x10 function-pointer slot are unknown
}
