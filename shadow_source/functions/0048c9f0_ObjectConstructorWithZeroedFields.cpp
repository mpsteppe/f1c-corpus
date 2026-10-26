// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048C9F0
// Canonical corpus name: ObjectConstructorWithZeroedFields
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithZeroedFields_0048c9f0.c

void UnknownObject::ObjectConstructorWithZeroedFields()
{
    // Extended object constructor: runs base initialization via sub_48C070(this, 0), zeroes four extra DWORD fields at offsets 0x31C, 0x320, 0x324 and 0x328, overrides the vtable pointer to off_5AC048, then initializes the list node through LinkedListDestructionWithVTableCall(this) and returns this.
    // CALL: Call sub_48C070(this, 0) to run base constructor initialization with argument 0. [callee:0x0048C070]
    // ASSIGNMENT: Zero the extended field at this+0x31C (source index this[199]). [field:this:0x0000031C]
    // ASSIGNMENT: Zero the extended field at this+0x320 (source index this[200]). [field:this:0x00000320]
    // ASSIGNMENT: Zero the extended field at this+0x324 (source index this[201]). [field:this:0x00000324]
    // ASSIGNMENT: Zero the extended field at this+0x328 (source index this[202]). [field:this:0x00000328]
    // ASSIGNMENT: Override the vtable pointer at this+0x0 to &off_5AC048 after the base constructor set its own. [field:this:0x00000000, global:0x005AC048]
    // CALL: Call LinkedListDestructionWithVTableCall(this) for list node setup. [callee:0x0048D230]
    // RETURN: Return the constructed this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* ObjectConstructorWithZeroedFields(_DWORD* this) {
    //     sub_48C070(this, 0);
    //     this[199] = 0;
    //     this[200] = 0;
    //     this[201] = 0;
    //     this[202] = 0;
    //     *this = &off_5AC048;
    //     LinkedListDestructionWithVTableCall(this);
    //     return this;
    //   }
    // UNRESOLVED: Semantic role of the four zeroed extended fields (offsets 0x31C-0x328) is not determined by this packet.
    // UNRESOLVED: Meaning of argument 0 passed to sub_48C070 depends on the base constructor contract.
    // UNRESOLVED: LinkedListDestructionWithVTableCall is named destructively but is invoked here during construction; its exact behavior is outside this packet.
}
