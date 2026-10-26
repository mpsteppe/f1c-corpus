// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FAD80
// Canonical corpus name: FAILTriageUnknownUnidentifiedButIsActuallyConstr
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FAILTriageUnknownUnidentifiedButIsActuallyConstr_004fad80.c

void UnknownObject::InitDefaultObjectState()
{
    // Constructor/initializer (__thiscall, AI subsystem): zeroes 43 dword fields across the object, then sets gravity to -9.81 (0x7C), a unity scalar of 1.0 (0x84), and four -1 sentinels (0x120..0x12C). Returns the this pointer unchanged. No reads, no calls, no branches.
    // ASSIGNMENT: Zero-initialize 43 dword fields (offsets 0x00..0x130) to 0. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x00000080, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C, field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, field:this:0x000000BC, field:this:0x000000C0, field:this:0x000000C4, field:this:0x0000010C, field:this:0x00000110, field:this:0x00000114, field:this:0x0000011C, field:this:0x00000130]
    // ASSIGNMENT: Set dword at 0x7C to -1055066685, the bit pattern of float -9.81 (gravity constant). [field:this:0x0000007C]
    // ASSIGNMENT: Set dword at 0x84 to 1065353216, the bit pattern of float 1.0 (unity scalar). [field:this:0x00000084]
    // ASSIGNMENT: Set the four dwords at 0x120..0x12C to -1 (sentinel values). [field:this:0x00000120, field:this:0x00000124, field:this:0x00000128, field:this:0x0000012C]
    // RETURN: Return the this pointer unchanged. [source:raw]
    // CALL: This initializer is invoked by sub_402690 (0x00402690). [caller:0x00402690]

    // Conservative worker pseudocode:
    //   void *sub_4FAD80(void *this) {
    //     for (each listed dword field except 0x7C, 0x84, 0x120..0x12C) *field = 0;
    //     *(unsigned*)((char*)this + 0x7C)  = -1055066685; /* float -9.81 * /
    //     *(unsigned*)((char*)this + 0x84)  = 1065353216;  /* float 1.0 * /
    //     *(unsigned*)((char*)this + 0x120) = -1;
    //     *(unsigned*)((char*)this + 0x124) = -1;
    //     *(unsigned*)((char*)this + 0x128) = -1;
    //     *(unsigned*)((char*)this + 0x12C) = -1;
    //     return this;
    //   }
    // UNRESOLVED: Object identity/class is unknown; untouched fields between the listed ones keep their prior contents.
    // UNRESOLVED: The -9.81 gravity value and 1.0 scalar suggest a physics/vehicle-like object but this is not confirmable from this packet.
}
