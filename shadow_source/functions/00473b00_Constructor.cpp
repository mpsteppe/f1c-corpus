// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473B00
// Canonical corpus name: Constructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Constructor_00473b00.c

void UnknownObject::Constructor()
{
    // UI element constructor. Runs a base-initializer helper with literal parameter 1, installs the vtable (off_5A2DC0) at offset 0x0, stores the address of byte_7D0474 at this[200] (offset 0x320), writes the literal 278 to this[199] (offset 0x31C), then registers two text-handle nodes (off_5C7084 then off_5C7080) into the element's node list via LinkedListInsertWithNodeAllocation. No callers are listed statically; the skeleton fill places it in the UI element family.
    // CALL: Calls the base-initialization helper sub_48C070(this, 1); the literal 1 selects the base-constructor path [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Writes the vtable address off_5A2DC0 into field this+0x0 [field:this:0x00000000, global:0x005A2DC0, source:raw]
    // ASSIGNMENT: Writes the address of byte_7D0474 into field this+0x320 (source renders this[200], the DWORD index) [field:this:0x00000320, global:0x007D0474, source:raw]
    // ASSIGNMENT: Writes literal 278 into field this+0x31C (source renders this[199], the DWORD index); role of the value is not named by the packet [field:this:0x0000031C, source:raw]
    // CALL: Registers text-handle node off_5C7084 by calling LinkedListInsertWithNodeAllocation(this, &off_5C7084, -1) [callee:0x00486F30, global:0x005C7084, source:raw]
    // CALL: Registers text-handle node off_5C7080 by calling LinkedListInsertWithNodeAllocation(this, &off_5C7080, -1) [callee:0x00486F30, global:0x005C7080, source:raw]
    // RETURN: Returns the constructed object pointer in EAX [function:0x00473B00, source:raw]

    // Conservative worker pseudocode:
    //   sub_48C070(this, 1);
    //   *this = &off_5A2DC0;
    //   this[200] = &byte_7D0474;
    //   this[199] = 278;
    //   LinkedListInsertWithNodeAllocation(this, &off_5C7084, -1);
    //   LinkedListInsertWithNodeAllocation(this, &off_5C7080, -1);
    //   return this;
    // UNRESOLVED: Literal 278 at this+0x31C has no named meaning in the packet; the skeleton fill calls it a value/ID/counter preset (DERIVED)
    // UNRESOLVED: byte_7D0474 is a text-encoding flag only per the skeleton fill (DERIVED); the packet itself provides no name
    // UNRESOLVED: The -1 parameter passed to LinkedListInsertWithNodeAllocation for both nodes is not interpreted by any evidence in this packet
}
