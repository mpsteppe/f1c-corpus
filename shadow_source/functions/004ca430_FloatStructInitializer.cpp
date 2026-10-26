// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CA430
// Canonical corpus name: FloatStructInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatStructInitializer_004ca430.c

void UnknownObject::FloatStructInitializer()
{
    // Constructor/initializer for an unknown object: writes unit scalars 1.0f to +0xC, +0x10, +0x14, zeroes +0x18..+0x2C, then sets float constants 10.0f (+0x30), 3.0f (+0x34, +0x38, +0x3C), 0.25f (+0x44) and 16.0f (+0x48), and zeroes +0x4C. Always returns 0.
    // ASSIGNMENT: Write unit scalar 1.0f (1065353216) to +0xC, +0x10, +0x14. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014]
    // ASSIGNMENT: Zero fields +0x18 through +0x2C (this[6..11]). [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // ASSIGNMENT: Write 10.0f (1092616192) to +0x30. [field:this:0x00000030]
    // ASSIGNMENT: Write 3.0f (1077936128) to +0x34, +0x38, +0x3C. [field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C]
    // ASSIGNMENT: Write 0.25f (1048576000) to +0x44, 16.0f (1098907648) to +0x48, and zero +0x4C. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C]
    // RETURN: Return integer result 0. [function:0x004CA430]

    // Conservative worker pseudocode:
    //   FloatStructInitializer(_DWORD *this) {
    //     this[+0xC] = this[+0x10] = this[+0x14] = 1.0f;
    //     this[+0x18..+0x2C] = 0;
    //     this[+0x30] = 10.0f;
    //     this[+0x34] = this[+0x38] = this[+0x3C] = 3.0f;
    //     this[+0x44] = 0.25f; this[+0x48] = 16.0f; this[+0x4C] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Object type unknown. The single caller is MaterialShaderReactionEffectParser (0x004CA480), suggesting a material-shader reaction-effect context, but the caller name alone is insufficient evidence to name the owner.
    // UNRESOLVED: The packet ABI names it Float_Struct_Initializer with LEGACY trust, which is not a schema-valid trust value, so owner trust is retained as UNKNOWN.
}
