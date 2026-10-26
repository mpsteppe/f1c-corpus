// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A323
// Canonical corpus name: AtomicLOCKUNLOCKWithIndirectCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AtomicLOCKUNLOCKWithIndirectCall_0058a323.c

void UnknownObject::AtomicLOCKUNLOCKWithIndirectCall()
{
    // Atomic lock/unlock trampoline around an indirect call: atomically exchanges the return-address slot with v3 via _InterlockedExchange, then invokes the swapped-out value as an indirect function pointer and returns its result. The decompiled frame is flagged mis-decoded (positive sp value detected), so the identity of the exchanged operand and the dispatch target is unresolved.
    // CALL: _InterlockedExchange((volatile __int32 *)&retaddr, v3) atomically swaps v3 into the return-address slot and returns the prior slot value as the indirect call target. [source:raw]
    // CALL: Indirect call through the value returned by the exchange, treated as a function pointer; the result of that call becomes the function result. [source:raw]
    // RETURN: Return the indirect call's result. [function:0x0058A323]

    // Conservative worker pseudocode:
    //   return ((int (*)(void))_InterlockedExchange((volatile __int32 *)&retaddr, v3))();
    // UNRESOLVED: The frame is mis-decoded ('positive sp value has been detected, the output may be wrong!'): v3 and the retaddr slot are stack-analysis artifacts; which real values flow through the atomic exchange and the indirect call is unresolved.
    // UNRESOLVED: Semantics of the exchange-and-invoke pattern (caller-side lock/unlock vs. plain thunk) and the dispatch target are unknown; the function is reached from sub_5939F9 and SEHWrappedRenderDispatchCall.
}
