// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473F50
// Canonical corpus name: UIScreenConstructor_3f50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIScreenConstructor_3f50_00473f50.c

void UnknownObject::InitializeUIScreenWithWeatherFlag()
{
    // Constructor for an unconfirmed UI-screen object. Calls base initializer ShortComputation_6d60(this, 1), installs vtable off_5A33C0 at +0x0, stores pointer dword_7CFC68 at +0x31C, sets flag/counter fields at +0x324..+0x330 to literals 2/0/1/1 and +0x334 to 386, then registers three linked-list text-handle nodes (off_5BE704, off_5C32A4 and the "High" handle aHigh) with LinkedListInsertWithNodeAllocation(this, handle, -1), and returns this.
    // CALL: Base-init call ShortComputation_6d60(this, 1) runs inherited construction with flag 1 before any field is written [callee:0x00466D60, source:raw]
    // ASSIGNMENT: vtable install: *this = &off_5A33C0 writes the object's virtual table pointer at +0x0 [field:this:0x00000000, global:0x005A33C0, source:raw]
    // ASSIGNMENT: this[199] = &dword_7CFC68 stores an external state-flag pointer at +0x31C [field:this:0x0000031C, global:0x007CFC68, source:raw]
    // ASSIGNMENT: this[201] = 2 initializes the +0x324 flag/counter field to 2 [field:this:0x00000324, source:raw]
    // ASSIGNMENT: this[202] = 0 initializes the +0x328 flag/counter field to 0 [field:this:0x00000328, source:raw]
    // ASSIGNMENT: this[203] = 1 initializes the +0x32C flag/counter field to 1 [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: this[204] = 1 initializes the +0x330 flag/counter field to 1 [field:this:0x00000330, source:raw]
    // ASSIGNMENT: this[205] = 386 initializes the +0x334 numeric field (value/limit/counter preset) to the literal 386 [field:this:0x00000334, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1) registers the first UI/text-handle node as linked-list entry [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, &off_5C32A4, -1) registers the RegisteredDataPtr text-handle node as linked-list entry [callee:0x00486F30, global:0x005C32A4, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, &aHigh, -1) registers the "High" text-handle node as linked-list entry [callee:0x00486F30, global:0x005C32A8, source:raw]
    // RETURN: Returns this, the fully initialized object [function:0x00473F50, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this->vtable = &off_5A33C0;
    //   this[0x31C/4] = &dword_7CFC68;
    //   this[0x324/4] = 2;
    //   this[0x328/4] = 0;
    //   this[0x32C/4] = 1;
    //   this[0x330/4] = 1;
    //   this[0x334/4] = 386;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, &off_5C32A4, -1);
    //   LinkedListInsertWithNodeAllocation(this, &aHigh, -1);
    //   return this;
    // UNRESOLVED: The concrete class owning this constructor is unidentified; no owner evidence exists in the packet
    // UNRESOLVED: The meaning of the literal 386 at +0x334 (value/limit/counter preset) is unknown
    // UNRESOLVED: The semantics of the four flag fields at +0x324..+0x330 (2/0/1/1) are unknown
    // UNRESOLVED: The external state-flag global dword_7CFC68 stored at +0x31C is not defined by this packet
}
