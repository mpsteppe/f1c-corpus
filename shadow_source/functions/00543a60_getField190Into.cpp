// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543A60
// Canonical corpus name: FieldGetter_3a60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldGetter_3a60_00543a60.c

void UnknownObject::getField190Into()
{
    // Conditional __thiscall getter: writes the dword at offset 0x190 of this into the caller-supplied output pointer a2 when a2 is non-null, then returns a2 unchanged.
    // GUARD: Guard on output pointer a2; the field write happens only when a2 is non-null. [function:0x00543A60, source:raw]
    // ASSIGNMENT: Store the dword at field 0x190 of this into *a2. [field:this:0x00000190, source:raw]
    // RETURN: Return a2 (the output pointer) unchanged. [function:0x00543A60, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_543A60(_DWORD *this, _DWORD *a2) {
    //     if (a2)
    //       *a2 = this[0x190 / 4];
    //     return a2;
    //   }
    // UNRESOLVED: Legacy ABI label 'Reads_field_at_400' does not match the derived 0x190 offset and is not trusted.
    // UNRESOLVED: Caller sub_4FCAA0 semantics are unknown; the purpose of the returned field is unresolved.
}
