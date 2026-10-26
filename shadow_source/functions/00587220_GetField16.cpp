// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587220
// Canonical corpus name: sub_587220
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587220_00587220.c

void UnknownObject::GetField16()
{
    // Getter: returns the dword stored at offset 0x10 of the this object (this[4]). Pure read, no calls, no guards, no side effects.
    // RETURN: Return the dword read from this+0x10 (this[4]). [field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   int sub_587220(void *this) {
    //     return *(int *)((char *)this + 0x10);
    //   }
    // UNRESOLVED: Meaning of field 0x10 of the this object is unknown; one caller is the trigger iteration path, but the field's semantic role is not established.
}
