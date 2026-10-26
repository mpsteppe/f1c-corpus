// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059987C
// Canonical corpus name: LocaleFunctionCallWrapper_987c
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LocaleFunctionCallWrapper_987c_0059987c.c

void UnknownObject::InvokeConstructorWithSEH()
{
    // Straight-line thunk that calls CConstructorWithSEH with the constant arguments 0 and 1 and returns its result. No branches or local state; the read of global dword_8D4478 is recorded in the packet but does not appear in the raw source text.
    // ASSIGNMENT: Pass literal 0 as the first argument to the callee. [source:raw]
    // ASSIGNMENT: Pass literal 1 as the second argument to the callee. [source:raw]
    // CALL: Call CConstructorWithSEH(0, 1). [callee:0x00599C58, source:raw]
    // RETURN: Return the callee's return value unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int InvokeConstructorWithSEH() {
    //     return CConstructorWithSEH(0, 1);
    //   }
    // UNRESOLVED: The packet lists a read of global dword_8D4478 at 0x008D4478, but the raw source text shows no reference to it; its role in this function is unclear.
    // UNRESOLVED: Meaning of the constant arguments 0 and 1 depends on the callee's constructor protocol.
}
