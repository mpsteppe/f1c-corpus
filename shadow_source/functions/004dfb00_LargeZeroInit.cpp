// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DFB00
// Canonical corpus name: LargeZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LargeZeroInit_004dfb00.c

void UnknownObject::LargeZeroInit()
{
    // Constructor/initializer for a 28-dword (112-byte) object: writes 0 into 27 dword fields from offset 0x0 to 0x6C and writes the float 0.25 (literal 1048576000) into the dword at offset 0x18 (this[6]). Returns 0. No reads, no globals, no calls. Matches the ctor_init template prelabel.
    // ASSIGNMENT: Zero 27 of the 28 dword fields spanning byte offsets 0x0 through 0x6C (all except 0x18): this[0]..this[5] and this[7]..this[27]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Write the float 0.25 (literal 1048576000) into the dword at byte offset 0x18 (this[6]). [field:this:0x00000018, source:raw]
    // RETURN: Return 0 (result register was seeded to 0 before the stores). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4DFB00(_DWORD *this) {
    //     this[0] = 0;  this[1] = 0;  this[2] = 0;  this[3] = 0;
    //     this[4] = 0;  this[5] = 0;  this[6] = 1048576000; /* 0.25f * /
    //     this[7] = 0;  this[8] = 0;  this[9] = 0;  this[10] = 0;
    //     this[11] = 0; this[12] = 0; this[13] = 0; this[14] = 0;
    //     this[15] = 0; this[16] = 0; this[17] = 0; this[18] = 0;
    //     this[19] = 0; this[20] = 0; this[21] = 0; this[22] = 0;
    //     this[23] = 0; this[24] = 0; this[25] = 0; this[26] = 0;
    //     this[27] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The object type owning these 28 dword fields is unknown; the 0.25f coefficient at offset 0x18 is likely consumed by another function.
    // UNRESOLVED: Both callers (InitWithDualCall 0x004DFB60 and sub_4DFBB0) invoke this right after allocating the object, consistent with a constructor body.
}
