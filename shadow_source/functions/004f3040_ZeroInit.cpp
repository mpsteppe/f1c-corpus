// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F3040
// Canonical corpus name: ZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroInit_004f3040.c

void UnknownObject::ZeroInit()
{
    // Zero-initializer for a 0x54-byte sub-object: writes a zero byte at this+0x0 and zeroes the remaining 20 dwords through this+0x50, then returns the this pointer. No reads, no globals, no callees. Called once from TireModelDataInit (0x004F34E0), which suggests this zeroes an embedded tire-model sub-structure. ABI lead names it Zero_Init (LEGACY).
    // ASSIGNMENT: Zero the first byte of the object at this+0x0 (byte write). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero dword words this[1]..this[9] at offsets 0x4..0x24. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Zero dword words this[10]..this[20] at offsets 0x28..0x50. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // RETURN: Return the this pointer (result = this). [function:0x004F3040, abi:lead]

    // Conservative worker pseudocode:
    //   *((unsigned char*)this) = 0;
    //   for (i = 1; i <= 20; ++i) this[i] = 0;
    //   return this;
    // UNRESOLVED: Owner object identity is not established by the packet (UnknownObject); the sole caller TireModelDataInit suggests an embedded sub-structure of the tire model data, but that is not confirmed here.
}
