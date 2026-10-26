// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00457CD0
// Canonical corpus name: StructFieldZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldZeroInit_00457cd0.c

void UnknownObject::StructFieldZeroInit()
{
    // Initializer that zeroes the seven leading DWORD fields (offsets 0x0 through 0x18) and the byte at offset 0x1C, then returns the struct pointer.
    // ASSIGNMENT: Zero the leading DWORDs at offsets 0x0, 0x4, 0x8, 0xC, 0x10, 0x14 and 0x18. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018]
    // ASSIGNMENT: Zero the byte at offset 0x1C (this + 28). [field:this:0x0000001C]
    // RETURN: Return the struct pointer in this (the this value). [source:raw]

    // Conservative worker pseudocode:
    //   DWORD* StructFieldZeroInit(DWORD* this) {
    //     this[0] = 0;
    //     this[1] = 0;
    //     this[2] = 0;
    //     this[3] = 0;
    //     this[4] = 0;
    //     this[5] = 0;
    //     this[6] = 0;
    //     *((BYTE*)this + 28) = 0;
    //     return this;
    //   }
    // UNRESOLVED: Owner object is unknown; called from F_3DTransformObjectInit (0x004583B0), so the struct may be a 3D transform-related sub-object.
    // UNRESOLVED: Whether the 0x1C byte is a flag, type tag or padding is unknown.
}
