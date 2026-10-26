// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005523E0
// Canonical corpus name: HashTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HashTable_005523e0.c

void UnknownObject::HashTableEntryDefaultInit()
{
    // Constructor/initializer: first zeroes the whole object via GlobalZeroInit_c2a0, then installs default literals across 26 fields. Float 1.0 (1065353216) is written to offsets 0x0, 0x4, 0x5C and 0x60; integer zeroes to most remaining dwords (0x8, 0xC, 0x10, 0x28, 0x2C, 0x30, 0x44, 0x4C, 0x64) plus the byte at 0x14 and the tail dwords at 0x868/0x86C/0x870; 0x10000 to 0x24; the float -8.0 bit pattern (-1056964609) to 0x48; the small integer defaults 192/65538/127 to 0x50/0x54/0x58; and the value 1 to 0x34/0x38/0x3C/0x40. Returns this. Called by sub_53CFE0.
    // CALL: GlobalZeroInit_c2a0(this) zero-fills the entire object as the first step of construction. [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Write float 1.0 (1065353216) defaults to offsets 0x0, 0x4, 0x5C and 0x60. [field:this:0x00000000, field:this:0x00000004, field:this:0x0000005C, field:this:0x00000060, source:raw]
    // ASSIGNMENT: Explicitly zero the dword fields at 0x8, 0xC, 0x10, 0x28, 0x2C, 0x30, 0x44, 0x4C and 0x64. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000044, field:this:0x0000004C, field:this:0x00000064, source:raw]
    // ASSIGNMENT: Zero the byte at offset 0x14. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Zero the tail dwords at offsets 0x868, 0x86C and 0x870. [field:this:0x00000868, field:this:0x0000086C, field:this:0x00000870, source:raw]
    // ASSIGNMENT: Set the integer default 0x10000 (65536) at offset 0x24 and the float -8.0 bit pattern (-1056964609) at offset 0x48. [field:this:0x00000024, field:this:0x00000048, source:raw]
    // ASSIGNMENT: Set the small integer defaults 192 at 0x50, 65538 at 0x54 and 127 at 0x58. [field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, source:raw]
    // ASSIGNMENT: Set the value 1 at offsets 0x34, 0x38, 0x3C and 0x40. [field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, source:raw]
    // RETURN: Return this; the sole caller is sub_53CFE0. [caller:0x0053CFE0, function:0x005523E0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_5523E0(this) {
    //     GlobalZeroInit_c2a0(this);          // zero the whole object
    //     this[0] = this[1] = 1.0f;          // 0x00, 0x04
    //     this[2] = this[3] = this[4] = 0;   // 0x08, 0x0C, 0x10
    //     *((_BYTE *)this + 20) = 0;         // 0x14
    //     this[9] = 0x10000;                 // 0x24
    //     this[10] = this[11] = this[12] = 0;// 0x28, 0x2C, 0x30
    //     this[13] = this[14] = this[15] = this[16] = 1; // 0x34..0x40
    //     this[17] = this[19] = 0;           // 0x44, 0x4C
    //     this[18] = -1056964609;            // 0x48, float -8.0
    //     this[20] = 192; this[21] = 65538; this[22] = 127; // 0x50..0x58
    //     this[23] = this[24] = 1.0f;        // 0x5C, 0x60
    //     this[25] = 0;                      // 0x64
    //     this[538] = this[539] = this[540] = 0; // 0x868, 0x86C, 0x870
    //     return this;
    //   }
    // UNRESOLVED: The semantic meaning of the literal defaults (float 1.0, float -8.0, 0x10000, 192, 65538, 127) and the owning type are not established; the legacy ABI label names a hash/string-table entry.
    // UNRESOLVED: The purpose of the tail fields at 0x868/0x86C/0x870 is unknown.
    // UNRESOLVED: GlobalZeroInit_c2a0 makes the explicit zero assignments redundant on a fresh allocation; the writes likely express intentional defaults, but the reason for re-zeroing is not documented.
}
