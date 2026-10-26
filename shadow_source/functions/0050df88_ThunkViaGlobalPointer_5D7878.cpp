// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DF88
// Canonical corpus name: Thunk_df88
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_df88_0050df88.c

void UnknownObject::ThunkViaGlobalPointer_5D7878()
{
    // Thin stdcall proxy: first calls the gate sub_50FEA7 with constant argument 1, then forwards no arguments through the function pointer read from global off_5D7878 and returns its result unchanged. The gate is invoked before the indirect dispatch.
    // CALL: Call sub_50FEA7 with constant 1 before dispatching; the gate runs before the indirect call. [callee:0x0050FEA7, source:raw]
    // CALL: Load the target function pointer from global off_5D7878 and call it with no arguments; its return value is forwarded. [global:0x005D7878, function:0x0050DF88, source:raw]
    // RETURN: Return the integer result produced by the indirect callee. [function:0x0050DF88, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50DF88() {
    //     sub_50FEA7(1u);
    //     return off_5D7878();
    //   }
    // UNRESOLVED: Purpose of the gate sub_50FEA7(1u) and why it is called before dispatch.
    // UNRESOLVED: Runtime target of off_5D7878 is a mutable function pointer; the actual callee is unknown statically.
    // UNRESOLVED: Owner of the object the proxy dispatches into is unknown.
}
