// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553DE0
// Canonical corpus name: StructZeroInitConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructZeroInitConstructor_00553de0.c

void UnknownObject::StructZeroInitConstructor()
{
    // __thiscall constructor. Zeroes the base sub-object via GlobalZeroInit_c2a0, initializes the sub-object at this+1 with default values via StructInitWithDefaultValues, then clears this[0] and this[9..16] (offsets 0x0 and 0x24..0x40) to zero. Returns this. No reads, no globals, no guards.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-initialize the base sub-object of the structure. [callee:0x0053C2A0]
    // CALL: Call StructInitWithDefaultValues(this + 1) to populate the sub-object at byte offset 0x4 with its default values. [callee:0x00553DB0]
    // ASSIGNMENT: Write 0 to *this (offset 0x0). [field:this:0x00000000, function:0x00553DE0, source:raw]
    // ASSIGNMENT: Write 0 to this[9] (offset 0x24). [field:this:0x00000024]
    // ASSIGNMENT: Write 0 to this[10] (offset 0x28). [field:this:0x00000028]
    // ASSIGNMENT: Write 0 to this[13] (offset 0x34). [field:this:0x00000034]
    // ASSIGNMENT: Write 0 to this[11] (offset 0x2C). [field:this:0x0000002C]
    // ASSIGNMENT: Write 0 to this[12] (offset 0x30). [field:this:0x00000030]
    // ASSIGNMENT: Write 0 to this[14] (offset 0x38). [field:this:0x00000038]
    // ASSIGNMENT: Write 0 to this[15] (offset 0x3C). [field:this:0x0000003C]
    // ASSIGNMENT: Write 0 to this[16] (offset 0x40). [field:this:0x00000040]
    // RETURN: Return this (pointer to the constructed object). [function:0x00553DE0]

    // Conservative worker pseudocode:
    //   _DWORD *StructZeroInitConstructor(_DWORD *this) {
    //     GlobalZeroInit_c2a0(this);
    //     StructInitWithDefaultValues(this + 1);
    //     this[0] = 0;
    //     this[9] = this[10] = this[11] = this[12] = 0;
    //     this[13] = this[14] = this[15] = this[16] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Caller DirectXDeviceSurfaceInitialization (0x0053D4F0) suggests the object belongs to a DirectX device/surface subsystem, but the exact type is not established.
    // UNRESOLVED: The sub-object at this+1 (byte offset 0x4) initialized by StructInitWithDefaultValues has no field-level evidence in this packet.
}
