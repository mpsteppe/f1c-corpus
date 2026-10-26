// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00474440
// Canonical corpus name: sub_474440
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_474440_00474440.c

void UnknownObject::InitializeRegisteredLabelElement()
{
    // UI element initializer (thiscall, constructor-style). Runs the base initializer sub_48C070(this, 1), installs the vtable off_5A3A80 at this+0, stores the literal 395 at this[199] (this+0x31C), registers three text-handle nodes (off_5BE704, off_5C32A4, aHigh) into the element's linked list via LinkedListInsertWithNodeAllocation with node id -1, then calls sub_474510(this) and returns this.
    // CALL: sub_48C070(this, 1) runs the base initializer with parameter 1. [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Install the vtable for this element type: *this = &off_5A3A80. [field:this:0x00000000, global:0x005A3A80, source:raw]
    // ASSIGNMENT: Store the literal value 395 at this[199], i.e. the field at this+0x31C. [field:this:0x0000031C, source:raw]
    // CALL: Register three text-handle nodes into the element's linked list via LinkedListInsertWithNodeAllocation(this, node, -1): off_5BE704 (standard label handle), off_5C32A4 (RegisteredDataPtr handle), and aHigh ('High' label handle). [callee:0x00486F30, global:0x005BE704, global:0x005C32A4, global:0x005C32A8, source:raw]
    // CALL: sub_474510(this) completes additional initialization specific to this element type. [callee:0x00474510, source:raw]
    // RETURN: Return this (constructor-style initializer returning the initialized object). [source:raw]

    // Conservative worker pseudocode:
    //   void *InitializeRegisteredLabelElement(void *this) {
    //     sub_48C070(this, 1);
    //     *(int*)this = (int)&off_5A3A80;
    //     this[199] = 395;
    //     LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
    //     LinkedListInsertWithNodeAllocation(this, (int)&off_5C32A4, -1);
    //     LinkedListInsertWithNodeAllocation(this, (int)aHigh, -1);
    //     sub_474510(this);
    //     return this;
    //   }
    // UNRESOLVED: Owner object type is not established; the UI element that owns this initializer is UnknownObject.
    // UNRESOLVED: The role of the literal 395 at this+0x31C and the meaning of the node id -1 are caller/domain-specific.
    // UNRESOLVED: The exact nature of the three text handles (off_5BE704, off_5C32A4, aHigh) requires the referencing UI code.
}
