// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004979D0
// Canonical corpus name: FieldGetter_79d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldGetter_79d0_004979d0.c

void UnknownObject::GetField0x20()
{
    // Plain field getter (__thiscall): returns the dword at offset 0x20 of this as an int. No side effects, no writes, no callees. Consistent with the template prelabel 'getter: returns field 0x20 of this'. The returned value is consumed by UI/session and object-lookup callers.
    // RETURN: Return the dword stored at this[8] (byte offset 0x20). [field:this:0x00000020, source:raw]
    // CALL: Read by SessionMessageUICommandHandler (0x00470490), UIWidgetVisibilityToggle (0x0048B91A), UIActiveStateToggle (0x0048BBE0), StructInitWithConditionalDefaultRead (0x00567900) and ObjectIDLookupAcross9Arrays (0x005684A0), so the field is read in UI/session and object-id paths. [caller:0x00470490, caller:0x0048B91A, caller:0x0048BBE0, caller:0x00567900, caller:0x005684A0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4979D0(_DWORD *this) {
    //     return this[8];
    //   }
    // UNRESOLVED: Semantics of the dword at offset 0x20 (id, flag, index, handle) are unknown.
    // UNRESOLVED: The concrete object type is unknown; the prelabel getter trust is DERIVED, not independently confirmed.
}
