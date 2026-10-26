// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485E30
// Canonical corpus name: ShortComputation_5e30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_5e30_00485e30.c

void UnknownObject::UIComponentInitWithZeroSentinelPairs()
{
    // UI-style component initializer: calls the base initializer ConstructorWith1Sentinels, zeros eight general fields (0x44..0x60) and four more (0x70..0x7C), initializes five (min=0, max=-1) sentinel-guarded range pairs at 0xA0/0xA4, 0xA8/0xAC, 0xB0/0xB4, 0xB8/0xBC and 0xC0/0xC4, installs the vtable pointer off_5AB8C0 at this+0x0, runs a final setup sub-routine sub_486010, and returns this. Shared by seventeen UI-family constructors.
    // CALL: ConstructorWith1Sentinels (0049A930) performs the base-class/sub-object initialization before any field writes here. [callee:0x0049A930, source:raw]
    // ASSIGNMENT: Zero the general-purpose dword fields this[17..24] at offsets 0x44, 0x48, 0x4C, 0x50, 0x54, 0x58, 0x5C and 0x60. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, source:raw]
    // ASSIGNMENT: Zero the dword fields this[28..31] at offsets 0x70, 0x74, 0x78 and 0x7C. [field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, source:raw]
    // ASSIGNMENT: Initialize five sentinel-guarded range pairs (min=0 at the even index, max=-1 at the odd index): 0xA0/0xA4, 0xA8/0xAC, 0xB0/0xB4, 0xB8/0xBC and 0xC0/0xC4. [field:this:0x000000A0, field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, field:this:0x000000B0, field:this:0x000000B4, field:this:0x000000B8, field:this:0x000000BC, field:this:0x000000C0, field:this:0x000000C4, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5AB8C0 at this+0x0, replacing the pointer left by the base initializer. [field:this:0x00000000, global:0x005AB8C0, source:raw]
    // CALL: sub_486010(this) runs the final setup sub-routine after all field defaults are installed. [callee:0x00486010, source:raw]
    // RETURN: Return this; the function is a shared initializer used by seventeen UI-family constructors (0047A9E0, 00487220, 00487660, 00487ED0, 00488180, 00488B00, 00488F90, 004893C0, 0048B420, 0048D3A0, 0048E070, 0048E600, 0048EAA0, 0048FB70, 0048FE60, 00490250, 00493FC0). [caller:0x0047A9E0, caller:0x00487220, caller:0x00487660, caller:0x00487ED0, caller:0x00488180, caller:0x00488B00, caller:0x00488F90, caller:0x004893C0, caller:0x0048B420, caller:0x0048D3A0, caller:0x0048E070, caller:0x0048E600, caller:0x0048EAA0, caller:0x0048FB70, caller:0x0048FE60, caller:0x00490250, caller:0x00493FC0, function:0x00485E30, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_485E30(this) {
    //     ConstructorWith1Sentinels(this);
    //     for (i = 17; i <= 24; ++i) this[i] = 0;   // 0x44..0x60
    //     for (i = 28; i <= 31; ++i) this[i] = 0;   // 0x70..0x7C
    //     this[40] = 0; this[41] = -1;   // 0xA0/0xA4
    //     this[42] = 0; this[43] = -1;   // 0xA8/0xAC
    //     this[44] = 0; this[45] = -1;   // 0xB0/0xB4
    //     this[46] = 0; this[47] = -1;   // 0xB8/0xBC
    //     this[48] = 0; this[49] = -1;   // 0xC0/0xC4
    //     this[0] = &off_5AB8C0;         // vtable
    //     sub_486010(this);              // final setup
    //     return this;
    //   }
    // UNRESOLVED: The five (min=0, max=-1) pairs are inferred to be sentinel-guarded range markers; their runtime meaning is not confirmed from this packet.
    // UNRESOLVED: The purpose of sub_486010 final setup and of the base initializer ConstructorWith1Sentinels is defined outside this packet.
    // UNRESOLVED: The exact UI class and vtable off_5AB8C0 dispatch table are not identified.
}
