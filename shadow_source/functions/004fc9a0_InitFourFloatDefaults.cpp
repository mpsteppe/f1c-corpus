// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC9A0
// Canonical corpus name: FloatArrayInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatArrayInitializer_004fc9a0.c

void UnknownObject::InitFourFloatDefaults()
{
    // Initializes four consecutive DWORD/float fields on a __thiscall object to default values: offset 0x0 to 0 (0.0f), 0x4 to 1101004800 (20.0f), 0x8 to 1050253722 (0.3f), and 0xC to 0 (0.0f). Returns the object pointer (this). No guards, globals or callees; unconditional four-field initialization.
    // ASSIGNMENT: Set this+0x0 to literal 0 (default 0.0f). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set this+0x4 to literal 1101004800, the IEEE-754 bit pattern of 20.0f. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set this+0x8 to literal 1050253722, the IEEE-754 bit pattern of 0.3f. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set this+0xC to literal 0 (default 0.0f). [field:this:0x0000000C, source:raw]
    // RETURN: Return the original this pointer, making the result the freshly-initialized object. [source:raw, function:0x004FC9A0]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4FC9A0(_DWORD *this) {
    //     this[0] = 0;
    //     this[1] = 1101004800;  // 20.0f
    //     this[2] = 1050253722;  // 0.3f
    //     this[3] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The owning class of this four-float configuration object is unknown; only the per-field defaults are evidenced.
    // UNRESOLVED: The semantic meaning of the 20.0f and 0.3f defaults (a range/proportion pair on a per-object basis) depends on the unknown owner.
    // UNRESOLVED: Callers sub_4FCC30, sub_4FD8B0 and sub_4FE350 are known but their role in invoking this initializer is not analyzed here.
}
