// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9200
// Canonical corpus name: GuardedFieldAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedFieldAccessor_004f9200.c

void UnknownObject::GuardedFieldAccessor()
{
    // Guard-conditional accessor: when the global dword_8AFE68 is set, resolves the object for a1 via sub_55BDE0 and returns the dword at offset 16 of that object; otherwise returns the literal default 16.
    // GUARD: Branch on the global dword_8AFE68: only when it is nonzero is the resolved object path taken. [global:0x008AFE68, source:raw]
    // CALL: Resolve the target object for the argument a1 with sub_55BDE0(a1). [callee:0x0055BDE0, source:raw]
    // RETURN: Return the dword read at offset 16 of the resolved object when the global guard is set. [callee:0x0055BDE0, global:0x008AFE68, source:raw]
    // RETURN: Return the fallback literal value 16 when the global guard is clear. [global:0x008AFE68, source:raw]

    // Conservative worker pseudocode:
    //   int GuardedFieldAccessor(int a1) {
    //     if (dword_8AFE68) return *(int*)(sub_55BDE0(a1) + 16);
    //     return 16;
    //   }
    // UNRESOLVED: The purpose of the global dword_8AFE68 and the identity of the object resolved by sub_55BDE0 are not established by the packet alone.
    // UNRESOLVED: The relation between the returned dword and the fallback literal 16 is unknown.
}
