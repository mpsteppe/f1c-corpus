// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6F20
// Canonical corpus name: sub_4F6F20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F6F20_004f6f20.c

void UnknownObject::TireStateStructInit()
{
    // Large tire-physics state initializer. Runs a 45-iteration StructZeroInit_6f00 loop over a stride-32-dword sub-struct array, zero-inits two sub-structs via StructZeroInit_6bc0, then zeroes the leading scalar fields, an array of twelve dword slots, and trailing fields, setting the float at offset 0xA0 to 1.0f. Returns this. Invoked by PhysicsTireSystemConstructor (004E4500).
    // LOOP: StructZeroInit_6f00 called on 45 consecutive sub-structs starting at this + 45 dwords, advancing by 32 dwords per step [callee:0x004F6F00, source:raw]
    // CALL: StructZeroInit_6bc0 zero-initializes the sub-struct at this + 405 dwords [callee:0x004F6BC0, source:raw]
    // CALL: StructZeroInit_6bc0 zero-initializes the sub-struct at this + 422 dwords [callee:0x004F6BC0, source:raw]
    // ASSIGNMENT: Zero the first eight dwords of the struct (offsets 0x0 through 0x1C) and the byte at offset 0x4 [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Zero the dwords at offsets 0x44, 0x48 and 0x4C (indexes 17, 18 and 19) [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // LOOP: Zero twelve dwords in groups of three (starting at index 20) across four iterations; the group at offset 0x58 is covered by this loop [field:this:0x00000058, source:raw]
    // ASSIGNMENT: Zero the dwords at offsets 0x80, 0x84, 0x88, 0x8C and 0x90 (indexes 32 through 36) [field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000090, source:raw]
    // ASSIGNMENT: Zero the byte at offset 0x98 (index 38) and the dwords at offsets 0x94, 0x9C, 0xA4, 0xA8, 0xAC and 0xB0 (indexes 37, 39, 41, 42, 43 and byte 44) [field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C, field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, field:this:0x000000B0, source:raw]
    // ASSIGNMENT: Set the dword at offset 0xA0 (index 40) to 1065353216 (1.0f), the only non-zero literal in the initializer [field:this:0x000000A0, source:raw]
    // ASSIGNMENT: Zero the trailing dwords at offsets 0x694 (index 421) and 0x6D8 (index 438) [field:this:0x00000694, field:this:0x000006D8, source:raw]
    // RETURN: Return this (the initialized struct pointer) [function:0x004F6F20, source:raw]
    // CALL: Called by PhysicsTireSystemConstructor (004E4500) as part of tire system object construction [caller:0x004E4500, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < 45; ++i)
    //     StructZeroInit_6f00(this + (45 + 32*i) dwords);
    //   StructZeroInit_6bc0(this + 405 dwords);
    //   StructZeroInit_6bc0(this + 422 dwords);
    //   for (offsets 0x0..0x1C) *dword = 0; byte[0x4] = 0;
    //   for (offsets 0x44, 0x48, 0x4C) *dword = 0;
    //   for (4 groups of 3 dwords starting at index 20) *dword = 0;
    //   for (offsets 0x80..0x90) *dword = 0;
    //   byte[0x98] = 0; for (offsets 0x94, 0x9C, 0xA4..0xB0) *dword = 0;
    //   this[40] = 1065353216;  // 1.0f
    //   this[421] = 0; this[438] = 0;
    //   return this;
    // UNRESOLVED: Field ownership is unknown; this is a generic large-state-struct initializer with no class evidence
    // UNRESOLVED: The sub-structs produced by StructZeroInit_6f00/StructZeroInit_6bc0 are opaque; their internal layout is not described here
}
