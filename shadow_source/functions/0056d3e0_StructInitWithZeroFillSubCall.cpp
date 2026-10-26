// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056D3E0
// Canonical corpus name: StructInitWithZeroFillSubCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithZeroFillSubCall_0056d3e0.c

void UnknownObject::StructInitWithZeroFillSubCall()
{
    // Constructor/initializer: zero-fills four consecutive dwords starting at dword index 13 via ZeroInit4Ints, then explicitly zeroes eight other fields at dword indices 1, 3, 5, 7, 9, 10, 11 and 12 (byte offsets 0x4, 0xC, 0x14, 0x1C, 0x24, 0x28, 0x2C, 0x30), then calls sub_56E970(this) and returns this. Called by DynamicsObjectInitialization.
    // CALL: Call ZeroInit4Ints(this + 13) to zero four consecutive dwords starting at dword index 13. [source:raw, callee:0x004BF630]
    // ASSIGNMENT: Zero this[1] at byte offset 0x4. [source:raw, field:this:0x00000004]
    // ASSIGNMENT: Zero this[3] at byte offset 0xC. [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Zero this[5] at byte offset 0x14. [source:raw, field:this:0x00000014]
    // ASSIGNMENT: Zero this[7] at byte offset 0x1C. [source:raw, field:this:0x0000001C]
    // ASSIGNMENT: Zero this[9] at byte offset 0x24. [source:raw, field:this:0x00000024]
    // ASSIGNMENT: Zero this[10] at byte offset 0x28. [source:raw, field:this:0x00000028]
    // ASSIGNMENT: Zero this[11] at byte offset 0x2C. [source:raw, field:this:0x0000002C]
    // ASSIGNMENT: Zero this[12] at byte offset 0x30. [source:raw, field:this:0x00000030]
    // CALL: Call sub_56E970(this) to finalize or continue initialization of the object. [source:raw, callee:0x0056E970]
    // RETURN: Return this, consistent with a constructor-style initializer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_56D3E0(_DWORD* this) {
    //     ZeroInit4Ints(this + 13);   // zeroes dword indices 13..16
    //     this[1] = 0; this[3] = 0; this[5] = 0; this[7] = 0;
    //     this[9] = 0; this[10] = 0; this[11] = 0; this[12] = 0;
    //     sub_56E970(this);
    //     return this;
    //   }
    // UNRESOLVED: Semantic meaning of the eight individually zeroed fields and the four-dword block at this+13 is not established.
    // UNRESOLVED: Purpose of the sub_56E970(this) call (further init, validation, or finalize) is unknown.
    // UNRESOLVED: Owner object type is unidentified; packet owner evidence is empty.
    // UNRESOLVED: Why fields 1, 3, 5, 7, 9, 10, 11, 12 are zeroed individually while 13..16 are zeroed via ZeroInit4Ints is unknown.
}
