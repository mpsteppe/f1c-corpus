// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495790
// Canonical corpus name: FieldGetterAt0x1570
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldGetterAt0x1570_00495790.c

void UnknownObject::FieldGetterAt0x1570()
{
    // Trivial getter: reads the DWORD at offset 0x1570 of this (this[1372]) and returns it unchanged. No guards, globals or callees. Used as a field read by UIScreenSelectionHandler (0x0048D6B0).
    // RETURN: Reads the DWORD at offset 0x1570 of this (this[1372]) and returns it unchanged. [field:this:0x00001570, source:raw]
    // CALL: Invoked by UIScreenSelectionHandler (0x0048D6B0) to read the field at offset 0x1570. [caller:0x0048D6B0]

    // Conservative worker pseudocode:
    //   return this[0x1570];
    // UNRESOLVED: The meaning of the field at offset 0x1570 and the owning class are unidentified; no other reads or writes of the field are recorded in the packet.
}
