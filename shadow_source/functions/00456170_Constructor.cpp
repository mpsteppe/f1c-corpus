// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456170
// Canonical corpus name: F_3DSoundEmitter
// Owner: F3DSoundEmitter [DERIVED]
// Raw source: functions/F_3DSoundEmitter_00456170.c

void F3DSoundEmitter::Constructor()
{
    // Constructor/initializer for a 3D sound emitter object. Installs the object vtable (off_59EFAC), copies the default string held at byte_5EA438 into the object's string buffer, zeroes all state/ID/flag fields, and writes the default floating-point spatial audio parameters (60.0f, 45.0f, 500.0f, 1.0f, 0.5f) across the parameter block. Returns the initialized this pointer.
    // ASSIGNMENT: Install the object vtable: *(DWORD*)(this + 0x0) = &off_59EFAC. [field:this:0x00000000, global:0x0059EFAC]
    // ASSIGNMENT: Zero offset 0x4 and write the all-ones sentinel -1 at offset 0x8 via the alias pointer v2 = this + 1 (dword indices 1 and 2). [field:this:0x00000004, field:this:0x00000008]
    // CALL: Call StringCopyWithBufferRealloc(byte_5EA438) to copy the global default string into the object's string buffer. [callee:0x00566650, global:0x005EA438]
    // ASSIGNMENT: Zero the string/state region at offsets 0xC, 0x10, 0x14, 0x18, 0x1C, 0x20. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020]
    // CALL: Call TripleFieldSetter_6280(0, 0, 0) to zero a triple of adjacent fields through the helper (target fields are not enumerated in this packet). [callee:0x00456280]
    // ASSIGNMENT: Write 60.0f (1114636288) to offsets 0x30 and 0x38 (cone/distance defaults). [field:this:0x00000030, field:this:0x00000038]
    // ASSIGNMENT: Write 45.0f (1110704128) to offsets 0x34 and 0x3C. [field:this:0x00000034, field:this:0x0000003C]
    // ASSIGNMENT: Write 500.0f (1140457472) to offset 0x44. [field:this:0x00000044]
    // ASSIGNMENT: Write 1.0f (1065353216) to offsets 0x48, 0x4C, 0x50. [field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050]
    // ASSIGNMENT: Write 0.5f (1056964608) to offsets 0x40, 0x54, 0x58. [field:this:0x00000040, field:this:0x00000054, field:this:0x00000058]
    // ASSIGNMENT: Zero offsets 0x5C, 0x60 (byte write at this + 96), 0x64, 0x68, 0x6C, 0x70, 0x74, 0x78. [field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078]
    // ASSIGNMENT: Zero offsets 0x80, 0x84, 0x88, 0x8C, 0x90, 0x94, 0x98, 0x9C, 0xA0, 0xA4, 0xA8. [field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C, field:this:0x000000A0, field:this:0x000000A4, field:this:0x000000A8]
    // ASSIGNMENT: Zero offsets 0xAC, 0xB0, 0xB4, 0xB8, 0xBC, 0xC0, 0xC4. [field:this:0x000000AC, field:this:0x000000B0, field:this:0x000000B4, field:this:0x000000B8, field:this:0x000000BC, field:this:0x000000C0, field:this:0x000000C4]
    // RETURN: Return this (the initialized object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   F3DSoundEmitter* F3DSoundEmitter::Constructor(F3DSoundEmitter* this) {
    //     *(DWORD*)((char*)this + 0x0) = (DWORD)&off_59EFAC;
    //     *(DWORD*)((char*)this + 0x4) = 0;
    //     *(DWORD*)((char*)this + 0x8) = -1;
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     // zero offsets 0xC..0x20, then TripleFieldSetter_6280(0, 0, 0)
    //     // float defaults: 0x30/0x38 = 60.0f, 0x34/0x3C = 45.0f, 0x44 = 500.0f,
    //     //   0x48/0x4C/0x50 = 1.0f, 0x40/0x54/0x58 = 0.5f; all other offsets zeroed
    //     return this;
    //   }
    // UNRESOLVED: The exact DirectSound3D role of each float parameter (cone angle vs distance vs gain vs rate) is DERIVED from the audio subsystem label, not proven by this packet.
    // UNRESOLVED: The string semantics of byte_5EA438 (the source copied by StringCopyWithBufferRealloc) cannot be resolved from this function alone.
    // UNRESOLVED: The three fields written by TripleFieldSetter_6280 are not enumerated in this packet's field list.
    // UNRESOLVED: Callers construct this object type; allocation and lifetime context are outside this function.
}
