// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470CC0
// Canonical corpus name: ObjectConstructorWithGlobalReferences
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithGlobalReferences_00470cc0.c

void UnknownObject::InitializeUIListWithExternalReference()
{
    // Constructor for an unconfirmed UI-list object. Calls base initializer ShortComputation_6d60(this, 1), installs vtable off_5A0840 at +0x0, stores pointer unk_7CF014 at +0x31C, sets flag/counter fields at +0x324..+0x330 to literals 1/0/1/1 and +0x334 to 408, then registers two linked-list text-handle nodes (off_5BE704 and the "On" handle aOn) with LinkedListInsertWithNodeAllocation(this, handle, -1), and returns this.
    // CALL: Base-init call ShortComputation_6d60(this, 1) runs inherited construction with flag 1 before any field is written [callee:0x00466D60, source:raw]
    // ASSIGNMENT: vtable install: *this = &off_5A0840 writes the object's virtual table pointer at +0x0 [field:this:0x00000000, global:0x005A0840, source:raw]
    // ASSIGNMENT: this[199] = &unk_7CF014 stores an external reference pointer at +0x31C [field:this:0x0000031C, global:0x007CF014, source:raw]
    // ASSIGNMENT: this[201] = 1 initializes the +0x324 flag/counter field to 1 [field:this:0x00000324, source:raw]
    // ASSIGNMENT: this[202] = 0 initializes the +0x328 flag/counter field to 0 [field:this:0x00000328, source:raw]
    // ASSIGNMENT: this[203] = 1 initializes the +0x32C flag/counter field to 1 [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: this[204] = 1 initializes the +0x330 flag/counter field to 1 [field:this:0x00000330, source:raw]
    // ASSIGNMENT: this[205] = 408 initializes the +0x334 numeric field (value/type ID/limit) to the literal 408 [field:this:0x00000334, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1) registers the UI/text-handle node as the first linked-list entry [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, &aOn, -1) registers the "On" text-handle node as the second linked-list entry [callee:0x00486F30, global:0x005C32C8, source:raw]
    // RETURN: Returns this, the fully initialized object [function:0x00470CC0, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this->vtable = &off_5A0840;
    //   this[0x31C/4] = &unk_7CF014;
    //   this[0x324/4] = 1;
    //   this[0x328/4] = 0;
    //   this[0x32C/4] = 1;
    //   this[0x330/4] = 1;
    //   this[0x334/4] = 408;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, &aOn, -1);
    //   return this;
    // UNRESOLVED: The concrete class owning this constructor is unidentified; no owner evidence exists in the packet
    // UNRESOLVED: The meaning of the literal 408 at +0x334 (value/type ID/limit) is unknown
    // UNRESOLVED: The semantics of the four flag fields at +0x324..+0x330 (1/0/1/1) are unknown
    // UNRESOLVED: The purpose of the external reference global unk_7CF014 stored at +0x31C is unknown
}
