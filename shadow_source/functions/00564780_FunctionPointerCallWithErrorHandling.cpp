// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564780
// Canonical corpus name: FunctionPointerCallWithErrorHandling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionPointerCallWithErrorHandling_00564780.c

void UnknownObject::FunctionPointerCallWithErrorHandling()
{
    // Indirect dispatch wrapper. Calls a function pointer stored at a1+12 with (a2, dword at a1+4) to obtain an index v4, then resolves a buffer via BufferIndexComputation on the dword at a1+16. When that buffer lookup returns -1 (failure sentinel) it falls back to a single-entry call through *(*(dword)a1 + 4*v4); otherwise it forwards v5 to CallChainWrapper. Called from four infrastructure/audio mixer paths.
    // CALL: Call the handler selected by the function pointer at a1+12, passing a2 and the dword at a1+4; store its return value as the index v4. [source:raw]
    // CALL: Resolve the target buffer index by calling BufferIndexComputation with the dword at a1+16 and two zero arguments; result stored in v5. [source:raw, callee:0x00564A20]
    // GUARD: Branch on whether the computed buffer index v5 equals -1, selecting the single-entry fallback path versus the multi-entry call chain. [source:raw]
    // CALL: Fallback path: call SingleFunctionCallWrapper with the dword at (dword at a1) + 4*v4 and a2, and return its result. [source:raw]
    // CALL: Normal path: forward v5 to CallChainWrapper and return its result. [source:raw, callee:0x005649D0]
    // RETURN: Return whichever handler result was taken; the function is reached from sub_563870, sub_564110, SingletonGlobalAccessorWithFallbackAlloc and AudioMixerPollingUpdateLoop. [source:raw, caller:0x00563870, caller:0x00564110, caller:0x00564270, caller:0x00564390]

    // Conservative worker pseudocode:
    //   int sub_564780(int a1, int a2) {
    //     int v4 = (*(int(__fastcall**)(int, int))(a1 + 12))(a2, *(int*)(a1 + 4));
    //     int v5 = BufferIndexComputation(*(int*)(a1 + 16), 0, 0);
    //     if (v5 == -1)
    //       return SingleFunctionCallWrapper(*(int*)(*(int*)a1 + 4*v4), a2);
    //     return CallChainWrapper(v5);
    //   }
    // UNRESOLVED: SingleFunctionCallWrapper is named by the decompiler source but absent from the packet callee table, so no callee evidence ref exists for it.
    // UNRESOLVED: The object type behind a1 and the meaning of the a1+4 and a1+16 slots are not established by this packet.
}
