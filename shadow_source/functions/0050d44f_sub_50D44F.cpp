// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D44F
// Canonical corpus name: sub_50D44F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50D44F_0050d44f.c

void UnknownObject::sub_50D44F()
{
    // Thin stdcall proxy: calls the gate sub_50FEA7 with constant argument 1, then forwards its four arguments a1, a2, a3, a4 unchanged through the function pointer read from global off_5D784C and returns the result.
    // CALL: Call sub_50FEA7 with constant 1 before dispatching; the gate runs before the indirect call. [callee:0x0050FEA7, source:raw]
    // CALL: Load the target function pointer from global off_5D784C and call it with a1, a2, a3, a4 unchanged. [global:0x005D784C, function:0x0050D44F, abi:lead, source:raw]
    // RETURN: Return the integer result produced by the indirect callee. [callee:0x0050D44F, function:0x0050D44F, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50D44F(int a1, float a2, float a3, float a4) {
    //     sub_50FEA7(1u);
    //     return off_5D784C(a1, a2, a3, a4);
    //   }
    // UNRESOLVED: Purpose of the gate sub_50FEA7(1u) and why it is called before dispatch.
    // UNRESOLVED: Runtime target of off_5D784C is a mutable function pointer; the actual callee is unknown statically.
    // UNRESOLVED: Owner of the object the proxy dispatches into is unknown.
}
