// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E174
// Canonical corpus name: IndirectDispatchViaGlobalFunctionPointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndirectDispatchViaGlobalFunctionPointer_0050e174.c

void UnknownObject::IndirectDispatchViaGlobalFunctionPointer()
{
    // Four-argument stdcall wrapper that first invokes sub_50FEA7 with constant 1 (a prepare/disable step shared by the indirect-call family) and then forwards its arguments (int a1, int a2, int a3, float a4) to the function pointer stored in global off_5D7854, returning the indirect call's result unchanged.
    // CALL: Call sub_50FEA7(1u) as a fixed preparation step before dispatching [callee:0x0050FEA7, source:raw]
    // CALL: Dispatch to the function pointer stored in global off_5D7854, passing a1, a2, a3, a4 through unchanged [global:0x005D7854, source:raw]
    // RETURN: Return the result of the indirect call as the wrapper's return value [function:0x0050E174, source:raw]

    // Conservative worker pseudocode:
    //   sub_50FEA7(1u);
    //   return off_5D7854(a1, a2, a3, a4);
    // UNRESOLVED: The concrete target of off_5D7854 is resolved at runtime and not statically identifiable; only the read of the global is evidenced
    // UNRESOLVED: The semantics of sub_50FEA7(1u) are not established here
    // UNRESOLVED: The callees list contains an entry whose address equals this function itself (0x0050E174), treated as IDA self-reference metadata rather than a real call
}
