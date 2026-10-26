// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005573A0
// Canonical corpus name: StructInitWithVTableColor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithVTableColor_005573a0.c

void UnknownObject::ColorStateInit()
{
    // Straight-line constructor/initializer for a color-bearing state object. Zeroes the whole object first, then initializes a 4x4 identity transform block at this+0x4, sets a color literal 0xFFFFFF at +0xC, an all-bits-one field at +0x4 (overwritten again by the identity-matrix init), zeroes +0x0 and +0x8, and clears +0x78/+0x7C. Returns the object pointer.
    // CALL: GlobalZeroInit_c2a0(this) zeroes the whole object before any per-field initialization [callee:0x0053C2A0, source:raw]
    // CALL: F_10FloatStructInitializer(this+4) initializes the float block starting at field offset 0x4 [callee:0x0053B130, source:raw]
    // ASSIGNMENT: Write 0 to this[0] (field offset 0x0) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write -1 (all bits set, packet literal 18446744073709551615) to this[1] (field offset 0x4) [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write 0 to this[2] (field offset 0x8) [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write 0xFFFFFF to this[3] (field offset 0xC); a white/opaque color literal [field:this:0x0000000C, source:raw]
    // CALL: Identity44MatrixInit(this+4) writes a 4x4 identity matrix over the float block at field offset 0x4, which is the final state of that region [callee:0x0053B3B0, source:raw]
    // ASSIGNMENT: Write 0 to this[30] (field offset 0x78) [field:this:0x00000078, source:raw]
    // ASSIGNMENT: Write 0 to this[31] (field offset 0x7C) [field:this:0x0000007C, source:raw]
    // RETURN: Return this; the constructed object is also consumed by callers sub_557670 and sub_557CE0 [function:0x005573A0, caller:0x00557670, caller:0x00557CE0, source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   F_10FloatStructInitializer(this + 4);
    //   this[0] = 0;
    //   this[1] = -1;
    //   this[2] = 0;
    //   this[3] = 0xFFFFFF;
    //   Identity44MatrixInit(this + 4);
    //   this[30] = 0;
    //   this[31] = 0;
    //   return this;
    // UNRESOLVED: Field 0x4 is written to -1 and then immediately covered by Identity44MatrixInit(this+4); the -1 write is dead unless F_10FloatStructInitializer does not touch it
    // UNRESOLVED: Whether 0xFFFFFF at +0xC is a color, an RGBA packed value, or a signed/unsigned semantic is not provable from this packet
    // UNRESOLVED: The role of the object (constructor name suggests a color state with an attached 4x4 transform) versus the absent vtable pointer write is not resolved
}
