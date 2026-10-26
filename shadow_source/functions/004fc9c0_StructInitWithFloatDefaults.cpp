// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC9C0
// Canonical corpus name: StructInitWithFloatDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithFloatDefaults_004fc9c0.c

void UnknownObject::StructInitWithFloatDefaults()
{
    // Straight-line structure initializer (this-call, returns this). Delegates a sub-object at this+0x20 to sub_4FC850 and a region starting at this+0x108 to MultiFieldReset, then fills a large run of scalar fields: first dword to 1.0f and the surrounding dwords to zero, a block of WORD fields with sentinel values (0, -1, -1, 0, 0x7FFF, 0x8000), and finally initializes the interpolation range table via RangeInterpolationTable(this). All field writes are literal-driven; there are no reads of existing state and no globals.
    // CALL: Initialize the sub-object at this+0x20 (offset 32 bytes) by calling sub_4FC850 on it. [callee:0x004FC850, field:this:0x00000020]
    // ASSIGNMENT: Zero four consecutive dwords this+0x54, this+0x58, this+0x5C, this+0x60. [field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060]
    // CALL: Reset the field block beginning at this+0x108 (byte offset 264) by calling MultiFieldReset. [callee:0x004FC280]
    // ASSIGNMENT: Set this+0x0 to 1.0f (bit pattern 1065353216) and this+0x4, this+0x8, this+0xC to zero. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // ASSIGNMENT: Zero this+0x14 and this+0x18. [field:this:0x00000014, field:this:0x00000018]
    // ASSIGNMENT: Zero this+0x20 (written through the saved pointer this+32). [field:this:0x00000020]
    // ASSIGNMENT: Zero the dword run this+0x24, this+0x28, this+0x2C, this+0x30, this+0x34, this+0x38, this+0x3C. [field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C]
    // ASSIGNMENT: Zero this+0x40 and this+0x44. [field:this:0x00000040, field:this:0x00000044]
    // ASSIGNMENT: Initialize the WORD block: this+0x48 = 0, this+0x4A = -1, this+0x4C = -1, this+0x4E = 0, this+0x50 = 0x7FFF, this+0x52 = 0x8000. [field:this:0x00000048, field:this:0x0000004A, field:this:0x0000004C, field:this:0x0000004E, field:this:0x00000050, field:this:0x00000052]
    // CALL: Initialize the range-interpolation lookup table with RangeInterpolationTable(this). [callee:0x004FD6F0]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_4FC9C0(char *p) {
    //     _DWORD *sub = (_DWORD *)(p + 32);
    //     sub_4FC850((_DWORD *)p + 8);
    //     ((_DWORD *)p)[21] = 0; ((_DWORD *)p)[22] = 0; ((_DWORD *)p)[23] = 0; ((_DWORD *)p)[24] = 0;
    //     MultiFieldReset(p + 264);
    //     *(_DWORD *)p = 1065353216;
    //     ((_DWORD *)p)[1] = 0; ((_DWORD *)p)[2] = 0; ((_DWORD *)p)[3] = 0;
    //     ((_DWORD *)p)[5] = 0; ((_DWORD *)p)[6] = 0; *sub = 0;
    //     ((_DWORD *)p)[9] = 0; ((_DWORD *)p)[10] = 0; ((_DWORD *)p)[11] = 0;
    //     ((_DWORD *)p)[12] = 0; ((_DWORD *)p)[13] = 0; ((_DWORD *)p)[14] = 0; ((_DWORD *)p)[15] = 0;
    //     p[64] = 0; ((_DWORD *)p)[17] = 0;
    //     ((_WORD *)p)[36] = 0; ((_WORD *)p)[37] = -1; ((_WORD *)p)[38] = -1;
    //     ((_WORD *)p)[39] = 0; ((_WORD *)p)[40] = 0x7FFF; ((_WORD *)p)[41] = 0x8000;
    //     RangeInterpolationTable(p);
    //     return p;
    //   }
    // UNRESOLVED: Identity of the owning class is unknown; no caller or RTTI evidence is present.
    // UNRESOLVED: Purpose of the sub-object at this+0x20 and the region reset by MultiFieldReset is not stated by the packet.
    // UNRESOLVED: Meaning of the sentinel WORD block (0, -1, -1, 0, 0x7FFF, 0x8000) is not stated by the packet.
    // UNRESOLVED: The sub-call at this+0x20 is an unnamed decompiler symbol (sub_4FC850) in the packet.
}
