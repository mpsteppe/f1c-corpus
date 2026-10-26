// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C910
// Canonical corpus name: sub_47C910
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47C910_0047c910.c

void UnknownObject::ObjectInitWithVTable_5A6A68()
{
    // Object constructor: calls UIConstructorWithVTableParams(this, 0, 1065353216), then initializes field at offset 0xFC (this[63]) to 0, then sets vtable pointer at offset 0x0 to off_5A6A68, and returns this.
    // CALL: Call base UI constructor UIConstructorWithVTableParams(this, 0, 1065353216). [callee:0x0048D3A0]
    // ASSIGNMENT: Set field at offset 0xFC (this[63]) to 0. [field:this:0x000000FC]
    // ASSIGNMENT: Set vtable pointer at offset 0x0 to the address of off_5A6A68. [field:this:0x00000000, global:0x005A6A68]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* ObjectInitWithVTable_5A6A68(_DWORD* this) {
    //     UIConstructorWithVTableParams((int)this, 0, 1065353216);
    //     this[63] = 0;
    //     *this = &off_5A6A68;
    //     return this;
    //   }
    // UNRESOLVED: Object type identity and owner are unknown; packet has no owner evidence.
    // UNRESOLVED: Semantics of constructor parameters 0 and 1065353216 depend on UIConstructorWithVTableParams; interpretation of 1065353216 as float 1.0 comes from skeleton prose only.
    // UNRESOLVED: Purpose of the zero-initialized field at offset 0xFC (dispatch mode/state guess) is unproven.
}
