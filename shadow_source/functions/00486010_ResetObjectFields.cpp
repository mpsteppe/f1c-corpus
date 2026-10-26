// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486010
// Canonical corpus name: sub_486010
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_486010_00486010.c

void UnknownObject::ResetObjectFields()
{
    // Field initializer: zeroes sixteen fields of the this-object (a byte at +0x64, a byte at +0x6C, and fourteen dwords at +0x80..+0x9C and +0xC8..+0xDC) and sets the byte at +0x65 to 1. Returns 0. No reads, no globals, no calls.
    // ASSIGNMENT: Write 0 to the byte at this+0x64. [field:this:0x00000064, source:raw]
    // ASSIGNMENT: Write 1 to the byte at this+0x65 (the non-zero flag). [field:this:0x00000065, source:raw]
    // ASSIGNMENT: Write 0 to the byte at this+0x6C. [field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0x80. [field:this:0x00000080, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0x84. [field:this:0x00000084, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0x88. [field:this:0x00000088, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0x8C. [field:this:0x0000008C, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0x90. [field:this:0x00000090, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0x94. [field:this:0x00000094, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0x98. [field:this:0x00000098, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0x9C. [field:this:0x0000009C, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0xC8. [field:this:0x000000C8, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0xCC. [field:this:0x000000CC, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0xD0. [field:this:0x000000D0, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0xD4. [field:this:0x000000D4, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0xD8. [field:this:0x000000D8, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0xDC. [field:this:0x000000DC, source:raw]
    // RETURN: Return 0 (initialized result). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_486010(int this) {
    //     *(byte*)(this + 0x64) = 0;
    //     *(byte*)(this + 0x65) = 1;
    //     *(byte*)(this + 0x6C) = 0;
    //     *(dword*)(this + 0x80) = 0; *(dword*)(this + 0x84) = 0;
    //     *(dword*)(this + 0x88) = 0; *(dword*)(this + 0x8C) = 0;
    //     *(dword*)(this + 0x90) = 0; *(dword*)(this + 0x94) = 0;
    //     *(dword*)(this + 0x98) = 0; *(dword*)(this + 0x9C) = 0;
    //     *(dword*)(this + 0xC8) = 0; *(dword*)(this + 0xCC) = 0;
    //     *(dword*)(this + 0xD0) = 0; *(dword*)(this + 0xD4) = 0;
    //     *(dword*)(this + 0xD8) = 0; *(dword*)(this + 0xDC) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Object type and field meanings are unknown; only the byte at +0x65 is set non-zero, suggesting a single enabled/active flag among otherwise-zeroed state.
    // UNRESOLVED: Class identity is not established; only one caller is known.
}
