// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473E50
// Canonical corpus name: ObjectInitWithGlobalRef
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithGlobalRef_00473e50.c

void UnknownObject::UIElementWithRendererRefInit()
{
    // Initializes a UI element object: runs a shared baseline computation, installs the off_5A3240 vtable, stores a pointer to the unknown global unk_7CFBB4 at offset 0x31C, writes the flag/value sequence (1, 0, 1, 1) at offsets 0x324..0x330 and preset 384 at 0x334, registers two text-handle nodes (off_5BE704 and aOn) into a linked list, then runs virtual dispatch initialization and returns this.
    // CALL: Run the shared baseline computation ShortComputation_6d60 on this with literal argument 1 before any field writes. [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Install the vtable: write this[0] (offset 0x0) = &off_5A3240. [field:this:0x00000000, global:0x005A3240, source:raw]
    // ASSIGNMENT: Write this[199] (offset 0x31C) = &unk_7CFBB4, storing a pointer to an unknown global. [field:this:0x0000031C, global:0x007CFBB4, source:raw]
    // ASSIGNMENT: Write this[201] (offset 0x324) = 1 (flag/counter field). [field:this:0x00000324, source:raw]
    // ASSIGNMENT: Write this[202] (offset 0x328) = 0 (flag/counter field). [field:this:0x00000328, source:raw]
    // ASSIGNMENT: Write this[203] (offset 0x32C) = 1 (flag/counter field). [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: Write this[204] (offset 0x330) = 1 (flag/counter field). [field:this:0x00000330, source:raw]
    // ASSIGNMENT: Write this[205] (offset 0x334) = 384 (value/limit/counter preset). [field:this:0x00000334, source:raw]
    // CALL: Register the first text node: LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1). [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Register the second text node: LinkedListInsertWithNodeAllocation(this, (int)aOn, -1). [callee:0x00486F30, global:0x005C32C8, source:raw]
    // CALL: Trigger virtual dispatch initialization via SwitchOnActionIDVirtualCall(this). [callee:0x004670E0, source:raw]
    // RETURN: Return this (the constructed instance). [source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this->vtable = &off_5A3240;
    //   this[0x31C/4] = &unk_7CFBB4;
    //   this[201] = 1; this[202] = 0; this[203] = 1; this[204] = 1; this[205] = 384;
    //   LinkedListInsertWithNodeAllocation(this, &off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, (int)aOn, -1);
    //   SwitchOnActionIDVirtualCall(this);
    //   return this;
    // UNRESOLVED: Semantic roles of the flag/value fields at offsets 0x324..0x334 are not established from this packet.
    // UNRESOLVED: Meaning of preset value 384 at offset 0x334 is unknown.
    // UNRESOLVED: The global unk_7CFBB4 referenced by the pointer at offset 0x31C is unnamed and its role is unknown.
}
