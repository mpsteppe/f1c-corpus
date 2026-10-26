// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FB90
// Canonical corpus name: StructInitWithDefaults_fb90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithDefaults_fb90_0054fb90.c

void UnknownObject::StructInitWithDefaults()
{
    // Constructor/initializer for a resource object whose dword fields run through offset 0x90. Calls the global zero-init helper GlobalZeroInit_c2a0, zeroes the first 0x40 header bytes with memset, then writes explicit default literals into 21 dword fields at offsets 0x40..0x90: enable/usage flags set to 1 at 0x44/0x48, a large cap value 0x100000 at 0x60, a small count 4 at 0x64, -1 at 0x68, and two 1.0f floats at 0x78/0x7C; all remaining listed fields are zeroed. Returns the this pointer. Called by DirectX mesh/texture resource creation paths.
    // CALL: Run the global zero-init helper GlobalZeroInit_c2a0(this) first. [callee:0x0053C2A0]
    // ASSIGNMENT: Zero the 0x40 header bytes of the object with memset(this, 0, 0x40). [source:raw]
    // ASSIGNMENT: Set the default-on flags: dword index 17 (offset 0x44) and index 18 (offset 0x48) are assigned 1. [field:this:0x00000044, field:this:0x00000048]
    // ASSIGNMENT: Zero dword index 16 (offset 0x40) and the contiguous run of dword indices 19..23 (offsets 0x4C, 0x50, 0x54, 0x58, 0x5C). [field:this:0x00000040, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C]
    // ASSIGNMENT: Assign the large default cap 0x100000 to dword index 24 (offset 0x60), count 4 to index 25 (offset 0x64), and -1 to index 26 (offset 0x68). [field:this:0x00000060, field:this:0x00000064, field:this:0x00000068]
    // ASSIGNMENT: Zero dword indices 27..29 (offsets 0x6C, 0x70, 0x74). [field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074]
    // ASSIGNMENT: Assign the two 1.0f floats (literal 1065353216) to dword indices 30 and 31 (offsets 0x78 and 0x7C). [field:this:0x00000078, field:this:0x0000007C]
    // ASSIGNMENT: Zero dword indices 32..36 (offsets 0x80, 0x84, 0x88, 0x8C, 0x90). [field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000090]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   memset(this, 0, 0x40);
    //   this[16] = 0;  this[17] = 1;  this[18] = 1;
    //   this[19] = 0;  this[20] = 0;  this[21] = 0;  this[22] = 0;  this[23] = 0;
    //   this[24] = 0x100000;  this[25] = 4;  this[26] = -1;
    //   this[27] = 0;  this[28] = 0;  this[29] = 0;
    //   this[30] = 1065353216;  this[31] = 1065353216;
    //   this[32] = 0;  this[33] = 0;  this[34] = 0;  this[35] = 0;  this[36] = 0;
    //   return this;
    // UNRESOLVED: The packet field extraction only covers offsets 0x40..0x90; the exact purpose of each literal (flags, cap, count, 1.0f scales) is not evidenced, only its value and position.
    // UNRESOLVED: The object type is unknown; the legacy ABI name Struct_Init_with_Defaults_54fb90 labels it only as a struct initializer.
    // UNRESOLVED: GlobalZeroInit_c2a0 may itself zero the same region, so the relative role of memset(0x40) versus the explicit assignments is inferred from ordering only.
}
