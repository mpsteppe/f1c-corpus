// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004583B0
// Canonical corpus name: F_3DTransformObjectInit_83b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DTransformObjectInit_83b0_004583b0.c

void UnknownObject::F_3DTransformObjectInit_83b0()
{
    // Initializes a 3D camera/transform node object: calls base init F_3DTransformObjectInit on this, zero-initializes a sub-struct at this + 176 via StructFieldZeroInit, assigns a vtable pointer from off_59F00C, copies a resource path string via StringCopyWithBufferRealloc from byte_5EA438, zeroes a block of state fields, then fills default float parameters (60.0, 45.0, 0.5, 500.0, 1.0, 25.0 literals) and sets an integer mode field to 2, returning this. Called from MainView (0x0040B850) and sub_4348B0 (0x004348B0).
    // CALL: Call F_3DTransformObjectInit(this) to run the base transform-object initializer. [callee:0x004571E0, source:raw]
    // CALL: Call StructFieldZeroInit(this + 176) to zero-initialize a sub-struct. [callee:0x00457CD0, source:raw]
    // ASSIGNMENT: Assign the vtable pointer: *(DWORD *)this = &off_59F00C. [field:this:0x00000000, global:0x0059F00C, source:raw]
    // CALL: Call StringCopyWithBufferRealloc(byte_5EA438) to copy a resource path string into a buffer. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Zero the dword state fields at +0xC through +0x2C. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Set projection/scale float parameters: +0x30 and +0x38 to 1114636288, +0x34 and +0x3C to 1110704128, +0x40 to 1056964608, +0x44 to 1140457472. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, source:raw]
    // ASSIGNMENT: Set axis-scale float parameters +0x48, +0x4C, +0x50 to 1065353216 and damping parameters +0x54, +0x58 to 1056964608. [field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, source:raw]
    // ASSIGNMENT: Zero the dword fields at +0x5C, +0x64, +0x68, +0x6C and the byte field at +0x60. [field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Set the integer mode field at +0x70 to 2. [field:this:0x00000070, source:raw]
    // ASSIGNMENT: Zero the dword fields at +0x74 through +0x84. [field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, source:raw]
    // ASSIGNMENT: Set the float parameter at +0x88 to 1103626240. [field:this:0x00000088, source:raw]
    // ASSIGNMENT: Zero the dword fields at +0x90, +0x94, +0x98, +0xA4, +0xA8 and the byte fields at +0x9C, +0xA0. [field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C, field:this:0x000000A0, field:this:0x000000A4, field:this:0x000000A8, source:raw]
    // ASSIGNMENT: Set the float parameter at +0xAC to 1065353216. [field:this:0x000000AC, source:raw]
    // RETURN: Return this. [source:raw, caller:0x0040B850, caller:0x004348B0]

    // Conservative worker pseudocode:
    //   int F_3DTransformObjectInit_83b0(int this) {
    //     F_3DTransformObjectInit((_DWORD *)this);
    //     StructFieldZeroInit((_DWORD *)(this + 176));
    //     *(_DWORD *)this = &off_59F00C;
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     this[0xC..0x2C] = 0;
    //     this[0x30] = 1114636288; this[0x34] = 1110704128;
    //     this[0x38] = 1114636288; this[0x3C] = 1110704128;
    //     this[0x40] = 1056964608; this[0x44] = 1140457472;
    //     this[0x48] = this[0x4C] = this[0x50] = 1065353216;
    //     this[0x54] = this[0x58] = 1056964608;
    //     this[0x5C..0x6C] = 0;
    //     this[0x70] = 2;
    //     this[0x74..0x84] = 0;
    //     this[0x88] = 1103626240;
    //     this[0x90..0xA8] = 0;
    //     this[0xAC] = 1065353216;
    //     return this;
    //   }
    // UNRESOLVED: The concrete object type and the semantic role of each default float parameter (candidate camera FOV, clip distances, or scale factors) are unknown.
    // UNRESOLVED: The vtable identity behind off_59F00C is unknown.
    // UNRESOLVED: The purpose of the sub-struct at +176 initialized by StructFieldZeroInit is unknown.
    // UNRESOLVED: The meaning of StringCopyWithBufferRealloc(byte_5EA438), a resource path string copy, is unknown.
    // UNRESOLVED: The source expression *(DWORD *)this = &off_59F00C assigns an address-of-pointer value; the exact vtable layout is ambiguous.
}
