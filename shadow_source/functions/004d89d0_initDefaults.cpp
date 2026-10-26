// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D89D0
// Canonical corpus name: sub_4D89D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D89D0_004d89d0.c

void UnknownObject::initDefaults()
{
    // Linear default-initializer for a per-object struct (thiscall). Sets three index/id dwords at +0x0/+0x4/+0x8 to -1 (invalid), nulls the +0xC pointer, zeroes the 100-byte block after +0x10 via memset(0x64 bytes), nulls three sub-object slots at +0x74/+0x78/+0x7C, nulls the +0xD8 slot, and stores configuration defaults: 0.5f at +0xDC, byte 1 at +0xE0, 1.0f at +0xE4 and 1.0f at +0xE8. Returns 0.
    // ASSIGNMENT: Set dword at +0x0 to -1 (invalid index/iterator) [field:this:0x00000000]
    // ASSIGNMENT: Set dword at +0x4 to -1 (invalid index/iterator) [field:this:0x00000004]
    // ASSIGNMENT: Set dword at +0x8 to -1 (invalid index/iterator) [field:this:0x00000008]
    // ASSIGNMENT: Set pointer dword at +0xC to 0 (null) [field:this:0x0000000C]
    // CALL: memset(this + 4, 0, 0x64): zero the 100-byte block following +0x10 [source:raw, function:0x004D89D0]
    // ASSIGNMENT: Set dword at +0x74 to 0 (null sub-object slot) [field:this:0x00000074]
    // ASSIGNMENT: Set dword at +0x78 to 0 (null sub-object slot) [field:this:0x00000078]
    // ASSIGNMENT: Set dword at +0x7C to 0 (null sub-object slot) [field:this:0x0000007C]
    // ASSIGNMENT: Set dword at +0xD8 to 0 (null slot) [field:this:0x000000D8]
    // ASSIGNMENT: Set float at +0xDC to 1056964608 (0.5f) scale/ratio default [field:this:0x000000DC]
    // ASSIGNMENT: Set byte at +0xE0 to 1 (enabled flag default) [field:this:0x000000E0]
    // ASSIGNMENT: Set float at +0xE4 to 1065353216 (1.0f) scale default [field:this:0x000000E4]
    // ASSIGNMENT: Set float at +0xE8 to 1065353216 (1.0f) scale default [field:this:0x000000E8]
    // RETURN: Return 0 as result [source:raw, function:0x004D89D0]

    // Conservative worker pseudocode:
    //   this->idx1 = -1;
    //   this->idx2 = -1;
    //   this->idx3 = -1;
    //   this->ptr = 0;
    //   memset(this + 4, 0, 0x64);
    //   this->sub[0] = 0; this->sub[1] = 0; this->sub[2] = 0;
    //   this->slotD8 = 0;
    //   this->scaleHalf = 0.5f;
    //   this->flagE0 = 1;
    //   this->scaleOne1 = 1.0f;
    //   this->scaleOne2 = 1.0f;
    //   return 0;
    // UNRESOLVED: Semantic purpose of the -1 sentinels at +0x0/+0x4/+0x8 and the float defaults at +0xDC..+0xE8 is unknown; owner struct type is unnamed.
    // UNRESOLVED: Read of global dword_5ACF34 is present in packet evidence but does not appear in the raw decompiled source text.
}
