// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00474F40
// Canonical corpus name: ObjectConstructorWithVTableAndResourceReg
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithVTableAndResourceReg_00474f40.c

void UnknownObject::UIListTextItemInit()
{
    // Constructor-style initializer (proposed UI list text item): calls the base-class initializer sub_48C070(this, 1), installs the vtable pointer &off_5A4200 at this+0, then registers two resource nodes by inserting &unk_5C6E18 and &off_5C6E14 with index -1 via LinkedListInsertWithNodeAllocation. Returns this. No guards; always executes fully.
    // CALL: sub_48C070(this, 1): run the base-class constructor/initializer with argument 1. [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_5A4200. [field:this:0x00000000, global:0x005A4200, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, (int)&unk_5C6E18, -1): register the first resource handle node. [callee:0x00486F30, global:0x005C6E18, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(this, (int)&off_5C6E14, -1): register the second resource handle node. [callee:0x00486F30, global:0x005C6E14, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   sub_48C070(this, 1);
    //   *this = &off_5A4200;
    //   LinkedListInsertWithNodeAllocation(this, (int)&unk_5C6E18, -1);
    //   LinkedListInsertWithNodeAllocation(this, (int)&off_5C6E14, -1);
    //   return this;
    // UNRESOLVED: Whether unk_5C6E18 and off_5C6E14 are text-handle resources and this object is a UI list text item is proposed by the existing analysis, not confirmed.
    // UNRESOLVED: The semantics of LinkedListInsertWithNodeAllocation (list head vs node ownership) and sub_48C070 are not confirmed from this packet.
    // UNRESOLVED: The meaning of the two -1 index arguments is unknown.
    // UNRESOLVED: The owner class is unknown (UnknownObject).
}
