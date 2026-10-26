// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470AF0
// Canonical corpus name: ObjectInitWithVTablePathRegistration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithVTablePathRegistration_00470af0.c

void UnknownObject::ObjectInitWithVTablePathRegistration()
{
    // UI-list-like object constructor: calls base initializer sub_48C070 with flag 1, installs vtable off_5A0780 at +0x0, sets numeric field +0x31C to 407, appends two linked-list entries (off_5BE704 then aOn) at index -1 (append), and returns the constructed object.
    // CALL: Call base initializer sub_48C070(this, 1). [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Install vtable: this+0x0 = off_5A0780. [field:this:0x00000000, global:0x005A0780]
    // ASSIGNMENT: Set this+0x31C to 407. [field:this:0x0000031C]
    // CALL: Insert linked-list node for off_5BE704 at index -1 (append). [callee:0x00486F30, global:0x005BE704]
    // CALL: Insert linked-list node for aOn at index -1 (append). [callee:0x00486F30, global:0x005C32C8]
    // RETURN: Return constructed object (this). [function:0x00470AF0]

    // Conservative worker pseudocode:
    //   base_init(this, 1);
    //   *this = off_5A0780;
    //   this[199] = 407;
    //   LinkedListInsertWithNodeAllocation(this, off_5BE704, -1);
    //   LinkedListInsertWithNodeAllocation(this, aOn, -1);
    //   return this;
}
