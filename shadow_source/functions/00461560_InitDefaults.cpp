// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461560
// Canonical corpus name: sub_461560
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_461560_00461560.c

void UnknownObject::InitDefaults()
{
    // Constructor/initializer: writes fixed literal defaults into 22 byte-aligned fields of a small object without reading any existing state. All fields are zeroed except a cluster of control-like values at +0x66..+0x6A (16, 1, 1, 100, 1) and the 16-bit field at +0x7C (200). No reads, no globals, no callees; returns 0. Owner object type is not established by this packet.
    // ASSIGNMENT: Zero leading scalar fields: byte at +0x00, +0x20, +0x40, +0x64, +0x65 all set to 0. [field:this:0x00000000, field:this:0x00000020, field:this:0x00000040, field:this:0x00000064, field:this:0x00000065, source:raw]
    // ASSIGNMENT: Write non-zero control-like byte defaults: +0x66 = 16, +0x67 = 1, +0x68 = 1, +0x69 = 100, +0x6A = 1. [field:this:0x00000066, field:this:0x00000067, field:this:0x00000068, field:this:0x00000069, field:this:0x0000006A, source:raw]
    // ASSIGNMENT: Zero remaining state: bytes at +0x6B, +0x6C, +0x6D, +0x6E, dword at +0x60, and words at +0x70, +0x72, +0x74, +0x76, +0x78, +0x7A all set to 0. [field:this:0x00000060, field:this:0x0000006B, field:this:0x0000006C, field:this:0x0000006D, field:this:0x0000006E, field:this:0x00000070, field:this:0x00000072, field:this:0x00000074, field:this:0x00000076, field:this:0x00000078, field:this:0x0000007A, source:raw]
    // ASSIGNMENT: Write 16-bit field at +0x7C = 200. [field:this:0x0000007C, source:raw]
    // RETURN: Return 0. [function:0x00461560, source:raw]

    // Conservative worker pseudocode:
    //   void InitDefaults(byte* this) {
    //       this[0x00] = 0; this[0x20] = 0; this[0x40] = 0;
    //       this[0x64] = 0; this[0x65] = 0;
    //       this[0x66] = 16; this[0x67] = 1; this[0x68] = 1;
    //       this[0x69] = 100; this[0x6A] = 1;
    //       this[0x6B] = 0; this[0x6C] = 0; this[0x6D] = 0;
    //       *(dword*)(this + 0x60) = 0;
    //       *(word*)(this + 0x70) = 0; *(word*)(this + 0x72) = 0;
    //       *(word*)(this + 0x74) = 0; *(word*)(this + 0x76) = 0;
    //       *(word*)(this + 0x78) = 0; *(word*)(this + 0x7A) = 0;
    //       *(word*)(this + 0x7C) = 200;
    //       this[0x6E] = 0;
    //   }
    // UNRESOLVED: The meaning of the non-zero defaults (+0x66 = 16, +0x67 = 1, +0x68 = 1, +0x69 = 100, +0x6A = 1, +0x7C = 200) is unknown; they resemble control/limits configuration, but no consuming code is visible in this packet.
    // UNRESOLVED: Owner object type is not established; caller FAILWRONGDESCRIPTION (0x00461550) does not name a class.
}
