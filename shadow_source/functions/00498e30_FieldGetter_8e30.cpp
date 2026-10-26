// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498E30
// Canonical corpus name: FieldGetter_8e30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldGetter_8e30_00498e30.c

void UnknownObject::FieldGetter_8e30()
{
    // Trivial getter: reads the dword field at this+0x48 (this[18]) and returns it. No side effects; called from list/tree/UI traversal paths as a per-node field accessor.
    // ASSIGNMENT: Read the dword field at this+0x48 (index 18) into the return value. [field:this:0x00000048, source:raw]
    // RETURN: Return the value read from this[18]. [source:raw]
    // CALL: Called by ShortComputation_58d0 (0x004958D0), LinkedListSearchWithAction (0x004974A0), UIListSearchByName_76c0 (0x004976C0), UtilityFunction_7890 (0x00497890), NodeInsertionIntoTree (0x00498E50) and LinkedListIteratorAdvance (0x00499870). [caller:0x004958D0, caller:0x004974A0, caller:0x004976C0, caller:0x00497890, caller:0x00498E50, caller:0x00499870, source:raw]

    // Conservative worker pseudocode:
    //   int FieldGetter_8e30(_DWORD* this) {
    //     return this[18];
    //   }
    // UNRESOLVED: The meaning of the dword at this+0x48 (a count, size, index or state field) is not established.
    // UNRESOLVED: The owner class is unknown; callers span list, tree and UI-name-search paths.
}
