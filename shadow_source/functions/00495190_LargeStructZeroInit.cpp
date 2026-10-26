// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495190
// Canonical corpus name: LargeStructZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LargeStructZeroInit_00495190.c

void UnknownObject::LargeStructZeroInit()
{
    // Initializes a large screen/UI data structure (at least 0x18EC bytes): zeroes many dword fields, writes sentinel values of -1 at +0x40 and +0x155C, zeroes a 0x1400-byte block at +276 and a 0x68-byte block at +5772, runs four sub-object constructors via sub_4999E0 at +5628 with a 12-byte stride, calls sub_493F50 at +5876 and ZeroInitInt at +6308, assigns a vtable pointer from off_5AC998 at offset 0, then calls sub_496560 and returns this. Called from ScreenDataStructInit (0x0047F370).
    // ASSIGNMENT: Zero the dword fields at offsets +0x4, +0x8, +0xC, and +0x10. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Zero the dword field at offset +0x3C. [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Set the dword field at offset +0x40 to -1 (sentinel / uninitialized marker). [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Zero the contiguous dword field block from +0x58 through +0x94. [field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, field:this:0x00000090, field:this:0x00000094, source:raw]
    // ASSIGNMENT: Zero the contiguous dword field block from +0xF0 through +0xFC. [field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, source:raw]
    // CALL: memset(this + 276, 0, 0x1400) to zero a 0x1400-byte field block. [source:raw]
    // ASSIGNMENT: Set the dword field at +0x1558 to 0 and the dword field at +0x155C to -1 (sentinel). [field:this:0x00001558, field:this:0x0000155C, source:raw]
    // LOOP: Run sub_4999E0 four times over consecutive 12-byte sub-objects starting at this + 5628. [callee:0x004999E0, source:raw]
    // CALL: memset(this + 5772, 0, 0x68) to zero a 0x68-byte field block. [source:raw]
    // CALL: Call sub_493F50(this + 5876) to initialize a sub-object. [callee:0x00493F50, source:raw]
    // CALL: Call ZeroInitInt(this + 6308) to zero-initialize a sub-object. [callee:0x0049A180, source:raw]
    // ASSIGNMENT: Zero the contiguous dword field block from +0x18AC through +0x18E8. [field:this:0x000018AC, field:this:0x000018B0, field:this:0x000018B4, field:this:0x000018B8, field:this:0x000018BC, field:this:0x000018C0, field:this:0x000018C4, field:this:0x000018C8, field:this:0x000018CC, field:this:0x000018D0, field:this:0x000018D4, field:this:0x000018D8, field:this:0x000018DC, field:this:0x000018E0, field:this:0x000018E4, field:this:0x000018E8, source:raw]
    // ASSIGNMENT: Assign the vtable pointer: *(DWORD *)this = &off_5AC998. [field:this:0x00000000, global:0x005AC998, source:raw]
    // CALL: Call sub_496560(this) to finish initialization. [callee:0x00496560, source:raw]
    // RETURN: Return this. [source:raw, caller:0x0047F370]

    // Conservative worker pseudocode:
    //   char *LargeStructZeroInit(char *this) {
    //     this[0x4..0x10] = 0; this[0x3C] = 0; this[0x40] = -1;
    //     this[0x58..0x94] = 0; this[0xF0..0xFC] = 0;
    //     memset(this + 276, 0, 0x1400);
    //     this[0x1558] = 0; this[0x155C] = -1;
    //     for (char *p = this + 5628, i = 4; i; --i, p += 12) sub_4999E0(p);
    //     memset(this + 5772, 0, 0x68);
    //     sub_493F50(this + 5876);
    //     ZeroInitInt(this + 6308);
    //     this[0x18AC..0x18E8] = 0;
    //     *(void **)this = &off_5AC998;
    //     sub_496560(this);
    //     return this;
    //   }
    // UNRESOLVED: The concrete type of the large structure and the role of its fields are unknown.
    // UNRESOLVED: The purpose of the four 12-byte sub-objects at +5628 initialized by sub_4999E0 is unknown.
    // UNRESOLVED: The meaning of the -1 sentinel values at +0x40 and +0x155C is unknown.
    // UNRESOLVED: The vtable identity behind off_5AC998 is unknown.
    // UNRESOLVED: The roles of sub_493F50 at +5876 and ZeroInitInt at +6308 are unknown.
}
