// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DE19
// Canonical corpus name: ShortComputation_de19
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_de19_0050de19.c

void UnknownObject::ThunkViaGlobalPointer_5D7814()
{
    // Thin stdcall proxy: first calls the gate sub_50FEA7 with constant argument 1, then forwards no arguments through the function pointer read from global off_5D7814 and returns its result unchanged. The gate is invoked before the indirect dispatch.
    // CALL: Call sub_50FEA7 with constant 1 before dispatching; the gate runs before the indirect call. [callee:0x0050FEA7, source:raw]
    // CALL: Load the target function pointer from global off_5D7814 and call it with no arguments; its return value is forwarded. [global:0x005D7814, function:0x0050DE19, source:raw]
    // RETURN: Return the integer result produced by the indirect callee. [function:0x0050DE19, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50DE19() {
    //     sub_50FEA7(1u);
    //     return off_5D7814();
    //   }
    // UNRESOLVED: Purpose of the gate sub_50FEA7(1u) and why it is called before dispatch.
    // UNRESOLVED: Runtime target of off_5D7814 is a mutable function pointer; the actual callee is unknown statically.
    // UNRESOLVED: Owner of the object the proxy dispatches into is unknown.
}
