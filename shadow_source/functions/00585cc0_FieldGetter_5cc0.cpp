// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585CC0
// Canonical corpus name: FieldGetter_5cc0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldGetter_5cc0_00585cc0.c

void UnknownObject::FieldGetter_5cc0()
{
    // Getter: returns the dword stored at offset 0x78 of the this object (this[30]). Pure read, no calls, no guards, no side effects.
    // RETURN: Return the dword read from this+0x78 (this[30]). [field:this:0x00000078, source:raw]

    // Conservative worker pseudocode:
    //   int sub_585CC0(void *this) {
    //     return *(int *)((char *)this + 0x78);
    //   }
    // UNRESOLVED: Meaning of field 0x78 of the this object is unknown; callers include trigger iteration and state propagation paths, so it may be a state tag or trigger identifier, but that is not established.
}
