// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563EC0
// Canonical corpus name: SwitchParamStoreGlobalSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SwitchParamStoreGlobalSet_00563ec0.c

void UnknownObject::SwitchParamStoreGlobalSet()
{
    // Selects a callback based on the type parameter a4, stores the two parameters into the context struct slots a1[32] and a1[33], publishes the context pointer to the global dword_8D46B4, then dispatches the callback through sub_564A00 with a1[1] as the callback-specific argument. Returns the result of the dispatch.
    // STATE_TRANSITION: Switch on a4 (via jump table jpt_563EC9): case 0 selects sub_563F20, case 1 selects PhysicsSignDirectionFunction, case 2 selects PhysicsObjectNameCompare, default selects sub_564090. [global:0x00563F10, global:0x00563F20, global:0x00563F70, global:0x00564000, global:0x00564090, source:raw]
    // ASSIGNMENT: Store the parameters: a1[32] = a3 and a1[33] = a2. [source:raw]
    // ASSIGNMENT: Write the context pointer a1 to the global dword_8D46B4. [global:0x008D46B4, source:raw]
    // CALL: Dispatch through sub_564A00 with a1[1] and the selected callback pointer. [callee:0x00564A00, source:raw]
    // RETURN: Return the result of the sub_564A00 dispatch call. [source:raw]

    // Conservative worker pseudocode:
    //   int SwitchParamStoreGlobalSet(int *a1, int a2, int a3, int a4) {
    //     cb = (a4==0) ? sub_563F20 : (a4==1) ? PhysicsSignDirectionFunction
    //         : (a4==2) ? PhysicsObjectNameCompare : sub_564090;
    //     a1[32] = a3; a1[33] = a2;
    //     dword_8D46B4 = a1;
    //     return sub_564A00(a1[1], cb);
    //   }
    // UNRESOLVED: Semantics of the four callback targets (sub_563F20, PhysicsSignDirectionFunction, PhysicsObjectNameCompare, sub_564090) and the dispatch contract of sub_564A00 are unproven.
    // UNRESOLVED: The struct layout of a1 and the meaning of slots a1[32] and a1[33] are unknown.
    // UNRESOLVED: Role of the global context pointer dword_8D46B4 (set here, read elsewhere) is unknown.
}
