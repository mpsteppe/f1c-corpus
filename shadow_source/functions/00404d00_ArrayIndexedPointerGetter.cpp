// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404D00
// Canonical corpus name: ArrayIndexedPointerGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayIndexedPointerGetter_00404d00.c

void UnknownObject::ArrayIndexedPointerGetter()
{
    // Returns the pointer stored at index a1 of the global pointer table off_5BE6C4, cast to int. Indexing is unguarded: any a1 value is accepted and the element is dereferenced directly. Called by sub_422BE0. The canonical name ArrayIndexedPointerGetter (from the packet's LEGACY ABI entry) is retained as the proposed name.
    // CALCULATION: Pointer arithmetic: element address = &off_5BE6C4[a1], i.e. off_5BE6C4 + a1 * element_stride. The off_* symbol type implies 4-byte pointer elements (DERIVED stride, not present verbatim in the packet). [function:0x00404D00, global:0x005BE6C4, source:raw]
    // RETURN: Dereference the indexed element and return it as int. [function:0x00404D00, global:0x005BE6C4, source:raw]
    // UNKNOWN: No bounds guard precedes the dereference; out-of-range a1 yields an out-of-bounds read, so the caller is responsible for a valid index. [caller:0x00422BE0, source:raw]

    // Conservative worker pseudocode:
    //   return (int)off_5BE6C4[a1];
    // UNRESOLVED: The purpose and contents of global pointer table off_5BE6C4 are not established by the packet.
    // UNRESOLVED: Why sub_422BE0 indexes this table and what it does with the returned pointer is outside this packet.
    // UNRESOLVED: The LEGACY ABI record (name 'Returns', address 4214016) carries no prototype; its exact meaning is not resolvable here.
}
