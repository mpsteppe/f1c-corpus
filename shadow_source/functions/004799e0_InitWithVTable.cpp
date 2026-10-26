// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004799E0
// Canonical corpus name: InitWithVTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitWithVTable_004799e0.c

void UnknownObject::InitWithVTable()
{
    // Straight-line __thiscall object constructor: calls VtableSetWithInitCall(this, 0, 1050253722) to seed an initialization range, then installs the vtable pointer off_5A57C8 into this[0] and returns this. No guards or branches.
    // CALL: Call VtableSetWithInitCall(this, 0, 1050253722) to initialize the object's state/range fields with the two literal arguments. [abi:lead, callee:0x00466980, source:raw]
    // ASSIGNMENT: Write the vtable pointer off_5A57C8 into this->vtable at field 0x0. [field:this:0x00000000, global:0x005A57C8, source:raw]
    // RETURN: Return this as the constructor result. [source:raw]

    // Conservative worker pseudocode:
    //   void *InitWithVTable(_DWORD *this) {
    //     VtableSetWithInitCall(this, 0, 1050253722);
    //     this[0] = &off_5A57C8;
    //     return this;
    //   }
    // UNRESOLVED: Owner object type is unknown; the packet does not identify a class.
    // UNRESOLVED: Semantic meaning of the literal 1050253722 passed to VtableSetWithInitCall is not grounded by the packet.
}
