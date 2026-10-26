// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C85D
// Canonical corpus name: ProxyCallToPTRFUN005d789c
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProxyCallToPTRFUN005d789c_0050c85d.c

void UnknownObject::ProxyCallToPTRFUN005d789c()
{
    // Thin stdcall proxy: first calls the gate sub_50FEA7 with constant argument 1, then forwards its six arguments a1..a6 unchanged through the function pointer read from global off_5D789C and returns the result.
    // CALL: Call sub_50FEA7 with constant 1 before dispatching; the gate runs before the indirect call. [callee:0x0050FEA7, source:raw]
    // CALL: Load the target function pointer from global off_5D789C and call it with a1, a2, a3, a4, a5, a6 unchanged. [global:0x005D789C, function:0x0050C85D, abi:lead, source:raw]
    // RETURN: Return the integer result produced by the indirect callee. [callee:0x0050C85D, function:0x0050C85D, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50C85D(int a1, int a2, int a3, int a4, int a5, float a6) {
    //     sub_50FEA7(1u);
    //     return off_5D789C(a1, a2, a3, a4, a5, a6);
    //   }
    // UNRESOLVED: Purpose of the gate sub_50FEA7(1u) and why it is called before dispatch.
    // UNRESOLVED: Runtime target of off_5D789C is a mutable function pointer; the actual callee is unknown statically.
    // UNRESOLVED: Owner of the object the proxy dispatches into is unknown.
}
