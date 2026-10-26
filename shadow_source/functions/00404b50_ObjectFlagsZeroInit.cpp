// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404B50
// Canonical corpus name: ShortComputation_4b50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_4b50_00404b50.c

void UnknownObject::ObjectFlagsZeroInit()
{
    // Zero-initializes three fields (bytes at offsets 0x14 and 0x15, dword at offset 0x1C) of an object obtained by dereferencing the this pointer, then returns that object pointer.
    // ASSIGNMENT: Read the target object pointer from *this. [field:this:0x00000000]
    // ASSIGNMENT: Write 0 to the byte at obj+0x14. [field:obj:0x00000014]
    // ASSIGNMENT: Write 0 to the byte at obj+0x15. [field:obj:0x00000015]
    // ASSIGNMENT: Write 0 to the dword at obj+0x1C. [field:obj:0x0000001C]
    // RETURN: Return the target object pointer. [source:raw]

    // Conservative worker pseudocode:
    //   obj = *this;
    //   obj->byte_0x14 = 0;
    //   obj->byte_0x15 = 0;
    //   obj->dword_0x1C = 0;
    //   return obj;
    // UNRESOLVED: The object type behind *this is unknown; the only recorded caller is Options_Setup (0x004A0EB0).
}
