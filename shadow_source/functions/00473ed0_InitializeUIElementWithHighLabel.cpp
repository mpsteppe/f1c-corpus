// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473ED0
// Canonical corpus name: ConstructorWithDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithDefaults_00473ed0.c

void UnknownObject::InitializeUIElementWithHighLabel()
{
    // Constructor for an unconfirmed UI-element object. Calls base initializer ShortComputation_6d60(this, 1), installs vtable off_5A3300 at +0x0, stores pointer unk_7CFD10 at +0x31C, sets flag/counter fields at +0x324..+0x330 to literals 1/0/1/1 and +0x334 to 385, then registers two linked-list text-handle nodes (off_5C32A4 and the "High" handle aHigh) with LinkedListInsertWithNodeAllocation(this, handle, -1), invokes virtual dispatch initialization via SwitchOnActionIDVirtualCall(this), and returns this.
    // CALL: Base-init call ShortComputation_6d60(this, 1) runs inherited construction with flag 1 before any field is written [callee:0x00466D60, source:raw]
    // ASSIGNMENT: vtable install: *this = &off_5A3300 writes the object's virtual table pointer at +0x0 [field:this:0x00000000, global:0x005A3300, source:raw]
    // ASSIGNMENT: this[199] = &unk_7CFD10 stores an external reference pointer at +0x31C [field:this:0x0000031C, global:0x007CFD10, source:raw]
    // ASSIGNMENT: this[201] = 1 initializes the +0x324 flag/counter field to 1 [field:this:0x00000324, source:raw]
    // ASSIGNMENT: this[202] = 0 initializes the +0x328 flag/counter field to 0 [field:this:0x00000328, source:raw]
    // ASSIGNMENT: this[203] = 1 initializes the +0x32C flag/counter field to 1 [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: this[204] = 1 initializes the +0x330 flag/counter field to 1 [field:this:0x00000330, source:raw]
    // ASSIGNMENT: this[205] = 385 initializes the +0x334 numeric field (value/limit/counter preset) to the literal 385 [field:this:0x00000334, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, &off_5C32A4, -1) registers the RegisteredDataPtr text-handle node as the first linked-list entry [callee:0x00486F30, global:0x005C32A4, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, &aHigh, -1) registers the "High" text-handle node as the second linked-list entry [callee:0x00486F30, global:0x005C32A8, source:raw]
    // CALL: SwitchOnActionIDVirtualCall(this) triggers virtual dispatch / action-ID routing initialization [callee:0x004670E0, source:raw]
    // RETURN: Returns this, the fully initialized object [function:0x00473ED0, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this->vtable = &off_5A3300;
    //   this[0x31C/4] = &unk_7CFD10;
    //   this[0x324/4] = 1;
    //   this[0x328/4] = 0;
    //   this[0x32C/4] = 1;
    //   this[0x330/4] = 1;
    //   this[0x334/4] = 385;
    //   LinkedListInsertWithNodeAllocation(this, &off_5C32A4, -1);
    //   LinkedListInsertWithNodeAllocation(this, &aHigh, -1);
    //   SwitchOnActionIDVirtualCall(this);
    //   return this;
    // UNRESOLVED: The concrete class owning this constructor is unidentified; no owner evidence exists in the packet
    // UNRESOLVED: The meaning of the literal 385 at +0x334 (value/limit/counter preset) is unknown
    // UNRESOLVED: The semantics of the four flag fields at +0x324..+0x330 (1/0/1/1) are unknown
    // UNRESOLVED: The purpose of the external reference global unk_7CFD10 stored at +0x31C is unknown
}
