// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D84A
// Canonical corpus name: DispatchCallPair_d84a
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DispatchCallPair_d84a_0050d84a.c

void UnknownObject::DispatchCallPair_d84a()
{
    // Dispatch pair (cdecl, no arguments) on an AI-related path: first calls sub_50FEA7 (0x0050FEA7) with constant argument 1, then calls the function pointer stored at global off_5D7860 (0x005D7860) and returns its result.
    // CALL: Call sub_50FEA7 (0x0050FEA7) with the constant argument 1u. [callee:0x0050FEA7, source:raw]
    // CALL: Read the function pointer held at global off_5D7860 (0x005D7860) and invoke it indirectly with no arguments. [global:0x005D7860, source:raw]
    // RETURN: Return the result of the indirect call through off_5D7860. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50D84A() {
    //     sub_50FEA7(1u);
    //     return off_5D7860();
    //   }
    // UNRESOLVED: Purpose of the sub_50FEA7(1u) preamble call is unknown.
    // UNRESOLVED: Target of the indirect function pointer off_5D7860 (0x005D7860) is not statically resolvable and unknown.
}
