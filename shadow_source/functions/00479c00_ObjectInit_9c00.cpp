// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479C00
// Canonical corpus name: ObjectInit_9c00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInit_9c00_00479c00.c

void UnknownObject::ObjectInit_9c00()
{
    // Straight-line __thiscall object constructor: calls VtableSetWithInitCall(this, 1028443341, 1048576000) to seed an initialization range, then installs the vtable pointer off_5A5AA8 into this[0] and returns this. No guards or branches.
    // CALL: Call VtableSetWithInitCall(this, 1028443341, 1048576000) to initialize the object's state/range fields with the two literal arguments. [abi:lead, callee:0x00466980, source:raw]
    // ASSIGNMENT: Write the vtable pointer off_5A5AA8 into this->vtable at field 0x0. [field:this:0x00000000, global:0x005A5AA8, source:raw]
    // RETURN: Return this as the constructor result. [source:raw]

    // Conservative worker pseudocode:
    //   void *ObjectInit_9c00(_DWORD *this) {
    //     VtableSetWithInitCall(this, 1028443341, 1048576000);
    //     this[0] = &off_5A5AA8;
    //     return this;
    //   }
    // UNRESOLVED: Owner object type is unknown; the packet does not identify a class.
    // UNRESOLVED: Semantic meaning of the literals 1028443341 and 1048576000 passed to VtableSetWithInitCall is not grounded by the packet.
}
