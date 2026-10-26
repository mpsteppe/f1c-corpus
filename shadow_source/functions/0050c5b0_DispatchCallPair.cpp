// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C5B0
// Canonical corpus name: DispatchCallPair
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DispatchCallPair_0050c5b0.c

void UnknownObject::DispatchCallPair()
{
    // Dispatch pair (cdecl, no arguments) on an AI-related path: first calls sub_50FEA7 (0x0050FEA7) with constant argument 1, then calls the function pointer stored at global off_5D77F0 (0x005D77F0) and returns its result.
    // CALL: Call sub_50FEA7 (0x0050FEA7) with the constant argument 1u. [callee:0x0050FEA7, source:raw]
    // CALL: Read the function pointer held at global off_5D77F0 (0x005D77F0) and invoke it indirectly with no arguments. [global:0x005D77F0, source:raw]
    // RETURN: Return the result of the indirect call through off_5D77F0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50C5B0() {
    //     sub_50FEA7(1u);
    //     return off_5D77F0();
    //   }
    // UNRESOLVED: Purpose of the sub_50FEA7(1u) preamble call is unknown.
    // UNRESOLVED: Target of the indirect function pointer off_5D77F0 (0x005D77F0) is not statically resolvable and unknown.
}
