// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479C30
// Canonical corpus name: sub_479C30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_479C30_00479c30.c

void UnknownObject::ObjectInitWithVTable_5A5B60()
{
    // Object constructor: calls UIConstructorWithVTableParams(this, 1116471296, 1123024896), then sets vtable pointer at offset 0x0 to off_5A5B60, then sets the enable flag at offset 0xF0 to 1, and returns this.
    // CALL: Call base UI constructor UIConstructorWithVTableParams(this, 1116471296, 1123024896). [callee:0x0048D3A0]
    // ASSIGNMENT: Set vtable pointer at offset 0x0 to the address of off_5A5B60. [field:this:0x00000000, global:0x005A5B60]
    // ASSIGNMENT: Set field at offset 0xF0 (this[240]) to 1 (enable/active flag). [field:this:0x000000F0]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _BYTE* ObjectInitWithVTable_5A5B60(_BYTE* this) {
    //     UIConstructorWithVTableParams((int)this, 1116471296, 1123024896);
    //     *(_DWORD*)this = &off_5A5B60;
    //     this[240] = 1;
    //     return this;
    //   }
    // UNRESOLVED: Object type identity and owner are unknown; packet has no owner evidence.
    // UNRESOLVED: Semantics of constructor parameters 1116471296 and 1123024896 depend on UIConstructorWithVTableParams; interpretation as float range ~72.0f and ~120.0f comes from skeleton prose only.
    // UNRESOLVED: Whether the flag at offset 0xF0 is toggled elsewhere is unknown.
}
