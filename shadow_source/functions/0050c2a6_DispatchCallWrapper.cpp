// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C2A6
// Canonical corpus name: DirectXCallWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectXCallWrapper_0050c2a6.c

void UnknownObject::DispatchCallWrapper()
{
    // Dispatch wrapper (cdecl, no arguments): first calls sub_50FEA7 (0x0050FEA7) with the constant argument 1u, then calls the function pointer stored at global off_5D77E4 (0x005D77E4) and returns its result.
    // CALL: Call sub_50FEA7 (0x0050FEA7) with the constant argument 1u. [callee:0x0050FEA7, source:raw]
    // CALL: Read the function pointer held at global off_5D77E4 (0x005D77E4) and invoke it indirectly with no arguments. [global:0x005D77E4, source:raw]
    // RETURN: Return the result of the indirect call through off_5D77E4. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50C2A6() {
    //     sub_50FEA7(1u);
    //     return off_5D77E4();
    //   }
    // UNRESOLVED: Purpose of the sub_50FEA7(1u) preamble call is unknown.
    // UNRESOLVED: Target of the indirect function pointer off_5D77E4 (0x005D77E4) is not statically resolvable and unknown.
}
