// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C48C
// Canonical corpus name: LockFunctionPointerCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LockFunctionPointerCall_0050c48c.c

void UnknownObject::LockFunctionPointerCall()
{
    // Dispatch trampoline (six arguments, mixed int/float tail): first calls sub_50FEA7 (0x0050FEA7) with the constant argument 1u, then reads the function pointer stored at global off_5D7894 (0x005D7894) and invokes it indirectly with all six incoming arguments forwarded unchanged, returning its result.
    // CALL: Call sub_50FEA7 (0x0050FEA7) with the constant argument 1u. [callee:0x0050FEA7, source:raw]
    // CALL: Read the function pointer held at global off_5D7894 (0x005D7894) and invoke it indirectly, forwarding the six incoming arguments a1..a6 unchanged. [global:0x005D7894, source:raw]
    // RETURN: Return the result of the indirect call through off_5D7894. [source:raw]

    // Conservative worker pseudocode:
    //   int LockFunctionPointerCall(int a1, int a2, int a3, int a4, float a5, float a6) {
    //     sub_50FEA7(1u);
    //     return off_5D7894(a1, a2, a3, a4, a5, a6);
    //   }
    // UNRESOLVED: Purpose of the sub_50FEA7(1u) preamble call is unknown.
    // UNRESOLVED: Target of the indirect function pointer off_5D7894 (0x005D7894) is not statically resolvable and unknown.
    // UNRESOLVED: The packet lists the function's own address as a callee (callee:0x0050C48C); this likely reflects an alias or dispatch-table entry rather than a recursive call, and is retained as unresolved evidence.
}
