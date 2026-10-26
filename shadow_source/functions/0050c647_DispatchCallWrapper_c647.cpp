// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C647
// Canonical corpus name: MathTrampoline
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MathTrampoline_0050c647.c

void UnknownObject::DispatchCallWrapper_c647()
{
    // Dispatch wrapper (cdecl, no arguments): first calls sub_50FEA7 (0x0050FEA7) with the constant argument 1u, then calls the function pointer stored at global off_5D7804 (0x005D7804) and returns its result.
    // CALL: Call sub_50FEA7 (0x0050FEA7) with the constant argument 1u. [callee:0x0050FEA7, source:raw]
    // CALL: Read the function pointer held at global off_5D7804 (0x005D7804) and invoke it indirectly with no arguments. [global:0x005D7804, source:raw]
    // RETURN: Return the result of the indirect call through off_5D7804. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50C647() {
    //     sub_50FEA7(1u);
    //     return off_5D7804();
    //   }
    // UNRESOLVED: Purpose of the sub_50FEA7(1u) preamble call is unknown.
    // UNRESOLVED: Target of the indirect function pointer off_5D7804 (0x005D7804) is not statically resolvable and unknown.
}
