// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00550870
// Canonical corpus name: StructZeroInitWithUnitVector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructZeroInitWithUnitVector_00550870.c

void UnknownObject::StructZeroInitWithUnitVector()
{
    // Constructor/initializer: calls GlobalZeroInit_c2a0, zeroes the leading dwords and byte 0x1C, sets the +0x4 dword to 1065353216 (1.0f) as a unit-vector-like component, and zeroes the trailing +0x2C and +0x30 dwords before returning this.
    // CALL: Call GlobalZeroInit_c2a0(this) to run the shared zero-initialization helper. [callee:0x0053C2A0]
    // ASSIGNMENT: Set the dword at this+0x0 to 0. [field:this:0x00000000]
    // ASSIGNMENT: Set the dword at this+0x4 to 1065353216 (1.0f), the unit component. [field:this:0x00000004]
    // ASSIGNMENT: Set the dword at this+0x8 to 0. [field:this:0x00000008]
    // ASSIGNMENT: Set the dword at this+0xC to 0. [field:this:0x0000000C]
    // ASSIGNMENT: Set the dword at this+0x10 to 0. [field:this:0x00000010]
    // ASSIGNMENT: Set the dword at this+0x14 to 0. [field:this:0x00000014]
    // ASSIGNMENT: Set the dword at this+0x18 to 0. [field:this:0x00000018]
    // ASSIGNMENT: Set the byte at this+0x1C to 0 (byte-width write, distinct from the dword writes). [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Set the dword at this+0x2C to 0. [field:this:0x0000002C]
    // ASSIGNMENT: Set the dword at this+0x30 to 0. [field:this:0x00000030]
    // RETURN: Return this as the initialized object. [function:0x00550870, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_550870(void* this) {
    //     GlobalZeroInit_c2a0(this);
    //     *(unsigned*)this = 0;
    //     *(unsigned*)((char*)this + 4) = 1065353216; /* 1.0f * /
    //     *(unsigned*)((char*)this + 8) = 0;
    //     *(unsigned*)((char*)this + 0xC) = 0;
    //     *(unsigned*)((char*)this + 0x10) = 0;
    //     *(unsigned*)((char*)this + 0x14) = 0;
    //     *(unsigned*)((char*)this + 0x18) = 0;
    //     *((char*)this + 0x1C) = 0;
    //     *(unsigned*)((char*)this + 0x2C) = 0;
    //     *(unsigned*)((char*)this + 0x30) = 0;
    //     return this;
    //   }
    // UNRESOLVED: Field roles (especially why +0x4 receives 1.0f while all other listed fields are zeroed) depend on the owning object's layout, which is unknown.
    // UNRESOLVED: Byte-width write at +0x1C inside an otherwise dword-initialized struct may indicate a flag or bitfield sub-field.
}
