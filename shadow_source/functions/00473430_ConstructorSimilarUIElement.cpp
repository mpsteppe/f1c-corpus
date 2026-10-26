// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473430
// Canonical corpus name: ConstructorSimilarUIElement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorSimilarUIElement_00473430.c

void UnknownObject::ConstructorSimilarUIElement()
{
    // UI element constructor. Runs a base field initialization (ShortComputation_6d60(this, 1)), installs the vtable pointer off_5A2880 at this[0x0], binds the global dword_7D032C by pointer at this[0x31C], configures flag fields 0x324=1, 0x328=0, 0x32C=1, 0x330=1, sets the value field 0x334 to 271, then registers two text-handle nodes (off_5BE704 and aOn) via LinkedListInsertWithNodeAllocation with node key -1. Returns this.
    // CALL: Run the shared base field initialization ShortComputation_6d60(this, 1) before any element-specific writes. [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5A2880 into this[0x0]. [field:this:0x00000000, global:0x005A2880, source:raw]
    // ASSIGNMENT: Store a pointer to the global dword_7D032C at this[0x31C], binding the element to that global. [field:this:0x0000031C, global:0x007D032C, source:raw]
    // ASSIGNMENT: Configure the four flag fields: this[0x324]=1, this[0x328]=0, this[0x32C]=1, this[0x330]=1. [field:this:0x00000324, field:this:0x00000328, field:this:0x0000032C, field:this:0x00000330, source:raw]
    // ASSIGNMENT: Set the value field this[0x334] to 271. [field:this:0x00000334, source:raw]
    // CALL: Register the text-handle node off_5BE704 by LinkedListInsertWithNodeAllocation(this, off_5BE704, -1). [callee:0x00486F30, global:0x005BE704, source:raw]
    // CALL: Register the text-handle node aOn (the "On" string handle) by LinkedListInsertWithNodeAllocation(this, aOn, -1). [callee:0x00486F30, global:0x005C32C8, source:raw]
    // RETURN: Return this as the constructed element. [function:0x00473430, source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_6d60(this, 1);
    //   this[0x0] = &off_5A2880;
    //   this[0x31C] = &dword_7D032C;
    //   this[0x324] = 1; this[0x328] = 0; this[0x32C] = 1; this[0x330] = 1;
    //   this[0x334] = 271;
    //   LinkedListInsertWithNodeAllocation(this, (int)&off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, (int)&aOn, -1);
    //   return this;
    // UNRESOLVED: The identity and semantics of the global dword_7D032C referenced via this[0x31C] are unknown.
    // UNRESOLVED: The meaning of the flag fields at 0x324/0x328/0x32C/0x330 and the value field at 0x334 is not evidenced.
    // UNRESOLVED: The packet carries no callers, so the construction context is unknown.
    // UNRESOLVED: off_5BE704 and aOn are treated as UI text handles per existing analysis, but their runtime use is not evidenced in this packet.
}
