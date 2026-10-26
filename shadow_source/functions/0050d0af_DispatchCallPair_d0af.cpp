// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D0AF
// Canonical corpus name: ShortComputation_d0af
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_d0af_0050d0af.c

void UnknownObject::DispatchCallPair_d0af()
{
    // Dispatch pair (cdecl, no arguments) on the shared dispatch-table path: first calls sub_50FEA7 (0x0050FEA7) with constant argument 1, then calls the function pointer stored at global off_5D7810 (0x005D7810) and returns its result.
    // CALL: Call sub_50FEA7 (0x0050FEA7) with the constant argument 1u. [callee:0x0050FEA7, source:raw]
    // CALL: Read the function pointer held at global off_5D7810 (0x005D7810) and invoke it indirectly with no arguments. [global:0x005D7810, source:raw]
    // RETURN: Return the result of the indirect call through off_5D7810. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50D0AF() {
    //     sub_50FEA7(1u);
    //     return off_5D7810();
    //   }
    // UNRESOLVED: Purpose of the sub_50FEA7(1u) preamble call is unknown.
    // UNRESOLVED: Target of the indirect function pointer off_5D7810 (0x005D7810) is not statically resolvable and unknown.
}
