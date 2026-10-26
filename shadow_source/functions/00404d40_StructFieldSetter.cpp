// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404D40
// Canonical corpus name: StructFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldSetter_00404d40.c

void UnknownObject::StructFieldSetter()
{
    // __thiscall setter that writes a caller-supplied dword (a2) into the field at offset 0x20 of the object pointed to by *this, and returns the original object pointer unchanged.
    // ASSIGNMENT: Dereference this to capture the target object pointer stored at this+0 into result. [field:this:0x00000000]
    // ASSIGNMENT: Write parameter a2 to the dword field at offset 0x20 of the target object (*this + 0x20). [field:obj:0x00000020]
    // RETURN: Return the object pointer captured before the write; the sole known caller is ConfigIniParser (00421CD0). [caller:0x00421CD0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_404D40(int *this, int a2) {
    //     int result = *this;
    //     *(int *)(*this + 0x20) = a2;
    //     return result;
    //   }
    // UNRESOLVED: Semantic role of the 0x20 field on the target object is unknown; this function only provides setter access.
    // UNRESOLVED: The object type behind *this is an unknown allocation owned by the ConfigIniParser path.
}
