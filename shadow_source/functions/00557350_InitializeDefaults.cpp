// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00557350
// Canonical corpus name: sub_557350
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_557350_00557350.c

void UnknownObject::InitializeDefaults()
{
    // Constructor/initializer that writes literal defaults into an object: a zero byte at this+0x0, three 1.0f float fields (this+0x28/0x2C/0x30), a 100.0f float at this+0x34, two zero dwords (this+0x58/0x5C), 0xFFFFFF at this+0x60, 65538 at this+0x64, zero at this+0x68, 3 at this+0x6C, and zero bytes at this+0x70 and this+0x90. Returns the this pointer. No reads, no calls, no branches. Callers are MaterialShaderReactionEffectParser (0x004CA480) and UIListNodeManager (0x0054BB40).
    // ASSIGNMENT: Write byte 0 to the flag/type field at this+0x0. [field:this:0x00000000]
    // ASSIGNMENT: Write dword 0 to this+0x20. [field:this:0x00000020]
    // ASSIGNMENT: Write dword 0 to this+0x24. [field:this:0x00000024]
    // ASSIGNMENT: Write dword 1065353216 (1.0f) to the float field at this+0x28. [field:this:0x00000028]
    // ASSIGNMENT: Write dword 1065353216 (1.0f) to the float field at this+0x2C. [field:this:0x0000002C]
    // ASSIGNMENT: Write dword 1065353216 (1.0f) to the float field at this+0x30. [field:this:0x00000030]
    // ASSIGNMENT: Write dword 1120403456 (100.0f) to the float field at this+0x34. [field:this:0x00000034]
    // ASSIGNMENT: Write dword 0 to this+0x58. [field:this:0x00000058]
    // ASSIGNMENT: Write dword 0 to this+0x5C. [field:this:0x0000005C]
    // ASSIGNMENT: Write dword 0xFFFFFF (16777215) to the color-like field at this+0x60. [field:this:0x00000060]
    // ASSIGNMENT: Write dword 65538 to the flags field at this+0x64. [field:this:0x00000064]
    // ASSIGNMENT: Write dword 0 to this+0x68. [field:this:0x00000068]
    // ASSIGNMENT: Write dword 3 to the count/category field at this+0x6C. [field:this:0x0000006C]
    // ASSIGNMENT: Write byte 0 to the flag field at this+0x70. [field:this:0x00000070]
    // ASSIGNMENT: Write byte 0 to the flag field at this+0x90. [field:this:0x00000090]
    // RETURN: Return the this pointer unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   void* InitializeDefaults(_DWORD* this) {
    //     *(BYTE*)this = 0;
    //     this[0x20/4] = 0;
    //     this[0x24/4] = 0;
    //     this[0x28/4] = 1065353216; /* 1.0f * /
    //     this[0x2C/4] = 1065353216; /* 1.0f * /
    //     this[0x30/4] = 1065353216; /* 1.0f * /
    //     this[0x34/4] = 1120403456; /* 100.0f * /
    //     this[0x58/4] = 0;
    //     this[0x5C/4] = 0;
    //     this[0x60/4] = 0xFFFFFF;
    //     this[0x64/4] = 65538;
    //     this[0x68/4] = 0;
    //     this[0x6C/4] = 3;
    //     *((BYTE*)this + 0x70) = 0;
    //     *((BYTE*)this + 0x90) = 0;
    //     return this;
    //   }
    // UNRESOLVED: The object type is unknown; it is constructed by both MaterialShaderReactionEffectParser (0x004CA480) and UIListNodeManager (0x0054BB40), which share no proven common owner.
    // UNRESOLVED: Semantics of the literal fields are unproven: the three 1.0f floats may be a scale/vector default, 100.0f a length or count default, 0xFFFFFF a white color, 65538 a packed flag word, 3 a count or category, and the byte fields type/state flags.
    // UNRESOLVED: No vtable pointer is written here, so it cannot be determined whether this is a complete constructor or a partial field-reset helper on an already-vtabled object.
    // UNRESOLVED: Whether callers allocate this object (and with what size) is not visible in this function.
}
