// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C030
// Canonical corpus name: sub_45C030
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_45C030_0045c030.c

void UnknownObject::ResetDefaults()
{
    // Initializer: zeroes twelve DWORD fields at this+0x8 through this+0x34, then writes two float constants into the leading fields (this+0x0 = 1092616192, i.e. 10.0; this+0x4 = 1087006310, i.e. 6.325). Returns 0. No reads, no globals, no callees. Called by NetCommPlayerSlotSync (0x0045FC50), consistent with resetting per-player slot state.
    // ASSIGNMENT: Zero the DWORD fields at this+0x8, this+0xC, this+0x10, this+0x14, this+0x18, this+0x1C, this+0x20, this+0x24, this+0x28, this+0x2C, this+0x30, this+0x34. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034]
    // ASSIGNMENT: Write the float constant 1092616192 (10.0) to this+0x0. [field:this:0x00000000]
    // ASSIGNMENT: Write the float constant 1087006310 (6.325) to this+0x4. [field:this:0x00000004]
    // RETURN: Return 0. [function:0x0045C030, source:raw]
    // CALL: Invoked by NetCommPlayerSlotSync (0x0045FC50) as part of slot-state setup. [caller:0x0045FC50]

    // Conservative worker pseudocode:
    //   int ResetDefaults(_DWORD* this) {
    //     this[2] = this[3] = this[4] = this[5] = 0;
    //     this[6] = this[7] = this[8] = this[9] = 0;
    //     this[10] = this[11] = this[12] = this[13] = 0;
    //     this[0] = 1092616192; /* 10.0f * /
    //     this[1] = 1087006310; /* 6.325f * /
    //     return 0;
    //   }
    // UNRESOLVED: Owning class and the meaning of the two leading float constants (10.0, 6.325) are unknown; they may be defaults consumed only when later fields are unset.
    // UNRESOLVED: The function returns 0; the caller's use of that return value is not observed here.
}
