// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00539F60
// Canonical corpus name: IndirectCallViaVTable0x24
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndirectCallViaVTable0x24_00539f60.c

void UnknownObject::VTableDispatch0x24()
{
    // Generic object-oriented dispatch thunk: reads the function pointer at offset 0x24 of the object passed in a2 and calls it with the context pointer at offset 0x28 plus the pass-through parameter a1, returning the callee's result. No guard conditions; the indirect call executes unconditionally with no null checks.
    // CALL: Indirect call through the function pointer stored at offset 0x24 of the receiver: (*(this->fn_0x24))(*(this->ctx_0x28), a1). The vtable slot value and the context argument are both read from the object. [source:raw, field:this:0x00000024, field:this:0x00000028]
    // RETURN: Return the result of the dispatched virtual method call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_539F60(int a1, int a2) {
    //     return (*(int (__fastcall **)(_DWORD, int))(a2 + 36))(*(_DWORD *)(a2 + 40), a1);
    //   }
    // UNRESOLVED: Receiver object identity and the concrete virtual method at vtable slot 0x24 are unknown; resolution requires the calling context (StateResetWithCallback 0x00537000 / sub_537110 0x00537110).
    // UNRESOLVED: Callee address is indirect so the callgraph lists no static callee for this thunk.
}
