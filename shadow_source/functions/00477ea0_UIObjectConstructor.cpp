// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477EA0
// Canonical corpus name: UIObjectConstructor_7ea0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIObjectConstructor_7ea0_00477ea0.c

void UnknownObject::UIObjectConstructor()
{
    // Constructor for a UI text display derived class: calls the base constructor UITextDisplayConstructor (0x00488180), initializes a sub-object at this+73 (offset 0x124) via sub_499B10 (0x00499B10), sets three sentinel -1 index fields (this[71] at 0x11C, this[72] at 0x120, this[87] at 0x15C) and a zero counter field (this[86] at 0x158), assigns the vtable off_5A46B0, and returns this.
    // CALL: Base constructor UITextDisplayConstructor (0x00488180) initializes this [callee:0x00488180, field:this:0x00000000, source:raw]
    // CALL: sub_499B10 (0x00499B10) initializes the sub-object at this+73 (offset 0x124) [callee:0x00499B10, source:raw]
    // ASSIGNMENT: Set this[87] (offset 0x15C) to sentinel -1 [field:this:0x0000015C, source:raw]
    // ASSIGNMENT: Set this[86] (offset 0x158) to 0 [field:this:0x00000158, source:raw]
    // ASSIGNMENT: Set this[71] (offset 0x11C) to sentinel -1 [field:this:0x0000011C, source:raw]
    // ASSIGNMENT: Set this[72] (offset 0x120) to sentinel -1 [field:this:0x00000120, source:raw]
    // ASSIGNMENT: Set vtable *this to &off_5A46B0 [field:this:0x00000000, global:0x005A46B0, source:raw]
    // RETURN: Return the this pointer [source:raw]

    // Conservative worker pseudocode:
    //   UITextDisplayConstructor(this);
    //   sub_499B10(this + 73);
    //   this[87] = -1;
    //   this[86] = 0;
    //   this[71] = -1;
    //   this[72] = -1;
    //   this->vtable = &off_5A46B0;
    //   return this;
    // UNRESOLVED: Role of the sub-object at this+73 (offset 0x124) initialized by sub_499B10 not grounded.
    // UNRESOLVED: Meaning of the sentinel -1 index fields (offsets 0x11C, 0x120, 0x15C) not established.
}
