// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040BDE0
// Canonical corpus name: StructFieldInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldInitializer_0040bde0.c

void UnknownObject::StructFieldInitializer()
{
    // Plain object-field initializer: writes literal defaults into fourteen fields of a small struct (byte offsets +0x0, +0x4, +0x8, +0xC, +0x14, +0x18, +0x1C, +0x20, +0x24, +0x25, +0x28, +0x2C, +0x2D, +0x2E), most zeroed, with +0xC set to 2 and +0x14 set to the unsigned value 18446744073709551615 (bit pattern of -1). No reads, no globals, no callees, no guards.
    // ASSIGNMENT: Set the DWORD at this+0x0 to 0. [field:this:0x00000000]
    // ASSIGNMENT: Set the DWORD at this+0x4 to 0. [field:this:0x00000004]
    // ASSIGNMENT: Set the DWORD at this+0x8 to 0. [field:this:0x00000008]
    // ASSIGNMENT: Set the DWORD at this+0xC to 2. [field:this:0x0000000C]
    // ASSIGNMENT: Set the DWORD at this+0x14 to the unsigned literal 18446744073709551615 (bit pattern of -1, a sentinel value). [field:this:0x00000014]
    // ASSIGNMENT: Set the DWORD at this+0x18 to 0. [field:this:0x00000018]
    // ASSIGNMENT: Set the DWORD at this+0x1C to 0. [field:this:0x0000001C]
    // ASSIGNMENT: Set the DWORD at this+0x20 to 0. [field:this:0x00000020]
    // ASSIGNMENT: Set the byte at this+0x24 to 0. [field:this:0x00000024]
    // ASSIGNMENT: Set the byte at this+0x25 to 0. [field:this:0x00000025]
    // ASSIGNMENT: Set the DWORD at this+0x28 to 0. [field:this:0x00000028]
    // ASSIGNMENT: Set the byte at this+0x2C to 0. [field:this:0x0000002C]
    // ASSIGNMENT: Set the byte at this+0x2D to 0. [field:this:0x0000002D]
    // ASSIGNMENT: Set the byte at this+0x2E to 0. [field:this:0x0000002E]
    // RETURN: Return the this pointer after all fields are initialized. [source:raw, function:0x0040BDE0, abi:lead]

    // Conservative worker pseudocode:
    //   _DWORD *StructFieldInitializer(_DWORD *this) {
    //     this[0] = 0; this[1] = 0; this[2] = 0;
    //     this[3] = 2;
    //     this[5] = -1;
    //     this[6] = 0; this[7] = 0; this[8] = 0;
    //     *((_BYTE *)this + 44) = 0;
    //     *((_BYTE *)this + 36) = 0;
    //     this[10] = 0;
    //     *((_BYTE *)this + 37) = 0;
    //     *((_BYTE *)this + 45) = 0;
    //     *((_BYTE *)this + 46) = 0;
    //     return this;
    //   }
    // UNRESOLVED: The owning object class and the meaning of each field are unknown; this is a bare initializer with no callees, globals, reads or guards.
    // UNRESOLVED: Semantics of the non-zero literals are unknown: value 2 at +0xC and the unsigned 18446744073709551615 (sentinel -1) at +0x14.
    // UNRESOLVED: Whether +0x24, +0x25, +0x2C, +0x2D and +0x2E are standalone flags or fields packed into wider words is unresolved from this function alone.
}
