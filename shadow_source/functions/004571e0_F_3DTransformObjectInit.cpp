// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004571E0
// Canonical corpus name: F_3DTransformObjectInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DTransformObjectInit_004571e0.c

void UnknownObject::F_3DTransformObjectInit()
{
    // Constructor/initializer for a 3D transform/camera object: stores a vtable pointer at this[0], copies a base directory string into the global byte_5EA438 buffer via StringCopyWithBufferRealloc, then initializes ~39 fields: zeroed state fields, an invalid-handle sentinel -1 at +0x8, field-of-view constants (60.0/45.0), scale/zoom scalars (1.0, 0.5), a far-clip/range value 500.0, a 25.0 parameter, and a set flag at +0x70. Returns the this pointer.
    // ASSIGNMENT: Store vtable pointer off_59EFEC into the object header at this[0] (+0x0). [field:this:0x00000000, global:0x0059EFEC]
    // CALL: Copy a base directory path into the global string buffer byte_5EA438 via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005EA438]
    // ASSIGNMENT: Zero this[1] (+0x4) and write -1 (invalid handle sentinel) to this[2] (+0x8). [field:this:0x00000004, field:this:0x00000008]
    // ASSIGNMENT: Zero state fields +0xC through +0x2C (this[3..11]). [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // ASSIGNMENT: Write field-of-view angle constants: 60.0f to +0x30 and +0x38, 45.0f to +0x34 and +0x3C. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C]
    // ASSIGNMENT: Write zoom/scalar 0.5f to +0x40 and far-clip/range 500.0f to +0x44. [field:this:0x00000040, field:this:0x00000044]
    // ASSIGNMENT: Write scale factors: 1.0f to +0x48, +0x4C, +0x50 and 0.5f to +0x54, +0x58. [field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058]
    // ASSIGNMENT: Zero fields +0x5C, +0x60 (byte, via this+96), +0x64, +0x68, +0x6C, +0x74, +0x78. [field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, field:this:0x00000074, field:this:0x00000078]
    // ASSIGNMENT: Set active/enabled flag to 1 at +0x70 (this[28]). [field:this:0x00000070]
    // ASSIGNMENT: Zero fields +0x7C, +0x80, +0x84 (this[31..33]). [field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084]
    // ASSIGNMENT: Write parameter value 25.0f to +0x88 (this[34]). [field:this:0x00000088]
    // ASSIGNMENT: Zero fields +0x90, +0x94, +0x98 and +0x9C (this[39] written as byte via this+156). [field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C]
    // RETURN: Return the this pointer. [function:0x004571E0]

    // Conservative worker pseudocode:
    //   TransformObjectInit(_DWORD *this) {
    //     this[0] = &off_59EFEC;
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     this[1] = 0; this[2] = -1;
    //     this[3..11] = 0;
    //     this[0x30/0x38] = 60.0f; this[0x34/0x3C] = 45.0f;
    //     this[0x40] = 0.5f; this[0x44] = 500.0f;
    //     this[0x48/0x4C/0x50] = 1.0f; this[0x54/0x58] = 0.5f;
    //     this[0x5C..0x6C, 0x74, 0x78, 0x7C..0x84, 0x90..0x9C] = 0;
    //     this[0x70] = 1; this[0x88] = 25.0f;
    //     return this;
    //   }
    // UNRESOLVED: Exact object type is unknown; callers StaticCameraSceneLoader (0x0040B030) and F_3DTransformObjectInit_83b0 (0x004583B0) suggest a 3D scene/camera transform context but are insufficient to name the owner.
}
