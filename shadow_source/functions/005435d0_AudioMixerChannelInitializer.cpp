// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005435D0
// Canonical corpus name: AudioMixerChannelInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioMixerChannelInitializer_005435d0.c

void UnknownObject::AudioMixerChannelInitializer()
{
    // Audio mixer channel constructor: zeroes the base object region via GlobalZeroInit_c2a0, initializes a two-byte sub-region via TwoFieldInitializer at this+104, then explicitly writes 87 state fields - most mixer/channel dwords to 0, a buffer-size 0x2000 (8192) at this+0xEC, an enable flag 1 at this+0x10C, a sentinel 11513775 at this+0x154, three 1.0f gain fields at this+0x17C/0x180/0x184, width/height words 180/160/160 at this+0x188/0x18A/0x18C, a 1000.0f limit at this+0x198 and a 1.0f factor at this+0x1D4 - then initializes a sub-object at this+272 via ObjectAllocationWithInit and returns this. Invoked by AudioEngineInitialization (00546010) when building an audio mixer channel.
    // CALL: Zero the base object region: GlobalZeroInit_c2a0((void*)this) runs before any explicit field writes. [callee:0x0053C2A0, source:raw]
    // CALL: Initialize the two-byte sub-region at this+104 via TwoFieldInitializer((_BYTE*)(this+104)). [callee:0x0053C6A0, source:raw]
    // ASSIGNMENT: Zero the leading mixer-state dwords this+0x4 through this+0x64 (offsets 0x4, 0x8, 0xC, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38, 0x3C, 0x40, 0x44, 0x48, 0x4C, 0x50, 0x54, 0x58, 0x5C, 0x60, 0x64). [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064]
    // ASSIGNMENT: Zero the byte flag at this+0x6C. [field:this:0x0000006C]
    // ASSIGNMENT: Set the buffer-size field this+0xEC = 0x2000 (8192); zero this+0xF0, 0xF4, 0xF8, 0xFC, 0x100, 0x104, 0x108. [field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, field:this:0x00000100, field:this:0x00000104, field:this:0x00000108]
    // ASSIGNMENT: Set the enable flag this+0x10C = 1; zero this+0x114 through 0x138 (offsets 0x114, 0x118, 0x11C, 0x120, 0x124, 0x128, 0x12C, 0x130, 0x134, 0x138). [field:this:0x0000010C, field:this:0x00000114, field:this:0x00000118, field:this:0x0000011C, field:this:0x00000120, field:this:0x00000124, field:this:0x00000128, field:this:0x0000012C, field:this:0x00000130, field:this:0x00000134, field:this:0x00000138]
    // ASSIGNMENT: Zero this+0x13C, 0x140, 0x144, 0x148, 0x14C, 0x150; set the sentinel this+0x154 = 11513775; zero this+0x158, 0x15C. [field:this:0x0000013C, field:this:0x00000140, field:this:0x00000144, field:this:0x00000148, field:this:0x0000014C, field:this:0x00000150, field:this:0x00000154, field:this:0x00000158, field:this:0x0000015C]
    // ASSIGNMENT: Zero this+0x160, 0x164, 0x16C, 0x170, 0x174, 0x178. [field:this:0x00000160, field:this:0x00000164, field:this:0x0000016C, field:this:0x00000170, field:this:0x00000174, field:this:0x00000178]
    // ASSIGNMENT: Set the three 1.0f gain fields this+0x17C, 0x180, 0x184 (bit pattern 1065353216). [field:this:0x0000017C, field:this:0x00000180, field:this:0x00000184]
    // ASSIGNMENT: Set the layout words this+0x188 = 180, this+0x18A = 160, this+0x18C = 160. [field:this:0x00000188, field:this:0x0000018A, field:this:0x0000018C]
    // ASSIGNMENT: Zero this+0x190, 0x194; set the 1000.0f limit this+0x198 (bit pattern 1148846080); zero this+0x19C through 0x1D0 (offsets 0x19C, 0x1A0, 0x1A4, 0x1A8, 0x1AC, 0x1B0, 0x1B4, 0x1B8, 0x1BC, 0x1C0, 0x1C4, 0x1C8, 0x1CC, 0x1D0). [field:this:0x00000190, field:this:0x00000194, field:this:0x00000198, field:this:0x0000019C, field:this:0x000001A0, field:this:0x000001A4, field:this:0x000001A8, field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001B4, field:this:0x000001B8, field:this:0x000001BC, field:this:0x000001C0, field:this:0x000001C4, field:this:0x000001C8, field:this:0x000001CC, field:this:0x000001D0]
    // ASSIGNMENT: Set the 1.0f factor this+0x1D4 (bit pattern 1065353216); zero this+0x1D8, 0x1DC, 0x1E0, 0x1E4, 0x1E8. [field:this:0x000001D4, field:this:0x000001D8, field:this:0x000001DC, field:this:0x000001E0, field:this:0x000001E4, field:this:0x000001E8]
    // CALL: Initialize the sub-object at this+272 via ObjectAllocationWithInit((int*)(this+272)). [callee:0x0053CAC0, source:raw]
    // CALL: Invoked by AudioEngineInitialization (00546010) when building an audio mixer channel. [caller:0x00546010, source:raw]
    // RETURN: Return this, the initialized channel pointer. [source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   TwoFieldInitializer((_BYTE*)(this + 104));
    //   zero dwords this+0x4..0x64;
    //   *(byte*)(this+0x6C) = 0;
    //   *(dword*)(this+0xEC) = 0x2000; zero this+0xF0..0x108;
    //   *(dword*)(this+0x10C) = 1; zero this+0x114..0x138;
    //   *(dword*)(this+0x154) = 11513775;
    //   *(float*)(this+0x17C) = *(float*)(this+0x180) = *(float*)(this+0x184) = 1.0f;
    //   *(word*)(this+0x188) = 180; *(word*)(this+0x18A) = *(word*)(this+0x18C) = 160;
    //   *(float*)(this+0x198) = 1000.0f;
    //   *(float*)(this+0x1D4) = 1.0f;
    //   ObjectAllocationWithInit((int*)(this + 272));
    //   return this;
    // UNRESOLVED: The TwoFieldInitializer target this+104 and the ObjectAllocationWithInit target this+272 are not enumerated among the packet field evidence, so their byte-level layout is not represented here.
    // UNRESOLVED: The meaning of the sentinel 11513775 at this+0x154 and the 0x2000 buffer-size value at this+0xEC depends on the mixer consumer code, which is outside this packet.
    // UNRESOLVED: Whether GlobalZeroInit_c2a0 also clears the sub-region later set by TwoFieldInitializer is not verifiable from this function alone.
}
