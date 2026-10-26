// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004594D0
// Canonical corpus name: StructInitWithFloatConstants
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithFloatConstants_004594d0.c

void UnknownObject::StructInitWithFloatConstants()
{
    // Constructor/initializer for an unknown object: zeroes the low fields +0x4..+0x18, writes a max-float sentinel (2139095039) to +0x1C and +0x20, then fills a mix of zeroed fields and float constants (3.75f, 3.25f, 1.75f, 0.814f, 0.7515f) plus two equal integer literals -755914244 at +0x40 and +0x48, and zeroes the high fields +0xC0..+0xD0. Always returns 0.
    // ASSIGNMENT: Zero low fields +0x4 through +0x18 (this[1..6]). [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018]
    // ASSIGNMENT: Write max-value sentinel 2139095039 (FLT_MAX bit pattern 0x7F7FFFFF) to +0x1C and +0x20. [field:this:0x0000001C, field:this:0x00000020]
    // ASSIGNMENT: Zero fields +0x24 and +0x28 (this[9..10]). [field:this:0x00000024, field:this:0x00000028]
    // ASSIGNMENT: Write float constants 3.75f (+0x2C), 3.25f (+0x34), 1.75f (+0x3C) and zero +0x30, +0x38 between them. [field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C]
    // ASSIGNMENT: Write integer literal -755914244 to +0x40 and +0x48, floats 1062232653 (0.814f) to +0x44 and 1061184077 (0.7515f) to +0x4C, and zero +0x50. [field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050]
    // ASSIGNMENT: Zero high fields +0xC0 through +0xD0 (this[48..52]). [field:this:0x000000C0, field:this:0x000000C4, field:this:0x000000C8, field:this:0x000000CC, field:this:0x000000D0]
    // RETURN: Return integer result 0. [function:0x004594D0]

    // Conservative worker pseudocode:
    //   StructInitWithFloatConstants(_DWORD *this) {
    //     this[+0x4..+0x18] = 0;
    //     this[+0x1C] = this[+0x20] = 2139095039;
    //     this[+0x24] = this[+0x28] = 0;
    //     this[+0x2C] = 3.75f; this[+0x30] = 0;
    //     this[+0x34] = 3.25f; this[+0x38] = 0;
    //     this[+0x3C] = 1.75f;
    //     this[+0x40] = -755914244; this[+0x44] = 0.814f;
    //     this[+0x48] = -755914244; this[+0x4C] = 0.7515f; this[+0x50] = 0;
    //     this[+0xC0..+0xD0] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Object type unknown; single caller is sub_40FE50 (0x0040FE50). The packet ABI names it Struct_Init_with_Float_Constants_4594d0 with LEGACY trust, which is not a schema-valid trust value, so owner trust is retained as UNKNOWN.
    // UNRESOLVED: The +0x40/+0x48 literals are stored as raw decimal -755914244; the packet init_float fields (-518969491456.0) for those offsets are synthesized IEEE decodes and are not asserted here.
}
