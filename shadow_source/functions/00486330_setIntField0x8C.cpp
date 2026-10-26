// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486330
// Canonical corpus name: FieldSetterAt0x8c
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldSetterAt0x8c_00486330.c

void UnknownObject::setIntField0x8C()
{
    // Trivial inline setter: stores the integer argument a2 into this[35] (dword index, byte offset 0x8C) and returns the same value. Unconditional and side-effect free beyond the field write; used by sub_486340 and ObjectRegistration.
    // ASSIGNMENT: Store a2 into this[35], the dword field at byte offset 0x8C. [field:this:0x0000008C, source:raw]
    // RETURN: Return the stored value a2. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_486330(_DWORD* this, int a2) {
    //     this[35] = a2;
    //     return a2;
    //   }
    // UNRESOLVED: Semantic role of the integer field at byte offset 0x8C is not established; the two known writers are sub_486340 and ObjectRegistration.
}
