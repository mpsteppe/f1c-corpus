// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9190
// Canonical corpus name: ConditionalDispatch_9190
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatch_9190_004f9190.c

void UnknownObject::ReadGlobalObjectFieldWithDefault()
{
    // Nullable accessor: when the global object pointer dword_8AFE68 is non-null, returns the dword field read at offset 284 of the pointed object; otherwise returns the default value 1. No side effects. Called by MultiTableCoordinateSearch (0x004F9240).
    // GUARD: Test the object pointer dword_8AFE68 for non-zero (non-null). [global:0x008AFE68, source:raw]
    // CALCULATION: Dereference dword_8AFE68 + 284 to read the field value. [global:0x008AFE68, source:raw]
    // RETURN: Return the dereferenced field when the pointer is non-null, else the default 1. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4F9190() {
    //       if (dword_8AFE68)
    //           return *(_DWORD *)(dword_8AFE68 + 284);
    //       else
    //           return 1;
    //   }
    // UNRESOLVED: Type and owner of the object pointed to by dword_8AFE68 unknown.
    // UNRESOLVED: Meaning of the field at offset 284 of that object unknown.
    // UNRESOLVED: Caller MultiTableCoordinateSearch context not covered by this packet.
}
