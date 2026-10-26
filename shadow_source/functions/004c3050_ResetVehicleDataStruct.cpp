// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C3050
// Canonical corpus name: sub_4C3050
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C3050_004c3050.c

void UnknownObject::ResetVehicleDataStruct()
{
    // Constructor/initializer for a vehicle-data sub-struct: zeroes a leading block of paired slots (alternating 0 and -1 sentinel) from this+0x00 through this+0x24, resets the second sentinel pair group at this+0x3CC..0x3DC, clears a dword block this+0x38..0x6C, sets this+0x70 to 1.0f, and clears scattered byte/dword flags (this+0x74, 0x7C, 0xBC, 0xFC, 0x13C, 0x17C, 0x1BC, 0x2BC, 0x33C, 0x34C, 0x38C, 0x39C, 0x3AC, 0x3BC, 0x3D4, 0x3E0, 0x420). No reads, no globals, no calls; returns this. Called by VehicleFileLoader and VehicleDataLoader.
    // ASSIGNMENT: Initialize leading paired slots this+0x00..0x24 with alternating 0 and -1 sentinel values (this[0]=0, this[1]=-1, ..., this[9]=-1). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Reset second sentinel pair group: this+0x3CC=0, this+0x3D0=-1, this+0x3D8=0, this+0x3DC=-1, and clear the byte flag at this+0x28. [field:this:0x000003CC, field:this:0x000003D0, field:this:0x000003D8, field:this:0x000003DC, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Zero the dword block this+0x38..0x6C (this[14] through this[27]). [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Set this+0x70 to 1065353216 (1.0f), and zero the adjacent dwords this+0x74 and this+0x7C. [field:this:0x00000070, field:this:0x00000074, field:this:0x0000007C, source:raw]
    // ASSIGNMENT: Clear scattered byte flags at this+0xBC, 0xFC, 0x13C, 0x17C, 0x1BC, 0x2BC, 0x33C, 0x34C, 0x38C, 0x39C, 0x3AC and 0x3BC. [field:this:0x000000BC, field:this:0x000000FC, field:this:0x0000013C, field:this:0x0000017C, field:this:0x000001BC, field:this:0x000002BC, field:this:0x0000033C, field:this:0x0000034C, field:this:0x0000038C, field:this:0x0000039C, field:this:0x000003AC, field:this:0x000003BC, source:raw]
    // ASSIGNMENT: Clear this+0x3D4 (this[245]), the byte flag at this+0x3E0, and this+0x420 (this[264]). [field:this:0x000003D4, field:this:0x000003E0, field:this:0x00000420, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4C3050(_DWORD *this) {
    //     this[0]=0; this[1]=-1; this[2]=0; this[3]=-1; this[4]=0; this[5]=-1; this[6]=0; this[7]=-1; this[8]=0; this[9]=-1;
    //     this[243]=0; this[244]=-1; this[246]=0; this[247]=-1;
    //     *((_BYTE *)this + 40) = 0;
    //     this[14]=0; ... this[27]=0;
    //     this[28] = 1065353216; /* 1.0f * /
    //     *((_BYTE *)this + 116)=0; *((_BYTE *)this + 124)=0; /* ... 188, 252, 316, 380, 444, 700, 828, 844, 908, 924, 940, 956 ... * /
    //     this[245]=0; *((_BYTE *)this + 992)=0; this[264]=0;
    //     return this;
    //   }
    // UNRESOLVED: Packet abi label 'State_Struct_Multi_Field_Init' (LEGACY) is generic; the exact containing vehicle-data class is not determinable from this packet.
    // UNRESOLVED: The alternating 0/-1 sentinel pairs suggest an array of {value, id} slots or a list-head pattern, but their precise role is unresolved.
}
