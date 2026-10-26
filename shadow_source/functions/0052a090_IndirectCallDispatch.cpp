// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052A090
// Canonical corpus name: IndirectCallDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndirectCallDispatch_0052a090.c

void UnknownObject::IndirectCallDispatch()
{
    // Indirect-call dispatch helper. Reads a function pointer stored at offset 36 of the descriptor object a2, loads an argument value from offset 40 of the same object, calls the pointer with that value followed by a1, and returns the callee's result. The call target is runtime-supplied, making this a vtable- or callback-table-style dispatch site.
    // ASSIGNMENT: Load the indirect call target: the function pointer stored at a2 + 36. [source:raw]
    // ASSIGNMENT: Load the first call argument: the dword stored at a2 + 40. [source:raw]
    // CALL: Indirectly call the function pointer with the value at a2 + 40 as the first argument and a1 as the second argument. [source:raw]
    // RETURN: Return the result of the indirect call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_52A090(int a1, int descriptor) {
    //     return (*(int (__cdecl **)(int, int))(descriptor + 36))(*(int *)(descriptor + 40), a1);
    //   }
    // UNRESOLVED: The descriptor object layout (roles of the fields at offsets 36 and 40) is unknown; only the dispatch pattern is visible.
    // UNRESOLVED: Whether a2 is a vtable, a callback table, or per-object state is caller-dependent.
    // UNRESOLVED: The two callers (sub_52765A and sub_527752) pass different descriptor objects, so the dispatched callee set is not resolved here.
}
