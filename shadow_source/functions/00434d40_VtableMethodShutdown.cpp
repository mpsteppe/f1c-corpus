// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00434D40
// Canonical corpus name: VtableMethodShutdown
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VtableMethodShutdown_00434d40.c

void UnknownObject::VtableMethodShutdown()
{
    // RAII-style cleanup of a heap-allocated polymorphic sub-object: loads the vtable pointer from the sub-object held at this[3] (offset 0xC), dispatches its first virtual method with argument 1 (interpreted as a destructor/delete request), then clears the this[3] pointer to 0. Returns 0 in both paths; when the pointer is already null the dispatch is skipped. Called from ConstraintSolverParamInit (0x00434860) and sub_4348B0 (0x004348B0).
    // CALCULATION: Load the vtable pointer of the sub-object into a local: v2 = this[3] (field at offset 0xC). [field:this:0x0000000C, source:raw]
    // GUARD: Guard on v2 being non-null; when this[3] is null the virtual dispatch and clear are skipped. [field:this:0x0000000C, source:raw]
    // CALL: Invoke the first virtual method of the sub-object (vtable entry at the object head, field *(this+0xC)+0x0) with argument 1, interpreted as a destructor/delete request. [field:*(this+0xC):0x00000000, source:raw]
    // ASSIGNMENT: Clear the sub-object pointer to 0 after deletion: this[3] = 0. [field:this:0x0000000C, source:raw]
    // RETURN: Return 0 in all paths. [source:raw, function:0x00434D40]

    // Conservative worker pseudocode:
    //   int sub_434D40(_DWORD* this) {
    //     void (__thiscall ***v2)(_DWORD, int);
    //     v2 = (void (__thiscall ***)(_DWORD, int))this[3];
    //     if (v2) {
    //       (**v2)(v2, 1);
    //       this[3] = 0;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The virtual method dispatched with argument 1 is assumed to be a destructor or deletion routine; its exact semantics depend on the sub-object's vtable and are not statically resolvable here.
    // UNRESOLVED: Owner class of `this` is unknown; the two recorded callers (ConstraintSolverParamInit at 0x00434860 and sub_4348B0 at 0x004348B0) suggest a constraint-solver-related parameter object.
    // UNRESOLVED: The vtable call target is dynamic and cannot be determined from this packet.
}
