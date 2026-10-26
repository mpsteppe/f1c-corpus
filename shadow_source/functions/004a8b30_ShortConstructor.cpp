// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A8B30
// Canonical corpus name: ShortConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortConstructor_004a8b30.c

void UnknownObject::ShortConstructor()
{
    // 3-dword thiscall constructor. Stores vtable/interface pointer from off_5ACBFC into this[0], then sets one value pair this[1] = 0 and this[2] = -1. Called from UIControlWindowInitialization.
    // ASSIGNMENT: Store vtable/interface pointer from off_5ACBFC into this[0] (offset 0x0). [global:0x005ACBFC, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set this[1] (offset 0x4) to 0 - state/counter field. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set this[2] (offset 0x8) to -1 (18446744073709551615) - handle/index (-1 = invalid). [field:this:0x00000008, source:raw]
    // RETURN: Return this (result = this). [source:raw]

    // Conservative worker pseudocode:
    //   this[0] = off_5ACBFC;
    //   this[1] = 0;
    //   this[2] = -1;
    //   return this;
    // UNRESOLVED: Owner class unknown; vtable stored is off_5ACBFC (existing analysis names it UIWidgetVTableSlot, DERIVED, unconfirmed). Semantics of the 0/-1 pair at 0x4/0x8 not confirmed.
}
