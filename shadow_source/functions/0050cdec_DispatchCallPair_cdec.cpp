// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050CDEC
// Canonical corpus name: sub_50CDEC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50CDEC_0050cdec.c

void UnknownObject::DispatchCallPair_cdec()
{
    // Dispatch pair (cdecl, no arguments) on the shared dispatch-table path: first calls sub_50FEA7 (0x0050FEA7) with constant argument 1, then calls the function pointer stored at global off_5D785C (0x005D785C) and returns its result.
    // CALL: Call sub_50FEA7 (0x0050FEA7) with the constant argument 1u. [callee:0x0050FEA7, source:raw]
    // CALL: Read the function pointer held at global off_5D785C (0x005D785C) and invoke it indirectly with no arguments. [global:0x005D785C, source:raw]
    // RETURN: Return the result of the indirect call through off_5D785C. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50CDEC() {
    //     sub_50FEA7(1u);
    //     return off_5D785C();
    //   }
    // UNRESOLVED: Purpose of the sub_50FEA7(1u) preamble call is unknown.
    // UNRESOLVED: Target of the indirect function pointer off_5D785C (0x005D785C) is not statically resolvable and unknown.
}
