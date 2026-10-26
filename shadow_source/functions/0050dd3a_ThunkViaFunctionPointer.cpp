// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DD3A
// Canonical corpus name: ThunkViaFunctionPointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkViaFunctionPointer_0050dd3a.c

void UnknownObject::ThunkViaFunctionPointer()
{
    // Thunk (thunk attribute in the raw source): forwards four arguments unchanged (int a1, float a2, float a3, float a4) through an indirect __stdcall call to the function pointer stored at global off_5D782C (0x005D782C) and returns the callee's result verbatim. Called by TwoThunkWrapper (0x0050EDD2).
    // CALL: Indirect call through the function pointer at off_5D782C (0x005D782C) with arguments (a1, a2, a3, a4). [global:0x005D782C, source:raw]
    // RETURN: Return the value produced by the indirect call unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int ThunkViaFunctionPointer(int a1, float a2, float a3, float a4) {
    //     return off_5D782C(a1, a2, a3, a4);
    //   }
    // UNRESOLVED: The target of the function pointer at 0x005D782C and the semantics of the forwarded arguments are not evidenced in this packet.
    // UNRESOLVED: The thunk's role within the caller TwoThunkWrapper (0x0050EDD2) and the owning object of the __stdcall contract are not identified.
}
