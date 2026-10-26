// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C7C0
// Canonical corpus name: UIObjectInitWithFloatConstant
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIObjectInitWithFloatConstant_0047c7c0.c

void UnknownObject::UIObjectInitWithFloatConstant()
{
    // UI-object constructor: delegates to UIConstructorWithVTableParams with this, integer 0, and the integer constant 1065353216, then stores the caller parameter a2 at offset 0xFC and sets the vtable pointer at offset 0x0 to the global table off_5A69B0. Returns this.
    // CALL: Call UIConstructorWithVTableParams with this, the integer zero, and the integer constant 1065353216 to run the base UI-object construction. [callee:0x0048D3A0, source:raw]
    // ASSIGNMENT: Store the caller parameter a2 into this[63], i.e. the dword at offset 0xFC. [field:this:0x000000FC, source:raw]
    // ASSIGNMENT: Set the vtable pointer at offset 0x0 to the address of the global table off_5A69B0. [field:this:0x00000000, global:0x005A69B0, source:raw]
    // RETURN: Return this after construction. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *UIObjectInitWithFloatConstant(_DWORD *this, int a2) {
    //       UIConstructorWithVTableParams((int)this, 0, 1065353216);
    //       this[63] = a2;
    //       *this = &off_5A69B0;
    //       return this;
    //   }
    // UNRESOLVED: The integer constant 1065353216 is not decoded by the raw source; the existing analysis (DERIVED) reads it as the bit pattern of float 1.0, but that decode is not stated in the source.
    // UNRESOLVED: off_5A69B0 is a vtable/global table, but its layout and the UI object type it describes are not established from this packet.
    // UNRESOLVED: The meaning of the caller-provided value stored at offset 0xFC is not stated in the packet.
}
