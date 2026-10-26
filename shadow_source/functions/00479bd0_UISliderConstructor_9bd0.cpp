// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479BD0
// Canonical corpus name: UISliderConstructor_9bd0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UISliderConstructor_9bd0_00479bd0.c

void UnknownObject::UISliderConstructor_9bd0()
{
    // Straight-line __thiscall object constructor: calls VtableSetWithInitCall(this, 0, 1048576000) to seed an initialization range, then installs the vtable pointer off_5A59F0 into this[0] and returns this. No guards or branches.
    // CALL: Call VtableSetWithInitCall(this, 0, 1048576000) to initialize the object's state/range fields with the two literal arguments. [abi:lead, callee:0x00466980, source:raw]
    // ASSIGNMENT: Write the vtable pointer off_5A59F0 into this->vtable at field 0x0. [field:this:0x00000000, global:0x005A59F0, source:raw]
    // RETURN: Return this as the constructor result. [source:raw]

    // Conservative worker pseudocode:
    //   void *UISliderConstructor_9bd0(_DWORD *this) {
    //     VtableSetWithInitCall(this, 0, 1048576000);
    //     this[0] = &off_5A59F0;
    //     return this;
    //   }
    // UNRESOLVED: Owner object type is unknown; the packet does not identify a class.
    // UNRESOLVED: Semantic meaning of the literal 1048576000 passed to VtableSetWithInitCall is not grounded by the packet.
}
