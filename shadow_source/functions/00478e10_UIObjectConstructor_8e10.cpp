// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478E10
// Canonical corpus name: UIObjectConstructor_8e10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIObjectConstructor_8e10_00478e10.c

void UnknownObject::UIObjectConstructor_8e10()
{
    // Constructor for a UI object. Initializes the text-display sub-object at the object's base via UITextDisplayConstructor, initializes a sub-struct at this[71] (byte offset 0x11C) via sub_499B10, zeroes state fields this+0x150..+0x170, sets this+0x160 to -1 (max marker), assigns the off_5A4A20 vtable to this+0x0, and writes the line/text capacity 148 to this+0x118.
    // CALL: UITextDisplayConstructor initializes the text-display sub-object at the base of this UI object [callee:0x00488180, source:raw]
    // CALL: sub_499B10 initializes the sub-struct located at this[71] (byte offset 0x11C) [callee:0x00499B10, source:raw]
    // ASSIGNMENT: Zero-initialize state fields this+0x150 (this[84]), this+0x15C (this[87]), this+0x164 (this[89]), this+0x168 (this[90]), this+0x16C (this[91]) and this+0x170 (this[92]) [field:this:0x00000150, field:this:0x0000015C, field:this:0x00000164, field:this:0x00000168, field:this:0x0000016C, field:this:0x00000170, source:raw]
    // ASSIGNMENT: Max/limit marker: this+0x160 (this[88]) is set to -1, reported by packet facts as the unsigned literal 18446744073709551615 [field:this:0x00000160, source:raw]
    // ASSIGNMENT: Vtable assignment: the object's first dword (this+0x0) is set to the off_5A4A20 vtable pointer [field:this:0x00000000, global:0x005A4A20, source:raw]
    // ASSIGNMENT: Capacity init: this+0x118 (this[70]) is set to the literal 148, interpreted as a line/text capacity [field:this:0x00000118, source:raw]
    // RETURN: Returns this (the fully initialized object pointer) [source:raw]

    // Conservative worker pseudocode:
    //   UITextDisplayConstructor(this);
    //   sub_499B10(this + 71);
    //   this[87] = 0; this[88] = -1;
    //   this[89] = 0; this[90] = 0; this[91] = 0; this[92] = 0;
    //   this[84] = 0;
    //   this[0] = &off_5A4A20;
    //   this[70] = 148;
    //   return this;
    // UNRESOLVED: The sub-struct initialized by sub_499B10 at this[71] (byte offset 0x11C) has no field layout in this packet
    // UNRESOLVED: UITextDisplayConstructor's own field writes and its effect on this object are not visible from this packet
    // UNRESOLVED: The -1 marker at this+0x160 is reported by packet facts as the unsigned literal 18446744073709551615; its runtime type (signed sentinel vs unsigned max) is not resolvable here
}
