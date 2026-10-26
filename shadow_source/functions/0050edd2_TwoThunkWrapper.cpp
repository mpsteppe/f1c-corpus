// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050EDD2
// Canonical corpus name: TwoThunkWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoThunkWrapper_0050edd2.c

void UnknownObject::TwoThunkWrapper()
{
    // Sequential thunk wrapper: first invokes ThunkViaFunctionPointer with three float arguments and a pointer to a local 4-int stack buffer, then invokes ThunkToIndirectCallViaDAT005d7860 which performs an indirect call through the function pointer at 005d7860, and finally returns the first argument a1 unchanged.
    // CALL: Call ThunkViaFunctionPointer((int)v5, a2, a3, a4), passing the three float arguments and a pointer to the local stack buffer v5. [callee:0x0050DD3A, source:raw]
    // CALL: Call ThunkToIndirectCallViaDAT005d7860, which dispatches through the indirect function pointer at 005d7860. [callee:0x0050D857, source:raw]
    // RETURN: Return the first argument a1 unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50EDD2(int a1, float a2, float a3, float a4) {
    //     int v5[4];
    //     ThunkViaFunctionPointer((int)v5, a2, a3, a4);
    //     ThunkToIndirectCallViaDAT005d7860();
    //     return a1;
    //   }
    // UNRESOLVED: What ThunkViaFunctionPointer writes into the local buffer v5 and why is unresolved.
    // UNRESOLVED: The target and purpose of the indirect call dispatched through function pointer 005d7860 are not resolved here.
    // UNRESOLVED: The meaning of the float triple (a2, a3, a4) forwarded to the first thunk is unknown.
}
